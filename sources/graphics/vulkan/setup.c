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

#include "ivk_load.h"
#include "icore_global.h"
#include "ivk_proto.h"
#include <canvas/core/library.h>
#include <inttypes.h>

ICE_API VkInstance ivk_inst = VK_NULL_HANDLE;

static ce_err s_create_instance(void);

ICE_API ce_err ivk_init(void) {
	IERRBEGIN {
		IDEBLOG("Loading global vulkan commands\n");
		IERRDO(ivk_load_global());
		
		uint32_t vkver;
		IERRDO(ifrom_vk(vkEnumerateInstanceVersion(&vkver)));
		if (vkver < IVK_MINVER) {
			IDEBERROR(
				"Current loaded vulkan version is v%u.%u.%u.%u but CanvasEngine requires at least v0.1.3.0\n",
				VK_API_VERSION_VARIANT(vkver),
				VK_API_VERSION_MAJOR(vkver),
				VK_API_VERSION_MINOR(vkver),
				VK_API_VERSION_PATCH(vkver)
			);
			return CE_EDRIVER;
		}
		
		IDEBLOG("Creating vulkan instance\n");
		IERRDO(s_create_instance());
		
		IDEBLOG("Loading vulkan commands\n");
		IERRDO(ivk_load(ivk_inst));
	} IERREND { }
	return IERRVAL;
}

ICE_API void ivk_shutdown(void) {
	if (ivk_inst != NULL) {
		vkDestroyInstance(ivk_inst, IVK_ALLOC);
	}
	ivk_inst = NULL;
	
	ivk_unload();
}

static ce_err s_create_instance(void) {
	IERRBEGIN {
		VkApplicationInfo app_info;
		app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app_info.pNext = NULL;
		app_info.pApplicationName = icore.app_info.name;
		app_info.applicationVersion = icore.app_info.version;
		app_info.pEngineName = icore.engine_info.name;
		app_info.engineVersion = icore.engine_info.version;
		app_info.apiVersion = VK_API_VERSION_1_0;
		
		VkInstanceCreateInfo inst_info;
		inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		inst_info.pNext = NULL;
		inst_info.flags = 0;
		inst_info.pApplicationInfo = &app_info;
		inst_info.enabledLayerCount = 0;
		inst_info.ppEnabledLayerNames = NULL;
		inst_info.enabledExtensionCount = 0;
		inst_info.ppEnabledExtensionNames = NULL;
		
		IERRDO(ifrom_vk(vkCreateInstance(&inst_info, IVK_ALLOC, &ivk_inst)));
		
	} IERREND {
	#ifdef CANVAS_DEBUG
		if (ivk_inst && !ivk_has(vkDestroyInstance)) {
			IDEBWARN("VkInstance was created but cannot be destroyed with vkDestroyInstance\n");
		}
	#endif
		
		if (ivk_inst && ivk_has(vkDestroyInstance)) {
			vkDestroyInstance(ivk_inst, IVK_ALLOC);
			ivk_inst = NULL;
		}
	}
	return IERRVAL;
}

ICE_API ce_err ifrom_vk(VkResult res) {
	switch (res) {
	case VK_SUCCESS:
	case VK_NOT_READY:
	case VK_TIMEOUT:
	case VK_EVENT_SET:
	case VK_EVENT_RESET:
	case VK_INCOMPLETE:
	case VK_PIPELINE_COMPILE_REQUIRED:
	case VK_SUBOPTIMAL_KHR:
	case VK_THREAD_IDLE_KHR:
	case VK_THREAD_DONE_KHR:
	case VK_OPERATION_DEFERRED_KHR:
	case VK_OPERATION_NOT_DEFERRED_KHR:
	case VK_INCOMPATIBLE_SHADER_BINARY_EXT:
	case VK_PIPELINE_BINARY_MISSING_KHR:
		return CE_EOK;
	
	default: return CE_EUNKNOWN;
	case VK_ERROR_OUT_OF_HOST_MEMORY: return CE_ENOMEM;
	case VK_ERROR_OUT_OF_DEVICE_MEMORY: return CE_ENOMEM;
	case VK_ERROR_INITIALIZATION_FAILED: return CE_EINIT;
	case VK_ERROR_DEVICE_LOST: return CE_ENODEV;
	case VK_ERROR_MEMORY_MAP_FAILED: return CE_EFAIL;
	case VK_ERROR_LAYER_NOT_PRESENT: return CE_EVKLAYER;
	case VK_ERROR_EXTENSION_NOT_PRESENT: return CE_EVKEXT;
	case VK_ERROR_FEATURE_NOT_PRESENT: return CE_EVKFEAT;
	case VK_ERROR_INCOMPATIBLE_DRIVER: return CE_EDRIVER;
	case VK_ERROR_TOO_MANY_OBJECTS: return CE_EOBJECTS;
	case VK_ERROR_FORMAT_NOT_SUPPORTED: return CE_EFORMAT;
	case VK_ERROR_FRAGMENTED_POOL: return CE_EFRAG;
	case VK_ERROR_OUT_OF_POOL_MEMORY: return CE_ENOMEM;
	case VK_ERROR_INVALID_EXTERNAL_HANDLE: return CE_EINVAL;
	case VK_ERROR_FRAGMENTATION: return CE_EFRAG;
	case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: return CE_EFAULT;
	case VK_ERROR_SURFACE_LOST_KHR: return CE_ELOST;
	case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return CE_EBUSY;
	case VK_ERROR_OUT_OF_DATE_KHR: return CE_EUNKNOWN;
	case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return CE_EUNKNOWN;
	case VK_ERROR_VALIDATION_FAILED_EXT: return CE_EUNKNOWN;
	case VK_ERROR_INVALID_SHADER_NV: return CE_EUNKNOWN;
	case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR: return CE_EUNKNOWN;
	case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR: return CE_EUNKNOWN;
	case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR: return CE_EUNKNOWN;
	case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR: return CE_EUNKNOWN;
	case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR: return CE_EUNKNOWN;
	case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR: return CE_EUNKNOWN;
	case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return CE_EUNKNOWN;
	case VK_ERROR_NOT_PERMITTED_KHR: return CE_EPERM;
	case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: return CE_EUNKNOWN;
	case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR: return CE_EUNKNOWN;
	case VK_ERROR_COMPRESSION_EXHAUSTED_EXT: return CE_EUNKNOWN;
	case VK_ERROR_NOT_ENOUGH_SPACE_KHR: return CE_EUNKNOWN;
	}
}
