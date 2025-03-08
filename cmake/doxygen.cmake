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

find_package(Doxygen)

cmake_dependent_option(CANVAS_GENERATE_DOXYGEN "Generate documentation with Doxygen" ON "DOXYGEN_FOUND" OFF)
if (CANVAS_GENERATE_DOXYGEN)
  set(DOXYGEN_EXCLUDE_PATTERNS
    "*/details/*"
  )

  set(DOXYGEN_EXCLUDE_SYMBOLS
    "ice_*"
    "ICE_*"
    "i*"
    "I*"
  )

  set(DOXYGEN_PREDEFINED
    "CE_NAMESPACE_BEGIN="
    "CE_NAMESPACE_END="
    "CE_INLINE="
    "CE_API="
    "ICE_DOXY="
    "CE_CXX98_STD=1"
    "CE_CXX11_STD=1"
    "CE_CXX14_STD=1"
    "CE_CXX17_STD=1"
    "CE_CXX20_STD=1"
    "CE_CXX23_STD=1"
    "CE_C89_STD=1"
    "CE_C99_STD=1"
    "CE_C11_STD=1"
    "CE_C17_STD=1"
    "CE_C23_STD=1"
    "ICE_FXHANDLE(x)=typedef struct x x"
  )

  set(DOXYGEN_FILE_PATTERNS
    "*.h"
    "*.md"
    "*.markdown"
  )
  
  set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "../docs/index.md")
  set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/CanvasDocs")
  
  set(DOXYGEN_SORT_MEMBER_DOCS NO)
  set(DOXYGEN_MACRO_EXPANSION YES)
  set(DOXYGEN_EXTRACT_ALL YES)
  set(DOXYGEN_GENERATE_HTML YES)
  set(DOXYGEN_RECURSIVE YES)
  set(DOXYGEN_ALLOW_UNICODE_NAMES YES)
  set(DOXYGEN_OUTPUT_LANGUAGE "English")
  set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
  set(DOXYGEN_TYPEDEF_HIDES_STRUCT YES)
  
  set(DOXYGEN_DISABLE_INDEX NO)
  set(DOXYGEN_GENERATE_TREEVIEW NO)
  set(DOXYGEN_FULL_SIDEBAR NO)
  
  doxygen_add_docs(CanvasDoxygen
    "./"
    "../docs"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )
  
  set_target_properties(CanvasDoxygen
  PROPERTIES
    FOLDER "CanvasEngine"
  )
endif ()
