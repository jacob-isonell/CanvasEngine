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
	void* (*alloc)(size_t, void*);
	void (*free)(void*, void*);
	void* user;
};

CE_API ce_err ce_set_alloc(struct ce_alloc_t in);
CE_API void* ce_alloc_s(size_t bytes, ce_err* opt_err);
CE_API void* ce_alloc(size_t bytes);
CE_API ce_err ce_free(void* addr);

CE_API ce_err ice_arr_alloc(void** out, size_t reserve, size_t stride);
CE_API ce_err ice_arr_free(void* array);
CE_API ce_err ice_arr_resize(void** out, size_t new_size);
CE_API ce_err ice_arr_reserve(void** out, size_t new_capacity);

#define ce_arr(type) struct { type* array; }
#define ce_arr_at(var, index) ((var).array[(index)])
#define ce_arr_alloc(out, reserve) ice_arr_alloc((void**)&(out)->array, (reserve), sizeof(*((out)->array)))
#define ce_arr_free(arr) ice_arr_free((out)->array)

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_MEMORY_H */
