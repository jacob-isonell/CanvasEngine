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

#ifndef CANVAS_GRAPHICS_DRIVER_H
#define CANVAS_GRAPHICS_DRIVER_H

#include <canvas/graphics/graphics.h>
#include <stdint.h>

CE_NAMESPACE_BEGIN

typedef struct ce_render_driver ce_render_driver;
ICE_GX_HANDLE(ce_gpu_adapter);
ICE_GX_HANDLE(ce_gpu_dev);

typedef struct ce_render_driver_vfp ce_render_driver_vfp;

#ifdef CANVAS_ENABLE_VULKAN
typedef struct ice_vulkan_driver_data ice_vulkan_driver_data;
#endif
#ifdef CANVAS_ENABLE_DIRECTX12
typedef struct ice_directx12_driver_data ice_directx12_driver_data;
#endif

/**
 * @brief 
 *  See [`DXGI_GPU_PREFERENCE`](https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_6/ne-dxgi1_6-dxgi_gpu_preference) for meaning.
 */
typedef enum ce_gpu_adapter_pref {
  CE_GPU_ADAPTER_PREF_UNSPECIFIED,
  CE_GPU_ADAPTER_PREF_PERFORMANCE,
  CE_GPU_ADAPTER_PREF_MINPOWER,
} ce_gpu_adapter_pref;

typedef struct ce_dev_create_info {
  ce_gpu_adapter adapter;
} ce_dev_create_info;

/**
 * @brief add documentation here!
 */
struct ce_render_driver_vfp {
  
  /**
   * @brief add documentation here!
   * @param self add documentation here!
   */
  void (*release)(
    CE_INOUT ce_render_driver* self
  );
  
  /**
   * @brief add documentation here!
   * @param self add documentation here!
   * @param order_pref The preferred method to order them in.
   */
  ce_err (*fetch_gpu_adapters)(
    CE_INOUT ce_render_driver*   self,
             ce_gpu_adapter_pref order_pref
  );
  
  /**
   * @brief add documentation here!
   * @param self add documentation here!
   * @param buffer add documentation here!
   * @param bufflen add documentation here!
   * @param index add documentation here!
   * @param out_len add documentation here!
   */
  ce_err (*get_gpu_adapters)(
    CE_IN      const ce_render_driver* CE_RESTRICT self,
    CE_OUT     ce_gpu_adapter*         CE_RESTRICT buffer,
               size_t                              bufflen,
               size_t                              index,
    CE_OUT_OPT size_t*                 CE_RESTRICT out_len
  );
  
  ce_err (*dev_create)(
    CE_IN  const ce_render_driver*   CE_RESTRICT self,
    CE_OUT ce_gpu_dev*               CE_RESTRICT out,
    CE_IN  const ce_dev_create_info* CE_RESTRICT info
  );
  
  void (*dev_destroy)(
    CE_IN    const ce_render_driver* self,
    CE_INOUT ce_gpu_dev dev
  );
};

struct ce_render_driver {
  const ce_render_driver_vfp* vfp;
  union {
  #ifdef CANVAS_ENABLE_VULKAN
    ice_vulkan_driver_data* vk;
  #endif
  #ifdef CANVAS_ENABLE_DIRECTX12
    ice_directx12_driver_data* dx12;
  #endif
  } data;
};

#ifdef CANVAS_ENABLE_VULKAN
typedef struct ce_vulkan_driver_create_info {
  const ce_utf8*     app_name;
  uint32_t           app_version;
  const ce_utf8*     engine_name;
  uint32_t           engine_version;
  const char* const* instance_layer_names;
  uint32_t           instance_layer_count;
  const char* const* instance_extension_names;
  uint32_t           instance_extension_count;
} ce_vulkan_driver_create_info;

CE_API ce_err ce_vulkan_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_vulkan_driver_create_info* info
);
#endif

#ifdef CANVAS_ENABLE_DIRECTX12
typedef struct ce_directx12_driver_create_info {
  cebool enable_debug;
} ce_directx12_driver_create_info;

CE_API ce_err ce_directx12_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_directx12_driver_create_info* info
);
#endif

CE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_DRIVER_H */
