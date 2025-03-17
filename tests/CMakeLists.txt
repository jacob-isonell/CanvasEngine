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

macro(ICEAddTest target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} PRIVATE CanvasEngine)
  target_compile_features(${target} PRIVATE c_std_11)
  set_target_properties(${target}
  PROPERTIES
    FOLDER "CanvasEngine"
  )
  add_test(
    NAME ${target}
    COMMAND "$<TARGET_FILE:${target}>"
  )
endmacro()

ICEAddTest(CanvasTest_Error error.c)
ICEAddTest(CanvasTest_Array array.c)
ICEAddTest(CanvasTest_Memory memory.c)
