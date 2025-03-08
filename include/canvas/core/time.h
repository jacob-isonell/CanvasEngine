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

CE_NAMESPACE_BEGIN

/**
 * @ingroup time
 * @brief Describes a span of time or the time span since the unix epoch time (january 1st 1970 00:00:00).
 */
typedef struct ce_time_t {
  
  /** Seconds. */
  unsigned long long sec;
  
  /** Nanoseconds. This field must be in the range of 0 to 999'999'999 (or 1 billion - 1). */
  unsigned long long nsec;
} ce_time_t;

typedef enum ce_clock {
  CE_CLOCK_UTC,  /* System UTC since 01/01/1970. */
  CE_CLOCK_PERF, /* Fastest clock available. */
} ce_clock;

/**
 * @ingroup time
 * @brief Gets the clock resolution.
 */
CE_API ce_err ce_time_res(ce_clock clock, ce_time_t* out);

/**
 * @ingroup time
 * @brief Gets the current time.
 */
CE_API ce_err ce_time_get(ce_clock clock, ce_time_t* out);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_add(ce_time_t lhs, ce_time_t rhs);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_sub(ce_time_t lhs, ce_time_t rhs);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE int ce_time_cmp(ce_time_t lhs, ce_time_t rhs);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE unsigned long long ce_time_to_inano(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE unsigned long long ce_time_to_imicro(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE unsigned long long ce_time_to_imilli(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE unsigned long long ce_time_to_iseconds(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE double ce_time_to_nano(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE double ce_time_to_micro(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE double ce_time_to_milli(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE double ce_time_to_seconds(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE float ce_time_to_fnano(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE float ce_time_to_fmicro(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE float ce_time_to_fmilli(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE float ce_time_to_fseconds(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE long double ce_time_to_lnano(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE long double ce_time_to_lmicro(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE long double ce_time_to_lmilli(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE long double ce_time_to_lseconds(ce_time_t in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_inano(unsigned long long in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_imicro(unsigned long long in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_imilli(unsigned long long in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_iseconds(unsigned long long in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_nano(double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_micro(double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_milli(double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_seconds(double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_fnano(float in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_fmicro(float in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_fmilli(float in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_fseconds(float in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_lnano(long double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_lmicro(long double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_lmilli(long double in);

/**
 * @ingroup time
 * @brief add documentation here!
 */
CE_INLINE ce_time_t ce_time_lseconds(long double in);

#ifndef ICE_DOCS
#include <canvas/core/details/time.h.inl>
#endif /* !ICE_DOCS */

CE_NAMESPACE_END

#endif /* !CANVAS_CORE_TIME_H */
