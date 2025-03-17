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

#undef CANVAS_ATOMIC_BOOL_LOCK_FREE
#undef CANVAS_ATOMIC_CHAR_LOCK_FREE
#undef CANVAS_ATOMIC_CHAR8_T_LOCK_FREE
#undef CANVAS_ATOMIC_CHAR16_T_LOCK_FREE
#undef CANVAS_ATOMIC_CHAR32_T_LOCK_FREE
#undef CANVAS_ATOMIC_WCHAR_T_LOCK_FREE
#undef CANVAS_ATOMIC_SHORT_LOCK_FREE
#undef CANVAS_ATOMIC_INT_LOCK_FREE
#undef CANVAS_ATOMIC_LONG_LOCK_FREE
#undef CANVAS_ATOMIC_LLONG_LOCK_FREE
#undef CANVAS_ATOMIC_POINTER_LOCK_FREE
#undef ce_kill_dependency
#undef ce_atomic_is_lock_free
#undef ce_atomic_store
#undef ce_atomic_store_explicit
#undef ce_atomic_load
#undef ce_atomic_load_explicit
#undef ce_atomic_exchange
#undef ce_atomic_exchange_explicit
#undef ce_atomic_compare_exchange_strong
#undef ce_atomic_compare_exchange_strong_explicit
#undef ce_atomic_compare_exchange_weak
#undef ce_atomic_compare_exchange_weak_explicit
#undef ce_atomic_fetch_add
#undef ce_atomic_fetch_add_explicit
#undef ce_atomic_fetch_sub
#undef ce_atomic_fetch_sub_explicit
#undef ce_atomic_fetch_or
#undef ce_atomic_fetch_or_explicit
#undef ce_atomic_fetch_xor
#undef ce_atomic_fetch_xor_explicit
#undef ce_atomic_fetch_and
#undef ce_atomic_fetch_and_explicit
#undef ce_atomic_flag
#undef ce_atomic_flag_test_and_set
#undef ce_atomic_flag_test_and_set_explicit
#undef ce_atomic_flag_clear
#undef ce_atomic_flag_clear_explicit
#undef ce_atomic_init
#undef CE_ATOMIC_VAR_INIT
#undef CE_ATOMIC_FLAG_INIT
#undef ce_atomic_thread_fence
#undef ce_atomic_signal_fence
#undef ce_atomic_bool
#undef ce_atomic_char
#undef ce_atomic_schar
#undef ce_atomic_uchar
#undef ce_atomic_short
#undef ce_atomic_ushort
#undef ce_atomic_int
#undef ce_atomic_uint
#undef ce_atomic_long
#undef ce_atomic_ulong
#undef ce_atomic_longlong
#undef ce_atomic_ulonglong
#undef ce_atomic_pointer

#ifdef CANVAS_HAS_ATOMICS

CE_NAMESPACE_BEGIN

/* Temporary */
#undef ICE_ATOMICS_MTXIMPL
#undef ICE_ATOMICS_WIN32
/* !Temporary */

#if defined(ICE_ATOMICS_CXX11)
#  include <atomic>
#  define CANVAS_ATOMIC_BOOL_LOCK_FREE     ATOMIC_BOOL_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR_LOCK_FREE     ATOMIC_CHAR_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE ATOMIC_CHAR16_T_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE ATOMIC_CHAR32_T_LOCK_FREE
#  define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  ATOMIC_WCHAR_T_LOCK_FREE
#  define CANVAS_ATOMIC_SHORT_LOCK_FREE    ATOMIC_SHORT_LOCK_FREE
#  define CANVAS_ATOMIC_INT_LOCK_FREE      ATOMIC_INT_LOCK_FREE
#  define CANVAS_ATOMIC_LONG_LOCK_FREE     ATOMIC_LONG_LOCK_FREE
#  define CANVAS_ATOMIC_LLONG_LOCK_FREE    ATOMIC_LLONG_LOCK_FREE
#  define CANVAS_ATOMIC_POINTER_LOCK_FREE  ATOMIC_POINTER_LOCK_FREE
#  ifdef CE_CXX20_STD
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR8_T_LOCK_FREE
#  else
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR_LOCK_FREE
#  endif

#  define ICE_ATOMIC_DECL(type) struct { ::std::atomic<type> val; }
#  define ce_atomic_flag ::std::atomic_flag

#  define ce_atomic_is_lock_free(in) ::std::atomic_is_lock_free(&(in)->val)
#  define ce_atomic_store(in, des) ::std::atomic_store(&(in)->val, (des))
#  define ce_atomic_store_explicit(in, des, ord) ::std::atomic_store_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_load(in) ::std::atomic_load(&(in)->val)
#  define ce_atomic_load_explicit(in, ord) ::std::atomic_load_explicit(&(in)->val, (ord))
#  define ce_atomic_exchange(in, des) ::std::atomic_exchange(&(in)->val, (des))
#  define ce_atomic_exchange_explicit(in, des, ord) ::std::atomic_exchange_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_compare_exchange_strong(in, exp, des) ::std::atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) ::std::atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_compare_exchange_weak(in, exp, des) ::std::atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) ::std::atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_fetch_add(in, arg) ::std::atomic_fetch_add(&(in)->val, (arg))
#  define ce_atomic_fetch_add_explicit(in, arg, ord) ::std::atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_sub(in, arg) ::std::atomic_fetch_sub(&(in)->val, (arg))
#  define ce_atomic_fetch_sub_explicit(in, arg, ord) ::std::atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_or(in, arg) ::std::atomic_fetch_or(&(in)->val, (arg))
#  define ce_atomic_fetch_or_explicit(in, arg, ord) ::std::atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_xor(in, arg) ::std::atomic_fetch_xor(&(in)->val, (arg))
#  define ce_atomic_fetch_xor_explicit(in, arg, ord) ::std::atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_and(in, arg) ::std::atomic_fetch_and(&(in)->val, (arg))
#  define ce_atomic_fetch_and_explicit(in, arg, ord) ::std::atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_init(in, des) ::std::atomic_init(&(in)->val, (des))
#  define CE_ATOMIC_VAR_INIT(val) {(val)}
#  define CE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define ce_atomic_flag_test_and_set(obj) ::std::atomic_flag_test_and_set(obj)
#  define ce_atomic_flag_test_and_set_explicit(obj, ord) ::std::atomic_flag_test_and_set_explicit((obj), (ord))
#  define ce_atomic_flag_clear(obj) ::std::atomic_flag_clear(obj)
#  define ce_atomic_flag_clear_explicit(obj, ord) ::std::atomic_flag_clear_explicit((obj), (ord))
#  define ce_atomic_thread_fence(order) ::std::atomic_thread_fence((memory_order)(order))
#  define ce_atomic_signal_fence(order) ::std::atomic_signal_fence((memory_order)(order))
#  define ce_kill_dependency(in) ::std::kill_dependency(in)
#elif defined(ICE_ATOMICS_C11)
#  include <stdatomic.h>
#  define CANVAS_ATOMIC_BOOL_LOCK_FREE     ATOMIC_BOOL_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR_LOCK_FREE     ATOMIC_CHAR_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE ATOMIC_CHAR16_T_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE ATOMIC_CHAR32_T_LOCK_FREE
#  define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  ATOMIC_WCHAR_T_LOCK_FREE
#  define CANVAS_ATOMIC_SHORT_LOCK_FREE    ATOMIC_SHORT_LOCK_FREE
#  define CANVAS_ATOMIC_INT_LOCK_FREE      ATOMIC_INT_LOCK_FREE
#  define CANVAS_ATOMIC_LONG_LOCK_FREE     ATOMIC_LONG_LOCK_FREE
#  define CANVAS_ATOMIC_LLONG_LOCK_FREE    ATOMIC_LLONG_LOCK_FREE
#  define CANVAS_ATOMIC_POINTER_LOCK_FREE  ATOMIC_POINTER_LOCK_FREE
#  ifdef ATOMIC_CHAR8_T_LOCK_FREE
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR8_T_LOCK_FREE
#  else
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE ATOMIC_CHAR_LOCK_FREE
#  endif

#  define ICE_ATOMIC_DECL(type) struct { _Atomic type val; }
#  define ce_atomic_flag atomic_flag

#  define ce_atomic_is_lock_free(in) atomic_is_lock_free(&(in)->val)
#  define ce_atomic_store(in, des) atomic_store(&(in)->val, (des))
#  define ce_atomic_store_explicit(in, des, ord) atomic_store_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_load(in) atomic_load(&(in)->val)
#  define ce_atomic_load_explicit(in, ord) atomic_load_explicit(&(in)->val, (ord))
#  define ce_atomic_exchange(in, des) atomic_exchange(&(in)->val, (des))
#  define ce_atomic_exchange_explicit(in, des, ord) atomic_exchange_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_compare_exchange_strong(in, exp, des) atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_compare_exchange_weak(in, exp, des) atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_fetch_add(in, arg) atomic_fetch_add(&(in)->val, (arg))
#  define ce_atomic_fetch_add_explicit(in, arg, ord) atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_sub(in, arg) atomic_fetch_sub(&(in)->val, (arg))
#  define ce_atomic_fetch_sub_explicit(in, arg, ord) atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_or(in, arg) atomic_fetch_or(&(in)->val, (arg))
#  define ce_atomic_fetch_or_explicit(in, arg, ord) atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_xor(in, arg) atomic_fetch_xor(&(in)->val, (arg))
#  define ce_atomic_fetch_xor_explicit(in, arg, ord) atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_and(in, arg) atomic_fetch_and(&(in)->val, (arg))
#  define ce_atomic_fetch_and_explicit(in, arg, ord) atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_init(in, des) atomic_init(&(in)->val, (des))
#  define CE_ATOMIC_VAR_INIT(val) {(val)}
#  define CE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define ce_atomic_flag_test_and_set(obj) atomic_flag_test_and_set(obj)
#  define ce_atomic_flag_test_and_set_explicit(obj, ord) atomic_flag_test_and_set_explicit((obj), (ord))
#  define ce_atomic_flag_clear(obj) atomic_flag_clear(obj)
#  define ce_atomic_flag_clear_explicit(obj, ord) atomic_flag_clear_explicit((obj), (ord))
#  define ce_atomic_thread_fence(order) atomic_thread_fence((memory_order)(order))
#  define ce_atomic_signal_fence(order) atomic_signal_fence((memory_order)(order))
#  define ce_kill_dependency(in) kill_dependency(in)
#elif defined(ICE_ATOMICS_CLANG)
#  define CANVAS_ATOMIC_BOOL_LOCK_FREE     __CLANG_ATOMIC_BOOL_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR_LOCK_FREE     __CLANG_ATOMIC_CHAR_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE __CLANG_ATOMIC_WCHAR_T_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE __CLANG_ATOMIC_CHAR16_T_LOCK_FREE
#  define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  __CLANG_ATOMIC_CHAR32_T_LOCK_FREE
#  define CANVAS_ATOMIC_SHORT_LOCK_FREE    __CLANG_ATOMIC_SHORT_LOCK_FREE
#  define CANVAS_ATOMIC_INT_LOCK_FREE      __CLANG_ATOMIC_INT_LOCK_FREE
#  define CANVAS_ATOMIC_LONG_LOCK_FREE     __CLANG_ATOMIC_LONG_LOCK_FREE
#  define CANVAS_ATOMIC_LLONG_LOCK_FREE    __CLANG_ATOMIC_LLONG_LOCK_FREE
#  define CANVAS_ATOMIC_POINTER_LOCK_FREE  __CLANG_ATOMIC_POINTER_LOCK_FREE
#  if CE_C23_STD
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE __CLANG_ATOMIC_CHAR8_T_LOCK_FREE
#  else
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE CANVAS_ATOMIC_CHAR_LOCK_FREE
#  endif

#  define ICE_ATOMIC_DECL(type) struct { _Atomic type val; }
#  define ce_atomic_flag atomic_flag

#  define ce_atomic_is_lock_free(in) __c11_atomic_is_lock_free(&(in)->val)
#  define ce_atomic_store(in, des) __c11_atomic_store(&(in)->val, (des))
#  define ce_atomic_store_explicit(in, des, ord) __c11_atomic_store_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_load(in) __c11_atomic_load(&(in)->val)
#  define ce_atomic_load_explicit(in, ord) __c11_atomic_load_explicit(&(in)->val, (ord))
#  define ce_atomic_exchange(in, des) __c11_atomic_exchange(&(in)->val, (des))
#  define ce_atomic_exchange_explicit(in, des, ord) __c11_atomic_exchange_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_compare_exchange_strong(in, exp, des) __c11_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) __c11_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_compare_exchange_weak(in, exp, des) __c11_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) __c11_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_fetch_add(in, arg) __c11_atomic_fetch_add(&(in)->val, (arg))
#  define ce_atomic_fetch_add_explicit(in, arg, ord) __c11_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_sub(in, arg) __c11_atomic_fetch_sub(&(in)->val, (arg))
#  define ce_atomic_fetch_sub_explicit(in, arg, ord) __c11_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_or(in, arg) __c11_atomic_fetch_or(&(in)->val, (arg))
#  define ce_atomic_fetch_or_explicit(in, arg, ord) __c11_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_xor(in, arg) __c11_atomic_fetch_xor(&(in)->val, (arg))
#  define ce_atomic_fetch_xor_explicit(in, arg, ord) __c11_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_and(in, arg) __c11_atomic_fetch_and(&(in)->val, (arg))
#  define ce_atomic_fetch_and_explicit(in, arg, ord) __c11_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_init(in, des) __c11_atomic_init(&(in)->val, (des))
#  define CE_ATOMIC_VAR_INIT(val) {(val)}
#  define CE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define ce_atomic_flag_test_and_set(obj) __c11_atomic_flag_test_and_set(obj)
#  define ce_atomic_flag_test_and_set_explicit(obj, ord) __c11_atomic_flag_test_and_set_explicit((obj), (ord))
#  define ce_atomic_flag_clear(obj) __c11_atomic_flag_clear(obj)
#  define ce_atomic_flag_clear_explicit(obj, ord) __c11_atomic_flag_clear_explicit((obj), (ord))
#  define ce_atomic_thread_fence(order) __c11_atomic_thread_fence((memory_order)(order))
#  define ce_atomic_signal_fence(order) __c11_atomic_signal_fence((memory_order)(order))
#  define ce_kill_dependency(in) (in)
#elif defined(ICE_ATOMICS_GNU)
#  define CANVAS_ATOMIC_BOOL_LOCK_FREE     __GCC_ATOMIC_BOOL_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR_LOCK_FREE     __GCC_ATOMIC_CHAR_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE __GCC_ATOMIC_WCHAR_T_LOCK_FREE
#  define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE __GCC_ATOMIC_CHAR16_T_LOCK_FREE
#  define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  __GCC_ATOMIC_CHAR32_T_LOCK_FREE
#  define CANVAS_ATOMIC_SHORT_LOCK_FREE    __GCC_ATOMIC_SHORT_LOCK_FREE
#  define CANVAS_ATOMIC_INT_LOCK_FREE      __GCC_ATOMIC_INT_LOCK_FREE
#  define CANVAS_ATOMIC_LONG_LOCK_FREE     __GCC_ATOMIC_LONG_LOCK_FREE
#  define CANVAS_ATOMIC_LLONG_LOCK_FREE    __GCC_ATOMIC_LLONG_LOCK_FREE
#  define CANVAS_ATOMIC_POINTER_LOCK_FREE  __GCC_ATOMIC_POINTER_LOCK_FREE
#  if CE_C23_STD
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE __GCC_ATOMIC_CHAR8_T_LOCK_FREE
#  else
#    define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE CANVAS_ATOMIC_CHAR_LOCK_FREE
#  endif

#  define ICE_ATOMIC_DECL(type) struct { type val; }
#  define ce_atomic_flag atomic_flag

#  define ce_atomic_is_lock_free(in) __atomic_is_lock_free(sizeof((in)->val), &(in)->val)
#  define ce_atomic_store(in, des) __atomic_store_n(&(in)->val, (des), __ATOMIC_SEQ_CST)
#  define ce_atomic_store_explicit(in, des, ord) __atomic_store_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_load(in) __atomic_load_n(&(in)->val, __ATOMIC_SEQ_CST)
#  define ce_atomic_load_explicit(in, ord) __atomic_load_explicit(&(in)->val, (ord))
#  define ce_atomic_exchange(in, des) __atomic_exchange_n(&(in)->val, (des))
#  define ce_atomic_exchange_explicit(in, des, ord) __atomic_exchange_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_compare_exchange_strong(in, exp, des) __atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) __atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_compare_exchange_weak(in, exp, des) __atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) __atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_fetch_add(in, arg) __atomic_fetch_add(&(in)->val, (arg))
#  define ce_atomic_fetch_add_explicit(in, arg, ord) __atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_sub(in, arg) __atomic_fetch_sub(&(in)->val, (arg))
#  define ce_atomic_fetch_sub_explicit(in, arg, ord) __atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_or(in, arg) __atomic_fetch_or(&(in)->val, (arg))
#  define ce_atomic_fetch_or_explicit(in, arg, ord) __atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_xor(in, arg) __atomic_fetch_xor(&(in)->val, (arg))
#  define ce_atomic_fetch_xor_explicit(in, arg, ord) __atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_and(in, arg) __atomic_fetch_and(&(in)->val, (arg))
#  define ce_atomic_fetch_and_explicit(in, arg, ord) __atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_init(in, des) __atomic_init(&(in)->val, (des))
#  define CE_ATOMIC_VAR_INIT(val) {(val)}
#  define CE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define ce_atomic_flag_test_and_set(obj) atomic_flag_test_and_set(obj)
#  define ce_atomic_flag_test_and_set_explicit(obj, ord) atomic_flag_test_and_set_explicit((obj), (ord))
#  define ce_atomic_flag_clear(obj) atomic_flag_clear(obj)
#  define ce_atomic_flag_clear_explicit(obj, ord) atomic_flag_clear_explicit((obj), (ord))
#  define ce_atomic_thread_fence(order) atomic_thread_fence((memory_order)(order))
#  define ce_atomic_signal_fence(order) atomic_signal_fence((memory_order)(order))
#  define ce_kill_dependency(in) (__extension__ ({ \
  auto_type ice_kill_dependency_value = (in); \
  ice_kill_dependency_value; \
}))
#elif defined(ICE_ATOMICS_WIN32)
#  define CANVAS_ATOMIC_BOOL_LOCK_FREE     0
#  define CANVAS_ATOMIC_CHAR_LOCK_FREE     0
#  define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE 0
#  define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE 0
#  define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  0
#  define CANVAS_ATOMIC_SHORT_LOCK_FREE    0
#  define CANVAS_ATOMIC_INT_LOCK_FREE      0
#  define CANVAS_ATOMIC_LONG_LOCK_FREE     0
#  define CANVAS_ATOMIC_LLONG_LOCK_FREE    0
#  define CANVAS_ATOMIC_POINTER_LOCK_FREE  0
#  define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE CANVAS_ATOMIC_CHAR_LOCK_FREE

#  define ICE_ATOMIC_DECL(type) struct { volatile type val; }
#  define ce_atomic_flag atomic_flag

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

#  define ce_atomic_is_lock_free(in) ice_impl_atomic_is_lock_free(&(in)->val)
#  define ce_atomic_store(in, des) ice_impl_atomic_store(&(in)->val, (des))
#  define ce_atomic_store_explicit(in, des, ord) ice_impl_atomic_store_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_load(in) ice_impl_atomic_load(&(in)->val)
#  define ce_atomic_load_explicit(in, ord) ice_impl_atomic_load_explicit(&(in)->val, (ord))
#  define ce_atomic_exchange(in, des) ice_impl_atomic_exchange(&(in)->val, (des))
#  define ce_atomic_exchange_explicit(in, des, ord) ice_impl_atomic_exchange_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_compare_exchange_strong(in, exp, des) ice_impl_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_compare_exchange_weak(in, exp, des) ice_impl_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_fetch_add(in, arg) ice_impl_atomic_fetch_add(&(in)->val, (arg))
#  define ce_atomic_fetch_add_explicit(in, arg, ord) ice_impl_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_sub(in, arg) ice_impl_atomic_fetch_sub(&(in)->val, (arg))
#  define ce_atomic_fetch_sub_explicit(in, arg, ord) ice_impl_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_or(in, arg) ice_impl_atomic_fetch_or(&(in)->val, (arg))
#  define ce_atomic_fetch_or_explicit(in, arg, ord) ice_impl_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_xor(in, arg) ice_impl_atomic_fetch_xor(&(in)->val, (arg))
#  define ce_atomic_fetch_xor_explicit(in, arg, ord) ice_impl_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_and(in, arg) ice_impl_atomic_fetch_and(&(in)->val, (arg))
#  define ce_atomic_fetch_and_explicit(in, arg, ord) ice_impl_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_init(in, des) ice_impl_atomic_init(&(in)->val, (des))
#  define CE_ATOMIC_VAR_INIT(val) {(val)}
#  define CE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define ce_atomic_flag_test_and_set(obj) ice_impl_atomic_flag_test_and_set(obj)
#  define ce_atomic_flag_test_and_set_explicit(obj, ord) ice_impl_atomic_flag_test_and_set_explicit((obj), (ord))
#  define ce_atomic_flag_clear(obj) ice_impl_atomic_flag_clear(obj)
#  define ce_atomic_flag_clear_explicit(obj, ord) ice_impl_atomic_flag_clear_explicit((obj), (ord))
#  define ce_atomic_thread_fence(order) ice_impl_atomic_thread_fence((memory_order)(order))
#  define ce_atomic_signal_fence(order) ice_impl_atomic_signal_fence((memory_order)(order))
#  define ce_kill_dependency(in) (in)
#elif defined(ICE_ATOMICS_MTXIMPL)
#  define CANVAS_ATOMIC_BOOL_LOCK_FREE     0
#  define CANVAS_ATOMIC_CHAR_LOCK_FREE     0
#  define CANVAS_ATOMIC_CHAR16_T_LOCK_FREE 0
#  define CANVAS_ATOMIC_CHAR32_T_LOCK_FREE 0
#  define CANVAS_ATOMIC_WCHAR_T_LOCK_FREE  0
#  define CANVAS_ATOMIC_SHORT_LOCK_FREE    0
#  define CANVAS_ATOMIC_INT_LOCK_FREE      0
#  define CANVAS_ATOMIC_LONG_LOCK_FREE     0
#  define CANVAS_ATOMIC_LLONG_LOCK_FREE    0
#  define CANVAS_ATOMIC_POINTER_LOCK_FREE  0
#  define CANVAS_ATOMIC_CHAR8_T_LOCK_FREE CANVAS_ATOMIC_CHAR_LOCK_FREE

#  define ICE_ATOMIC_DECL(type) struct { volatile type val; ce_mtx lock; }
#  define ce_atomic_flag atomic_flag

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

#  define ce_atomic_is_lock_free(in) ice_impl_atomic_is_lock_free(&(in)->val)
#  define ce_atomic_store(in, des) ice_impl_atomic_store(&(in)->val, (des))
#  define ce_atomic_store_explicit(in, des, ord) ice_impl_atomic_store_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_load(in) ice_impl_atomic_load(&(in)->val)
#  define ce_atomic_load_explicit(in, ord) ice_impl_atomic_load_explicit(&(in)->val, (ord))
#  define ce_atomic_exchange(in, des) ice_impl_atomic_exchange(&(in)->val, (des))
#  define ce_atomic_exchange_explicit(in, des, ord) ice_impl_atomic_exchange_explicit(&(in)->val, (des), (ord))
#  define ce_atomic_compare_exchange_strong(in, exp, des) ice_impl_atomic_compare_exchange_strong(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_strong_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_strong_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_compare_exchange_weak(in, exp, des) ice_impl_atomic_compare_exchange_weak(&(in)->val, (exp), (des))
#  define ce_atomic_compare_exchange_weak_explicit(in, exp, des, succ, fail) ice_impl_atomic_compare_exchange_weak_explicit(&(in)->val, (exp), (des), (succ), (fail))
#  define ce_atomic_fetch_add(in, arg) ice_impl_atomic_fetch_add(&(in)->val, (arg))
#  define ce_atomic_fetch_add_explicit(in, arg, ord) ice_impl_atomic_fetch_add_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_sub(in, arg) ice_impl_atomic_fetch_sub(&(in)->val, (arg))
#  define ce_atomic_fetch_sub_explicit(in, arg, ord) ice_impl_atomic_fetch_sub_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_or(in, arg) ice_impl_atomic_fetch_or(&(in)->val, (arg))
#  define ce_atomic_fetch_or_explicit(in, arg, ord) ice_impl_atomic_fetch_or_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_xor(in, arg) ice_impl_atomic_fetch_xor(&(in)->val, (arg))
#  define ce_atomic_fetch_xor_explicit(in, arg, ord) ice_impl_atomic_fetch_xor_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_fetch_and(in, arg) ice_impl_atomic_fetch_and(&(in)->val, (arg))
#  define ce_atomic_fetch_and_explicit(in, arg, ord) ice_impl_atomic_fetch_and_explicit(&(in)->val, (arg), (ord))
#  define ce_atomic_init(in, des) ice_impl_atomic_init(&(in)->val, (des))
#  define CE_ATOMIC_VAR_INIT(val) {(val)}
#  define CE_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define ce_atomic_flag_test_and_set(obj) ice_impl_atomic_flag_test_and_set(obj)
#  define ce_atomic_flag_test_and_set_explicit(obj, ord) ice_impl_atomic_flag_test_and_set_explicit((obj), (ord))
#  define ce_atomic_flag_clear(obj) ice_impl_atomic_flag_clear(obj)
#  define ce_atomic_flag_clear_explicit(obj, ord) ice_impl_atomic_flag_clear_explicit((obj), (ord))
#  define ce_atomic_thread_fence(order) ice_impl_atomic_thread_fence((memory_order)(order))
#  define ce_atomic_signal_fence(order) ice_impl_atomic_signal_fence((memory_order)(order))
#  define ce_kill_dependency(in) (in)
#endif

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

CE_NAMESPACE_END

#endif /* !CANVAS_HAS_ATOMICS */
