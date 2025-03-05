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

#if defined(__GNUC__)
#  define CANVAS_COMPILER_GNU 1
#  if defined(__clang__)
#    define CANVAS_COMPILER_CLANG 1
#  else
#    define CANVAS_COMPILER_GCC 1
#  endif
#elif defined(_MSC_VER)
#  define CANVAS_COMPILER_MSVC 1
#else
#  define CANVAS_COMPILER_OTHER 1
#endif

#ifndef CANVAS_COMPILER_GNU
#  define CANVAS_COMPILER_GNU 0
#endif
#ifndef CANVAS_COMPILER_CLANG
#  define CANVAS_COMPILER_CLANG 0
#endif
#ifndef CANVAS_COMPILER_GCC
#  define CANVAS_COMPILER_GCC 0
#endif
#ifndef CANVAS_COMPILER_MSVC
#  define CANVAS_COMPILER_MSVC 0
#endif
#ifndef CANVAS_COMPILER_OTHER
#  define CANVAS_COMPILER_OTHER 0
#endif

#if defined(__unix__) || defined(__unix) || defined(unix)
#  define CANVAS_PLATFORM_UNIX 1
#else
#  define CANVAS_PLATFORM_UNIX 0
#endif

#if defined(BSD)
#  define CANVAS_PLATFORM_BSD 1
#  if defined(__FreeBSD__)
#    define CANVAS_PLATFORM_FREEBSD 1
#  endif
#  if defined(__NetBSD__)
#    define CANVAS_PLATFORM_NETBSD 1
#  endif
#  if defined(__OpenBSD__)
#    define CANVAS_PLATFORM_OPENBSD 1
#  endif
#  if defined(__bsdi__)
#    define CANVAS_PLATFORM_BSDI 1
#  endif
#  if defined(__DragonFly__)
#    define CANVAS_PLATFORM_DRAGONFLY 1
#  endif
#  if defined(__MidnightBSD__)
#    define CANVAS_PLATFORM_MIDNIGHTBSD 1
#  endif
#else
#  define CANVAS_PLATFORM_BSD 0
#  define CANVAS_PLATFORM_FREEBSD 0
#  define CANVAS_PLATFORM_NETBSD 0
#  define CANVAS_PLATFORM_OPENBSD 0
#  define CANVAS_PLATFORM_BSDI 0
#  define CANVAS_PLATFORM_DRAGONFLY 0
#  define CANVAS_PLATFORM_MIDNIGHTBSD 0
#endif

#if defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WINDOWS__)
#  define CANVAS_PLATFORM_WINDOWS 1
#else
#  define CANVAS_PLATFORM_WINDOWS 0
#endif

#if defined(__ANDROID__)
#  define CANVAS_PLATFORM_ANDROID 1
#else
#  define CANVAS_PLATFORM_ANDROID 0
#endif

#if !CANVAS_PLATFORM_UNIX && !CANVAS_PLATFORM_BSD && \
  !CANVAS_PLATFORM_WINDOWS && !CANVAS_PLATFORM_ANDROID
#  define CANVAS_PLATFORM_OTHER 1
#else
#  define CANVAS_PLATFORM_OTHER 0
#endif

#if defined(__CYGWIN__)
#  define CANVAS_ENVIROMENT_CYGWIN 1
#else
#  define CANVAS_ENVIROMENT_CYGWIN 0
#endif

#if defined(EMSCRIPTEN) || defined(__EMSCRIPTEN__)
#  define CANVAS_ENVIROMENT_EMSCRIPTEN 1
#else
#  define CANVAS_ENVIROMENT_EMSCRIPTEN 0
#endif

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || \
  defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#  define CANVAS_ARCH_AMD64 1
#elif defined(__arm__) || defined(__arm) || defined(__TARGET_ARCH_ARM) || \
  defined(_ARM) || defined(_M_ARM)
#  define CANVAS_ARCH_ARM 1
#elif defined(__aarch64__) || defined(_M_ARM64)
#  define CANVAS_ARCH_ARM64 1
#elif (defined(_M_IX86) && defined(__386__)) || \
  defined(i386) || defined(__i386) || defined(__i386__) || \
  defined(__IA32__) || defined(__X86__) || defined(_X86_)
#  define CANVAS_ARCH_X86 1
#else
#  define CANVAS_ARCH_OTHER 1
#endif

#ifndef CANVAS_ARCH_AMD64
#  define CANVAS_ARCH_AMD64 0
#endif
#ifndef CANVAS_ARCH_ARM
#  define CANVAS_ARCH_ARM 0
#endif
#ifndef CANVAS_ARCH_ARM64
#  define CANVAS_ARCH_ARM64 0
#endif
#ifndef CANVAS_ARCH_X86
#  define CANVAS_ARCH_X86 0
#endif
#ifndef CANVAS_ARCH_OTHER
#  define CANVAS_ARCH_OTHER 0
#endif

#define CE_PRAGMAX(x) _Pragma(#x)
#define CE_PRAGMA(x)  CE_PRAGMAX(x)

#if CANVAS_COMPILER_GNU
#  define CE_WARN_PUSH_GNU       CE_PRAGMA(GCC diagnostic push)
#  define CE_WARN_POP_GNU        CE_PRAGMA(GCC diagnostic pop)
#  define CE_WARN_DISABLE_GNU(x) CE_PRAGMA(GCC diagnostic ignored x)
#  define CE_WARN_RESTORE_GNU(x) CE_PRAGMA(GCC diagnostic warning x)
#  define CE_WARN_ERROR_GNU(x)   CE_PRAGMA(GCC diagnostic error x)
#else
#  define CE_WARN_PUSH_GNU
#  define CE_WARN_POP_GNU
#  define CE_WARN_DISABLE_GNU(x)
#  define CE_WARN_RESTORE_GNU(x)
#  define CE_WARN_ERROR_GNU(x)
#endif

#if CANVAS_COMPILER_GCC
#  define CE_WARN_PUSH_GCC       CE_WARN_PUSH_GNU
#  define CE_WARN_POP_GCC        CE_WARN_POP_GNU
#  define CE_WARN_DISABLE_GCC(x) CE_WARN_DISABLE_GNU(x)
#  define CE_WARN_RESTORE_GCC(x) CE_WARN_RESTORE_GNU(x)
#  define CE_WARN_ERROR_GCC(x)   CE_WARN_ERROR_GNU(x)
#else
#  define CE_WARN_PUSH_GCC
#  define CE_WARN_POP_GCC
#  define CE_WARN_DISABLE_GCC(x)
#  define CE_WARN_RESTORE_GCC(x)
#  define CE_WARN_ERROR_GCC(x)
#endif

#if CANVAS_COMPILER_CLANG
#  define CE_WARN_PUSH_CLANG       CE_WARN_PUSH_GNU
#  define CE_WARN_POP_CLANG        CE_WARN_POP_GNU
#  define CE_WARN_DISABLE_CLANG(x) CE_WARN_DISABLE_GNU(x)
#  define CE_WARN_RESTORE_CLANG(x) CE_WARN_RESTORE_GNU(x)
#  define CE_WARN_ERROR_CLANG(x)   CE_WARN_ERROR_GNU(x)
#else
#  define CE_WARN_PUSH_CLANG
#  define CE_WARN_POP_CLANG
#  define CE_WARN_DISABLE_CLANG(x)
#  define CE_WARN_RESTORE_CLANG(x)
#  define CE_WARN_ERROR_CLANG(x)
#endif

#if CANVAS_COMPILER_MSVC
#  define CE_WARN_PUSH_MSVC       CE_PRAGMA(warning(push))
#  define CE_WARN_POP_MSVC        CE_PRAGMA(warning(pop))
#  define CE_WARN_DISABLE_MSVC(x) CE_PRAGMA(warning(disable : x))
#  define CE_WARN_RESTORE_MSVC(x) CE_PRAGMA(warning(default : x))
#  define CE_WARN_ERROR_MSVC(x)   CE_PRAGMA(warning(error : x))
#else
#  define CE_WARN_PUSH_MSVC
#  define CE_WARN_POP_MSVC
#  define CE_WARN_DISABLE_MSVC(x)
#  define CE_WARN_RESTORE_MSVC(x)
#  define CE_WARN_ERROR_MSVC(x)
#endif

#if CANVAS_COMPILER_GNU
#  define CE_WARN_PUSH CE_WARN_PUSH_GNU
#  define CE_WARN_POP  CE_WARN_POP_GNU
#elif CANVAS_COMPILER_MSVC
#  define CE_WARN_PUSH CE_WARN_PUSH_MSVC
#  define CE_WARN_POP  CE_WARN_POP_MSVC
#else
#  define CE_WARN_PUSH
#  define CE_WARN_POP
#endif

#if defined(__cplusplus)
#define CE_CXX 1

#if CANVAS_COMPILER_MSVC
#  define ICE_CXXVER _MSVC_LANG
#else
#  define ICE_CXXVER __cplusplus
#endif

#if !defined(CANVAS_SKIP_COMPILER_CHECKS) && (ICE_CXXVER < 201103L)
#  error CanvasEngine requires a C++11 compiler to compile
#endif

#define CE_EXTERNC extern "C"
#define CE_EXTERNC_BEGIN CE_EXTERNC {
#define CE_EXTERNC_END }
#define CE_STRUCT_INIT(type) type

#define ICE_CXX_CHECK_STANDARD(value) ((value) <= ICE_CXXVER)
#define ICE_C_CHECK_STANDARD(value) 0

#else
#define CE_CXX 0

#ifndef CANVAS_SKIP_COMPILER_CHECKS
#  if CANVAS_COMPILER_MSVC
#  elif defined(__STDC__) && __STDC__
#  else
#    error CanvasEngine does not support the current compiler
#  endif
#endif

#define CE_EXTERNC
#define CE_EXTERNC_BEGIN
#define CE_EXTERNC_END
#define CE_STRUCT_INIT(type) (type)

#define ICE_CXX_CHECK_STANDARD(value) 0
#if defined(__STDC_VERSION__) && __STDC_VERSION__
#define ICE_C_CHECK_STANDARD(value) ((value) <= __STDC_VERSION__)
#else
#define ICE_C_CHECK_STANDARD(value) 0
#endif

#if !defined(CANVAS_SKIP_COMPILER_CHECKS) && !ICE_C_CHECK_STANDARD(199901L)
#  error CanvasEngine requires C99 and does not support any earlier standard
#endif

#endif

#define CE_C89_STD ICE_C_CHECK_STANDARD(199409L)
#define CE_C99_STD ICE_C_CHECK_STANDARD(199901L)
#define CE_C11_STD ICE_C_CHECK_STANDARD(201112L)
#define CE_C17_STD ICE_C_CHECK_STANDARD(201710L)
#define CE_C23_STD ICE_C_CHECK_STANDARD(202311L)

#define CE_CXX98_STD ICE_CXX_CHECK_STANDARD(199711L)
#define CE_CXX11_STD ICE_CXX_CHECK_STANDARD(201103L)
#define CE_CXX14_STD ICE_CXX_CHECK_STANDARD(201402L)
#define CE_CXX17_STD ICE_CXX_CHECK_STANDARD(201703L)
#define CE_CXX20_STD ICE_CXX_CHECK_STANDARD(202002L)
#define CE_CXX23_STD ICE_CXX_CHECK_STANDARD(202302L)

#if CE_CXX
# define icebool bool
# define icetrue true
# define icefalse false
# define CE_RESTRICT __restrict
# define CE_INLINE inline
#elif CE_C99_STD
# if CE_C23_STD || (defined(__bool_true_false_are_defined) && __bool_true_false_are_defined)
#   define icebool bool
#   define icetrue true
#   define icefalse false
# else
#   define icebool _Bool
#   define icetrue ((cebool)1)
#   define icefalse ((cebool)0)
# endif
# define CE_RESTRICT restrict
# define CE_INLINE static inline
#else
# define icebool unsigned char
# define icetrue ((cebool)1)
# define icefalse ((cebool)0)
# define CE_RESTRICT
# if CANVAS_COMPILER_GNU
#   define CE_INLINE static __inline
# else
#   define CE_INLINE static
# endif
#endif

#if CANVAS_COMPILER_GNU && defined(__has_attribute)
#  define ICE_HAS_GNU_ATTRIB(x) __has_attribute(x)
#else
#  define ICE_HAS_GNU_ATTRIB(x) 0
#endif

#if CANVAS_COMPILER_GNU && defined(__has_builtin)
#  define ICE_HAS_GNU_BUILTIN(x) __has_builtin(x)
#else
#  define ICE_HAS_GNU_BUILTIN(x) 0
#endif

#if defined(__has_include)
#  define ICE_HAS_INCLUDE(x) __has_include(x)
#else
#  define ICE_HAS_INCLUDE(x) 0
#endif

#if CANVAS_ARCH_AMD64 || CANVAS_ARCH_X86
#define ICE_ASM_BREAKSTR "int {$}3" :
#elif CANVAS_ARCH_ARM
#define ICE_ASM_BREAKSTR "udf #0xfe"
#elif CANVAS_ARCH_ARM64
#define ICE_ASM_BREAKSTR "brk #0xf000"
#else
#define ICE_ASM_BREAKSTR "unimplemented"
#endif

#ifdef CANVAS_DEBUG
#if CANVAS_COMPILER_GNU
#define CE_UNREACHABLE() (__extension__ ({ \
  __asm__ __volatile__(ICE_ASM_BREAKSTR); \
  abort(); \
}))
#elif CANVAS_COMPILER_MSVC
#define CE_UNREACHABLE() (__debugbreak(), __fastfail(1), __assume(0))
#else
#define CE_UNREACHABLE() (abort())
#endif
#elif ICE_HAS_GNU_BUILTIN(__builtin_unreachable)
#define CE_UNREACHABLE() __builtin_unreachable()
#elif CANVAS_COMPILER_MSVC
#define CE_UNREACHABLE() __assume(0)
#else
#define CE_UNREACHABLE() abort()
#endif

#if ICE_HAS_GNU_ATTRIB(__cdecl__)
#  define CE_CDECL __attribute__((__cdecl__))
#elif CANVAS_COMPILER_MSVC
#  define CE_CDECL __cdecl
#else
#  define CE_CDECL
#endif

#if ICE_HAS_GNU_ATTRIB(__stdcall__)
#  define CE_STDCALL __attribute__((__stdcall__))
#elif CANVAS_COMPILER_MSVC
#  define CE_STDCALL __stdcall
#else
#  define CE_STDCALL
#endif

#if ICE_HAS_GNU_ATTRIB(__fastcall__)
#  define CE_FASTCALL __attribute__((__fastcall__))
#elif CANVAS_COMPILER_MSVC
#  define CE_FASTCALL __fastcall
#else
#  define CE_FASTCALL
#endif

#if ICE_HAS_GNU_ATTRIB(__thiscall__)
#  define CE_THISCALL __attribute__((__thiscall__))
#elif CANVAS_COMPILER_MSVC
#  define CE_THISCALL __thiscall
#else
#  define CE_THISCALL
#endif

#if ICE_HAS_GNU_ATTRIB(__vectorcall__)
#  define CE_VECCALL __attribute__((__vectorcall__))
#elif CANVAS_COMPILER_MSVC
#  define CE_VECCALL __vectorcall
#else
#  define CE_VECCALL ICE_FASTCALL
#endif

#if CANVAS_COMPILER_MSVC
#  define CE_ATTR_DLLEXPORT __declspec(dllexport)
#  define CE_ATTR_DLLIMPORT __declspec(dllimport)
#elif ICE_HAS_GNU_ATTRIB(visibility)
#  define CE_ATTR_DLLEXPORT __attribute__((visibility("default")))
#  define CE_ATTR_DLLIMPORT __attribute__((visibility("default")))
#else
#  define CE_ATTR_DLLEXPORT
#  define CE_ATTR_DLLIMPORT
#endif

#if CE_C11_STD
#define CE_ATTR_NORET _Noreturn
#elif ICE_HAS_GNU_ATTRIB(noreturn)
#define CE_ATTR_NORET __attribute__((noreturn))
#elif CANVAS_COMPILER_MSVC
#define CE_ATTR_NORET __declspec(noreturn)
#else
#define CE_ATTR_NORET
#endif

#if CE_CXX11_STD
#define ICE_NOEXCEPT nothrow
#elif CE_CXX98_STD
#define ICE_NOEXCEPT throw()
#else
#define ICE_NOEXCEPT
#endif

#ifdef CANVAS_SHARED
#  ifdef ICE_BUILD
#    define CE_API CE_ATTR_DLLEXPORT
#  else
#    define CE_API CE_ATTR_DLLIMPORT
#  endif
#else
#  define CE_API
#endif

#define ICE_NAMESPACE_BEGIN \
  CE_EXTERNC_BEGIN \
  CE_WARN_PUSH \
  CE_WARN_DISABLE_GNU("-Wunused-function") \
  CE_WARN_DISABLE_MSVC(4820)

#define ICE_NAMESPACE_END \
  CE_WARN_POP \
  CE_EXTERNC_END
