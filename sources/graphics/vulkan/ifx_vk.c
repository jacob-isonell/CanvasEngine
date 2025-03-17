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

#include "ifx_vk.h"

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
