/**
 * @file graphics.cpp
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

#include <canvas/graphics/graphics.hpp>

ICANVAS_NAMESPACE_GRAPHICS_BEGIN

static backend s_selected_backend = backend::vulkan;

CANVAS_API
err set_backend(backend selected_backend) noexcept {
	s_selected_backend = selected_backend;
	return err::eok;
}

CANVAS_API
[[nodiscard]]
backend get_backend() noexcept {
	return s_selected_backend;
}

ICANVAS_NAMESPACE_GRAPHICS_END
