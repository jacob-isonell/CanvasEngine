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

/** @brief add documentation here! */
#define CE_COND_INIT /* implementation-defined */

/** @brief add documentation here! */
#define ce_cnd /* implementation-defined */

#include <canvas/threads/mutex.h>
#include <canvas/threads/details/condition_variable.h.inl>

ICE_NAMESPACE_BEGIN

#ifdef CANVAS_HAS_THREADS

/** @brief add documentation here! */
CE_API
ce_err cnd_init(
	ce_cnd* cond
);

/** @brief add documentation here! */
CE_API
ce_err cnd_signal(
	ce_cnd* cond
);

/** @brief add documentation here! */
CE_API
ce_err cnd_broadcast(
	ce_cnd* cond
);

/** @brief add documentation here! */
CE_API
ce_err cnd_wait(
	ce_cnd* cond,
	ce_mtx* mutex
);

/** @brief add documentation here! */
CE_API
ce_err cnd_timedwait(
	ce_cnd* CE_RESTRICT                 cond,
	ce_mtx* CE_RESTRICT                 mutex,
	const struct ce_time_t* CE_RESTRICT time_point
);

/** @brief add documentation here! */
CE_API
void cnd_destroy(
	ce_cnd* cond
);

#endif /* !CANVAS_HAS_THREADS */

ICE_NAMESPACE_END

#endif /* !CANVAS_THREADS_CONDITION_VARIABLE_H */
