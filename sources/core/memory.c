/**************************************************************************
** CanvasEngine is a C11 cross platform multimedia library.              **
** Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             **
**                                                                       **
** This program is free software: you can redistribute it and/or modify  **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 3 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** This program is distributed in the hope that it will be useful,       **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with this program. If not, see <https://www.gnu.org/licenses/>. **
**************************************************************************/

#include "icore_base.h"
#include <canvas/threads/mutex.h>

static void* s_defalloc(size_t bytes, void* arg);
static void s_deffree(void* addr, size_t bytes, void* arg);

static ce_mtx s_lock = CE_MTX_INIT_PLAIN;
static ce_alloc_t s_alloc = {
  .alloc = &s_defalloc,
  .free = &s_deffree,
  .user = NULL
};

/* Memory layout of `ce_alloc` and `ce_alloc_s`. */
typedef struct imem_t {
  size_t        length;
  unsigned char buffer[1]; /* variable length. */
} imem_t;

/* Memory layout of `ce_arr`. */
typedef struct iarr_t {
  size_t cap;
  size_t len;
  size_t stride;
  unsigned char buffer[1]; /* variable length. */
} iarr_t;

static imem_t* s_get_mem(void* in) {
  union {
    unsigned char* in;
    imem_t* out;
  } p;
  
  p.in = in;
  p.in -= offsetof(imem_t, buffer);
  return p.out;
}

static iarr_t* s_get_arr(void* in) {
  union {
    void* in;
    unsigned char* shift;
    iarr_t* out;
  } p;
  
  if (in == NULL) {
    return NULL;
  }
  
  p.in = in;
  p.shift -= offsetof(iarr_t, buffer);
  return p.out;
}

static const iarr_t* s_get_carr(const void* in) {
  union {
    const void* in;
    const unsigned char* shift;
    const iarr_t* out;
  } p;
  
  if (in == NULL) {
    return NULL;
  }
  
  p.in = in;
  p.shift -= offsetof(iarr_t, buffer);
  return p.out;
}

static iarr_t* s_get_to_arr(void* in) {
  union {
    void* in;
    void** out;
  } p;
  
  if (in == NULL) {
    return NULL;
  }
  
  p.in = in;
  return s_get_arr(*p.out);
}

static void* s_defalloc(size_t bytes, void* arg) {
  (void)arg;
  return malloc(bytes);
}

static void s_deffree(void* addr, size_t bytes, void* arg) {
  (void)bytes;
  (void)arg;
  free(addr);
}

static void* s_doalloc(size_t bytes) {
  return s_alloc.alloc(bytes, s_alloc.user);
}

static void s_dofree(void* addr, size_t bytes) {
  s_alloc.free(addr, bytes, s_alloc.user);
}

CE_API ce_err ce_set_alloc(ce_alloc_t in) {
  if (in.alloc == NULL || in.free == NULL) {
    return CE_EINVAL;
  }
  
  ce_err err = ce_mtx_lock(&s_lock);
  
  if (ce_success(err)) {
    s_alloc = in;
    ce_mtx_unlock(&s_lock);
  }
  
  return err;
}

ICE_API void* ialloc(size_t bytes, ce_err* opt_err) {
  void* out = NULL;
  IERRBEGIN {
    if (bytes == 0) {
      IERRDO(CE_EINVAL);
    }
    
    IERRDO(ce_mtx_lock(&s_lock));
    out = s_doalloc(bytes);
    ce_mtx_unlock(&s_lock);
    
    if (out == NULL) {
      IERRVAL = CE_ENOMEM;
    }
  } IERREND { }
  if (opt_err) {
    *opt_err = IERRVAL;
  }
  return out;
}

ICE_API void ifree(void* addr, size_t bytes) {
  if (addr == NULL) {
    return;
  }
  
  if (ce_success(ce_mtx_lock(&s_lock))) {
    s_dofree(addr, bytes);
    ce_mtx_unlock(&s_lock);
  }
}

CE_API void* ce_alloc_s(size_t bytes, ce_err* opt_err) {
  imem_t* const data = (imem_t*)ialloc(bytes + offsetof(imem_t, buffer), opt_err);
  if (data) {
    data->length = bytes;
  }
  return data->buffer;
}

CE_API void* ce_alloc(size_t bytes) {
  const size_t alloc_size = bytes + offsetof(imem_t, buffer);
  if (bytes == 0 || alloc_size <= bytes) { /* Check for overflow. */
    return NULL;
  }
  
  if (ce_success(ce_mtx_lock(&s_lock))) {
    imem_t* const data = (imem_t*)s_doalloc(alloc_size);
    ce_mtx_unlock(&s_lock);
    
    if (data) {
      data->length = bytes;
      return data->buffer;
    }
  }
  
  return NULL;
}

CE_API void ce_free(void* addr) {
  if (addr == NULL) {
    return;
  }
  
  imem_t* const data = s_get_mem(addr);
  ifree(data, data->length + offsetof(imem_t, buffer));
}

CE_API ce_err ce_realloc(
  CE_INOUT void*  addr,
           size_t new_size
) {
  void** const inout_ptr = (void**)addr;
  imem_t* const data = s_get_mem(*inout_ptr);
  
  if (new_size == 0) {
    return CE_EINVAL;
  }
  
  const size_t alloc_size = new_size + offsetof(imem_t, buffer);
  if (alloc_size <= new_size) {
    return CE_ERANGE;
  }
  
  if (new_size <= data->length) {
    return CE_EOK;
  }
  
  const ce_err err = ce_mtx_lock(&s_lock);
  if (ce_failure(err)) {
    return err;
  }
  
  imem_t* const new_data = s_doalloc(alloc_size);
  if (new_data == NULL) {
    ce_mtx_unlock(&s_lock);
    return CE_ENOMEM;
  }
  
  new_data->length = new_size;
  memcpy(new_data->buffer, data->buffer, data->length);
  *inout_ptr = new_data->buffer;
  
  s_dofree(data, data->length + offsetof(imem_t, buffer));
  ce_mtx_unlock(&s_lock);
  
  return CE_EOK;
}

CE_API void ce_arr_free(void* array) {
  if (array == NULL) {
    return;
  }
  
  iarr_t* const data = s_get_arr(array);
  const size_t bytes = (data->cap * data->stride) + offsetof(iarr_t, buffer);
  
  const ce_err err = ce_mtx_lock(&s_lock);
  if (ce_failure(err)) {
    IDEBERROR("Failed to deallocate memory %p (%zu bytes)\n", (void*)data, bytes);
    return;
  }
  
  s_dofree(data, bytes);
  ce_mtx_unlock(&s_lock);
}

CE_API ce_err ce_arr_resize(void* inout_arr, size_t stride, size_t new_size) {
  const ce_err err = ce_arr_reserve(inout_arr, stride, new_size);
  if (ce_failure(err)) {
    return err;
  }
  
  iarr_t* const data = s_get_to_arr(inout_arr);
  data->len = new_size;
  return CE_EOK;
}

CE_API ce_err ce_arr_reserve(void* inout_arr, size_t stride, size_t new_capacity) {
  iarr_t* const data = s_get_to_arr(inout_arr);
  if (data) {
    /* Enough storage, reserve doesn't shrink storage. */
    if (new_capacity <= data->cap) {
      return CE_EOK;
    }
  }
  
  /* Ensure theres always at least 2 elements. */
  if (new_capacity < 2) {
    new_capacity = 2;
  }
  
  const size_t alloc_size = (stride * new_capacity) + offsetof(iarr_t, buffer);
  
  /* Check for integer overflow (i.e. the arguments aren't too large). */
  if (alloc_size < stride || alloc_size < new_capacity || alloc_size < offsetof(iarr_t, buffer)) {
    return CE_ERANGE;
  }
    
  const ce_err err = ce_mtx_lock(&s_lock);
  if (ce_failure(err)) {
    return err;
  }
  
  iarr_t* const new_buffer = (iarr_t*)s_doalloc(alloc_size);
  if (new_buffer == NULL) {
    ce_mtx_unlock(&s_lock);
    return CE_ENOMEM;
  }

  /* Copy over old data */
  new_buffer->cap = new_capacity;
  new_buffer->len = data ? data->len : 0;
  new_buffer->stride = stride;
  if (data) {
    memcpy(new_buffer->buffer, data->buffer, data->len * stride);
  }

  /* Replace buffer. */
  if (data) {
    s_dofree(data, (data->cap * stride) + offsetof(iarr_t, buffer));
  }
  memcpy(inout_arr, new_buffer->buffer, sizeof(void*));
  return ce_mtx_unlock(&s_lock);
}

CE_API size_t ce_arr_size(const void* array) {
  ICE_ASSERT(array != NULL);
  return s_get_carr(array)->len;
}

CE_API size_t ce_arr_cap(const void* array) {
  ICE_ASSERT(array != NULL);
  return s_get_carr(array)->cap;
}
