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
#include <canvas/threads/condition_variable.h>

#ifdef CANVAS_HAS_THREADS

CE_API ce_err cnd_init(ce_cnd* cond) {
	if (cond == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ierrno(pthread_cond_init(cond, NULL));
#elif defined(ICE_THREADS_WIN32)
	ICE_NOIMPL();
#endif
}

CE_API ce_err cnd_signal(ce_cnd* cond) {
	if (cond == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ierrno(pthread_cond_signal(cond));
#elif defined(ICE_THREADS_WIN32)
	ICE_NOIMPL();
#endif
}

CE_API ce_err cnd_broadcast(ce_cnd* cond) {
	if (cond == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ierrno(pthread_cond_broadcast(cond));
#elif defined(ICE_THREADS_WIN32)
	ICE_NOIMPL();
#endif
}

CE_API ce_err cnd_wait(ce_cnd* cond, ce_mtx* mtx) {
	if (cond == NULL || mtx == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	return ierrno(pthread_cond_wait(cond, mtx));
#elif defined(ICE_THREADS_WIN32)
	ICE_NOIMPL();
#endif
}

CE_API ce_err cnd_timedwait(ce_cnd* CE_RESTRICT cond, ce_mtx* CE_RESTRICT mtx, const struct ce_time_t* CE_RESTRICT time_point) {
	if (cond == NULL || mtx == NULL || time_point == NULL) {
		return CE_EINVAL;
	}
	
#if defined(ICE_THREADS_POSIX)
	struct timespec t;
	t.tv_sec = time_point->sec;
	t.tv_nsec = time_point->nsec;
	return ierrno(pthread_cond_timedwait(cond, mtx, &t));
#elif defined(ICE_THREADS_WIN32)
	ICE_NOIMPL();
#endif
}

CE_API void cnd_destroy(ce_cnd* cond) {
	if (cond == NULL) {
		return;
	}
	
#if defined(ICE_THREADS_POSIX)
	pthread_cond_destroy(cond);
#elif defined(ICE_THREADS_WIN32)
	ICE_NOIMPL();
#endif
}

#endif /* !CANVAS_HAS_THREADS */
