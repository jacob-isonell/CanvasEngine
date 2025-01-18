/**
 * @file error.hpp
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

#include <canvas/core/traits.hpp>
#include <initializer_list>
#include <utility>
#include <variant>
#include <format>

ICANVAS_NAMESPACE_BEGIN

enum class error : i32 {
	eok      = 0,
	eunknown = -1,
	enomem   = -2,
	enoimpl  = -3
};

template<typename T>
class expected {
public:
	using value_type = T;
	using error_type = ::canvas::error;
	
	constexpr expected() = default;
	constexpr expected(expected&&) = default;
	constexpr expected(const expected&) = default;
	constexpr expected& operator=(expected&&) = default;
	constexpr expected& operator=(const expected&) = default;
	
	constexpr expected(error_type e) noexcept
		: m_error(e), m_values() {
	}
	
	template<typename U = T>
	constexpr explicit(!std::is_convertible_v<U, T>) expected(U&& value)
		: m_values(std::forward<U>(value)) {
	}
	
	template<typename ... Args>
	constexpr explicit expected(std::in_place_t, Args&&... args)
		: m_values(std::in_place_index<1>, std::forward<Args>(args)...){
	}
	
	template<typename U, typename ... Args>
	constexpr explicit expected(std::in_place_t, std::initializer_list<U> ilist, Args&&... args)
		: m_values(std::in_place_index<1>, ilist, std::forward<Args>(args)...){
	}
	
	constexpr expected& operator=(error_type e) {
		m_error = e;
		m_values = decltype(m_values) { std::in_place_index<0> };
		return *this;
	}
	
	template<typename U = T>
	constexpr expected& operator=(U&& arg) {
		m_error = error_type::eok;
		m_values = decltype(m_values) { std::in_place_index<1>, std::forward<U>(arg) };
		return *this;
	}
	
	[[nodiscard]]
	constexpr explicit operator bool() const noexcept {
		return has_value();
	}
	
	[[nodiscard]]
	constexpr bool has_value() const noexcept {
		return 0 <= to_underlying(m_error);
	}
	
	constexpr const T* operator->() const noexcept {
		return std::get_if<1>(&m_values);
	}
	
	constexpr T* operator->() noexcept {
		return std::get_if<1>(&m_values);
	}
	
	constexpr const T& operator*() const& noexcept {
		return *(this->operator->());
	}
	
	constexpr T& operator*() & noexcept {
		return *(this->operator->());
	}
	
	constexpr const T&& operator*() const&& noexcept {
		return std::move(*(this->operator->()));
	}
	
	constexpr T&& operator*() && noexcept {
		return std::move(*(this->operator->()));
	}
	
	constexpr T& value() & {
		return **this;
	}
	
	constexpr const T& value() const& {
		return **this;
	}
	
	constexpr T&& value() && {
		return std::move(**this);
	}
	
	constexpr const T&& value() const&& {
		return std::move(**this);
	}

	template< class U >
	constexpr T value_or(U&& default_value) const& {
		return has_value() ? **this : static_cast<T>(std::forward<U>(default_value));
	}
	
	template< class U >
	constexpr T value_or(U&& default_value) && {
		return has_value() ? std::move(**this) : static_cast<T>(std::forward<U>(default_value));
	}
	
	constexpr error_type error() const noexcept {
		return m_error;
	}
	
	void swap(expected& other) noexcept(std::is_nothrow_swappable_v<decltype(m_values)>) {
		std::swap(m_error, other.m_error);
		std::swap(m_values, other.m_values);
	}
	
private:
	error_type m_error = error_type::eok;
	std::variant<std::monostate, T> m_values;
};

template<typename T, typename U>
constexpr bool operator==(const expected<T>& lhs, const expected<U>& rhs) {
	if (lhs.has_value() == rhs.has_value()) {
		return false;
	}
	
	if (lhs.has_value()) {
		return lhs.value() == rhs.value();
	}
	
	return lhs.error() == rhs.error();
}

ICANVAS_NAMESPACE_END

template<>
struct std::formatter<canvas::error, char> : std::formatter<std::string_view, char> {
private:
	using base = std::formatter<std::string_view, char>;
	
public:
	template<typename Ctx>
	Ctx::iterator format(canvas::error e, Ctx& ctx) const {
		return base::format(s_to_string(e), ctx);
	}
	
private:
	static constexpr std::string_view s_to_string(canvas::error e) noexcept {
		switch (e) {
		default:
		case canvas::error::eunknown: return "eunknown";
		case canvas::error::eok:      return "eok";
		}
	}
};

template<>
struct std::formatter<canvas::error, wchar_t> : std::formatter<std::wstring_view, wchar_t> {
private:
	using base = std::formatter<std::wstring_view, wchar_t>;
	
public:
	template<typename Ctx>
	Ctx::iterator format(canvas::error e, Ctx& ctx) const {
		return base::format(s_to_string(e), ctx);
	}
	
private:
	static constexpr std::wstring_view s_to_string(canvas::error e) noexcept {
		switch (e) {
		default:
		case canvas::error::eunknown: return L"eunknown";
		case canvas::error::eok:      return L"eok";
		}
	}
};
