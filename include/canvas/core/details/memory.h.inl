/**************************************************************************
** CanvasEngine is a C11 cross platform multimedia library.              **
** Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             **
**                                                                       **
** This program is free software: you can redistribute it and/or modify  **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 3 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** This program is distributed in the hope that it will be useful,       **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with this program. If not, see <https://www.gnu.org/licenses/>. **
**************************************************************************/

#undef ce_arr
#undef CE_ARRINIT
#undef ce_arr_alloc
#undef ce_arr_free
#undef ce_arr_at
#undef ce_arr_size
#undef ce_arr_cap
#undef ce_arr_data

#ifdef CANVAS_DEBUG
ICE_INLINE
size_t ice_assert_arr_at(size_t index, size_t length) {
	if (index < length) {
		return index;
	}
	abort();
}
#else
#define ice_assert_arr_at(index, length) (index) 
#endif

#define ICE_ARRPAIR(arr) ((void**)(arr)), sizeof((arr)->m_data)
#define ICE_ARRPAIR_ARG void** inout_arr_arg, size_t in_arr_stride

CE_API ce_err ice_arr_alloc(ICE_ARRPAIR_ARG, size_t reserve);
CE_API void ice_arr_free(void* array);
CE_API ce_err ice_arr_resize(ICE_ARRPAIR_ARG, size_t new_size);
CE_API ce_err ice_arr_reserve(ICE_ARRPAIR_ARG, size_t new_capacity);

#define ce_arr(type) struct { size_t m_capacity; size_t m_count; type* m_data; }
#define CE_ARRINIT {0,0,NULL}
#define ce_arr_alloc(out, reserve) ice_arr_alloc(ICE_ARRPAIR(out), (reserve))
#define ce_arr_free(arr) ice_arr_free((arr)->m_data)
#define ce_arr_at(arr, index) ((arr).m_data[ice_assert_arr_at((index), (arr).m_count)])
#define ce_arr_size(arr) ((const size_t)((arr).m_count))
#define ce_arr_cap(arr) ((const size_t)((arr).m_capacity))
#define ce_arr_data(arr) ((arr).m_data)
