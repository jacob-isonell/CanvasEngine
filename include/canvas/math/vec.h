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

#ifndef CANVAS_MATH_VEC_H
#define CANVAS_MATH_VEC_H

#include <canvas/math/math.h>

ICE_NAMESPACE_BEGIN

/** @brief add documentation here! */
struct ce_vec2f32 {
	ce_f32 x, y; 
};

/** @brief add documentation here! */
struct ce_vec3f32 {
	ce_f32 x, y, z; 
};

/** @brief add documentation here! */
struct ce_vec4f32 {
	ce_f32 x, y, z, w; 
};

/** @brief add documentation here! */
struct ce_vec2f64 {
	ce_f64 x, y; 
};

/** @brief add documentation here! */
struct ce_vec3f64 {
	ce_f64 x, y, z; 
};

/** @brief add documentation here! */
struct ce_vec4f64 {
	ce_f64 x, y, z, w; 
};

/** @brief add documentation here! */
ICE_INLINE struct ce_vec2f32 ce_add_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec2f32 ce_sub_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec2f32 ce_mul_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec2f32 ce_div_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_dot_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_sqrmag_vec2f32(struct ce_vec2f32 in);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_mag_vec2f32(struct ce_vec2f32 in);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_sqrdist_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_dist_vec2f32(struct ce_vec2f32 lhs, struct ce_vec2f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec3f32 ce_add_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec3f32 ce_sub_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec3f32 ce_mul_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec3f32 ce_div_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_dot_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_sqrmag_vec3f32(struct ce_vec3f32 in);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_mag_vec3f32(struct ce_vec3f32 in);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_sqrdist_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_dist_vec3f32(struct ce_vec3f32 lhs, struct ce_vec3f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec4f32 ce_add_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec4f32 ce_sub_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec4f32 ce_mul_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

/** @brief add documentation here! */
ICE_INLINE struct ce_vec4f32 ce_div_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_dot_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_sqrmag_vec4f32(struct ce_vec4f32 in);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_mag_vec4f32(struct ce_vec4f32 in);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_sqrdist_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

/** @brief add documentation here! */
ICE_INLINE ce_f32 ce_dist_vec4f32(struct ce_vec4f32 lhs, struct ce_vec4f32 rhs);

#include <canvas/math/details/vec.h.inl>

ICE_NAMESPACE_END

#endif /* !CANVAS_MATH_VEC_H */
