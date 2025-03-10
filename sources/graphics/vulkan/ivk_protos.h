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

#ifndef IVK_PROTO_H
#define IVK_PROTO_H

#include "ifx_vk.h"
#include <canvas/core/library.h>

CE_NAMESPACE_BEGIN

#if CANVAS_PLATFORM_WINDOWS
#define IVK_DLL_FILE "vulkan-1.dll"
#elif CANVAS_PLATFORM_UNIX
#define IVK_DLL_FILE "libvulkan.so.1"
#endif

typedef struct ivk_protos {
  ce_lib* libvulkan1;
  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
  
  PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
  PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
  PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
  PFN_vkCreateInstance vkCreateInstance;
  
  PFN_vkDestroyInstance vkDestroyInstance;
} ivk_protos;

struct ice_vulkan_driver_data {
  VkInstance instance;
  ivk_protos pfn;
};

ICE_API ce_err ivk_load_protos(
  CE_IN  const VkInstanceCreateInfo* CE_RESTRICT info,
  CE_OUT VkInstance*                 CE_RESTRICT out_inst,
  CE_OUT ivk_protos*                 CE_RESTRICT out_proto
);

ICE_API void ivk_unload_protos(
  CE_INOUT VkInstance              inst,
  CE_INOUT ivk_protos* CE_RESTRICT protos
);

CE_NAMESPACE_END

#endif /* !IVK_PROTO_H */
