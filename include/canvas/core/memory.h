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

/**
 * @ingroup memory
 * @brief Function pointer type for a
 */
typedef void* (*ce_pfunc_alloc)(size_t bytecount, void* usr);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
typedef void (*ce_pfunc_free)(void* address, size_t bytecount, void* usr);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
typedef struct ce_alloc_t {
  
  /** add documentation here! */
  void*          user;
  
  /** add documentation here! */
  ce_pfunc_alloc alloc;
  
  /** add documentation here! */
  ce_pfunc_free  free;
} ce_alloc_t;

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API ce_err ce_set_alloc(ce_alloc_t in);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API void* ce_alloc_s(size_t bytes, ce_err* opt_err);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API void* ce_alloc(size_t bytes);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API void ce_free(void* addr);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
#define ce_realloc(inout, new_size) /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr(type) /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define CE_ARRINIT /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr_free(arr) /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr_size(arr) /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr_cap(arr) /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr_resize(inout_array, new_size) /* implementation-defined */

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr_reserve(inout_array, new_capacity) /* implementation-defined */

#ifndef ICE_DOXY
#include <canvas/core/details/memory.h.inl>
#endif /* !ICE_DOXY */

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_MEMORY_H */
