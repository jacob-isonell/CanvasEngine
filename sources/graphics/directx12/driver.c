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

#include "ifx_dx12.h"

struct ice_directx12_driver_data {
  IDXGIFactory* fact;
};

static void irelease_driver(
  CE_INOUT ce_render_driver* self
) {
  ifree(self->data.dx12, sizeof(*(self->data.dx12)));
  *self = (ce_render_driver) {0};
}

static const ice_render_driver_vfp s_vfp = {
  .release = &irelease_driver,
  .fetch_gpu_devs = NULL,
  .get_gpu_dev = NULL
};

CE_API ce_err ce_directx12_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_directx12_driver_create_info* info
) {
  if (driver == NULL || info == NULL) {
    return CE_EINVAL;
  }
  
  IDXGIFactory7* p = NULL;
  
  IERRBEGIN {
    IERRDO(ifrom_hres(CreateDXGIFactory2(0, IDX_UUIDOF(p), (void**)&p)));
  } IERREND {
    
  }
  
  if (p != NULL) {
    p->lpVtbl->Release(p);
  }
  return IERRVAL;
}
