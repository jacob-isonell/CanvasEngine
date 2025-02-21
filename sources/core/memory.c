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

struct imemdata {
	size_t length;
	unsigned char buffer[1];
};

struct itemp_arr_t {
	size_t m_capacity;
	size_t m_count;
	void* m_data;
};

struct iarr_data_t {
	size_t* m_capacity;
	size_t* m_count;
	union {
		void** vptr;
		unsigned char** bptr;
	} m_data;
	size_t m_stride;
};

#define ITEMPARR ((struct itemp_arr_t*)inout_arr_arg)
#define IFROM_ARRARG CE_STRUCT_INIT(struct iarr_data_t) { &(ITEMPARR->m_capacity), &(ITEMPARR->m_count), {&(ITEMPARR->m_data)}, in_arr_stride }
#define IARRSTRIDE in_arr_stride

static struct imemdata* igetmemdata(void* in) {
	return (struct imemdata*)((unsigned char*)in - offsetof(struct imemdata, buffer));
}

CE_API ce_err ce_set_alloc(struct ce_alloc_t in) {
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
	const size_t alloc_size = offsetof(struct imemdata, buffer) + bytes;
	ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_success(err)) {
		struct imemdata* const data = (struct imemdata*)icore.mem.alloc.alloc(alloc_size, icore.mem.alloc.user);
		ce_mtx_unlock(&icore.mem.lck);
		if (data) {
			err = CE_EOK;
			data->length = bytes;
			out = data->buffer;
		} else err = CE_ENOMEM;
	}
	if (opt_err) {
		*opt_err = err;
	}
	return out;
}

CE_API void* ce_alloc(size_t bytes) {
	void* out = NULL;
	const size_t alloc_size = offsetof(struct imemdata, buffer) + bytes;
	if (ce_success(ce_mtx_lock(&icore.mem.lck))) {
		struct imemdata* const data = (struct imemdata*)icore.mem.alloc.alloc(alloc_size, icore.mem.alloc.user);
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
		icore.mem.alloc.free(data, data->length + offsetof(struct imemdata, buffer), icore.mem.alloc.user);
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
	
	const size_t alloc_size = offsetof(struct imemdata, buffer) + new_size;
	struct imemdata* const new_data = (struct imemdata*)icore.mem.alloc.alloc(alloc_size, icore.mem.alloc.user);
	if (new_data == NULL) {
		ce_mtx_unlock(&icore.mem.lck);
		return CE_ENOMEM;
	}
	
	new_data->length = new_size;
	memcpy(new_data->buffer, data->buffer, data->length);
	*inout_ptr = new_data->buffer;
	icore.mem.alloc.free(data, data->length + offsetof(struct imemdata, buffer), icore.mem.alloc.user);
	ce_mtx_unlock(&icore.mem.lck);
	return CE_EOK;
}

/*CE_API ce_err ice_arr_alloc(ICE_ARRPAIR_ARG, size_t reserve) {
	struct iarr_data_t in_arr = IFROM_ARRARG;
	(void)reserve;
	abort();
}

CE_API void ice_arr_free(void* array) {
	struct itemp_arr_t* p = (struct itemp_arr_t*)array;
	if (p == NULL) {
		return;
	}
	
	ce_free(p->m_data);
}

CE_API ce_err ice_arr_resize(ICE_ARRPAIR_ARG, size_t new_size);
CE_API ce_err ice_arr_reserve(ICE_ARRPAIR_ARG, size_t new_capacity);*/


/*CE_API ce_err ice_arr_alloc(void** out, size_t reserve, size_t stride) {
	
}

CE_API void ice_arr_free(void* array) {
	if (array == NULL) {
		return;
	}
}

CE_API ce_err ice_arr_resize(void** out, size_t new_size) {
	
}

CE_API ce_err ice_arr_reserve(void** out, size_t new_capacity) {
	
}*/
