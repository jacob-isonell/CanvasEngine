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

static size_t s_copy_narrow(char* dest, const char* src, size_t len) {
  size_t n = 0;
  while (len) {
    switch (*src) {
    case '\n':
    case '\r':
      break;
    case '%':
      ++src;
    default:
      *dest = *src;
      ++dest;
      ++n;
      break;
    }
    --len;
    ++src;
  }
  *dest = '\0';
  return n;
}

static size_t s_copy_wide(wchar_t* dest, const wchar_t* src, size_t len) {
  size_t n = 0;
  while (len) {
    switch (*src) {
    case L'\n':
    case L'\r':
      break;
    case L'%':
      ++src;
    default:
      *dest = *src;
      ++dest;
      ++n;
      break;
    }
    --len;
    ++src;
  }
  *dest = L'\0';
  return n;
}

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
    out = ce_alloc(len + 1);
    if (out) {
      s_copy_narrow(out, buffer, len);
    }
    LocalFree((HLOCAL)buffer);
  }
  return out;
}

ICE_API size_t ice_win32err_s(
  char* buff,
  size_t bufflen,
  DWORD errcode,
  DWORD langid
) {
  char* msg = NULL;
  FormatMessageA(
    FORMAT_MESSAGE_ALLOCATE_BUFFER
    | FORMAT_MESSAGE_FROM_SYSTEM
    | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, errcode, langid,
    (char*)&msg, 0,
    NULL
  );
  
  if (msg != NULL) {
    const size_t maxlen = strlen(msg);
    if (buff == NULL) {
      LocalFree((HLOCAL)msg);
      return maxlen;
    }
    
    const size_t len = bufflen < maxlen
      ? bufflen
      : maxlen;
    
    const size_t out = s_copy_narrow(buff, msg, len);
    LocalFree((HLOCAL)msg);
    return out;
  }
  
  IDEBWARN("Failed to get Win32 message\n");
  return SIZE_MAX;
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
    out = ce_alloc(len + 1);
    if (out) {
      s_copy_wide(out, buffer, len);
    }
    LocalFree((HLOCAL)buffer);
  }
  return out;
}

ICE_API size_t ice_wwin32err_s(
  wchar_t* buff,
  size_t bufflen,
  DWORD errcode,
  DWORD langid
) {
  wchar_t* msg = NULL;
  FormatMessageW(
    FORMAT_MESSAGE_ALLOCATE_BUFFER
    | FORMAT_MESSAGE_FROM_SYSTEM
    | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, errcode, langid,
    (wchar_t*)&msg, 0,
    NULL
  );
  
  if (msg != NULL) {
    const size_t maxlen = wcslen(msg);
    if (buff == NULL) {
      LocalFree((HLOCAL)msg);
      return maxlen;
    }
    
    const size_t len = bufflen < maxlen
      ? bufflen
      : maxlen;
    
    const size_t out = s_copy_wide(buff, msg, len);
    LocalFree((HLOCAL)msg);
    return out;
  }
  
  IDEBWARN("Failed to get Win32 message\n");
  return SIZE_MAX;
}

ICE_API ce_err ifrom_hres(HRESULT in) {
  if (SUCCEEDED(in)) {
    return CE_EOK;
  }
  
  switch (in) {
  default: return CE_EUNKNOWN;
  }
}

#endif /* !CANVAS_PLATFORM_WINDOWS */
