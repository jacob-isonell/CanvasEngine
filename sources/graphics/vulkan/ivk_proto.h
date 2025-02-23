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

#ifndef IGRAPHICS_VULKAN_PROTO_H
#define IGRAPHICS_VULKAN_PROTO_H

#include "ifx_vk.h"

ICE_NAMESPACE_BEGIN

#undef IVK_PROTO_MACRO
#undef IVK_PROTO_DECL
#undef IVK_PROTO_NO_UNDEF

#include "ivk_proto/global.inl"
#include "ivk_proto/1.0.inl"
#include "ivk_proto/1.1.inl"
#include "ivk_proto/1.2.inl"
#include "ivk_proto/1.3.inl"
#include "ivk_proto/1.4.inl"

#ifdef CANVAS_DEBUG
ICE_API void ivk_impl_check_pfn_value(
	cebool       is_empty,
	const char*  name,
	const char*  func,
	const char*  file,
	unsigned int line
);
#else
#define ivk_impl_check_pfn_value(...) ((void)(__VA_ARGS__))
#endif /* !CANVAS_DEBUG */

#define IVK_PROTO_DECL(name) \
	ICE_API extern PFN_##name ice_##name; \
	ICE_INLINE PFN_##name ice_get_##name(const char* func, const char* file, unsigned int line) { \
		ivk_impl_check_pfn_value(ice_##name == NULL, #name, func, file, line); \
		return ice_##name; \
	}

#include "ivk_proto/global.inl"
#include "ivk_proto/1.0.inl"
#ifdef VK_API_VERSION_1_1
#include "ivk_proto/1.1.inl"
#endif /* !VK_API_VERSION_1_1 */
#ifdef VK_API_VERSION_1_2
#include "ivk_proto/1.2.inl"
#endif /* !VK_API_VERSION_1_2 */
#ifdef VK_API_VERSION_1_3
#include "ivk_proto/1.3.inl"
#endif /* !VK_API_VERSION_1_3 */
#ifdef VK_API_VERSION_1_4
#include "ivk_proto/1.4.inl"
#endif /* !VK_API_VERSION_1_4 */

#define IVK_PROTO_MACRO(name) ice_get_##name(__func__, __FILE__, __LINE__)

#include "ivk_proto/global.inl"
#include "ivk_proto/1.0.inl"
#ifdef VK_API_VERSION_1_1
#include "ivk_proto/1.1.inl"
#endif /* !VK_API_VERSION_1_1 */
#ifdef VK_API_VERSION_1_2
#include "ivk_proto/1.2.inl"
#endif /* !VK_API_VERSION_1_2 */
#ifdef VK_API_VERSION_1_3
#include "ivk_proto/1.3.inl"
#endif /* !VK_API_VERSION_1_3 */
#ifdef VK_API_VERSION_1_4
#include "ivk_proto/1.4.inl"
#endif /* !VK_API_VERSION_1_4 */

#undef IVK_PROTO_DECL
#undef IVK_PROTO_NO_UNDEF

ICE_NAMESPACE_END

#endif /* !IGRAPHICS_VULKAN_PROTO_H */
