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

#ifndef CANVAS_CORE_SIGNAL_H
#define CANVAS_CORE_SIGNAL_H

#include <canvas/core/memory.h>

CE_NAMESPACE_BEGIN

typedef int ce_sigtype;
typedef int ce_sigstatus;

#define CE_SIGOK 0
#define CE_SIGERROR 1

#define CE_SIGTERM 0
typedef struct ce_sig_term_t {
  int unused;
} ce_sig_term_t;

typedef struct ce_sigarg {
  ce_sigtype type;
  union {
    ce_sig_term_t term;
  } data;
} ce_sigarg;



CE_NAMESPACE_END

#endif /* !CANVAS_CORE_SIGNAL_H */
