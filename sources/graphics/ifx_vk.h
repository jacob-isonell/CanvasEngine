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

#ifndef IGRAPHICS_VULKAN_H
#define IGRAPHICS_VULKAN_H

#include "ifx_base.h"

#ifdef ICE_VULKAN

#include <vulkan/vulkan.h>

ICE_NAMESPACE_BEGIN

#define IVK_CURRVER VK_HEADER_VERSION_COMPLETE
#define IVK_MINVER VK_MAKE_API_VERSION(0, 1, 3, 0)

/* Used to fill in a `VkAllocationCallbacks*` function argument. Currently just `NULL` */
#define IVK_ALLOC NULL
ICE_API extern VkInstance ivk_inst;

ICE_API ce_err ivk_init(void);
ICE_API void ivk_shutdown(void);

ICE_API ce_err ifrom_vk(VkResult res);

ICE_NAMESPACE_END

#endif /* !ICE_VULKAN */

#endif /* !IGRAPHICS_VULKAN_H */
