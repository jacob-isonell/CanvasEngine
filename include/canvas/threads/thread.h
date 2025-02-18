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

#ifndef CANVAS_THREADS_THREAD_H
#define CANVAS_THREADS_THREAD_H

#include <canvas/core/time.h>

#if CANVAS_PLATFORM_UNIX && ICE_HAS_INCLUDE(<pthread.h>)
#	define ICE_THREADS_POSIX
#	include <unistd.h>
#	include <pthread.h>
#elif CANVAS_PLATFORM_WINDOWS
#	define ICE_THREADS_WIN32
#	if !defined(WIN32_LEAN_AND_MEAN)
#		define WIN32_LEAN_AND_MEAN
#		define ICE_UNDEF_WIN32_LAM
#	endif
#	include <windows.h>
#	include <synchapi.h>
#	include <process.h>
#	if defined(ICE_UNDEF_WIN32_LAM)
#		undef WIN32_LEAN_AND_MEAN
#	endif
#else
#	define ICE_THREADS_NONE
#endif

ICE_NAMESPACE_BEGIN

#ifndef ICE_THREADS_NONE
#define CANVAS_HAS_THREADS 1

#if defined(ICE_THREADS_POSIX)
#define ce_thrd_t pthread_t
#define ce_once_flag_t pthread_once_t
#define CE_ONCE_FLAG_INIT PTHREAD_ONCE_INIT
#elif defined(ICE_THREADS_WIN32)
struct ice_thread_impl_t {
	HANDLE handle;
};

struct ice_once_flag_t {
	CRITICAL_SECTION mtx;
	cebool called;
};
#define ce_thrd_t struct ice_thread_impl_t
#define ce_once_flag_t pthread_once_t
#define CE_ONCE_FLAG_INIT {0}
#endif

CE_API ce_err ce_thrd_create(ce_thrd_t* out, int (*func)(void*), void* arg);
CE_API cebool ce_thrd_equal(ce_thrd_t lhs, ce_thrd_t rhs);
CE_API ce_thrd_t ce_thrd_current(void);
CE_API unsigned long ce_thrd_id(ce_thrd_t thrd);
CE_API ce_err ce_thrd_sleep(const struct ce_time_t* duration, struct ce_time_t* opt_remaining);
CE_API ce_err ce_thrd_yield(void);
CE_ATTR_NORET CE_API void ce_thrd_exit(int res);
CE_API ce_err ce_thrd_detach(ce_thrd_t thrd);
CE_API ce_err ce_thrd_join(ce_thrd_t thrd, int* opt_res);

/** @brief Creates a new thread running the given function. Does not wait for the thread to finish. */
CE_API ce_err ce_thrd_run(int (*func)(void*), void* arg);

CE_API ce_err ce_call_once(ce_once_flag_t* flag, void (*func)(void));

#else
#define CANVAS_HAS_THREADS 0
#endif /* !CANVAS_NO_THREADS */

ICE_NAMESPACE_END

#endif /* !CANVAS_THREADS_THREAD_H */
