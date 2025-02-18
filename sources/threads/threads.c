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

#include "icore_base.h"
#include <canvas/threads/thread.h>
#include <stdint.h>
#ifdef ICE_THREADS_POSIX
#include <sched.h>
#endif

#ifndef ICE_THREADS_NONE

#if defined(ICE_THREADS_POSIX)
struct i_thread_start_data_t {
	int (*func)(void*);
	void* arg;
};

static void* i_thread_start(void* in) {
	struct i_thread_start_data_t data = *(struct i_thread_start_data_t*)in;
	ce_free(in);
	const intptr_t out = data.func(data.arg);
	return (void*)out;
}
#elif defined(ICE_THREADS_WIN32)
struct i_thread_start_data_t {
	int (*func)(void*);
};

static unsigned int CE_STDCALL i_thread_start(void* in) {
	struct i_thread_start_data_t* const p = (struct i_thread_start_data_t*)in;
}
#endif

CE_API ce_err ce_thrd_create(ce_thrd_t* out, int(*func)(void*), void* arg) {
	if (func == NULL || out == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	ce_err err;
	struct i_thread_start_data_t* data;
	data = ce_alloc_s(sizeof(*data), &err);
	if (ce_success(err)) {
		data->func = func;
		data->arg = arg;
		err = ifrom_errno(pthread_create(out, NULL, &i_thread_start, data));
	}
	if (ce_failure(err)) {
		ce_free(data);
	}
	return err;
#elif defined(ICE_THREADS_WIN32)
	// _beginthreadex(NULL, 0, &i_thread_start, );
#endif
}

CE_API cebool ce_thrd_equal(ce_thrd_t lhs, ce_thrd_t rhs) {
#if defined(ICE_THREADS_POSIX)
	return pthread_equal(lhs, rhs);
#elif defined(ICE_THREADS_WIN32)
	
#endif
}

CE_API ce_thrd_t ce_thrd_current(void) {
#if defined(ICE_THREADS_POSIX)
	return pthread_self();
#elif defined(ICE_THREADS_WIN32)
	
#endif
}

CE_API unsigned long ce_thrd_id(ce_thrd_t thrd) {
#if defined(ICE_THREADS_POSIX)
	return thrd;
#elif defined(ICE_THREADS_WIN32)
	
#endif
}

CE_API ce_err ce_thrd_sleep(const struct ce_time_t* duration, struct ce_time_t* opt_remaining) {
	if (duration == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	struct timespec dur, rem;
	dur.tv_sec = duration->sec;
	dur.tv_nsec = duration->nsec;
	if (nanosleep(&dur, &rem) != 0) {
		if (opt_remaining) {
			opt_remaining->sec = rem.tv_sec;
			opt_remaining->nsec = rem.tv_nsec;
		}
		return ifrom_errno(errno);
	}
	return CE_EOK;
#elif defined(ICE_THREADS_WIN32)
	struct ce_time_t begin, end;
	DWORD sleep_status;
	IERRBEGIN {
		IERRDO(ce_time_get(&begin, CE_TIME_UTC));
		sleep_status = SleepEx((DWORD)ce_time_imilli(duration), TRUE);
		IERRDO(ce_time_get(&end, CE_TIME_UTC));
		if (opt_remaining) {
			*opt_remaining = ce_time_sub(end, begin);
		}
	} IERREND {
		return IERRVAL;
	}
	switch (sleep_status) {
	case 0:                  return CE_EOK;
	case WAIT_IO_COMPLETION: return CE_EINTR;
	default:                 return CE_EFAIL;
	}
#endif
}

CE_API ce_err ce_thrd_yield(void) {
#if defined(ICE_THREADS_POSIX)
	if (sched_yield() == 0) {
		return CE_EOK;
	}
	return ifrom_errno(errno);
#elif defined(ICE_THREADS_WIN32)
	switch (SwitchToThread()) {
	case FALSE: return CE_EUNKNOWN;
	default:    return CE_EOK;
	}
#endif
}

CE_ATTR_NORET CE_API void ce_thrd_exit(int res) {
#if defined(ICE_THREADS_POSIX)
	const intptr_t p = res;
	pthread_exit((void*)p);
#elif defined(ICE_THREADS_WIN32)
	ExitThread((DWORD)res);
#endif
}

CE_API ce_err ce_thrd_detach(ce_thrd_t thrd) {
#if defined(ICE_THREADS_POSIX)
	return ifrom_errno(pthread_detach(thrd));
#elif defined(ICE_THREADS_WIN32)
	if (thrd.handle == NULL || GetCurrentThreadId() != GetThreadId(thrd.handle)) {
		return CE_EINVAL;
	}
	switch (CloseHandle(thrd.handle)) {
	case FALSE: return CE_EOK;
	default:    return CE_EUNKNOWN;
	}
#endif
}

CE_API ce_err ce_thrd_join(ce_thrd_t thrd, int* opt_res) {
#if defined(ICE_THREADS_POSIX)
	intptr_t res;
	const ce_err err = ifrom_errno(pthread_join(thrd, (void**)&res));
	if (ce_success(err) && opt_res) {
		*opt_res = (int)res;
	}
	return err;
#elif defined(ICE_THREADS_WIN32)
	
#endif
}

CE_API ce_err ce_thrd_run(int (*func)(void*), void* arg) {
	if (func == NULL) {
		return CE_EINVAL;
	}
	
	ce_thrd_t thrd;
	ce_err err = ce_thrd_create(&thrd, func, arg);
	if (ce_success(err)) {
		err = ce_thrd_detach(thrd);
	}
	return err;
}

CE_API ce_err ce_call_once(ce_once_flag_t* flag, void (*func)(void)) {
	if (flag == NULL || func == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	pthread_once(flag, func);
	return CE_EOK;
#elif defined(ICE_THREADS_WIN32)
	EnterCriticalSection(&flag->mtx);
	if (!flag->called) {
		flag->called = canvas_true;
		func();
	}
	LeaveCriticalSection(&flag->mtx);
	return CE_EOK;
#endif
}

#endif /* !ICE_THREADS_NONE */
