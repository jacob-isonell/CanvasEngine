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

#ifdef ICE_DOXY

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_COMPILER_GNU

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_COMPILER_CLANG

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_COMPILER_GCC

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_COMPILER_MSVC

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_COMPILER_OTHER

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_UNIX

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_BSD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_FREEBSD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_NETBSD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_OPENBSD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_BSDI

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_DRAGONFLY

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_MIDNIGHTBSD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_WINDOWS

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_ANDROID

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_PLATFORM_OTHER

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ENVIROMENT_CYGWIN

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ENVIROMENT_EMSCRIPTEN

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ARCH_AMD64

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ARCH_ARM

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ARCH_ARM64

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ARCH_X86

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CANVAS_ARCH_OTHER

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_PRAGMAX(x) _Pragma(#x)

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_PRAGMA(x) CE_PRAGMAX(x)

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_EXTERNC

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_EXTERNC_BEGIN

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_EXTERNC_END

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_STRUCT_INIT(type) (type)

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_C89_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_C99_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_C11_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_C17_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_C23_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX98_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX11_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX14_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX17_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX20_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CXX23_STD

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_UNREACHABLE()

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CDECL

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_STDCALL

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_FASTCALL

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_THISCALL

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_VECCALL

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_CALL

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_ATTR_DLLEXPORT

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_ATTR_DLLIMPORT

/**
 * @ingroup utility
 * @brief add documentation here
 */
#define CE_ATTR_NORET

/**
 * @ingroup utility
 * @brief Indicates that on success, the function will write to the address pointed
 *        to by the argument.
 */
#define CE_OUT

/**
 * @ingroup utility
 * @brief Same as `CE_OUT` except the argument is optinally `NULL`.
 */
#define CE_OUT_OPT

/**
 * @ingroup utility
 * @brief Indicates that the input argument is read from an never written to.
 */
#define CE_IN

/**
 * @ingroup utility
 * @brief same as `CE_IN` but the argument is optionally `NULL`.
 */
#define CE_IN_OPT

/**
 * @ingroup utility
 * @brief Indicates that the function reads and writes to the argument.
 */
#define CE_INOUT

/**
 * @ingroup utility
 * @brief same as `CE_INOUT` but the argument is optionally `NULL`.
 */
#define CE_INOUT_OPT

/** @internal */
#define CE_NAMESPACE_BEGIN

/** @internal */
#define CE_NAMESPACE_END

/** @internal */
#define CE_API

/** @internal */
typedef unsigned char icebool;

#else
#include <canvas_cmake_options.h>
#include <canvas/core/details/base.h.inl>
#endif /* !ICE_DOXY */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <string.h>
#include <wchar.h>

CE_NAMESPACE_BEGIN

/** @brief A typedef for char. Indicates that the stored value follows UTF-8 encoding. */
typedef char ce_utf8;

/** @brief A typedef of `unsigned char`. Represents an unsigned byte value. */
typedef unsigned char ce_byte;

/** @brief A typedef of `signed char`. Represents a signed byte value. */
typedef signed char ce_sbyte;

/**
 * @ingroup types
 * @brief A boolean type (`bool` in C++ or `_Bool` in C11)
 */
typedef icebool cebool;

/**
 * @ingroup types
 * @brief [`cebool`](@ref cebool) value representing a `true` value.
 */
#define cetrue icetrue

/**
 * @ingroup types
 * @brief [`cebool`](@ref cebool) value representing a `false` value.
 */
#define cefalse icefalse

/**
 * @ingroup utility
 * @brief add documentation here!
 */
typedef struct ce_version {
  unsigned int patch : 14; /* add documentation here! */
  unsigned int minor : 12; /* add documentation here! */
  unsigned int major : 6;  /* add documentation here! */
} ce_version;

/**
 * @ingroup utility
 * @brief add documentation here!
 */
#define CE_VERSION(major, minor, patch) (((major) << 24) | ((minor) << 24) | (patch))

/**
 * @ingroup utility
 * @brief add documentation here!
 */
#define CE_CURRVER CE_VERSION(ICE_VERSION_MAJOR, ICE_VERSION_MINOR, ICE_VERSION_PATCH)

/**
 * @ingroup utility
 * @brief Gets the number of elements in a fixed sized array 
 */
#define CE_ARRLEN(arr) (sizeof(arr) / sizeof(*(arr)))

#if defined(CANVAS_DEBUG) || defined(ICE_INTELLI) || defined(ICE_DOXY)

/**
 * @brief
 *    Disable debug logs. On non-debug builds this is equivalent to a no-op.
 */
CE_API void ce_disable_debug_logs(void);

#else
#define ce_disable_debug_logs() ((void)0)
#endif /* !ICE_INTELLI */

CE_NAMESPACE_END

#endif /* !CANVAS_CORE_BASE_H */
