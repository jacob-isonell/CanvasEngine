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

#ifndef IFX_BASE_H
#define IFX_BASE_H

#include "icore_base.h"

#ifdef CANVAS_ENABLE_XLIB
#define VK_USE_PLATFORM_XLIB_KHR 1
#define VK_USE_PLATFORM_XCB_KHR 1
#define VK_USE_PLATFORM_XLIB_XRANDR_EXT 1
#include <X11/Xlib.h>
#endif

#ifdef CANVAS_ENABLE_WAYLAND
#define VK_USE_PLATFORM_WAYLAND_KHR 1
#include <wayland-client.h>
#endif

#if CANVAS_PLATFORM_WINDOWS
#define VK_USE_PLATFORM_WIN32_KHR 1
#endif

#include <canvas/graphics.h>

CE_NAMESPACE_BEGIN

ICE_API extern ce_graphics ifx_ops;
ICE_API ce_err ifx_init(void);
ICE_API void ifx_shutdown(void);

#define IFX_GET_VK_HANDLE(hndl) (ICE_ASSERT(hndl.type == ICEFX_VULKAN), hndl.handle.vk)
#define IFX_GET_DX12_HANDLE(hndl) (ICE_ASSERT(hndl.type == ICEFX_DIRECTX12), hndl.handle.dx12)

CE_NAMESPACE_END

#endif /* !IFX_BASE_H */
