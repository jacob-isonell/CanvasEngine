#########################################################################
# CanvasEngine is a cross platform multimedia library in C++20          #
# Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             #
#                                                                       #
# This program is free software: you can redistribute it and/or modify  #
# it under the terms of the GNU General Public License as published by  #
# the Free Software Foundation, either version 3 of the License, or     #
# (at your option) any later version.                                   #
#                                                                       #
# This program is distributed in the hope that it will be useful,       #
# but WITHOUT ANY WARRANTY; without even the implied warranty of        #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
# GNU General Public License for more details.                          #
#                                                                       #
# You should have received a copy of the GNU General Public License     #
# along with this program. If not, see <https://www.gnu.org/licenses/>. #
#########################################################################

add_library(CanvasEngineDependencies INTERFACE)
include(FindPackageHandleStandardArgs)

### Core module dependencies


### Graphics module dependencies

include("find_xlib.cmake")
include("find_wayland.cmake")
include("find_vulkan.cmake")

cmake_dependent_option(CANVAS_ENABLE_DIRECTX12 "Enable support for DirectX12 API" ON "CANVAS_GRAPHICS;WIN32" OFF)
if (CANVAS_GRAPHICS)
  if (UNIX)
    ICELinkXLIB(CanvasEngineDependencies INTERFACE)
    ICELinkWaylandClient(CanvasEngineDependencies INTERFACE)
    if (NOT CANVAS_ENABLE_WAYLAND AND NOT CANVAS_ENABLE_XLIB)
      message(FATAL_ERROR "CanvasEngine requires support for either xLib or Wayland on Linux but neither could be found or both were disabled")
    endif ()
  endif ()
  ICELinkVulkan(CanvasEngineDependencies INTERFACE)
  
  # if (ICE_DEVMODE)
  #   message(STATUS "Vulkan_FOUND : ${Vulkan_FOUND}")
  #   message(STATUS "CANVAS_ENABLE_VULKAN : ${CANVAS_ENABLE_VULKAN}")
  #   message(STATUS "ICE_VULKAN : ${ICE_VULKAN}")
  # endif ()
endif (CANVAS_GRAPHICS)
