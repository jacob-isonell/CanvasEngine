/**
 * @file vector.hpp
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

#include <canvas/core/error.hpp>

namespace canvas {

using std::allocator;

namespace internal {
using namespace ::canvas::internal;

} // !namespace internal

template<typename ValueTy, typename AllocTy = std::allocator<ValueTy>>
class vector {
private:
	using s_alloc_traits = std::allocator_traits<AllocTy>;
	
public:
	using value_type = ValueTy;
	using allocator_type = AllocTy;
	using difference_type = typename s_alloc_traits::difference_type;
	using size_type = typename s_alloc_traits::size_type;
	using pointer = typename s_alloc_traits::pointer;
	using const_pointer = typename s_alloc_traits::const_pointer;
	
public:
	struct s_big_storage {
		size_type capacity;
		size_type length;
		pointer data;
	};
	
	// The maximum ammount of items that can be stored in small storage.
	static constexpr sz s_small_storage_cap =
		max((sz)2, (sizeof(s_big_storage) - 1) / sizeof(value_type));
	
	// Only enable small vector optimization if the type is small enough.
	static constexpr bool s_small_storage_enabled =
		sizeof(value_type) <= sizeof(u32);
	
	struct s_small_storage {
		union {
			byte _byte;
			
			// Ensures padding goes here
			value_type _alignment;
		};
		unsigned char bytes[s_small_storage_cap * sizeof(value_type)];
	};
	
	union s_storage {
		s_big_storage big;
		s_small_storage small;
	};
	
	union {
		
	} m_storage;
};

// static_assert(vector<u32>);

} // !namespace canvas
