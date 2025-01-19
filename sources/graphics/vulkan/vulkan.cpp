/**
 * @file vulkan.cpp
 * @author Jacob Isonell (isonelljacob@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-09
 * 
 * @copyright Copyright (c) 2025
 * 
 * CanvasEngine is a cross platform multimedia library in C89
 * Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "icanvas_vulkan.hpp"
#include <algorithm>

ICANVAS_NAMESPACE_GRAPHICS_VULKAN_BEGIN

static expected<std::vector<extension_info>> s_query_instance_extensions(
	const char* layer
) {
	std::vector<extension_info> out;
	std::vector<VkExtensionProperties> extensions;
	u32 count;
	vkerror e;
	
	e = vkEnumerateInstanceExtensionProperties(layer, &count, nullptr);
	if (!e) [[unlikely]] {
		return e;
	}
	
	if (extensions.max_size() < count || out.max_size() < count) [[unlikely]] {
		return err::enomem;
	}
	
	extensions.resize(count);
	e = vkEnumerateInstanceExtensionProperties(layer, &count, extensions.data());
	if (!e) [[unlikely]] {
		return e;
	}
	
	extensions.resize(count);
	out.reserve(count);
	for (const auto& ext : extensions) {
		auto& v = out.emplace_back();
		std::ranges::copy(ext.extensionName, v.name);
		v.specification_version = ext.specVersion;
	}
	return out;
}

CANVAS_API
expected<std::vector<layer_info>> query_instance_layers() {
	std::vector<layer_info> out;
	std::vector<VkLayerProperties> layers;
	u32 count;
	vkerror e;
	
	e = vkEnumerateInstanceLayerProperties(&count, nullptr);
	if (!e) [[unlikely]] {
		return e;
	}
	
	if (layers.max_size() < count) [[unlikely]] {
		return err::enomem;
	}
	
	layers.resize(count);
	e = vkEnumerateInstanceLayerProperties(&count, layers.data());
	if (!e) [[unlikely]] {
		return e;
	}
	
	layers.resize(count);
	out.reserve(count);
	for (const auto& layer : layers) {
		auto& v = out.emplace_back();
		std::ranges::copy(layer.layerName, v.name);
		v.specification_version = layer.specVersion;
		v.implementation_version = layer.implementationVersion;
		std::ranges::copy(layer.description, v.description);
	}
	return out;
}

CANVAS_API
expected<std::vector<extension_info>> query_instance_extensions(
	const layer_info& layer
) {
	return s_query_instance_extensions(layer.name);
}

CANVAS_API
expected<std::vector<extension_info>> query_instance_extensions(
	const std::string& layer
) {
	return s_query_instance_extensions(layer.c_str());
}

CANVAS_API
expected<std::vector<extension_info>> query_instance_extensions() {
	return s_query_instance_extensions(nullptr);
}

ICANVAS_NAMESPACE_GRAPHICS_VULKAN_END
