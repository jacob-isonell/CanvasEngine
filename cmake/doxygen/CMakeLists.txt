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
if (NOT CANVAS_GENERATE_DOXYGEN)
	return ()
endif ()

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
	"ICE_NAMESPACE_BEGIN="
	"ICE_NAMESPACE_END="
	"ICE_INLINE="
	"CE_API="
)

set(DOXYGEN_MACRO_EXPANSION YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_RECURSIVE YES)
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/CanvasDocs")
set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)

doxygen_add_docs(CanvasDoxygen
	"../../include"
)
