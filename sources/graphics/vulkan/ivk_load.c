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

#include "ivk_proto.h"
#include "ivk_load.h"
#include <canvas/core/library.h>

#ifndef VK_API_VERSION_1_0
#	error VK_API_VERSION_1_0 is not defined. Check your install of the VulkanSDK
#endif

ICE_API PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = NULL;
static struct ce_lib* ivulkan_lib = NULL;

#undef IVK_PROTO_MACRO
#undef IVK_PROTO_DECL

#include "ivk_proto/all.inl"

#define IVK_PROTO_DECL(name) \
	static ce_err iload_##name(VkInstance inst) { \
		union { \
			PFN_vkVoidFunction in; \
			PFN_##name out; \
		} cast; \
		cast.in = vkGetInstanceProcAddr(inst, #name); \
		if (cast.in == NULL) { \
			IDEBERROR("Failed to load \"" #name "\"\n"); \
			return CE_ENODATA; \
		} \
		IDEBLOG("Loaded \"" #name "\"\n"); \
		ice_##name = cast.out; \
		return CE_EOK; \
	}

#include "ivk_proto/all.inl"

static ce_err iload_global(void);
static ce_err iload_1_0(VkInstance inst);

#ifdef VK_API_VERSION_1_1
static ce_err iload_1_1(VkInstance inst);
#else
#define iload_1_1() CE_EOK
#endif /* !VK_API_VERSION_1_1 */

#ifdef VK_API_VERSION_1_2
static ce_err iload_1_2(VkInstance inst);
#else
#define iload_1_2() CE_EOK
#endif /* !VK_API_VERSION_1_2 */

#ifdef VK_API_VERSION_1_3
static ce_err iload_1_3(VkInstance inst);
#else
#define iload_1_3() CE_EOK
#endif /* !VK_API_VERSION_1_3 */

#ifdef VK_API_VERSION_1_4
static ce_err iload_1_4(VkInstance inst);
#else
#define iload_1_4() CE_EOK
#endif /* !VK_API_VERSION_1_4 */

ICE_API ce_err ivk_load_global(void) {
	IERRBEGIN {
		union {
			PFN_vkVoidFunction in;
			PFN_vkGetInstanceProcAddr out;
		} cast;
		
		IERRDO(ce_lib_open(&ivulkan_lib, IVK_DLL_FILE, CE_LIB_FLAG_NONE));
		
		IERRDO(ce_lib_load(ivulkan_lib, "vkGetInstanceProcAddr", &cast.in));
		vkGetInstanceProcAddr = cast.out;
		
		return iload_global();
	} IERREND { }
	return IERRVAL;
}

ICE_API ce_err ivk_load(VkInstance inst) {
	IERRBEGIN {
		ICE_ASSERT(vkGetInstanceProcAddr != NULL);
		
		IDEBLOG("Loading vulkan 1.0 commands\n"); IERRDO(iload_1_0(inst));
		IDEBLOG("Loading vulkan 1.1 commands\n"); IERRDO(iload_1_1(inst));
		IDEBLOG("Loading vulkan 1.2 commands\n"); IERRDO(iload_1_2(inst));
		IDEBLOG("Loading vulkan 1.3 commands\n"); IERRDO(iload_1_3(inst));
		IDEBLOG("Loading vulkan 1.4 commands\n"); IERRDO(iload_1_4(inst));
	} IERREND { }
	return IERRVAL;
}

ICE_API void ivk_unload(void) {
	ce_lib_close(ivulkan_lib);
	ivulkan_lib = NULL;
}

#define LOAD(name) IERRDO(iload_##name(VK_NULL_HANDLE))
#undef IVK_PROTO_DECL
#define IVK_PROTO_DECL(name) LOAD(name);

static ce_err iload_global(void) {
	IERRBEGIN {
#include "ivk_proto/global.inl"
	} IERREND { }
	return IERRVAL;
}

#undef LOAD
#define LOAD(name) IERRDO(iload_##name(inst))
static ce_err iload_1_0(VkInstance inst) {
	IERRBEGIN {
#include "ivk_proto/1.0.inl"
	} IERREND { }
	return IERRVAL;
}

/* Temporary */
ICE_WARN_DISABLE_MSVC(4102)
ICE_WARN_DISABLE_GNU("-Wunused-label")
ICE_WARN_DISABLE_GNU("-Wunused-parameter")

#ifdef VK_API_VERSION_1_1
static ce_err iload_1_1(VkInstance inst) {
	IERRBEGIN {
#include "ivk_proto/1.1.inl"
	} IERREND { }
	return IERRVAL;
}
#endif /* !VK_API_VERSION_1_1 */

#ifdef VK_API_VERSION_1_2
static ce_err iload_1_2(VkInstance inst) {
	IERRBEGIN {
#include "ivk_proto/1.2.inl"
	} IERREND { }
	return IERRVAL;
}
#endif /* !VK_API_VERSION_1_2 */

#ifdef VK_API_VERSION_1_3
static ce_err iload_1_3(VkInstance inst) {
	IERRBEGIN {
#include "ivk_proto/1.3.inl"
	} IERREND { }
	return IERRVAL;
}
#endif /* !VK_API_VERSION_1_3 */

#ifdef VK_API_VERSION_1_4
static ce_err iload_1_4(VkInstance inst) {
	IERRBEGIN {
#include "ivk_proto/1.4.inl"
	} IERREND { }
	return IERRVAL;
}
#endif /* !VK_API_VERSION_1_4 */
