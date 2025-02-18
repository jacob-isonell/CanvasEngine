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

CE_API ce_err ce_set_alloc(struct ce_alloc_t in) {
	ICE_REQ_INIT();
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
	ICE_REQ_INIT();
	void* out = NULL;
	ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_success(err)) {
		out = icore.mem.alloc.alloc(bytes, icore.mem.alloc.user);
		err = (out == NULL) ? CE_ENOMEM : CE_EOK;
		ce_mtx_unlock(&icore.mem.lck);
	}
	if (opt_err) {
		*opt_err = err;
	}
	return out;
}

CE_API void* ce_alloc(size_t bytes) {
	ICE_REQ_INIT();
	void* out = NULL;
	if (ce_success(ce_mtx_lock(&icore.mem.lck))) {
		out = icore.mem.alloc.alloc(bytes, icore.mem.alloc.user);
		ce_mtx_unlock(&icore.mem.lck);
	}
	return out;
}

CE_API ce_err ce_free(void* addr) {
	ICE_REQ_INIT();
	ce_err err = ce_mtx_lock(&icore.mem.lck);
	if (ce_success(err)) {
		icore.mem.alloc.free(addr, icore.mem.alloc.user);
		ce_mtx_unlock(&icore.mem.lck);
	}
	return err;
}

/*CE_API ce_err ice_arr_alloc(void** out, size_t reserve, size_t stride) {
	
}

CE_API void ice_arr_free(void* array) {
	
}

CE_API ce_err ice_arr_resize(void** out, size_t new_size) {
	
}

CE_API ce_err ice_arr_reserve(void** out, size_t new_capacity) {
	
}*/
