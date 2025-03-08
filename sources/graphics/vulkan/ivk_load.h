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

#ifndef IVK_LOAD_H
#define IVK_LOAD_H

#include "ifx_vk.h"

CE_NAMESPACE_BEGIN

#if CANVAS_PLATFORM_WINDOWS
#define IVK_DLL_FILE "vulkan-1.dll"
#elif CANVAS_PLATFORM_UNIX
#define IVK_DLL_FILE "libvulkan.so.1"
#endif

ICE_API ce_err ivk_load_global(void);
ICE_API ce_err ivk_load(VkInstance inst);
ICE_API void ivk_unload(void);

ICE_API extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;

CE_NAMESPACE_END

#endif /* !IVK_LOAD_H */
