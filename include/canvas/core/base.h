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

/**
 * CANVAS_SKIP_COMPILER_CHECKS:
 *   CanvasEngine performs checks during compile time to determine
 *   if the compiler has all the nessecairy features required.
 *   Defining this macro disables these checks and it's up to the programming
 *   to ensure the compiler is able to compile the CanvasEngine library.
 */

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

#define cetrue ((cebool)1)
#define cefalse ((cebool)0)

#define ce_f32 float
#define ce_f64 double

#define ce_il8 /* implementation-defined */
#define ce_il16 /* implementation-defined */
#define ce_il32 /* implementation-defined */
#define ce_il64 /* implementation-defined */
#define ce_ul8 /* implementation-defined */
#define ce_ul16 /* implementation-defined */
#define ce_ul32 /* implementation-defined */
#define ce_ul64 /* implementation-defined */
#define CE_IL8_MAX /* implementation-defined */
#define CE_IL16_MAX /* implementation-defined */
#define CE_IL32_MAX /* implementation-defined */
#define CE_IL64_MAX /* implementation-defined */
#define CE_IL8_MIN /* implementation-defined */
#define CE_IL16_MIN /* implementation-defined */
#define CE_IL32_MIN /* implementation-defined */
#define CE_IL64_MIN /* implementation-defined */
#define CE_UL8_MAX /* implementation-defined */
#define CE_UL16_MAX /* implementation-defined */
#define CE_UL32_MAX /* implementation-defined */
#define CE_UL64_MAX /* implementation-defined */

#define ce_i8 /* implementation-defined */
#define ce_i16 /* implementation-defined */
#define ce_i32 /* implementation-defined */
#define ce_i64 /* implementation-defined */
#define ce_u8 /* implementation-defined */
#define ce_u16 /* implementation-defined */
#define ce_u32 /* implementation-defined */
#define ce_u64 /* implementation-defined */
#define CE_I8_MAX /* implementation-defined */
#define CE_I16_MAX /* implementation-defined */
#define CE_I32_MAX /* implementation-defined */
#define CE_I64_MAX /* implementation-defined */
#define CE_I8_MIN /* implementation-defined */
#define CE_I16_MIN /* implementation-defined */
#define CE_I32_MIN /* implementation-defined */
#define CE_I64_MIN /* implementation-defined */
#define CE_U8_MAX /* implementation-defined */
#define CE_U16_MAX /* implementation-defined */
#define CE_U32_MAX /* implementation-defined */
#define CE_U64_MAX /* implementation-defined */

/** @brief Gets the number of elements in a fixed sized array */
#define CE_ARRLEN(arr) (sizeof(arr) / sizeof(*(arr)))

struct ce_version {
	unsigned int patch : 14;
	unsigned int minor : 12;
	unsigned int major : 6;
};

#define CE_VERSION(major, minor, patch) /* implementation-defined */
#define CE_CURRVER CE_VERSION(ICE_VERSION_MAJOR, ICE_VERSION_MINOR, ICE_VERSION_PATCH)

#include <canvas/core/details/base.h.inl>

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_BASE_H */
