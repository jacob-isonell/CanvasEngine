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

#ifndef CANVAS_CORE_TIME_H
#define CANVAS_CORE_TIME_H

#include <canvas/core/error.h>
#include <time.h>
#include <math.h>

ICE_NAMESPACE_BEGIN

/** @brief add documentation here! */
#define CE_TIME_UTC 1

/** @brief Describes a span of time or the time span since the unix epoch time (january 1st 1970 00:00:00). */
struct ce_time_t {
	
	/** Seconds. */
	unsigned long long int sec;
	
	/** Nanoseconds. This field must be in the range of 0 to 999'999'999 (or 1 billion - 1). */
	unsigned long long int nsec;
};

/** @brief Gets the current time. */
CE_API ce_err ce_time_get(
	struct ce_time_t* out,
	int               base
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_add(
	struct ce_time_t lhs,
	struct ce_time_t rhs
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_sub(
	struct ce_time_t lhs,
	struct ce_time_t rhs
);

/** @brief add documentation here! */
ICE_INLINE
int ce_time_cmp(
	struct ce_time_t lhs,
	struct ce_time_t rhs
);

/** @brief add documentation here! */
ICE_INLINE
unsigned long long int ce_time_to_inano(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
unsigned long long int ce_time_to_imicro(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
unsigned long long int ce_time_to_imilli(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
unsigned long long int ce_time_to_iseconds(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
double ce_time_to_nano(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
double ce_time_to_micro(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
double ce_time_to_milli(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
double ce_time_to_seconds(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
float ce_time_to_fnano(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
float ce_time_to_fmicro(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
float ce_time_to_fmilli(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
float ce_time_to_fseconds(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
long double ce_time_to_lnano(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
long double ce_time_to_lmicro(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
long double ce_time_to_lmilli(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
long double ce_time_to_lseconds(
	struct ce_time_t in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_inano(
	unsigned long long int in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_imicro(
	unsigned long long int in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_imilli(
	unsigned long long int in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_iseconds(
	unsigned long long int in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_nano(
	double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_micro(
	double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_milli(
	double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_seconds(
	double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_fnano(
	float in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_fmicro(
	float in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_fmilli(
	float in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_fseconds(
	float in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_lnano(
	long double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_lmicro(
	long double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_lmilli(
	long double in
);

/** @brief add documentation here! */
ICE_INLINE
struct ce_time_t ce_time_lseconds(
	long double in
);

#include <canvas/core/details/time.h.inl>

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_TIME_H */
