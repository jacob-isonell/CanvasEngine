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

#ifndef CANVAS_CORE_SETUP_H
#define CANVAS_CORE_SETUP_H

#include <canvas/core/error.h>

ICE_NAMESPACE_BEGIN

/** @brief add documentation here! */
struct ce_core_t {
	struct {
		char name[256];
		unsigned int version;
	} app_info, engine_info;
};

/** @brief add documentation here! */
CE_API
ce_err ce_core_options(
	const struct ce_core_t* ops
);

/** @brief add documentation here! */
CE_API
ce_err ce_init(
	void
);

/** @brief add documentation here! */
CE_API
void ce_shutdown(
	void
);

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_SETUP_H */
