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

#ifndef IVK_PROTO_H
#define IVK_PROTO_H

#include "ifx_vk.h"
#include <canvas/core/library.h>

CE_NAMESPACE_BEGIN

#if CANVAS_PLATFORM_WINDOWS
#define IVK_DLL_FILE "vulkan-1.dll"
#elif CANVAS_PLATFORM_UNIX
#define IVK_DLL_FILE "libvulkan.so.1"
#endif

typedef struct ivk_protos {
  ce_lib* libvulkan1;
  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
  
  PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
  PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
  PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
  PFN_vkCreateInstance vkCreateInstance;
  
  PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
  PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
  PFN_vkAllocateMemory vkAllocateMemory;
  PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
  PFN_vkBindBufferMemory vkBindBufferMemory;
  PFN_vkBindImageMemory vkBindImageMemory;
  PFN_vkCmdBeginQuery vkCmdBeginQuery;
  PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
  PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
  PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
  PFN_vkCmdBindPipeline vkCmdBindPipeline;
  PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
  PFN_vkCmdBlitImage vkCmdBlitImage;
  PFN_vkCmdClearAttachments vkCmdClearAttachments;
  PFN_vkCmdClearColorImage vkCmdClearColorImage;
  PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
  PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
  PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
  PFN_vkCmdCopyImage vkCmdCopyImage;
  PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
  PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
  PFN_vkCmdDispatch vkCmdDispatch;
  PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
  PFN_vkCmdDraw vkCmdDraw;
  PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
  PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
  PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
  PFN_vkCmdEndQuery vkCmdEndQuery;
  PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
  PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
  PFN_vkCmdFillBuffer vkCmdFillBuffer;
  PFN_vkCmdNextSubpass vkCmdNextSubpass;
  PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
  PFN_vkCmdPushConstants vkCmdPushConstants;
  PFN_vkCmdResetEvent vkCmdResetEvent;
  PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
  PFN_vkCmdResolveImage vkCmdResolveImage;
  PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
  PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
  PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
  PFN_vkCmdSetEvent vkCmdSetEvent;
  PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
  PFN_vkCmdSetScissor vkCmdSetScissor;
  PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
  PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
  PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
  PFN_vkCmdSetViewport vkCmdSetViewport;
  PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
  PFN_vkCmdWaitEvents vkCmdWaitEvents;
  PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
  PFN_vkCreateBuffer vkCreateBuffer;
  PFN_vkCreateBufferView vkCreateBufferView;
  PFN_vkCreateCommandPool vkCreateCommandPool;
  PFN_vkCreateComputePipelines vkCreateComputePipelines;
  PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
  PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
  PFN_vkCreateDevice vkCreateDevice;
  PFN_vkCreateEvent vkCreateEvent;
  PFN_vkCreateFence vkCreateFence;
  PFN_vkCreateFramebuffer vkCreateFramebuffer;
  PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
  PFN_vkCreateImage vkCreateImage;
  PFN_vkCreateImageView vkCreateImageView;
  PFN_vkCreatePipelineCache vkCreatePipelineCache;
  PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
  PFN_vkCreateQueryPool vkCreateQueryPool;
  PFN_vkCreateRenderPass vkCreateRenderPass;
  PFN_vkCreateSampler vkCreateSampler;
  PFN_vkCreateSemaphore vkCreateSemaphore;
  PFN_vkCreateShaderModule vkCreateShaderModule;
  PFN_vkDestroyBuffer vkDestroyBuffer;
  PFN_vkDestroyBufferView vkDestroyBufferView;
  PFN_vkDestroyCommandPool vkDestroyCommandPool;
  PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
  PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
  PFN_vkDestroyDevice vkDestroyDevice;
  PFN_vkDestroyEvent vkDestroyEvent;
  PFN_vkDestroyFence vkDestroyFence;
  PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
  PFN_vkDestroyImage vkDestroyImage;
  PFN_vkDestroyImageView vkDestroyImageView;
  PFN_vkDestroyInstance vkDestroyInstance;
  PFN_vkDestroyPipeline vkDestroyPipeline;
  PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
  PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
  PFN_vkDestroyQueryPool vkDestroyQueryPool;
  PFN_vkDestroyRenderPass vkDestroyRenderPass;
  PFN_vkDestroySampler vkDestroySampler;
  PFN_vkDestroySemaphore vkDestroySemaphore;
  PFN_vkDestroyShaderModule vkDestroyShaderModule;
  PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
  PFN_vkEndCommandBuffer vkEndCommandBuffer;
  PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
  PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
  PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
  PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
  PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
  PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
  PFN_vkFreeMemory vkFreeMemory;
  PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
  PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
  PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
  PFN_vkGetDeviceQueue vkGetDeviceQueue;
  PFN_vkGetEventStatus vkGetEventStatus;
  PFN_vkGetFenceStatus vkGetFenceStatus;
  PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
  PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
  PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
  PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
  PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
  PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
  PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
  PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
  PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
  PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
  PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
  PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
  PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
  PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
  PFN_vkMapMemory vkMapMemory;
  PFN_vkMergePipelineCaches vkMergePipelineCaches;
  PFN_vkQueueBindSparse vkQueueBindSparse;
  PFN_vkQueueSubmit vkQueueSubmit;
  PFN_vkQueueWaitIdle vkQueueWaitIdle;
  PFN_vkResetCommandBuffer vkResetCommandBuffer;
  PFN_vkResetCommandPool vkResetCommandPool;
  PFN_vkResetDescriptorPool vkResetDescriptorPool;
  PFN_vkResetEvent vkResetEvent;
  PFN_vkResetFences vkResetFences;
  PFN_vkSetEvent vkSetEvent;
  PFN_vkUnmapMemory vkUnmapMemory;
  PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
  PFN_vkWaitForFences vkWaitForFences;
  PFN_vkBindBufferMemory2 vkBindBufferMemory2;
  PFN_vkBindImageMemory2 vkBindImageMemory2;
  PFN_vkCmdDispatchBase vkCmdDispatchBase;
  PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
  PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
  PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
  PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
  PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
  PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
  PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
  PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
  PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
  PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
  PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
  PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
  PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
  PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
  PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
  PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
  PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
  PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
  PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
  PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
  PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
  PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
  PFN_vkTrimCommandPool vkTrimCommandPool;
  PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
  PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
  PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
  PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
  PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
  PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
  PFN_vkCreateRenderPass2 vkCreateRenderPass2;
  PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
  PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
  PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;
  PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
  PFN_vkResetQueryPool vkResetQueryPool;
  PFN_vkSignalSemaphore vkSignalSemaphore;
  PFN_vkWaitSemaphores vkWaitSemaphores;
  PFN_vkCmdBeginRendering vkCmdBeginRendering;
  PFN_vkCmdBindVertexBuffers2 vkCmdBindVertexBuffers2;
  PFN_vkCmdBlitImage2 vkCmdBlitImage2;
  PFN_vkCmdCopyBuffer2 vkCmdCopyBuffer2;
  PFN_vkCmdCopyBufferToImage2 vkCmdCopyBufferToImage2;
  PFN_vkCmdCopyImage2 vkCmdCopyImage2;
  PFN_vkCmdCopyImageToBuffer2 vkCmdCopyImageToBuffer2;
  PFN_vkCmdEndRendering vkCmdEndRendering;
  PFN_vkCmdPipelineBarrier2 vkCmdPipelineBarrier2;
  PFN_vkCmdResetEvent2 vkCmdResetEvent2;
  PFN_vkCmdResolveImage2 vkCmdResolveImage2;
  PFN_vkCmdSetCullMode vkCmdSetCullMode;
  PFN_vkCmdSetDepthBiasEnable vkCmdSetDepthBiasEnable;
  PFN_vkCmdSetDepthBoundsTestEnable vkCmdSetDepthBoundsTestEnable;
  PFN_vkCmdSetDepthCompareOp vkCmdSetDepthCompareOp;
  PFN_vkCmdSetDepthTestEnable vkCmdSetDepthTestEnable;
  PFN_vkCmdSetDepthWriteEnable vkCmdSetDepthWriteEnable;
  PFN_vkCmdSetEvent2 vkCmdSetEvent2;
  PFN_vkCmdSetFrontFace vkCmdSetFrontFace;
  PFN_vkCmdSetPrimitiveRestartEnable vkCmdSetPrimitiveRestartEnable;
  PFN_vkCmdSetPrimitiveTopology vkCmdSetPrimitiveTopology;
  PFN_vkCmdSetRasterizerDiscardEnable vkCmdSetRasterizerDiscardEnable;
  PFN_vkCmdSetScissorWithCount vkCmdSetScissorWithCount;
  PFN_vkCmdSetStencilOp vkCmdSetStencilOp;
  PFN_vkCmdSetStencilTestEnable vkCmdSetStencilTestEnable;
  PFN_vkCmdSetViewportWithCount vkCmdSetViewportWithCount;
  PFN_vkCmdWaitEvents2 vkCmdWaitEvents2;
  PFN_vkCmdWriteTimestamp2 vkCmdWriteTimestamp2;
  PFN_vkCreatePrivateDataSlot vkCreatePrivateDataSlot;
  PFN_vkDestroyPrivateDataSlot vkDestroyPrivateDataSlot;
  PFN_vkGetDeviceBufferMemoryRequirements vkGetDeviceBufferMemoryRequirements;
  PFN_vkGetDeviceImageMemoryRequirements vkGetDeviceImageMemoryRequirements;
  PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
  PFN_vkGetPhysicalDeviceToolProperties vkGetPhysicalDeviceToolProperties;
  PFN_vkGetPrivateData vkGetPrivateData;
  PFN_vkQueueSubmit2 vkQueueSubmit2;
  PFN_vkSetPrivateData vkSetPrivateData;
  #ifdef VK_API_VERSION_1_4
  PFN_vkCmdBindDescriptorSets2 vkCmdBindDescriptorSets2;
  PFN_vkCmdBindIndexBuffer2 vkCmdBindIndexBuffer2;
  PFN_vkCmdPushConstants2 vkCmdPushConstants2;
  PFN_vkCmdPushDescriptorSet vkCmdPushDescriptorSet;
  PFN_vkCmdPushDescriptorSet2 vkCmdPushDescriptorSet2;
  PFN_vkCmdPushDescriptorSetWithTemplate vkCmdPushDescriptorSetWithTemplate;
  PFN_vkCmdPushDescriptorSetWithTemplate2 vkCmdPushDescriptorSetWithTemplate2;
  PFN_vkCmdSetLineStipple vkCmdSetLineStipple;
  PFN_vkCmdSetRenderingAttachmentLocations vkCmdSetRenderingAttachmentLocations;
  PFN_vkCmdSetRenderingInputAttachmentIndices vkCmdSetRenderingInputAttachmentIndices;
  PFN_vkCopyImageToImage vkCopyImageToImage;
  PFN_vkCopyImageToMemory vkCopyImageToMemory;
  PFN_vkCopyMemoryToImage vkCopyMemoryToImage;
  PFN_vkGetDeviceImageSubresourceLayout vkGetDeviceImageSubresourceLayout;
  PFN_vkGetImageSubresourceLayout2 vkGetImageSubresourceLayout2;
  PFN_vkGetRenderingAreaGranularity vkGetRenderingAreaGranularity;
  PFN_vkMapMemory2 vkMapMemory2;
  PFN_vkTransitionImageLayout vkTransitionImageLayout;
  PFN_vkUnmapMemory2 vkUnmapMemory2;
  #endif /* !VK_API_VERSION_1_4 */
  #ifdef VK_KHR_surface
  PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
  PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
  PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
  PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
  PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
  #ifdef VK_KHR_swapchain
  PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
  PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
  PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
  PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
  PFN_vkQueuePresentKHR vkQueuePresentKHR;
  #ifdef VK_VERSION_1_1
  PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
  PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
  PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
  PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
  #endif /* !VK_VERSION_1_1 */
  #endif /* !VK_KHR_swapchain */
  #ifdef VK_KHR_android_surface
  PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
  #endif /* !VK_KHR_android_surface */
  #ifdef CANVAS_ENABLE_WAYLAND
  #ifdef VK_KHR_wayland_surface
  PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
  PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
  #endif /* !VK_KHR_wayland_surface */
  #endif /* !CANVAS_ENABLE_WAYLAND */
  #ifdef CANVAS_ENABLE_XLIB
  #ifdef VK_KHR_xlib_surface
  PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
  PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
  #endif /* !VK_KHR_xlib_surface */
  #ifdef VK_KHR_xcb_surface
  PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
  PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
  #endif /* !VK_KHR_xcb_surface */
  #endif /* !CANVAS_ENABLE_XLIB */
  #if CANVAS_PLATFORM_WINDOWS
  #ifdef VK_KHR_win32_surface
  PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
  PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
  #endif
  #endif /* !CANVAS_PLATFORM_WINDOWS */
  #endif /* !VK_KHR_surface */
  #ifdef VK_KHR_display
  PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
  PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
  PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
  PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
  PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
  PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
  PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
  #endif /* !VK_KHR_display */
  #ifdef VK_KHR_display_swapchain
  PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
  #endif /* !VK_KHR_display_swapchain */
  #ifdef VK_KHR_get_physical_device_properties2
  PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
  PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
  PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
  PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
  PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
  PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
  PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
  #endif /* !VK_KHR_get_physical_device_properties2 */
  #ifdef VK_KHR_synchronization2
  PFN_vkCmdPipelineBarrier2KHR vkCmdPipelineBarrier2KHR;
  PFN_vkCmdResetEvent2KHR vkCmdResetEvent2KHR;
  PFN_vkCmdSetEvent2KHR vkCmdSetEvent2KHR;
  PFN_vkCmdWaitEvents2KHR vkCmdWaitEvents2KHR;
  PFN_vkCmdWriteTimestamp2KHR vkCmdWriteTimestamp2KHR;
  PFN_vkQueueSubmit2KHR vkQueueSubmit2KHR;
  #endif /* !VK_KHR_synchronization2 */
} ivk_protos;

struct ice_vulkan_driver_data {
  ivk_protos pfn;
  VkInstance instance;
  ce_arr(ice_gpu_adapter_vk) gpu_adapters;
};

ICE_API ce_err ivk_load_protos(
  CE_IN  const VkInstanceCreateInfo* CE_RESTRICT info,
  CE_OUT VkInstance*                 CE_RESTRICT out_inst,
  CE_OUT ivk_protos*                 CE_RESTRICT out_proto
);

ICE_API void ivk_unload_protos(
  CE_INOUT VkInstance              inst,
  CE_INOUT ivk_protos* CE_RESTRICT protos
);

CE_NAMESPACE_END

#endif /* !IVK_PROTO_H */
