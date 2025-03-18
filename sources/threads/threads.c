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

#ifdef CANVAS_HAS_THREADS

typedef struct i_thread_start_data_t {
  int (*func)(void*);
  void* arg;
} i_thread_start_data_t;

#if defined(ICE_THREADS_POSIX)

static void* i_thread_start(void* in) {
  i_thread_start_data_t data = *(i_thread_start_data_t*)in;
  
  ifree(in, sizeof(data));
  const intptr_t out = data.func(data.arg);
  
  return (void*)out;
}

#elif defined(ICE_THREADS_WIN32)

static unsigned int CE_STDCALL i_thread_start(void* in) {
  i_thread_start_data_t data = *(i_thread_start_data_t*)in;
  
  ifree(in, sizeof(data));
  return (unsigned int)data.func(data.arg);
}

#endif

CE_API ce_err ce_thrd_create(ce_thrd* out, int (*func)(void*), void* arg) {
  if (func == NULL || out == NULL) {
    return CE_EINVAL;
  }
  
  ce_err err;
  i_thread_start_data_t* const data = IALLOC_TYPE(i_thread_start_data_t, &err);
  if (ce_failure(err)) {
    return err;
  }
  
  data->func = func;
  data->arg = arg;
  
#if defined(ICE_THREADS_POSIX)
  
  err = ifrom_errno(pthread_create(out, NULL, &i_thread_start, data));
  if (ce_failure(err)) {
    ifree(data, sizeof(*data));
  }
  return err;
  
#elif defined(ICE_THREADS_WIN32)
  
  union {
    uintptr_t in;
    ce_thrd out;
  } thrd_handle;
  
  thrd_handle.in = _beginthreadex(NULL, 0, &i_thread_start, data, 0, NULL);
  if (thrd_handle.in == UINTPTR_MAX) {
    ifree(data, sizeof(*data));
    return ierrno;
  }
  
  *out = thrd_handle.out;
  return CE_EOK;
  
#endif
}

CE_API cebool ce_thrd_equal(ce_thrd lhs, ce_thrd rhs) {
#if defined(ICE_THREADS_POSIX)
  
  return pthread_equal(lhs, rhs);
  
#elif defined(ICE_THREADS_WIN32)
  
  return GetThreadId(lhs) == GetThreadId(rhs);
  
#endif
}

CE_API ce_thrd ce_thrd_current(void) {
#if defined(ICE_THREADS_POSIX)
  
  return pthread_self();
  
#elif defined(ICE_THREADS_WIN32)
  
  ce_thrd out;
  out = GetCurrentThread();
  return out;
  
#endif
}

CE_API unsigned long ce_thrd_id(ce_thrd thrd) {
#if defined(ICE_THREADS_POSIX)
  
  return thrd;
  
#elif defined(ICE_THREADS_WIN32)
  
  return GetThreadId(thrd);
  
#endif
}

CE_API ce_err ce_thrd_sleep(
  const ce_time_t* CE_RESTRICT duration,
        ce_time_t* CE_RESTRICT opt_remaining
) {
  if (duration == NULL) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  
  struct timespec dur, rem;
  dur.tv_sec = (time_t)duration->sec;
  dur.tv_nsec = (long)duration->nsec;
  
  if (nanosleep(&dur, &rem) == 0) {
    return CE_EOK;
  }
  
  if (opt_remaining) {
    opt_remaining->sec = (unsigned long long)rem.tv_sec;
    opt_remaining->nsec = (unsigned long long)rem.tv_nsec;
  }
  
  return ierrno;
  
#elif defined(ICE_THREADS_WIN32)
  
  ce_time_t begin = {0};
  ce_time_t end;
  DWORD sleep_status;
  ce_err err;
  if (opt_remaining) {
    err = ce_time_get(CE_CLOCK_PERF, &begin);
    if (ce_failure(err)) {
      return err;
    }
  }
  
  sleep_status = SleepEx((DWORD)ce_time_to_imilli(*duration), TRUE);
  
  if (opt_remaining) {
    err = ce_time_get(CE_CLOCK_PERF, &end);
    if (ce_failure(err)) {
      return err;
    }
    
    *opt_remaining = ce_time_sub(end, begin);
  }
  
  switch (sleep_status) {
  case 0:                  return CE_EOK;
  case WAIT_IO_COMPLETION: return CE_EINTR;
  default:                 return CE_EUNKNOWN;
  }
  
#endif
}

CE_API ce_err ce_thrd_yield(void) {
#if defined(ICE_THREADS_POSIX)
  
  return sched_yield() == 0
    ? CE_EOK
    : ierrno;
  
#elif defined(ICE_THREADS_WIN32)
  
  return SwitchToThread() == FALSE
    ? CE_EPERM
    : CE_EOK;
  
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

CE_API ce_err ce_thrd_detach(ce_thrd thrd) {
#if defined(ICE_THREADS_POSIX)
  
  return ifrom_errno(pthread_detach(thrd));
  
#elif defined(ICE_THREADS_WIN32)
  
  if (thrd == NULL || GetCurrentThreadId() != GetThreadId(thrd)) {
    return CE_EINVAL;
  }
  
  switch (CloseHandle(thrd)) {
  case FALSE: return CE_EOK;
  default:    return CE_EUNKNOWN;
  }
  
#endif
}

CE_API ce_err ce_thrd_join(ce_thrd thrd, int* opt_res) {
#if defined(ICE_THREADS_POSIX)
  intptr_t res;
  const ce_err err = ifrom_errno(pthread_join(thrd, (void**)&res));
  if (ce_success(err) && opt_res) {
    *opt_res = (int)res;
  }
  return err;
#elif defined(ICE_THREADS_WIN32)
  if (thrd == NULL || GetCurrentThreadId() != GetThreadId(thrd)) {
    return CE_EINVAL;
  }
  
  switch (WaitForSingleObjectEx(thrd, INFINITE, FALSE)) {
  case WAIT_FAILED:
    return CE_EUNKNOWN;
  }
  
  if (opt_res) {
    GetExitCodeThread(thrd, (DWORD*)opt_res);
  }
  CloseHandle(thrd);
  return CE_EOK;
#endif
}

CE_API ce_err ce_thrd_run(int (*func)(void*), void* arg) {
  if (func == NULL) {
    return CE_EINVAL;
  }
  
  ce_thrd thrd;
  ce_err err = ce_thrd_create(&thrd, func, arg);
  if (ce_success(err)) {
    err = ce_thrd_detach(thrd);
  }
  return err;
}

CE_API ce_err ce_call_once(ce_once_flag* flag, void (*func)(void)) {
  if (flag == NULL || func == NULL) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  pthread_once(flag, func);
  return CE_EOK;
#elif defined(ICE_THREADS_WIN32)
  EnterCriticalSection(&flag->mtx);
  if (!flag->called) {
    flag->called = cetrue;
    func();
  }
  LeaveCriticalSection(&flag->mtx);
  return CE_EOK;
#endif
}

#endif /* !CANVAS_HAS_THREADS */
