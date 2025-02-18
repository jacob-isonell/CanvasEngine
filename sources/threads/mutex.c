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

#ifndef ICE_THREADS_NONE

static cebool s_check_mtx_type(CE_MTX_TYPE type) {
	switch (type) {
	case CE_MTX_PLAIN:
	case CE_MTX_TIMED:
	case CE_MTX_PLAIN | CE_MTX_RECURSIVE_BIT:
	case CE_MTX_TIMED | CE_MTX_RECURSIVE_BIT:
		return cetrue;
	default: return cefalse;
	}
}

static int s_to_pthread(CE_MTX_TYPE type) {
	switch (type) {
	case CE_MTX_PLAIN: return PTHREAD_MUTEX_DEFAULT;
	case CE_MTX_TIMED: return PTHREAD_MUTEX_DEFAULT;
	case CE_MTX_PLAIN | CE_MTX_RECURSIVE_BIT: return PTHREAD_MUTEX_RECURSIVE;
	case CE_MTX_TIMED | CE_MTX_RECURSIVE_BIT: return PTHREAD_MUTEX_RECURSIVE;
	default: CE_UNREACHABLE();
	}
}

CE_API ce_err ce_mtx_init(ce_mtx* mtx, CE_MTX_TYPE type) {
	if (mtx == NULL || !s_check_mtx_type(type)) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	pthread_mutexattr_t attr;
	IERRBEGIN {
		IERRDO_ERRNO(pthread_mutexattr_init(&attr));
		pthread_mutexattr_settype(&attr, s_to_pthread(type));
		IERRDO_ERRNO(pthread_mutex_init(mtx, &attr));
		pthread_mutexattr_destroy(&attr);
	} IERREND {
		pthread_mutexattr_destroy(&attr);
	}
	return IERRVAL;
#elif defined(ICE_THREADS_WIN32)
	
#endif
}
CE_API ce_err ce_mtx_lock(ce_mtx* mtx) {
	if (mtx == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ifrom_errno(pthread_mutex_lock(mtx));
#elif defined(ICE_THREADS_WIN32)
	
#endif
}
CE_API ce_err ce_mtx_timedlock(ce_mtx* CE_RESTRICT mtx, const struct ce_time_t* CE_RESTRICT time_point) {
	if (mtx == NULL || time_point == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	struct timespec t;
	t.tv_sec = time_point->sec;
	t.tv_nsec = time_point->nsec;
	return ifrom_errno(pthread_mutex_timedlock(mtx, &t));
#elif defined(ICE_THREADS_WIN32)
	
#endif
}
CE_API ce_err ce_mtx_trylock(ce_mtx* mtx) {
	if (mtx == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ifrom_errno(pthread_mutex_trylock(mtx));
#elif defined(ICE_THREADS_WIN32)
	
#endif
}
CE_API ce_err ce_mtx_unlock(ce_mtx* mtx) {
	if (mtx == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ifrom_errno(pthread_mutex_unlock(mtx));
#elif defined(ICE_THREADS_WIN32)
	
#endif
}
CE_API void ce_mtx_destroy(ce_mtx* mtx) {
	if (mtx == NULL) {
		return;
	}
	
#if defined(ICE_THREADS_POSIX)
	pthread_mutex_destroy(mtx);
#elif defined(ICE_THREADS_WIN32)
	
#endif
}

#endif /* !CANVAS_NO_THREADS */
