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

#ifndef CANVAS_GRAPHICS_GRAPHICS_H
#define CANVAS_GRAPHICS_GRAPHICS_H

#include <canvas/core/error.h>

#ifndef CANVAS_GRAPHICS
#error the graphics module for CanvasEngine has been disabled
#endif

CE_NAMESPACE_BEGIN

#ifdef ICE_DOXY

typedef void* ice_win32_hwnd;
typedef void* ice_wl_surface;
typedef long ice_xlib_window;

/**
 * @brief
 *    A native handle to a OS window.
 *    The active member is dependent on the current OS and
 *    which windowing system is active/supported.
 */
typedef union ce_wnd_handle {
  ice_win32_hwnd win32;
  ice_wl_surface wl;
  ice_xlib_window xlib;
} ce_wnd_handle;

#else

#ifdef CANVAS_ENABLE_VULKAN
#define ICE_GX_VK_HANDLE(name) typedef struct name name;
#define ICE_GX_VK_ENABLE(x) x
#else
#define ICE_GX_VK_HANDLE(name)
#define ICE_GX_VK_ENABLE(x)
#endif

#ifdef CANVAS_ENABLE_DIRECTX12
#define ICE_GX_DX12_HANDLE(name) typedef struct name name;
#define ICE_GX_DX12_ENABLE(x) x
#else
#define ICE_GX_DX12_HANDLE(name)
#define ICE_GX_DX12_ENABLE(x)
#endif

#define ICE_GX_HANDLE(name) \
  ICE_GX_VK_HANDLE(i##name##_vk) \
  ICE_GX_DX12_HANDLE(i##name##_dx12) \
  typedef union name { \
    ICE_GX_VK_ENABLE(i##name##_vk* vk;) \
    ICE_GX_DX12_ENABLE(i##name##_dx12* dx12;) \
  } name

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

CE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_GRAPHICS_H */
