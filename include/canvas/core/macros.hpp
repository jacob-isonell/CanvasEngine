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

// Currently the audio library is not implemented
#undef CANVAS_AUDIO
#define CANVAS_AUDIO 0

// Currently the network library is not implemented
#undef CANVAS_NETWORK
#define CANVAS_NETWORK 0

#if !defined(ICANVAS_BUILD)
#	define ICANVAS_BUILD 1
#endif

#if defined(CANVAS_DEBUG) || defined(DEBUG)
#	undef CANVAS_DEBUG
#	define CANVAS_DEBUG 1
#else
#	define CANVAS_DEBUG 0
#endif

#if defined(_MSC_VER)
#	define CANVAS_COMPILER_MSVC 1
#elif defined(__GNUC__)
#	define CANVAS_COMPILER_GNU 1
#	if defined(__clang__)
#		define CANVAS_COMPILER_CLANG 1
#	else
#		define CANVAS_COMPILER_GCC 1
#	endif
#else
#	define CANVAS_COMPILER_UNKNOWN 1
#endif

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(_WIN64) || defined(__WINDOWS__)
#	define CANVAS_PLATFORM_WINDOWS 1
#elif defined(__APPLE__) || defined(__MACH__) || defined(Macintosh) || defined(macintosh)
#	define CANVAS_PLATFORM_MACOS 1
# if !defined(CANVAS_MACOS_EXPERIMENTAL)
#		error CanvasEngine has not been tested yet on MacOS and may not work or compile. To remove this error message, define the CANVAS_MACOS_EXPERIMENTAL macro
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

// Define the macros to 0 to silence compiler warnings
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

#if defined(__has_builtin) && CANVAS_COMPILER_GNU
#define ICANVAS_HAS_GNU_BUILTIN(x) __has_builtin(x)
#else
#define ICANVAS_HAS_GNU_BUILTIN(x) 0
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

#if CANVAS_COMPILER_MSVC
#	define CANVAS_ATTR_NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#elif ICANVAS_HAS_CPP_ATTRIBUTE(no_unique_address)
#	define CANVAS_ATTR_NO_UNIQUE_ADDRESS [[no_unique_address]]
#else
#	define CANVAS_ATTR_NO_UNIQUE_ADDRESS
#endif

#define ICANVAS_IMPL_NAMESPACE_BEGIN(name) \
	namespace name { \
	ICANVAS_WARN_PUSH

#define ICANVAS_IMPL_NAMESPACE_END \
	ICANVAS_WARN_POP \
	}

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

#define CANVAS_MACRO_COMBINEX(a, b)  a##b
#define CANVAS_MACRO_STRINGX(a)      #a
#define CANVAS_MACRO_LSTRINGX(a)     L"" #a
#define CANVAS_MACRO_COMBINE(a, b)   CANVAS_MACRO_COMBINEX(a, b)
#define CANVAS_MACRO_STRING(a)       CANVAS_MACRO_STRINGX(a)
#define CANVAS_MACRO_LSTRING(a)      CANVAS_MACRO_LSTRINGX(a)
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
#include <memory>
#include <compare>
#include <utility>
#include <algorithm>
#include <functional>
#include <ranges>
#include <array>
#include <bit>

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

namespace canvas {

enum struct compiler {
	msvc,
	clang,
	gcc,
	unknown,
	
	current = 
#if CANVAS_COMPILER_MSVC
	msvc,
#elif CANVAS_COMPILER_CLANG
	clang,
#elif CANVAS_COMPILER_GCC
	gcc,
#else
	unknown,
#endif
};

enum struct platform {
	windows,
	macos,
	linux,
	unknown,
	
	current = 
#if CANVAS_PLATFORM_WINDOWS
	windows,
#elif CANVAS_PLATFORM_MACOS
	macos,
#elif CANVAS_PLATFORM_LINUX
	linux,
#else
	unknown,
#endif
};

static constexpr bool platform_unix = CANVAS_PLATFORM_UNIX;

enum struct cpu_arch {
	x86_64,
	i386,
	arm,
	arm64,
	unknown,
	
	current = 
#if CANVAS_ARCH_I386
	x86_64,
#elif CANVAS_ARCH_X86_64
	i386,
#elif CANVAS_ARCH_ARM
	arm,
#elif CANVAS_ARCH_ARM64
	arm64,
#endif
};

using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::int_least8_t;
using std::int_least16_t;
using std::int_least32_t;
using std::int_least64_t;
using std::uint_least8_t;
using std::uint_least16_t;
using std::uint_least32_t;
using std::uint_least64_t;
using std::int_fast8_t;
using std::int_fast16_t;
using std::int_fast32_t;
using std::int_fast64_t;
using std::uint_fast8_t;
using std::uint_fast16_t;
using std::uint_fast32_t;
using std::uint_fast64_t;
using std::size_t;
using std::ptrdiff_t;
using std::intptr_t;
using std::uintptr_t;
using std::intmax_t;
using std::uintmax_t;
using std::nullptr_t;
using std::get;
using std::array;
using std::to_array;

using i8     = int8_t;
using i16    = int16_t;
using i32    = int32_t;
using i64    = int64_t;
using u8     = uint8_t;
using u16    = uint16_t;
using u32    = uint32_t;
using u64    = uint64_t;
using il8    = int_least8_t;
using il16   = int_least16_t;
using il32   = int_least32_t;
using il64   = int_least64_t;
using ul8    = uint_least8_t;
using ul16   = uint_least16_t;
using ul32   = uint_least32_t;
using ul64   = uint_least64_t;
using if8    = int_fast8_t;
using if16   = int_fast16_t;
using if32   = int_fast32_t;
using if64   = int_fast64_t;
using uf8    = uint_fast8_t;
using uf16   = uint_fast16_t;
using uf32   = uint_fast32_t;
using uf64   = uint_fast64_t;
using sz     = size_t;
using pd     = ptrdiff_t;
using iptr   = intptr_t;
using uptr   = uintptr_t;
using imax   = intmax_t;
using umax   = uintmax_t;
using null_t = nullptr_t;

inline constexpr null_t null = nullptr;

enum class byte : u8 { };
enum class sbyte : i8 { };

namespace literals {

consteval i8   operator""_i8   (unsigned long long v) noexcept { return (i8)v; }
consteval i16  operator""_i16  (unsigned long long v) noexcept { return (i16)v; }
consteval i32  operator""_i32  (unsigned long long v) noexcept { return (i32)v; }
consteval i64  operator""_i64  (unsigned long long v) noexcept { return (i64)v; }
consteval u8   operator""_u8   (unsigned long long v) noexcept { return (u8)v; }
consteval u16  operator""_u16  (unsigned long long v) noexcept { return (u16)v; }
consteval u32  operator""_u32  (unsigned long long v) noexcept { return (u32)v; }
consteval u64  operator""_u64  (unsigned long long v) noexcept { return (u64)v; }
consteval il8  operator""_il8  (unsigned long long v) noexcept { return (il8)v; }
consteval il16 operator""_il16 (unsigned long long v) noexcept { return (il16)v; }
consteval il32 operator""_il32 (unsigned long long v) noexcept { return (il32)v; }
consteval il64 operator""_il64 (unsigned long long v) noexcept { return (il64)v; }
consteval ul8  operator""_ul8  (unsigned long long v) noexcept { return (ul8)v; }
consteval ul16 operator""_ul16 (unsigned long long v) noexcept { return (ul16)v; }
consteval ul32 operator""_ul32 (unsigned long long v) noexcept { return (ul32)v; }
consteval ul64 operator""_ul64 (unsigned long long v) noexcept { return (ul64)v; }
consteval if8  operator""_if8  (unsigned long long v) noexcept { return (if8)v; }
consteval if16 operator""_if16 (unsigned long long v) noexcept { return (if16)v; }
consteval if32 operator""_if32 (unsigned long long v) noexcept { return (if32)v; }
consteval if64 operator""_if64 (unsigned long long v) noexcept { return (if64)v; }
consteval uf8  operator""_uf8  (unsigned long long v) noexcept { return (uf8)v; }
consteval uf16 operator""_uf16 (unsigned long long v) noexcept { return (uf16)v; }
consteval uf32 operator""_uf32 (unsigned long long v) noexcept { return (uf32)v; }
consteval uf64 operator""_uf64 (unsigned long long v) noexcept { return (uf64)v; }
consteval sz   operator""_sz   (unsigned long long v) noexcept { return (sz)v; }
consteval pd   operator""_pd   (unsigned long long v) noexcept { return (pd)v; }
consteval iptr operator""_iptr (unsigned long long v) noexcept { return (iptr)v; }
consteval uptr operator""_uptr (unsigned long long v) noexcept { return (uptr)v; }
consteval imax operator""_imax (unsigned long long v) noexcept { return (imax)v; }
consteval umax operator""_umax (unsigned long long v) noexcept { return (umax)v; }

} // !namespace literals

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

struct ignore_t {
	template<typename ... Args>
	constexpr const ignore_t& operator()(const Args&...) const noexcept {
		return *this;
	}
	
	template<typename T>
	constexpr const ignore_t& operator=(const T&) const noexcept {
		return *this;
	}
};

constexpr ignore_t ignore { };

namespace internal {
using namespace ::canvas::internal;
using namespace ::canvas::literals;

struct min_t {
	template<
		typename T,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const T*, Proj>> Comp = std::ranges::less
	>
	constexpr const T& operator()(const T& a, const T& b, Comp comp = {}, Proj proj = {}) const {
		return std::invoke(comp,
			std::invoke(proj, a),
			std::invoke(proj, b)
		) ? a : b;
	}
	
	template<
		typename T,
		typename U,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const std::common_type_t<T, U>*, Proj>> Comp = std::ranges::less
	> requires (std::convertible_to<T, std::common_type_t<T, U>> && std::convertible_to<U, std::common_type_t<T, U>>)
	constexpr std::common_type_t<T, U> operator()(const T& a, const U& b, Comp comp = {}, Proj proj = {}) const {
		return (*this).operator()<std::common_type_t<T, U>, Proj, Comp>(
			static_cast<std::common_type_t<T, U>>(a),
			static_cast<std::common_type_t<T, U>>(b),
			std::ref(comp),
			std::ref(proj)
		);
	}
	
	template<
		std::copyable T,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const T*, Proj>> Comp = std::ranges::less
	>
	constexpr T operator()(std::initializer_list<T> r, Comp comp = {}, Proj proj = {}) const {
		const auto end = r.end();
		auto out_it = r.begin();
		auto it = out_it;
		
		while (++it != end) {
			if (std::invoke(comp,
				std::invoke(proj, *it),
				std::invoke(proj, *out_it)
			)) {
				out_it = it;
			}
		}
		
		return *out_it;
	}

	template<
		std::ranges::input_range R,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<std::ranges::iterator_t<R>, Proj>> Comp = std::ranges::less
	>
	requires std::indirectly_copyable_storable<std::ranges::iterator_t<R>, std::ranges::range_value_t<R>*>
	constexpr std::ranges::range_value_t<R> operator()(R&& r, Comp comp = {}, Proj proj = {}) const {
		const auto end = std::ranges::end(r);
		auto out_it = std::ranges::begin(r);
		auto it = out_it;
		
		while (++it != end) {
			if (std::invoke(comp,
				std::invoke(proj, *it),
				std::invoke(proj, *out_it)
			)) {
				out_it = it;
			}
		}
		
		return *out_it;
	}
};

struct max_t {
	template<
		typename T,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const T*, Proj>> Comp = std::ranges::less
	>
	constexpr const T& operator()(const T& a, const T& b, Comp comp = {}, Proj proj = {}) const {
		return std::invoke(comp,
			std::invoke(proj, b),
			std::invoke(proj, a)
		) ? a : b;
	}
	
	template<
		typename T,
		typename U,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const std::common_type_t<T, U>*, Proj>> Comp = std::ranges::less
	>
	constexpr std::common_type_t<T, U> operator()(const T& a, const T& b, Comp comp = {}, Proj proj = {}) const {
		return std::invoke(comp,
			std::invoke(proj, b),
			std::invoke(proj, a)
		) ? a : b;
	}
	
	template<
		std::copyable T,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const T*, Proj>> Comp = std::ranges::less
	>
	constexpr T operator()(std::initializer_list<T> r, Comp comp = {}, Proj proj = {}) const {
		const auto end = r.end();
		auto out_it = r.begin();
		auto it = out_it;
		
		while (++it != end) {
			if (std::invoke(comp,
				std::invoke(proj, *out_it),
				std::invoke(proj, *it)
			)) {
				out_it = it;
			}
		}
		
		return *out_it;
	}

	template<
		std::ranges::input_range R,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<std::ranges::iterator_t<R>, Proj>> Comp = std::ranges::less
	>
	requires std::indirectly_copyable_storable<std::ranges::iterator_t<R>, std::ranges::range_value_t<R>*>
	constexpr std::ranges::range_value_t<R> operator()(R&& r, Comp comp = {}, Proj proj = {}) const {
		const auto end = std::ranges::end(r);
		auto out_it = std::ranges::begin(r);
		auto it = out_it;
		
		while (++it != end) {
			if (std::invoke(comp,
				std::invoke(proj, *out_it),
				std::invoke(proj, *it)
			)) {
				out_it = it;
			}
		}
		
		return *out_it;
	}
};

struct clamp_t {
	template<
		typename T,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const T*, Proj>> Comp = std::ranges::less
	>
	constexpr const T& operator()(
		const T& v,
		const T& lo,
		const T& hi,
		Comp comp = {},
		Proj proj = {}
	) {
		return std::ranges::clamp(v, lo, hi, std::ref(comp), std::ref(proj));
	}
	
	template<
		typename T,
		std::convertible_to<T> U,
		std::convertible_to<T> V,
		typename Proj = std::identity,
		std::indirect_strict_weak_order<std::projected<const T*, Proj>> Comp = std::ranges::less
	>
	constexpr const T& operator()(
		const T& v,
		const U& lo,
		const V& hi,
		Comp comp = {},
		Proj proj = {}
	) {
		return std::ranges::clamp(
			v,
			static_cast<T>(lo),
			static_cast<T>(hi),
			std::ref(comp),
			std::ref(proj)
		);
	}
};

} // !namespace internal

inline constexpr internal::min_t min { };
inline constexpr internal::max_t max { };
inline constexpr internal::clamp_t clamp { };

} // !namespace canvas
