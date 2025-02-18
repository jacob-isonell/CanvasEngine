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

#ifndef CANVAS_THREADS_MUTEX_H
#define CANVAS_THREADS_MUTEX_H

#include <canvas/threads/thread.h>

#ifndef ICE_THREADS_NONE

ICE_NAMESPACE_BEGIN

#define CE_MTX_TYPE int
#define CE_MTX_PLAIN 0
#define CE_MTX_TIMED 1
#define CE_MTX_RECURSIVE_BIT 2

#if defined(ICE_THREADS_POSIX)
#define ice_mtx_t pthread_mutex_t
#define CE_MTX_INIT_PLAIN PTHREAD_MUTEX_INITIALIZER
#define CE_MTX_INIT_TIMED PTHREAD_MUTEX_INITIALIZER
#ifdef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define CE_MTX_INIT_RECURSIVE PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define CE_MTX_INIT_TIMED_RECURSIVE PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#endif
#elif defined(ICE_THREADS_WIN32)
struct ice_mtx_impl_t {
	SRWLOCK     lock;
	CE_MTX_TYPE flags;
};
#define ice_mtx_t struct ice_mtx_impl_t
#define CE_MTX_INIT_PLAIN { SRWLOCK_INIT, CE_MTX_PLAIN }
#define CE_MTX_INIT_TIMED { SRWLOCK_INIT, CE_MTX_TIMED }
#define CE_MTX_INIT_RECURSIVE { SRWLOCK_INIT, CE_MTX_PLAIN | CE_MTX_RECURSIVE_BIT }
#define CE_MTX_INIT_TIMED_RECURSIVE { SRWLOCK_INIT, CE_MTX_TIMED | CE_MTX_RECURSIVE_BIT }
#endif

#define ce_mtx_t ice_mtx_t

CE_API ce_err ce_mtx_init(ce_mtx_t* mtx, CE_MTX_TYPE type);
CE_API ce_err ce_mtx_lock(ce_mtx_t* mtx);
CE_API ce_err ce_mtx_timedlock(ce_mtx_t* CE_RESTRICT mtx, const struct ce_time_t* CE_RESTRICT time_point);
CE_API ce_err ce_mtx_trylock(ce_mtx_t* mtx);
CE_API ce_err ce_mtx_unlock(ce_mtx_t* mtx);
CE_API void ce_mtx_destroy(ce_mtx_t* mtx);

ICE_NAMESPACE_END

#endif /* !CANVAS_NO_THREADS */

#endif /* !CANVAS_THREADS_MUTEX_H */
