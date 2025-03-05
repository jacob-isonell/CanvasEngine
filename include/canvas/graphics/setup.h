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
typedef struct ce_graphics_vulkan_t {
  
  /**
   * @brief An array of vulkan instance layers that are required by the running program.
   * @note Querying for instance layers and assinging them to these fields is incorrect usage.
   *   These fields are for specifying instance layers that are required for the application
   *   to run properly. CanvasEngine by default requires certain instance layers to function.
   */
  const ce_vk_layer_str* inst_layers;
  
  /** @brief The number of elements in `inst_layers`. */
  size_t inst_layers_len;
  
  /**
   * @brief An array of vulkan instance extensions that are required by the running program.
   * @note Querying for instance extensions and assinging them to these fields is incorrect usage.
   *   These fields are for specifying instance extensions that are required for the application
   *   to run properly. CanvasEngine by default requires certain instance extensions to function.
   */
  const ce_vk_ext_str* inst_exts;
  
  /** @brief The number of elements in `inst_exts`. */
  size_t inst_exts_len;
  
} ce_graphics_vulkan_t;

/**
 * @ingroup configuration
 * @brief add documentation here!
 */
typedef struct ce_graphics {
  
  /** add documentation here! */
  ce_render_api render_api;
  
  /** add documentation here! */
  ce_graphics_vulkan_t vulkan;
  
} ce_graphics;

/**
 * @ingroup configuration
 * @brief add documentation here!
 */
CE_API ce_err ce_graphics_set(
  const ce_graphics* ops
);

ICE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_SETUP_H */
