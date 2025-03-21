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
#  define CANVAS_EXPOSE_VULKAN
#  if CANVAS_PLATFORM_UNIX
#    define CANVAS_EXPOSE_WAYLAND
#    define CANVAS_EXPOSE_XLIB
#  elif CANVAS_PLATFORM_WINDOWS
#    define CANVAS_EXPOSE_WIN32
#  endif
#endif

#if !defined(CANVAS_SKIP_COMPILER_CHECKS) && !CE_C11_STD
#  error CanvasEngine requires C11 to compile
#endif

#if CANVAS_COMPILER_GNU
#define ICE_API __attribute__((visibility("hidden")))
#else
#define ICE_API
#endif

#define CONCATX(a, b) a##b
#define CONCAT(a, b) CONCATX(a, b)
#define STRIFYX(in) #in
#define STRIFY(in) STRIFYX(in)

#ifdef CANVAS_DEBUG
#define ICE_DEB(x) x
#define ICE_NDEB(x)
#define ICE_DEBCON(x, y) x
#else
#ifndef NDEBUG
#define NDEBUG
#endif
#define ICE_DEB(x)
#define ICE_NDEB(x) x
#define ICE_DEBCON(x, y) y
#endif

#include <canvas/core/memory.h>
#if CANVAS_PLATFORM_UNIX
#  include <unistd.h>
#  if _POSIX_VERSION < 200809L
#    error CanvasEngine requires POSIX.1-2008 compatibility
#  endif
#elif CANVAS_PLATFORM_WINDOWS
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <SDKDDKVer.h>
#  include <Windows.h>
#  include <synchapi.h>
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
#include "icore_ascii.h"

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

CE_NAMESPACE_BEGIN

ICE_API void* ialloc(size_t bytes, ce_err* opt_err);
ICE_API void ifree(void* addr, size_t bytes);

/* Convert errno value to ce_err. */
ICE_API ce_err ifrom_errno(int in);
#define ierrno ifrom_errno(errno)

#define ISTRIFYX(in) #in
#define ISTRIFY(in) ISTRIFYX(in)

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

#define IERRALLOC(bytes) ialloc(bytes, &IERRVAL); IERRDO(IERRVAL)

#define IERRALLOC_TYPE(type) ((type*)ialloc(sizeof(type), &IERRVAL)); IERRDO(IERRVAL)
#define IALLOC_TYPE(type, opt_err) ((type*)ialloc(sizeof(type), (opt_err)))
#define IFREE_TYPE(in) ifree((in), sizeof(*(in)))

#ifdef CANVAS_DEBUG

ICE_API extern cebool ideblog_enabled;

static inline void ilog_impl(
  FILE*       stream,
  const char* pre_text,
  const char* fmt, ...
) {
  if (!ideblog_enabled) {
    return;
  }
  
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

#define ICE_ASSERT(cond) assert(cond)

#if CANVAS_PLATFORM_UNIX
#include "icore_unix.h"
#elif CANVAS_PLATFORM_WINDOWS
#include "icore_win32.h"
#endif

CE_NAMESPACE_END

#endif /* !ICORE_BASE_H */
