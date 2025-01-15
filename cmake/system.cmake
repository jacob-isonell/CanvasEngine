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

if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
	set(CANVAS_COMPILER_CLANG ON)
	message(VERBOSE "CanvasEngine : Current platform detected : Clang")
elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
	set(CANVAS_COMPILER_CLANG ON)
	message(VERBOSE "CanvasEngine : Current platform detected : Clang")
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
	set(CANVAS_COMPILER_MSVC ON)
	message(VERBOSE "CanvasEngine : Current platform detected : MSVC")
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
	set(CANVAS_COMPILER_GCC ON)
	message(VERBOSE "CanvasEngine : Current platform detected : GCC")
endif ()

if (CANVAS_COMPILER_CLANG OR CANVAS_COMPILER_GCC)
	set(CANVAS_COMPILER_GNU ON)
endif ()

if (WIN32)
	set(CANVAS_PLATFORM_WINDOWS ON)
	message(VERBOSE "CanvasEngine : Current platform detected : Windows")
elseif (LINUX)
	set(CANVAS_PLATFORM_UNIX ON)
	set(CANVAS_PLATFORM_LINUX ON)
	message(VERBOSE "CanvasEngine : Current platform detected : Linux")
elseif (UNIX)
	set(CANVAS_PLATFORM_UNIX ON)
	message(VERBOSE "CanvasEngine : Current platform detected : Unix")
else()
	message(FATAL_ERROR "CanvasEngine does not support the current OS")
endif ()
