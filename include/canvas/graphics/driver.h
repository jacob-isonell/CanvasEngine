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

#include <canvas/core/error.h>

CE_NAMESPACE_BEGIN

typedef struct ce_gpu_dev ce_gpu_dev;

typedef struct ce_render_driver ce_render_driver;

typedef struct ice_render_driver_vfp ice_render_driver_vfp;

#ifdef CANVAS_ENABLE_VULKAN
typedef struct ice_vulkan_driver_data ice_vulkan_driver_data;
#endif
#ifdef CANVAS_ENABLE_DIRECTX12
typedef struct ice_directx12_driver_data ice_directx12_driver_data;
#endif

struct ice_render_driver_vfp {
  void (*release)(
    CE_INOUT ce_render_driver* self
  );
  
  ce_err (*fetch_gpu_devs)(
    CE_INOUT ce_render_driver* self
  );
  
  ce_err (*get_gpu_dev)(
    CE_IN  const ce_render_driver* self,
    CE_OUT ce_gpu_dev** out
  );
};

struct ce_render_driver {
  union {
  #ifdef CANVAS_ENABLE_VULKAN
    ice_vulkan_driver_data* vk;
  #endif
  #ifdef CANVAS_ENABLE_DIRECTX12
    ice_directx12_driver_data* dx12;
  #endif
  } data;
  const ice_render_driver_vfp* vfp;
};

#ifdef CANVAS_ENABLE_VULKAN
typedef struct ce_vulkan_driver_create_info {
  int unused;
} ce_vulkan_driver_create_info;

CE_API ce_err ce_vulkan_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_vulkan_driver_create_info* info
);
#endif

#ifdef CANVAS_ENABLE_DIRECTX12
typedef struct ce_directx12_driver_create_info {
  int unused;
} ce_directx12_driver_create_info;

CE_API ce_err ce_directx12_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_directx12_driver_create_info* info
);
#endif

CE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_DRIVER_H */
