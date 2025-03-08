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
#ifdef VK_KHR_surface
#undef vkCreateDisplayModeKHR
#undef vkCreateDisplayPlaneSurfaceKHR
#undef vkGetDisplayModePropertiesKHR
#undef vkGetDisplayPlaneCapabilitiesKHR
#undef vkGetDisplayPlaneSupportedDisplaysKHR
#undef vkGetPhysicalDeviceDisplayPlanePropertiesKHR
#undef vkGetPhysicalDeviceDisplayPropertiesKHR
# ifdef VK_KHR_swapchain
#   undef vkAcquireNextImageKHR
#   undef vkCreateSwapchainKHR
#   undef vkDestroySwapchainKHR
#   undef vkGetSwapchainImagesKHR
#   undef vkQueuePresentKHR
#   ifdef VK_VERSION_1_1
#     undef vkAcquireNextImage2KHR
#     undef vkGetDeviceGroupPresentCapabilitiesKHR
#     undef vkGetDeviceGroupSurfacePresentModesKHR
#     undef vkGetPhysicalDevicePresentRectanglesKHR
#   endif /* !VK_VERSION_1_1 */
# endif /* !VK_KHR_swapchain */
# ifdef VK_KHR_android_surface
#   undef vkCreateAndroidSurfaceKHR
# endif /* !VK_KHR_android_surface */
# ifdef CANVAS_ENABLE_WAYLAND
#   ifdef VK_KHR_wayland_surface
#     undef vkCreateWaylandSurfaceKHR
#     undef vkGetPhysicalDeviceWaylandPresentationSupportKHR
#   endif /* !VK_KHR_wayland_surface */
# endif /* !CANVAS_ENABLE_WAYLAND */
# ifdef CANVAS_ENABLE_XLIB
#   ifdef VK_KHR_xlib_surface
#     undef vkCreateXcbSurfaceKHR
#     undef vkGetPhysicalDeviceXcbPresentationSupportKHR
#   endif /* !VK_KHR_xlib_surface */
#   ifdef VK_KHR_xcb_surface
#     undef vkCreateXlibSurfaceKHR
#     undef vkGetPhysicalDeviceXlibPresentationSupportKHR
#   endif /* !VK_KHR_xcb_surface */
# endif /* !CANVAS_ENABLE_XLIB */
# if CANVAS_PLATFORM_WINDOWS
#   ifdef VK_KHR_win32_surface
#     undef vkCreateWin32SurfaceKHR
#     undef vkGetPhysicalDeviceWin32PresentationSupportKHR
#   endif
# endif /* !CANVAS_PLATFORM_WINDOWS */
#endif /* !VK_KHR_surface */
#ifdef VK_KHR_display
#undef vkCreateDisplayModeKHR
#undef vkCreateDisplayPlaneSurfaceKHR
#undef vkGetDisplayModePropertiesKHR
#undef vkGetDisplayPlaneCapabilitiesKHR
#undef vkGetDisplayPlaneSupportedDisplaysKHR
#undef vkGetPhysicalDeviceDisplayPlanePropertiesKHR
#undef vkGetPhysicalDeviceDisplayPropertiesKHR
#endif /* !VK_KHR_display */
#ifdef VK_KHR_display_swapchain
#undef vkCreateSharedSwapchainsKHR
#endif /* !VK_KHR_display_swapchain */
#ifdef VK_KHR_get_physical_device_properties2
# undef vkGetPhysicalDeviceFeatures2KHR
# undef vkGetPhysicalDeviceFormatProperties2KHR
# undef vkGetPhysicalDeviceImageFormatProperties2KHR
# undef vkGetPhysicalDeviceMemoryProperties2KHR
# undef vkGetPhysicalDeviceProperties2KHR
# undef vkGetPhysicalDeviceQueueFamilyProperties2KHR
# undef vkGetPhysicalDeviceSparseImageFormatProperties2KHR
#endif /* !VK_KHR_get_physical_device_properties2 */
#ifdef VK_KHR_synchronization2
#undef vkCmdPipelineBarrier2KHR
#undef vkCmdResetEvent2KHR
#undef vkCmdSetEvent2KHR
#undef vkCmdWaitEvents2KHR
#undef vkCmdWriteTimestamp2KHR
#undef vkQueueSubmit2KHR
#endif /* !VK_KHR_synchronization2 */
#endif /* !IVK_PROTO_NO_UNDEF */

#ifdef IVK_PROTO_MACRO
#ifdef VK_KHR_surface
#define vkCreateDisplayModeKHR IVK_PROTO_MACRO(vkCreateDisplayModeKHR)
#define vkCreateDisplayPlaneSurfaceKHR IVK_PROTO_MACRO(vkCreateDisplayPlaneSurfaceKHR)
#define vkGetDisplayModePropertiesKHR IVK_PROTO_MACRO(vkGetDisplayModePropertiesKHR)
#define vkGetDisplayPlaneCapabilitiesKHR IVK_PROTO_MACRO(vkGetDisplayPlaneCapabilitiesKHR)
#define vkGetDisplayPlaneSupportedDisplaysKHR IVK_PROTO_MACRO(vkGetDisplayPlaneSupportedDisplaysKHR)
#define vkGetPhysicalDeviceDisplayPlanePropertiesKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceDisplayPlanePropertiesKHR)
#define vkGetPhysicalDeviceDisplayPropertiesKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceDisplayPropertiesKHR)
# ifdef VK_KHR_swapchain
#   define vkAcquireNextImageKHR IVK_PROTO_MACRO(vkAcquireNextImageKHR)
#   define vkCreateSwapchainKHR IVK_PROTO_MACRO(vkCreateSwapchainKHR)
#   define vkDestroySwapchainKHR IVK_PROTO_MACRO(vkDestroySwapchainKHR)
#   define vkGetSwapchainImagesKHR IVK_PROTO_MACRO(vkGetSwapchainImagesKHR)
#   define vkQueuePresentKHR IVK_PROTO_MACRO(vkQueuePresentKHR)
#   ifdef VK_VERSION_1_1
#     define vkAcquireNextImage2KHR IVK_PROTO_MACRO(vkAcquireNextImage2KHR)
#     define vkGetDeviceGroupPresentCapabilitiesKHR IVK_PROTO_MACRO(vkGetDeviceGroupPresentCapabilitiesKHR)
#     define vkGetDeviceGroupSurfacePresentModesKHR IVK_PROTO_MACRO(vkGetDeviceGroupSurfacePresentModesKHR)
#     define vkGetPhysicalDevicePresentRectanglesKHR IVK_PROTO_MACRO(vkGetPhysicalDevicePresentRectanglesKHR)
#   endif /* !VK_VERSION_1_1 */
# endif /* !VK_KHR_swapchain */
# ifdef VK_KHR_android_surface
#   define vkCreateAndroidSurfaceKHR IVK_PROTO_MACRO(vkCreateAndroidSurfaceKHR)
# endif /* !VK_KHR_android_surface */
# ifdef CANVAS_ENABLE_WAYLAND
#   ifdef VK_KHR_wayland_surface
#     define vkCreateWaylandSurfaceKHR IVK_PROTO_MACRO(vkCreateWaylandSurfaceKHR)
#     define vkGetPhysicalDeviceWaylandPresentationSupportKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceWaylandPresentationSupportKHR)
#   endif /* !VK_KHR_wayland_surface */
# endif /* !CANVAS_ENABLE_WAYLAND */
# ifdef CANVAS_ENABLE_XLIB
#   ifdef VK_KHR_xlib_surface
#     define vkCreateXcbSurfaceKHR IVK_PROTO_MACRO(vkCreateXcbSurfaceKHR)
#     define vkGetPhysicalDeviceXcbPresentationSupportKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceXcbPresentationSupportKHR)
#   endif /* !VK_KHR_xlib_surface */
#   ifdef VK_KHR_xcb_surface
#     define vkCreateXlibSurfaceKHR IVK_PROTO_MACRO(vkCreateXlibSurfaceKHR)
#     define vkGetPhysicalDeviceXlibPresentationSupportKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceXlibPresentationSupportKHR)
#   endif /* !VK_KHR_xcb_surface */
# endif /* !CANVAS_ENABLE_XLIB */
# if CANVAS_PLATFORM_WINDOWS
#   ifdef VK_KHR_win32_surface
#     define vkCreateWin32SurfaceKHR IVK_PROTO_MACRO(vkCreateWin32SurfaceKHR)
#     define vkGetPhysicalDeviceWin32PresentationSupportKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceWin32PresentationSupportKHR)
#   endif
# endif /* !CANVAS_PLATFORM_WINDOWS */
#endif /* !VK_KHR_surface */
#ifdef VK_KHR_display
#define vkCreateDisplayModeKHR IVK_PROTO_MACRO(vkCreateDisplayModeKHR)
#define vkCreateDisplayPlaneSurfaceKHR IVK_PROTO_MACRO(vkCreateDisplayPlaneSurfaceKHR)
#define vkGetDisplayModePropertiesKHR IVK_PROTO_MACRO(vkGetDisplayModePropertiesKHR)
#define vkGetDisplayPlaneCapabilitiesKHR IVK_PROTO_MACRO(vkGetDisplayPlaneCapabilitiesKHR)
#define vkGetDisplayPlaneSupportedDisplaysKHR IVK_PROTO_MACRO(vkGetDisplayPlaneSupportedDisplaysKHR)
#define vkGetPhysicalDeviceDisplayPlanePropertiesKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceDisplayPlanePropertiesKHR)
#define vkGetPhysicalDeviceDisplayPropertiesKHR IVK_PROTO_MACRO(vkGetPhysicalDeviceDisplayPropertiesKHR)
#endif /* !VK_KHR_display */
#ifdef VK_KHR_display_swapchain
#define vkCreateSharedSwapchainsKHR IVK_PROTO_MACRO(vkCreateSharedSwapchainsKHR)
#endif /* !VK_KHR_display_swapchain */
#ifdef VK_KHR_get_physical_device_properties2
# define vkGetPhysicalDeviceFeatures2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceFeatures2KHR)
# define vkGetPhysicalDeviceFormatProperties2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceFormatProperties2KHR)
# define vkGetPhysicalDeviceImageFormatProperties2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceImageFormatProperties2KHR)
# define vkGetPhysicalDeviceMemoryProperties2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceMemoryProperties2KHR)
# define vkGetPhysicalDeviceProperties2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceProperties2KHR)
# define vkGetPhysicalDeviceQueueFamilyProperties2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceQueueFamilyProperties2KHR)
# define vkGetPhysicalDeviceSparseImageFormatProperties2KHR IVK_PROTO_MACRO(vkGetPhysicalDeviceSparseImageFormatProperties2KHR)
#endif /* !VK_KHR_get_physical_device_properties2 */
#ifdef VK_KHR_synchronization2
#define vkCmdPipelineBarrier2KHR IVK_PROTO_MACRO(vkCmdPipelineBarrier2KHR)
#define vkCmdResetEvent2KHR IVK_PROTO_MACRO(vkCmdResetEvent2KHR)
#define vkCmdSetEvent2KHR IVK_PROTO_MACRO(vkCmdSetEvent2KHR)
#define vkCmdWaitEvents2KHR IVK_PROTO_MACRO(vkCmdWaitEvents2KHR)
#define vkCmdWriteTimestamp2KHR IVK_PROTO_MACRO(vkCmdWriteTimestamp2KHR)
#define vkQueueSubmit2KHR IVK_PROTO_MACRO(vkQueueSubmit2KHR)
#endif /* !VK_KHR_synchronization2 */

#elif defined(IVK_PROTO_DECL)
#ifdef VK_KHR_surface
IVK_PROTO_DECL(vkCreateDisplayModeKHR)
IVK_PROTO_DECL(vkCreateDisplayPlaneSurfaceKHR)
IVK_PROTO_DECL(vkGetDisplayModePropertiesKHR)
IVK_PROTO_DECL(vkGetDisplayPlaneCapabilitiesKHR)
IVK_PROTO_DECL(vkGetDisplayPlaneSupportedDisplaysKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceDisplayPlanePropertiesKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceDisplayPropertiesKHR)
# ifdef VK_KHR_swapchain
IVK_PROTO_DECL(vkAcquireNextImageKHR)
IVK_PROTO_DECL(vkCreateSwapchainKHR)
IVK_PROTO_DECL(vkDestroySwapchainKHR)
IVK_PROTO_DECL(vkGetSwapchainImagesKHR)
IVK_PROTO_DECL(vkQueuePresentKHR)
#   ifdef VK_VERSION_1_1
IVK_PROTO_DECL(vkAcquireNextImage2KHR)
IVK_PROTO_DECL(vkGetDeviceGroupPresentCapabilitiesKHR)
IVK_PROTO_DECL(vkGetDeviceGroupSurfacePresentModesKHR)
IVK_PROTO_DECL(vkGetPhysicalDevicePresentRectanglesKHR)
#   endif /* !VK_VERSION_1_1 */
# endif /* !VK_KHR_swapchain */
# ifdef VK_KHR_android_surface
IVK_PROTO_DECL(vkCreateAndroidSurfaceKHR)
# endif /* !VK_KHR_android_surface */
# ifdef CANVAS_ENABLE_WAYLAND
#   ifdef VK_KHR_wayland_surface
IVK_PROTO_DECL(vkCreateWaylandSurfaceKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceWaylandPresentationSupportKHR)
#   endif /* !VK_KHR_wayland_surface */
# endif /* !CANVAS_ENABLE_WAYLAND */
# ifdef CANVAS_ENABLE_XLIB
#   ifdef VK_KHR_xlib_surface
IVK_PROTO_DECL(vkCreateXcbSurfaceKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceXcbPresentationSupportKHR)
#   endif /* !VK_KHR_xlib_surface */
#   ifdef VK_KHR_xcb_surface
IVK_PROTO_DECL(vkCreateXlibSurfaceKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceXlibPresentationSupportKHR)
#   endif /* !VK_KHR_xcb_surface */
# endif /* !CANVAS_ENABLE_XLIB */
# if CANVAS_PLATFORM_WINDOWS
#   ifdef VK_KHR_win32_surface
IVK_PROTO_DECL(vkCreateWin32SurfaceKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceWin32PresentationSupportKHR)
#   endif
# endif /* !CANVAS_PLATFORM_WINDOWS */
#endif /* !VK_KHR_surface */
#ifdef VK_KHR_display
IVK_PROTO_DECL(vkCreateDisplayModeKHR)
IVK_PROTO_DECL(vkCreateDisplayPlaneSurfaceKHR)
IVK_PROTO_DECL(vkGetDisplayModePropertiesKHR)
IVK_PROTO_DECL(vkGetDisplayPlaneCapabilitiesKHR)
IVK_PROTO_DECL(vkGetDisplayPlaneSupportedDisplaysKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceDisplayPlanePropertiesKHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceDisplayPropertiesKHR)
#endif /* !VK_KHR_display */
#ifdef VK_KHR_display_swapchain
IVK_PROTO_DECL(vkCreateSharedSwapchainsKHR)
#endif /* !VK_KHR_display_swapchain */
#ifdef VK_KHR_get_physical_device_properties2
IVK_PROTO_DECL(vkGetPhysicalDeviceFeatures2KHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceFormatProperties2KHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceImageFormatProperties2KHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceMemoryProperties2KHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceProperties2KHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceQueueFamilyProperties2KHR)
IVK_PROTO_DECL(vkGetPhysicalDeviceSparseImageFormatProperties2KHR)
#endif /* !VK_KHR_get_physical_device_properties2 */
#ifdef VK_KHR_synchronization2
IVK_PROTO_DECL(vkCmdPipelineBarrier2KHR)
IVK_PROTO_DECL(vkCmdResetEvent2KHR)
IVK_PROTO_DECL(vkCmdSetEvent2KHR)
IVK_PROTO_DECL(vkCmdWaitEvents2KHR)
IVK_PROTO_DECL(vkCmdWriteTimestamp2KHR)
IVK_PROTO_DECL(vkQueueSubmit2KHR)
#endif /* !VK_KHR_synchronization2 */

#endif /* !IVK_PROTO_MACRO */
