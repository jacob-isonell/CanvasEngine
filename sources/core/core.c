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
#include <canvas/core/setup.h>

ICE_API cebool ireq_init_impl(void) {
	return icore.init_count != 0;
}

static void* s_defalloc(size_t bytes, void* arg) {
	(void)arg;
	return malloc(bytes);
}

static void s_deffree(void* addr, void* arg) {
	(void)arg;
	free(addr);
}

ICE_API ce_err icore_init(void) {
	IERRBEGIN {
		IERRDO(ce_mtx_init(&icore.mem.lck, CE_MTX_PLAIN));
	} IERREND { }
	return IERRVAL;
}

ICE_API void icore_shutdown(void) {
	ce_mtx_destroy(&icore.mem.lck);
}

struct icore_t icore = {
	.init_count = 0,
	.mem = {
		.alloc = {
			.alloc = &s_defalloc,
			.free = &s_deffree,
			.user = NULL
		},
		.lck = {0}
	}
};


/*struct icore_t icore = {
	.init_count = 0,
	.mem = {
		.alloc = {
			.alloc = &s_defalloc,
			.free = &s_deffree,
			.user = NULL
		},
		.lck = { }
	}
};*/
