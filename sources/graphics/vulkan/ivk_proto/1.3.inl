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
#undef vkCmdBeginRendering
#undef vkCmdBindVertexBuffers2
#undef vkCmdBlitImage2
#undef vkCmdCopyBuffer2
#undef vkCmdCopyBufferToImage2
#undef vkCmdCopyImage2
#undef vkCmdCopyImageToBuffer2
#undef vkCmdEndRendering
#undef vkCmdPipelineBarrier2
#undef vkCmdResetEvent2
#undef vkCmdResolveImage2
#undef vkCmdSetCullMode
#undef vkCmdSetDepthBiasEnable
#undef vkCmdSetDepthBoundsTestEnable
#undef vkCmdSetDepthCompareOp
#undef vkCmdSetDepthTestEnable
#undef vkCmdSetDepthWriteEnable
#undef vkCmdSetEvent2
#undef vkCmdSetFrontFace
#undef vkCmdSetPrimitiveRestartEnable
#undef vkCmdSetPrimitiveTopology
#undef vkCmdSetRasterizerDiscardEnable
#undef vkCmdSetScissorWithCount
#undef vkCmdSetStencilOp
#undef vkCmdSetStencilTestEnable
#undef vkCmdSetViewportWithCount
#undef vkCmdWaitEvents2
#undef vkCmdWriteTimestamp2
#undef vkCreatePrivateDataSlot
#undef vkDestroyPrivateDataSlot
#undef vkGetDeviceBufferMemoryRequirements
#undef vkGetDeviceImageMemoryRequirements
#undef vkGetDeviceImageSparseMemoryRequirements
#undef vkGetPhysicalDeviceToolProperties
#undef vkGetPrivateData
#undef vkQueueSubmit2
#undef vkSetPrivateData
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef VK_VERSION_1_3
#ifdef IVK_PROTO_MACRO
#define vkCmdBeginRendering IVK_PROTO_MACRO(vkCmdBeginRendering)
#define vkCmdBindVertexBuffers2 IVK_PROTO_MACRO(vkCmdBindVertexBuffers2)
#define vkCmdBlitImage2 IVK_PROTO_MACRO(vkCmdBlitImage2)
#define vkCmdCopyBuffer2 IVK_PROTO_MACRO(vkCmdCopyBuffer2)
#define vkCmdCopyBufferToImage2 IVK_PROTO_MACRO(vkCmdCopyBufferToImage2)
#define vkCmdCopyImage2 IVK_PROTO_MACRO(vkCmdCopyImage2)
#define vkCmdCopyImageToBuffer2 IVK_PROTO_MACRO(vkCmdCopyImageToBuffer2)
#define vkCmdEndRendering IVK_PROTO_MACRO(vkCmdEndRendering)
#define vkCmdPipelineBarrier2 IVK_PROTO_MACRO(vkCmdPipelineBarrier2)
#define vkCmdResetEvent2 IVK_PROTO_MACRO(vkCmdResetEvent2)
#define vkCmdResolveImage2 IVK_PROTO_MACRO(vkCmdResolveImage2)
#define vkCmdSetCullMode IVK_PROTO_MACRO(vkCmdSetCullMode)
#define vkCmdSetDepthBiasEnable IVK_PROTO_MACRO(vkCmdSetDepthBiasEnable)
#define vkCmdSetDepthBoundsTestEnable IVK_PROTO_MACRO(vkCmdSetDepthBoundsTestEnable)
#define vkCmdSetDepthCompareOp IVK_PROTO_MACRO(vkCmdSetDepthCompareOp)
#define vkCmdSetDepthTestEnable IVK_PROTO_MACRO(vkCmdSetDepthTestEnable)
#define vkCmdSetDepthWriteEnable IVK_PROTO_MACRO(vkCmdSetDepthWriteEnable)
#define vkCmdSetEvent2 IVK_PROTO_MACRO(vkCmdSetEvent2)
#define vkCmdSetFrontFace IVK_PROTO_MACRO(vkCmdSetFrontFace)
#define vkCmdSetPrimitiveRestartEnable IVK_PROTO_MACRO(vkCmdSetPrimitiveRestartEnable)
#define vkCmdSetPrimitiveTopology IVK_PROTO_MACRO(vkCmdSetPrimitiveTopology)
#define vkCmdSetRasterizerDiscardEnable IVK_PROTO_MACRO(vkCmdSetRasterizerDiscardEnable)
#define vkCmdSetScissorWithCount IVK_PROTO_MACRO(vkCmdSetScissorWithCount)
#define vkCmdSetStencilOp IVK_PROTO_MACRO(vkCmdSetStencilOp)
#define vkCmdSetStencilTestEnable IVK_PROTO_MACRO(vkCmdSetStencilTestEnable)
#define vkCmdSetViewportWithCount IVK_PROTO_MACRO(vkCmdSetViewportWithCount)
#define vkCmdWaitEvents2 IVK_PROTO_MACRO(vkCmdWaitEvents2)
#define vkCmdWriteTimestamp2 IVK_PROTO_MACRO(vkCmdWriteTimestamp2)
#define vkCreatePrivateDataSlot IVK_PROTO_MACRO(vkCreatePrivateDataSlot)
#define vkDestroyPrivateDataSlot IVK_PROTO_MACRO(vkDestroyPrivateDataSlot)
#define vkGetDeviceBufferMemoryRequirements IVK_PROTO_MACRO(vkGetDeviceBufferMemoryRequirements)
#define vkGetDeviceImageMemoryRequirements IVK_PROTO_MACRO(vkGetDeviceImageMemoryRequirements)
#define vkGetDeviceImageSparseMemoryRequirements IVK_PROTO_MACRO(vkGetDeviceImageSparseMemoryRequirements)
#define vkGetPhysicalDeviceToolProperties IVK_PROTO_MACRO(vkGetPhysicalDeviceToolProperties)
#define vkGetPrivateData IVK_PROTO_MACRO(vkGetPrivateData)
#define vkQueueSubmit2 IVK_PROTO_MACRO(vkQueueSubmit2)
#define vkSetPrivateData IVK_PROTO_MACRO(vkSetPrivateData)
#elif defined(IVK_PROTO_DECL)
IVK_PROTO_DECL(vkCmdBeginRendering)
IVK_PROTO_DECL(vkCmdBindVertexBuffers2)
IVK_PROTO_DECL(vkCmdBlitImage2)
IVK_PROTO_DECL(vkCmdCopyBuffer2)
IVK_PROTO_DECL(vkCmdCopyBufferToImage2)
IVK_PROTO_DECL(vkCmdCopyImage2)
IVK_PROTO_DECL(vkCmdCopyImageToBuffer2)
IVK_PROTO_DECL(vkCmdEndRendering)
IVK_PROTO_DECL(vkCmdPipelineBarrier2)
IVK_PROTO_DECL(vkCmdResetEvent2)
IVK_PROTO_DECL(vkCmdResolveImage2)
IVK_PROTO_DECL(vkCmdSetCullMode)
IVK_PROTO_DECL(vkCmdSetDepthBiasEnable)
IVK_PROTO_DECL(vkCmdSetDepthBoundsTestEnable)
IVK_PROTO_DECL(vkCmdSetDepthCompareOp)
IVK_PROTO_DECL(vkCmdSetDepthTestEnable)
IVK_PROTO_DECL(vkCmdSetDepthWriteEnable)
IVK_PROTO_DECL(vkCmdSetEvent2)
IVK_PROTO_DECL(vkCmdSetFrontFace)
IVK_PROTO_DECL(vkCmdSetPrimitiveRestartEnable)
IVK_PROTO_DECL(vkCmdSetPrimitiveTopology)
IVK_PROTO_DECL(vkCmdSetRasterizerDiscardEnable)
IVK_PROTO_DECL(vkCmdSetScissorWithCount)
IVK_PROTO_DECL(vkCmdSetStencilOp)
IVK_PROTO_DECL(vkCmdSetStencilTestEnable)
IVK_PROTO_DECL(vkCmdSetViewportWithCount)
IVK_PROTO_DECL(vkCmdWaitEvents2)
IVK_PROTO_DECL(vkCmdWriteTimestamp2)
IVK_PROTO_DECL(vkCreatePrivateDataSlot)
IVK_PROTO_DECL(vkDestroyPrivateDataSlot)
IVK_PROTO_DECL(vkGetDeviceBufferMemoryRequirements)
IVK_PROTO_DECL(vkGetDeviceImageMemoryRequirements)
IVK_PROTO_DECL(vkGetDeviceImageSparseMemoryRequirements)
IVK_PROTO_DECL(vkGetPhysicalDeviceToolProperties)
IVK_PROTO_DECL(vkGetPrivateData)
IVK_PROTO_DECL(vkQueueSubmit2)
IVK_PROTO_DECL(vkSetPrivateData)
#endif /* !IVK_PROTO_MACRO */
#endif /* !VK_VERSION_1_3 */
