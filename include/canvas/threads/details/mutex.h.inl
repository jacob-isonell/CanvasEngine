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

#undef CE_MTX_INIT_PLAIN
#undef CE_MTX_INIT_TIMED
#undef CE_MTX_INIT_RECURSIVE
#undef CE_MTX_INIT_TIMED_RECURSIVE
#undef ce_mtx

#ifdef CANVAS_HAS_THREADS

#if defined(ICE_THREADS_POSIX)
#define ce_mtx pthread_mutex_t
#define CE_MTX_INIT_PLAIN PTHREAD_MUTEX_INITIALIZER
#define CE_MTX_INIT_TIMED PTHREAD_MUTEX_INITIALIZER
#ifdef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define CE_MTX_INIT_RECURSIVE PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define CE_MTX_INIT_TIMED_RECURSIVE PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#endif
#elif defined(ICE_THREADS_WIN32)
struct ice_mtx_impl {
	SRWLOCK     lock;
	CE_MTX_TYPE flags;
};
#define ce_mtx struct ice_mtx_impl
#define CE_MTX_INIT_PLAIN { SRWLOCK_INIT, CE_MTX_PLAIN }
#define CE_MTX_INIT_TIMED { SRWLOCK_INIT, CE_MTX_TIMED }
#define CE_MTX_INIT_RECURSIVE { SRWLOCK_INIT, CE_MTX_PLAIN | CE_MTX_RECURSIVE_BIT }
#define CE_MTX_INIT_TIMED_RECURSIVE { SRWLOCK_INIT, CE_MTX_TIMED | CE_MTX_RECURSIVE_BIT }
#endif

#endif /* !CANVAS_HAS_THREADS */
