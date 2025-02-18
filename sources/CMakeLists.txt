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

add_subdirectory("core")
target_include_directories(CanvasEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/core")
add_subdirectory("threads")
target_include_directories(CanvasEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/threads")
if (CANVAS_GRAPHICS)
	add_subdirectory("graphics")
	target_include_directories(CanvasEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/graphics")
endif ()
if (CANVAS_AUDIO)
	add_subdirectory("audio")
	target_include_directories(CanvasEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/audio")
endif ()
if (CANVAS_NETWORK)
	add_subdirectory("network")
	target_include_directories(CanvasEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/network")
endif ()
