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

ICE_ADDHEADERS(
  "canvas/core.h"
  
  "canvas/core/base.h"
  "canvas/core/error.h"
  "canvas/core/library.h"
  "canvas/core/memory.h"
  "canvas/core/random.h"
  "canvas/core/time.h"
  "canvas/core/uuid.h"
  
  "canvas/core/details/base.h.inl"
  "canvas/core/details/time.h.inl"
)

target_sources(CanvasEngine
PRIVATE
  "configs.c"
  "icore_base.h"
  "icore_unix.h"
    "icore_unix.c"
  "icore_win32.h"
    "icore_win32.c"
  
PRIVATE
  "error.c"
  "library.c"
  "memory.c"
  "random.c"
  "time.c"
)
