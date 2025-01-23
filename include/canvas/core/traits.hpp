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
#include <type_traits>
#include <concepts>
#include <compare>
#include <utility>

namespace canvas {

template<typename T>
using underlying_type = std::underlying_type_t<T>;

template<typename T>
[[nodiscard]]
constexpr underlying_type<T> to_underlying(T val) noexcept {
	return static_cast<underlying_type<T>>(val);
}

namespace traits {

using std::same_as;
using std::derived_from;
using std::convertible_to;
using std::common_reference_with;
using std::common_with;
using std::integral;
using std::signed_integral;
using std::unsigned_integral;
using std::floating_point;
using std::assignable_from;
using std::swappable;
using std::swappable_with;
using std::destructible;
using std::constructible_from;
using std::default_initializable;
using std::move_constructible;
using std::copy_constructible;
using std::equality_comparable;
using std::equality_comparable_with;
using std::totally_ordered;
using std::totally_ordered_with;
using std::three_way_comparable;
using std::three_way_comparable_with;
using std::movable;
using std::copyable;
using std::semiregular;
using std::regular;
using std::invocable;
using std::regular_invocable;
using std::predicate;
using std::relation;
using std::equivalence_relation;
using std::strict_weak_order;

namespace internal {
using namespace ::canvas::internal;

template<typename B>
concept boolean_testable_impl = std::convertible_to<B, bool>;

} // !namespace internal

template<typename B>
concept boolean_testable =
	internal::boolean_testable_impl<B> &&
	requires (B&& b) {
		{ !std::forward<B>(b) } -> internal::boolean_testable_impl;
	};

template<typename T>
concept arithmetic = std::is_arithmetic_v<T> || std::is_floating_point_v<T>
	|| requires(T a, T b) {
		!std::is_pointer_v<T>;
		!std::is_reference_v<T>;
		(+a) -> T;
		(-a) -> T;
		(~a) -> T;
		(a + b) -> T;
		(a - b) -> T;
		(a * b) -> T;
		(a / b) -> T;
		(a % b) -> T;
		(a & b) -> T;
		(a ^ b) -> T;
		(a | b) -> T;
		(a << b) -> T;
		(a >> b) -> T;
	};

} // !namespace traits

} // !namespace canvas
