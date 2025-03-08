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

#include "ifx_base.h"
#include "ifx_vk.h"
#include "icore_global.h"

CE_API ce_err ce_graphics_set(const ce_graphics* ops) {
  return ISET_OPS(&ifx_ops, ops);
}

#ifdef CANVAS_ENABLE_VULKAN

#define IVK_SHUTDOWN() ivk_shutdown()
static ce_err s_init_vk(void) {
  IERRBEGIN {
    IERRDO(ivk_init());
  } IERREND { }
  return IERRVAL;
}

#else

#define IVK_SHUTDOWN() ((void)0)
static ce_err s_init_vk(void) {
  return CE_ENOTSUP;
}

#endif

#ifdef CANVAS_ENABLE_DIRECTX12

#define IDX12_SHUTDOWN() ivk_shutdown()
static ce_err s_init_dx12(void) {
  return CE_NOSYS;
}

#else

#define IDX12_SHUTDOWN() ((void)0)
static ce_err s_init_dx12(void) {
  return CE_ENOTSUP;
}

#endif

ICE_API ce_err ifx_init(void) {
  switch (ifx_ops.render_api) {
  default: return CE_EINVAL;
  case CE_VULKAN:    return s_init_vk();
  case CE_DIRECTX12: return s_init_dx12();
  }
}

ICE_API void ifx_shutdown(void) {
  switch (ifx_ops.render_api) {
  default: return;
  case CE_VULKAN:    IVK_SHUTDOWN(); break;
  case CE_DIRECTX12: IDX12_SHUTDOWN(); break;
  }
}

ICE_API ce_graphics ifx_ops = {
  .render_api = CE_VULKAN,
  .vulkan = {
    .inst_layers = NULL,
    .inst_layers_len = 0,
    .inst_exts = NULL,
    .inst_exts_len = 0,
  }
};
