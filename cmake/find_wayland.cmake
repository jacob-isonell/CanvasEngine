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

macro(ICEFindWaylandClient)
  if (NOT ICE_WAYLAND_CLIENT_LIBRARY)
    message(CHECK_START "Looking for wayland client")
    find_path(ICE_WAYLAND_CLIENT_INCLUDE_DIR NAMES wayland-client.h)
    find_library(ICE_WAYLAND_CLIENT_LIBRARY NAMES wayland-client libwayland-client)
    
    if (ICE_WAYLAND_CLIENT_INCLUDE_DIR AND ICE_WAYLAND_CLIENT_LIBRARY)
      message(CHECK_PASS "found")
      set(ICE_WAYLAND_CLIENT_FOUND ON)
      mark_as_advanced(ICE_WAYLAND_CLIENT_INCLUDE_DIR ICE_WAYLAND_CLIENT_LIBRARY)
    endif ()
  endif ()
  
  if (ICE_WAYLAND_CLIENT_INCLUDE_DIR AND ICE_WAYLAND_CLIENT_LIBRARY)
    add_library(ice_wayland::client UNKNOWN IMPORTED)
    
    set_target_properties(ice_wayland::client
    PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${ICE_WAYLAND_CLIENT_INCLUDE_DIR}"
      IMPORTED_LINK_INTERFACE_LANGUAGES "C"
      IMPORTED_LOCATION "${ICE_WAYLAND_CLIENT_LIBRARY}"
    )
    find_package_handle_standard_args(WAYLAND_CLIENT REQUIRED_VARS ICE_WAYLAND_CLIENT_LIBRARY ICE_WAYLAND_CLIENT_INCLUDE_DIR)
  endif ()
endmacro()

macro(ICEFindWaylandServer)
  if (NOT ICE_WAYLAND_SERVER_LIBRARY)
    message(CHECK_START "Looking for wayland server")
    find_path(ICE_WAYLAND_SERVER_INCLUDE_DIR NAMES wayland-server.h)
    find_library(ICE_WAYLAND_SERVER_LIBRARY NAMES wayland-server libwayland-server)
    if (ICE_WAYLAND_SERVER_INCLUDE_DIR AND ICE_WAYLAND_SERVER_LIBRARY)
      message(CHECK_PASS "found")
      set(ICE_WAYLAND_SERVER_FOUND ON)
      mark_as_advanced(ICE_WAYLAND_SERVER_INCLUDE_DIR ICE_WAYLAND_SERVER_LIBRARY)
    endif ()
  endif ()
  
  if (ICE_WAYLAND_SERVER_INCLUDE_DIR AND ICE_WAYLAND_SERVER_LIBRARY)
    add_library(ice_wayland::server UNKNOWN IMPORTED)
    
    set_target_properties(ice_wayland::server
    PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${ICE_WAYLAND_SERVER_INCLUDE_DIR}"
      IMPORTED_LINK_INTERFACE_LANGUAGES "C"
      IMPORTED_LOCATION "${ICE_WAYLAND_SERVER_LIBRARY}"
    )
    find_package_handle_standard_args(WAYLAND_SERVER REQUIRED_VARS ICE_WAYLAND_SERVER_LIBRARY ICE_WAYLAND_SERVER_INCLUDE_DIR)
  endif ()
endmacro()

ICEFindWaylandClient()
cmake_dependent_option(CANVAS_ENABLE_WAYLAND "Enable support for wayland" ON "CANVAS_GRAPHICS;ICE_WAYLAND_CLIENT_FOUND" OFF)
if (CANVAS_ENABLE_WAYLAND)
  target_link_libraries(CanvasEngineDependencies INTERFACE
    ice_wayland::client
  )
endif ()
