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

CE_API ce_err ce_core_options(const struct ce_core_t* ops) {
	if (ihas_initialized()) {
		return CE_EPERM;
	}
	
	if (ops == NULL) {
		return CE_EINVAL;
	}
	
	strncpy(icore.app_info.name, ops->app_info.name, 256);
	strncpy(icore.engine_info.name, ops->engine_info.name, 256);
	icore.app_info.version = ops->app_info.version;
	icore.engine_info.version = ops->engine_info.version;
	return CE_EOK;
}

ICE_API cebool ihas_initialized(void) {
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
		
		printf("icore.app_info.name : %s\n", icore.app_info.name);
		/*for (size_t i = 0; i < CE_ARRLEN(icore.app_info.name); ++i) {
			printf("%02X", icore.app_info.name[i]);
		}*/
		
	} IERREND { }
	return IERRVAL;
}

ICE_API void icore_shutdown(void) {
	ce_mtx_destroy(&icore.mem.lck);
}

ICE_API struct icore_t icore = {
	.init_count = 0,
	.mem = {
		.alloc = {
			.alloc = &s_defalloc,
			.free = &s_deffree,
			.user = NULL
		},
		.lck = CE_MTX_INIT_PLAIN
	}
};

ICE_API struct ce_core_t icore_ops = {
	.app_info = {
		.name = { 0 },
		.version = 0,
	},
	.engine_info = {
		.name = { 0 },
		.version = 0,
	},
};
