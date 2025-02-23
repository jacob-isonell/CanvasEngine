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
#ifdef CANVAS_GRAPHICS
#include <canvas/graphics.h>
#endif
#ifdef CANVAS_AUDIO
#include <canvas/audio.h>
#endif
#ifdef CANVAS_NETWORK
#include <canvas/network.h>
#endif
#include <canvas/math.h>
#include <canvas/threads.h>

#endif /* !CANVAS_H */
