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

#include "ivk_proto.h"

#if 0
ICE_API ce_err ivk_gpu_dev_get(
  CE_OUT ce_gpu_dev* CE_RESTRICT buffer,
  CE_IN  size_t                  buffer_size,
  CE_OUT size_t*     CE_RESTRICT opt_out_size
);

ICE_API void ivk_gpu_dev_release(
  CE_IN ce_gpu_dev gpu_dev
);

ICE_API ce_err ivk_dev_create(
  CE_OUT ce_dev* dev_out,
  CE_IN  const ce_dev_create_info* info
);

ICE_API void ivk_dev_delete(
  CE_IN ce_dev dev
);
#endif

#endif /* !IVK_DEV_H */
