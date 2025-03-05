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

#undef ICE_FX_HANDLE

typedef enum ice_fx_type {
  ICEFX_VULKAN,
  ICEFX_DIRECTX12,
} ice_fx_type;

#define ICE_FX_DECL_HANDLE_VK(name) i##name##vk
#define ICE_FX_DECL_HANDLE_DX12(name) i##name##dx12

#define ICE_FX_HANDLE(name) \
typedef struct ICE_FX_DECL_HANDLE_VK(name) ICE_FX_DECL_HANDLE_VK(name); \
typedef struct ICE_FX_DECL_HANDLE_DX12(name) ICE_FX_DECL_HANDLE_DX12(name); \
typedef union name { \
  struct { \
    ice_fx_type type; \
    void* handle; \
  } common; \
  struct { \
    ice_fx_type type; \
    ICE_FX_DECL_HANDLE_VK(name)* handle; \
  } vk; \
  struct { \
    ice_fx_type type; \
    ICE_FX_DECL_HANDLE_DX12(name)* handle; \
  } dx12; \
} name

#ifndef ICE_DOXY

#ifdef CANVAS_EXPOSE_WIN32
typedef HWND ice_win32_hwnd;
#else
typedef void* ice_win32_hwnd;
#endif

#ifdef CANVAS_EXPOSE_WAYLAND
typedef struct wl_surface* ice_wl_surface;
#else
typedef void* ice_wl_surface;
#endif

#ifdef CANVAS_EXPOSE_X11
typedef Window ice_x11_window;
#else
typedef long ice_x11_window;
#endif

typedef union ce_wnd_handle {
#if CANVAS_PLATFORM_WINDOWS
  ice_win32_hwnd win32;
#else
#if CANVAS_ENABLE_WAYLAND
  ice_wl_surface wl;
#endif
#if CANVAS_ENABLE_X11
  ice_x11_window x11;
#endif
#endif
} ce_wnd_handle;

#endif
