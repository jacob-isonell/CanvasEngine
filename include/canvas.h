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

#ifndef CANVAS_H
#define CANVAS_H

/**
 * @defgroup arrays            Arrays
 * @defgroup atomic_types      Atomic Types
 * @defgroup configuration     Configuration
 * @defgroup error_handling    Error Handling
 * @defgroup gpu_devices       GPU Devices
 * @defgroup memory            Memory
 * @defgroup time              Time
 * @defgroup threading_objects Threading Objects
 * @defgroup types             Types
 * @defgroup utility           Utility
 * @defgroup vector_types      Vector Types
 */

#include <canvas/core.h>
#ifndef CANVAS_NO_MATH_API
#include <canvas/math.h>
#endif
#ifndef CANVAS_NO_THREADS_API
#include <canvas/threads.h>
#endif

#if defined(CANVAS_GRAPHICS) && !defined(CANVAS_NO_GRAPHICS_API)
#include <canvas/graphics.h>
#endif
#if defined(CANVAS_AUDIO) && !defined(CANVAS_NO_AUDIO_API)
#include <canvas/audio.h>
#endif
#if defined(CANVAS_NETWORK) && !defined(CANVAS_NO_NETWORK_API)
#include <canvas/network.h>
#endif
#if defined(CANVAS_INPUT) && !defined(CANVAS_NO_INPUT_API)
#include <canvas/input.h>
#endif

#endif /* !CANVAS_H */
