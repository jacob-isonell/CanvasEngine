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

ICE_NAMESPACE_BEGIN

typedef struct ce_vk_layer_str {
  ce_utf8 name[256];
} ce_vk_layer_str;

typedef struct ce_vk_ext_str {
  ce_utf8 name[256];
} ce_vk_ext_str;

#define ICE_FXHANDLE(name) typedef struct name name

#ifdef ICE_DOXY
typedef void* ice_win32_hwnd;
typedef void* ice_wl_surface;
typedef long ice_x11_window;

/**
 * @brief
 *    A native handle to a OS window.
 *    The active member is dependent on the current OS and
 *    which windowing system is active/supported.
 */
typedef union ce_wnd_handle {
  ice_win32_hwnd win32;
  ice_wl_surface wl;
  ice_x11_window x11;
} ce_wnd_handle;
#else

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

ICE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_GRAPHICS_H */
