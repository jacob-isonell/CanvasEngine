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
#include <canvas/core/error.h>

CE_API const char* ce_errstr(ce_err error) {
	switch (error) {
	case CE_ETHRDDONE      : return "thread is done";
	case CE_ETHRDIDLE      : return "thread is idle";
	case CE_ETRUNC         : return "array was truncated";
	case CE_ESUBOPTI       : return "object is suboptimal";
	case CE_EOK            : return "not an error";
	
	default:
	case CE_EUNKNOWN       : return "unknown/unspecified error";
	case CE_EPERM          : return "operation not permitted";
	case CE_EACCESS        : return "permission denied";
	case CE_EINVAL         : return "invalid argument";
	case CE_EIO            : return "input/output error";
	case CE_ENOMEM         : return "no available memory";
	case CE_ENODEVMEM      : return "no available device memory";
	case CE_ENOSYS         : return "function not implemented";
	case CE_ENOTSUP        : return "operation not supported";
	case CE_ETIMEOUT       : return "operation timed out";
	case CE_ECONNTIMEDOUT  : return "connection timed out";
	case CE_ECONNREFUSED   : return "connection refused";
	case CE_EBUSY          : return "device or resource busy";
	case CE_EBADFILE       : return "invalid file handle";
	case CE_EISDIR         : return "file path is a directory";
	case CE_ENOTDIR        : return "file path is not a directory";
	case CE_EISFILE        : return "file path is a file";
	case CE_ENOTFILE       : return "file path is not a file";
	case CE_EEXIST         : return "file/object already exists";
	case CE_EBIGFILE       : return "file too large";
	case CE_ENODEV         : return "no such device";
	case CE_EDEV           : return "incompatible device";
	case CE_EDOM           : return "argument out of domain";
	case CE_ERANGE         : return "result out of range";
	case CE_EDEADLOCK      : return "resource deadlock avoided";
	case CE_EWOULDBLOCK    : return "operation would be blocked";
	case CE_ECANCELED      : return "operation canceled";
	case CE_EUNRECOV       : return "state is unrecoverable";
	case CE_ENOTREADY      : return "object is not ready for use";
	case CE_EDATA          : return "data is incompatible";
	case CE_EINITFAIL      : return "object initialization failed";
	case CE_EDEVLOST       : return "device was lost";
	case CE_EMEMMAP        : return "memory mapping failed";
	case CE_EDRIVER        : return "driver is incompatible";
	case CE_EOBJ           : return "too many objects";
	case CE_EOUTOFDATE     : return "object is out of date";
	case CE_EVKLAYER       : return "vulkan layer cannot be found";
	case CE_EVKEXT         : return "vulkan extension cannot be found";
	case CE_EVKFEAT        : return "vulkan feature cannot be found";
	case CE_EVKFORMAT      : return "vulkan format not supported by device";
	case CE_EVKSURFACE     : return "vulkan surface was lost";
	}
}

ICE_API ce_err ifrom_errno(int errno_value) {
	switch (errno_value) {
	default: return CE_EUNKNOWN;
	case 0: return CE_EOK;
	}
}
