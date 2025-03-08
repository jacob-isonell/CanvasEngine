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

#ifndef CANVAS_CORE_LIBRARY_H
#define CANVAS_CORE_LIBRARY_H

#include <canvas/core/error.h>

CE_NAMESPACE_BEGIN

/**
 * @ingroup types
 * @brief add documentation here!
 */
typedef struct ce_lib ce_lib;

/**
 * @ingroup types
 * @brief add documentation here!
 */
typedef enum ce_lib_flags {
  CE_LIB_FLAG_NONE = 0, /* add documentation here! */
} ce_lib_flags;

/** @brief Opens a handle to the library file.
 */
CE_API ce_err ce_lib_open(
  CE_OUT ce_lib**       CE_RESTRICT handle,
  CE_IN  const ce_utf8* CE_RESTRICT filepath,
         ce_lib_flags               flags
);

/** @brief Loads a symbol `name` from the library and writes the address to
 *   the symbol to the location pointed to by `out`.
 */
CE_API ce_err ce_lib_load(
  CE_INOUT ce_lib*        CE_RESTRICT handle,
  CE_IN    const ce_utf8* CE_RESTRICT name,
  CE_OUT   void*          CE_RESTRICT out
);

/** @brief add documentation here!
 */
CE_API void ce_lib_close(
  CE_IN ce_lib* handle
);

CE_NAMESPACE_END

#endif /* !CANVAS_CORE_LIBRARY_H */
