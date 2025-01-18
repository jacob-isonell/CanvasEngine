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

cmake_minimum_required(VERSION 3.30.0)

list(APPEND languages C CXX)
if (WIN32)
	list(APPEND languages RC)
endif ()

project(CanvasEngine
	VERSION 0.1.0
	DESCRIPTION "CanvasEngine is a cross platform low level library for real time rendering"
	LANGUAGES ${languages}
)

enable_testing()
include(CMakeDependentOption)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(ICANVAS_DEVMODE "Enable warning flags for development" OFF)
option(CANVAS_GRAPHICS "Enable the graphics subsystem" ON)
option(CANVAS_ENABLE_STACKTRACE "Enable stacktrace support" ON)
option(CANVAS_ENABLE_ALLOCATORS "Enables the use of setting custom allocator functions for CanvasEngine" OFF)
option(CANVAS_DISABLE_LOGS "Disables all logging API functions" OFF)
option(CANVAS_ENABLE_ASSERTS "Enables assertions for release builds. Debug builds will always have assertions" OFF)
option(CANVAS_ENABLE_TESTS "Create and build cmake test targets" OFF)
set(CANVAS_LIBRARY_KIND "" CACHE STRING "Set the library type to STATIC, SHARED or empty to use the value of BUILD_SHARED_LIBS")

if (CANVAS_GRAPHICS)
	find_package(Vulkan)
endif ()

include("cmake/system.cmake")

cmake_dependent_option(CANVAS_GRAPHICS_ENABLE_VULKAN "Enable support for VulkanAPI as a backend" ON "CANVAS_GRAPHICS;Vulkan_FOUND" OFF)
cmake_dependent_option(CANVAS_GRAPHICS_ENABLE_GTK "Use GTK for creating windows and widgets in CanvasEngine (this option only applies to linux platform)" ON "CANVAS_GRAPHICS;CANVAS_PLATFORM_LINUX" OFF)

if (CANVAS_LIBRARY_KIND STREQUAL "")
	set(lib_kind)
	set(CANVAS_SHARED BUILD_SHARED_LIBS)
else ()
	set(lib_kind ${CANVAS_LIBRARY_KIND})
	if (CANVAS_LIBRARY_KIND STREQUAL "SHARED")
		set(CANVAS_SHARED ON)
	else ()
		set(CANVAS_SHARED OFF)
	endif ()
endif ()

add_library(CanvasEngine ${lib_kind})
add_library(CanvasEngineDeps INTERFACE)

target_include_directories(CanvasEngine
PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${CMAKE_CURRENT_BINARY_DIR}/include"
)

target_compile_definitions(CanvasEngine
PUBLIC
	"$<$<CONFIG:Debug>:CANVAS_DEBUG=1>"
PRIVATE
	"ICANVAS_BUILD=1"
	"CANVAS_GRAPHICS_EXPOSE_WAYLAND"
	"CANVAS_GRAPHICS_EXPOSE_X11"
	"CANVAS_GRAPHICS_EXPOSE_WIN32"
	"CANVAS_GRAPHICS_EXPOSE_VULKAN"
)

target_compile_options(CanvasEngine
PRIVATE
	"$<$<C_COMPILER_ID:MSVC>:/std:c++23>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-std=c++23>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-fvisibility=hidden>"
)

target_link_libraries(CanvasEngine
PRIVATE
	"$<$<C_COMPILER_ID:GNU,Clang>:-luuid>"
	"$<$<PLATFORM_ID:Windows>:shlwapi>"
	"$<$<PLATFORM_ID:Windows>:rpcrt4>"
)

include("cmake/compiler_options.cmake")
if (CANVAS_PLATFORM_UNIX)
	include("cmake/wayland_and_x11.cmake")
endif ()

macro(CanvasAddCompileSource)
	target_sources(CanvasEngine
	PRIVATE
		${ARGN}
	)
endmacro()

add_subdirectory("dependencies")

target_link_libraries(CanvasEngine
PRIVATE
	CanvasEngineDeps
)

add_subdirectory("sources")

string(TIMESTAMP CANVAS_BUILD_DATE "%Y%m")

include("cmake/doxygen.cmake")

set_target_properties(CanvasEngine
PROPERTIES
	FOLDER "CanvasEngine"
)

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake_configs.hpp.in"
	"${CMAKE_CURRENT_BINARY_DIR}/include/canvas/cmake_configs.hpp"
)

add_custom_command(TARGET CanvasEngine PRE_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include"
)
