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
  return iset_ops(&ifx_ops, ops, sizeof(*ops));
}

ICE_API ce_err ifx_init(void) {
  IERRBEGIN {
    IERRDO(ivk_init());
  } IERREND { }
  return IERRVAL;
}

ICE_API void ifx_shutdown(void) {
  ivk_shutdown();
}

ICE_API ce_graphics ifx_ops = {
  .vulkan = {
    .inst_layers = NULL,
    .inst_layers_len = 0,
    .inst_exts = NULL,
    .inst_exts_len = 0,
  }
};
