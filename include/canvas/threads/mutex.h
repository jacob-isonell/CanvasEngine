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

/** @brief add documentation here! */
#define CE_MTX_TYPE int
#define CE_MTX_PLAIN 0
#define CE_MTX_TIMED 1
#define CE_MTX_RECURSIVE_BIT 2

/** @brief Initializes a ce_mtx. */
#define CE_MTX_INIT_PLAIN /* implementation-defined */

/** @brief Initializes a ce_mtx for recursive use. */
#define CE_MTX_INIT_TIMED /* implementation-defined */

/** @brief If the implementation suports it, initializes a ce_mtx for recursive use. */
#define CE_MTX_INIT_RECURSIVE /* implementation-defined */

/** @brief If the implementation suports it, initializes a ce_mtx for timed recursive use. */
#define CE_MTX_INIT_TIMED_RECURSIVE /* implementation-defined */

/** @brief add documentation here! */
#define ce_mtx /* implementation-defined */

#include <canvas/threads/thread.h>
#include <canvas/threads/details/mutex.h.inl>

ICE_NAMESPACE_BEGIN

#ifdef CANVAS_HAS_THREADS

/** @brief add documentation here! */
CE_API
ce_err ce_mtx_init(
	ce_mtx*     mtx,
	CE_MTX_TYPE type
);

/** @brief add documentation here! */
CE_API
ce_err ce_mtx_lock(
	ce_mtx* mtx
);

/** @brief add documentation here! */
CE_API
ce_err ce_mtx_timedlock(
	ce_mtx* CE_RESTRICT                 mtx,
	const struct ce_time_t* CE_RESTRICT time_point
);

/** @brief add documentation here! */
CE_API
ce_err ce_mtx_trylock(
	ce_mtx* mtx
);

/** @brief add documentation here! */
CE_API
ce_err ce_mtx_unlock(
	ce_mtx* mtx
);

/** @brief add documentation here! */
CE_API
void ce_mtx_destroy(
	ce_mtx* mtx
);

#endif /* !CANVAS_HAS_THREADS */

ICE_NAMESPACE_END

#endif /* !CANVAS_THREADS_MUTEX_H */
