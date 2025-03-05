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
#if CANVAS_PLATFORM_WINDOWS

ICE_API double ihiperf_clock_factor;

ICE_API ce_err icore_win32_init(void) {
  LARGE_INTEGER highres_freq;
  QueryPerformanceFrequency(&highres_freq);
  ihiperf_clock_factor = 1.0 / (double)highres_freq.QuadPart;
  
  return CE_EOK;
}

ICE_API void icore_win32_shutdown(void) {
  
}

#endif /* !CANVAS_PLATFORM_WINDOWS */
