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
#undef vkBindBufferMemory2
#undef vkBindImageMemory2
#undef vkCmdDispatchBase
#undef vkCmdSetDeviceMask
#undef vkCreateDescriptorUpdateTemplate
#undef vkCreateSamplerYcbcrConversion
#undef vkDestroyDescriptorUpdateTemplate
#undef vkDestroySamplerYcbcrConversion
#undef vkEnumerateInstanceVersion
#undef vkEnumeratePhysicalDeviceGroups
#undef vkGetBufferMemoryRequirements2
#undef vkGetDescriptorSetLayoutSupport
#undef vkGetDeviceGroupPeerMemoryFeatures
#undef vkGetDeviceQueue2
#undef vkGetImageMemoryRequirements2
#undef vkGetImageSparseMemoryRequirements2
#undef vkGetPhysicalDeviceExternalBufferProperties
#undef vkGetPhysicalDeviceExternalFenceProperties
#undef vkGetPhysicalDeviceExternalSemaphoreProperties
#undef vkGetPhysicalDeviceFeatures2
#undef vkGetPhysicalDeviceFormatProperties2
#undef vkGetPhysicalDeviceImageFormatProperties2
#undef vkGetPhysicalDeviceMemoryProperties2
#undef vkGetPhysicalDeviceProperties2
#undef vkGetPhysicalDeviceQueueFamilyProperties2
#undef vkGetPhysicalDeviceSparseImageFormatProperties2
#undef vkTrimCommandPool
#undef vkUpdateDescriptorSetWithTemplate
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef VK_VERSION_1_1
#ifdef IVK_PROTO_MACRO
#define vkBindBufferMemory2 IVK_PROTO_MACRO(vkBindBufferMemory2)
#define vkBindImageMemory2 IVK_PROTO_MACRO(vkBindImageMemory2)
#define vkCmdDispatchBase IVK_PROTO_MACRO(vkCmdDispatchBase)
#define vkCmdSetDeviceMask IVK_PROTO_MACRO(vkCmdSetDeviceMask)
#define vkCreateDescriptorUpdateTemplate IVK_PROTO_MACRO(vkCreateDescriptorUpdateTemplate)
#define vkCreateSamplerYcbcrConversion IVK_PROTO_MACRO(vkCreateSamplerYcbcrConversion)
#define vkDestroyDescriptorUpdateTemplate IVK_PROTO_MACRO(vkDestroyDescriptorUpdateTemplate)
#define vkDestroySamplerYcbcrConversion IVK_PROTO_MACRO(vkDestroySamplerYcbcrConversion)
#define vkEnumerateInstanceVersion IVK_PROTO_MACRO(vkEnumerateInstanceVersion)
#define vkEnumeratePhysicalDeviceGroups IVK_PROTO_MACRO(vkEnumeratePhysicalDeviceGroups)
#define vkGetBufferMemoryRequirements2 IVK_PROTO_MACRO(vkGetBufferMemoryRequirements2)
#define vkGetDescriptorSetLayoutSupport IVK_PROTO_MACRO(vkGetDescriptorSetLayoutSupport)
#define vkGetDeviceGroupPeerMemoryFeatures IVK_PROTO_MACRO(vkGetDeviceGroupPeerMemoryFeatures)
#define vkGetDeviceQueue2 IVK_PROTO_MACRO(vkGetDeviceQueue2)
#define vkGetImageMemoryRequirements2 IVK_PROTO_MACRO(vkGetImageMemoryRequirements2)
#define vkGetImageSparseMemoryRequirements2 IVK_PROTO_MACRO(vkGetImageSparseMemoryRequirements2)
#define vkGetPhysicalDeviceExternalBufferProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceExternalBufferProperties)
#define vkGetPhysicalDeviceExternalFenceProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceExternalFenceProperties)
#define vkGetPhysicalDeviceExternalSemaphoreProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceExternalSemaphoreProperties)
#define vkGetPhysicalDeviceFeatures2 IVK_PROTO_MACRO(vkGetPhysicalDeviceFeatures2)
#define vkGetPhysicalDeviceFormatProperties2 IVK_PROTO_MACRO(vkGetPhysicalDeviceFormatProperties2)
#define vkGetPhysicalDeviceImageFormatProperties2 IVK_PROTO_MACRO(vkGetPhysicalDeviceImageFormatProperties2)
#define vkGetPhysicalDeviceMemoryProperties2 IVK_PROTO_MACRO(vkGetPhysicalDeviceMemoryProperties2)
#define vkGetPhysicalDeviceProperties2 IVK_PROTO_MACRO(vkGetPhysicalDeviceProperties2)
#define vkGetPhysicalDeviceQueueFamilyProperties2 IVK_PROTO_MACRO(vkGetPhysicalDeviceQueueFamilyProperties2)
#define vkGetPhysicalDeviceSparseImageFormatProperties2 IVK_PROTO_MACRO(vkGetPhysicalDeviceSparseImageFormatProperties2)
#define vkTrimCommandPool IVK_PROTO_MACRO(vkTrimCommandPool)
#define vkUpdateDescriptorSetWithTemplate IVK_PROTO_MACRO(vkUpdateDescriptorSetWithTemplate)
#elif defined(IVK_PROTO_DECL)
IVK_PROTO_DECL(vkBindBufferMemory2)
IVK_PROTO_DECL(vkBindImageMemory2)
IVK_PROTO_DECL(vkCmdDispatchBase)
IVK_PROTO_DECL(vkCmdSetDeviceMask)
IVK_PROTO_DECL(vkCreateDescriptorUpdateTemplate)
IVK_PROTO_DECL(vkCreateSamplerYcbcrConversion)
IVK_PROTO_DECL(vkDestroyDescriptorUpdateTemplate)
IVK_PROTO_DECL(vkDestroySamplerYcbcrConversion)
IVK_PROTO_DECL(vkEnumeratePhysicalDeviceGroups)
IVK_PROTO_DECL(vkGetBufferMemoryRequirements2)
IVK_PROTO_DECL(vkGetDescriptorSetLayoutSupport)
IVK_PROTO_DECL(vkGetDeviceGroupPeerMemoryFeatures)
IVK_PROTO_DECL(vkGetDeviceQueue2)
IVK_PROTO_DECL(vkGetImageMemoryRequirements2)
IVK_PROTO_DECL(vkGetImageSparseMemoryRequirements2)
IVK_PROTO_DECL(vkGetPhysicalDeviceExternalBufferProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceExternalFenceProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceExternalSemaphoreProperties)
IVK_PROTO_DECL(vkGetPhysicalDeviceFeatures2)
IVK_PROTO_DECL(vkGetPhysicalDeviceFormatProperties2)
IVK_PROTO_DECL(vkGetPhysicalDeviceImageFormatProperties2)
IVK_PROTO_DECL(vkGetPhysicalDeviceMemoryProperties2)
IVK_PROTO_DECL(vkGetPhysicalDeviceProperties2)
IVK_PROTO_DECL(vkGetPhysicalDeviceQueueFamilyProperties2)
IVK_PROTO_DECL(vkGetPhysicalDeviceSparseImageFormatProperties2)
IVK_PROTO_DECL(vkTrimCommandPool)
IVK_PROTO_DECL(vkUpdateDescriptorSetWithTemplate)
#endif /* !IVK_PROTO_MACRO */
#endif /* !VK_VERSION_1_1 */
