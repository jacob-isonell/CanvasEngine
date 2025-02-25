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

#ifndef IVK_PROTO_NO_UNDEF
#undef vkAllocateCommandBuffers
#undef vkAllocateDescriptorSets
#undef vkAllocateMemory
#undef vkBeginCommandBuffer
#undef vkBindBufferMemory
#undef vkBindImageMemory
#undef vkCmdBeginQuery
#undef vkCmdBeginRenderPass
#undef vkCmdBindDescriptorSets
#undef vkCmdBindIndexBuffer
#undef vkCmdBindPipeline
#undef vkCmdBindVertexBuffers
#undef vkCmdBlitImage
#undef vkCmdClearAttachments
#undef vkCmdClearColorImage
#undef vkCmdClearDepthStencilImage
#undef vkCmdCopyBuffer
#undef vkCmdCopyBufferToImage
#undef vkCmdCopyImage
#undef vkCmdCopyImageToBuffer
#undef vkCmdCopyQueryPoolResults
#undef vkCmdDispatch
#undef vkCmdDispatchIndirect
#undef vkCmdDraw
#undef vkCmdDrawIndexed
#undef vkCmdDrawIndexedIndirect
#undef vkCmdDrawIndirect
#undef vkCmdEndQuery
#undef vkCmdEndRenderPass
#undef vkCmdExecuteCommands
#undef vkCmdFillBuffer
#undef vkCmdNextSubpass
#undef vkCmdPipelineBarrier
#undef vkCmdPushConstants
#undef vkCmdResetEvent
#undef vkCmdResetQueryPool
#undef vkCmdResolveImage
#undef vkCmdSetBlendConstants
#undef vkCmdSetDepthBias
#undef vkCmdSetDepthBounds
#undef vkCmdSetEvent
#undef vkCmdSetLineWidth
#undef vkCmdSetScissor
#undef vkCmdSetStencilCompareMask
#undef vkCmdSetStencilReference
#undef vkCmdSetStencilWriteMask
#undef vkCmdSetViewport
#undef vkCmdUpdateBuffer
#undef vkCmdWaitEvents
#undef vkCmdWriteTimestamp
#undef vkCreateBuffer
#undef vkCreateBufferView
#undef vkCreateCommandPool
#undef vkCreateComputePipelines
#undef vkCreateDescriptorPool
#undef vkCreateDescriptorSetLayout
#undef vkCreateDevice
#undef vkCreateEvent
#undef vkCreateFence
#undef vkCreateFramebuffer
#undef vkCreateGraphicsPipelines
#undef vkCreateImage
#undef vkCreateImageView
#undef vkCreateInstance
#undef vkCreatePipelineCache
#undef vkCreatePipelineLayout
#undef vkCreateQueryPool
#undef vkCreateRenderPass
#undef vkCreateSampler
#undef vkCreateSemaphore
#undef vkCreateShaderModule
#undef vkDestroyBuffer
#undef vkDestroyBufferView
#undef vkDestroyCommandPool
#undef vkDestroyDescriptorPool
#undef vkDestroyDescriptorSetLayout
#undef vkDestroyDevice
#undef vkDestroyEvent
#undef vkDestroyFence
#undef vkDestroyFramebuffer
#undef vkDestroyImage
#undef vkDestroyImageView
#undef vkDestroyInstance
#undef vkDestroyPipeline
#undef vkDestroyPipelineCache
#undef vkDestroyPipelineLayout
#undef vkDestroyQueryPool
#undef vkDestroyRenderPass
#undef vkDestroySampler
#undef vkDestroySemaphore
#undef vkDestroyShaderModule
#undef vkDeviceWaitIdle
#undef vkEndCommandBuffer
#undef vkEnumerateDeviceExtensionProperties
#undef vkEnumerateDeviceLayerProperties
#undef vkEnumerateInstanceExtensionProperties
#undef vkEnumerateInstanceLayerProperties
#undef vkEnumeratePhysicalDevices
#undef vkFlushMappedMemoryRanges
#undef vkFreeCommandBuffers
#undef vkFreeDescriptorSets
#undef vkFreeMemory
#undef vkGetBufferMemoryRequirements
#undef vkGetDeviceMemoryCommitment
#undef vkGetDeviceProcAddr
#undef vkGetDeviceQueue
#undef vkGetEventStatus
#undef vkGetFenceStatus
#undef vkGetImageMemoryRequirements
#undef vkGetImageSparseMemoryRequirements
#undef vkGetImageSubresourceLayout
#undef vkGetInstanceProcAddr
#undef vkGetPhysicalDeviceFeatures
#undef vkGetPhysicalDeviceFormatProperties
#undef vkGetPhysicalDeviceImageFormatProperties
#undef vkGetPhysicalDeviceMemoryProperties
#undef vkGetPhysicalDeviceProperties
#undef vkGetPhysicalDeviceQueueFamilyProperties
#undef vkGetPhysicalDeviceSparseImageFormatProperties
#undef vkGetPipelineCacheData
#undef vkGetQueryPoolResults
#undef vkGetRenderAreaGranularity
#undef vkInvalidateMappedMemoryRanges
#undef vkMapMemory
#undef vkMergePipelineCaches
#undef vkQueueBindSparse
#undef vkQueueSubmit
#undef vkQueueWaitIdle
#undef vkResetCommandBuffer
#undef vkResetCommandPool
#undef vkResetDescriptorPool
#undef vkResetEvent
#undef vkResetFences
#undef vkSetEvent
#undef vkUnmapMemory
#undef vkUpdateDescriptorSets
#undef vkWaitForFences
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef VK_VERSION_1_0
#ifdef IVK_PROTO_MACRO
#define vkAllocateCommandBuffers IVK_PROTO_MACRO(vkAllocateCommandBuffers)
#define vkAllocateDescriptorSets IVK_PROTO_MACRO(vkAllocateDescriptorSets)
#define vkAllocateMemory IVK_PROTO_MACRO(vkAllocateMemory)
#define vkBeginCommandBuffer IVK_PROTO_MACRO(vkBeginCommandBuffer)
#define vkBindBufferMemory IVK_PROTO_MACRO(vkBindBufferMemory)
#define vkBindImageMemory IVK_PROTO_MACRO(vkBindImageMemory)
#define vkCmdBeginQuery IVK_PROTO_MACRO(vkCmdBeginQuery)
#define vkCmdBeginRenderPass IVK_PROTO_MACRO(vkCmdBeginRenderPass)
#define vkCmdBindDescriptorSets IVK_PROTO_MACRO(vkCmdBindDescriptorSets)
#define vkCmdBindIndexBuffer IVK_PROTO_MACRO(vkCmdBindIndexBuffer)
#define vkCmdBindPipeline IVK_PROTO_MACRO(vkCmdBindPipeline)
#define vkCmdBindVertexBuffers IVK_PROTO_MACRO(vkCmdBindVertexBuffers)
#define vkCmdBlitImage IVK_PROTO_MACRO(vkCmdBlitImage)
#define vkCmdClearAttachments IVK_PROTO_MACRO(vkCmdClearAttachments)
#define vkCmdClearColorImage IVK_PROTO_MACRO(vkCmdClearColorImage)
#define vkCmdClearDepthStencilImage IVK_PROTO_MACRO(vkCmdClearDepthStencilImage)
#define vkCmdCopyBuffer IVK_PROTO_MACRO(vkCmdCopyBuffer)
#define vkCmdCopyBufferToImage IVK_PROTO_MACRO(vkCmdCopyBufferToImage)
#define vkCmdCopyImage IVK_PROTO_MACRO(vkCmdCopyImage)
#define vkCmdCopyImageToBuffer IVK_PROTO_MACRO(vkCmdCopyImageToBuffer)
#define vkCmdCopyQueryPoolResults IVK_PROTO_MACRO(vkCmdCopyQueryPoolResults)
#define vkCmdDispatch IVK_PROTO_MACRO(vkCmdDispatch)
#define vkCmdDispatchIndirect IVK_PROTO_MACRO(vkCmdDispatchIndirect)
#define vkCmdDraw IVK_PROTO_MACRO(vkCmdDraw)
#define vkCmdDrawIndexed IVK_PROTO_MACRO(vkCmdDrawIndexed)
#define vkCmdDrawIndexedIndirect IVK_PROTO_MACRO(vkCmdDrawIndexedIndirect)
#define vkCmdDrawIndirect IVK_PROTO_MACRO(vkCmdDrawIndirect)
#define vkCmdEndQuery IVK_PROTO_MACRO(vkCmdEndQuery)
#define vkCmdEndRenderPass IVK_PROTO_MACRO(vkCmdEndRenderPass)
#define vkCmdExecuteCommands IVK_PROTO_MACRO(vkCmdExecuteCommands)
#define vkCmdFillBuffer IVK_PROTO_MACRO(vkCmdFillBuffer)
#define vkCmdNextSubpass IVK_PROTO_MACRO(vkCmdNextSubpass)
#define vkCmdPipelineBarrier IVK_PROTO_MACRO(vkCmdPipelineBarrier)
#define vkCmdPushConstants IVK_PROTO_MACRO(vkCmdPushConstants)
#define vkCmdResetEvent IVK_PROTO_MACRO(vkCmdResetEvent)
#define vkCmdResetQueryPool IVK_PROTO_MACRO(vkCmdResetQueryPool)
#define vkCmdResolveImage IVK_PROTO_MACRO(vkCmdResolveImage)
#define vkCmdSetBlendConstants IVK_PROTO_MACRO(vkCmdSetBlendConstants)
#define vkCmdSetDepthBias IVK_PROTO_MACRO(vkCmdSetDepthBias)
#define vkCmdSetDepthBounds IVK_PROTO_MACRO(vkCmdSetDepthBounds)
#define vkCmdSetEvent IVK_PROTO_MACRO(vkCmdSetEvent)
#define vkCmdSetLineWidth IVK_PROTO_MACRO(vkCmdSetLineWidth)
#define vkCmdSetScissor IVK_PROTO_MACRO(vkCmdSetScissor)
#define vkCmdSetStencilCompareMask IVK_PROTO_MACRO(vkCmdSetStencilCompareMask)
#define vkCmdSetStencilReference IVK_PROTO_MACRO(vkCmdSetStencilReference)
#define vkCmdSetStencilWriteMask IVK_PROTO_MACRO(vkCmdSetStencilWriteMask)
#define vkCmdSetViewport IVK_PROTO_MACRO(vkCmdSetViewport)
#define vkCmdUpdateBuffer IVK_PROTO_MACRO(vkCmdUpdateBuffer)
#define vkCmdWaitEvents IVK_PROTO_MACRO(vkCmdWaitEvents)
#define vkCmdWriteTimestamp IVK_PROTO_MACRO(vkCmdWriteTimestamp)
#define vkCreateBuffer IVK_PROTO_MACRO(vkCreateBuffer)
#define vkCreateBufferView IVK_PROTO_MACRO(vkCreateBufferView)
#define vkCreateCommandPool IVK_PROTO_MACRO(vkCreateCommandPool)
#define vkCreateComputePipelines IVK_PROTO_MACRO(vkCreateComputePipelines)
#define vkCreateDescriptorPool IVK_PROTO_MACRO(vkCreateDescriptorPool)
#define vkCreateDescriptorSetLayout IVK_PROTO_MACRO(vkCreateDescriptorSetLayout)
#define vkCreateDevice IVK_PROTO_MACRO(vkCreateDevice)
#define vkCreateEvent IVK_PROTO_MACRO(vkCreateEvent)
#define vkCreateFence IVK_PROTO_MACRO(vkCreateFence)
#define vkCreateFramebuffer IVK_PROTO_MACRO(vkCreateFramebuffer)
#define vkCreateGraphicsPipelines IVK_PROTO_MACRO(vkCreateGraphicsPipelines)
#define vkCreateImage IVK_PROTO_MACRO(vkCreateImage)
#define vkCreateImageView IVK_PROTO_MACRO(vkCreateImageView)
#define vkCreateInstance IVK_PROTO_MACRO(vkCreateInstance)
#define vkCreatePipelineCache IVK_PROTO_MACRO(vkCreatePipelineCache)
#define vkCreatePipelineLayout IVK_PROTO_MACRO(vkCreatePipelineLayout)
#define vkCreateQueryPool IVK_PROTO_MACRO(vkCreateQueryPool)
#define vkCreateRenderPass IVK_PROTO_MACRO(vkCreateRenderPass)
#define vkCreateSampler IVK_PROTO_MACRO(vkCreateSampler)
#define vkCreateSemaphore IVK_PROTO_MACRO(vkCreateSemaphore)
#define vkCreateShaderModule IVK_PROTO_MACRO(vkCreateShaderModule)
#define vkDestroyBuffer IVK_PROTO_MACRO(vkDestroyBuffer)
#define vkDestroyBufferView IVK_PROTO_MACRO(vkDestroyBufferView)
#define vkDestroyCommandPool IVK_PROTO_MACRO(vkDestroyCommandPool)
#define vkDestroyDescriptorPool IVK_PROTO_MACRO(vkDestroyDescriptorPool)
#define vkDestroyDescriptorSetLayout IVK_PROTO_MACRO(vkDestroyDescriptorSetLayout)
#define vkDestroyDevice IVK_PROTO_MACRO(vkDestroyDevice)
#define vkDestroyEvent IVK_PROTO_MACRO(vkDestroyEvent)
#define vkDestroyFence IVK_PROTO_MACRO(vkDestroyFence)
#define vkDestroyFramebuffer IVK_PROTO_MACRO(vkDestroyFramebuffer)
#define vkDestroyImage IVK_PROTO_MACRO(vkDestroyImage)
#define vkDestroyImageView IVK_PROTO_MACRO(vkDestroyImageView)
#define vkDestroyInstance IVK_PROTO_MACRO(vkDestroyInstance)
#define vkDestroyPipeline IVK_PROTO_MACRO(vkDestroyPipeline)
#define vkDestroyPipelineCache IVK_PROTO_MACRO(vkDestroyPipelineCache)
#define vkDestroyPipelineLayout IVK_PROTO_MACRO(vkDestroyPipelineLayout)
#define vkDestroyQueryPool IVK_PROTO_MACRO(vkDestroyQueryPool)
#define vkDestroyRenderPass IVK_PROTO_MACRO(vkDestroyRenderPass)
#define vkDestroySampler IVK_PROTO_MACRO(vkDestroySampler)
#define vkDestroySemaphore IVK_PROTO_MACRO(vkDestroySemaphore)
#define vkDestroyShaderModule IVK_PROTO_MACRO(vkDestroyShaderModule)
#define vkDeviceWaitIdle IVK_PROTO_MACRO(vkDeviceWaitIdle)
#define vkEndCommandBuffer IVK_PROTO_MACRO(vkEndCommandBuffer)
#define vkEnumerateDeviceExtensionProperties IVK_PROTO_MACRO(vkEnumerateDeviceExtensionProperties)
#define vkEnumerateDeviceLayerProperties IVK_PROTO_MACRO(vkEnumerateDeviceLayerProperties)
#define vkEnumerateInstanceExtensionProperties IVK_PROTO_MACRO(vkEnumerateInstanceExtensionProperties)
#define vkEnumerateInstanceLayerProperties IVK_PROTO_MACRO(vkEnumerateInstanceLayerProperties)
#define vkEnumeratePhysicalDevices IVK_PROTO_MACRO(vkEnumeratePhysicalDevices)
#define vkFlushMappedMemoryRanges IVK_PROTO_MACRO(vkFlushMappedMemoryRanges)
#define vkFreeCommandBuffers IVK_PROTO_MACRO(vkFreeCommandBuffers)
#define vkFreeDescriptorSets IVK_PROTO_MACRO(vkFreeDescriptorSets)
#define vkFreeMemory IVK_PROTO_MACRO(vkFreeMemory)
#define vkGetBufferMemoryRequirements IVK_PROTO_MACRO(vkGetBufferMemoryRequirements)
#define vkGetDeviceMemoryCommitment IVK_PROTO_MACRO(vkGetDeviceMemoryCommitment)
#define vkGetDeviceProcAddr IVK_PROTO_MACRO(vkGetDeviceProcAddr)
#define vkGetDeviceQueue IVK_PROTO_MACRO(vkGetDeviceQueue)
#define vkGetEventStatus IVK_PROTO_MACRO(vkGetEventStatus)
#define vkGetFenceStatus IVK_PROTO_MACRO(vkGetFenceStatus)
#define vkGetImageMemoryRequirements IVK_PROTO_MACRO(vkGetImageMemoryRequirements)
#define vkGetImageSparseMemoryRequirements IVK_PROTO_MACRO(vkGetImageSparseMemoryRequirements)
#define vkGetImageSubresourceLayout IVK_PROTO_MACRO(vkGetImageSubresourceLayout)
#define vkGetPhysicalDeviceFeatures IVK_PROTO_MACRO(vkGetPhysicalDeviceFeatures)
#define vkGetPhysicalDeviceFormatProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceFormatProperties)
#define vkGetPhysicalDeviceImageFormatProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceImageFormatProperties)
#define vkGetPhysicalDeviceMemoryProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceMemoryProperties)
#define vkGetPhysicalDeviceProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceProperties)
#define vkGetPhysicalDeviceQueueFamilyProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceQueueFamilyProperties)
#define vkGetPhysicalDeviceSparseImageFormatProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceSparseImageFormatProperties)
#define vkGetPipelineCacheData IVK_PROTO_MACRO(vkGetPipelineCacheData)
#define vkGetQueryPoolResults IVK_PROTO_MACRO(vkGetQueryPoolResults)
#define vkGetRenderAreaGranularity IVK_PROTO_MACRO(vkGetRenderAreaGranularity)
#define vkInvalidateMappedMemoryRanges IVK_PROTO_MACRO(vkInvalidateMappedMemoryRanges)
#define vkMapMemory IVK_PROTO_MACRO(vkMapMemory)
#define vkMergePipelineCaches IVK_PROTO_MACRO(vkMergePipelineCaches)
#define vkQueueBindSparse IVK_PROTO_MACRO(vkQueueBindSparse)
#define vkQueueSubmit IVK_PROTO_MACRO(vkQueueSubmit)
#define vkQueueWaitIdle IVK_PROTO_MACRO(vkQueueWaitIdle)
#define vkResetCommandBuffer IVK_PROTO_MACRO(vkResetCommandBuffer)
#define vkResetCommandPool IVK_PROTO_MACRO(vkResetCommandPool)
#define vkResetDescriptorPool IVK_PROTO_MACRO(vkResetDescriptorPool)
#define vkResetEvent IVK_PROTO_MACRO(vkResetEvent)
#define vkResetFences IVK_PROTO_MACRO(vkResetFences)
#define vkSetEvent IVK_PROTO_MACRO(vkSetEvent)
#define vkUnmapMemory IVK_PROTO_MACRO(vkUnmapMemory)
#define vkUpdateDescriptorSets IVK_PROTO_MACRO(vkUpdateDescriptorSets)
#define vkWaitForFences IVK_PROTO_MACRO(vkWaitForFences)
#elif defined(IVK_PROTO_DECL)
IVK_PROTO_DECL(vkAllocateCommandBuffers)
IVK_PROTO_DECL(vkAllocateDescriptorSets)
IVK_PROTO_DECL(vkAllocateMemory)
IVK_PROTO_DECL(vkBeginCommandBuffer)
IVK_PROTO_DECL(vkBindBufferMemory)
IVK_PROTO_DECL(vkBindImageMemory)
IVK_PROTO_DECL(vkCmdBeginQuery)
IVK_PROTO_DECL(vkCmdBeginRenderPass)
IVK_PROTO_DECL(vkCmdBindDescriptorSets)
IVK_PROTO_DECL(vkCmdBindIndexBuffer)
IVK_PROTO_DECL(vkCmdBindPipeline)
IVK_PROTO_DECL(vkCmdBindVertexBuffers)
IVK_PROTO_DECL(vkCmdBlitImage)
IVK_PROTO_DECL(vkCmdClearAttachments)
IVK_PROTO_DECL(vkCmdClearColorImage)
IVK_PROTO_DECL(vkCmdClearDepthStencilImage)
IVK_PROTO_DECL(vkCmdCopyBuffer)
IVK_PROTO_DECL(vkCmdCopyBufferToImage)
IVK_PROTO_DECL(vkCmdCopyImage)
IVK_PROTO_DECL(vkCmdCopyImageToBuffer)
IVK_PROTO_DECL(vkCmdCopyQueryPoolResults)
IVK_PROTO_DECL(vkCmdDispatch)
IVK_PROTO_DECL(vkCmdDispatchIndirect)
IVK_PROTO_DECL(vkCmdDraw)
IVK_PROTO_DECL(vkCmdDrawIndexed)
IVK_PROTO_DECL(vkCmdDrawIndexedIndirect)
IVK_PROTO_DECL(vkCmdDrawIndirect)
IVK_PROTO_DECL(vkCmdEndQuery)
IVK_PROTO_DECL(vkCmdEndRenderPass)
IVK_PROTO_DECL(vkCmdExecuteCommands)
IVK_PROTO_DECL(vkCmdFillBuffer)
IVK_PROTO_DECL(vkCmdNextSubpass)
IVK_PROTO_DECL(vkCmdPipelineBarrier)
IVK_PROTO_DECL(vkCmdPushConstants)
IVK_PROTO_DECL(vkCmdResetEvent)
IVK_PROTO_DECL(vkCmdResetQueryPool)
IVK_PROTO_DECL(vkCmdResolveImage)
IVK_PROTO_DECL(vkCmdSetBlendConstants)
IVK_PROTO_DECL(vkCmdSetDepthBias)
IVK_PROTO_DECL(vkCmdSetDepthBounds)
IVK_PROTO_DECL(vkCmdSetEvent)
IVK_PROTO_DECL(vkCmdSetLineWidth)
IVK_PROTO_DECL(vkCmdSetScissor)
IVK_PROTO_DECL(vkCmdSetStencilCompareMask)
IVK_PROTO_DECL(vkCmdSetStencilReference)
IVK_PROTO_DECL(vkCmdSetStencilWriteMask)
IVK_PROTO_DECL(vkCmdSetViewport)
IVK_PROTO_DECL(vkCmdUpdateBuffer)
IVK_PROTO_DECL(vkCmdWaitEvents)
IVK_PROTO_DECL(vkCmdWriteTimestamp)
IVK_PROTO_DECL(vkCreateBuffer)
IVK_PROTO_DECL(vkCreateBufferView)
IVK_PROTO_DECL(vkCreateCommandPool)
IVK_PROTO_DECL(vkCreateComputePipelines)
IVK_PROTO_DECL(vkCreateDescriptorPool)
IVK_PROTO_DECL(vkCreateDescriptorSetLayout)
IVK_PROTO_DECL(vkCreateDevice)
IVK_PROTO_DECL(vkCreateEvent)
IVK_PROTO_DECL(vkCreateFence)
IVK_PROTO_DECL(vkCreateFramebuffer)
IVK_PROTO_DECL(vkCreateGraphicsPipelines)
IVK_PROTO_DECL(vkCreateImage)
IVK_PROTO_DECL(vkCreateImageView)
IVK_PROTO_DECL(vkCreatePipelineCache)
IVK_PROTO_DECL(vkCreatePipelineLayout)
IVK_PROTO_DECL(vkCreateQueryPool)
IVK_PROTO_DECL(vkCreateRenderPass)
IVK_PROTO_DECL(vkCreateSampler)
IVK_PROTO_DECL(vkCreateSemaphore)
IVK_PROTO_DECL(vkCreateShaderModule)
IVK_PROTO_DECL(vkDestroyBuffer)
IVK_PROTO_DECL(vkDestroyBufferView)
IVK_PROTO_DECL(vkDestroyCommandPool)
IVK_PROTO_DECL(vkDestroyDescriptorPool)
IVK_PROTO_DECL(vkDestroyDescriptorSetLayout)
IVK_PROTO_DECL(vkDestroyDevice)
IVK_PROTO_DECL(vkDestroyEvent)
IVK_PROTO_DECL(vkDestroyFence)
IVK_PROTO_DECL(vkDestroyFramebuffer)
IVK_PROTO_DECL(vkDestroyImage)
IVK_PROTO_DECL(vkDestroyImageView)
IVK_PROTO_DECL(vkDestroyInstance)
IVK_PROTO_DECL(vkDestroyPipeline)
IVK_PROTO_DECL(vkDestroyPipelineCache)
IVK_PROTO_DECL(vkDestroyPipelineLayout)
IVK_PROTO_DECL(vkDestroyQueryPool)
IVK_PROTO_DECL(vkDestroyRenderPass)
IVK_PROTO_DECL(vkDestroySampler)
IVK_PROTO_DECL(vkDestroySemaphore)
IVK_PROTO_DECL(vkDestroyShaderModule)
IVK_PROTO_DECL(vkDeviceWaitIdle)
IVK_PROTO_DECL(vkEndCommandBuffer)
IVK_PROTO_DECL(vkEnumerateDeviceExtensionProperties)
IVK_PROTO_DECL(vkEnumerateDeviceLayerProperties)
IVK_PROTO_DECL(vkEnumeratePhysicalDevices)
IVK_PROTO_DECL(vkFlushMappedMemoryRanges)
IVK_PROTO_DECL(vkFreeCommandBuffers)
IVK_PROTO_DECL(vkFreeDescriptorSets)
IVK_PROTO_DECL(vkFreeMemory)
IVK_PROTO_DECL(vkGetBufferMemoryRequirements)
IVK_PROTO_DECL(vkGetDeviceMemoryCommitment)
IVK_PROTO_DECL(vkGetDeviceProcAddr)
IVK_PROTO_DECL(vkGetDeviceQueue)
IVK_PROTO_DECL(vkGetEventStatus)
IVK_PROTO_DECL(vkGetFenceStatus)
IVK_PROTO_DECL(vkGetImageMemoryRequirements)
IVK_PROTO_DECL(vkGetImageSparseMemoryRequirements)
IVK_PROTO_DECL(vkGetImageSubresourceLayout)
IVK_PROTO_DECL(vkGetInstanceProcAddr)
IVK_PROTO_DECL(vkGetPhysicalDeviceFeatures)
IVK_PROTO_DECL(vkGetPhysicalDeviceFormatProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceImageFormatProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceMemoryProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceQueueFamilyProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceSparseImageFormatProperties)
IVK_PROTO_DECL(vkGetPipelineCacheData)
IVK_PROTO_DECL(vkGetQueryPoolResults)
IVK_PROTO_DECL(vkGetRenderAreaGranularity)
IVK_PROTO_DECL(vkInvalidateMappedMemoryRanges)
IVK_PROTO_DECL(vkMapMemory)
IVK_PROTO_DECL(vkMergePipelineCaches)
IVK_PROTO_DECL(vkQueueBindSparse)
IVK_PROTO_DECL(vkQueueSubmit)
IVK_PROTO_DECL(vkQueueWaitIdle)
IVK_PROTO_DECL(vkResetCommandBuffer)
IVK_PROTO_DECL(vkResetCommandPool)
IVK_PROTO_DECL(vkResetDescriptorPool)
IVK_PROTO_DECL(vkResetEvent)
IVK_PROTO_DECL(vkResetFences)
IVK_PROTO_DECL(vkSetEvent)
IVK_PROTO_DECL(vkUnmapMemory)
IVK_PROTO_DECL(vkUpdateDescriptorSets)
IVK_PROTO_DECL(vkWaitForFences)
#endif /* !IVK_PROTO_MACRO */
#endif /* !VK_VERSION_1_0 */
