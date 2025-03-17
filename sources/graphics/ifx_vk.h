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

#ifndef IFX_VK_H
#define IFX_VK_H

#include "ifx_base.h"
#include <canvas/graphics.h>

#ifdef CANVAS_ENABLE_VULKAN

#include <vulkan/vulkan.h>

CE_NAMESPACE_BEGIN

#ifndef VK_VERSION_1_3
#  error CanvasEngine graphics requires VulkanAPI 1.3 or later
#endif

/* Used to fill in a `VkAllocationCallbacks*` function argument. Currently just `NULL` */
#define IVK_ALLOC NULL

ICE_API ce_err ivk_inst_layers(
  CE_OUT ce_arr(VkLayerProperties)* out_layers
);

ICE_API ce_err ivk_inst_exts(
  CE_IN  const ce_utf8* name,
  CE_OUT ce_arr(VkExtensionProperties)* out_exts
);

ICE_API ce_err ifrom_vk(VkResult res);

struct ice_gpu_adapter_vk {
  VkPhysicalDevice dev;
};

CE_NAMESPACE_END

#endif /* !CANVAS_ENABLE_VULKAN */

#endif /* !IFX_VK_H */
