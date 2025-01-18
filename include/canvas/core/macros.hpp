/**
 * @file macros.hpp
 * @author Jacob Isonell (isonelljacob@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-09
 * 
 * @copyright Copyright (c) 2025
 * 
 * CanvasEngine is a cross platform multimedia library in C89
 * Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <canvas/cmake_configs.hpp>

#if !defined(ICANVAS_BUILD)
#	define ICANVAS_BUILD 1
#endif

#if defined(CANVAS_DEBUG)
#	undef CANVAS_DEBUG
#	define CANVAS_DEBUG 1
#else
#	define CANVAS_DEBUG 0
#endif

#if defined(_MSC_VER)
#	define CANVAS_COMPILER_MSVC 1
#	define ICANVAS_MSVC_VERSION _MSC_VER
#elif defined(__GNUC__)
#	define CANVAS_COMPILER_GNU 1
#	if defined(__clang__)
#		define CANVAS_COMPILER_CLANG 1
#		define ICANVAS_CLANG_VERSION \
	 (__clang_major__ * 10000 \
	+ __clang_minor__ * 100   \
	+ __clang_patchlevel__)
#	else
#		define CANVAS_COMPILER_GCC 1
#		define ICANVAS_GCC_VERSION \
	 (__GNUC__       * 10000 \
	+ __GNUC_MINOR__ * 100   \
	+ __GNUC_PATCHLEVEL__)
#	endif
#else
#	define CANVAS_COMPILER_UNKNOWN 1
#endif

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(_WIN64) || defined(__WINDOWS__)
#	define CANVAS_PLATFORM_WINDOWS 1
#elif defined(__APPLE__) || defined(__MACH__) || defined(Macintosh) || defined(macintosh)
#	define CANVAS_PLATFORM_MACOS 1
# if !defined(CANVAS_MACOS_EXPERIMENTAL)
#		error CanvasEngine has not been tested yet on MacOS. To remove this error message, define the CANVAS_MACOS_EXPERIMENTAL macro
#	endif
#elif defined(unix) || defined(__unix__) || defined(__unix)
#	define CANVAS_PLATFORM_UNIX 1
#	if defined(linux) || defined(__linux__) || defined(__linux) || defined(__gnu__linux__)
#		define CANVAS_PLATFORM_LINUX 1
#	endif
#else
#	define CANVAS_PLATFORM_UNKNOWN 1
#endif

#if defined(__i386__) || defined(__i386) || defined(_M_IX86) || defined(_X86_)
#	define CANVAS_ARCH_I386 1
#elif defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(__amd64)
#define CANVAS_ARCH_X86_64 1
#elif defined(__arm__) || defined(_M_ARM)
#define CANVAS_ARCH_ARM 1
#elif defined(__aarch64__) || defined(_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined(_M_ARM64EC)
#define CANVAS_ARCH_ARM64 1
#else
#define CANVAS_ARCH_UNKNOWN 1
#endif

#if !defined(CANVAS_COMPILER_MSVC)
#	define CANVAS_COMPILER_MSVC 0
#endif
#if !defined(CANVAS_COMPILER_GNU)
#	define CANVAS_COMPILER_GNU 0
#endif
#if !defined(CANVAS_COMPILER_CLANG)
#	define CANVAS_COMPILER_CLANG 0
#endif
#if !defined(CANVAS_COMPILER_GCC)
#	define CANVAS_COMPILER_GCC 0
#endif
#if !defined(CANVAS_COMPILER_UNKNOWN)
#	define CANVAS_COMPILER_UNKNOWN 0
#endif
#if !defined(CANVAS_PLATFORM_WINDOWS)
#	define CANVAS_PLATFORM_WINDOWS 0
#endif
#if !defined(CANVAS_PLATFORM_MACOS)
#	define CANVAS_PLATFORM_MACOS 0
#endif
#if !defined(CANVAS_PLATFORM_UNIX)
#	define CANVAS_PLATFORM_UNIX 0
#endif
#if !defined(CANVAS_PLATFORM_LINUX)
#	define CANVAS_PLATFORM_LINUX 0
#endif
#if !defined(CANVAS_PLATFORM_UNKNOWN)
#	define CANVAS_PLATFORM_UNKNOWN 0
#endif
#if !defined(CANVAS_ARCH_I386)
#	define CANVAS_ARCH_I386 0
#endif
#if !defined(CANVAS_ARCH_X86_64)
#	define CANVAS_ARCH_X86_64 0
#endif
#if !defined(CANVAS_ARCH_ARM)
#	define CANVAS_ARCH_ARM 0
#endif
#if !defined(CANVAS_ARCH_ARM64)
#	define CANVAS_ARCH_ARM64 0
#endif
#if !defined(CANVAS_ARCH_UNKNOWN)
#	define CANVAS_ARCH_UNKNOWN 0
#endif

#define CANVAS_PRAGMAX(x) _Pragma(#x)
#define CANVAS_PRAGMA(x)  CANVAS_PRAGMAX(x)

#if CANVAS_COMPILER_GNU
#define ICANVAS_WARN_PUSH_GNU       CANVAS_PRAGMA(GCC diagnostic push)
#define ICANVAS_WARN_POP_GNU        CANVAS_PRAGMA(GCC diagnostic pop)
#define ICANVAS_WARN_DISABLE_GNU(x) CANVAS_PRAGMA(GCC diagnostic ignored x)
#define ICANVAS_WARN_RESTORE_GNU(x) CANVAS_PRAGMA(GCC diagnostic warning x)
#define ICANVAS_WARN_ERROR_GNU(x)   CANVAS_PRAGMA(GCC diagnostic error x)
#else
#define ICANVAS_WARN_PUSH_GNU
#define ICANVAS_WARN_POP_GNU
#define ICANVAS_WARN_DISABLE_GNU(x)
#define ICANVAS_WARN_RESTORE_GNU(x)
#define ICANVAS_WARN_ERROR_GNU(x)
#endif

#if CANVAS_COMPILER_GCC
#define ICANVAS_WARN_PUSH_GCC       ICANVAS_WARN_PUSH_GNU
#define ICANVAS_WARN_POP_GCC        ICANVAS_WARN_POP_GNU
#define ICANVAS_WARN_DISABLE_GCC(x) ICANVAS_WARN_DISABLE_GNU(x)
#define ICANVAS_WARN_RESTORE_GCC(x) ICANVAS_WARN_RESTORE_GNU(x)
#define ICANVAS_WARN_ERROR_GCC(x)   ICANVAS_WARN_ERROR_GNU(x)
#else
#define ICANVAS_WARN_PUSH_GCC
#define ICANVAS_WARN_POP_GCC
#define ICANVAS_WARN_DISABLE_GCC(x)
#define ICANVAS_WARN_RESTORE_GCC(x)
#define ICANVAS_WARN_ERROR_GCC(x)
#endif

#if CANVAS_COMPILER_CLANG
#define ICANVAS_WARN_PUSH_CLANG       ICANVAS_WARN_PUSH_GNU
#define ICANVAS_WARN_POP_CLANG        ICANVAS_WARN_POP_GNU
#define ICANVAS_WARN_DISABLE_CLANG(x) ICANVAS_WARN_DISABLE_GNU(x)
#define ICANVAS_WARN_RESTORE_CLANG(x) ICANVAS_WARN_RESTORE_GNU(x)
#define ICANVAS_WARN_ERROR_CLANG(x)   ICANVAS_WARN_ERROR_GNU(x)
#else
#define ICANVAS_WARN_PUSH_CLANG
#define ICANVAS_WARN_POP_CLANG
#define ICANVAS_WARN_DISABLE_CLANG(x)
#define ICANVAS_WARN_RESTORE_CLANG(x)
#define ICANVAS_WARN_ERROR_CLANG(x)
#endif

#if CANVAS_COMPILER_MSVC
#define ICANVAS_WARN_PUSH_MSVC       CANVAS_PRAGMA(warning(push))
#define ICANVAS_WARN_POP_MSVC        CANVAS_PRAGMA(warning(pop))
#define ICANVAS_WARN_DISABLE_MSVC(x) CANVAS_PRAGMA(warning(disable : x))
#define ICANVAS_WARN_RESTORE_MSVC(x) CANVAS_PRAGMA(warning(default : x))
#define ICANVAS_WARN_ERROR_MSVC(x)   CANVAS_PRAGMA(warning(error : x))
#else
#define ICANVAS_WARN_PUSH_MSVC
#define ICANVAS_WARN_POP_MSVC
#define ICANVAS_WARN_DISABLE_MSVC(x)
#define ICANVAS_WARN_RESTORE_MSVC(x)
#define ICANVAS_WARN_ERROR_MSVC(x)
#endif

#if CANVAS_COMPILER_GNU
#define ICANVAS_WARN_PUSH ICANVAS_WARN_PUSH_GNU
#define ICANVAS_WARN_POP  ICANVAS_WARN_POP_GNU
#elif CANVAS_COMPILER_MSVC
#define ICANVAS_WARN_PUSH ICANVAS_WARN_PUSH_MSVC
#define ICANVAS_WARN_POP  ICANVAS_WARN_POP_MSVC
#else
#define ICANVAS_WARN_PUSH
#define ICANVAS_WARN_POP
#endif

#if CANVAS_COMPILER_MSVC
#define ICANVAS_CXX_STANDARD _MSVC_LANG
#else
#define ICANVAS_CXX_STANDARD __cplusplus
#endif

#if ICANVAS_CXX_STANDARD < 200202L
#if CANVAS_COMPILER_MSVC
#	error CanvasEngine is built for the C++20 standard. Add the compiler flag /std:c++20 to fix this
#elif CANVAS_COMPILER_GNU
#	error CanvasEngine is built for the C++20 standard. Add the compiler flag --std=c++20 to fix this
#else
#	error CanvasEngine is built for the C++20 standard. Refer to your compiler manual to set the langauge to C++20 if it supports it
#endif
#endif

#if defined(__has_feature) && CANVAS_COMPILER_GNU
#define ICANVAS_HAS_GNU_FEATURE(x) __has_feature(x)
#else
#define ICANVAS_HAS_GNU_FEATURE(x) 0
#endif

#if defined(__has_builtin) && CANVAS_COMPILER_GNU
#define ICANVAS_HAS_GNU_BUILTIN(x) __has_builtin(x)
#else
#define ICANVAS_HAS_GNU_BUILTIN(x) 0
#endif

#if defined(__has_extension) && CANVAS_COMPILER_GNU
#define ICANVAS_HAS_GNU_EXTENSION(x) __has_extension(x)
#else
#define ICANVAS_HAS_GNU_EXTENSION(x) 0
#endif

#if defined(__has_constexpr_builtin) && CANVAS_COMPILER_GNU
#define ICANVAS_HAS_GNU_CONSTEXPR_BUILTIN(x) __has_constexpr_builtin(x)
#else
#define ICANVAS_HAS_GNU_CONSTEXPR_BUILTIN(x) 0
#endif

#if defined(__has_include)
#define ICANVAS_HAS_INCLUDE(x) __has_include(x)
#else
#define ICANVAS_HAS_INCLUDE(x) 0
#endif

#if defined(__has_cpp_attribute) && defined(__cpp_attributes) && 200809L <= __cpp_attributes
#define ICANVAS_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
#define ICANVAS_HAS_CPP_ATTRIBUTE(x) 0
#endif

#if defined(__has_attribute) && CANVAS_COMPILER_GNU
#define ICANVAS_HAS_GNU_ATTRIBUTE(x) __has_attribute(x)
#else
#define ICANVAS_HAS_GNU_ATTRIBUTE(x) 0
#endif

#if defined(__has_attribute)
#define ICANVAS_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
#define ICANVAS_HAS_ATTRIBUTE(x) 0
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(__cdecl__)
#define ICANVAS_CDECL __attribute__((__cdecl__))
#elif CANVAS_COMPILER_MSVC
#define ICANVAS_CDECL __cdecl
#else
#define ICANVAS_CDECL
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(__stdcall__)
#define ICANVAS_STDCALL __attribute__((__stdcall__))
#elif CANVAS_COMPILER_MSVC
#define ICANVAS_STDCALL __stdcall
#else
#define ICANVAS_STDCALL
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(__fastcall__)
#define ICANVAS_FASTCALL __attribute__((__fastcall__))
#elif CANVAS_COMPILER_MSVC
#define ICANVAS_FASTCALL __fastcall
#else
#define ICANVAS_FASTCALL
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(__thiscall__)
#define ICANVAS_THISCALL __attribute__((__thiscall__))
#elif CANVAS_COMPILER_MSVC
#define ICANVAS_THISCALL __thiscall
#else
#define ICANVAS_THISCALL
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(__vectorcall__)
#define ICANVAS_VECTORCALL __attribute__((__vectorcall__))
#elif CANVAS_COMPILER_MSVC
#define ICANVAS_VECTORCALL __vectorcall
#else
#define ICANVAS_VECTORCALL ICANVAS_FASTCALL
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(visibility)
#define ICANVAS_DEFAULT_VIS   __attribute__((visibility("default")))
#define ICANVAS_HIDDEN_VIS    __attribute__((visibility("hidden")))
#define ICANVAS_INTERNAL_VIS  __attribute__((visibility("internal")))
#define ICANVAS_PROTECTED_VIS __attribute__((visibility("protected")))
#else
#define ICANVAS_DEFAULT_VIS
#define ICANVAS_HIDDEN_VIS
#define ICANVAS_INTERNAL_VIS
#define ICANVAS_PROTECTED_VIS
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(dllimport)
#define CANVAS_DLLIMPORT __attribute__((dllimport))
#elif CANVAS_COMPILER_MSVC
#define CANVAS_DLLIMPORT __declspec(dllimport)
#else
#define CANVAS_DLLIMPORT ICANVAS_DEFAULT_VIS
#endif

#if ICANVAS_HAS_GNU_ATTRIBUTE(dllexport)
#define CANVAS_DLLEXPORT __attribute__((dllexport))
#elif CANVAS_COMPILER_MSVC
#define CANVAS_DLLEXPORT __declspec(dllexport)
#else
#define CANVAS_DLLEXPORT ICANVAS_DEFAULT_VIS
#endif

#define ICANVAS_IMPL_NAMESPACE_BEGIN(name) \
	namespace name { \
	ICANVAS_WARN_PUSH

#define ICANVAS_IMPL_NAMESPACE_END \
	ICANVAS_WARN_POP \
	}

#define ICANVAS_NAMESPACE canvas
#define ICANVAS_NAMESPACE_BEGIN ICANVAS_IMPL_NAMESPACE_BEGIN(canvas)
#define ICANVAS_NAMESPACE_END ICANVAS_IMPL_NAMESPACE_END

#define ICANVAS_NAMESPACE_MATH ICANVAS_NAMESPACE::math
#define ICANVAS_NAMESPACE_MATH_BEGIN ICANVAS_IMPL_NAMESPACE_BEGIN(ICANVAS_NAMESPACE_MATH)
#define ICANVAS_NAMESPACE_MATH_END ICANVAS_IMPL_NAMESPACE_END

#define ICANVAS_NAMESPACE_GRAPHICS ICANVAS_NAMESPACE::graphics
#define ICANVAS_NAMESPACE_GRAPHICS_BEGIN ICANVAS_IMPL_NAMESPACE_BEGIN(ICANVAS_NAMESPACE_GRAPHICS)
#define ICANVAS_NAMESPACE_GRAPHICS_END ICANVAS_IMPL_NAMESPACE_END

#define ICANVAS_NAMESPACE_NETWORK ICANVAS_NAMESPACE::network
#define ICANVAS_NAMESPACE_NETWORK_BEGIN ICANVAS_IMPL_NAMESPACE_BEGIN(ICANVAS_NAMESPACE_NETWORK)
#define ICANVAS_NAMESPACE_NETWORK_END ICANVAS_IMPL_NAMESPACE_END

#define ICANVAS_NAMESPACE_INTERNAL internal
#define ICANVAS_NAMESPACE_INTERNAL_BEGIN ICANVAS_IMPL_NAMESPACE_BEGIN(internal) using namespace ::canvas::internal;
#define ICANVAS_NAMESPACE_INTERNAL_END ICANVAS_IMPL_NAMESPACE_END

#if CANVAS_SHARED
#if defined(ICANVAS_BUILD)
#define CANVAS_API    \
	ICANVAS_DEFAULT_VIS \
	CANVAS_DLLEXPORT
#else
#define CANVAS_API    \
	ICANVAS_DEFAULT_VIS \
	CANVAS_DLLIMPORT
#endif
#else
#define CANVAS_API ICANVAS_DEFAULT_VIS
#endif

#define CANVAS_MACRO_COMBINEX(a, b) a##b
#define CANVAS_MACRO_STRINGX(a)     #a
#define CANVAS_MACRO_LSTRINGX(a)    L"" #a
#define CANVAS_MACRO_COMBINE(a, b)  CANVAS_MACRO_COMBINEX(a, b)
#define CANVAS_MACRO_STRING(a)      CANVAS_MACRO_STRINGX(a)
#define CANVAS_MACRO_LSTRING(a)     CANVAS_MACRO_LSTRINGX(a)
#define CANVAS_UNIQUE_IDENTIFIER     CANVAS_MACRO_COMBINE(icanvas_unique_identifier_, __LINE__)
#define ICANVAS_UNIQUE_IDENTIFIER(x) CANVAS_MACRO_COMBINE(CANVAS_UNIQUE_IDENTIFIER, x)
#define CANVAS_UNIQUE_IDENTIFIER1 ICANVAS_UNIQUE_IDENTIFIER(_1)
#define CANVAS_UNIQUE_IDENTIFIER2 ICANVAS_UNIQUE_IDENTIFIER(_2)
#define CANVAS_UNIQUE_IDENTIFIER3 ICANVAS_UNIQUE_IDENTIFIER(_3)
#define CANVAS_UNIQUE_IDENTIFIER4 ICANVAS_UNIQUE_IDENTIFIER(_4)
#define CANVAS_UNIQUE_IDENTIFIER5 ICANVAS_UNIQUE_IDENTIFIER(_5)
#define CANVAS_UNIQUE_IDENTIFIER6 ICANVAS_UNIQUE_IDENTIFIER(_6)
#define CANVAS_UNIQUE_IDENTIFIER7 ICANVAS_UNIQUE_IDENTIFIER(_7)
#define CANVAS_UNIQUE_IDENTIFIER8 ICANVAS_UNIQUE_IDENTIFIER(_8)

#if ICANVAS_BUILD
#define CANVAS_EXPOSE_VULKAN
#if CANVAS_GRAPHICS_ENABLE_VULKAN
#if CANVAS_PLATFORM_WINDOWS
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#if CANVAS_GRAPHICS_SUPPORT_X11
#define VK_USE_PLATFORM_XLIB_KHR
#endif
#if CANVAS_GRAPHICS_SUPPORT_WAYLAND
#define VK_USE_PLATFORM_WAYLAND_KHR
#endif
#endif
#endif

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <csignal>
#include <concepts>
#include <utility>
#include <exception>
#include <stdexcept>

#if (defined(__cpp_exceptions) && 199711L <= __cpp_exceptions) || defined(CANVAS_ENABLE_EXCEPTIONS)
#define ICANVAS_EXCEPTIONS 1
#else
#define ICANVAS_EXCEPTIONS 0
#endif

#if (defined(__cpp_rtti) && 199711L <= __cpp_rtti) || defined(CANVAS_ENABLE_RTTI)
#define ICANVAS_RTTI 1
#else
#define ICANVAS_RTTI 0
#endif

ICANVAS_NAMESPACE_BEGIN

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using il8 = std::int_least8_t;
using il16 = std::int_least16_t;
using il32 = std::int_least32_t;
using il64 = std::int_least64_t;
using ul8 = std::uint_least8_t;
using ul16 = std::uint_least16_t;
using ul32 = std::uint_least32_t;
using ul64 = std::uint_least64_t;

using if8 = std::int_fast8_t;
using if16 = std::int_fast16_t;
using if32 = std::int_fast32_t;
using if64 = std::int_fast64_t;
using uf8 = std::uint_fast8_t;
using uf16 = std::uint_fast16_t;
using uf32 = std::uint_fast32_t;
using uf64 = std::uint_fast64_t;

using sz = std::size_t;
using pd = std::ptrdiff_t;
using iptr = std::intptr_t;
using uptr = std::uintptr_t;
using imax = std::intmax_t;
using umax = std::uintmax_t;
constexpr std::nullptr_t null = nullptr;
using null_t = std::nullptr_t;

[[noreturn]]
inline void unreachable() noexcept {
#if CANVAS_DEBUG
	std::raise(SIGINT);
#endif

#if ICANVAS_HAS_GNU_BUILTIN(__builtin_unreachable)
	__builtin_unreachable();
#elif CANVAS_COMPILER_MSVC
	__assume(false);
#elif !CANVAS_DEBUG
	std::abort();
#endif
}

ICANVAS_NAMESPACE_INTERNAL_BEGIN

template<typename T, typename ... Args>
[[noreturn]]
constexpr void dothrow([[maybe_unused]] Args&&... args) {
#if ICANVAS_EXCEPTIONS
	throw T { std::forward<Args>(args)... };
#else
	std::terminate();
#endif
}

template<typename T, typename ... Args>
[[noreturn]]
constexpr void dothrow_debug([[maybe_unused]] Args&&... args) {
#if CANVAS_DEBUG
	dothrow<T>(std::forward<Args>(args)...);
#else
	unreachable();
#endif
}

ICANVAS_NAMESPACE_INTERNAL_END

ICANVAS_NAMESPACE_END
