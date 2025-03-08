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

#undef CE_COND_INIT
#undef ce_cnd

#ifdef CANVAS_HAS_THREADS

CE_NAMESPACE_BEGIN

#if defined(ICE_THREADS_POSIX)
#define ice_cnd pthread_cond_t
#define CE_COND_INIT PTHREAD_COND_INITIALIZER
#elif defined(ICE_THREADS_WIN32)
typedef struct ice_cnd_impl {
  CONDITION_VARIABLE var;
} ice_cnd_impl;
#define ice_cnd ice_cnd_impl
#define CE_COND_INIT {CONDITION_VARIABLE_INIT}
#endif

CE_NAMESPACE_END

#endif /* !CANVAS_HAS_THREADS */
