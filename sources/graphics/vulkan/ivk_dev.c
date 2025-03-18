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

ICE_API
ce_err ivk_dev_create(
  CE_IN  const ce_render_driver*   CE_RESTRICT self,
  CE_OUT ce_gpu_dev*               CE_RESTRICT out,
  CE_IN  const ce_dev_create_info* CE_RESTRICT info
) {
  /* work in progress */
  
  (void)self;
  if (out == NULL || info == NULL) {
    return CE_EINVAL;
  }
  
  return CE_ENOSYS;
  
#if 0
  if (info->adapter.vk == NULL) {
    return CE_EINVAL;
  }
  
  ivk_protos* const proto = &(self->data.vk->pfn);
  *out = (ce_gpu_dev) {0};
  
  ice_gpu_dev_vk* data;
  IERRBEGIN {
    data = IERRALLOC(sizeof(*data));
    out->vk = data;
    
    VkDeviceCreateInfo vkinfo;
    vkinfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    vkinfo.pNext = NULL;
    vkinfo.flags = 0;
    vkinfo.queueCreateInfoCount = 0;
    vkinfo.pQueueCreateInfos = 0;
    vkinfo.enabledLayerCount = 0;
    vkinfo.ppEnabledLayerNames = 0;
    vkinfo.enabledExtensionCount = 0;
    vkinfo.ppEnabledExtensionNames = 0;
    vkinfo.pEnabledFeatures = 0;
    
    IERRDO(ifrom_vk(proto->vkCreateDevice(info->adapter.vk->dev, &vkinfo, IVK_ALLOC, &data->handle)));
  } IERREND {
    ifree(data, sizeof(*data));
  }
  return IERRVAL;
#endif
}

ICE_API
void ivk_dev_destroy(
  CE_IN    const ce_render_driver* self,
  CE_INOUT ce_gpu_dev dev
) {
  /* work in progress */
  
  (void)self;
  if (dev.vk == NULL) {
    return;
  }
  
  // IFREE_TYPE(dev.vk);
}
