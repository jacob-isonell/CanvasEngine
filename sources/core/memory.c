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

#include "icore_global.h"
#include <canvas/core/memory.h>

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

static void* s_doalloc(size_t bytes) {
  return icore.mem.alloc.alloc(bytes, icore.mem.alloc.user);
}

static void s_dofree(void* addr, size_t bytes) {
  icore.mem.alloc.free(addr, bytes, icore.mem.alloc.user);
}

CE_API ce_err ce_set_alloc(ce_alloc_t in) {
  if (ihas_initialized()) {
    return CE_EPERM;
  }
  
  if (in.alloc == NULL || in.free == NULL) {
    return CE_EINVAL;
  }
  
  ce_err err = ce_mtx_lock(&icore.mem.lck);
  
  if (ce_success(err)) {
    icore.mem.alloc = in;
    ce_mtx_unlock(&icore.mem.lck);
  }
  
  return err;
}

ICE_API void* ialloc(size_t bytes, ce_err* opt_err) {
  void* out = NULL;
  IERRBEGIN {
    if (!ihas_initialized()) {
      IERRDO(CE_EPERM);
    }
    
    if (bytes == 0) {
      IERRDO(CE_EINVAL);
    }
    
    IERRDO(ce_mtx_lock(&icore.mem.lck));
    out = s_doalloc(bytes);
    ce_mtx_unlock(&icore.mem.lck);
    
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
  ICE_ASSERT(ihas_initialized());
  
  if (addr == NULL) {
    return;
  }
  
  if (ce_success(ce_mtx_lock(&icore.mem.lck))) {
    s_dofree(addr, bytes);
    ce_mtx_unlock(&icore.mem.lck);
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
  ICE_REQ_INIT();
  
  const size_t alloc_size = bytes + offsetof(imem_t, buffer);
  if (bytes == 0 || alloc_size <= bytes) { /* Check for overflow. */
    return NULL;
  }
  
  if (ce_success(ce_mtx_lock(&icore.mem.lck))) {
    imem_t* const data = (imem_t*)s_doalloc(alloc_size);
    ce_mtx_unlock(&icore.mem.lck);
    
    if (data) {
      data->length = bytes;
      return data->buffer;
    }
  }
  
  return NULL;
}

CE_API void ce_free(void* addr) {
  if (addr == NULL || !ihas_initialized()) {
    return;
  }
  
  imem_t* const data = s_get_mem(addr);
  ifree(data, data->length + offsetof(imem_t, buffer));
}

CE_API ce_err ice_realloc(void* inout, size_t new_size) {
  if (!ihas_initialized()) {
    return CE_EPERM;
  }
  
  void** const inout_ptr = (void**)inout;
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
  
  const ce_err err = ce_mtx_lock(&icore.mem.lck);
  if (ce_failure(err)) {
    return err;
  }
  
  imem_t* const new_data = s_doalloc(alloc_size);
  if (new_data == NULL) {
    ce_mtx_unlock(&icore.mem.lck);
    return CE_ENOMEM;
  }
  
  new_data->length = new_size;
  memcpy(new_data->buffer, data->buffer, data->length);
  *inout_ptr = new_data->buffer;
  
  s_dofree(data, data->length + offsetof(imem_t, buffer));
  ce_mtx_unlock(&icore.mem.lck);
  
  return CE_EOK;
}

CE_API ce_err ice_arr_free(void* array) {
  if (!ihas_initialized()) {
    return CE_EPERM;
  }
  
  if (array == NULL) {
    return CE_EOK;
  }
  
  iarr_t* const data = s_get_arr(array);
  const size_t bytes = (data->cap * data->stride) + offsetof(iarr_t, buffer);
  
  const ce_err err = ce_mtx_lock(&icore.mem.lck);
  if (ce_failure(err)) {
    IDEBERROR("Failed to deallocate memory %p (%zu bytes)\n", (void*)data, bytes);
    return err;
  }
  
  s_dofree(data, bytes);
  return ce_mtx_unlock(&icore.mem.lck);
}

CE_API ce_err ice_arr_resize(void** inout_arr, size_t stride, size_t new_size) {
  if (!ihas_initialized()) {
    return CE_EPERM;
  }
  
  const ce_err err = ice_arr_reserve(inout_arr, stride, new_size);
  if (ce_failure(err)) {
    return err;
  }
  
  iarr_t* const data = s_get_arr(*inout_arr);
  data->len = new_size;
  return CE_EOK;
}

CE_API ce_err ice_arr_reserve(void** inout_arr, size_t stride, size_t new_capacity) {
  if (!ihas_initialized()) {
    return CE_EPERM;
  }
  
  iarr_t* const data = s_get_arr(*inout_arr);
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
    
  const ce_err err = ce_mtx_lock(&icore.mem.lck);
  if (ce_failure(err)) {
    return err;
  }
  
  iarr_t* const new_buffer = (iarr_t*)s_doalloc(alloc_size);
  if (new_buffer == NULL) {
    ce_mtx_unlock(&icore.mem.lck);
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
  *inout_arr = new_buffer->buffer;
  return ce_mtx_unlock(&icore.mem.lck);
}

CE_API size_t ice_arr_len(void* array) {
  ICE_ASSERT(array != NULL);
  return s_get_carr(array)->len;
}

CE_API size_t ice_arr_cap(void* array) {
  ICE_ASSERT(array != NULL);
  return s_get_carr(array)->cap;
}
