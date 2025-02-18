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

#ifndef CANVAS_GRAPHICS_GPU_DEVICE_H
#define CANVAS_GRAPHICS_GPU_DEVICE_H

#include <canvas/graphics/graphics.h>

ICE_NAMESPACE_BEGIN

struct ce_gpu_dev;

struct ce_gpy_dev_props {
	char name[256];
	ce_ul32 driver_version;
};

CE_API size_t ce_gpu_dev_get(struct ce_gpu_dev** buffer, size_t buffer_size);

ICE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_GPU_DEVICE_H */
