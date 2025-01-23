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

CANVAS_API void vprint(std::ostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::ostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprint(std::wostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::wostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprint(std::FILE* stream, const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::FILE* stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprint(const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(const std::locale& loc, std::wstring_view fmt, std::wformat_args args);

CANVAS_API void vprint(std::ostream& stream, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::ostream& stream, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprint(std::wostream& stream, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::wostream& stream, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprint(std::FILE* stream, std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::FILE* stream, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprint(std::string_view fmt, std::format_args args);
CANVAS_API void vprint(std::wstring_view fmt, std::wformat_args args);

CANVAS_API void vprintln(std::ostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::ostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprintln(std::wostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::wostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprintln(std::FILE* stream, const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::FILE* stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprintln(const std::locale& loc, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(const std::locale& loc, std::wstring_view fmt, std::wformat_args args);

CANVAS_API void vprintln(std::ostream& stream, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::ostream& stream, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprintln(std::wostream& stream, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::wostream& stream, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprintln(std::FILE* stream, std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::FILE* stream, std::wstring_view fmt, std::wformat_args args);
CANVAS_API void vprintln(std::string_view fmt, std::format_args args);
CANVAS_API void vprintln(std::wstring_view fmt, std::wformat_args args);

template<typename ... Args>
void print(std::ostream& stream, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::ostream& stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(std::wostream& stream, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::wostream& stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(std::FILE* stream, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::FILE* stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(std::format_string<Args...> fmt, Args&&... args) {
	vprint(fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::ostream& stream, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::ostream& stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::wostream& stream, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::wostream& stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::FILE* stream, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::FILE* stream, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::format_string<Args...> fmt, Args&&... args) {
	vprintln(fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(std::ostream& stream, const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::ostream& stream, const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(std::wostream& stream, const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::wostream& stream, const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(std::FILE* stream, const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprint(stream, loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(std::FILE* stream, const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(stream, loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void print(const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprint(loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void print(const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprint(loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::ostream& stream, const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::ostream& stream, const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::wostream& stream, const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::wostream& stream, const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(std::FILE* stream, const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(stream, loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(std::FILE* stream, const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(stream, loc, fmt.get(), std::make_wformat_args(args...));
}

template<typename ... Args>
void println(const std::locale& loc, std::format_string<Args...> fmt, Args&&... args) {
	vprintln(loc, fmt.get(), std::make_format_args(args...));
}

template<typename ... Args>
void println(const std::locale& loc, std::wformat_string<Args...> fmt, Args&&... args) {
	vprintln(loc, fmt.get(), std::make_wformat_args(args...));
}

} // !namespace canvas
