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

LOAD(vkAllocateCommandBuffers);
LOAD(vkAllocateDescriptorSets);
LOAD(vkAllocateMemory);
LOAD(vkBeginCommandBuffer);
LOAD(vkBindBufferMemory);
LOAD(vkBindImageMemory);
LOAD(vkCmdBeginQuery);
LOAD(vkCmdBeginRenderPass);
LOAD(vkCmdBindDescriptorSets);
LOAD(vkCmdBindIndexBuffer);
LOAD(vkCmdBindPipeline);
LOAD(vkCmdBindVertexBuffers);
LOAD(vkCmdBlitImage);
LOAD(vkCmdClearAttachments);
LOAD(vkCmdClearColorImage);
LOAD(vkCmdClearDepthStencilImage);
LOAD(vkCmdCopyBuffer);
LOAD(vkCmdCopyBufferToImage);
LOAD(vkCmdCopyImage);
LOAD(vkCmdCopyImageToBuffer);
LOAD(vkCmdCopyQueryPoolResults);
LOAD(vkCmdDispatch);
LOAD(vkCmdDispatchIndirect);
LOAD(vkCmdDraw);
LOAD(vkCmdDrawIndexed);
LOAD(vkCmdDrawIndexedIndirect);
LOAD(vkCmdDrawIndirect);
LOAD(vkCmdEndQuery);
LOAD(vkCmdEndRenderPass);
LOAD(vkCmdExecuteCommands);
LOAD(vkCmdFillBuffer);
LOAD(vkCmdNextSubpass);
LOAD(vkCmdPipelineBarrier);
LOAD(vkCmdPushConstants);
LOAD(vkCmdResetEvent);
LOAD(vkCmdResetQueryPool);
LOAD(vkCmdResolveImage);
LOAD(vkCmdSetBlendConstants);
LOAD(vkCmdSetDepthBias);
LOAD(vkCmdSetDepthBounds);
LOAD(vkCmdSetEvent);
LOAD(vkCmdSetLineWidth);
LOAD(vkCmdSetScissor);
LOAD(vkCmdSetStencilCompareMask);
LOAD(vkCmdSetStencilReference);
LOAD(vkCmdSetStencilWriteMask);
LOAD(vkCmdSetViewport);
LOAD(vkCmdUpdateBuffer);
LOAD(vkCmdWaitEvents);
LOAD(vkCmdWriteTimestamp);
LOAD(vkCreateBuffer);
LOAD(vkCreateBufferView);
LOAD(vkCreateCommandPool);
LOAD(vkCreateComputePipelines);
LOAD(vkCreateDescriptorPool);
LOAD(vkCreateDescriptorSetLayout);
LOAD(vkCreateDevice);
LOAD(vkCreateEvent);
LOAD(vkCreateFence);
LOAD(vkCreateFramebuffer);
LOAD(vkCreateGraphicsPipelines);
LOAD(vkCreateImage);
LOAD(vkCreateImageView);
LOAD(vkCreatePipelineCache);
LOAD(vkCreatePipelineLayout);
LOAD(vkCreateQueryPool);
LOAD(vkCreateRenderPass);
LOAD(vkCreateSampler);
LOAD(vkCreateSemaphore);
LOAD(vkCreateShaderModule);
LOAD(vkDestroyBuffer);
LOAD(vkDestroyBufferView);
LOAD(vkDestroyCommandPool);
LOAD(vkDestroyDescriptorPool);
LOAD(vkDestroyDescriptorSetLayout);
LOAD(vkDestroyDevice);
LOAD(vkDestroyEvent);
LOAD(vkDestroyFence);
LOAD(vkDestroyFramebuffer);
LOAD(vkDestroyImage);
LOAD(vkDestroyImageView);
LOAD(vkDestroyInstance);
LOAD(vkDestroyPipeline);
LOAD(vkDestroyPipelineCache);
LOAD(vkDestroyPipelineLayout);
LOAD(vkDestroyQueryPool);
LOAD(vkDestroyRenderPass);
LOAD(vkDestroySampler);
LOAD(vkDestroySemaphore);
LOAD(vkDestroyShaderModule);
LOAD(vkDeviceWaitIdle);
LOAD(vkEndCommandBuffer);
LOAD(vkEnumerateDeviceExtensionProperties);
LOAD(vkEnumerateDeviceLayerProperties);
LOAD(vkEnumeratePhysicalDevices);
LOAD(vkFlushMappedMemoryRanges);
LOAD(vkFreeCommandBuffers);
LOAD(vkFreeDescriptorSets);
LOAD(vkFreeMemory);
LOAD(vkGetBufferMemoryRequirements);
LOAD(vkGetDeviceMemoryCommitment);
LOAD(vkGetDeviceProcAddr);
LOAD(vkGetDeviceQueue);
LOAD(vkGetEventStatus);
LOAD(vkGetFenceStatus);
LOAD(vkGetImageMemoryRequirements);
LOAD(vkGetImageSparseMemoryRequirements);
LOAD(vkGetImageSubresourceLayout);
LOAD(vkGetPhysicalDeviceFeatures);
LOAD(vkGetPhysicalDeviceFormatProperties);
LOAD(vkGetPhysicalDeviceImageFormatProperties);
LOAD(vkGetPhysicalDeviceMemoryProperties);
LOAD(vkGetPhysicalDeviceProperties);
LOAD(vkGetPhysicalDeviceQueueFamilyProperties);
LOAD(vkGetPhysicalDeviceSparseImageFormatProperties);
LOAD(vkGetPipelineCacheData);
LOAD(vkGetQueryPoolResults);
LOAD(vkGetRenderAreaGranularity);
LOAD(vkInvalidateMappedMemoryRanges);
LOAD(vkMapMemory);
LOAD(vkMergePipelineCaches);
LOAD(vkQueueBindSparse);
LOAD(vkQueueSubmit);
LOAD(vkQueueWaitIdle);
LOAD(vkResetCommandBuffer);
LOAD(vkResetCommandPool);
LOAD(vkResetDescriptorPool);
LOAD(vkResetEvent);
LOAD(vkResetFences);
LOAD(vkSetEvent);
LOAD(vkUnmapMemory);
LOAD(vkUpdateDescriptorSets);
LOAD(vkWaitForFences);
LOAD(vkBindBufferMemory2);
LOAD(vkBindImageMemory2);
LOAD(vkCmdDispatchBase);
LOAD(vkCmdSetDeviceMask);
LOAD(vkCreateDescriptorUpdateTemplate);
LOAD(vkCreateSamplerYcbcrConversion);
LOAD(vkDestroyDescriptorUpdateTemplate);
LOAD(vkDestroySamplerYcbcrConversion);
LOAD(vkEnumerateInstanceVersion);
LOAD(vkEnumeratePhysicalDeviceGroups);
LOAD(vkGetBufferMemoryRequirements2);
LOAD(vkGetDescriptorSetLayoutSupport);
LOAD(vkGetDeviceGroupPeerMemoryFeatures);
LOAD(vkGetDeviceQueue2);
LOAD(vkGetImageMemoryRequirements2);
LOAD(vkGetImageSparseMemoryRequirements2);
LOAD(vkGetPhysicalDeviceExternalBufferProperties);
LOAD(vkGetPhysicalDeviceExternalFenceProperties);
LOAD(vkGetPhysicalDeviceExternalSemaphoreProperties);
LOAD(vkGetPhysicalDeviceFeatures2);
LOAD(vkGetPhysicalDeviceFormatProperties2);
LOAD(vkGetPhysicalDeviceImageFormatProperties2);
LOAD(vkGetPhysicalDeviceMemoryProperties2);
LOAD(vkGetPhysicalDeviceProperties2);
LOAD(vkGetPhysicalDeviceQueueFamilyProperties2);
LOAD(vkGetPhysicalDeviceSparseImageFormatProperties2);
LOAD(vkTrimCommandPool);
LOAD(vkUpdateDescriptorSetWithTemplate);
LOAD(vkCmdBeginRenderPass2);
LOAD(vkCmdDrawIndexedIndirectCount);
LOAD(vkCmdDrawIndirectCount);
LOAD(vkCmdEndRenderPass2);
LOAD(vkCmdNextSubpass2);
LOAD(vkCreateRenderPass2);
LOAD(vkGetBufferDeviceAddress);
LOAD(vkGetBufferOpaqueCaptureAddress);
LOAD(vkGetDeviceMemoryOpaqueCaptureAddress);
LOAD(vkGetSemaphoreCounterValue);
LOAD(vkResetQueryPool);
LOAD(vkSignalSemaphore);
LOAD(vkWaitSemaphores);
LOAD(vkCmdBeginRendering);
LOAD(vkCmdBindVertexBuffers2);
LOAD(vkCmdBlitImage2);
LOAD(vkCmdCopyBuffer2);
LOAD(vkCmdCopyBufferToImage2);
LOAD(vkCmdCopyImage2);
LOAD(vkCmdCopyImageToBuffer2);
LOAD(vkCmdEndRendering);
LOAD(vkCmdPipelineBarrier2);
LOAD(vkCmdResetEvent2);
LOAD(vkCmdResolveImage2);
LOAD(vkCmdSetCullMode);
LOAD(vkCmdSetDepthBiasEnable);
LOAD(vkCmdSetDepthBoundsTestEnable);
LOAD(vkCmdSetDepthCompareOp);
LOAD(vkCmdSetDepthTestEnable);
LOAD(vkCmdSetDepthWriteEnable);
LOAD(vkCmdSetEvent2);
LOAD(vkCmdSetFrontFace);
LOAD(vkCmdSetPrimitiveRestartEnable);
LOAD(vkCmdSetPrimitiveTopology);
LOAD(vkCmdSetRasterizerDiscardEnable);
LOAD(vkCmdSetScissorWithCount);
LOAD(vkCmdSetStencilOp);
LOAD(vkCmdSetStencilTestEnable);
LOAD(vkCmdSetViewportWithCount);
LOAD(vkCmdWaitEvents2);
LOAD(vkCmdWriteTimestamp2);
LOAD(vkCreatePrivateDataSlot);
LOAD(vkDestroyPrivateDataSlot);
LOAD(vkGetDeviceBufferMemoryRequirements);
LOAD(vkGetDeviceImageMemoryRequirements);
LOAD(vkGetDeviceImageSparseMemoryRequirements);
LOAD(vkGetPhysicalDeviceToolProperties);
LOAD(vkGetPrivateData);
LOAD(vkQueueSubmit2);
LOAD(vkSetPrivateData);
#ifdef VK_API_VERSION_1_4
LOAD(vkCmdBindDescriptorSets2);
LOAD(vkCmdBindIndexBuffer2);
LOAD(vkCmdPushConstants2);
LOAD(vkCmdPushDescriptorSet);
LOAD(vkCmdPushDescriptorSet2);
LOAD(vkCmdPushDescriptorSetWithTemplate);
LOAD(vkCmdPushDescriptorSetWithTemplate2);
LOAD(vkCmdSetLineStipple);
LOAD(vkCmdSetRenderingAttachmentLocations);
LOAD(vkCmdSetRenderingInputAttachmentIndices);
LOAD(vkCopyImageToImage);
LOAD(vkCopyImageToMemory);
LOAD(vkCopyMemoryToImage);
LOAD(vkGetDeviceImageSubresourceLayout);
LOAD(vkGetImageSubresourceLayout2);
LOAD(vkGetRenderingAreaGranularity);
LOAD(vkMapMemory2);
LOAD(vkTransitionImageLayout);
LOAD(vkUnmapMemory2);
#endif /* !VK_API_VERSION_1_4 */
#ifdef VK_KHR_surface
LOAD(vkDestroySurfaceKHR);
LOAD(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
LOAD(vkGetPhysicalDeviceSurfaceFormatsKHR);
LOAD(vkGetPhysicalDeviceSurfacePresentModesKHR);
LOAD(vkGetPhysicalDeviceSurfaceSupportKHR);
#ifdef VK_KHR_swapchain
LOAD(vkAcquireNextImageKHR);
LOAD(vkCreateSwapchainKHR);
LOAD(vkDestroySwapchainKHR);
LOAD(vkGetSwapchainImagesKHR);
LOAD(vkQueuePresentKHR);
#ifdef VK_VERSION_1_1
LOAD(vkAcquireNextImage2KHR);
LOAD(vkGetDeviceGroupPresentCapabilitiesKHR);
LOAD(vkGetDeviceGroupSurfacePresentModesKHR);
LOAD(vkGetPhysicalDevicePresentRectanglesKHR);
#endif /* !VK_VERSION_1_1 */
#endif /* !VK_KHR_swapchain */
#ifdef VK_KHR_android_surface
LOAD(vkCreateAndroidSurfaceKHR);
#endif /* !VK_KHR_android_surface */
#ifdef CANVAS_ENABLE_WAYLAND
#ifdef VK_KHR_wayland_surface
LOAD(vkCreateWaylandSurfaceKHR);
LOAD(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
#endif /* !VK_KHR_wayland_surface */
#endif /* !CANVAS_ENABLE_WAYLAND */
#ifdef CANVAS_ENABLE_XLIB
#ifdef VK_KHR_xlib_surface
LOAD(vkCreateXcbSurfaceKHR);
LOAD(vkGetPhysicalDeviceXcbPresentationSupportKHR);
#endif /* !VK_KHR_xlib_surface */
#ifdef VK_KHR_xcb_surface
LOAD(vkCreateXlibSurfaceKHR);
LOAD(vkGetPhysicalDeviceXlibPresentationSupportKHR);
#endif /* !VK_KHR_xcb_surface */
#endif /* !CANVAS_ENABLE_XLIB */
#if CANVAS_PLATFORM_WINDOWS
#ifdef VK_KHR_win32_surface
LOAD(vkCreateWin32SurfaceKHR);
LOAD(vkGetPhysicalDeviceWin32PresentationSupportKHR);
#endif
#endif /* !CANVAS_PLATFORM_WINDOWS */
#endif /* !VK_KHR_surface */
#ifdef VK_KHR_display
LOAD(vkCreateDisplayModeKHR);
LOAD(vkCreateDisplayPlaneSurfaceKHR);
LOAD(vkGetDisplayModePropertiesKHR);
LOAD(vkGetDisplayPlaneCapabilitiesKHR);
LOAD(vkGetDisplayPlaneSupportedDisplaysKHR);
LOAD(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
LOAD(vkGetPhysicalDeviceDisplayPropertiesKHR);
#endif /* !VK_KHR_display */
#ifdef VK_KHR_display_swapchain
LOAD(vkCreateSharedSwapchainsKHR);
#endif /* !VK_KHR_display_swapchain */
#ifdef VK_KHR_get_physical_device_properties2
LOAD(vkGetPhysicalDeviceFeatures2KHR);
LOAD(vkGetPhysicalDeviceFormatProperties2KHR);
LOAD(vkGetPhysicalDeviceImageFormatProperties2KHR);
LOAD(vkGetPhysicalDeviceMemoryProperties2KHR);
LOAD(vkGetPhysicalDeviceProperties2KHR);
LOAD(vkGetPhysicalDeviceQueueFamilyProperties2KHR);
LOAD(vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
#endif /* !VK_KHR_get_physical_device_properties2 */
#ifdef VK_KHR_synchronization2
LOAD(vkCmdPipelineBarrier2KHR);
LOAD(vkCmdResetEvent2KHR);
LOAD(vkCmdSetEvent2KHR);
LOAD(vkCmdWaitEvents2KHR);
LOAD(vkCmdWriteTimestamp2KHR);
LOAD(vkQueueSubmit2KHR);
#endif /* !VK_KHR_synchronization2 */
