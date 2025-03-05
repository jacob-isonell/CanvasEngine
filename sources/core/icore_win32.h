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

#ifndef ICORE_WIN32_H
#define ICORE_WIN32_H

#include "icore_base.h"
#include <Ntddk.h>

#if !CANVAS_PLATFORM_WINDOWS
#error icore_win32.h can only be included on Windows
#endif

ICE_NAMESPACE_BEGIN

/* The high performance frequency. */
ICE_API extern double ihiperf_clock_factor;

ICE_API ce_err icore_win32_init(void);
ICE_API void icore_win32_shutdown(void);

ICE_NAMESPACE_END

#endif /* !ICORE_WIN32_H */
