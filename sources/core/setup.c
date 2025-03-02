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
  return iset_ops(&icore_ops, ops, sizeof(*ops));
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
  if (icore_ops.app_name) {
    ce_err e;
    icore.app_info.name = ce_alloc_s(strlen(icore_ops.app_name), &e);
    strcpy(icore.app_info.name, icore_ops.app_name);
    if (ce_failure(e)) {
      return e;
    }
  }
  
  if (icore_ops.engine_name) {
    ce_err e;
    icore.engine_info.name = ce_alloc_s(strlen(icore_ops.engine_name), &e);
    strcpy(icore.engine_info.name, icore_ops.engine_name);
    if (ce_failure(e)) {
      return e;
    }
  }
  
  icore.app_info.version = icore_ops.app_version;
  icore.engine_info.version = icore_ops.engine_version;
  return CE_EOK;
}

ICE_API void icore_shutdown(void) {
  if (icore.app_info.name) {
    ce_free(icore.app_info.name);
    icore.app_info.name = NULL;
  }
  
  if (icore.engine_info.name) {
    ce_free(icore.engine_info.name);
    icore.engine_info.name = NULL;
  }
}

ICE_API ce_core icore_ops = {
  .app_name = NULL,
  .app_version = 0,
  .engine_name = NULL,
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
