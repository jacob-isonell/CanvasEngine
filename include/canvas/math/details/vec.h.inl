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

/* vvv vec2f32 vvv */
CE_INLINE
ce_vec2f32 ce_add_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  ce_vec2f32 out;
  out.x = lhs.x + rhs.x;
  out.y = lhs.y + rhs.y;
  return out;
}

CE_INLINE
ce_vec2f32 ce_sub_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  ce_vec2f32 out;
  out.x = lhs.x - rhs.x;
  out.y = lhs.y - rhs.y;
  return out;
}

CE_INLINE
ce_vec2f32 ce_mul_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  ce_vec2f32 out;
  out.x = lhs.x * rhs.x;
  out.y = lhs.y * rhs.y;
  return out;
}

CE_INLINE
ce_vec2f32 ce_div_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  ce_vec2f32 out;
  out.x = lhs.x / rhs.x;
  out.y = lhs.y / rhs.y;
  return out;
}

CE_INLINE float ce_dot_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  return lhs.x * rhs.x - lhs.y * rhs.y;
}

CE_INLINE float ce_sqrmag_vec2f32(ce_vec2f32 in) {
  return ce_dot_vec2f32(in, in);
}

CE_INLINE float ce_mag_vec2f32(ce_vec2f32 in) {
  return sqrtf(ce_sqrmag_vec2f32(in));
}

CE_INLINE float ce_sqrdist_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  return ce_sqrmag_vec2f32(ce_sub_vec2f32(lhs, rhs));
}

CE_INLINE float ce_dist_vec2f32(ce_vec2f32 lhs, ce_vec2f32 rhs) {
  return ce_mag_vec2f32(ce_sub_vec2f32(lhs, rhs));
}
/* ^^^ vec2f32 ^^^/vvv vec3f32 vvv */
CE_INLINE
ce_vec3f32 ce_add_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  ce_vec3f32 out;
  out.x = lhs.x + rhs.x;
  out.y = lhs.y + rhs.y;
  out.z = lhs.z + rhs.z;
  return out;
}

CE_INLINE
ce_vec3f32 ce_sub_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  ce_vec3f32 out;
  out.x = lhs.x - rhs.x;
  out.y = lhs.y - rhs.y;
  out.z = lhs.z - rhs.z;
  return out;
}

CE_INLINE
ce_vec3f32 ce_mul_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  ce_vec3f32 out;
  out.x = lhs.x * rhs.x;
  out.y = lhs.y * rhs.y;
  out.z = lhs.z * rhs.z;
  return out;
}

CE_INLINE
ce_vec3f32 ce_div_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  ce_vec3f32 out;
  out.x = lhs.x / rhs.x;
  out.y = lhs.y / rhs.y;
  out.z = lhs.z / rhs.z;
  return out;
}

CE_INLINE float ce_dot_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  return lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z;
}

CE_INLINE float ce_sqrmag_vec3f32(ce_vec3f32 in) {
  return ce_dot_vec3f32(in, in);
}

CE_INLINE float ce_mag_vec3f32(ce_vec3f32 in) {
  return sqrtf(ce_sqrmag_vec3f32(in));
}

CE_INLINE float ce_sqrdist_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  return ce_sqrmag_vec3f32(ce_sub_vec3f32(lhs, rhs));
}

CE_INLINE float ce_dist_vec3f32(ce_vec3f32 lhs, ce_vec3f32 rhs) {
  return ce_mag_vec3f32(ce_sub_vec3f32(lhs, rhs));
}
/* ^^^ vec3f32 ^^^/vvv vec4f32 vvv */
CE_INLINE
ce_vec4f32 ce_add_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  ce_vec4f32 out;
  out.x = lhs.x + rhs.x;
  out.y = lhs.y + rhs.y;
  out.z = lhs.z + rhs.z;
  out.w = lhs.w + rhs.w;
  return out;
}

CE_INLINE
ce_vec4f32 ce_sub_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  ce_vec4f32 out;
  out.x = lhs.x - rhs.x;
  out.y = lhs.y - rhs.y;
  out.z = lhs.z - rhs.z;
  out.w = lhs.w - rhs.w;
  return out;
}

CE_INLINE
ce_vec4f32 ce_mul_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  ce_vec4f32 out;
  out.x = lhs.x * rhs.x;
  out.y = lhs.y * rhs.y;
  out.z = lhs.z * rhs.z;
  out.w = lhs.w * rhs.w;
  return out;
}

CE_INLINE
ce_vec4f32 ce_div_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  ce_vec4f32 out;
  out.x = lhs.x / rhs.x;
  out.y = lhs.y / rhs.y;
  out.z = lhs.z / rhs.z;
  out.w = lhs.w / rhs.w;
  return out;
}

CE_INLINE float ce_dot_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  return lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z - lhs.w * rhs.w;
}

CE_INLINE float ce_sqrmag_vec4f32(ce_vec4f32 in) {
  return ce_dot_vec4f32(in, in);
}

CE_INLINE float ce_mag_vec4f32(ce_vec4f32 in) {
  return sqrtf(ce_sqrmag_vec4f32(in));
}

CE_INLINE float ce_sqrdist_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  return ce_sqrmag_vec4f32(ce_sub_vec4f32(lhs, rhs));
}

CE_INLINE float ce_dist_vec4f32(ce_vec4f32 lhs, ce_vec4f32 rhs) {
  return ce_mag_vec4f32(ce_sub_vec4f32(lhs, rhs));
}
/* ^^^ vec4f32 ^^^/vvv vec2f64 vvv */
