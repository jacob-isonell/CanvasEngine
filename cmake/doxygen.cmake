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

message(CHECK_START "Checking for Doxygen")
find_package(Doxygen)
if (DOXYGEN_FOUND)
	message(CHECK_PASS "found version ${DOXYGEN_VERSION}")
	
# TODO: The generated pages by doxygen contains a bunch
#       clutter and weird formatting. The styling of the pages
#       could also be improved. But since I'm not that familiar
#       with using Doxygen yet this will have to do for now.
	
	set(DOXYGEN_PREDEFINED
		"CANVAS_DOXYGEN=1"
		
		"CANVAS_EXTERN_C="
		"CANVAS_EXTERN_C_BEGIN="
		"CANVAS_EXTERN_C_END="
	)
	
	set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
	
	set(DOXYGEN_ALLOW_UNICODE_NAMES        YES)
	set(DOXYGEN_ENABLE_PREPROCESSING       YES)
	set(DOXYGEN_ENUM_VALUES_PER_LINE       0)
	set(DOXYGEN_EXCLUDE_SYMBOLS            "ICANVAS_*" "icanvas_*")
	set(DOXYGEN_GENERATE_HTML              YES)
	set(DOXYGEN_INPUT_ENCODING             "UTF-8")
	set(DOXYGEN_MACRO_EXPANSION            YES)
	set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C      YES)
	set(DOXYGEN_SHOW_ENUM_VALUES           NO)
	set(DOXYGEN_TYPEDEF_HIDES_STRUCT       YES)
	set(DOXYGEN_WARNINGS                   YES)
	set(DOXYGEN_WARN_AS_ERROR              NO)
	set(DOXYGEN_WARN_IF_DOC_ERROR          YES)
	set(DOXYGEN_WARN_IF_INCOMPLETE_DOC     YES)
	set(DOXYGEN_WARN_IF_UNDOCUMENTED       YES)
	set(DOXYGEN_WARN_IF_UNDOC_ENUM_VAL     YES)
	set(DOXYGEN_WARN_LINE_FORMAT           YES)
	set(DOXYGEN_WARN_LOGFILE               YES)
	set(DOXYGEN_WARN_NO_PARAMDOC           YES)
	
	set(DOXYGEN_DISABLE_INDEX              YES)
	set(DOXYGEN_GENERATE_TREEVIEW          YES)
	set(DOXYGEN_FULL_SIDEBAR               NO)
	set(DOXYGEN_CREATE_SUBDIRS NO)
	set(DOXYGEN_FULL_PATH_NAMES NO)
	
	doxygen_add_docs(
		CanvasEngineDocs
		"${CMAKE_CURRENT_SOURCE_DIR}/include/canvas.h"
		"${CMAKE_CURRENT_BINARY_DIR}/include/canvas/cmake_configs.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/include/canvas/core.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/include/canvas/graphics.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/include/canvas/threads.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/include/canvas/math.h"
		COMMENT "Generate CanvasEngine documentation"
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/canvas"
	)
	
	set_target_properties(CanvasEngineDocs
	PROPERTIES
		FOLDER "CanvasEngine"
	)
else ()
	message(CHECK_FAIL "not found")
endif ()
