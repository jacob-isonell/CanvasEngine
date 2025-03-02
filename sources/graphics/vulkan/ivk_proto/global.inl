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
#  undef vkCreateInstance
#  ifdef VK_VERSION_1_1
#    undef vkEnumerateInstanceVersion
#  endif /* !VK_VERSION_1_1 */
#  undef vkEnumerateInstanceExtensionProperties
#  undef vkEnumerateInstanceLayerProperties
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef IVK_PROTO_MACRO
#  define vkCreateInstance IVK_PROTO_MACRO(vkCreateInstance)
#  ifdef VK_VERSION_1_1
#    define vkEnumerateInstanceVersion IVK_PROTO_MACRO(vkEnumerateInstanceVersion)
#  endif /* !VK_VERSION_1_1 */
#  define vkEnumerateInstanceExtensionProperties IVK_PROTO_MACRO(vkEnumerateInstanceExtensionProperties)
#  define vkEnumerateInstanceLayerProperties IVK_PROTO_MACRO(vkEnumerateInstanceLayerProperties)
#  define vkCreateInstance IVK_PROTO_MACRO(vkCreateInstance)
#elif defined(IVK_PROTO_DECL)
IVK_PROTO_DECL(vkCreateInstance)
#  ifdef VK_VERSION_1_1
IVK_PROTO_DECL(vkEnumerateInstanceVersion)
#  endif /* !VK_VERSION_1_1 */
IVK_PROTO_DECL(vkEnumerateInstanceExtensionProperties)
IVK_PROTO_DECL(vkEnumerateInstanceLayerProperties)
#endif /* !IVK_PROTO_MACRO */
