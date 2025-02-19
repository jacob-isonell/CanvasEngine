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

ICE_API extern VkInstance ivk_inst;
ICE_API ce_err ifxvk_init(void);
ICE_API void ifxvk_shutdown(void);

ICE_NAMESPACE_END

#endif /* !ICE_VULKAN */

#endif /* !IGRAPHICS_VULKAN_H */
