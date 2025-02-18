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
	void (*term)(void);
};

static const struct iitem_pairs s_items[] = {
	{ &icore_init, &icore_shutdown },
#ifdef CANVAS_GRAPHICS
	{ &ifx_init, &ifx_shutdown }
#endif
};

CE_API ce_err ce_init(void) {
	if (icore.init_count++) {
		return CE_EOK;
	}
	
	size_t i = 0;
	IERRBEGIN {
		while (i < CE_ARRLEN(s_items)) {
			IERRDO(s_items[i].init());
			++i;
		}
	} IERREND {
	while (0 < i) {
		s_items[i--].term();
	}
} return IERRVAL;
}

CE_API void ce_shutdown(void) {
	if (icore.init_count == 0) {
		return;
	}
	
	if (--icore.init_count != 0) {
		return;
	}
	
	size_t i = CE_ARRLEN(s_items);
	while (0 < i) {
		s_items[--i].term();
	}
}
