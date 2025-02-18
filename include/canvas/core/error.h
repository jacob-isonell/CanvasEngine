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
#include <assert.h>

ICE_NAMESPACE_BEGIN

#define ce_err int

/* Success codes */
#define CE_ETHRDDONE -4 /* Thread is done */
#define CE_ETHRDIDLE -3 /* Thread is idle */
#define CE_ETRUNC    -2 /* Array was truncated */
#define CE_ESUBOPTI  -1 /* Object is suboptimal */
#define CE_EOK        0 /* Not an error */
	
/* Error codes */
#define CE_EUNKNOWN       1 /* Unknown/unspecified error */
#define CE_EPERM          2 /* Operation not permitted */
#define CE_EACCESS        3 /* Permission denied */
#define CE_EINVAL         4 /* Invalid argument */
#define CE_EIO            5 /* Input/Output error */
#define CE_ENOMEM         6 /* No available memory */
#define CE_ENODEVMEM      7 /* No available device memory */
#define CE_ENOSYS         8 /* Function not implemented */
#define CE_ENOTSUP        9 /* Operation not supported */
#define CE_ETIMEOUT      10 /* Operation Timed out */
#define CE_ECONNTIMEDOUT 11 /* Connection timed out */
#define CE_ECONNREFUSED  12 /* Connection refused */
#define CE_EBUSY         13 /* Device or resource busy */
#define CE_EBADFILE      14 /* Invalid file handle */
#define CE_EISDIR        15 /* File path is a directory */
#define CE_ENOTDIR       16 /* File path is not a directory */
#define CE_EISFILE       17 /* File path is a file */
#define CE_ENOTFILE      18 /* File path is not a file */
#define CE_EEXIST        19 /* File/Object already exists */
#define CE_EBIGFILE      20 /* File too large */
#define CE_ENODEV        21 /* No such device */
#define CE_EDEV          22 /* Incompatible device */
#define CE_EDOM          23 /* Argument out of domain */
#define CE_ERANGE        24 /* Result out of range */
#define CE_EDEADLOCK     25 /* Resource deadlock avoided */
#define CE_EWOULDBLOCK   26 /* Operation would be blocked */
#define CE_ECANCELED     27 /* Operation canceled */
#define CE_EUNRECOV      28 /* State is unrecoverable */
#define CE_ENOTREADY     29 /* Object is not ready for use */
#define CE_EDATA         30 /* Data is incompatible */
#define CE_EINITFAIL     31 /* Object initialization failed */
#define CE_EDEVLOST      32 /* Device was lost */
#define CE_EMEMMAP       33 /* Memory mapping failed */
#define CE_EDRIVER       34 /* Driver is incompatible */
#define CE_EOBJ          35 /* Too many objects */
#define CE_EOUTOFDATE    36 /* Object is out of date */
#define CE_EVKLAYER      37 /* Vulkan layer cannot be found */
#define CE_EVKEXT        38 /* Vulkan extension cannot be found */
#define CE_EVKFEAT       39 /* Vulkan feature cannot be found */
#define CE_EVKFORMAT     40 /* Vulkan format not supported by device */
#define CE_EVKSURFACE    41 /* Vulkan surface was lost */

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
