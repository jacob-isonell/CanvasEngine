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

#ifndef CANVAS_CORE_ERROR_H
#define CANVAS_CORE_ERROR_H

#include <canvas/core/base.h>
#include <errno.h>
#include <assert.h>

ICE_NAMESPACE_BEGIN

/* Error codes */
#define CE_EUNKNOWN      0x7FFF /* Unknown/unspecified error */
#define CE_EVKLAYER      0x7000 /* Vulkan layer cannot be found */
#define CE_EVKEXT        0x7001 /* Vulkan extension cannot be found */
#define CE_EVKFEAT       0x7002 /* Vulkan feature cannot be found */
#define CE_EVKFORMAT     0x7003 /* Vulkan format not supported by device */
#define CE_EVKSURFACE    0x7004 /* Vulkan surface was lost */

#define ce_failure(code) (0 < (code))
#define ce_success(code) ((code) <= 0)

/**
 * @brief Gets the error message associated with the error code.
 * @return A pointer to a c-style string stored in static memory.
 *         This pointer should not be free-ed or written to.
 */
CE_API const char* ce_errstr(ce_err error);

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_ERROR_H */
