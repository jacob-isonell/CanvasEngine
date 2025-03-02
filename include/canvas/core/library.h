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

ICE_NAMESPACE_BEGIN

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

/**
 * @brief add documentation here!
 */
CE_API ce_err ce_lib_open(
  ce_lib**       CE_RESTRICT handle,
  const ce_utf8* CE_RESTRICT filepath,
  ce_lib_flags               flags
);

/**
 * @brief add documentation here!
 */
CE_API ce_err ce_lib_load(
  ce_lib*        CE_RESTRICT handle,
  const ce_utf8* CE_RESTRICT name,
  void*          CE_RESTRICT out
);

/**
 * @brief add documentation here!
 */
CE_API void ce_lib_close(ce_lib* handle);

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_LIBRARY_H */
