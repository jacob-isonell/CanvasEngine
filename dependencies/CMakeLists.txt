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

include(FetchContent)

if (CANVAS_GRAPHICS_ENABLE_GTK)
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(GTK REQUIRED IMPORTED_TARGET
		gtk4
		glib-2.0
		gio-2.0 
	)
	target_link_libraries(CanvasEngineDeps
	INTERFACE
		PkgConfig::GTK
	)
endif ()

if (CANVAS_GRAPHICS_ENABLE_VULKAN)
	find_package(Vulkan REQUIRED)
	target_link_libraries(CanvasEngineDeps
	INTERFACE
		Vulkan::Vulkan
	)
endif ()
