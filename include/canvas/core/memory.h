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

#ifndef CANVAS_CORE_MEMORY_H
#define CANVAS_CORE_MEMORY_H

#include <canvas/core/error.h>

ICE_NAMESPACE_BEGIN

struct ce_alloc_t {
	void* (*alloc)(size_t count, void* usr);
	void (*free)(void* address, size_t count, void* usr);
	void* user;
};

CE_API ce_err ce_set_alloc(struct ce_alloc_t in);
CE_API void* ce_alloc_s(size_t bytes, ce_err* opt_err);
CE_API void* ce_alloc(size_t bytes);
CE_API ce_err ce_free(void* addr);
#define ce_realloc(inout, new_size) /* implementation-defined */

#define ce_arr(type) /* implementation-defined */
#define CE_ARRINIT /* implementation-defined */
#define ce_arr_alloc(out, reserve) /* implementation-defined */
#define ce_arr_free(arr) /* implementation-defined */
#define ce_arr_at(arr, index) /* implementation-defined */
#define ce_arr_size(arr) /* implementation-defined */
#define ce_arr_cap(arr) /* implementation-defined */
#define ce_arr_data(arr) /* implementation-defined */

#include <canvas/core/details/memory.h.inl>

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_MEMORY_H */
