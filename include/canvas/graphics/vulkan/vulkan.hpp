/**
 * @file vulkan.hpp
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

#pragma once

#include <canvas/graphics/graphics.hpp>

#if !CANVAS_GRAPHICS_ENABLE_VULKAN
#error VulkanAPI support is disabled with this build of CanvasEngine
#endif

namespace canvas::graphics::vulkan {

struct alignas(u32) version_t {
private:
	struct alignas(u32) s_storage {
		unsigned int patch   : 12;
		unsigned int minor   : 10;
		unsigned int major   : 7;
		unsigned int variant : 3;
	};
	
	static constexpr s_storage s_construct(
		u32 _variant,
		u32 _major,
		u32 _minor,
		u32 _patch
	) {
		s_storage out;
		out.patch = _patch & 4095;
		out.minor = _minor & 1023;
		out.major = _major & 127;
		out.variant = _variant & 7;
		return out;
	}
	
	s_storage m_value {0,0,0,0};
public:
	constexpr version_t() noexcept = default;
	constexpr version_t(const version_t&) noexcept = default;
	constexpr version_t& operator=(const version_t&) noexcept = default;
	
	[[nodiscard]] constexpr bool operator==(const version_t& other) const noexcept {
		return std::bit_cast<u32>(m_value) == std::bit_cast<u32>(other.m_value);
	}
	
	[[nodiscard]] constexpr auto operator<=>(const version_t& other) const noexcept {
		return std::bit_cast<u32>(m_value) <=> std::bit_cast<u32>(other.m_value);
	}
	
	[[nodiscard]] constexpr bool operator==(u32 val) const noexcept {
		return *this == version_t{val};
	}
	
	[[nodiscard]] constexpr auto operator<=>(u32 val) const noexcept {
		return *this <=> version_t{val};
	}
	
	constexpr version_t(u32 value) noexcept
		: m_value(std::bit_cast<s_storage>(value)) {
	}
	
	constexpr version_t(u32 _major, u32 _minor) noexcept
		: m_value(s_construct(0,_major,_minor,0)) {
	}
	
	constexpr version_t(u32 _variant, u32 _major, u32 _minor, u32 _patch) noexcept
		: m_value(s_construct(_variant,_major,_minor,_patch)) {
	}
	
	[[nodiscard]] constexpr explicit operator u32() const noexcept {
		return std::bit_cast<u32>(m_value);
	}
	
	[[nodiscard]] constexpr u32 variant() const noexcept { return m_value.variant; }
	[[nodiscard]] constexpr u32   major() const noexcept { return m_value.major; }
	[[nodiscard]] constexpr u32   minor() const noexcept { return m_value.minor; }
	[[nodiscard]] constexpr u32   patch() const noexcept { return m_value.patch; }
	
	constexpr void variant(u32 value) noexcept { m_value = s_construct(value, major(), minor(), patch()); }
	constexpr void   major(u32 value) noexcept { m_value = s_construct(variant(), value, minor(), patch()); }
	constexpr void   minor(u32 value) noexcept { m_value = s_construct(variant(), major(), value, patch()); }
	constexpr void   patch(u32 value) noexcept { m_value = s_construct(variant(), major(), minor(), value); }
};

inline constexpr version_t version_1_0{0,1,0,0};
inline constexpr version_t version_1_1{0,1,1,0};
inline constexpr version_t version_1_2{0,1,2,0};
inline constexpr version_t version_1_3{0,1,3,0};
inline constexpr version_t version_1_4{0,1,4,0};

} // !namespace canvas::graphics::vulkan
