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

#include "ivk_dev.h"

#if 0
struct ICE_FX_HANDLE_VK(ce_gpu_dev) {
  VkPhysicalDevice handle;
};

struct ICE_FX_HANDLE_VK(ce_dev) {
  VkDevice handle;
};

ICE_API ce_err ivk_gpu_dev_get(
  CE_OUT ce_gpu_dev* CE_RESTRICT buffer,
         size_t                  buffer_size,
  CE_OUT size_t*     CE_RESTRICT opt_out_size
) {
  // VkPhysicalDevice
  // vkEnumeratePhysicalDeviceGroups();
  
  if (buffer == NULL && opt_out_size == NULL) {
    return CE_EINVAL;
  }
  
  if (buffer != NULL && buffer_size == 0) {
    return CE_EINVAL;
  }
  
  uint32_t index = 0;
  uint32_t count = 0;
  VkPhysicalDevice* devs = NULL;
  IERRBEGIN {
    IERRDO(ifrom_vk(vkEnumeratePhysicalDevices(ivk_inst, &count, NULL)));
    if (buffer == NULL) {
      *opt_out_size = count;
      return CE_EOK;
    }
    
    if (buffer_size < count) {
      count = (uint32_t)buffer_size;
    }
    
    devs = (VkPhysicalDevice*)ialloc(sizeof(*devs) * count, &IERRVAL);
    IERRDO(IERRVAL);
    IERRDO(ifrom_vk(vkEnumeratePhysicalDevices(ivk_inst, &count, devs)));
    
    for (index = 0; index < count; ++index) {
      ICE_FX_HANDLE_VK(ce_gpu_dev)* const ptr = (ICE_FX_HANDLE_VK(ce_gpu_dev)*)ialloc(sizeof(ICE_FX_HANDLE_VK(ce_gpu_dev)), &IERRVAL);
      IERRDO(IERRVAL);
      
      ptr->handle = devs[index];
      buffer[index].type = ICEFX_VULKAN;
      buffer[index].handle.vk = ptr;
    }
  } IERREND { }
  
  if (opt_out_size) {
    *opt_out_size = index;
  }
  
  ifree(devs, sizeof(*devs) * count);
  return IERRVAL;
  
  (void)buffer;
  (void)buffer_size;
  (void)opt_out_size;
  return CE_ENOSYS;
}

ICE_API void ivk_gpu_dev_release(
  CE_IN ce_gpu_dev gpu_dev
) {
  ICE_FX_HANDLE_VK(ce_gpu_dev)* const handle = IFX_GET_VK_HANDLE(gpu_dev);
  if (handle == NULL) {
    return;
  }
  
  ifree(handle, sizeof(*handle));
}

ICE_API ce_err ivk_dev_create(
  CE_OUT ce_dev* dev_out,
  CE_IN  const ce_dev_create_info* info
) {
  if (dev_out == NULL || info == NULL) {
    return CE_EINVAL;
  }
  
  if (info->gpu_dev == NULL || info->gpu_dev->type != ICEFX_VULKAN) {
    return CE_EINVAL;
  }
  
#if 0
  ICE_FX_HANDLE_VK(ce_dev)* p;
  IERRBEGIN {
    p = (ICE_FX_HANDLE_VK(ce_dev)*)ialloc(sizeof(*p), &IERRVAL);
    IERRDO(IERRVAL);
    
    VkDeviceCreateInfo create_info;
    create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    create_info.pNext = NULL;
    create_info.flags = 0;
    create_info.queueCreateInfoCount = 0;
    create_info.pQueueCreateInfos = 0;
    create_info.enabledLayerCount = 0;
    create_info.ppEnabledLayerNames = 0;
    create_info.enabledExtensionCount = 0;
    create_info.ppEnabledExtensionNames = 0;
    create_info.pEnabledFeatures = 0;
    
    vkCreateDevice(
      info->gpu_dev->handle.vk->handle,
      
    );
    
    VkResult (*PFN_vkCreateDevice)(
      VkPhysicalDevice physicalDevice,
      const VkDeviceCreateInfo* pCreateInfo,
      const VkAllocationCallbacks* pAllocator,
      VkDevice* pDevice
    );
    
    // p->handle
    PFN_vkCreateDevice s;
  } IERREND {
    ifree(p, sizeof(*p));
  }
  return IERRVAL;
#endif
  
  return CE_ENOSYS;
}

ICE_API void ivk_dev_delete(
  CE_IN ce_dev dev
) {
  (void)dev;
#if 0
  ICE_FX_HANDLE_VK(ce_dev)* const handle = IFX_GET_VK_HANDLE(dev);
  if (handle == NULL) {
    return;
  }
  
  ifree(handle, sizeof(*handle));
#endif
}
#endif
