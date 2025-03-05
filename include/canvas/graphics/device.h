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

#ifndef CANVAS_GRAPHICS_DEVICE_H
#define CANVAS_GRAPHICS_DEVICE_H

#include <canvas/graphics/gpu_device.h>

ICE_NAMESPACE_BEGIN

ICE_FX_HANDLE(ce_dev);

typedef struct ce_dev_create_info {
  ce_gpu_dev* gpu_dev;
} ce_dev_create_info;

CE_API ce_err ce_dev_create(ce_dev** dev_out, const ce_dev_create_info* info);
CE_API void ce_dev_delete(ce_dev* dev);

ICE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_DEVICE_H */
