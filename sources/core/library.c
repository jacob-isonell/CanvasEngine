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

#include "icore_base.h"
#include <canvas/core/library.h>

#if CANVAS_PLATFORM_UNIX
#include <dlfcn.h>
#endif

CE_API ce_err ce_lib_open(
  CE_OUT ce_lib**       CE_RESTRICT handle,
  CE_IN  const ce_utf8* CE_RESTRICT filepath,
         ce_lib_flags               flags
) {
  (void)flags;
  if (handle == NULL || filepath == NULL) {
    return CE_EINVAL;
  }
  
#if CANVAS_PLATFORM_WINDOWS
  
  const HMODULE mod = LoadLibraryExA(filepath, NULL, 0);
  if (mod == NULL) {
    return CE_EFAULT;
  }
  
#elif CANVAS_PLATFORM_UNIX
  
  void* const mod = dlopen(filepath, RTLD_NOW | RTLD_GLOBAL);
  if (mod == NULL) {
    IDEBERROR("dlopen failed (\"%s\")\n", dlerror());
    return CE_ENOENT;
  }
  
#endif
  
  *handle = (ce_lib*)mod;
  return CE_EOK;
}

CE_API ce_err ce_lib_load(
  CE_IN  ce_lib*        CE_RESTRICT handle,
  CE_IN  const ce_utf8* CE_RESTRICT name,
  CE_OUT void*          CE_RESTRICT out
) {
  if (handle == NULL || name == NULL || out == NULL) {
    return CE_EINVAL;
  }
  
#if CANVAS_PLATFORM_WINDOWS
  
  FARPROC p = GetProcAddress((HMODULE)handle, name);
  if (p == NULL) {
    return CE_ENODATA;
  }
  
#elif CANVAS_PLATFORM_UNIX
  
  (void)dlerror(); /* Clear previous error; */
  
  void* const p = dlsym((void*)handle, name);
  const char* const errstr = dlerror();
  
  if (errstr != NULL) {
    IDEBERROR("dlclose failed (\"%s\")\n", errstr);
    return CE_ENOENT;
  }
  
#endif
  
  memcpy(out, &p, sizeof(void*));
  return CE_EOK;
}

CE_API void ce_lib_close(
  CE_IN ce_lib* handle
) {
  if (handle == NULL) {
    return;
  }
  
#if CANVAS_PLATFORM_WINDOWS
  
  FreeLibrary((HMODULE)handle);
  
#elif CANVAS_PLATFORM_UNIX
  
#if CANVAS_DEBUG
  if (dlclose(handle) != 0) {
    fprintf(stderr, "dlclose failed (\"%s\")\n", dlerror());
  }
#else
  dlclose(handle);
#endif
  
#endif
}
