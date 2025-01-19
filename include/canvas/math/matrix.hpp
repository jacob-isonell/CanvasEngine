/**
 * @file matrix.hpp
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

#include <canvas/math/vector.hpp>

ICANVAS_NAMESPACE_MATH_BEGIN

template<typename FloatingType, std::size_t Rows, std::size_t Columns>
struct matrix;

ICANVAS_NAMESPACE_INTERNAL_BEGIN

template<typename T>
struct is_matrix_type : std::false_type {
};

template<typename FloatingType, std::size_t Rows, std::size_t Columns>
struct is_matrix_type<matrix<FloatingType, Rows, Columns>> : std::true_type {
};

template<typename T>
constexpr bool is_matrix_type_v = is_matrix_type<T>::value;

template<typename T>
concept matrix_type = is_matrix_type_v<T>;

template<typename T>
struct matrix_traits {
};

template<typename FloatingType, std::size_t Rows, std::size_t Columns>
struct matrix_traits<matrix<FloatingType, Rows, Columns>> {
	using type = FloatingType;
	static constexpr std::size_t rows = Rows;
	static constexpr std::size_t columns = Columns;
};

template<matrix_type Mat>
constexpr auto matrix_row_range = std::views::iota((std::size_t)0, matrix_traits<Mat>::rows);

template<matrix_type Mat>
constexpr auto matrix_column_range = std::views::iota((std::size_t)0, matrix_traits<Mat>::columns);

template<matrix_type Mat, typename Func>
constexpr Mat matrix_transform(const Mat& mat, Func&& func) {
	Mat out { };
	for (std::size_t row : internal::matrix_row_range<Mat>) {
		out[row] = vector_transform(mat[row], std::forward<Func>(func));
	}
	return out;
}

template<matrix_type Mat, typename Func>
constexpr Mat matrix_operate(const Mat& lhs, const Mat& rhs, Func&& func) {
	Mat out { };
	for (std::size_t row : internal::matrix_row_range<Mat>) {
		out[row] = vector_operate(lhs[row], rhs[row], std::forward<Func>(func));
	}
	return out;
}

ICANVAS_NAMESPACE_INTERNAL_END

template<internal::matrix_type Mat>
constexpr Mat operator+(const Mat& lhs, const Mat& rhs) {
	return internal::matrix_operate(lhs, rhs, std::plus{});
}

template<internal::matrix_type Mat>
constexpr Mat operator-(const Mat& lhs, const Mat& rhs) {
	return internal::matrix_operate(lhs, rhs, std::minus{});
}

template<internal::matrix_type Mat>
constexpr Mat operator*(const Mat& lhs, const typename internal::matrix_traits<Mat>::type& rhs) {
	return internal::matrix_transform(lhs, [&](const auto& l) {
		return l * rhs;
	});
}

template<internal::matrix_type Mat>
constexpr Mat operator/(const Mat& lhs, const typename internal::matrix_traits<Mat>::type& rhs) {
	return internal::matrix_transform(lhs, [&](const auto& l) {
		return l / rhs;
	});
}

template<typename FloatingType, std::size_t Rows, std::size_t Columns>
struct matrix {
	vector<FloatingType, Rows> axies[Columns];
	
	constexpr matrix& operator+=(const matrix& other) { return *this = *this + other; }
	constexpr matrix& operator-=(const matrix& other) { return *this = *this - other; }
	constexpr matrix& operator*=(const FloatingType& other) { return *this = *this * other; }
	constexpr matrix& operator/=(const FloatingType& other) { return *this = *this / other; }
	
	constexpr auto& operator[](std::size_t n) {
		if (Columns <= n) {
			internal::dothrow_debug<std::out_of_range>("out_of_range");
		}
		return axies[n];
	}
	
	constexpr const auto& operator[](std::size_t n) const {
		if (Columns <= n) {
			internal::dothrow_debug<std::out_of_range>("out_of_range");
		}
		return axies[n];
	}
};

using mat2x2f32_t = matrix<float, 2, 2>;
using mat2x3f32_t = matrix<float, 2, 3>;
using mat2x4f32_t = matrix<float, 2, 4>;
using mat3x2f32_t = matrix<float, 3, 2>;
using mat3x3f32_t = matrix<float, 3, 3>;
using mat3x4f32_t = matrix<float, 3, 4>;
using mat4x2f32_t = matrix<float, 4, 2>;
using mat4x3f32_t = matrix<float, 4, 3>;
using mat4x4f32_t = matrix<float, 4, 4>;
using mat2x2f64_t = matrix<double, 2, 2>;
using mat2x3f64_t = matrix<double, 2, 3>;
using mat2x4f64_t = matrix<double, 2, 4>;
using mat3x2f64_t = matrix<double, 3, 2>;
using mat3x3f64_t = matrix<double, 3, 3>;
using mat3x4f64_t = matrix<double, 3, 4>;
using mat4x2f64_t = matrix<double, 4, 2>;
using mat4x3f64_t = matrix<double, 4, 3>;
using mat4x4f64_t = matrix<double, 4, 4>;

ICANVAS_NAMESPACE_MATH_END
