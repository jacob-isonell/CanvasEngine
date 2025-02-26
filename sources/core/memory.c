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
struct imemdata {
	size_t        length;
	unsigned char buffer[1]; /* variable length. */
};

/* Memory layout of `ce_arr`. */
struct iarr {
	size_t cap;
	size_t len;
	size_t stride;
	unsigned char buffer[1]; /* variable length. */
};

static struct iarr* s_get_arr(void* in) {
	union {
		void* in;
		unsigned char* shift;
		struct iarr* out;
	} p;
	
	if (in == NULL) {
		return NULL;
	}
	
	p.in = in;
	p.shift -= offsetof(struct iarr, buffer);
	return p.out;
}

static const struct iarr* s_get_carr(const void* in) {
	union {
		const void* in;
		const unsigned char* shift;
		const struct iarr* out;
	} p;
	
	if (in == NULL) {
		return NULL;
	}
	
	p.in = in;
	p.shift -= offsetof(struct iarr, buffer);
	return p.out;
}

#define ISETARR(in, arr) (*(in) = (arr)->buffer)

#define RAWALLOC(bytes) (icore.mem.alloc.alloc((bytes), icore.mem.alloc.user))
#define RAWFREE(addr, bytes) (icore.mem.alloc.free((addr), (bytes), icore.mem.alloc.user))
#define IALLOCDATA(bytes) ((struct imemdata*)RAWALLOC(offsetof(struct imemdata, buffer) + (bytes)))
#define IFREEDATA(addr) (icore.mem.alloc.free((addr), (addr)->length + offsetof(struct imemdata, buffer), icore.mem.alloc.user))

static struct imemdata* igetmemdata(void* in) {
	union {
		unsigned char* in;
		struct imemdata* out;
	} p;
	
	p.in = in;
	p.in -= offsetof(struct imemdata, buffer);
	return p.out;
}

CE_API ce_err ce_set_alloc(struct ce_alloc_t in) {
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

CE_API void* ce_alloc_s(size_t bytes, ce_err* opt_err) {
	void* out = NULL;
	ce_err err = ce_mtx_lock(&icore.mem.lck);
	
	if (ce_success(err)) {
		struct imemdata* const data = IALLOCDATA(bytes);
		ce_mtx_unlock(&icore.mem.lck);
		
		if (data) {
			err = CE_EOK;
			data->length = bytes;
			out = data->buffer;
		} else {
			err = CE_ENOMEM;
		}
	}
	
	if (opt_err) {
		*opt_err = err;
	}
	
	return out;
}

CE_API void* ce_alloc(size_t bytes) {
	void* out = NULL;
	
	if (ce_success(ce_mtx_lock(&icore.mem.lck))) {
		struct imemdata* const data = IALLOCDATA(bytes);
		ce_mtx_unlock(&icore.mem.lck);
		
		if (data) {
			data->length = bytes;
			out = data->buffer;
		}
	}
	
	return out;
}

CE_API ce_err ce_free(void* addr) {
	if (addr == NULL) {
		return CE_EOK;
	}
	
	struct imemdata* const data = igetmemdata(addr);
	
	ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_success(err)) {
		IFREEDATA(data);
		ce_mtx_unlock(&icore.mem.lck);
	}
	
	return err;
}

CE_API ce_err ice_realloc(void* inout, size_t new_size) {
	void** const inout_ptr = (void**)inout;
	struct imemdata* const data = igetmemdata(*inout_ptr);
	
	if (new_size <= data->length) {
		return CE_EOK;
	}
	
	const ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_failure(err)) {
		return err;
	}
	
	struct imemdata* const new_data = IALLOCDATA(new_size);
	if (new_data == NULL) {
		ce_mtx_unlock(&icore.mem.lck);
		return CE_ENOMEM;
	}
	
	new_data->length = new_size;
	memcpy(new_data->buffer, data->buffer, data->length);
	*inout_ptr = new_data->buffer;
	
	IFREEDATA(data);
	ce_mtx_unlock(&icore.mem.lck);
	
	return CE_EOK;
}

CE_API ce_err ice_arr_free(void* array) {
	if (array == NULL) {
		return CE_EOK;
	}
	
	struct iarr* const data = s_get_arr(array);
	const size_t bytes = (data->cap * data->stride) + offsetof(struct iarr, buffer);
	
	const ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_failure(err)) {
		IDEBERROR("Failed to deallocate memory %p (%zu bytes)\n", (void*)data, bytes);
		return err;
	}
	
	RAWFREE(data, bytes);
	return ce_mtx_unlock(&icore.mem.lck);
}

CE_API ce_err ice_arr_resize(void** inout_arr, size_t stride, size_t new_size) {
	const ce_err err = ice_arr_reserve(inout_arr, stride, new_size);
	if (ce_failure(err)) {
		return err;
	}
	
	struct iarr* const data = s_get_arr(*inout_arr);
	data->len = new_size;
	return CE_EOK;
}

CE_API ce_err ice_arr_reserve(void** inout_arr, size_t stride, size_t new_capacity) {
	struct iarr* const data = s_get_arr(*inout_arr);
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
	
	const size_t alloc_size = (stride * new_capacity) + offsetof(struct iarr, buffer);
	
	/* Check for integer overflow (i.e. the arguments aren't too large). */
	if (alloc_size < stride || alloc_size < new_capacity || alloc_size < offsetof(struct iarr, buffer)) {
		return CE_ERANGE;
	}
		
	const ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_failure(err)) {
		return err;
	}
	
	struct iarr* const new_buffer = (struct iarr*)RAWALLOC(alloc_size);
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
		RAWFREE(data, (data->cap * stride) + offsetof(struct iarr, buffer));
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


/*
CE_API void ice_arr_free(void* array) {
	struct itemp_arr_t* p = (struct itemp_arr_t*)array;
	if (p == NULL) {
		return;
	}
	
	ce_free(p->m_data);
}

CE_API ce_err ice_arr_resize(ICE_ARRPAIR_ARG, size_t new_size) {
	struct iarr_data_t in_arr = IFROM_ARRARG;
	
	// *in_arr.m_data.vptr = 
}

CE_API ce_err ice_arr_reserve(ICE_ARRPAIR_ARG, size_t new_capacity) {
	struct iarr_data_t in_arr = IFROM_ARRARG;
	if (new_capacity <= *in_arr.m_capacity) {
		return CE_EOK;
	}
	
	const ce_err e = ce_mtx_lock(&icore.mem.lck);
	if (ce_failure(e)) {
		return e;
	}
	
	void* const buffer = IALLOCDATA(in_arr.m_stride * new_capacity);
	if (buffer == NULL) {
		ce_mtx_unlock(&icore.mem.lck);
		return CE_ENOMEM;
	}
	
	memcpy(buffer, *in_arr.m_data.vptr, *in_arr.m_count * in_arr.m_stride);
	
	ce_mtx_unlock(&icore.mem.lck);
	return CE_EOK;
}
*/
