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
#undef ce_arr_resize
#undef ce_arr_reserve
#undef ce_arr_free
#undef ce_arr_size
#undef ce_arr_cap
#undef ce_realloc

CE_API ce_err ice_realloc(void* inout, size_t new_size);
#define ce_realloc(inout, new_size) ice_realloc((void**)(inout), (sizeof(**(inout)), (new_size)))

#if CE_CXX
template<typename T>
inline void** ice_to_voidpp(T** in) ICE_NOEXCEPT {
  void** out;
  memcpy(&out, &in, sizeof(void*));
  return out;
}
#else
CE_INLINE void** ice_to_voidpp(void* in) {
  void** out;
  memcpy(&out, &in, sizeof(void*));
  return out;
}
#endif

#ifdef CANVAS_DEBUG
CE_INLINE
size_t ice_assert_arr_at(size_t index, size_t length) {
  if (index < length) {
    return index;
  }
  abort();
}
#else
#define ice_assert_arr_at(index, length) (index) 
#endif

CE_API ce_err ice_arr_free(void* array);
CE_API ce_err ice_arr_resize(void** inout_arr, size_t stride, size_t new_size);
CE_API ce_err ice_arr_reserve(void** inout_arr, size_t stride, size_t new_capacity);
CE_API size_t ice_arr_len(void* array);
CE_API size_t ice_arr_cap(void* array);

#define ce_arr(type) type*
#define CE_ARRINIT NULL
#define ce_arr_free(arr) ice_arr_free(arr)
#define ce_arr_size(arr) ice_arr_len(arr)
#define ce_arr_cap(arr) ice_arr_cap(arr)
#define ce_arr_resize(inout_array, new_size) ice_arr_resize(ice_to_voidpp(inout_array), sizeof(**(inout_array)), (new_size))
#define ce_arr_reserve(inout_array, new_capacity) ice_arr_reserve(ice_to_voidpp(inout_array), sizeof(**(inout_array)), (new_capacity))
