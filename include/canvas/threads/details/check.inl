/**************************************************************************
** CanvasEngine is a cross platform multimedia library in C++20          **
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

#include <canvas/core/base.h>

#undef CANVAS_HAS_THREADS
#undef CANVAS_HAS_ATOMICS
#undef ICE_THREADS_POSIX
#undef ICE_THREADS_WIN32
#undef ICE_THREADS_NONE
#undef ICE_ATOMICS_CXX11
#undef ICE_ATOMICS_C11
#undef ICE_ATOMICS_CLANG
#undef ICE_ATOMICS_GNU
#undef ICE_ATOMICS_WIN32
#undef ICE_ATOMICS_MTXIMPL
#undef ICE_NO_ATOMICS

#if CANVAS_PLATFORM_UNIX && ICE_HAS_INCLUDE(<pthread.h>)
#  define ICE_THREADS_POSIX
#  include <unistd.h>
#  include <pthread.h>
#elif CANVAS_PLATFORM_WINDOWS
#  define ICE_THREADS_WIN32
#  if !defined(WIN32_LEAN_AND_MEAN)
#    define WIN32_LEAN_AND_MEAN
#    define ICE_UNDEF_WIN32_LAM
#  endif
#  include <windows.h>
#  include <synchapi.h>
#  include <process.h>
#  if defined(ICE_UNDEF_WIN32_LAM)
#    undef WIN32_LEAN_AND_MEAN
#  endif
#else
#  define ICE_THREADS_NONE
#endif

#if CE_CXX11_STD
#  define ICE_ATOMICS_CXX11
#elif CE_C11_STD && !defined(__STDC_NO_ATOMICS__)
#  define ICE_ATOMICS_C11
#elif CANVAS_COMPILER_CLANG && CE_C11_STD
#  define ICE_ATOMICS_CLANG
#elif CANVAS_COMPILER_GNU && CE_C11_STD
#  define ICE_ATOMICS_GNU
#elif CANVAS_PLATFORM_WINDOWS
#  define ICE_ATOMICS_WIN32
#elif !defined(CANVAS_NO_MUTEX_ATOMICS) && defined(UINTPTR_T) && UINTPTR_MAX <= UINTMAX_MAX
#  define ICE_ATOMICS_MTXIMPL
#else
#  define ICE_NO_ATOMICS
#endif

#if !defined(ICE_THREADS_NONE) || defined(ICE_DOCS)
#define CANVAS_HAS_THREADS 1
#endif
#if !defined(ICE_NO_ATOMICS) || defined(ICE_DOCS)
#define CANVAS_HAS_ATOMICS 1
#endif
