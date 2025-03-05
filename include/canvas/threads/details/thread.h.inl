/**************************************************************************
** CanvasEngine is a cross platform multimedia library in C++20          **
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

#undef ce_thrd
#undef ce_once_flag
#undef CE_ONCE_FLAG_INIT

#ifdef CANVAS_HAS_THREADS

ICE_NAMESPACE_BEGIN

#if defined(ICE_THREADS_POSIX)
typedef pthread_t ice_thrd;
typedef pthread_once_t ice_once_flag;
#define CE_ONCE_FLAG_INIT PTHREAD_ONCE_INIT
#elif defined(ICE_THREADS_WIN32)
typedef HANDLE ice_thrd;

typedef struct ice_once_flag {
  CRITICAL_SECTION mtx;
  cebool called;
} ice_once_flag;
#define CE_ONCE_FLAG_INIT {0}
#endif

ICE_NAMESPACE_END

#endif /* !CANVAS_HAS_THREADS */
