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

#ifndef CANVAS_THREADS_ATOMIC_H
#define CANVAS_THREADS_ATOMIC_H

#define CE_MEMORD int
#define CE_MEMORD_RELAXED /* implementation-defined */
#define CE_MEMORD_CONSUME /* implementation-defined */
#define CE_MEMORD_ACQUIRE /* implementation-defined */
#define CE_MEMORD_RELEASE /* implementation-defined */
#define CE_MEMORD_ACQ_REL /* implementation-defined */
#define CE_MEMORD_SEQ_CST /* implementation-defined */

#define CANVAS_ATOMIC_BOOL_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_CHAR_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_SHORT_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_INT_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_LONG_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_LLONG_LOCK_FREE /* implementation-defined */
#define CANVAS_ATOMIC_POINTER_LOCK_FREE /* implementation-defined */

#define ce_atomic_is_lock_free /* implementation-defined */
#define ce_atomic_store /* implementation-defined */
#define ce_atomic_store_explicit /* implementation-defined */
#define ce_atomic_load /* implementation-defined */
#define ce_atomic_load_explicit /* implementation-defined */
#define ce_atomic_exchange /* implementation-defined */
#define ce_atomic_exchange_explicit /* implementation-defined */
#define ce_atomic_compare_exchange_strong /* implementation-defined */
#define ce_atomic_compare_exchange_strong_explicit /* implementation-defined */
#define ce_atomic_compare_exchange_weak /* implementation-defined */
#define ce_atomic_compare_exchange_weak_explicit /* implementation-defined */
#define ce_atomic_fetch_add /* implementation-defined */
#define ce_atomic_fetch_add_explicit /* implementation-defined */
#define ce_atomic_fetch_sub /* implementation-defined */
#define ce_atomic_fetch_sub_explicit /* implementation-defined */
#define ce_atomic_fetch_or /* implementation-defined */
#define ce_atomic_fetch_or_explicit /* implementation-defined */
#define ce_atomic_fetch_xor /* implementation-defined */
#define ce_atomic_fetch_xor_explicit /* implementation-defined */
#define ce_atomic_fetch_and /* implementation-defined */
#define ce_atomic_fetch_and_explicit /* implementation-defined */

#define ce_atomic_thread_fence /* implementation-defined */
#define ce_atomic_signal_fence /* implementation-defined */

#define ce_atomic_bool /* implementation-defined */
#define ce_atomic_char /* implementation-defined */
#define ce_atomic_schar /* implementation-defined */
#define ce_atomic_uchar /* implementation-defined */
#define ce_atomic_short /* implementation-defined */
#define ce_atomic_ushort /* implementation-defined */
#define ce_atomic_int /* implementation-defined */
#define ce_atomic_uint /* implementation-defined */
#define ce_atomic_long /* implementation-defined */
#define ce_atomic_ulong /* implementation-defined */
#define ce_atomic_longlong /* implementation-defined */
#define ce_atomic_ulonglong /* implementation-defined */
#define ce_atomic_pointer(type) /* implementation-defined */

#define ce_atomic_init /* implementation-defined */
#define CE_ATOMIC_VAR_INIT /* implementation-defined */
#define CE_ATOMIC_FLAG_INIT /* implementation-defined */

#define ce_atomic_flag /* implementation-defined */
#define ce_atomic_flag_test_and_set /* implementation-defined */
#define ce_atomic_flag_test_and_set_explicit /* implementation-defined */
#define ce_atomic_flag_clear /* implementation-defined */
#define ce_atomic_flag_clear_explicit /* implementation-defined */

#define ce_kill_dependency(in) /* implementation-defined */

/**
 * * CANVAS_NO_MUTEX_ATOMICS
 * 	If no atomics implementation is available, a mutex is used to lock the variable.
 *  Defining this macro disables this behaviour and no atomics API will be available.
 */

#include <canvas/threads/mutex.h>
#include <canvas/threads/details/atomic.h.inl>

#endif /* !CANVAS_THREADS_ATOMIC_H */
