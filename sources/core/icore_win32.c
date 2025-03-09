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
#if CANVAS_PLATFORM_WINDOWS

ICE_API const char* ice_win32err(DWORD errcode, DWORD langid) {
  char* buffer = NULL;
  char* out = NULL;
  FormatMessageA(
    FORMAT_MESSAGE_ALLOCATE_BUFFER
    | FORMAT_MESSAGE_FROM_SYSTEM
    | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, errcode, langid,
    (char*)&buffer, 0,
    NULL
  );
  
  if (buffer != NULL) {
    const size_t len = strlen(buffer);
    out = ialloc(len + 1, NULL);
    if (out) {
      strcpy(out, buffer);
    }
    LocalFree((HLOCAL)buffer);
  }
  return out;
}

ICE_API const wchar_t* ice_wwin32err(DWORD errcode, DWORD langid) {
  wchar_t* buffer = NULL;
  wchar_t* out = NULL;
  FormatMessageW(
    FORMAT_MESSAGE_ALLOCATE_BUFFER
    | FORMAT_MESSAGE_FROM_SYSTEM
    | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, errcode, langid,
    (wchar_t*)&buffer, 0,
    NULL
  );
  
  if (buffer != NULL) {
    const size_t len = wcslen(buffer);
    out = ialloc(len + 1, NULL);
    if (out) {
      wcscpy(out, buffer);
    }
    LocalFree((HLOCAL)buffer);
  }
  return out;
}

ICE_API ce_err ifrom_hres(HRESULT in) {
  switch (in) {
  default: return CE_EUNKNOWN;
  case S_OK: return CE_EOK;
  }
}

#endif /* !CANVAS_PLATFORM_WINDOWS */
