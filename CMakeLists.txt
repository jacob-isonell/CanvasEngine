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

cmake_minimum_required(VERSION 3.20.0)

if (WIN32)
  set(ICE_CMAKE_LANGUAGES C CXX RC)
else ()
  set(ICE_CMAKE_LANGUAGES C CXX)
endif ()

project(CanvasEngine
  VERSION 0.1.0.0
  LANGUAGES ${ICE_CMAKE_LANGUAGES}
)

include(CTest)
include(FindPackageHandleStandardArgs)
include(CMakeDependentOption)
include("cmake/configs.cmake")
add_library(CanvasEngine ${CANVAS_LIBRARY_KIND})
include("cmake/dependencies.cmake")
include("cmake/options.cmake")
include("cmake/doxygen.cmake")

set(ICE_HEADER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE STRING "internal" FORCE)

macro(ICE_ADDHEADERS)
  foreach (item ${ARGV})
    target_sources(CanvasEngine PRIVATE "${ICE_HEADER_PATH}/${item}")
  endforeach ()
endmacro()

add_subdirectory("sources")

if (BUILD_TESTING)
  add_subdirectory("tests")
endif ()

string(TIMESTAMP CANVAS_BUILD_DATE "%Y%m")
# file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/include" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/canvas_cmake_options.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/include/canvas_cmake_options.h"
)

message(STATUS "CanvasEngine configurations")
message(STATUS "CANVAS_SHARED           : ${CANVAS_SHARED}")
message(STATUS "CANVAS_ENABLE_LOGS      : ${CANVAS_ENABLE_LOGS}")
message(STATUS "CANVAS_GRAPHICS         : ${CANVAS_GRAPHICS}")
message(STATUS "CANVAS_ENABLE_XLIB      : ${CANVAS_ENABLE_XLIB}")
message(STATUS "CANVAS_ENABLE_WAYLAND   : ${CANVAS_ENABLE_WAYLAND}")
message(STATUS "CANVAS_ENABLE_VULKAN    : ${CANVAS_ENABLE_VULKAN}")
message(STATUS "CANVAS_ENABLE_DIRECTX12 : ${CANVAS_ENABLE_DIRECTX12}")
message(STATUS "CANVAS_AUDIO            : ${CANVAS_AUDIO}")
message(STATUS "CANVAS_NETWORK          : ${CANVAS_NETWORK}")
