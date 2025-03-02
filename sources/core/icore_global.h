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

#ifndef ICORE_GLOBAL_H
#define ICORE_GLOBAL_H

#include "icore_base.h"
#include <canvas/core/memory.h>
#include <canvas/threads/mutex.h>

ICE_NAMESPACE_BEGIN

typedef struct icore_t {
  size_t init_count;
  
  struct {
    ce_alloc_t alloc;
    ce_mtx lck;
  } mem;
  
  struct {
    ce_utf8* name;
    unsigned int version;
  } app_info, engine_info;
} icore_t;

ICE_API extern icore_t icore;

ICE_NAMESPACE_END

#endif /* !ICORE_GLOBAL_H */
