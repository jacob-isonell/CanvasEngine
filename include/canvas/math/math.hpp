/**
 * @file vector.hpp
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
#include <cmath>
#include <numeric>
#include <numbers>

ICANVAS_NAMESPACE_MATH_BEGIN

namespace numbers {

using namespace std::numbers;

template<traits::floating_point T>
inline constexpr T tau_v = 6.283185307179586476925286766559005768;

inline constexpr double tau = tau_v<double>;

} // namespace numbers

using std::abs;
using std::fmod;
using std::min;
using std::max;
using std::lerp;
using std::exp;
using std::pow;
using std::sqrt;
using std::cbrt;
using std::hypot;
using std::sin;
using std::cos;
using std::tan;
using std::asin;
using std::acos;
using std::atan;
using std::atan2;
using std::ceil;
using std::floor;
using std::trunc;
using std::round;

constexpr auto ln = [](auto f) { return std::log(f); };
constexpr auto log = [](auto f) { return std::log10(f); };

ICANVAS_NAMESPACE_MATH_END
