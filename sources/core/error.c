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
	default:
		return strerror(error);
	
	}
}

/*CE_API const char* ce_errstr(ce_err error) {
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
	case EINVAL         : return "invalid argument";
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
}*/

#if 0
#define CE_EDOM          EDOM /* Argument out of domain */
#define CE_ERANGE        ERANGE /* Result out of range */

#define CE_EPERM         0x00002 /* Operation not permitted */
#define CE_EACCESS       0x00003 /* Permission denied */
#define CE_EINVAL        0x00004 /* Invalid argument */
#define CE_EIO           0x00005 /* Input/Output error */
#define CE_ENOMEM        0x00006 /* No available memory */
#define CE_ENODEVMEM     0x00007 /* No available device memory */
#define CE_ENOSYS        0x00008 /* Function not implemented */
#define CE_ENOTSUP       0x00009 /* Operation not supported */
#define CE_ETIMEOUT      0x0000A /* Operation Timed out */
#define CE_ECONNTIMEDOUT 0x0000B /* Connection timed out */
#define CE_ECONNREFUSED  0x0000C /* Connection refused */
#define CE_EBUSY         0x0000D /* Device or resource busy */
#define CE_EBADFILE      0x0000E /* Invalid file handle */
#define CE_EISDIR        0x0000F /* File path is a directory */
#define CE_ENOTDIR       0x00010 /* File path is not a directory */
#define CE_EISFILE       0x00011 /* File path is a file */
#define CE_ENOTFILE      0x00012 /* File path is not a file */
#define CE_EEXIST        0x00013 /* File/Object already exists */
#define CE_EBIGFILE      0x00014 /* File too large */
#define CE_ENODEV        0x00015 /* No such device */
#define CE_EDEV          0x00016 /* Incompatible device */
#define CE_EDEADLOCK     0x00019 /* Resource deadlock avoided */
#define CE_EWOULDBLOCK   0x0001A /* Operation would be blocked */
#define CE_ECANCELED     0x0001B /* Operation canceled */
#define CE_EUNRECOV      0x0001C /* State is unrecoverable */
#define CE_ENOTREADY     0x0001D /* Object is not ready for use */
#define CE_EDATA         0x0001E /* Data is incompatible */
#define CE_EINITFAIL     0x0001F /* Object initialization failed */
#define CE_EDEVLOST      0x00020 /* Device was lost */
#define CE_EMEMMAP       0x00021 /* Memory mapping failed */
#define CE_EDRIVER       0x00022 /* Driver is incompatible */
#define CE_EOBJ          0x00023 /* Too many objects */
#define CE_EOUTOFDATE    0x00024 /* Object is out of date */
#define CE_EINTR         0x00025
#endif
