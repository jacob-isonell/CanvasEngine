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

#undef ce_il8
#undef ce_il16
#undef ce_il32
#undef ce_il64
#undef ce_ul8
#undef ce_ul16
#undef ce_ul32
#undef ce_ul64
#undef CE_IL8_MAX
#undef CE_IL16_MAX
#undef CE_IL32_MAX
#undef CE_IL64_MAX
#undef CE_IL8_MIN
#undef CE_IL16_MIN
#undef CE_IL32_MIN
#undef CE_IL64_MIN
#undef CE_UL8_MAX
#undef CE_UL16_MAX
#undef CE_UL32_MAX
#undef CE_UL64_MAX
#undef ce_i8
#undef ce_i16
#undef ce_i32
#undef ce_i64
#undef ce_u8
#undef ce_u16
#undef ce_u32
#undef ce_u64
#undef CE_I8_MAX
#undef CE_I16_MAX
#undef CE_I32_MAX
#undef CE_I64_MAX
#undef CE_I8_MIN
#undef CE_I16_MIN
#undef CE_I32_MIN
#undef CE_I64_MIN
#undef CE_U8_MAX
#undef CE_U16_MAX
#undef CE_U32_MAX
#undef CE_U64_MAX
#undef CE_VERSION

#if CE_C99_STD
#	define ce_il8 int_least8_t
#	define ce_il16 int_least16_t
#	define ce_il32 int_least32_t
#	define ce_il64 int_least64_t
#	define ce_ul8 uint_least8_t
#	define ce_ul16 uint_least16_t
#	define ce_ul32 uint_least32_t
#	define ce_ul64 uint_least64_t
#	define CE_IL8_MAX INT_LEAST8_MAX
#	define CE_IL16_MAX INT_LEAST16_MAX
#	define CE_IL32_MAX INT_LEAST32_MAX
#	define CE_IL64_MAX INT_LEAST64_MAX
#	define CE_IL8_MIN INT_LEAST8_MIN
#	define CE_IL16_MIN INT_LEAST16_MIN
#	define CE_IL32_MIN INT_LEAST32_MIN
#	define CE_IL64_MIN INT_LEAST64_MIN
#	define CE_UL8_MAX UINT_LEAST8_MAX
#	define CE_UL16_MAX UINT_LEAST16_MAX
#	define CE_UL32_MAX UINT_LEAST32_MAX
#	define CE_UL64_MAX UINT_LEAST64_MAX
#	ifdef INT8_C
#		define ce_i8 int8_t
#		define CE_I8_MAX INT8_MAX
#		define CE_I8_MIN INT8_MIN
#	endif
#	ifdef UINT8_C
#		define ce_u8 uint8_t
#		define CE_U8_MAX UINT8_MAX
#	endif
#	ifdef INT16_C
#		define ce_i16 int16_t
#		define CE_I16_MAX INT16_MAX
#		define CE_I16_MIN INT16_MIN
#	endif
#	ifdef UINT16_C
#		define ce_u16 uint16_t
#		define CE_U16_MAX UINT16_MAX
#	endif
#	ifdef INT32_C
#		define ce_i32 int32_t
#		define CE_I32_MAX INT32_MAX
#		define CE_I32_MIN INT32_MIN
#	endif
#	ifdef UINT32_C
#		define ce_u32 uint32_t
#		define CE_U32_MAX UINT32_MAX
#	endif
#	ifdef INT64_C
#		define ce_i64 int64_t
#		define CE_I64_MAX INT64_MAX
#		define CE_I64_MIN INT64_MIN
#	endif
#	ifdef UINT64_C
#		define ce_u64 uint64_t
#		define CE_U64_MAX UINT64_MAX
#	endif
#	ifdef INTPTR_C
#		define ce_iptr intptr_t
#		define CE_IPTR_MAX INTPTR_MAX
#		define CE_IPTR_MIN INTPTR_MIN
#	endif
#	ifdef UINTPTR_C
#		define ce_uptr uintptr_t
#		define CE_UPTR_MAX UINTPTR_MAX
#		define CE_UPTR_MIN UINTPTR_MIN
#	endif
#elif CANVAS_COMPILER_MSVC
#	define ce_i8 signed __int8
#	define ce_i16 signed __int16
#	define ce_i32 signed __int32
#	define ce_i64 signed __int64
#	define ce_u8 unsigned __int8
#	define ce_u16 unsigned __int16
#	define ce_u32 unsigned __int32
#	define ce_u64 unsigned __int64
#	define CE_I8_MAX 127
#	define CE_I16_MAX 32767
#	define CE_I32_MAX 2147483647
#	define CE_I64_MAX 9223372036854775807LL
#	define CE_I8_MIN (-128)
#	define CE_I16_MIN (-32768)
#	define CE_I32_MIN (-2147483648)
#	define CE_I64_MIN (-9223372036854775808LL)
#	define CE_U8_MAX 255U
#	define CE_U16_MAX 65535U
#	define CE_U32_MAX 4294967295U
#	define CE_U64_MAX 18446744073709551615ULL
#	define ce_il8 ce_i8
#	define ce_il16 ce_i16
#	define ce_il32 ce_i32
#	define ce_il64 ce_i64
#	define ce_ul8 ce_u8
#	define ce_ul16 ce_u16
#	define ce_ul32 ce_u32
#	define ce_ul64 ce_u64
#	define CE_IL8_MAX CE_I8_MAX
#	define CE_IL16_MAX CE_I16_MAX
#	define CE_IL32_MAX CE_I32_MAX
#	define CE_IL64_MAX CE_I64_MAX
#	define CE_IL8_MIN CE_I8_MIN
#	define CE_IL16_MIN CE_I16_MIN
#	define CE_IL32_MIN CE_I32_MIN
#	define CE_IL64_MIN CE_I64_MIN
#	define CE_UL8_MAX CE_U8_MAX
#	define CE_UL16_MAX CE_U16_MAX
#	define CE_UL32_MAX CE_U32_MAX
#	define CE_UL64_MAX CE_U64_MAX
#else
#	define ce_il8 signed char
#	define ce_ul8 unsigned char
#	define ce_il16 signed short int
#	define ce_ul16 unsigned short int
#	define ce_il64 signed long long int
#	define ce_ul64 unsigned long long int
#	define CE_IL8_MAX SCHAR_MAX
#	define CE_IL8_MIN SCHAR_MIN
#	define CE_UL8_MAX UCHAR_MAX
#	define CE_IL16_MAX SHRT_MAX
#	define CE_IL16_MIN SHRT_MIN
#	define CE_UL16_MAX USHRT_MAX
#	define CE_IL64_MAX LLONG_MAX
#	define CE_IL64_MIN LLONG_MIN
#	define CE_UL64_MAX ULLONG_MAX
#	if LONG_MAX == INT_MAX
#		define ce_il32 signed int
#		define ce_ul32 unsigned int
#		define CE_IL32_MAX INT_MAX
#		define CE_IL32_MIN INT_MIN
#		define CE_UL32_MAX UINT_MAX
#	else
#		define ce_il32 signed long int
#		define ce_ul32 unsigned long int
#		define CE_IL32_MAX LONG_MAX
#		define CE_IL32_MIN LONG_MIN
#		define CE_UL32_MAX ULONG_MAX
#	endif
#	if CE_UL8_MAX == 0xFFU
#		define ce_i8 ce_il8
#		define ce_u8 ce_ul8
#		define CE_I8_MAX 0x7F
#		define CE_I8_MIN -0x80
#		define CE_U8_MAX 0xFFU
#	endif
#	if CE_UL16_MAX == 0xFFFFU
#		define ce_i16 ce_il16
#		define ce_u16 ce_ul16
#		define CE_I16_MAX 0x7FFF
#		define CE_I16_MIN -0x8000
#		define CE_U16_MAX 0xFFFFU
#	endif
#	if CE_UL32_MAX == 0xFFFFFFFFU
#		define ce_i32 ce_il32
#		define ce_u32 ce_ul32
#		define CE_I32_MAX 0x7FFFFFFF
#		define CE_I32_MIN (-0x80000000)
#		define CE_U32_MAX 0xFFFFFFFFU
#	endif
#	if CE_UL64_MAX == 0xFFFFFFFFFFFFFFFFULL
#		define ce_i64 ce_il64
#		define ce_u64 ce_ul64
#		define CE_I64_MAX 0x7FFFFFFFFFFFFFFFLL
#		define CE_I64_MIN (-0x8000000000000000LL)
#		define CE_U64_MAX 0xFFFFFFFFFFFFFFFFULL
#	endif
#endif

#define CE_VERSION(major, minor, patch) \
	(((unsigned int)(major) << 26) & 64 \
	| (((unsigned int)(major) << 14) & 1024) \
	| ((unsigned int)(major) & 4096))
