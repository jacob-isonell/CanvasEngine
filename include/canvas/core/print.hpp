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
#include <iterator>
#include <iostream>
#include <string_view>
#include <cstdio>

namespace canvas {

namespace internal {

template<typename CharTy>
struct cio_funcs { };

template<>
struct cio_funcs<char> {
	static constexpr auto fputc = std::fputc;
	static constexpr auto putc = std::putc;
	static constexpr auto fputs = std::fputs;
	static constexpr auto putchar = std::putchar;
	static constexpr auto fprintf = std::fprintf;
	static constexpr auto printf = std::printf;
};

template<>
struct cio_funcs<wchar_t> {
	static constexpr auto fputc = std::fputwc;
	static constexpr auto putc = std::putwc;
	static constexpr auto fputs = std::fputws;
	static constexpr auto putchar = std::putwchar;
	static constexpr auto fprintf = std::fwprintf;
	static constexpr auto printf = std::wprintf;
};

template<typename CharTy>
struct cfile_out_iterator {
private:
	using cio_t = cio_funcs<CharTy>;
	
public:
	explicit cfile_out_iterator(std::FILE* file) noexcept
		: m_file(file) {
	}
	
	using iterator_category = std::output_iterator_tag;
	using value_type = void;
	using difference_type = pd;
	using pointer = void;
	using reference = void;
	
	cfile_out_iterator& operator=(CharTy c) noexcept {
		cio_t::fputc(c, m_file);
		return *this;
	}
	
	cfile_out_iterator& operator*() noexcept { return *this; }
	cfile_out_iterator& operator++() noexcept { return *this; }
	cfile_out_iterator& operator++(int) noexcept { return *this; }
	
private:
	std::FILE* m_file;
};

} // !namespace internal

inline void vprint(std::ostream& stream, std::string_view fmt, std::format_args args) {
	std::vformat_to(std::ostream_iterator<char>(stream), fmt, args);
}

inline void vprintln(std::ostream& stream, std::string_view fmt, std::format_args args) {
	std::vformat_to(std::ostream_iterator<char>(stream), fmt, args);
	stream.put('\n');
}

inline void vprint(std::FILE* cstream, std::string_view fmt, std::format_args args) {
	std::vformat_to(internal::cfile_out_iterator<char>(cstream), fmt, args);
}

inline void vprintln(std::FILE* cstream, std::string_view fmt, std::format_args args) {
	std::vformat_to(internal::cfile_out_iterator<char>(cstream), fmt, args);
	std::fputc('\n', cstream);
}

inline void vprint(std::wostream& stream, std::wstring_view fmt, std::wformat_args args) {
	std::vformat_to(std::ostream_iterator<wchar_t, wchar_t>(stream), fmt, args);
}

inline void vprintln(std::wostream& stream, std::wstring_view fmt, std::wformat_args args) {
	std::vformat_to(std::ostream_iterator<wchar_t, wchar_t>(stream), fmt, args);
	stream.put(L'\n');
}

inline void vprint(std::FILE* cstream, std::wstring_view fmt, std::wformat_args args) {
	std::vformat_to(internal::cfile_out_iterator<wchar_t>(cstream), fmt, args);
}

inline void vprintln(std::FILE* cstream, std::wstring_view fmt, std::wformat_args args) {
	std::vformat_to(internal::cfile_out_iterator<wchar_t>(cstream), fmt, args);
	std::fputwc(L'\n', cstream);
}

template<typename ... Args>
inline void print(std::ostream& stream, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
inline void println(std::ostream& stream, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
inline void print(std::FILE* stream, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
inline void println(std::FILE* stream, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
inline void print(std::format_string<Args...> fmt, Args&&... args) {
	vprint(stdout, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
inline void println(std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stdout, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
inline void print(std::ostream& stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
inline void println(std::ostream& stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
inline void print(std::FILE* stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
inline void println(std::FILE* stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
inline void print(std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(std::wcout, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
inline void println(std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(std::wcout, fmt.get(), std::make_wformat_args(args...));
}

} // !namespace canvas
