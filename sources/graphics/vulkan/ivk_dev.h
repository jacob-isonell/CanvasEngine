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

#ifndef IVK_DEV_H
#define IVK_DEV_H

#include "ivk_protos.h"

struct ice_gpu_dev_vk {
  VkDevice handle;
};

ICE_API
ce_err ivk_dev_create(
  CE_IN  const ce_render_driver*   CE_RESTRICT self,
  CE_OUT ce_gpu_dev*               CE_RESTRICT out,
  CE_IN  const ce_dev_create_info* CE_RESTRICT info
);

ICE_API
void ivk_dev_destroy(
  CE_IN    const ce_render_driver* self,
  CE_INOUT ce_gpu_dev dev
);

#endif /* !IVK_DEV_H */
