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

#include <canvas/threads/mutex.h>
#include <limits.h>

/**
 * * CANVAS_NO_MUTEX_ATOMICS
 * 	If no atomics implementation is available, a mutex is used to lock the variable.
 *  Defining this macro disables this behaviour.
 */

#if CE_CXX
#	define ICE_ATOMICS_CXX11
#elif CE_C11_STD && !defined(__STDC_NO_ATOMICS__)
#	define ICE_ATOMICS_C11
#elif CANVAS_COMPILER_CLANG && CE_C11_STD
#	define ICE_ATOMICS_CLANG
#elif CANVAS_COMPILER_GNU && CE_C11_STD
#	define ICE_ATOMICS_GNU
#elif CANVAS_PLATFORM_WINDOWS
#	define ICE_ATOMICS_WIN32
#elif !defined(CANVAS_NO_MUTEX_ATOMICS) && defined(UINTPTR_T) && UINTPTR_MAX <= UINTMAX_MAX
#	define ICE_ATOMICS_MTXIMPL
#else
#	define ICE_NO_ATOMICS
#endif

/* Temporary */
#undef ICE_ATOMICS_MTXIMPL
#undef ICE_ATOMICS_WIN32
#define ICE_NO_ATOMICS
/* !Temporary */

#if defined(ICE_ATOMICS_CXX11)
#	include <atomic>
#	define ICE_ATOMIC_BOOL_LOCK_FREE     ATOMIC_BOOL_LOCK_FREE
#	define ICE_ATOMIC_CHAR_LOCK_FREE     ATOMIC_CHAR_LOCK_FREE
#	define ICE_ATOMIC_CHAR16_T_LOCK_FREE ATOMIC_CHAR16_T_LOCK_FREE
#	define ICE_ATOMIC_CHAR32_T_LOCK_FREE ATOMIC_CHAR32_T_LOCK_FREE
#	define ICE_ATOMIC_WCHAR_T_LOCK_FREE  ATOMIC_WCHAR_T_LOCK_FREE
#	define ICE_ATOMIC_SHORT_LOCK_FREE    ATOMIC_SHORT_LOCK_FREE
#	define ICE_ATOMIC_INT_LOCK_FREE      ATOMIC_INT_LOCK_FREE
#	define ICE_ATOMIC_LONG_LOCK_FREE     ATOMIC_LONG_LOCK_FREE
#	define ICE_ATOMIC_LLONG_LOCK_FREE    ATOMIC_LLONG_LOCK_FREE
#	define ICE_ATOMIC_POINTER_LOCK_FREE  ATOMIC_POINTER_LOCK_FREE
#	ifdef CE_CXX20_STD
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR8_T_LOCK_FREE
#	else
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR_LOCK_FREE
#	endif
#	define ICE_ATOMIC_RELAXED ((int)::std::memory_order_relaxed)
#	define ICE_ATOMIC_CONSUME ((int)::std::memory_order_consume)
#	define ICE_ATOMIC_ACQUIRE ((int)::std::memory_order_acquire)
#	define ICE_ATOMIC_RELEASE ((int)::std::memory_order_release)
#	define ICE_ATOMIC_ACQ_REL ((int)::std::memory_order_acq_rel)
#	define ICE_ATOMIC_SEQ_CST ((int)::std::memory_order_seq_cst)

#	define ICE_ATOMIC_DECL(type) struct { ::std::atomic<type> val; }
#	define ice_atomic_flag ::std::atomic_flag

#	define ice_atomic_is_lock_free(in) ::std::atomic_is_lock_free(&(in)->val)
#	define ice_atomic_store(in, des) ::std::atomic_store(&(in)->val, (des))
#	define ice_atomic_store_explicit(in, des, ord) ::std::atomic_store_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_load(in) ::std::atomic_load(&(in)->val)
#	define ice_atomic_load_explicit(in, ord) ::std::atomic_load_explicit(&(in)->val, (ord))
#	define ice_atomic_exchange(in, des) ::std::atomic_exchange(&(in)->val, (des))
#	define ice_atomic_exchange_explicit(in, des, ord) ::std::atomic_exchange_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_compare_exchange_strong(in, exp, des) ::std::atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) ::std::atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_compare_exchange_weak(in, exp, des) ::std::atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) ::std::atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_fetch_add(in, arg) ::std::atomic_fetch_add(&(in)->val, (arg))
#	define ice_atomic_fetch_add_explicit(in, arg, ord) ::std::atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_sub(in, arg) ::std::atomic_fetch_sub(&(in)->val, (arg))
#	define ice_atomic_fetch_sub_explicit(in, arg, ord) ::std::atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_or(in, arg) ::std::atomic_fetch_or(&(in)->val, (arg))
#	define ice_atomic_fetch_or_explicit(in, arg, ord) ::std::atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_xor(in, arg) ::std::atomic_fetch_xor(&(in)->val, (arg))
#	define ice_atomic_fetch_xor_explicit(in, arg, ord) ::std::atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_and(in, arg) ::std::atomic_fetch_and(&(in)->val, (arg))
#	define ice_atomic_fetch_and_explicit(in, arg, ord) ::std::atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_init(in, des) ::std::atomic_init(&(in)->val, (des))
#	define ICE_ATOMIC_VAR_INIT(val) {(val)}
#	define ICE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#	define ice_atomic_flag_test_and_set(obj) ::std::atomic_flag_test_and_set(obj)
#	define ice_atomic_flag_test_and_set_explicit(obj, ord) ::std::atomic_flag_test_and_set_explicit((obj), (ord))
#	define ice_atomic_flag_clear(obj) ::std::atomic_flag_clear(obj)
#	define ice_atomic_flag_clear_explicit(obj, ord) ::std::atomic_flag_clear_explicit((obj), (ord))
#	define ice_atomic_thread_fence(order) ::std::atomic_thread_fence((memory_order)(order))
#	define ice_atomic_signal_fence(order) ::std::atomic_signal_fence((memory_order)(order))
#	define ice_kill_dependency(in) ::std::kill_dependency(in)
#elif defined(ICE_ATOMICS_C11)
#	include <stdatomic.h>
#	define ICE_ATOMIC_BOOL_LOCK_FREE     ATOMIC_BOOL_LOCK_FREE
#	define ICE_ATOMIC_CHAR_LOCK_FREE     ATOMIC_CHAR_LOCK_FREE
#	define ICE_ATOMIC_CHAR16_T_LOCK_FREE ATOMIC_CHAR16_T_LOCK_FREE
#	define ICE_ATOMIC_CHAR32_T_LOCK_FREE ATOMIC_CHAR32_T_LOCK_FREE
#	define ICE_ATOMIC_WCHAR_T_LOCK_FREE  ATOMIC_WCHAR_T_LOCK_FREE
#	define ICE_ATOMIC_SHORT_LOCK_FREE    ATOMIC_SHORT_LOCK_FREE
#	define ICE_ATOMIC_INT_LOCK_FREE      ATOMIC_INT_LOCK_FREE
#	define ICE_ATOMIC_LONG_LOCK_FREE     ATOMIC_LONG_LOCK_FREE
#	define ICE_ATOMIC_LLONG_LOCK_FREE    ATOMIC_LLONG_LOCK_FREE
#	define ICE_ATOMIC_POINTER_LOCK_FREE  ATOMIC_POINTER_LOCK_FREE
#	ifdef ATOMIC_CHAR8_T_LOCK_FREE
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR8_T_LOCK_FREE
#	else
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR_LOCK_FREE
#	endif
#	define ICE_ATOMIC_RELAXED memory_order_relaxed
#	define ICE_ATOMIC_CONSUME memory_order_consume
#	define ICE_ATOMIC_ACQUIRE memory_order_acquire
#	define ICE_ATOMIC_RELEASE memory_order_release
#	define ICE_ATOMIC_ACQ_REL memory_order_acq_rel
#	define ICE_ATOMIC_SEQ_CST memory_order_seq_cst

#	define ICE_ATOMIC_DECL(type) struct { _Atomic type val; }
#	define ice_atomic_flag atomic_flag

#	define ice_atomic_is_lock_free(in) atomic_is_lock_free(&(in)->val)
#	define ice_atomic_store(in, des) atomic_store(&(in)->val, (des))
#	define ice_atomic_store_explicit(in, des, ord) atomic_store_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_load(in) atomic_load(&(in)->val)
#	define ice_atomic_load_explicit(in, ord) atomic_load_explicit(&(in)->val, (ord))
#	define ice_atomic_exchange(in, des) atomic_exchange(&(in)->val, (des))
#	define ice_atomic_exchange_explicit(in, des, ord) atomic_exchange_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_compare_exchange_strong(in, exp, des) atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_compare_exchange_weak(in, exp, des) atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_fetch_add(in, arg) atomic_fetch_add(&(in)->val, (arg))
#	define ice_atomic_fetch_add_explicit(in, arg, ord) atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_sub(in, arg) atomic_fetch_sub(&(in)->val, (arg))
#	define ice_atomic_fetch_sub_explicit(in, arg, ord) atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_or(in, arg) atomic_fetch_or(&(in)->val, (arg))
#	define ice_atomic_fetch_or_explicit(in, arg, ord) atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_xor(in, arg) atomic_fetch_xor(&(in)->val, (arg))
#	define ice_atomic_fetch_xor_explicit(in, arg, ord) atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_and(in, arg) atomic_fetch_and(&(in)->val, (arg))
#	define ice_atomic_fetch_and_explicit(in, arg, ord) atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_init(in, des) atomic_init(&(in)->val, (des))
#	define ICE_ATOMIC_VAR_INIT(val) {(val)}
#	define ICE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#	define ice_atomic_flag_test_and_set(obj) atomic_flag_test_and_set(obj)
#	define ice_atomic_flag_test_and_set_explicit(obj, ord) atomic_flag_test_and_set_explicit((obj), (ord))
#	define ice_atomic_flag_clear(obj) atomic_flag_clear(obj)
#	define ice_atomic_flag_clear_explicit(obj, ord) atomic_flag_clear_explicit((obj), (ord))
#	define ice_atomic_thread_fence(order) atomic_thread_fence((memory_order)(order))
#	define ice_atomic_signal_fence(order) atomic_signal_fence((memory_order)(order))
#	define ice_kill_dependency(in) kill_dependency(in)
#elif defined(ICE_ATOMICS_CLANG)
#	define ICE_ATOMIC_BOOL_LOCK_FREE     __CLANG_ATOMIC_BOOL_LOCK_FREE
#	define ICE_ATOMIC_CHAR_LOCK_FREE     __CLANG_ATOMIC_CHAR_LOCK_FREE
#	define ICE_ATOMIC_CHAR16_T_LOCK_FREE __CLANG_ATOMIC_WCHAR_T_LOCK_FREE
#	define ICE_ATOMIC_CHAR32_T_LOCK_FREE __CLANG_ATOMIC_CHAR16_T_LOCK_FREE
#	define ICE_ATOMIC_WCHAR_T_LOCK_FREE  __CLANG_ATOMIC_CHAR32_T_LOCK_FREE
#	define ICE_ATOMIC_SHORT_LOCK_FREE    __CLANG_ATOMIC_SHORT_LOCK_FREE
#	define ICE_ATOMIC_INT_LOCK_FREE      __CLANG_ATOMIC_INT_LOCK_FREE
#	define ICE_ATOMIC_LONG_LOCK_FREE     __CLANG_ATOMIC_LONG_LOCK_FREE
#	define ICE_ATOMIC_LLONG_LOCK_FREE    __CLANG_ATOMIC_LLONG_LOCK_FREE
#	define ICE_ATOMIC_POINTER_LOCK_FREE  __CLANG_ATOMIC_POINTER_LOCK_FREE
#	if CE_C23_STD
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE __CLANG_ATOMIC_CHAR8_T_LOCK_FREE
#	else
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE ICE_ATOMIC_CHAR_LOCK_FREE
#	endif
#	define ICE_ATOMIC_RELAXED __ATOMIC_RELAXED
#	define ICE_ATOMIC_CONSUME __ATOMIC_CONSUME
#	define ICE_ATOMIC_ACQUIRE __ATOMIC_ACQUIRE
#	define ICE_ATOMIC_RELEASE __ATOMIC_RELEASE
#	define ICE_ATOMIC_ACQ_REL __ATOMIC_ACQ_REL
#	define ICE_ATOMIC_SEQ_CST __ATOMIC_SEQ_CST

#	define ICE_ATOMIC_DECL(type) struct { _Atomic type val; }
#	define ice_atomic_flag atomic_flag

#	define ice_atomic_is_lock_free(in) __c11_atomic_is_lock_free(&(in)->val)
#	define ice_atomic_store(in, des) __c11_atomic_store(&(in)->val, (des))
#	define ice_atomic_store_explicit(in, des, ord) __c11_atomic_store_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_load(in) __c11_atomic_load(&(in)->val)
#	define ice_atomic_load_explicit(in, ord) __c11_atomic_load_explicit(&(in)->val, (ord))
#	define ice_atomic_exchange(in, des) __c11_atomic_exchange(&(in)->val, (des))
#	define ice_atomic_exchange_explicit(in, des, ord) __c11_atomic_exchange_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_compare_exchange_strong(in, exp, des) __c11_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) __c11_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_compare_exchange_weak(in, exp, des) __c11_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) __c11_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_fetch_add(in, arg) __c11_atomic_fetch_add(&(in)->val, (arg))
#	define ice_atomic_fetch_add_explicit(in, arg, ord) __c11_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_sub(in, arg) __c11_atomic_fetch_sub(&(in)->val, (arg))
#	define ice_atomic_fetch_sub_explicit(in, arg, ord) __c11_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_or(in, arg) __c11_atomic_fetch_or(&(in)->val, (arg))
#	define ice_atomic_fetch_or_explicit(in, arg, ord) __c11_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_xor(in, arg) __c11_atomic_fetch_xor(&(in)->val, (arg))
#	define ice_atomic_fetch_xor_explicit(in, arg, ord) __c11_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_and(in, arg) __c11_atomic_fetch_and(&(in)->val, (arg))
#	define ice_atomic_fetch_and_explicit(in, arg, ord) __c11_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_init(in, des) __c11_atomic_init(&(in)->val, (des))
#	define ICE_ATOMIC_VAR_INIT(val) {(val)}
#	define ICE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#	define ice_atomic_flag_test_and_set(obj) __c11_atomic_flag_test_and_set(obj)
#	define ice_atomic_flag_test_and_set_explicit(obj, ord) __c11_atomic_flag_test_and_set_explicit((obj), (ord))
#	define ice_atomic_flag_clear(obj) __c11_atomic_flag_clear(obj)
#	define ice_atomic_flag_clear_explicit(obj, ord) __c11_atomic_flag_clear_explicit((obj), (ord))
#	define ice_atomic_thread_fence(order) __c11_atomic_thread_fence((memory_order)(order))
#	define ice_atomic_signal_fence(order) __c11_atomic_signal_fence((memory_order)(order))
#	define ice_kill_dependency(in) (in)
#elif defined(ICE_ATOMICS_GNU)
#	define ICE_ATOMIC_BOOL_LOCK_FREE     __GCC_ATOMIC_BOOL_LOCK_FREE
#	define ICE_ATOMIC_CHAR_LOCK_FREE     __GCC_ATOMIC_CHAR_LOCK_FREE
#	define ICE_ATOMIC_CHAR16_T_LOCK_FREE __GCC_ATOMIC_WCHAR_T_LOCK_FREE
#	define ICE_ATOMIC_CHAR32_T_LOCK_FREE __GCC_ATOMIC_CHAR16_T_LOCK_FREE
#	define ICE_ATOMIC_WCHAR_T_LOCK_FREE  __GCC_ATOMIC_CHAR32_T_LOCK_FREE
#	define ICE_ATOMIC_SHORT_LOCK_FREE    __GCC_ATOMIC_SHORT_LOCK_FREE
#	define ICE_ATOMIC_INT_LOCK_FREE      __GCC_ATOMIC_INT_LOCK_FREE
#	define ICE_ATOMIC_LONG_LOCK_FREE     __GCC_ATOMIC_LONG_LOCK_FREE
#	define ICE_ATOMIC_LLONG_LOCK_FREE    __GCC_ATOMIC_LLONG_LOCK_FREE
#	define ICE_ATOMIC_POINTER_LOCK_FREE  __GCC_ATOMIC_POINTER_LOCK_FREE
#	if CE_C23_STD
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE __GCC_ATOMIC_CHAR8_T_LOCK_FREE
#	else
#		define ICE_ATOMIC_CHAR8_T_LOCK_FREE ICE_ATOMIC_CHAR_LOCK_FREE
#	endif
#	define ICE_ATOMIC_RELAXED __ATOMIC_RELAXED
#	define ICE_ATOMIC_CONSUME __ATOMIC_CONSUME
#	define ICE_ATOMIC_ACQUIRE __ATOMIC_ACQUIRE
#	define ICE_ATOMIC_RELEASE __ATOMIC_RELEASE
#	define ICE_ATOMIC_ACQ_REL __ATOMIC_ACQ_REL
#	define ICE_ATOMIC_SEQ_CST __ATOMIC_SEQ_CST

#	define ICE_ATOMIC_DECL(type) struct { type val; }
#	define ice_atomic_flag atomic_flag

#	define ice_atomic_is_lock_free(in) __atomic_is_lock_free(sizeof((in)->val), &(in)->val)
#	define ice_atomic_store(in, des) __atomic_store_n(&(in)->val, (des), __ATOMIC_SEQ_CST)
#	define ice_atomic_store_explicit(in, des, ord) __atomic_store_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_load(in) __atomic_load_n(&(in)->val, __ATOMIC_SEQ_CST)
#	define ice_atomic_load_explicit(in, ord) __atomic_load_explicit(&(in)->val, (ord))
#	define ice_atomic_exchange(in, des) __atomic_exchange_n(&(in)->val, (des))
#	define ice_atomic_exchange_explicit(in, des, ord) __atomic_exchange_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_compare_exchange_strong(in, exp, des) __atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) __atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_compare_exchange_weak(in, exp, des) __atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) __atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_fetch_add(in, arg) __atomic_fetch_add(&(in)->val, (arg))
#	define ice_atomic_fetch_add_explicit(in, arg, ord) __atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_sub(in, arg) __atomic_fetch_sub(&(in)->val, (arg))
#	define ice_atomic_fetch_sub_explicit(in, arg, ord) __atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_or(in, arg) __atomic_fetch_or(&(in)->val, (arg))
#	define ice_atomic_fetch_or_explicit(in, arg, ord) __atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_xor(in, arg) __atomic_fetch_xor(&(in)->val, (arg))
#	define ice_atomic_fetch_xor_explicit(in, arg, ord) __atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_and(in, arg) __atomic_fetch_and(&(in)->val, (arg))
#	define ice_atomic_fetch_and_explicit(in, arg, ord) __atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_init(in, des) __atomic_init(&(in)->val, (des))
#	define ICE_ATOMIC_VAR_INIT(val) {(val)}
#	define ICE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#	define ice_atomic_flag_test_and_set(obj) atomic_flag_test_and_set(obj)
#	define ice_atomic_flag_test_and_set_explicit(obj, ord) atomic_flag_test_and_set_explicit((obj), (ord))
#	define ice_atomic_flag_clear(obj) atomic_flag_clear(obj)
#	define ice_atomic_flag_clear_explicit(obj, ord) atomic_flag_clear_explicit((obj), (ord))
#	define ice_atomic_thread_fence(order) atomic_thread_fence((memory_order)(order))
#	define ice_atomic_signal_fence(order) atomic_signal_fence((memory_order)(order))
#	define ice_kill_dependency(in) (__extension__ ({ \
	auto_type ice_kill_dependency_value = (in); \
	ice_kill_dependency_value; \
}))
#elif defined(ICE_ATOMICS_WIN32)
#	define ICE_ATOMIC_BOOL_LOCK_FREE     0
#	define ICE_ATOMIC_CHAR_LOCK_FREE     0
#	define ICE_ATOMIC_CHAR16_T_LOCK_FREE 0
#	define ICE_ATOMIC_CHAR32_T_LOCK_FREE 0
#	define ICE_ATOMIC_WCHAR_T_LOCK_FREE  0
#	define ICE_ATOMIC_SHORT_LOCK_FREE    0
#	define ICE_ATOMIC_INT_LOCK_FREE      0
#	define ICE_ATOMIC_LONG_LOCK_FREE     0
#	define ICE_ATOMIC_LLONG_LOCK_FREE    0
#	define ICE_ATOMIC_POINTER_LOCK_FREE  0
#	define ICE_ATOMIC_CHAR8_T_LOCK_FREE ICE_ATOMIC_CHAR_LOCK_FREE
#	define ICE_ATOMIC_RELAXED 0
#	define ICE_ATOMIC_CONSUME 1
#	define ICE_ATOMIC_ACQUIRE 2
#	define ICE_ATOMIC_RELEASE 3
#	define ICE_ATOMIC_ACQ_REL 4
#	define ICE_ATOMIC_SEQ_CST 5

#	define ICE_ATOMIC_DECL(type) struct { volatile type val; }
#	define ice_atomic_flag atomic_flag

#if 0
ice_impl_atomic_is_lock_free(&(in)->val)
ice_impl_atomic_store(&(in)->val, (des))
ice_impl_atomic_store_explicit(&(in)->val, (des), (ord))
ice_impl_atomic_load(&(in)->val)
ice_impl_atomic_load_explicit(&(in)->val, (ord))
ice_impl_atomic_exchange(&(in)->val, (des))
ice_impl_atomic_exchange_explicit(&(in)->val, (des), (ord))
ice_impl_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
ice_impl_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
ice_impl_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
ice_impl_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
ice_impl_atomic_fetch_add(&(in)->val, (arg))
ice_impl_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_sub(&(in)->val, (arg))
ice_impl_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_or(&(in)->val, (arg))
ice_impl_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_xor(&(in)->val, (arg))
ice_impl_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_and(&(in)->val, (arg))
ice_impl_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_init(&(in)->val, (des))
ice_impl_atomic_flag_test_and_set(obj)
ice_impl_atomic_flag_test_and_set_explicit((obj), (ord))
ice_impl_atomic_flag_clear(obj)
ice_impl_atomic_flag_clear_explicit((obj), (ord))
ice_impl_atomic_thread_fence((memory_order)(order))
ice_impl_atomic_signal_fence((memory_order)(order))
#endif

#	define ice_atomic_is_lock_free(in) ice_impl_atomic_is_lock_free(&(in)->val)
#	define ice_atomic_store(in, des) ice_impl_atomic_store(&(in)->val, (des))
#	define ice_atomic_store_explicit(in, des, ord) ice_impl_atomic_store_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_load(in) ice_impl_atomic_load(&(in)->val)
#	define ice_atomic_load_explicit(in, ord) ice_impl_atomic_load_explicit(&(in)->val, (ord))
#	define ice_atomic_exchange(in, des) ice_impl_atomic_exchange(&(in)->val, (des))
#	define ice_atomic_exchange_explicit(in, des, ord) ice_impl_atomic_exchange_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_compare_exchange_strong(in, exp, des) ice_impl_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_compare_exchange_weak(in, exp, des) ice_impl_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_fetch_add(in, arg) ice_impl_atomic_fetch_add(&(in)->val, (arg))
#	define ice_atomic_fetch_add_explicit(in, arg, ord) ice_impl_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_sub(in, arg) ice_impl_atomic_fetch_sub(&(in)->val, (arg))
#	define ice_atomic_fetch_sub_explicit(in, arg, ord) ice_impl_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_or(in, arg) ice_impl_atomic_fetch_or(&(in)->val, (arg))
#	define ice_atomic_fetch_or_explicit(in, arg, ord) ice_impl_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_xor(in, arg) ice_impl_atomic_fetch_xor(&(in)->val, (arg))
#	define ice_atomic_fetch_xor_explicit(in, arg, ord) ice_impl_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_and(in, arg) ice_impl_atomic_fetch_and(&(in)->val, (arg))
#	define ice_atomic_fetch_and_explicit(in, arg, ord) ice_impl_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_init(in, des) ice_impl_atomic_init(&(in)->val, (des))
#	define ICE_ATOMIC_VAR_INIT(val) {(val)}
#	define ICE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#	define ice_atomic_flag_test_and_set(obj) ice_impl_atomic_flag_test_and_set(obj)
#	define ice_atomic_flag_test_and_set_explicit(obj, ord) ice_impl_atomic_flag_test_and_set_explicit((obj), (ord))
#	define ice_atomic_flag_clear(obj) ice_impl_atomic_flag_clear(obj)
#	define ice_atomic_flag_clear_explicit(obj, ord) ice_impl_atomic_flag_clear_explicit((obj), (ord))
#	define ice_atomic_thread_fence(order) ice_impl_atomic_thread_fence((memory_order)(order))
#	define ice_atomic_signal_fence(order) ice_impl_atomic_signal_fence((memory_order)(order))
#	define ice_kill_dependency(in) (in)
#elif defined(ICE_ATOMICS_MTXIMPL)
#	define ICE_ATOMIC_BOOL_LOCK_FREE     0
#	define ICE_ATOMIC_CHAR_LOCK_FREE     0
#	define ICE_ATOMIC_CHAR16_T_LOCK_FREE 0
#	define ICE_ATOMIC_CHAR32_T_LOCK_FREE 0
#	define ICE_ATOMIC_WCHAR_T_LOCK_FREE  0
#	define ICE_ATOMIC_SHORT_LOCK_FREE    0
#	define ICE_ATOMIC_INT_LOCK_FREE      0
#	define ICE_ATOMIC_LONG_LOCK_FREE     0
#	define ICE_ATOMIC_LLONG_LOCK_FREE    0
#	define ICE_ATOMIC_POINTER_LOCK_FREE  0
#	define ICE_ATOMIC_CHAR8_T_LOCK_FREE ICE_ATOMIC_CHAR_LOCK_FREE
#	define ICE_ATOMIC_RELAXED 0
#	define ICE_ATOMIC_CONSUME 1
#	define ICE_ATOMIC_ACQUIRE 2
#	define ICE_ATOMIC_RELEASE 3
#	define ICE_ATOMIC_ACQ_REL 4
#	define ICE_ATOMIC_SEQ_CST 5

#	define ICE_ATOMIC_DECL(type) struct { volatile type val; ce_mtx_t lock; }
#define ice_atomic_bool ICE_ATOMIC_DECL(cebool)
#define ice_atomic_char ICE_ATOMIC_DECL(char)
#define ice_atomic_schar ICE_ATOMIC_DECL(signed char)
#define ice_atomic_uchar ICE_ATOMIC_DECL(unsigned char)
#define ice_atomic_short ICE_ATOMIC_DECL(short)
#define ice_atomic_ushort ICE_ATOMIC_DECL(unsigned short)
#define ice_atomic_int ICE_ATOMIC_DECL(int)
#define ice_atomic_uint ICE_ATOMIC_DECL(unsigned int)
#define ice_atomic_long ICE_ATOMIC_DECL(long)
#define ice_atomic_ulong ICE_ATOMIC_DECL(unsigned long)
#define ice_atomic_longlong ICE_ATOMIC_DECL(long long)
#define ice_atomic_ulonglong ICE_ATOMIC_DECL(unsigned long long)
#	define ice_atomic_flag atomic_flag

#if 0
ice_impl_atomic_is_lock_free(&(in)->val)
ice_impl_atomic_store(&(in)->val, (des))
ice_impl_atomic_store_explicit(&(in)->val, (des), (ord))
ice_impl_atomic_load(&(in)->val)
ice_impl_atomic_load_explicit(&(in)->val, (ord))
ice_impl_atomic_exchange(&(in)->val, (des))
ice_impl_atomic_exchange_explicit(&(in)->val, (des), (ord))
ice_impl_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
ice_impl_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
ice_impl_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
ice_impl_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
ice_impl_atomic_fetch_add(&(in)->val, (arg))
ice_impl_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_sub(&(in)->val, (arg))
ice_impl_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_or(&(in)->val, (arg))
ice_impl_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_xor(&(in)->val, (arg))
ice_impl_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_fetch_and(&(in)->val, (arg))
ice_impl_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
ice_impl_atomic_init(&(in)->val, (des))
ice_impl_atomic_flag_test_and_set(obj)
ice_impl_atomic_flag_test_and_set_explicit((obj), (ord))
ice_impl_atomic_flag_clear(obj)
ice_impl_atomic_flag_clear_explicit((obj), (ord))
ice_impl_atomic_thread_fence((memory_order)(order))
ice_impl_atomic_signal_fence((memory_order)(order))
#endif

#	define ice_atomic_is_lock_free(in) ice_impl_atomic_is_lock_free(&(in)->val)
#	define ice_atomic_store(in, des) ice_impl_atomic_store(&(in)->val, (des))
#	define ice_atomic_store_explicit(in, des, ord) ice_impl_atomic_store_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_load(in) ice_impl_atomic_load(&(in)->val)
#	define ice_atomic_load_explicit(in, ord) ice_impl_atomic_load_explicit(&(in)->val, (ord))
#	define ice_atomic_exchange(in, des) ice_impl_atomic_exchange(&(in)->val, (des))
#	define ice_atomic_exchange_explicit(in, des, ord) ice_impl_atomic_exchange_explicit(&(in)->val, (des), (ord))
#	define ice_atomic_compare_exchange_strong(in, exp, des) ice_impl_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_compare_exchange_weak(in, exp, des) ice_impl_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#	define ice_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#	define ice_atomic_fetch_add(in, arg) ice_impl_atomic_fetch_add(&(in)->val, (arg))
#	define ice_atomic_fetch_add_explicit(in, arg, ord) ice_impl_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_sub(in, arg) ice_impl_atomic_fetch_sub(&(in)->val, (arg))
#	define ice_atomic_fetch_sub_explicit(in, arg, ord) ice_impl_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_or(in, arg) ice_impl_atomic_fetch_or(&(in)->val, (arg))
#	define ice_atomic_fetch_or_explicit(in, arg, ord) ice_impl_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_xor(in, arg) ice_impl_atomic_fetch_xor(&(in)->val, (arg))
#	define ice_atomic_fetch_xor_explicit(in, arg, ord) ice_impl_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_fetch_and(in, arg) ice_impl_atomic_fetch_and(&(in)->val, (arg))
#	define ice_atomic_fetch_and_explicit(in, arg, ord) ice_impl_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#	define ice_atomic_init(in, des) ice_impl_atomic_init(&(in)->val, (des))
#	define ICE_ATOMIC_VAR_INIT(val) {(val)}
#	define ICE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#	define ice_atomic_flag_test_and_set(obj) ice_impl_atomic_flag_test_and_set(obj)
#	define ice_atomic_flag_test_and_set_explicit(obj, ord) ice_impl_atomic_flag_test_and_set_explicit((obj), (ord))
#	define ice_atomic_flag_clear(obj) ice_impl_atomic_flag_clear(obj)
#	define ice_atomic_flag_clear_explicit(obj, ord) ice_impl_atomic_flag_clear_explicit((obj), (ord))
#	define ice_atomic_thread_fence(order) ice_impl_atomic_thread_fence((memory_order)(order))
#	define ice_atomic_signal_fence(order) ice_impl_atomic_signal_fence((memory_order)(order))
#	define ice_kill_dependency(in) (in)
#else
#	define ICE_NO_ATOMICS
#endif

ICE_NAMESPACE_BEGIN

#ifndef ICE_NO_ATOMICS
#define CANVAS_HAS_ATOMICS 1

#define CANVAS_ATOMIC_BOOL_LOCK_FREE     ICE_ATOMIC_BOOL_LOCK_FREE
#define CANVAS_ATOMIC_CHAR_LOCK_FREE     ICE_ATOMIC_CHAR_LOCK_FREE
#define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE  ICE_ATOMIC_CHAR8_T_LOCK_FREE
#define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE ICE_ATOMIC_CHAR16_T_LOCK_FREE
#define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE ICE_ATOMIC_CHAR32_T_LOCK_FREE
#define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  ICE_ATOMIC_WCHAR_T_LOCK_FREE
#define CANVAS_ATOMIC_SHORT_LOCK_FREE    ICE_ATOMIC_SHORT_LOCK_FREE
#define CANVAS_ATOMIC_INT_LOCK_FREE      ICE_ATOMIC_INT_LOCK_FREE
#define CANVAS_ATOMIC_LONG_LOCK_FREE     ICE_ATOMIC_LONG_LOCK_FREE
#define CANVAS_ATOMIC_LLONG_LOCK_FREE    ICE_ATOMIC_LLONG_LOCK_FREE
#define CANVAS_ATOMIC_POINTER_LOCK_FREE  ICE_ATOMIC_POINTER_LOCK_FREE

#define CE_MEMORD int
#define CE_MEMORD_RELAXED ICE_ATOMIC_RELAXED
#define CE_MEMORD_CONSUME ICE_ATOMIC_CONSUME
#define CE_MEMORD_ACQUIRE ICE_ATOMIC_ACQUIRE
#define CE_MEMORD_RELEASE ICE_ATOMIC_RELEASE
#define CE_MEMORD_ACQ_REL ICE_ATOMIC_ACQ_REL
#define CE_MEMORD_SEQ_CST ICE_ATOMIC_SEQ_CST

#ifdef ice_kill_dependency
#define ce_kill_dependency(in) ice_kill_dependency(in)
#endif

#define ce_atomic_is_lock_free ice_atomic_is_lock_free
#define ce_atomic_store ice_atomic_store
#define ce_atomic_store_explicit ice_atomic_store_explicit
#define ce_atomic_load ice_atomic_load
#define ce_atomic_load_explicit ice_atomic_load_explicit
#define ce_atomic_exchange ice_atomic_exchange
#define ce_atomic_exchange_explicit ice_atomic_exchange_explicit
#define ce_atomic_compare_exchange_strong ice_atomic_compare_exchange_strong
#define ce_atomic_compare_exchange_strong_explicit ice_atomic_compare_exchange_strong_explicit
#define ce_atomic_compare_exchange_weak ice_atomic_compare_exchange_weak
#define ce_atomic_compare_exchange_weak_explicit ice_atomic_compare_exchange_weak_explicit
#define ce_atomic_fetch_add ice_atomic_fetch_add
#define ce_atomic_fetch_add_explicit ice_atomic_fetch_add_explicit
#define ce_atomic_fetch_sub ice_atomic_fetch_sub
#define ce_atomic_fetch_sub_explicit ice_atomic_fetch_sub_explicit
#define ce_atomic_fetch_or ice_atomic_fetch_or
#define ce_atomic_fetch_or_explicit ice_atomic_fetch_or_explicit
#define ce_atomic_fetch_xor ice_atomic_fetch_xor
#define ce_atomic_fetch_xor_explicit ice_atomic_fetch_xor_explicit
#define ce_atomic_fetch_and ice_atomic_fetch_and
#define ce_atomic_fetch_and_explicit ice_atomic_fetch_and_explicit
#define ce_atomic_flag ice_atomic_flag
#define ce_atomic_flag_test_and_set ice_atomic_flag_test_and_set
#define ce_atomic_flag_test_and_set_explicit ice_atomic_flag_test_and_set_explicit
#define ce_atomic_flag_clear ice_atomic_flag_clear
#define ce_atomic_flag_clear_explicit ice_atomic_flag_clear_explicit
#define ce_atomic_init ice_atomic_init
#define CE_ATOMIC_VAR_INIT ICE_ATOMIC_VAR_INIT
#define CE_ATOMIC_FLAG_INIT ICE_ATOMIC_FLAG_INIT
#define ce_atomic_thread_fence ice_atomic_thread_fence
#define ce_atomic_signal_fence ice_atomic_signal_fence

#define ce_atomic_bool ICE_ATOMIC_DECL(cebool)
#define ce_atomic_char ICE_ATOMIC_DECL(char)
#define ce_atomic_schar ICE_ATOMIC_DECL(signed char)
#define ce_atomic_uchar ICE_ATOMIC_DECL(unsigned char)
#define ce_atomic_short ICE_ATOMIC_DECL(short)
#define ce_atomic_ushort ICE_ATOMIC_DECL(unsigned short)
#define ce_atomic_int ICE_ATOMIC_DECL(int)
#define ce_atomic_uint ICE_ATOMIC_DECL(unsigned int)
#define ce_atomic_long ICE_ATOMIC_DECL(long)
#define ce_atomic_ulong ICE_ATOMIC_DECL(unsigned long)
#define ce_atomic_longlong ICE_ATOMIC_DECL(long long)
#define ce_atomic_ulonglong ICE_ATOMIC_DECL(unsigned long long)
#define ce_atomic_pointer(type) ICE_ATOMIC_DECL(type*)

#else
#define CANVAS_HAS_ATOMICS 0
#endif

ICE_NAMESPACE_END

#endif /* !CANVAS_THREADS_ATOMIC_H */
