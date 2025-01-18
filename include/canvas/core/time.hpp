/**
 * @file time.hpp
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
#include <compare>
#include <chrono>

ICANVAS_NAMESPACE_BEGIN

class time {
public:
	using duration = std::chrono::nanoseconds;
	using rep = typename duration::rep;
	using period = typename duration::period;
	
	constexpr time() noexcept = default;
	constexpr time(const time&) noexcept = default;
	constexpr time& operator=(const time&) noexcept = default;
	
	template<typename Rep=rep, typename Period=period>
	constexpr time(const std::chrono::duration<Rep, Period>& dur)
		: m_value(std::chrono::duration_cast<duration>(dur)) {
	}
	
	template<typename Duration>
	[[nodiscard]]
	constexpr Duration as() const {
		return std::chrono::duration_cast<Duration>(m_value);
	}
	
	template<typename Rep=rep, typename Period=period>
	[[nodiscard]]
	constexpr operator std::chrono::duration<Rep, Period>() const {
		return as<std::chrono::duration<Rep, Period>>();
	}
	
	[[nodiscard]]
	constexpr bool operator==(const time&) const = default;
	
	[[nodiscard]]
	constexpr auto operator<=>(const time&) const = default;
	
	constexpr time& operator+=(const time& other) {
		m_value += other.m_value;
		return *this;
	}
	
	template<typename Rep=rep, typename Period=period>
	constexpr time& operator+=(const std::chrono::duration<Rep, Period>& other) {
		m_value += other;
		return *this;
	}
	
	constexpr time& operator-=(const time& other) {
		m_value -= other.m_value;
		return *this;
	}
	
	template<typename Rep=rep, typename Period=period>
	constexpr time& operator-=(const std::chrono::duration<Rep, Period>& other) {
		m_value -= other;
		return *this;
	}
	
	constexpr time& operator%=(const time& other) {
		m_value %= other.m_value;
		return *this;
	}
	
	template<typename Rep=rep, typename Period=period>
	constexpr time& operator%=(const std::chrono::duration<Rep, Period>& other) {
		m_value %= other;
		return *this;
	}
	
	constexpr time& operator*=(const rep& other) {
		m_value *= other;
		return *this;
	}
	
	constexpr time& operator/=(const rep& other) {
		m_value /= other;
		return *this;
	}
	
	constexpr time& operator%=(const rep& other) {
		m_value %= other;
		return *this;
	}
	
	constexpr time& operator++() {
		++m_value;
		return *this;
	}
	
	constexpr time& operator--() {
		--m_value;
		return *this;
	}
	
	constexpr time operator++(int) {
		time cpy = *this;
		++(*this);
		return cpy;
	}
	
	constexpr time operator--(int) {
		time cpy = *this;
		--(*this);
		return cpy;
	}
	
	constexpr time operator+() const {
		+m_value;
		return *this;
	}
	
	constexpr time operator-() const {
		-m_value;
		return *this;
	}
	
private:
	duration m_value { };
};

[[nodiscard]]
constexpr time operator+(const time& lhs, const time& rhs) {
	time cpy = lhs;
	cpy += rhs;
	return cpy;
}

[[nodiscard]]
constexpr time operator-(const time& lhs, const time& rhs) {
	time cpy = lhs;
	cpy -= rhs;
	return cpy;
}

[[nodiscard]]
constexpr time operator%(const time& lhs, const time& rhs) {
	time cpy = lhs;
	cpy %= rhs;
	return cpy;
}

template<typename Rep, typename Period>
[[nodiscard]]
constexpr time operator+(const time& lhs, const std::chrono::duration<Rep, Period>& rhs) {
	time cpy = lhs;
	cpy += rhs;
	return cpy;
}

template<typename Rep, typename Period>
[[nodiscard]]
constexpr time operator-(const time& lhs, const std::chrono::duration<Rep, Period>& rhs) {
	time cpy = lhs;
	cpy -= rhs;
	return cpy;
}

template<typename Rep, typename Period>
[[nodiscard]]
constexpr time operator%(const time& lhs, const std::chrono::duration<Rep, Period>& rhs) {
	time cpy = lhs;
	cpy %= rhs;
	return cpy;
}

[[nodiscard]]
constexpr time operator*(const time& lhs, const time::rep& rhs) {
	time cpy = lhs;
	cpy *= rhs;
	return cpy;
}

[[nodiscard]]
constexpr time operator/(const time& lhs, const time::rep& rhs) {
	time cpy = lhs;
	cpy /= rhs;
	return cpy;
}

[[nodiscard]]
constexpr time operator%(const time& lhs, const time::rep& rhs) {
	time cpy = lhs;
	cpy %= rhs;
	return cpy;
}

#if 0
inline string to_string(const time& t) {
	string out;
}
#endif

ICANVAS_NAMESPACE_INTERNAL_BEGIN

using stopwatch_clock = std::conditional_t<
	std::chrono::high_resolution_clock::is_steady,
	std::chrono::high_resolution_clock,
	std::chrono::steady_clock
>;

ICANVAS_NAMESPACE_INTERNAL_END

template<typename Clock>
class basic_stopwatch {
public:
	using clock = Clock;
	using time_point = typename clock::time_point;
	using duration = typename clock::duration;
	
	[[nodiscard]]
	bool operator==(const basic_stopwatch&) const noexcept = default;
	
	[[nodiscard]]
	auto operator<=>(const basic_stopwatch&) const noexcept = default;
	
	[[nodiscard]]
	bool active() const {
		return m_start != time_point { };
	}
	
	void restart() {
		m_duration = duration { };
		m_start = clock::now();
	}
	
	void reset() {
		m_start = time_point { };
		m_duration = duration { };
	}
	
	void start() {
		if (active()) {
			return;
		}
		
		m_start = clock::now();
	}
	
	void stop() {
		if (!active()) {
			return;
		}
		
		const time_point end = clock::now();
		m_duration += end - m_start;
		m_start = time_point { };
	}
	
	[[nodiscard]]
	duration elapsed() const {
		basic_stopwatch cpy = *this;
		cpy.stop();
		return cpy.m_duration;
	}
	
	template<typename Duration>
	[[nodiscard]]
	Duration elapsed() const {
		return std::chrono::duration_cast<Duration>(elapsed());
	}
	
private:
	time_point m_start { };
	duration m_duration { };
};

template<typename Clock>
class stopwatch_scope {
public:
	stopwatch_scope(basic_stopwatch<Clock>& sw) noexcept
		: m_sw(sw) {
		m_sw.start();
	}
	
	~stopwatch_scope() noexcept {
		m_sw.stop();
	}
	
private:
	basic_stopwatch<Clock>& m_sw;
};

template<typename Clock>
class stopwatch_stopscope {
public:
	stopwatch_stopscope(basic_stopwatch<Clock>& sw) noexcept
		: m_sw(sw) {
		m_sw.start();
	}
	
	~stopwatch_stopscope() noexcept {
		m_sw.stop();
	}
	
private:
	basic_stopwatch<Clock>& m_sw;
};

template<typename Clock>
stopwatch_scope(basic_stopwatch<Clock>&) -> stopwatch_scope<Clock>;

template<typename Clock>
stopwatch_stopscope(basic_stopwatch<Clock>&) -> stopwatch_stopscope<Clock>;

using stopwatch = basic_stopwatch<internal::stopwatch_clock>;

ICANVAS_NAMESPACE_END

template<typename CharTy>
struct std::formatter<canvas::time, CharTy> : std::formatter<std::chrono::duration<float>, CharTy> {
private:
	using base = std::formatter<std::chrono::duration<float>, CharTy>;
	
public:
	auto format(const canvas::time& t, auto& ctx) {
		return base::format(t.as<std::chrono::duration<float>>(), ctx);
	}
};
