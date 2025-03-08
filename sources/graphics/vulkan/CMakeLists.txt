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

target_sources(CanvasEngine
PRIVATE
  "setup.c"
  "driver.c"
  "ivk_load.h"
    "ivk_load.c"
  "ivk_proto.h"
    "ivk_proto.c"
    "ivk_proto/1.0.inl"
    "ivk_proto/1.1.inl"
    "ivk_proto/1.2.inl"
    "ivk_proto/1.3.inl"
    "ivk_proto/1.4.inl"
    "ivk_proto/all.inl"
    "ivk_proto/ext.inl"
    "ivk_proto/global.inl"
  "ivk_dev.h"
    "ivk_dev.c"
)
