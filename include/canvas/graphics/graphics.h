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

typedef enum ce_render_api {
  CE_VULKAN,
  CE_DIRECTX12,
} ce_render_api;

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
#endif

#include <canvas/graphics/details/graphics.inl>

ICE_NAMESPACE_END

#endif /* !CANVAS_GRAPHICS_GRAPHICS_H */
