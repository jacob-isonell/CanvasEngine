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

#ifndef ICORE_BASE_H
#define ICORE_BASE_H

#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE
#define _FILE_OFFSET_BITS 64
#define _ISOC11_SOURCE
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <canvas/core/base.h>

#ifdef CANVAS_GRAPHICS
#	define CANVAS_GRAPHICS_EXPOSE_VULKAN
#	if CANVAS_PLATFORM_UNIX
#		define CANVAS_GRAPHICS_EXPOSE_WAYLAND
#		define CANVAS_GRAPHICS_EXPOSE_X11
#	elif CANVAS_PLATFORM_WINDOWS
#		define CANVAS_GRAPHICS_EXPOSE_VULKAN
#	endif
#endif

#if !defined(CANVAS_SKIP_COMPILER_CHECKS) && !CE_C11_STD
#	error CanvasEngine requires C11 to compile
#endif

#if CANVAS_COMPILER_GNU
#define ICE_API __attribute__((visibility("hidden")))
#else
#define ICE_API
#endif

#ifndef CANVAS_DEBUG
#define NDEBUG
#endif

#include <canvas/core/memory.h>
#include <canvas/core/setup.h>
#if CANVAS_PLATFORM_UNIX
#	include <unistd.h>
/*#	if _POSIX_VERSION < 200809L
#		error CanvasEngine requires POSIX.1-2008 compatibility
#	endif*/
#elif CANVAS_PLATFORM_WINDOWS
#	define WIN32_LEAN_AND_MEAN
#	define NOMINMAX
#	include <SDKDDKVer.h>
#	include <Windows.h>
#	include <synchapi.h>
#endif

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <uchar.h>
#include <time.h>
#include <assert.h>
#include <errno.h>

/**
 * Naming scheme (this applies to regadless of capitalisation):
 *  ce_* (library API used by API consumer)
 *  ice_* (internal library usage, not intended to be used by the API user but are declared in the API header files)
 *  i* (internal stuff not exposed/accessible to API consumer)
 *  icore_* (core module)
 *  ifx_* (graphics module)
 *  iaud_* (audio module)
 *  inet_* (network module)
 */

ICE_NAMESPACE_BEGIN

#define IERRVAL i_curr_error
#define IERRBEGIN ce_err IERRVAL = CE_EOK;
#define IERRDO(expr) do { \
	IERRVAL = (expr); \
	if (ce_success(IERRVAL)) break; \
	goto IERR_ERRTHROW; \
} while (0)

#define IERREND IERR_ERRTHROW: for (cebool ierr_cond = cetrue; ce_failure(IERRVAL) && ierr_cond; ierr_cond = cefalse)

#define ICE_REQ_INIT() ICE_ASSERT(ihas_initialized())

ICE_API ce_err icore_init(void);
ICE_API void icore_shutdown(void);

ICE_API cebool ihas_initialized(void);

#define ICE_ASSERT(cond) assert(cond)

ICE_NAMESPACE_END

#endif /* !ICORE_BASE_H */
