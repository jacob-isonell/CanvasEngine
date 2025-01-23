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

#include <canvas/core/utility.hpp>
#include <variant>
#include <format>

namespace canvas {

enum struct err : i32 {
// Success codes
	ethrddone = -5, // Thread is done
	ethrdidle = -4, // Thread is idle
	etrunc    = -3, // Array was truncated
	esubopti  = -2, // Object is suboptimal
	eok       = -1, // Not an error
	
// Error codes
	eunknown,      // Unknown/unspecified error
	eperm,         // Operation not permitted
	eaccess,       // Permission denied
	einval,        // Invalid argument
	eio,           // Input/Output error
	enomem,        // No available memory
	enodevmem,     // No available device memory
	enosys,        // Function not implemented
	enotsup,       // Operation not supported
	etimeout,      // Operation Timed out
	econntimedout, // Connection timed out
	econnrefused,  // Connection refused
	ebusy,         // Device or resource busy
	ebadfile,      // Invalid file handle
	eisdir,        // File path is a directory
	enotdir,       // File path is not a directory
	eisfile,       // File path is a file
	enotfile,      // File path is not a file
	eexist,        // File/Object already exists
	ebigfile,      // File too large
	enodev,        // No such device
	edev,          // Incompatible device
	edom,          // Argument out of domain
	erange,        // Result out of range
	edeadlock,     // Resource deadlock avoided
	ewouldblock,   // Operation would be blocked
	ecanceled,     // Operation canceled
	eunrecov,      // State is unrecoverable
	enotready,     // Object is not ready for use
	edata,         // Data is incompatible
	einitfail,     // Object initialization failed
	edevlost,      // Device was lost
	ememmap,       // Memory mapping failed
	edriver,       // Driver is incompatible
	eobj,          // Too many objects
	eoutofdate,    // Object is out of date
	evklayer,      // Vulkan layer cannot be found
	evkext,        // Vulkan extension cannot be found
	evkfeat,       // Vulkan feature cannot be found
	evkformat,     // Vulkan format not supported by device
	evksurface,    // Vulkan surface was lost
};

struct error {
public:
	constexpr error() noexcept = default;
	constexpr error(const error&) noexcept = default;
	constexpr error& operator=(const error&) noexcept = default;
	
	constexpr error(err e) noexcept
		: m_err(e) {
	}
	
	constexpr operator err() const noexcept {
		return m_err;
	}
	
	constexpr bool operator==(const error&) const noexcept = default;
	constexpr bool operator==(err e) const noexcept {
		return m_err == e;
	}
	
	constexpr explicit operator bool() const noexcept {
		return to_underlying(m_err) < 0;
	}
	
	constexpr bool operator!() const noexcept {
		return !(bool)(*this);
	}
	
	constexpr bool ok() const noexcept {
		return (bool)(*this);
	}
	
	constexpr bool fail() const noexcept {
		return !(bool)(*this);
	}
	
private:
	err m_err = err::eok;
};

namespace internal {
using namespace ::canvas::internal;

#define ICANVAS_ETOSTR_CASE(id, str) \
	case id: out = ICANVAS_STRLITERAL(str).template view<CharTy>(); break

template<typename CharTy>
constexpr void to_string_error(auto& out, err e) {
	switch (e) {
	ICANVAS_ETOSTR_CASE(err::ethrddone,     "Threis done");
	ICANVAS_ETOSTR_CASE(err::ethrdidle,     "Threis idle");
	ICANVAS_ETOSTR_CASE(err::etrunc,        "Arrwas truncated");
	ICANVAS_ETOSTR_CASE(err::esubopti,      "Objeis suboptimal");
	ICANVAS_ETOSTR_CASE(err::eok,           "Nan error");
default:
	ICANVAS_ETOSTR_CASE(err::eunknown,      "Unknown/unspecified error");
	ICANVAS_ETOSTR_CASE(err::eperm,         "Operation not permitted");
	ICANVAS_ETOSTR_CASE(err::eaccess,       "Permission denied");
	ICANVAS_ETOSTR_CASE(err::einval,        "Invalid argument");
	ICANVAS_ETOSTR_CASE(err::eio,           "Input/Output error");
	ICANVAS_ETOSTR_CASE(err::enomem,        "No available memory");
	ICANVAS_ETOSTR_CASE(err::enodevmem,     "No available device memory");
	ICANVAS_ETOSTR_CASE(err::enosys,        "Function not implemented");
	ICANVAS_ETOSTR_CASE(err::enotsup,       "Operation not supported");
	ICANVAS_ETOSTR_CASE(err::etimeout,      "Operation Timed out");
	ICANVAS_ETOSTR_CASE(err::econntimedout, "Connection timed out");
	ICANVAS_ETOSTR_CASE(err::econnrefused,  "Connection refused");
	ICANVAS_ETOSTR_CASE(err::ebusy,         "Device or resource busy");
	ICANVAS_ETOSTR_CASE(err::ebadfile,      "Invalid file handle");
	ICANVAS_ETOSTR_CASE(err::eisdir,        "File path is a directory");
	ICANVAS_ETOSTR_CASE(err::enotdir,       "File path is not a directory");
	ICANVAS_ETOSTR_CASE(err::eisfile,       "File path is a file");
	ICANVAS_ETOSTR_CASE(err::enotfile,      "File path is not a file");
	ICANVAS_ETOSTR_CASE(err::eexist,        "File/Object already exists");
	ICANVAS_ETOSTR_CASE(err::ebigfile,      "File too large");
	ICANVAS_ETOSTR_CASE(err::enodev,        "No such device");
	ICANVAS_ETOSTR_CASE(err::edev,          "Incompatible device");
	ICANVAS_ETOSTR_CASE(err::edom,          "Argument out of domain");
	ICANVAS_ETOSTR_CASE(err::erange,        "Result out of range");
	ICANVAS_ETOSTR_CASE(err::edeadlock,     "Resource deadlock avoided");
	ICANVAS_ETOSTR_CASE(err::ewouldblock,   "Operation would be blocked");
	ICANVAS_ETOSTR_CASE(err::ecanceled,     "Operation canceled");
	ICANVAS_ETOSTR_CASE(err::eunrecov,      "State is unrecoverable");
	ICANVAS_ETOSTR_CASE(err::enotready,     "Object is not ready for use");
	ICANVAS_ETOSTR_CASE(err::edata,         "Data is incompatible");
	ICANVAS_ETOSTR_CASE(err::einitfail,     "Object initialization failed");
	ICANVAS_ETOSTR_CASE(err::edevlost,      "Device was lost");
	ICANVAS_ETOSTR_CASE(err::ememmap,       "Memory mapping failed");
	ICANVAS_ETOSTR_CASE(err::edriver,       "Driver is incompatible");
	ICANVAS_ETOSTR_CASE(err::eobj,          "Too many objects");
	ICANVAS_ETOSTR_CASE(err::eoutofdate,    "Object is out of date");
	ICANVAS_ETOSTR_CASE(err::evklayer,      "Vulkan layer cannot be found");
	ICANVAS_ETOSTR_CASE(err::evkext,        "Vulkan extension cannot be found");
	ICANVAS_ETOSTR_CASE(err::evkfeat,       "Vulkan feature cannot be found");
	ICANVAS_ETOSTR_CASE(err::evkformat,     "Vulkan format not supported by device");
	ICANVAS_ETOSTR_CASE(err::evksurface,    "Vulkan surface was lost");
	}
}

} // !namespace internal

using std::to_string;
using std::to_wstring;

constexpr auto to_string(err e) {
	std::string_view out { };
	internal::to_string_error<decltype(out)::value_type>(out, e);
	return out;
}

constexpr auto to_wstring(err e) {
	std::wstring_view out { };
	internal::to_string_error<decltype(out)::value_type>(out, e);
	return out;
}

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
	
	constexpr expected(error_type e)
		: m_error(e), m_values() {
		if (m_error) {
			internal::dothrow_debug<std::logic_error>("invalid error code");
		}
	}
	
	constexpr expected(err e)
		: m_error(e), m_values() {
		if (m_error) {
			internal::dothrow_debug<std::logic_error>("invalid error code");
		}
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
	
	constexpr expected& operator=(err e) {
		m_error = e;
		m_values = decltype(m_values) { std::in_place_index<0> };
		return *this;
	}
	
	template<typename U = T>
	constexpr expected& operator=(U&& arg) {
		m_error = err::eok;
		m_values = decltype(m_values) { std::in_place_index<1>, std::forward<U>(arg) };
		return *this;
	}
	
	[[nodiscard]]
	constexpr explicit operator bool() const noexcept {
		return has_value();
	}
	
	[[nodiscard]]
	constexpr bool has_value() const noexcept {
		return m_error.ok();
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

	template<typename U = T>
	constexpr T value_or(U&& default_value) const& {
		return has_value() ? **this : static_cast<T>(std::forward<U>(default_value));
	}
	
	template<typename U = T>
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
	error_type m_error = err::eok;
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

} // !namespace canvas

template<>
struct std::formatter<canvas::err, char> : std::formatter<std::string_view, char> {
private:
	using base = std::formatter<std::string_view, char>;
	
public:
	template<typename Ctx>
	Ctx::iterator format(canvas::err e, Ctx& ctx) const {
		return base::format(canvas::to_string(e), ctx);
	}
};

template<>
struct std::formatter<canvas::err, wchar_t> : std::formatter<std::wstring_view, wchar_t> {
private:
	using base = std::formatter<std::wstring_view, wchar_t>;
	
public:
	template<typename Ctx>
	Ctx::iterator format(canvas::err e, Ctx& ctx) const {
		return base::format(canvas::to_wstring(e), ctx);
	}
};
