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

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
struct ce_vec2f32 {
	float x, y; 
};

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
struct ce_vec3f32 {
	float x, y, z; 
};

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
struct ce_vec4f32 {
	float x, y, z, w; 
};

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
struct ce_vec2f64 {
	double x, y; 
};

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
struct ce_vec3f64 {
	double x, y, z; 
};

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
struct ce_vec4f64 {
	double x, y, z, w; 
};

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec2f32 ce_add_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec2f32 ce_sub_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec2f32 ce_mul_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec2f32 ce_div_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_dot_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_sqrmag_vec2f32(
	struct ce_vec2f32 in
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_mag_vec2f32(
	struct ce_vec2f32 in
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_sqrdist_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_dist_vec2f32(
	struct ce_vec2f32 lhs,
	struct ce_vec2f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec3f32 ce_add_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec3f32 ce_sub_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec3f32 ce_mul_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec3f32 ce_div_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_dot_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_sqrmag_vec3f32(
	struct ce_vec3f32 in
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_mag_vec3f32(
	struct ce_vec3f32 in
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_sqrdist_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_dist_vec3f32(
	struct ce_vec3f32 lhs,
	struct ce_vec3f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec4f32 ce_add_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec4f32 ce_sub_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec4f32 ce_mul_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
struct ce_vec4f32 ce_div_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_dot_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_sqrmag_vec4f32(
	struct ce_vec4f32 in
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_mag_vec4f32(
	struct ce_vec4f32 in
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_sqrdist_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

/**
 * @ingroup vector_types
 * @brief add documentation here!
 */
ICE_INLINE
float ce_dist_vec4f32(
	struct ce_vec4f32 lhs,
	struct ce_vec4f32 rhs
);

#ifndef ICE_DOXY
#include <canvas/math/details/vec.h.inl>
#endif /* !ICE_DOXY */

ICE_NAMESPACE_END

#endif /* !CANVAS_MATH_VEC_H */
