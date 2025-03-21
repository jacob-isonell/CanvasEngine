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

### User options
option(CANVAS_ENABLE_LOGS    "add description here" OFF)
option(CANVAS_BUILD_EXAMPLES "Builds the example projects" ON)
option(CANVAS_GRAPHICS       "Enables the graphics module" ON)
option(CANVAS_AUDIO          "Enables the audio module" ON)
option(CANVAS_NETWORK        "Enables the network module" ON)
set(CANVAS_LIBRARY_KIND "" CACHE STRING "The library kind to build. \"STATIC\" to build a statically linked library, \"SHARED\" to build a dynamically linked library, or leave as empty to follow the value of \"BUILD_SHARED_LIBS\"")

if (CANVAS_LIBRARY_KIND STREQUAL "SHARED")
  set(CANVAS_SHARED ON)
elseif (CANVAS_LIBRARY_KIND STREQUAL "STATIC")
  set(CANVAS_SHARED OFF)
else ()
  set(CANVAS_SHARED BUILD_SHARED_LIBS)
endif ()

### Advance options
option(ICANVAS_DEBUG "Enables strict compiler options for warnings, treats warnings as errors, and additional checks when compiling CanvasEngine" OFF)
