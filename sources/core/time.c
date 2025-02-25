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

static int s_convert_base(int in) {
	switch (in) {
	case CE_TIME_UTC: return TIME_UTC;
	default: CE_UNREACHABLE();
	}
}

CE_API
ce_err ce_time_get(
	struct ce_time_t* out,
	int               base
) {
	if (out == NULL) {
		return CE_EINVAL;
	}
	
	struct timespec now;
	if (timespec_get(&now, s_convert_base(base)) == 0) {
		return CE_EUNKNOWN;
	}
	
	out->sec = (unsigned long long int)now.tv_sec;
	out->nsec = (unsigned long long int)now.tv_nsec;
	
	return CE_EOK;
}
