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

set(ICE_DEVMODE OFF CACHE INTERNAL "Enable CanvasEngine development mode")

option(CANVAS_ENABLE_LOGS "add description here" OFF)
option(CANVAS_GRAPHICS    "add description here" ON)
option(CANVAS_AUDIO       "add description here" ON)
option(CANVAS_NETWORK     "add description here" ON)
set(CANVAS_LIBRARY_KIND "" CACHE STRING "add description here")

if (CANVAS_LIBRARY_KIND STREQUAL "SHARED")
	set(CANVAS_SHARED ON)
elseif (CANVAS_LIBRARY_KIND STREQUAL "STATIC")
	set(CANVAS_SHARED OFF)
else ()
	set(CANVAS_SHARED BUILD_SHARED_LIBS)
endif ()
