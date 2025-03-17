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

CE_NAMESPACE_BEGIN

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
 * @brief Sets the allocation and deallocation methods used by CanvasEngine.
 * @note This should be set once at the start of the program and never again.
 *    Because if this were to be called mid program then memory that has already
 *    been allocated will be deallocated with the incorrect deallocator
 *    (e.x. by default CanvasEngine uses `malloc`/`free` for dynamic memory allocation,
 *    but if this function was called with the C++ `new`/`delete` methods mid program
 *    with already allocated memory then memory allocated with `malloc` would be
 *    free-ed with `delete`).
 */
CE_API ce_err ce_set_alloc(ce_alloc_t in);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API void* ce_alloc(size_t bytes);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API void* ce_alloc_s(
          size_t bytes,
  CE_OUT ce_err* opt_err
);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API ce_err ce_realloc(
  CE_INOUT void*  addr,
           size_t new_size
);

/**
 * @ingroup memory
 * @brief add documentation here!
 */
CE_API void ce_free(
  CE_IN void* addr
);

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define ce_arr(type) type*

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
#define CE_ARRINIT NULL

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
CE_API void ce_arr_free(void* arr);

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
CE_API size_t ce_arr_size(const void* arr);

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
CE_API size_t ce_arr_cap(const void* arr);

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
CE_API ce_err ce_arr_resize(
  CE_INOUT void* arr,
  size_t new_size,
  size_t stride
);

/**
 * @ingroup arrays
 * @brief add documentation here!
 */
CE_API ce_err ce_arr_reserve(
  CE_INOUT void* arr,
  size_t new_size,
  size_t stride
);

CE_NAMESPACE_END

#endif /* !CANVAS_CORE_MEMORY_H */
