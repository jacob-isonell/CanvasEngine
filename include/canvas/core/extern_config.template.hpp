/**
 * @file extern_config.template.hpp
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

/**
 * This is an example template file for providing customization for CanvasEngine
 * at compile time. Copy this file to your project, modify it, then use the CMake
 * function `CanvasSetUsrConfigHeaders` defined by CanvasEngine with the path
 * to your local copy. You can replace the defined types with your own implementations.
 * But they should still have the same expected behaviour.
 */

#include <string>
#include <vector>

namespace canvas {
	
	template<typename T>
	using tstring = std::basic_string<T>;
	
	template<typename T>
	using dynamic_array = std::vector<T>;
}
