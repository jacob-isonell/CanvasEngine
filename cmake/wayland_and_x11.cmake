# CanvasEngine is a cross platform multimedia library in C89
# Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.

include(FindPackageHandleStandardArgs)

if (NOT CANVAS_WAYLAND_CLIENT_LIBRARY)
	message(CHECK_START "Looking for wayland client")
	find_path(CANVAS_WAYLAND_CLIENT_INCLUDE_DIR NAMES wayland-client.h)
	find_library(CANVAS_WAYLAND_CLIENT_LIBRARY NAMES wayland-client libwayland-client)
	
	if ((DEFINED CANVAS_WAYLAND_CLIENT_INCLUDE_DIR) AND (DEFINED CANVAS_WAYLAND_CLIENT_LIBRARY))
		message(CHECK_PASS "found")
		set(CANVAS_WAYLAND_CLIENT_FOUND ON CACHE INTERNAL "CANVAS_WAYLAND_CLIENT_FOUND" FORCE)
		mark_as_advanced(CANVAS_WAYLAND_CLIENT_INCLUDE_DIR CANVAS_WAYLAND_CLIENT_LIBRARY)
	endif ()
endif ()

if (NOT CANVAS_WAYLAND_SERVER_LIBRARY)
	message(CHECK_START "Looking for wayland server")
	find_path(CANVAS_WAYLAND_SERVER_INCLUDE_DIR NAMES wayland-server.h)
	find_library(CANVAS_WAYLAND_SERVER_LIBRARY NAMES wayland-server libwayland-server)
	if ((DEFINED CANVAS_WAYLAND_SERVER_INCLUDE_DIR) AND (DEFINED CANVAS_WAYLAND_SERVER_LIBRARY))
		message(CHECK_PASS "found")
		set(CANVAS_WAYLAND_SERVER_FOUND ON CACHE INTERNAL "CANVAS_WAYLAND_SERVER_FOUND" FORCE)
		mark_as_advanced(CANVAS_WAYLAND_SERVER_INCLUDE_DIR CANVAS_WAYLAND_SERVER_LIBRARY)
	endif ()
endif ()

if ((DEFINED CANVAS_WAYLAND_CLIENT_INCLUDE_DIR) AND (DEFINED CANVAS_WAYLAND_CLIENT_LIBRARY))
	add_library(wayland::client UNKNOWN IMPORTED)
	
	set_target_properties(wayland::client
	PROPERTIES
		INTERFACE_INCLUDE_DIRECTORIES "${CANVAS_WAYLAND_CLIENT_INCLUDE_DIR}"
		IMPORTED_LINK_INTERFACE_LANGUAGES "C"
		IMPORTED_LOCATION "${CANVAS_WAYLAND_CLIENT_LIBRARY}"
	)
	find_package_handle_standard_args(WAYLAND_CLIENT REQUIRED_VARS CANVAS_WAYLAND_CLIENT_LIBRARY CANVAS_WAYLAND_CLIENT_INCLUDE_DIR)
endif ()

if ((DEFINED CANVAS_WAYLAND_SERVER_INCLUDE_DIR) AND (DEFINED CANVAS_WAYLAND_SERVER_LIBRARY))
	add_library(wayland::server UNKNOWN IMPORTED)
	
	set_target_properties(wayland::server
	PROPERTIES
		INTERFACE_INCLUDE_DIRECTORIES "${CANVAS_WAYLAND_SERVER_INCLUDE_DIR}"
		IMPORTED_LINK_INTERFACE_LANGUAGES "C"
		IMPORTED_LOCATION "${CANVAS_WAYLAND_SERVER_LIBRARY}"
	)
	find_package_handle_standard_args(WAYLAND_SERVER REQUIRED_VARS CANVAS_WAYLAND_SERVER_LIBRARY CANVAS_WAYLAND_SERVER_INCLUDE_DIR)
endif ()

find_package(X11 COMPONENTS Xrandr xcb xcb_randr)

cmake_dependent_option(CANVAS_GRAPHICS_SUPPORT_WAYLAND "Enable support for wayland" ON "CANVAS_GRAPHICS;CANVAS_WAYLAND_CLIENT_FOUND" OFF)
cmake_dependent_option(CANVAS_GRAPHICS_SUPPORT_X11 "Enable support for X11" ON "CANVAS_GRAPHICS;X11_FOUND" OFF)
if (CANVAS_GRAPHICS AND NOT CANVAS_GRAPHICS_SUPPORT_WAYLAND AND NOT CANVAS_GRAPHICS_SUPPORT_X11)
	message(FATAL_ERROR "CanvasEngine requires support for either X11 or Wayland on Linux but neither could be found or was enabled")
endif ()

if (CANVAS_GRAPHICS_SUPPORT_WAYLAND)
	target_link_libraries(CanvasEngineDeps
	INTERFACE
		wayland::client
	)
endif ()

if (CANVAS_GRAPHICS_SUPPORT_X11)
	target_link_libraries(CanvasEngineDeps
	INTERFACE
		X11::X11
		X11::Xrandr
		X11::xcb
		X11::xcb_randr
	)
endif ()
