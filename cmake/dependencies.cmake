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

### Core module dependencies


### Graphics module dependencies
if (CANVAS_GRAPHICS)
	### X11/Wayland libraries
	if (UNIX)
		include("cmake/find_x11.cmake")
		include("cmake/find_wayland.cmake")
		if (CANVAS_GRAPHICS AND NOT CANVAS_GRAPHICS_SUPPORT_WAYLAND AND NOT CANVAS_GRAPHICS_SUPPORT_X11)
			message(FATAL_ERROR "CanvasEngine requires support for either X11 or Wayland on Linux but neither could be found or was enabled")
		endif ()
	endif ()

	### Vulkan
	find_package(Vulkan)
	if (Vulkan_FOUND)
		target_link_libraries(CanvasEngineDependencies INTERFACE
			# Vulkan::Vulkan
			Vulkan::Headers
		)
		set(ICE_VULKAN ON)
	endif (Vulkan_FOUND)
endif (CANVAS_GRAPHICS)
