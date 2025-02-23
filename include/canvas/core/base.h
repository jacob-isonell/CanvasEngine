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

#ifndef CANVAS_CORE_BASE_H
#define CANVAS_CORE_BASE_H

/** @brief A boolean type (`bool` in C++ or `_Bool` in C11) */
#define cebool /* boolean-type */

#include <canvas_cmake_options.h>
#include <canvas/core/details/sysmacros.inl>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <string.h>
#include <wchar.h>

ICE_NAMESPACE_BEGIN

/** @brief add documentation here! */
#define cetrue ((cebool)1)

/** @brief add documentation here! */
#define cefalse ((cebool)0)

/** @brief add documentation here! */
#define ce_f32 float

/** @brief add documentation here! */
#define ce_f64 double

/** @brief add documentation here! */
#define ce_il8 /* implementation-defined */

/** @brief add documentation here! */
#define ce_il16 /* implementation-defined */

/** @brief add documentation here! */
#define ce_il32 /* implementation-defined */

/** @brief add documentation here! */
#define ce_il64 /* implementation-defined */

/** @brief add documentation here! */
#define ce_ul8 /* implementation-defined */

/** @brief add documentation here! */
#define ce_ul16 /* implementation-defined */

/** @brief add documentation here! */
#define ce_ul32 /* implementation-defined */

/** @brief add documentation here! */
#define ce_ul64 /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL8_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL16_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL32_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL64_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL8_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL16_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL32_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_IL64_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_UL8_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_UL16_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_UL32_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_UL64_MAX /* implementation-defined */

/** @brief add documentation here! */
#define ce_i8 /* implementation-defined */

/** @brief add documentation here! */
#define ce_i16 /* implementation-defined */

/** @brief add documentation here! */
#define ce_i32 /* implementation-defined */

/** @brief add documentation here! */
#define ce_i64 /* implementation-defined */

/** @brief add documentation here! */
#define ce_u8 /* implementation-defined */

/** @brief add documentation here! */
#define ce_u16 /* implementation-defined */

/** @brief add documentation here! */
#define ce_u32 /* implementation-defined */

/** @brief add documentation here! */
#define ce_u64 /* implementation-defined */

/** @brief add documentation here! */
#define CE_I8_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_I16_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_I32_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_I64_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_I8_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_I16_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_I32_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_I64_MIN /* implementation-defined */

/** @brief add documentation here! */
#define CE_U8_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_U16_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_U32_MAX /* implementation-defined */

/** @brief add documentation here! */
#define CE_U64_MAX /* implementation-defined */

/** @brief Gets the number of elements in a fixed sized array */
#define CE_ARRLEN(arr) (sizeof(arr) / sizeof(*(arr)))

/** @brief add documentation here! */
struct ce_version {
	unsigned int patch : 14; /* add documentation here! */
	unsigned int minor : 12; /* add documentation here! */
	unsigned int major : 6;  /* add documentation here! */
};

/** @brief add documentation here! */
#define CE_VERSION(major, minor, patch) (((major) << 24) | ((minor) << 24) | (patch))

/** @brief add documentation here! */
#define CE_CURRVER /* implementation-defined */

#include <canvas/core/details/base.h.inl>

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_BASE_H */
