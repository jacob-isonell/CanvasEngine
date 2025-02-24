/**************************************************************************
** CanvasEngine is a C11 cross platform multimedia library.              **
** Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             **
**                                                                       **
** This program is free software: you can redistribute it and/or modify  **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 3 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** This program is distributed in the hope that it will be useful,       **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with this program. If not, see <https://www.gnu.org/licenses/>. **
**************************************************************************/

#ifndef CANVAS_GRAPHICS_SETUP_H
#define CANVAS_GRAPHICS_SETUP_H

#include <canvas/graphics/graphics.h>

ICE_NAMESPACE_BEGIN

/**
 * @ingroup configuration
 * @brief add documentation here!
 */
struct ce_graphics_vulkan_t {
	size_t instance_layers_count;
	struct ce_vk_layer_str* instance_layers;
	size_t instance_extensions_count;
	struct ce_vk_ext_str* instance_extensions;
};

/**
 * @ingroup configuration
 * @brief add documentation here!
 */
struct ce_graphics_t {
	/** add documentation here! */
	struct ce_graphics_vulkan_t vulkan;
};

/**
 * @ingroup configuration
 * @brief add documentation here!
 */
CE_API
ce_err ce_graphics_options(
	const struct ce_graphics_t* options
);

ICE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_SETUP_H */
