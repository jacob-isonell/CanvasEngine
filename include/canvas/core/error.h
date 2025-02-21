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

ICE_NAMESPACE_BEGIN

/** @brief CanvasEngine's error type. Based on errno. Values less than or equal to 0 is a success value. */
#define ce_err int

#define ce_success(code) ((code) <= 0)
#define ce_failure(code) (!ce_success(code))

/**
 * @brief Gets the error message associated with the error code.
 * @return A pointer to a c-style string stored in static memory.
 *         This pointer should not be free-ed or written to.
 */
CE_API const char* ce_errstr(ce_err error);

/* Success codes */
#define CE_EOK 0x0000 /* No error */

/* Error codes */
#define CE_EPERM            0x0001 /* Operation not permitted */
#define CE_ENOENT           0x0002 /* No such file or directory */
#define CE_ESRCH            0x0003 /* No such process */
#define CE_EINTR            0x0004 /* Interrupted system call */
#define CE_EIO              0x0005 /* Input/output error */
#define CE_ENXIO            0x0006 /* No such device or address */
#define CE_E2BIG            0x0007 /* Argument list too long */
#define CE_ENOEXEC          0x0008 /* Exec format error */
#define CE_EBADF            0x0009 /* Bad file descriptor */
#define CE_ECHILD           0x000A /* No child processes */
#define CE_EAGAIN           0x000B /* Resource temporarily unavailable */
#define CE_ENOMEM           0x000C /* Cannot allocate memory */
#define CE_EACCES           0x000D /* Permission denied */
#define CE_EFAULT           0x000E /* Bad address */
#define CE_ENOTBLK          0x000F /* Block device required */
#define CE_EBUSY            0x0010 /* Device or resource busy */
#define CE_EEXIST           0x0011 /* File exists */
#define CE_EXDEV            0x0012 /* Invalid cross-device link */
#define CE_ENODEV           0x0013 /* No such device */
#define CE_ENOTDIR          0x0014 /* Not a directory */
#define CE_EISDIR           0x0015 /* Is a directory */
#define CE_EINVAL           0x0016 /* Invalid argument */
#define CE_ENFILE           0x0017 /* Too many open files in system */
#define CE_EMFILE           0x0018 /* Too many open files */
#define CE_ENOTTY           0x0019 /* Inappropriate ioctl for device */
#define CE_ETXTBSY          0x001A /* Text file busy */
#define CE_EFBIG            0x001B /* File too large */
#define CE_ENOSPC           0x001C /* No space left on device */
#define CE_ESPIPE           0x001D /* Illegal seek */
#define CE_EROFS            0x001E /* Read-only file system */
#define CE_EMLINK           0x001F /* Too many links */
#define CE_EPIPE            0x0020 /* Broken pipe */
#define CE_EDOM             0x0021 /* Numerical argument out of domain */
#define CE_ERANGE           0x0022 /* Numerical result out of range */
#define CE_EDEADLOCK        0x0023 /* Resource deadlock avoided */
#define CE_ENAMETOOLONG     0x0024 /* File name too long */
#define CE_ENOLCK           0x0025 /* No locks available */
#define CE_ENOSYS           0x0026 /* Function not implemented */
#define CE_ENOTEMPTY        0x0027 /* Directory not empty */
#define CE_ELOOP            0x0028 /* Too many levels of symbolic links */
#define CE_ENOMSG           0x002A /* No message of desired type */
#define CE_EIDRM            0x002B /* Identifier removed */
#define CE_ECHRNG           0x002C /* Channel number out of range */
#define CE_EL2NSYNC         0x002D /* Level 2 not synchronized */
#define CE_EL3HLT           0x002E /* Level 3 halted */
#define CE_EL3RST           0x002F /* Level 3 reset */
#define CE_ELNRNG           0x0030 /* Link number out of range */
#define CE_EUNATCH          0x0031 /* Protocol driver not attached */
#define CE_ENOCSI           0x0032 /* No CSI structure available */
#define CE_EL2HLT           0x0033 /* Level 2 halted */
#define CE_EBADE            0x0034 /* Invalid exchange */
#define CE_EBADR            0x0035 /* Invalid request descriptor */
#define CE_EXFULL           0x0036 /* Exchange full */
#define CE_ENOANO           0x0037 /* No anode */
#define CE_EBADRQC          0x0038 /* Invalid request code */
#define CE_EBADSLT          0x0039 /* Invalid slot */
#define CE_EBFONT           0x003B /* Bad font file format */
#define CE_ENOSTR           0x003C /* Device not a stream */
#define CE_ENODATA          0x003D /* No data available */
#define CE_ETIME            0x003E /* Timer expired */
#define CE_ENOSR            0x003F /* Out of streams resources */
#define CE_ENONET           0x0040 /* Machine is not on the network */
#define CE_ENOPKG           0x0041 /* Package not installed */
#define CE_EREMOTE          0x0042 /* Object is remote */
#define CE_ENOLINK          0x0043 /* Link has been severed */
#define CE_EADV             0x0044 /* Advertise error */
#define CE_ESRMNT           0x0045 /* Srmount error */
#define CE_ECOMM            0x0046 /* Communication error on send */
#define CE_EPROTO           0x0047 /* Protocol error */
#define CE_EMULTIHOP        0x0048 /* Multihop attempted */
#define CE_EDOTDOT          0x0049 /* RFS specific error */
#define CE_EBADMSG          0x004A /* Bad message */
#define CE_EOVERFLOW        0x004B /* Value too large for defined data type */
#define CE_ENOTUNIQ         0x004C /* Name not unique on network */
#define CE_EBADFD           0x004D /* File descriptor in bad state */
#define CE_EREMCHG          0x004E /* Remote address changed */
#define CE_ELIBACC          0x004F /* Can not access a needed shared library */
#define CE_ELIBBAD          0x0050 /* Accessing a corrupted shared library */
#define CE_ELIBSCN          0x0051 /* .lib section in a.out corrupted */
#define CE_ELIBMAX          0x0052 /* Attempting to link in too many shared libraries */
#define CE_ELIBEXEC         0x0053 /* Cannot exec a shared library directly */
#define CE_EILSEQ           0x0054 /* Invalid or incomplete multibyte or wide character */
#define CE_ERESTART         0x0055 /* Interrupted system call should be restarted */
#define CE_ESTRPIPE         0x0056 /* Streams pipe error */
#define CE_EUSERS           0x0057 /* Too many users */
#define CE_ENOTSOCK         0x0058 /* Socket operation on non-socket */
#define CE_EDESTADDRREQ     0x0059 /* Destination address required */
#define CE_EMSGSIZE         0x005A /* Message too long */
#define CE_EPROTOTYPE       0x005B /* Protocol wrong type for socket */
#define CE_ENOPROTOOPT      0x005C /* Protocol not available */
#define CE_EPROTONOSUPPORT  0x005D /* Protocol not supported */
#define CE_ESOCKTNOSUPPORT  0x005E /* Socket type not supported */
#define CE_ENOTSUP          0x005F /* Operation not supported */
#define CE_EPFNOSUPPORT     0x0060 /* Protocol family not supported */
#define CE_EAFNOSUPPORT     0x0061 /* Address family not supported by protocol */
#define CE_EADDRINUSE       0x0062 /* Address already in use */
#define CE_EADDRNOTAVAIL    0x0063 /* Cannot assign requested address */
#define CE_ENETDOWN         0x0064 /* Network is down */
#define CE_ENETUNREACH      0x0065 /* Network is unreachable */
#define CE_ENETRESET        0x0066 /* Network dropped connection on reset */
#define CE_ECONNABORTED     0x0067 /* Software caused connection abort */
#define CE_ECONNRESET       0x0068 /* Connection reset by peer */
#define CE_ENOBUFS          0x0069 /* No buffer space available */
#define CE_EISCONN          0x006A /* Transport endpoint is already connected */
#define CE_ENOTCONN         0x006B /* Transport endpoint is not connected */
#define CE_ESHUTDOWN        0x006C /* Cannot send after transport endpoint shutdown */
#define CE_ETOOMANYREFS     0x006D /* Too many references: cannot splice */
#define CE_ETIMEDOUT        0x006E /* Connection timed out */
#define CE_ECONNREFUSED     0x006F /* Connection refused */
#define CE_EHOSTDOWN        0x0070 /* Host is down */
#define CE_EHOSTUNREACH     0x0071 /* No route to host */
#define CE_EALREADY         0x0072 /* Operation already in progress */
#define CE_EINPROGRESS      0x0073 /* Operation now in progress */
#define CE_ESTALE           0x0074 /* Stale file handle */
#define CE_EUCLEAN          0x0075 /* Structure needs cleaning */
#define CE_ENOTNAM          0x0076 /* Not a XENIX named type file */
#define CE_ENAVAIL          0x0077 /* No XENIX semaphores available */
#define CE_EISNAM           0x0078 /* Is a named type file */
#define CE_EREMOTEIO        0x0079 /* Remote I/O error */
#define CE_EDQUOT           0x007A /* Disk quota exceeded */
#define CE_ENOMEDIUM        0x007B /* No medium found */
#define CE_EMEDIUMTYPE      0x007C /* Wrong medium type */
#define CE_ECANCELED        0x007D /* Operation canceled */
#define CE_ENOKEY           0x007E /* Required key not available */
#define CE_EKEYEXPIRED      0x007F /* Key has expired */
#define CE_EKEYREVOKED      0x0080 /* Key has been revoked */
#define CE_EKEYREJECTED     0x0081 /* Key was rejected by service */
#define CE_EOWNERDEAD       0x0082 /* Owner died */
#define CE_ENOTRECOVERABLE  0x0083 /* State not recoverable */
#define CE_ERFKILL          0x0084 /* Operation not possible due to RF-kill */
#define CE_EHWPOISON        0x0085 /* Memory page has hardware error */
#define CE_EVKLAYER         0x7000 /* Vulkan layer cannot be found */
#define CE_EVKEXT           0x7001 /* Vulkan extension cannot be found */
#define CE_EVKFEAT          0x7002 /* Vulkan feature cannot be found */
#define CE_EVKFORMAT        0x7003 /* Vulkan format not supported by device */
#define CE_EVKSURFACE       0x7004 /* Vulkan surface was lost */
#define CE_EUNKNOWN         0x7FFF /* Unknown/unspecified error */

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_ERROR_H */
