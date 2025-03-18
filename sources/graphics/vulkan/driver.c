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

#include "ifx_vk.h"
#include "ivk_protos.h"
#include "ivk_dev.h"

static const char* s_req_inst_exts[] = {
  VK_KHR_DISPLAY_EXTENSION_NAME,
  VK_KHR_SURFACE_EXTENSION_NAME,
#ifdef CANVAS_ENABLE_WAYLAND
  VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
#endif
#ifdef CANVAS_ENABLE_XLIB
  VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
  VK_KHR_XCB_SURFACE_EXTENSION_NAME,
#endif
#if CANVAS_PLATFORM_WINDOWS
  VK_KHR_WIN32_SURFACE_EXTENSION_NAME
#endif
};

static void irelease_driver(
  CE_INOUT ce_render_driver* self
);
  
static ce_err ifetch_gpu_adapters(
  CE_INOUT ce_render_driver*   self,
           ce_gpu_adapter_pref order_pref
);

#define IFX_GPU_ADAPTER_TYPE ice_gpu_adapter_vk
#define IFX_GPU_ADAPTER_VAR vk
#include "ifx_get_adapters.inl"

static const ce_render_driver_vfp s_vfp = {
  .release = &irelease_driver,
  .fetch_gpu_adapters = &ifetch_gpu_adapters,
  .get_gpu_adapters = &iget_gpu_adapters,
  .dev_create = &ivk_dev_create,
  .dev_destroy = &ivk_dev_destroy,
};

CE_API ce_err ce_vulkan_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_vulkan_driver_create_info* info
) {
  if (driver == NULL || info == NULL) {
    return CE_EINVAL;
  }
  
  const size_t req_exts_count = CE_ARRLEN(s_req_inst_exts) + info->instance_extension_count;
  const ce_utf8** req_exts = NULL;
  
  ice_vulkan_driver_data* vkp = NULL;
  IERRBEGIN {
    
    req_exts = IERRALLOC(sizeof(*req_exts) * req_exts_count);
    vkp = IERRALLOC(sizeof(ice_vulkan_driver_data));
    driver->data.vk = vkp;
    *vkp = (ice_vulkan_driver_data) {0};
    ivk_protos* const pfn = &vkp->pfn;
    
    memcpy(req_exts, s_req_inst_exts, CE_ARRLEN(s_req_inst_exts) * sizeof(char*));
    memcpy(req_exts + CE_ARRLEN(s_req_inst_exts), info->instance_extension_names, info->instance_extension_count * sizeof(char*));
    
    VkApplicationInfo app_info;
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pNext = NULL;
    app_info.pApplicationName = info->app_name;
    app_info.applicationVersion = info->app_version;
    app_info.pEngineName = info->engine_name;
    app_info.engineVersion = info->engine_version;
    app_info.apiVersion = VK_API_VERSION_1_3;
    
    VkInstanceCreateInfo inst_info;
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    inst_info.pNext = NULL;
    inst_info.flags = 0;
    inst_info.pApplicationInfo = &app_info;
    inst_info.enabledLayerCount = info->instance_layer_count;
    inst_info.ppEnabledLayerNames = info->instance_layer_names;
    inst_info.enabledExtensionCount = (uint32_t)req_exts_count;
    inst_info.ppEnabledExtensionNames = req_exts;
    
    IERRDO(ivk_load_protos(&inst_info, &vkp->instance, pfn));
    
    driver->vfp = &s_vfp;
  } IERREND {
    *driver = (ce_render_driver) {0};
    ifree(vkp, sizeof(*vkp));
  }
  
  ifree(req_exts, sizeof(*req_exts) * req_exts_count);
  return IERRVAL;
}

static void irelease_driver(
  CE_INOUT ce_render_driver* self
) {
  ice_vulkan_driver_data* const vkp = self->data.vk;
  ivk_protos* const p = &(vkp->pfn);
  
  ce_arr_free(vkp->gpu_adapters);
  ivk_unload_protos(vkp->instance, p);
  ifree(vkp, sizeof(*(vkp)));
  
  *self = (ce_render_driver) {0};
}

static ce_err ifetch_gpu_adapters(
  CE_INOUT ce_render_driver*   self,
           ce_gpu_adapter_pref order_pref
) {
  (void)order_pref; /* This parameter is only used in DX12. */
  
  ice_vulkan_driver_data* const vkp = self->data.vk;
  const ivk_protos* const pfn = &vkp->pfn;
  ce_arr(ice_gpu_adapter_vk)* adapters = &vkp->gpu_adapters;
  
  VkPhysicalDevice* phys_devs = NULL;
  uint32_t count;
  
  IERRBEGIN {
    
    IERRDO(ifrom_vk(pfn->vkEnumeratePhysicalDevices(vkp->instance, &count, NULL)));
    
    phys_devs = IERRALLOC(sizeof(*phys_devs) * count);
    IERRDO(ce_arr_resize(adapters, count, sizeof(**adapters)));
    
    IERRDO(ifrom_vk(pfn->vkEnumeratePhysicalDevices(vkp->instance, &count, phys_devs)));
    
    for (uint32_t i = 0; i < count; ++i) {
      (*adapters)[i].dev = phys_devs[i];
    }
    
  } IERREND { }
  
  ifree(phys_devs, sizeof(*phys_devs) * count);
  
  return IERRVAL;
}
