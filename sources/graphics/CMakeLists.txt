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
  "canvas/graphics.h"
  
  "canvas/graphics/driver.h"
  "canvas/graphics/graphics.h"
)

target_sources(CanvasEngine
PRIVATE
  "ifx_base.h"
  "ifx_vk.h"
)

if (CANVAS_ENABLE_VULKAN)
  ICE_ADDDIR("vulkan")
endif ()
if (CANVAS_ENABLE_DIRECTX12)
  ICE_ADDDIR("directx12")
endif ()
