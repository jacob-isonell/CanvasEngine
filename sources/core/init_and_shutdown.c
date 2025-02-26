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
#ifdef CANVAS_GRAPHICS
#include "ifx_base.h"
#endif

struct iitem_pairs {
	ce_err (*init)(void);
	void   (*term)(void);
	
#ifdef CANVAS_DEBUG
	const char* debug_name;
#endif
};

static const struct iitem_pairs s_items[] = {
	{ &icore_init, &icore_shutdown, ICE_DEB("core") },
#ifdef CANVAS_GRAPHICS
	{ &ifx_init, &ifx_shutdown, ICE_DEB("graphics") }
#endif
};

CE_API ce_err ce_init(void) {
	if (icore.init_count++) {
		IDEBLOG("CanvasEngine has already been initialized. Incrementing reference count\n");
		return CE_EOK;
	}
	
	const struct iitem_pairs* it = s_items;
	const struct iitem_pairs* const end = s_items + CE_ARRLEN(s_items);
	IERRBEGIN {
		for (; it != end; ++it) {
			IDEBLOG("Initializing CanvasEngine module \"%s\"\n", it->debug_name);
			IERRDO(it->init());
		}
		IDEBLOG("CanvasEngine initialization complete\n");
	} IERREND {
		IDEBERROR("Failed to initialize %s module (0x%08X) \"%s\"\n", it->debug_name, IERRVAL, ce_errstr(IERRVAL));
		do {
			IDEBWARN("Terminating CanvasEngine module \"%s\"\n", it->debug_name);
			it->term();
		} while (it-- != s_items);
	}
	return IERRVAL;
}

CE_API void ce_shutdown(void) {
	if (icore.init_count == 0) {
		return;
	}
	
	if (--icore.init_count != 0) {
		return;
	}
	
	IDEBLOG("Shuting down CanvasEngine\n");
	const struct iitem_pairs* it = s_items;
	const struct iitem_pairs* const end = s_items + CE_ARRLEN(s_items);
	for (; it != end; ++it) {
		IDEBLOG("Terminating CanvasEngine module \"%s\"\n", it->debug_name);
		it->term();
	}
}
