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

#include <canvas/math/math.hpp>
#include <array>
#include <ranges>
#include <functional>

ICANVAS_NAMESPACE_MATH_BEGIN

template<typename Vec>
constexpr auto dot(const Vec& lhs, const Vec& rhs);

ICANVAS_NAMESPACE_INTERNAL_BEGIN

template<typename T> struct vector_traits { };
template<template<typename, std::size_t> typename T, typename ValueType, std::size_t ElementCount>
struct vector_traits<T<ValueType, ElementCount>> {
	using type = ValueType;
	static constexpr std::size_t count = ElementCount;
};

template<typename Vec>
using vector_traits_type = typename vector_traits<Vec>::type;

template<typename Vec>
constexpr std::size_t vector_traits_count = vector_traits<Vec>::count;

template<typename SelfType>
struct vector_impl;

template<typename T>
concept vector_type = std::derived_from<T, vector_impl<T>>;

template<typename T, std::size_t N>
concept vector_sized = vector_type<T> && vector_traits_count<T> == N;

template<vector_type Vec, typename Func>
constexpr Vec vector_operate(const Vec& lhs, const Vec& rhs, Func&& func) {
	Vec out;
	for (std::size_t i : std::views::iota((std::size_t)0, Vec::element_count)) {
		out[i] = std::invoke(std::forward<Func>(func), lhs[i], rhs[i]);
	}
	return out;
}

template<vector_type Vec, typename Func>
constexpr Vec vector_transform(const Vec& vec, Func&& func) {
	Vec out;
	for (std::size_t i : std::views::iota((std::size_t)0, Vec::element_count)) {
		out[i] = std::invoke(std::forward<Func>(func), vec[i]);
	}
	return out;
}

template<vector_type Vec, typename Func>
constexpr vector_traits_type<Vec> vector_accumulate(const Vec& lhs, const Vec& rhs, const vector_traits_type<Vec>& init, Func&& func) {
	vector_traits_type<Vec> out { init };
	for (std::size_t i : std::views::iota((std::size_t)0, Vec::element_count)) {
		out += std::invoke(std::forward<Func>(func), lhs[i], rhs[i]);
	}
	return out;
}

template<vector_type Vec, typename Func>
constexpr vector_traits_type<Vec> vector_accumulate(const Vec& lhs, const Vec& rhs, Func&& func) {
	vector_traits_type<Vec> out { };
	for (std::size_t i : std::views::iota((std::size_t)0, Vec::element_count)) {
		out += std::invoke(std::forward<Func>(func), lhs[i], rhs[i]);
	}
	return out;
}

template<vector_type Vec, typename Func>
constexpr vector_traits_type<Vec> vector_accumulate(const Vec& vec, const vector_traits_type<Vec>& init, Func&& func) {
	vector_traits_type<Vec> out { init };
	for (std::size_t i : std::views::iota((std::size_t)0, Vec::element_count)) {
		out += std::invoke(std::forward<Func>(func), vec[i]);
	}
	return out;
}

template<vector_type Vec, typename Func>
constexpr vector_traits_type<Vec> vector_accumulate(const Vec& vec, Func&& func) {
	vector_traits_type<Vec> out { };
	for (std::size_t i : std::views::iota((std::size_t)0, Vec::element_count)) {
		out += std::invoke(std::forward<Func>(func), vec[i]);
	}
	return out;
}

template<vector_type Vec>
constexpr Vec operator+(const Vec& lhs, const Vec& rhs) {
	return vector_operate(lhs, rhs, std::plus{});
}

template<vector_type Vec>
constexpr Vec operator-(const Vec& lhs, const Vec& rhs) {
	return vector_operate(lhs, rhs, std::minus{});
}

template<vector_type Vec>
constexpr Vec operator*(const Vec& lhs, const Vec& rhs) {
	return vector_operate(lhs, rhs, std::multiplies{});
}

template<vector_type Vec>
constexpr Vec operator/(const Vec& lhs, const Vec& rhs) {
	return vector_operate(lhs, rhs, std::divides{});
}

template<vector_type Vec>
constexpr Vec operator*(const Vec& lhs, const vector_traits_type<Vec>& rhs) {
	return vector_transform(lhs, [&](const auto& in) {
		return in * rhs;
	});
}

template<vector_type Vec>
constexpr Vec operator*(const vector_traits_type<Vec>& lhs, const Vec& rhs) {
	return vector_transform(rhs, [&](const auto& in) {
		return in * lhs;
	});
}

template<vector_type Vec>
constexpr Vec operator/(const Vec& lhs, const vector_traits_type<Vec>& rhs) {
	return vector_transform(lhs, [&](const auto& in) {
		return in / rhs;
	});
}

template<typename SelfType>
struct vector_impl {
	using value_type = typename vector_traits<SelfType>::type;
	static constexpr std::size_t element_count = vector_traits<SelfType>::count;
	
	constexpr SelfType& operator+=(const SelfType& other) {
		SelfType& self = static_cast<SelfType&>(*this);
		return self = self + other;
	}
	
	constexpr SelfType& operator-=(const SelfType& other) {
		SelfType& self = static_cast<SelfType&>(*this);
		return self = self - other;
	}
	
	constexpr SelfType& operator*=(const SelfType& other) {
		SelfType& self = static_cast<SelfType&>(*this);
		return self = self * other;
	}
	
	constexpr SelfType& operator/=(const SelfType& other) {
		SelfType& self = static_cast<SelfType&>(*this);
		return self = self / other;
	}
	
	constexpr SelfType& operator*=(const value_type& other) {
		SelfType& self = static_cast<SelfType&>(*this);
		return self = self * other;
	}
	
	constexpr SelfType& operator/=(const value_type& other) {
		SelfType& self = static_cast<SelfType&>(*this);
		return self = self / other;
	}
	
	constexpr value_type sqr_magnitude() const {
		const SelfType& self = static_cast<const SelfType&>(*this);
		return dot(self, self);
	}
	
	value_type magnitude() const {
		return std::sqrt(sqr_magnitude());
	}
};

ICANVAS_NAMESPACE_INTERNAL_END

template<typename FloatingType, std::size_t Elements>
struct vector : internal::vector_impl<vector<FloatingType, Elements>> {
private:
	using base = internal::vector_impl<vector<FloatingType, Elements>>;
	
public:
	using value_type = FloatingType;
	
	static constexpr std::size_t element_count = Elements;
	
	FloatingType m_data[Elements];
	
	constexpr FloatingType& operator[](std::size_t n) {
		if (Elements <= n) {
			internal::dothrow_debug<std::out_of_range>("out_of_range");
		}
		return m_data[n];
	}
	
	constexpr const FloatingType& operator[](std::size_t n) const {
		if (Elements <= n) {
			internal::dothrow_debug<std::out_of_range>("out_of_range");
		}
		return m_data[n];
	}
};

template<typename FloatingType>
struct vector<FloatingType, 1> : internal::vector_impl<vector<FloatingType, 1>> {
private:
	using base = internal::vector_impl<vector<FloatingType, 1>>;
	
public:
	using value_type = FloatingType;
	
	static constexpr std::size_t element_count = 1;
	
	FloatingType x;
	
	constexpr FloatingType& operator[](std::size_t n) {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		}
	}
	
	constexpr const FloatingType& operator[](std::size_t n) const {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		}
	}
};

template<typename FloatingType>
struct vector<FloatingType, 2> : internal::vector_impl<vector<FloatingType, 2>> {
private:
	using base = internal::vector_impl<vector<FloatingType, 2>>;
	
public:
	using value_type = FloatingType;
	
	static constexpr std::size_t element_count = 2;
	
	FloatingType x, y;
	
	constexpr FloatingType& operator[](std::size_t n) {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		case 1: return y;
		}
	}
	
	constexpr const FloatingType& operator[](std::size_t n) const {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		case 1: return y;
		}
	}
};

template<typename FloatingType>
struct vector<FloatingType, 3> : internal::vector_impl<vector<FloatingType, 3>> {
private:
	using base = internal::vector_impl<vector<FloatingType, 3>>;
	
public:
	using value_type = FloatingType;
	
	static constexpr std::size_t element_count = 3;
	
	FloatingType x, y, z;
	
	constexpr FloatingType& operator[](std::size_t n) {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		case 1: return y;
		case 2: return z;
		}
	}
	
	constexpr const FloatingType& operator[](std::size_t n) const {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		case 1: return y;
		case 2: return z;
		}
	}
};

template<typename FloatingType>
struct vector<FloatingType, 4> : internal::vector_impl<vector<FloatingType, 4>> {
private:
	using base = internal::vector_impl<vector<FloatingType, 4>>;
	
public:
	using value_type = FloatingType;
	
	static constexpr std::size_t element_count = 4;
	
	FloatingType x, y, z, w;
	
	constexpr FloatingType& operator[](std::size_t n) {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		}
	}
	
	constexpr const FloatingType& operator[](std::size_t n) const {
		switch (n) {
		default: internal::dothrow_debug<std::out_of_range>("out_of_range");
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		}
	}
};

template<internal::vector_type Vec>
constexpr auto dot(const Vec& lhs, const Vec& rhs) {
	return internal::vector_accumulate(lhs, rhs, std::multiplies{});
}

template<internal::vector_type Vec>
constexpr auto sqr_magnitude(const Vec& vec) {
	return vec.sqr_magnitude();
}

template<internal::vector_type Vec>
auto magnitude(const Vec& vec) {
	return vec.magnitude();
}

template<internal::vector_sized<3> Vec>
constexpr Vec cross(const Vec& lhs, const Vec& rhs) {
	return Vec {
		.x = {(lhs[1] * rhs[2]) - (lhs[2] * rhs[1])},
		.y = {(lhs[2] * rhs[0]) - (lhs[0] * rhs[2])},
		.z = {(lhs[0] * rhs[1]) - (lhs[1] * rhs[0])}
	};
}

template<typename FloatingType, std::size_t N>
constexpr auto make_vector(const FloatingType (&arr)[N]) {
	vector<FloatingType, N> out;
	for (std::size_t i : std::views::iota((std::size_t)0, N)) {
		out[i] = arr[i];
	}
	return out;
}

using vec1f32_t = vector<float, 1>;
using vec2f32_t = vector<float, 2>;
using vec3f32_t = vector<float, 3>;
using vec4f32_t = vector<float, 4>;

using vec1f64_t = vector<double, 1>;
using vec2f64_t = vector<double, 2>;
using vec3f64_t = vector<double, 3>;
using vec4f64_t = vector<double, 4>;

ICANVAS_NAMESPACE_MATH_END
