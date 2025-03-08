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

#include "icore_global.h"
#include <canvas/core/setup.h>

CE_API ce_err ce_core_set(const ce_core* ops) {
  return ISET_OPS(&icore_ops, ops);
}

#ifdef CANVAS_DEBUG
ICE_API cebool ideblog_enabled = cetrue;
CE_API void ce_disable_debug_logs(void) {
  ideblog_enabled = cefalse;
}
#endif /* !CANVAS_DEBUG */

ICE_API cebool ihas_initialized(void) {
  return icore.init_count != 0;
}

static void* s_defalloc(size_t bytes, void* arg) {
  (void)arg;
  return malloc(bytes);
}

static void s_deffree(void* addr, size_t bytes, void* arg) {
  (void)bytes;
  (void)arg;
  free(addr);
}

ICE_API ce_err icore_init(void) {
  /* Nothing to do here for now. */
  return CE_EOK;
}

ICE_API void icore_shutdown(void) {
  /* Nothing to do here for now. */
}

ICE_API ce_core icore_ops = {
  .app_name = {0},
  .app_version = 0,
  .engine_name = {0},
  .engine_version = 0,
};

ICE_API icore_t icore = {
  .init_count = 0,
  .mem = {
    .alloc = {
      .alloc = &s_defalloc,
      .free = &s_deffree,
      .user = NULL
    },
    .lck = CE_MTX_INIT_PLAIN
  }
};
