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

#ifdef CANVAS_ENABLE_VULKAN
#define ICE_FX_HANDLE_VK(name) i##name##vk
#define ICE_FX_DECL_HANDLE_VK(name) \
  typedef struct ICE_FX_HANDLE_VK(name) ICE_FX_HANDLE_VK(name);
#define ICE_VK_ENABLEX(x) x
#define ICE_VK_ENABLE(x) ICE_VK_ENABLEX(x)
#else
#define ICE_FX_HANDLE_VK(name)
#define ICE_FX_DECL_HANDLE_VK(name)
#define ICE_VK_ENABLEX(x)
#define ICE_VK_ENABLE(x) ICE_VK_ENABLEX(x)
#endif

#ifdef CANVAS_ENABLE_DIRECTX12
#define ICE_FX_HANDLE_DX12(name) i##name##dx12
#define ICE_FX_DECL_HANDLE_DX12(name) \
  typedef struct ICE_FX_HANDLE_DX12(name) ICE_FX_HANDLE_DX12(name);
#define ICE_DX12_ENABLEX(x) x
#define ICE_DX12_ENABLE(x) ICE_DX12_ENABLEX(x)
#else
#define ICE_FX_HANDLE_DX12(name)
#define ICE_FX_DECL_HANDLE_DX12(name)
#define ICE_DX12_ENABLEX(x)
#define ICE_DX12_ENABLE(x) ICE_DX12_ENABLEX(x)
#endif

#define ICE_FX_HANDLE(name) \
ICE_FX_DECL_HANDLE_VK(name) \
ICE_FX_DECL_HANDLE_DX12(name) \
typedef struct name { \
  ice_fx_type type; \
  union { \
    ICE_VK_ENABLE(ICE_FX_HANDLE_VK(name)* vk;) \
    ICE_DX12_ENABLE(ICE_FX_HANDLE_DX12(name)* dx12;) \
    void* common; \
  } handle; \
} name

#ifndef ICE_DOCS

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

#ifdef CANVAS_EXPOSE_XLIB
typedef Window ice_xlib_window;
#else
typedef long ice_xlib_window;
#endif

typedef union ce_wnd_handle {
#if CANVAS_PLATFORM_WINDOWS
  ice_win32_hwnd win32;
#else
#ifdef CANVAS_ENABLE_WAYLAND
  ice_wl_surface wl;
#endif
#ifdef CANVAS_ENABLE_XLIB
  ice_xlib_window xlib;
#endif
#endif
} ce_wnd_handle;

#endif
