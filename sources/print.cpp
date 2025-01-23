/**
 * @file print.cpp
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

#include <canvas/core/print.hpp>
#include <locale>

namespace canvas {

struct s_wchar_to_char : std::ctype<wchar_t> { };

static void s_fputc(std::FILE* stream, char c) { std::fputc(c, stream); }
static void s_fputc(std::FILE* stream, wchar_t c) { std::fputwc(c, stream); }
static void s_fputc(std::ostream& stream, char c) { stream << c; }
static void s_fputc(std::wostream& stream, char c) { stream << c; }
static void s_fputc(std::ostream& stream, wchar_t c) {
	s_wchar_to_char conv;
	stream << conv.narrow(c, ' ');
}
static void s_fputc(std::wostream& stream, wchar_t c) { stream << c; }

template<typename StreamTy>
struct s_stream_iterator {
	s_stream_iterator(StreamTy& stream) noexcept
		: m_stream(&stream) {
	}
	
	using iterator_category = std::output_iterator_tag;
	using value_type = void;
	using difference_type = pd;
	using pointer = void;
	using reference = void;
	
	s_stream_iterator& operator=(auto c) noexcept {
		s_fputc(*m_stream, c);
		return *this;
	}
	
	s_stream_iterator& operator*() noexcept { return *this; }
	s_stream_iterator& operator++() noexcept { return *this; }
	s_stream_iterator& operator++(int) noexcept { return *this; }
	
private:
	StreamTy* m_stream;
};

template<
	typename StrView,
	typename FmtArgs,
	typename AppendFunc = std::identity
>
inline void s_vprint_impl(
	auto& stream,
	StrView fmt_str,
	FmtArgs fmt_args,
	AppendFunc&& func = { }
) {
	std::vformat_to(s_stream_iterator(stream), fmt_str, fmt_args);
	std::invoke(func, stream);
}

template<
	typename StrView,
	typename FmtArgs,
	typename AppendFunc = std::identity
>
inline void s_vprint_impl(
	auto& stream,
	const std::locale& loc,
	StrView fmt_str,
	FmtArgs fmt_args,
	AppendFunc&& func = { }
) {
	std::vformat_to(s_stream_iterator(stream), loc, fmt_str, fmt_args);
	std::invoke(func, stream);
}

struct s_newline {
	void operator()(auto& stream) {
		s_fputc(stream, '\n');
	}
};

CANVAS_API
void vprint(std::ostream& stream, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, fmt, args);
}

CANVAS_API
void vprint(std::ostream& stream, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, fmt, args);
}

CANVAS_API
void vprint(std::wostream& stream, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, fmt, args);
}

CANVAS_API
void vprint(std::wostream& stream, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, fmt, args);
}

CANVAS_API
void vprint(std::FILE* stream, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, fmt, args);
}

CANVAS_API
void vprint(std::FILE* stream, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, fmt, args);
}

CANVAS_API
void vprint(std::string_view fmt, std::format_args args) {
	s_vprint_impl(stdout, fmt, args);
}

CANVAS_API
void vprint(std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stdout, fmt, args);
}

CANVAS_API
void vprintln(std::ostream& stream, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::ostream& stream, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::wostream& stream, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::wostream& stream, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::FILE* stream, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::FILE* stream, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::string_view fmt, std::format_args args) {
	s_vprint_impl(stdout, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stdout, fmt, args, s_newline{});
}

CANVAS_API
void vprint(std::ostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, loc, fmt, args);
}

CANVAS_API
void vprint(std::ostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, loc, fmt, args);
}

CANVAS_API
void vprint(std::wostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, loc, fmt, args);
}

CANVAS_API
void vprint(std::wostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, loc, fmt, args);
}

CANVAS_API
void vprint(std::FILE* stream, const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, loc, fmt, args);
}

CANVAS_API
void vprint(std::FILE* stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, loc, fmt, args);
}

CANVAS_API
void vprint(const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stdout, loc, fmt, args);
}

CANVAS_API
void vprint(const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stdout, loc, fmt, args);
}

CANVAS_API
void vprintln(std::ostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::ostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::wostream& stream, const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::wostream& stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::FILE* stream, const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stream, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(std::FILE* stream, const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stream, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(const std::locale& loc, std::string_view fmt, std::format_args args) {
	s_vprint_impl(stdout, loc, fmt, args, s_newline{});
}

CANVAS_API
void vprintln(const std::locale& loc, std::wstring_view fmt, std::wformat_args args) {
	s_vprint_impl(stdout, loc, fmt, args, s_newline{});
}

} // !namespace canvas
