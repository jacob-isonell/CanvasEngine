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

/** @brief CanvasEngine's error type. Based on errno. Zero is a success value and any non-zero value is an error. */
#define ce_err int

/** @brief add documentation here! */
#define ce_success(code) ((code) == 0)

/** @brief add documentation here! */
#define ce_failure(code) (!ce_success(code))

/**
 * @brief Gets the error message associated with the error code.
 * @return A pointer to a c-style string stored in static memory.
 *         This pointer should not be free-ed or written to.
 */
CE_API
const char* ce_errstr(
	const ce_err error
);

#define CE_EOK             0x0000
#define CE_EUNDEF          0xFFFF
#define CE_EUNKNOWN        0x7FFF
#define CE_EPERM           0x0001
#define CE_ENOENT          0x0002
#define CE_ESRCH           0x0003
#define CE_EINTR           0x0004
#define CE_EIO             0x0005
#define CE_ENXIO           0x0006
#define CE_E2BIG           0x0007
#define CE_ENOEXEC         0x0008
#define CE_EBADF           0x0009
#define CE_ECHILD          0x000A
#define CE_EAGAIN          0x000B
#define CE_ENOMEM          0x000C
#define CE_EACCES          0x000D
#define CE_EFAULT          0x000E
#define CE_ENOTBLK         0x000F
#define CE_EBUSY           0x0010
#define CE_EEXIST          0x0011
#define CE_EXDEV           0x0012
#define CE_ENODEV          0x0013
#define CE_ENOTDIR         0x0014
#define CE_EISDIR          0x0015
#define CE_EINVAL          0x0016
#define CE_ENFILE          0x0017
#define CE_EMFILE          0x0018
#define CE_ENOTTY          0x0019
#define CE_ETXTBSY         0x001A
#define CE_EFBIG           0x001B
#define CE_ENOSPC          0x001C
#define CE_ESPIPE          0x001D
#define CE_EROFS           0x001E
#define CE_EMLINK          0x001F
#define CE_EPIPE           0x0020
#define CE_EDOM            0x0021
#define CE_ERANGE          0x0022
#define CE_EDEADLOCK       0x0023
#define CE_ENAMETOOLONG    0x0024
#define CE_ENOLCK          0x0025
#define CE_ENOSYS          0x0026
#define CE_ENOTEMPTY       0x0027
#define CE_ELOOP           0x0028
#define CE_ENOMSG          0x002A
#define CE_EIDRM           0x002B
#define CE_ECHRNG          0x002C
#define CE_EL2NSYNC        0x002D
#define CE_EL3HLT          0x002E
#define CE_EL3RST          0x002F
#define CE_ELNRNG          0x0030
#define CE_EUNATCH         0x0031
#define CE_ENOCSI          0x0032
#define CE_EL2HLT          0x0033
#define CE_EBADE           0x0034
#define CE_EBADR           0x0035
#define CE_EXFULL          0x0036
#define CE_ENOANO          0x0037
#define CE_EBADRQC         0x0038
#define CE_EBADSLT         0x0039
#define CE_EBFONT          0x003B
#define CE_ENOSTR          0x003C
#define CE_ENODATA         0x003D
#define CE_ETIME           0x003E
#define CE_ENOSR           0x003F
#define CE_ENONET          0x0040
#define CE_ENOPKG          0x0041
#define CE_EREMOTE         0x0042
#define CE_ENOLINK         0x0043
#define CE_EADV            0x0044
#define CE_ESRMNT          0x0045
#define CE_ECOMM           0x0046
#define CE_EPROTO          0x0047
#define CE_EMULTIHOP       0x0048
#define CE_EDOTDOT         0x0049
#define CE_EBADMSG         0x004A
#define CE_EOVERFLOW       0x004B
#define CE_ENOTUNIQ        0x004C
#define CE_EBADFD          0x004D
#define CE_EREMCHG         0x004E
#define CE_ELIBACC         0x004F
#define CE_ELIBBAD         0x0050
#define CE_ELIBSCN         0x0051
#define CE_ELIBMAX         0x0052
#define CE_ELIBEXEC        0x0053
#define CE_EILSEQ          0x0054
#define CE_ERESTART        0x0055
#define CE_ESTRPIPE        0x0056
#define CE_EUSERS          0x0057
#define CE_ENOTSOCK        0x0058
#define CE_EDESTADDRREQ    0x0059
#define CE_EMSGSIZE        0x005A
#define CE_EPROTOTYPE      0x005B
#define CE_ENOPROTOOPT     0x005C
#define CE_EPROTONOSUPPORT 0x005D
#define CE_ESOCKTNOSUPPORT 0x005E
#define CE_ENOTSUP         0x005F
#define CE_EPFNOSUPPORT    0x0060
#define CE_EAFNOSUPPORT    0x0061
#define CE_EADDRINUSE      0x0062
#define CE_EADDRNOTAVAIL   0x0063
#define CE_ENETDOWN        0x0064
#define CE_ENETUNREACH     0x0065
#define CE_ENETRESET       0x0066
#define CE_ECONNABORTED    0x0067
#define CE_ECONNRESET      0x0068
#define CE_ENOBUFS         0x0069
#define CE_EISCONN         0x006A
#define CE_ENOTCONN        0x006B
#define CE_ESHUTDOWN       0x006C
#define CE_ETOOMANYREFS    0x006D
#define CE_ETIMEDOUT       0x006E
#define CE_ECONNREFUSED    0x006F
#define CE_EHOSTDOWN       0x0070
#define CE_EHOSTUNREACH    0x0071
#define CE_EALREADY        0x0072
#define CE_EINPROGRESS     0x0073
#define CE_ESTALE          0x0074
#define CE_EUCLEAN         0x0075
#define CE_ENOTNAM         0x0076
#define CE_ENAVAIL         0x0077
#define CE_EISNAM          0x0078
#define CE_EREMOTEIO       0x0079
#define CE_EDQUOT          0x007A
#define CE_ENOMEDIUM       0x007B
#define CE_EMEDIUMTYPE     0x007C
#define CE_ECANCELED       0x007D
#define CE_ENOKEY          0x007E
#define CE_EKEYEXPIRED     0x007F
#define CE_EKEYREVOKED     0x0080
#define CE_EKEYREJECTED    0x0081
#define CE_EOWNERDEAD      0x0082
#define CE_ENOTRECOVERABLE 0x0083
#define CE_ERFKILL         0x0084
#define CE_EHWPOISON       0x0085
#define CE_EINIT           0x7000
#define CE_EFAIL           0x7001
#define CE_EDRIVER         0x7002
#define CE_EOBJECTS        0x7003
#define CE_EFRAG           0x7004
#define CE_EFORMAT         0x7005
#define CE_ELOST           0x7006
#define CE_EVKLAYER        0x7100
#define CE_EVKEXT          0x7101
#define CE_EVKFEAT         0x7102
#define CE_EVKFORMAT       0x7103
#define CE_EVKSURFACE      0x7104

#define CE_EDEADLK CE_EDEADLOCK

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_ERROR_H */
