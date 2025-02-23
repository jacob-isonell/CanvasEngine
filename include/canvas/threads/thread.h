/**************************************************************************
** CanvasEngine is a cross platform multimedia library in C++20          **
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

#ifndef CANVAS_THREADS_THREAD_H
#define CANVAS_THREADS_THREAD_H

/** @brief If macro is defined if the thread API is available for CanvasEngine. */
#define CANVAS_HAS_THREADS /* implementation-defined */

/** @brief missing documentation. */
#define ce_thrd /* implementation-defined */

/** @brief missing documentation. */
#define ce_once_flag /* implementation-defined */

/** @brief missing documentation. */
#define CE_ONCE_FLAG_INIT /* implementation-defined */

#include <canvas/core/time.h>
#include <canvas/threads/details/check.inl>
#include <canvas/threads/details/thread.h.inl>

ICE_NAMESPACE_BEGIN

#ifdef CANVAS_HAS_THREADS

/** @brief missing documentation. */
CE_API
ce_err ce_thrd_create(
	ce_thrd* out,
	int    (*func)(void*),
	void*    arg
);

/** @brief missing documentation. */
CE_API
cebool ce_thrd_equal(
	ce_thrd lhs,
	ce_thrd rhs
);

/** @brief missing documentation. */
CE_API
ce_thrd ce_thrd_current(
	void
);

/** @brief missing documentation. */
CE_API
unsigned long ce_thrd_id(
	ce_thrd thrd
);

/** @brief missing documentation. */
CE_API
ce_err ce_thrd_sleep(
	const struct ce_time_t* duration,
	struct ce_time_t*       opt_remaining
);

/** @brief missing documentation. */
CE_API
ce_err ce_thrd_yield(
	void
);

/** @brief missing documentation. */
CE_ATTR_NORET CE_API
void ce_thrd_exit(
	int res
);

/** @brief missing documentation. */
CE_API
ce_err ce_thrd_detach(
	ce_thrd thrd
);

/** @brief missing documentation. */
CE_API
ce_err ce_thrd_join(
	ce_thrd thrd,
	int*    opt_res
);

/** @brief missing documentation. */
CE_API
ce_err ce_thrd_run(
	int (*func)(void*),
	void* arg
);

/** @brief missing documentation. */
CE_API
ce_err ce_call_once(
	ce_once_flag* flag,
	void        (*func)(void)
);

#endif /* !CANVAS_HAS_THREADS */

ICE_NAMESPACE_END

#endif /* !CANVAS_THREADS_THREAD_H */
