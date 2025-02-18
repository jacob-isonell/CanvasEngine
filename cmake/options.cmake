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

target_compile_features(CanvasEngine
PUBLIC
	c_std_11
)

target_include_directories(CanvasEngine
PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${CMAKE_CURRENT_BINARY_DIR}/include"
)

set_target_properties(CanvasEngine
PROPERTIES
	FOLDER "CanvasEngine"
)

target_compile_definitions(CanvasEngine
PUBLIC
	"$<$<CONFIG:Debug>:CANVAS_DEBUG>"
PRIVATE
	"ICE_BUILD"
)

target_compile_options(CanvasEngine
PRIVATE
	"$<$<C_COMPILER_ID:MSVC>:/std:c11>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-std=c11>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-fvisibility=hidden>"
)

target_link_libraries(CanvasEngine
PRIVATE
	"$<$<C_COMPILER_ID:GNU,Clang>:-luuid>"
	"$<$<PLATFORM_ID:Windows>:shlwapi>"
	"$<$<PLATFORM_ID:Windows>:rpcrt4>"
	CanvasEngineDependencies
)

set(ICE_COMMON_SANITIZER_FLAGS
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=address>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fno-omit-frame-pointer>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fno-optimize-sibling-calls>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=address>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=undefined>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize-trap=all>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fno-sanitize-recover=all>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=shift>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=shift-exponent>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=shift-base>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=integer-divide-by-zero>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=unreachable>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=vla-bound>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=null>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=return>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=signed-integer-overflow>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=bounds>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=alignment>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=float-divide-by-zero>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=float-cast-overflow>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=nonnull-attribute>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=returns-nonnull-attribute>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=bool>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=enum>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=pointer-overflow>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize=builtin>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fsanitize-address-use-after-scope>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fcf-protection=full>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fstack-protector>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fstack-protector-strong>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU,Clang>>:-fstack-check>"
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:GNU>>:-fsanitize=bounds-strict>"
)

set(ICE_COMPILER_SANITIZER_FLAGS ${ICE_COMMON_SANITIZER_FLAGS}
	"$<$<C_COMPILER_ID:TinyCC>:-bench>"
	"$<$<C_COMPILER_ID:TinyCC>:-Wimplicit-function-declaration>"
	"$<$<C_COMPILER_ID:TinyCC>:-Wwrite-strings>"
	"$<$<C_COMPILER_ID:TinyCC>:-Wwrite-strings>"
	"$<$<C_COMPILER_ID:MSVC>:/W4>"
	"$<$<C_COMPILER_ID:MSVC>:/WX>"
	"$<$<C_COMPILER_ID:MSVC>:/wd4334>" # 'shift_operator': result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
	"$<$<C_COMPILER_ID:MSVC>:/wd4505>" # 'function': unreferenced local function has been removed
	"$<$<C_COMPILER_ID:MSVC>:/wd4127>" # conditional expression is constant
	"$<$<C_COMPILER_ID:MSVC>:/wd4065>" # switch statement contains 'default' but no 'case' labels
	"$<$<C_COMPILER_ID:MSVC>:/wd4060>" # switch statement contains no 'case' or 'default' labels
	"$<$<C_COMPILER_ID:MSVC>:/wd4820>" # padding bytes added
	"$<$<C_COMPILER_ID:MSVC>:/wd4255>" # function decleration with () instead of (void)
	"$<$<AND:$<CONFIG:Debug>,$<C_COMPILER_ID:MSVC>>:/fsanitize=address>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wall>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Werror>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wextra>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-pedantic>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-pedantic-errors>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wshadow>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wpointer-arith>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wcast-qual>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wformat=2>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wcast-align>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wstrict-overflow=5>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Winline>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wundef>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wunreachable-code>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wfloat-equal>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wstrict-aliasing=2>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wredundant-decls>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wfree-nonheap-object>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wconversion>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wfloat-conversion>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wsign-conversion>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wsign-compare>"
	"$<$<C_COMPILER_ID:GNU,Clang>:-Wno-format-nonliteral>"
	"$<$<AND:$<C_COMPILER_ID:GNU,Clang>,$<COMPILE_LANGUAGE:C>>:-Wmissing-prototypes>"
	"$<$<AND:$<C_COMPILER_ID:GNU,Clang>,$<COMPILE_LANGUAGE:C>>:-Wstrict-prototypes>"
	"$<$<AND:$<C_COMPILER_ID:GNU,Clang>,$<COMPILE_LANGUAGE:C>>:-Wold-style-definition>"
	"$<$<AND:$<C_COMPILER_ID:GNU,Clang>,$<COMPILE_LANGUAGE:C>>:-Wnested-externs>"
	"$<$<AND:$<C_COMPILER_ID:GNU,Clang>,$<COMPILE_LANGUAGE:C>>:-Wno-bad-function-cast>"
	"$<$<C_COMPILER_ID:GNU>:-Warith-conversion>"
	"$<$<C_COMPILER_ID:GNU>:-Wmismatched-dealloc>"
	"$<$<C_COMPILER_ID:GNU>:-Wlogical-op>"
	"$<$<C_COMPILER_ID:GNU>:-Wno-nonnull-compare>"
	"$<$<C_COMPILER_ID:GNU>:-Wanalyzer-mismatching-deallocation>"
	"$<$<C_COMPILER_ID:GNU>:-Wanalyzer-double-free>"
	"$<$<C_COMPILER_ID:GNU>:-Wanalyzer-possible-null-dereference>"
	"$<$<C_COMPILER_ID:GNU>:-Wanalyzer-possible-null-argument>"
	"$<$<C_COMPILER_ID:GNU>:-Wanalyzer-use-after-free>"
	"$<$<C_COMPILER_ID:GNU>:-Wanalyzer-free-of-non-heap>"
)

if (ICE_DEVMODE)
	target_compile_options(CanvasEngine PUBLIC ${ICE_COMPILER_SANITIZER_FLAGS})
	target_link_options(CanvasEngine PUBLIC ${ICE_COMMON_SANITIZER_FLAGS})
endif ()
