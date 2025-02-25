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
#undef vkCmdBindDescriptorSets2
#undef vkCmdBindIndexBuffer2
#undef vkCmdPushConstants2
#undef vkCmdPushDescriptorSet
#undef vkCmdPushDescriptorSet2
#undef vkCmdPushDescriptorSetWithTemplate
#undef vkCmdPushDescriptorSetWithTemplate2
#undef vkCmdSetLineStipple
#undef vkCmdSetRenderingAttachmentLocations
#undef vkCmdSetRenderingInputAttachmentIndices
#undef vkCopyImageToImage
#undef vkCopyImageToMemory
#undef vkCopyMemoryToImage
#undef vkGetDeviceImageSubresourceLayout
#undef vkGetImageSubresourceLayout2
#undef vkGetRenderingAreaGranularity
#undef vkMapMemory2
#undef vkTransitionImageLayout
#undef vkUnmapMemory2
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef VK_VERSION_1_4
#ifdef IVK_PROTO_MACRO
#define vkCmdBindDescriptorSets2 IVK_PROTO_MACRO(vkCmdBindDescriptorSets2)
#define vkCmdBindIndexBuffer2 IVK_PROTO_MACRO(vkCmdBindIndexBuffer2)
#define vkCmdPushConstants2 IVK_PROTO_MACRO(vkCmdPushConstants2)
#define vkCmdPushDescriptorSet IVK_PROTO_MACRO(vkCmdPushDescriptorSet)
#define vkCmdPushDescriptorSet2 IVK_PROTO_MACRO(vkCmdPushDescriptorSet2)
#define vkCmdPushDescriptorSetWithTemplate IVK_PROTO_MACRO(vkCmdPushDescriptorSetWithTemplate)
#define vkCmdPushDescriptorSetWithTemplate2 IVK_PROTO_MACRO(vkCmdPushDescriptorSetWithTemplate2)
#define vkCmdSetLineStipple IVK_PROTO_MACRO(vkCmdSetLineStipple)
#define vkCmdSetRenderingAttachmentLocations IVK_PROTO_MACRO(vkCmdSetRenderingAttachmentLocations)
#define vkCmdSetRenderingInputAttachmentIndices IVK_PROTO_MACRO(vkCmdSetRenderingInputAttachmentIndices)
#define vkCopyImageToImage IVK_PROTO_MACRO(vkCopyImageToImage)
#define vkCopyImageToMemory IVK_PROTO_MACRO(vkCopyImageToMemory)
#define vkCopyMemoryToImage IVK_PROTO_MACRO(vkCopyMemoryToImage)
#define vkGetDeviceImageSubresourceLayout IVK_PROTO_MACRO(vkGetDeviceImageSubresourceLayout)
#define vkGetImageSubresourceLayout2 IVK_PROTO_MACRO(vkGetImageSubresourceLayout2)
#define vkGetRenderingAreaGranularity IVK_PROTO_MACRO(vkGetRenderingAreaGranularity)
#define vkMapMemory2 IVK_PROTO_MACRO(vkMapMemory2)
#define vkTransitionImageLayout IVK_PROTO_MACRO(vkTransitionImageLayout)
#define vkUnmapMemory2 IVK_PROTO_MACRO(vkUnmapMemory2)
#elif defined(IVK_PROTO_DECL)
IVK_PROTO_DECL(vkCmdBindDescriptorSets2)
IVK_PROTO_DECL(vkCmdBindIndexBuffer2)
IVK_PROTO_DECL(vkCmdPushConstants2)
IVK_PROTO_DECL(vkCmdPushDescriptorSet)
IVK_PROTO_DECL(vkCmdPushDescriptorSet2)
IVK_PROTO_DECL(vkCmdPushDescriptorSetWithTemplate)
IVK_PROTO_DECL(vkCmdPushDescriptorSetWithTemplate2)
IVK_PROTO_DECL(vkCmdSetLineStipple)
IVK_PROTO_DECL(vkCmdSetRenderingAttachmentLocations)
IVK_PROTO_DECL(vkCmdSetRenderingInputAttachmentIndices)
IVK_PROTO_DECL(vkCopyImageToImage)
IVK_PROTO_DECL(vkCopyImageToMemory)
IVK_PROTO_DECL(vkCopyMemoryToImage)
IVK_PROTO_DECL(vkGetDeviceImageSubresourceLayout)
IVK_PROTO_DECL(vkGetImageSubresourceLayout2)
IVK_PROTO_DECL(vkGetRenderingAreaGranularity)
IVK_PROTO_DECL(vkMapMemory2)
IVK_PROTO_DECL(vkTransitionImageLayout)
IVK_PROTO_DECL(vkUnmapMemory2)
#endif /* !IVK_PROTO_MACRO */
#endif /* !VK_VERSION_1_4 */
