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
#include <canvas/threads/mutex.h>

#ifdef CANVAS_HAS_THREADS

static cebool s_check_mtx_type(ce_mtx_kind type) {
  switch (type) {
  case CE_MTX_PLAIN:
  case CE_MTX_TIMED:
  case CE_MTX_RECURSIVE:
  case CE_MTX_TIMED_RECURSIVE:
    return cetrue;
  default: return cefalse;
  }
}

CE_WARN_PUSH
CE_WARN_DISABLE_GNU("-Wunused-function")
static cebool s_is_recursive(ce_mtx_kind type) {
  switch (type) {
    default: CE_UNREACHABLE();
    case CE_MTX_PLAIN:
    case CE_MTX_TIMED:
      return cefalse;
    case CE_MTX_RECURSIVE:
    case CE_MTX_TIMED_RECURSIVE:
      return cetrue;
  }
}
CE_WARN_POP

#ifdef ICE_THREADS_POSIX
static int s_to_pthread(ce_mtx_kind type) {
  switch (type) {
  case CE_MTX_PLAIN: return PTHREAD_MUTEX_DEFAULT;
  case CE_MTX_TIMED: return PTHREAD_MUTEX_DEFAULT;
  case CE_MTX_RECURSIVE: return PTHREAD_MUTEX_RECURSIVE;
  case CE_MTX_TIMED_RECURSIVE: return PTHREAD_MUTEX_RECURSIVE;
  default: CE_UNREACHABLE();
  }
}
#endif

CE_API ce_err ce_mtx_init(ce_mtx* mtx, ce_mtx_kind type) {
  if (mtx == NULL || !s_check_mtx_type(type)) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  
  pthread_mutexattr_t attr;
  IERRBEGIN {
    IERRDO(pthread_mutexattr_init(&attr));
    pthread_mutexattr_settype(&attr, s_to_pthread(type));
    IERRDO(pthread_mutex_init(mtx, &attr));
    pthread_mutexattr_destroy(&attr);
  } IERREND {
    pthread_mutexattr_destroy(&attr);
  }
  return IERRVAL;
  
#elif defined(ICE_THREADS_WIN32)
  
  InitializeSRWLock(&mtx->lock);
  mtx->refcount = 0;
  mtx->flags = type;
  return CE_EOK;
  
#endif
}

CE_API ce_err ce_mtx_lock(ce_mtx* mtx) {
  if (mtx == NULL) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  
  return ifrom_errno(pthread_mutex_lock(mtx));
  
#elif defined(ICE_THREADS_WIN32)
  
  if (mtx->owner == GetCurrentThreadId()) {
    if (s_is_recursive(mtx->flags)) {
      ++mtx->refcount;
      return CE_EOK;
    } else return CE_EDEADLOCK;
  }
  
  AcquireSRWLockExclusive(&mtx->lock);
  mtx->owner = GetCurrentThreadId();
  if (s_is_recursive(mtx->flags)) {
    ++mtx->refcount;
  }
  return CE_EOK;
  
#endif
}

CE_API ce_err ce_mtx_timedlock(
           ce_mtx* CE_RESTRICT mtx,
  const ce_time_t* CE_RESTRICT time_point
) {
  if (mtx == NULL || time_point == NULL) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  
  struct timespec t;
  t.tv_sec = (time_t)time_point->sec;
  t.tv_nsec = (long)time_point->nsec;
  return ifrom_errno(pthread_mutex_timedlock(mtx, &t));
  
#elif defined(ICE_THREADS_WIN32)
  
  ICE_NOIMPL();
#if 0
  if (mtx->owner == GetCurrentThreadId()) {
    if (s_is_recursive(mtx->flags)) {
      ++mtx->refcount;
      return CE_EOK;
    } else return CE_EDEADLK;
  }
  
  /* Add locking scheme here */
  
  mtx->owner = GetCurrentThreadId();
  if (s_is_recursive(mtx->flags)) {
    ++mtx->refcount;
  }
  return CE_EOK;
#endif
  
#endif
}

CE_API ce_err ce_mtx_trylock(ce_mtx* mtx) {
  if (mtx == NULL) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  
  return ifrom_errno(pthread_mutex_trylock(mtx));
  
#elif defined(ICE_THREADS_WIN32)
  
  if (mtx->owner == GetCurrentThreadId()) {
    if (s_is_recursive(mtx->flags)) {
      ++mtx->refcount;
      return CE_EOK;
    } else {
      return CE_EDEADLK;
    }
  }
  
  if (!TryAcquireSRWLockExclusive(&mtx->lock)) {
    return CE_EBUSY;
  }
  
  mtx->owner = GetCurrentThreadId();
  
  if (s_is_recursive(mtx->flags)) {
    ++mtx->refcount;
  }
  
  return CE_EOK;
  
#endif
}

CE_API ce_err ce_mtx_unlock(ce_mtx* mtx) {
  if (mtx == NULL) {
    return CE_EINVAL;
  }
  
#if defined(ICE_THREADS_POSIX)
  return ifrom_errno(pthread_mutex_unlock(mtx));
#elif defined(ICE_THREADS_WIN32)
  if (mtx->owner != GetCurrentThreadId()) {
    return CE_EPERM;
  }
  
  if (s_is_recursive(mtx->flags) && --mtx->refcount) {
    return CE_EOK;
  }
  
  mtx->owner = 0;
  ReleaseSRWLockExclusive(&mtx->lock);
  return CE_EOK;
#endif
}

CE_API void ce_mtx_destroy(ce_mtx* mtx) {
#if defined(ICE_THREADS_POSIX)
  pthread_mutex_destroy(mtx);
#else
  (void)mtx;
#endif
}

#endif /* !CANVAS_HAS_THREADS */
