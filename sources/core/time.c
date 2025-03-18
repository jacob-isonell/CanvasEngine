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

#include "icore_base.h"
#include <canvas/core/time.h>

#if CANVAS_PLATFORM_WINDOWS
#include <winternl.h>

static ce_time_t s_perf_freq(void) {
  LARGE_INTEGER i;
  QueryPerformanceFrequency(&i);
  const double f = 1.0 / (double)i.QuadPart;
  const ce_time_t out = {
    .sec = (unsigned long long)f,
    .nsec = (unsigned long long)(f * 1000000000.0) % 1000000000,
  };
  return out;
}

static ce_time_t s_perf_count(void) {
  LARGE_INTEGER i;
  QueryPerformanceFrequency(&i);
  const double f = (double)i.QuadPart;
  QueryPerformanceCounter(&i);
  const double dur = (double)i.QuadPart / f;
  const ce_time_t out = {
    .sec = (unsigned long long)dur,
    .nsec = (unsigned long long)(dur * 1000000000.0) % 1000000000,
  };
  return out;
}
  
#endif

CE_API ce_err ce_time_res(ce_clock clock, ce_time_t* out) {
  if (out == NULL) {
    return CE_EINVAL;
  }
  
#if CANVAS_PLATFORM_UNIX
  
  struct timespec now;
  int posix_clock;
  switch (clock) {
  default: return CE_EINVAL;
  case CE_CLOCK_UTC:  posix_clock = CLOCK_REALTIME;  break;
  case CE_CLOCK_PERF: posix_clock = CLOCK_MONOTONIC; break;
  }
  
  if (clock_getres(posix_clock, &now) != 0) {
    return ierrno;
  }
  
  out->sec = (unsigned long long)now.tv_sec;
  out->nsec = (unsigned long long)now.tv_nsec;
  
  return CE_EOK;
  
#elif CANVAS_PLATFORM_WINDOWS
  
  switch (clock) {
  default: return CE_EINVAL;
  case CE_CLOCK_UTC: {
    out->sec = 0;
    out->nsec = 100;
    return CE_EOK;
  } break;
  case CE_CLOCK_PERF: {
    *out = s_perf_freq();
    return CE_EOK;
  } break;
  }
  
#endif
  
}

CE_API ce_err ce_time_get(ce_clock clock, ce_time_t* out) {
  if (out == NULL) {
    return CE_EINVAL;
  }
  
#if CANVAS_PLATFORM_UNIX
  
  struct timespec now;
  int posix_clock;
  switch (clock) {
  default: return CE_EINVAL;
  case CE_CLOCK_UTC:  posix_clock = CLOCK_REALTIME;  break;
  case CE_CLOCK_PERF: posix_clock = CLOCK_MONOTONIC; break;
  }
  
  if (clock_gettime(posix_clock, &now) != 0) {
    return ierrno;
  }
  
  out->sec = (unsigned long long)now.tv_sec;
  out->nsec = (unsigned long long)now.tv_nsec;
  
  return CE_EOK;
  
#elif CANVAS_PLATFORM_WINDOWS
  
  switch (clock) {
  default: return CE_EINVAL;
  case CE_CLOCK_UTC: {
    LARGE_INTEGER i;
    NtQuerySystemTime(&i);
    
    /* NtQuerySystemTime returns the number of 100 nanoseconds since 1st of January 1601.
     * This function converts it to 1st of January 1970 like unix.
     * 1970 - 1601 = 369 years = 11644754400 seconds.
     */
    #define SUB_369_YEARS 11644754400LL
    
    const unsigned long long nanosec = (unsigned long long)(i.QuadPart * 100 - SUB_369_YEARS);
    out->nsec = nanosec % ICE_NANO2SEC_V;
    out->sec = nanosec / ICE_NANO2SEC_V;
    return CE_EOK;
  } break;
  case CE_CLOCK_PERF: {
    *out = s_perf_count();
    return CE_EOK;
  } break;
  }
  
#endif
}
