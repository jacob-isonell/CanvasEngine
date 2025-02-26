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
#define VK_NO_PROTOTYPES
#include <canvas/core/base.h>

#ifdef CANVAS_GRAPHICS
#	define CANVAS_EXPOSE_VULKAN
#	if CANVAS_PLATFORM_UNIX
#		define CANVAS_EXPOSE_WAYLAND
#		define CANVAS_EXPOSE_X11
#	elif CANVAS_PLATFORM_WINDOWS
#		define CANVAS_EXPOSE_WIN32
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

#ifdef CANVAS_DEBUG
#define ICE_DEB(x) x
#define ICE_NDEB(x)
#define ICE_DEBCON(x, y) x
#else
#define NDEBUG
#define ICE_DEB(x)
#define ICE_NDEB(x) x
#define ICE_DEBCON(x, y) y
#endif

#include <canvas/core/memory.h>
#include <canvas/core/setup.h>
#if CANVAS_PLATFORM_UNIX
#	include <unistd.h>
#	if _POSIX_VERSION < 200809L
#		error CanvasEngine requires POSIX.1-2008 compatibility
#	endif
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
#include <stdarg.h>

/**
 * Naming scheme (this applies to regadless of capitalisation):
 *  ce_* (library API used by API consumer)
 *  ice_* (internal library usage, not intended to be used by the API user but are declared in the API header files)
 *  i* (internal stuff not exposed/accessible to API consumer)
 *    icore_* (core module)
 *    ifx_* (graphics module)
 *      ivk_* (vulkan api)
 *    iaud_* (audio module)
 *    inet_* (network module)
 */

ICE_NAMESPACE_BEGIN

#define ISTRIFYX(in) #in
#define ISTRIFY(in) ISTRIFYX(in)

#define IASCII_ESCAPE "\x1B"
#define IASCII_BLACK         IASCII_ESCAPE "[0;30m"
#define IASCII_RED           IASCII_ESCAPE "[0;31m"
#define IASCII_GREEN         IASCII_ESCAPE "[0;32m"
#define IASCII_YELLOW        IASCII_ESCAPE "[0;33m"
#define IASCII_BLUE          IASCII_ESCAPE "[0;34m"
#define IASCII_PURPLE        IASCII_ESCAPE "[0;35m"
#define IASCII_CYAN          IASCII_ESCAPE "[0;36m"
#define IASCII_WHITE         IASCII_ESCAPE "[0;37m"
#define IASCII_BOLD_BLACK    IASCII_ESCAPE "[1;30m"
#define IASCII_BOLD_RED      IASCII_ESCAPE "[1;31m"
#define IASCII_BOLD_GREEN    IASCII_ESCAPE "[1;32m"
#define IASCII_BOLD_YELLOW   IASCII_ESCAPE "[1;33m"
#define IASCII_BOLD_BLUE     IASCII_ESCAPE "[1;34m"
#define IASCII_BOLD_PURPLE   IASCII_ESCAPE "[1;35m"
#define IASCII_BOLD_CYAN     IASCII_ESCAPE "[1;36m"
#define IASCII_BOLD_WHITE    IASCII_ESCAPE "[1;37m"
#define IASCII_UL_BLACK      IASCII_ESCAPE "[4;30m"
#define IASCII_UL_RED        IASCII_ESCAPE "[4;31m"
#define IASCII_UL_GREEN      IASCII_ESCAPE "[4;32m"
#define IASCII_UL_YELLOW     IASCII_ESCAPE "[4;33m"
#define IASCII_UL_BLUE       IASCII_ESCAPE "[4;34m"
#define IASCII_UL_PURPLE     IASCII_ESCAPE "[4;35m"
#define IASCII_UL_CYAN       IASCII_ESCAPE "[4;36m"
#define IASCII_UL_WHITE      IASCII_ESCAPE "[4;37m"
#define IASCII_BG_BLACK      IASCII_ESCAPE "[40m"
#define IASCII_BG_RED        IASCII_ESCAPE "[41m"
#define IASCII_BG_GREEN      IASCII_ESCAPE "[42m"
#define IASCII_BG_YELLOW     IASCII_ESCAPE "[43m"
#define IASCII_BG_BLUE       IASCII_ESCAPE "[44m"
#define IASCII_BG_PURPLE     IASCII_ESCAPE "[45m"
#define IASCII_BG_CYAN       IASCII_ESCAPE "[46m"
#define IASCII_BG_WHITE      IASCII_ESCAPE "[47m"
#define IASCII_HI_BLACK      IASCII_ESCAPE "[0;90m"
#define IASCII_HI_RED        IASCII_ESCAPE "[0;91m"
#define IASCII_HI_GREEN      IASCII_ESCAPE "[0;92m"
#define IASCII_HI_YELLOW     IASCII_ESCAPE "[0;93m"
#define IASCII_HI_BLUE       IASCII_ESCAPE "[0;94m"
#define IASCII_HI_PURPLE     IASCII_ESCAPE "[0;95m"
#define IASCII_HI_CYAN       IASCII_ESCAPE "[0;96m"
#define IASCII_HI_WHITE      IASCII_ESCAPE "[0;97m"
#define IASCII_HIBOLD_BLACK  IASCII_ESCAPE "[1;90m"
#define IASCII_HIBOLD_RED    IASCII_ESCAPE "[1;91m"
#define IASCII_HIBOLD_GREEN  IASCII_ESCAPE "[1;92m"
#define IASCII_HIBOLD_YELLOW IASCII_ESCAPE "[1;93m"
#define IASCII_HIBOLD_BLUE   IASCII_ESCAPE "[1;94m"
#define IASCII_HIBOLD_PURPLE IASCII_ESCAPE "[1;95m"
#define IASCII_HIBOLD_CYAN   IASCII_ESCAPE "[1;96m"
#define IASCII_HIBOLD_WHITE  IASCII_ESCAPE "[1;97m"
#define IASCII_HIBG_BLACK    IASCII_ESCAPE "[0;100m"
#define IASCII_HIBG_RED      IASCII_ESCAPE "[0;101m"
#define IASCII_HIBG_GREEN    IASCII_ESCAPE "[0;102m"
#define IASCII_HIBG_YELLOW   IASCII_ESCAPE "[0;103m"
#define IASCII_HIBG_BLUE     IASCII_ESCAPE "[0;104m"
#define IASCII_HIBG_PURPLE   IASCII_ESCAPE "[0;105m"
#define IASCII_HIBG_CYAN     IASCII_ESCAPE "[0;106m"
#define IASCII_HIBG_WHITE    IASCII_ESCAPE "[0;107m"
#define IASCII_RESET         IASCII_ESCAPE "[0m"

#define ICE_REQ_INIT() ICE_ASSERT(ihas_initialized())

/* Starts an error checking scope (similar to a try/catch scope).
 */
#define IERRBEGIN ce_err IERRVAL = CE_EOK; do

/* Ends an error checking scope. Any error causes a jump to the end
 * of the error checking scope to perform error handling.
 */
#define IERREND \
while (0); IERR_ERRTHROW:\
	for (cebool ierr_cond = cetrue; ce_failure(IERRVAL) && ierr_cond; ierr_cond = cefalse)

/* Checks if `in` holds an error value. If it does then
 * a jump to `IERREND` is performed.
 */
#define IERRDO(in) do { \
	IERRVAL = (in); \
	if (ce_success(IERRVAL)) break; \
	goto IERR_ERRTHROW; \
} while (0)


#ifdef CANVAS_DEBUG

static inline void ilog_impl(
	FILE*       stream,
	const char* pre_text,
	const char* fmt, ...
) {
	va_list args;
	va_start(args, fmt);
	fputs(pre_text, stream);
	vfprintf(stream, fmt, args);
	fputs(IASCII_RESET, stream);
	va_end(args);
}

#define IDEBLOG(...)   ilog_impl(stdout, IASCII_CYAN "[CE_LOG] " __FILE__ ":" ISTRIFY(__LINE__) " ", __VA_ARGS__)
#define IDEBWARN(...)  ilog_impl(stdout, IASCII_CYAN "[CE_WARN] " __FILE__ ":" ISTRIFY(__LINE__) " ", __VA_ARGS__)
#define IDEBERROR(...) ilog_impl(stdout, IASCII_CYAN "[CE_ERR] " __FILE__ ":" ISTRIFY(__LINE__) " ", __VA_ARGS__)
#else
#define IDEBLOG(...)   ((void)0)
#define IDEBWARN(...)  ((void)0)
#define IDEBERROR(...) ((void)0)
#endif

ICE_API ce_err icore_init(void);
ICE_API void icore_shutdown(void);

/* Bool is the CanvasEngine library has been initalized (same as checking `icore.init_count > 0`).
 * Used for implementing `ICE_REQ_INIT` without including `icore_global.h`.
 */
ICE_API cebool ihas_initialized(void);

/* Convert errno value to ce_err. */
ICE_API ce_err ierrno(int in);

/* Convert errno value to ce_err and clear `errno`. */
ICE_API ce_err ierrno_cls(int in);

ICE_API ce_err icore_str2wcs(wchar_t* buffer, size_t buffer_count, const char* src, size_t opt_srclen, size_t* opt_out_len);
ICE_API ce_err icore_wcs2str(char* buffer, size_t buffer_count, const wchar_t* src, size_t opt_srclen, size_t* opt_out_len);

#define ICE_ASSERT(cond) assert(cond)

ICE_NAMESPACE_END

#endif /* !ICORE_BASE_H */
