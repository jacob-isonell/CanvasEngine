/**
 * @file error.hpp
 * @author Jacob Isonell (isonelljacob@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-09
 * 
 * @copyright Copyright (c) 2025
 * 
 * CanvasEngine is a cross platform multimedia library in C89
 * Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <canvas/graphics/vulkan.hpp>
#include <vulkan/vulkan.hpp>

ICANVAS_NAMESPACE_GRAPHICS_VULKAN_BEGIN

constexpr err vkresult_to_err(VkResult res) noexcept {
	switch (res) {
	default:
		return err::eunknown;
	case VK_SUCCESS:
		return err::eok;
	case VK_NOT_READY:
		return err::eok;
	case VK_TIMEOUT:
		return err::eok;
	case VK_EVENT_SET:
		return err::eok;
	case VK_EVENT_RESET:
		return err::eok;
	case VK_INCOMPLETE:
		return err::eok;
	case VK_ERROR_OUT_OF_HOST_MEMORY:
		return err::enomem;
	case VK_ERROR_OUT_OF_DEVICE_MEMORY:
		return err::enomem;
	case VK_ERROR_INITIALIZATION_FAILED:
		return err::eunknown;
	case VK_ERROR_DEVICE_LOST:
		return err::eunknown;
	case VK_ERROR_MEMORY_MAP_FAILED:
		return err::eunknown;
	case VK_ERROR_LAYER_NOT_PRESENT:
		return err::eunknown;
	case VK_ERROR_EXTENSION_NOT_PRESENT:
		return err::eunknown;
	case VK_ERROR_FEATURE_NOT_PRESENT:
		return err::eunknown;
	case VK_ERROR_INCOMPATIBLE_DRIVER:
		return err::eunknown;
	case VK_ERROR_TOO_MANY_OBJECTS:
		return err::eunknown;
	case VK_ERROR_FORMAT_NOT_SUPPORTED:
		return err::eunknown;
	case VK_ERROR_FRAGMENTED_POOL:
		return err::eunknown;
	case VK_ERROR_UNKNOWN:
		return err::eunknown;
	case VK_ERROR_OUT_OF_POOL_MEMORY:
		return err::eunknown;
	case VK_ERROR_INVALID_EXTERNAL_HANDLE:
		return err::eunknown;
	case VK_ERROR_FRAGMENTATION:
		return err::eunknown;
	case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
		return err::eunknown;
	case VK_PIPELINE_COMPILE_REQUIRED:
		return err::eunknown;
	case VK_ERROR_NOT_PERMITTED:
		return err::eunknown;
	case VK_ERROR_SURFACE_LOST_KHR:
		return err::eunknown;
	case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
		return err::eunknown;
	case VK_SUBOPTIMAL_KHR:
		return err::eunknown;
	case VK_ERROR_OUT_OF_DATE_KHR:
		return err::eunknown;
	case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
		return err::eunknown;
	case VK_ERROR_VALIDATION_FAILED_EXT:
		return err::eunknown;
	case VK_ERROR_INVALID_SHADER_NV:
		return err::eunknown;
	case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR:
		return err::eunknown;
	case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR:
		return err::eunknown;
	case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR:
		return err::eunknown;
	case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR:
		return err::eunknown;
	case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR:
		return err::eunknown;
	case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR:
		return err::eunknown;
	case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
		return err::eunknown;
	case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
		return err::eunknown;
	case VK_THREAD_IDLE_KHR:
		return err::eunknown;
	case VK_THREAD_DONE_KHR:
		return err::eunknown;
	case VK_OPERATION_DEFERRED_KHR:
		return err::eunknown;
	case VK_OPERATION_NOT_DEFERRED_KHR:
		return err::eunknown;
	case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR:
		return err::eunknown;
	case VK_ERROR_COMPRESSION_EXHAUSTED_EXT:
		return err::eunknown;
	case VK_INCOMPATIBLE_SHADER_BINARY_EXT:
		return err::eunknown;
	case VK_PIPELINE_BINARY_MISSING_KHR:
		return err::eunknown;
	case VK_ERROR_NOT_ENOUGH_SPACE_KHR:
		return err::eunknown;
	}
}

struct vkerror : error {
	using error::error;
	
	constexpr vkerror(VkResult e) noexcept
		: error(vkresult_to_err(e)) {
	}
};

ICANVAS_NAMESPACE_GRAPHICS_VULKAN_END
