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

#ifndef CANVAS_THREADS_CONDITION_VARIABLE_H
#define CANVAS_THREADS_CONDITION_VARIABLE_H

#include <canvas/threads/mutex.h>

#ifndef ICE_THREADS_NONE

ICE_NAMESPACE_BEGIN

#if defined(ICE_THREADS_POSIX)
#define ice_cnd_t pthread_cond_t
#define CE_COND_INIT PTHREAD_COND_INITIALIZER
#elif defined(ICE_THREADS_WIN32)
struct ice_cnd_impl_t {
	CONDITION_VARIABLE var;
};
#define ice_cnd_t struct ice_cnd_impl_t
#define CE_COND_INIT {CONDITION_VARIABLE_INIT}
#endif

#define ce_cnd_t ice_cnd_t

CE_API ce_err cnd_init(ce_cnd_t* cond);
CE_API ce_err cnd_signal(ce_cnd_t *cond);
CE_API ce_err cnd_broadcast(ce_cnd_t *cond);
CE_API ce_err cnd_wait(ce_cnd_t* cond, ce_mtx_t* mutex);
CE_API ce_err cnd_timedwait(ce_cnd_t* CE_RESTRICT cond, ce_mtx_t* CE_RESTRICT mutex, const struct ce_time_t* CE_RESTRICT time_point);
CE_API void cnd_destroy(ce_cnd_t* cond);

ICE_NAMESPACE_END

#endif /* !ICE_THREADS_NONE */

#endif /* !CANVAS_THREADS_CONDITION_VARIABLE_H */
