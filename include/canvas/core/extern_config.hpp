/**
 * @file canvas.hpp
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

#if defined(CANVAS_USR_CONFIG)
#include CANVAS_USR_CONFIG
#else
#include <string>
#include <vector>

ICANVAS_NAMESPACE_BEGIN

template<typename T>
using tstring = std::basic_string<T>;

template<typename T>
using darray = std::vector<T>;

ICANVAS_NAMESPACE_END

#endif

ICANVAS_NAMESPACE_BEGIN

using string = tstring<char>;
using wstring = tstring<wchar_t>;

ICANVAS_NAMESPACE_END
