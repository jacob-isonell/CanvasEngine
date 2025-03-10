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
#include <canvas/core/random.h>

CE_API ce_err ce_rand(unsigned int* seed, unsigned int* out) {
  if (out == NULL) {
    return CE_EINVAL;
  }
  
  unsigned int s = seed ? *seed : (unsigned int)time(NULL);
  if (s == 0) {
    s = 1;
  }
  
  s = (0x5E61A729 * s) % CE_RANDMAX;
  
  *out = s;
  if (seed) {
    *seed = s;
  }
  return CE_EOK;
}
