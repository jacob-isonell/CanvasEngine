/**
 * @file traits.hpp
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

#include <canvas/core/macros.hpp>
#include <format>
#include <array>
#include <tuple>

ICANVAS_NAMESPACE_BEGIN

ICANVAS_NAMESPACE_INTERNAL_BEGIN

template<typename T, typename ... Args>
struct get_front_varg {
	using type = T;
};

template<sz I, typename ... Args>
struct get_nth_varg {
};

template<sz I, typename T, typename ... Args>
struct get_nth_varg<I, T, Args...> {
	using type = typename get_nth_varg<I - 1, Args...>::type;
};

template<typename ... Args>
struct get_nth_varg<0, Args...> {
	using type = typename get_front_varg<Args...>::type;
};

template<typename ... Args>
using get_front_varg_t = typename get_front_varg<Args...>::type;

template<sz I, typename ... Args>
using get_nth_varg_t = typename get_nth_varg<I, Args...>::type;

template<typename A, typename B>
struct default_type_match_comparitor : std::bool_constant<std::same_as<A, typename B::type>> {
};

template<
	template<typename, typename> typename Comparitor,
	bool Match,
	typename Type,
	typename ... Patterns
>
struct type_match_impl { };

template<
	template<typename, typename> typename Comparitor,
	typename Type,
	typename FirstPattern,
	typename ... Patterns
>
struct type_match_impl<Comparitor, true, Type, FirstPattern, Patterns...> {
	using type = FirstPattern;
};

template<
	template<typename, typename> typename Comparitor,
	typename Type,
	typename FirstPattern,
	typename ... Patterns
>
struct type_match_impl<Comparitor, false, Type, FirstPattern, Patterns...> {
	using type = typename type_match_impl<
		Comparitor,
		Comparitor<Type, typename get_front_varg<Patterns...>::type>::value,
		Type,
		Patterns...
	>::type;
};

template<
	template<typename, typename> typename Comparitor,
	typename Type,
	typename ... Patterns
>
struct type_match {
	using type = typename type_match_impl<
		Comparitor,
		Comparitor<Type, typename get_front_varg<Patterns...>::type>::value,
		Type,
		Patterns...
	>::type;
};

template<
	template<typename, typename> typename Comparitor,
	typename Type,
	typename ... Patterns
>
using type_match_t = typename type_match<Comparitor, Type, Patterns...>::type;

template<typename Type, auto Value>
struct type_value_pair {
	using type = Type;
	static constexpr auto value = Value;
};

template<
	sz Len,
	sz WLen,
	sz U8Len,
	sz U16Len,
	sz U32Len
>
struct strliteral {
private:
	using self_type = strliteral;
	
	const char (*m_narrow)[Len];
	const wchar_t (*m_wide)[WLen];
	const char8_t (*m_u8)[U8Len];
	const char16_t (*m_u16)[U16Len];
	const char32_t (*m_u32)[U32Len];
	
	template<typename CharTy>
	static constexpr sz char_size = type_match_t<
		default_type_match_comparitor,
		CharTy,
		type_value_pair<char, Len>,
		type_value_pair<wchar_t, WLen>,
		type_value_pair<char8_t, U8Len>,
		type_value_pair<char16_t, U16Len>,
		type_value_pair<char32_t, U32Len>
	>::value;
	
	template<typename CharTy>
	using return_type = CharTy[char_size<CharTy>];
	
public:
	strliteral() = delete;
	strliteral(strliteral&&) = delete;
	strliteral(const strliteral&) = delete;
	strliteral& operator=(strliteral&&) = delete;
	strliteral& operator=(const strliteral&) = delete;
	
	consteval strliteral(
		const char (&narrow)[Len],
		const wchar_t (&wide)[WLen],
		const char8_t (&u8)[U8Len],
		const char16_t (&u16)[U16Len],
		const char32_t (&u32)[U32Len]
	) :
		m_narrow(&narrow),
		m_wide(&wide),
		m_u8(&u8),
		m_u16(&u16),
		m_u32(&u32)
	 {
	}
	
	template<typename CharTy>
	consteval const auto& get() const noexcept {
		return *(this->*type_match_t<
			default_type_match_comparitor,
			CharTy,
			type_value_pair<char, (&strliteral::m_narrow)>,
			type_value_pair<wchar_t, (&strliteral::m_wide)>,
			type_value_pair<char8_t, (&strliteral::m_u8)>,
			type_value_pair<char16_t, (&strliteral::m_u16)>,
			type_value_pair<char32_t, (&strliteral::m_u32)>
		>::value);
	}
	
	template<typename CharTy>
	static consteval sz size() noexcept {
		return char_size<CharTy>;
	}
	
	template<typename CharTy>
	consteval const auto* cstr() const noexcept {
		return get<CharTy>();
	}
	
	template<typename CharTy>
	consteval std::basic_string_view<CharTy> view() const noexcept {
		return std::basic_string_view<CharTy> { get<CharTy>() };
	}
};

template<
	sz Len,
	sz WLen,
	sz U8Len,
	sz U16Len,
	sz U32Len
>
consteval strliteral<Len, WLen, U8Len, U16Len, U32Len> make_strliteral(
	const char (&narrow)[Len],
	const wchar_t (&wide)[WLen],
	const char8_t (&u8)[U8Len],
	const char16_t (&u16)[U16Len],
	const char32_t (&u32)[U32Len]
) {
	return strliteral<Len, WLen, U8Len, U16Len, U32Len> {
		narrow, wide, u8, u16, u32
	};
}

#define ICANVAS_STRLITERAL(input_str) \
	::canvas::internal::make_strliteral( \
		input_str, \
		L"" input_str, \
		u8"" input_str, \
		u"" input_str, \
		U"" input_str \
	)

template<typename CharTy, typename ... Args>
inline auto make_format_args(Args&... args) {
	static_assert(
		std::same_as<CharTy, char>
		|| std::same_as<CharTy, wchar_t>,
		"Char type argument must be either char or wchar_t"
	);
	
	if constexpr (std::same_as<CharTy, char>) {
		return std::make_format_args(args...);
	}
	if constexpr (std::same_as<CharTy, wchar_t>) {
		return std::make_wformat_args(args...);
	}
}

template<typename CharTy, typename ... Args>
using format_string = std::conditional_t<
	std::same_as<CharTy, wchar_t>,
	std::wformat_string<Args...>,
	std::format_string<Args...>
>;

ICANVAS_NAMESPACE_INTERNAL_END

ICANVAS_NAMESPACE_END
