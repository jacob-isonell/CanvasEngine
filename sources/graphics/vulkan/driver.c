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

#include "ivk_load.h"
#include "icore_global.h"
#include "ivk_proto.h"
#include "ivk_dev.h"

struct ice_vulkan_driver_data {
  int unused;
};

static const ice_render_driver_vfp s_vfp = {
  .release = NULL,
  .fetch_gpu_devs = NULL,
  .get_gpu_dev = NULL
};

CE_API ce_err ce_vulkan_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_vulkan_driver_create_info* info
) {
  if (!ihas_initialized()) {
    return CE_EPERM;
  }
  
  if (driver == NULL || info == NULL) {
    return CE_EINVAL;
  }
  
  (void)info;
  
  ce_err e;
  driver->data.vk = (ice_vulkan_driver_data*)ialloc(sizeof(ice_vulkan_driver_data), &e);
  if (ce_failure(e)) {
    return e;
  }
  
  driver->data.vk->unused = 0;
  return CE_EOK;
}
