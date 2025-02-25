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
#undef vkCmdBeginRenderPass2
#undef vkCmdDrawIndexedIndirectCount
#undef vkCmdDrawIndirectCount
#undef vkCmdEndRenderPass2
#undef vkCmdNextSubpass2
#undef vkCreateRenderPass2
#undef vkGetBufferDeviceAddress
#undef vkGetBufferOpaqueCaptureAddress
#undef vkGetDeviceMemoryOpaqueCaptureAddress
#undef vkGetSemaphoreCounterValue
#undef vkResetQueryPool
#undef vkSignalSemaphore
#undef vkWaitSemaphores
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef VK_VERSION_1_2
#ifdef IVK_PROTO_MACRO
#define vkCmdBeginRenderPass2 IVK_PROTO_MACRO(vkCmdBeginRenderPass2)
#define vkCmdDrawIndexedIndirectCount IVK_PROTO_MACRO(vkCmdDrawIndexedIndirectCount)
#define vkCmdDrawIndirectCount IVK_PROTO_MACRO(vkCmdDrawIndirectCount)
#define vkCmdEndRenderPass2 IVK_PROTO_MACRO(vkCmdEndRenderPass2)
#define vkCmdNextSubpass2 IVK_PROTO_MACRO(vkCmdNextSubpass2)
#define vkCreateRenderPass2 IVK_PROTO_MACRO(vkCreateRenderPass2)
#define vkGetBufferDeviceAddress IVK_PROTO_MACRO(vkGetBufferDeviceAddress)
#define vkGetBufferOpaqueCaptureAddress IVK_PROTO_MACRO(vkGetBufferOpaqueCaptureAddress)
#define vkGetDeviceMemoryOpaqueCaptureAddress IVK_PROTO_MACRO(vkGetDeviceMemoryOpaqueCaptureAddress)
#define vkGetSemaphoreCounterValue IVK_PROTO_MACRO(vkGetSemaphoreCounterValue)
#define vkResetQueryPool IVK_PROTO_MACRO(vkResetQueryPool)
#define vkSignalSemaphore IVK_PROTO_MACRO(vkSignalSemaphore)
#define vkWaitSemaphores IVK_PROTO_MACRO(vkWaitSemaphores)
#elif defined(IVK_PROTO_DECL)
IVK_PROTO_DECL(vkCmdBeginRenderPass2)
IVK_PROTO_DECL(vkCmdDrawIndexedIndirectCount)
IVK_PROTO_DECL(vkCmdDrawIndirectCount)
IVK_PROTO_DECL(vkCmdEndRenderPass2)
IVK_PROTO_DECL(vkCmdNextSubpass2)
IVK_PROTO_DECL(vkCreateRenderPass2)
IVK_PROTO_DECL(vkGetBufferDeviceAddress)
IVK_PROTO_DECL(vkGetBufferOpaqueCaptureAddress)
IVK_PROTO_DECL(vkGetDeviceMemoryOpaqueCaptureAddress)
IVK_PROTO_DECL(vkGetSemaphoreCounterValue)
IVK_PROTO_DECL(vkResetQueryPool)
IVK_PROTO_DECL(vkSignalSemaphore)
IVK_PROTO_DECL(vkWaitSemaphores)
#endif /* !IVK_PROTO_MACRO */
#endif /* !VK_VERSION_1_2 */
