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
	case CE_EPERM            : return "Operation not permitted";
	case CE_ENOENT           : return "No such file or directory";
	case CE_ESRCH            : return "No such process";
	case CE_EINTR            : return "Interrupted system call";
	case CE_EIO              : return "Input/output error";
	case CE_ENXIO            : return "No such device or address";
	case CE_E2BIG            : return "Argument list too long";
	case CE_ENOEXEC          : return "Exec format error";
	case CE_EBADF            : return "Bad file descriptor";
	case CE_ECHILD           : return "No child processes";
	case CE_EAGAIN           : return "Resource temporarily unavailable";
	case CE_ENOMEM           : return "Cannot allocate memory";
	case CE_EACCES           : return "Permission denied";
	case CE_EFAULT           : return "Bad address";
	case CE_ENOTBLK          : return "Block device required";
	case CE_EBUSY            : return "Device or resource busy";
	case CE_EEXIST           : return "File exists";
	case CE_EXDEV            : return "Invalid cross-device link";
	case CE_ENODEV           : return "No such device";
	case CE_ENOTDIR          : return "Not a directory";
	case CE_EISDIR           : return "Is a directory";
	case CE_EINVAL           : return "Invalid argument";
	case CE_ENFILE           : return "Too many open files in system";
	case CE_EMFILE           : return "Too many open files";
	case CE_ENOTTY           : return "Inappropriate ioctl for device";
	case CE_ETXTBSY          : return "Text file busy";
	case CE_EFBIG            : return "File too large";
	case CE_ENOSPC           : return "No space left on device";
	case CE_ESPIPE           : return "Illegal seek";
	case CE_EROFS            : return "Read-only file system";
	case CE_EMLINK           : return "Too many links";
	case CE_EPIPE            : return "Broken pipe";
	case CE_EDOM             : return "Numerical argument out of domain";
	case CE_ERANGE           : return "Numerical result out of range";
	case CE_EDEADLOCK        : return "Resource deadlock avoided";
	case CE_ENAMETOOLONG     : return "File name too long";
	case CE_ENOLCK           : return "No locks available";
	case CE_ENOSYS           : return "Function not implemented";
	case CE_ENOTEMPTY        : return "Directory not empty";
	case CE_ELOOP            : return "Too many levels of symbolic links";
	case CE_ENOMSG           : return "No message of desired type";
	case CE_EIDRM            : return "Identifier removed";
	case CE_ECHRNG           : return "Channel number out of range";
	case CE_EL2NSYNC         : return "Level 2 not synchronized";
	case CE_EL3HLT           : return "Level 3 halted";
	case CE_EL3RST           : return "Level 3 reset";
	case CE_ELNRNG           : return "Link number out of range";
	case CE_EUNATCH          : return "Protocol driver not attached";
	case CE_ENOCSI           : return "No CSI structure available";
	case CE_EL2HLT           : return "Level 2 halted";
	case CE_EBADE            : return "Invalid exchange";
	case CE_EBADR            : return "Invalid request descriptor";
	case CE_EXFULL           : return "Exchange full";
	case CE_ENOANO           : return "No anode";
	case CE_EBADRQC          : return "Invalid request code";
	case CE_EBADSLT          : return "Invalid slot";
	case CE_EBFONT           : return "Bad font file format";
	case CE_ENOSTR           : return "Device not a stream";
	case CE_ENODATA          : return "No data available";
	case CE_ETIME            : return "Timer expired";
	case CE_ENOSR            : return "Out of streams resources";
	case CE_ENONET           : return "Machine is not on the network";
	case CE_ENOPKG           : return "Package not installed";
	case CE_EREMOTE          : return "Object is remote";
	case CE_ENOLINK          : return "Link has been severed";
	case CE_EADV             : return "Advertise error";
	case CE_ESRMNT           : return "Srmount error";
	case CE_ECOMM            : return "Communication error on send";
	case CE_EPROTO           : return "Protocol error";
	case CE_EMULTIHOP        : return "Multihop attempted";
	case CE_EDOTDOT          : return "RFS specific error";
	case CE_EBADMSG          : return "Bad message";
	case CE_EOVERFLOW        : return "Value too large for defined data type";
	case CE_ENOTUNIQ         : return "Name not unique on network";
	case CE_EBADFD           : return "File descriptor in bad state";
	case CE_EREMCHG          : return "Remote address changed";
	case CE_ELIBACC          : return "Can not access a needed shared library";
	case CE_ELIBBAD          : return "Accessing a corrupted shared library";
	case CE_ELIBSCN          : return ".lib section in a.out corrupted";
	case CE_ELIBMAX          : return "Attempting to link in too many shared libraries";
	case CE_ELIBEXEC         : return "Cannot exec a shared library directly";
	case CE_EILSEQ           : return "Invalid or incomplete multibyte or wide character";
	case CE_ERESTART         : return "Interrupted system call should be restarted";
	case CE_ESTRPIPE         : return "Streams pipe error";
	case CE_EUSERS           : return "Too many users";
	case CE_ENOTSOCK         : return "Socket operation on non-socket";
	case CE_EDESTADDRREQ     : return "Destination address required";
	case CE_EMSGSIZE         : return "Message too long";
	case CE_EPROTOTYPE       : return "Protocol wrong type for socket";
	case CE_ENOPROTOOPT      : return "Protocol not available";
	case CE_EPROTONOSUPPORT  : return "Protocol not supported";
	case CE_ESOCKTNOSUPPORT  : return "Socket type not supported";
	case CE_ENOTSUP          : return "Operation not supported";
	case CE_EPFNOSUPPORT     : return "Protocol family not supported";
	case CE_EAFNOSUPPORT     : return "Address family not supported by protocol";
	case CE_EADDRINUSE       : return "Address already in use";
	case CE_EADDRNOTAVAIL    : return "Cannot assign requested address";
	case CE_ENETDOWN         : return "Network is down";
	case CE_ENETUNREACH      : return "Network is unreachable";
	case CE_ENETRESET        : return "Network dropped connection on reset";
	case CE_ECONNABORTED     : return "Software caused connection abort";
	case CE_ECONNRESET       : return "Connection reset by peer";
	case CE_ENOBUFS          : return "No buffer space available";
	case CE_EISCONN          : return "Transport endpoint is already connected";
	case CE_ENOTCONN         : return "Transport endpoint is not connected";
	case CE_ESHUTDOWN        : return "Cannot send after transport endpoint shutdown";
	case CE_ETOOMANYREFS     : return "Too many references: cannot splice";
	case CE_ETIMEDOUT        : return "Connection timed out";
	case CE_ECONNREFUSED     : return "Connection refused";
	case CE_EHOSTDOWN        : return "Host is down";
	case CE_EHOSTUNREACH     : return "No route to host";
	case CE_EALREADY         : return "Operation already in progress";
	case CE_EINPROGRESS      : return "Operation now in progress";
	case CE_ESTALE           : return "Stale file handle";
	case CE_EUCLEAN          : return "Structure needs cleaning";
	case CE_ENOTNAM          : return "Not a XENIX named type file";
	case CE_ENAVAIL          : return "No XENIX semaphores available";
	case CE_EISNAM           : return "Is a named type file";
	case CE_EREMOTEIO        : return "Remote I/O error";
	case CE_EDQUOT           : return "Disk quota exceeded";
	case CE_ENOMEDIUM        : return "No medium found";
	case CE_EMEDIUMTYPE      : return "Wrong medium type";
	case CE_ECANCELED        : return "Operation canceled";
	case CE_ENOKEY           : return "Required key not available";
	case CE_EKEYEXPIRED      : return "Key has expired";
	case CE_EKEYREVOKED      : return "Key has been revoked";
	case CE_EKEYREJECTED     : return "Key was rejected by service";
	case CE_EOWNERDEAD       : return "Owner died";
	case CE_ENOTRECOVERABLE  : return "State not recoverable";
	case CE_ERFKILL          : return "Operation not possible due to RF-kill";
	case CE_EHWPOISON        : return "Memory page has hardware error";
	case CE_EVKLAYER         : return "Vulkan layer cannot be found";
	case CE_EVKEXT           : return "Vulkan extension cannot be found";
	case CE_EVKFEAT          : return "Vulkan feature cannot be found";
	case CE_EVKFORMAT        : return "Vulkan format not supported by device";
	case CE_EVKSURFACE       : return "Vulkan surface was lost";
	default:
	case CE_EUNKNOWN         : return "Unknown/unspecified error";
	}
}

ICE_API ce_err ierrno(int in) {
	switch (in) {
	default: return CE_EUNKNOWN;
#ifdef EPERM
	case CE_EPERM: return EPERM;
#endif /* !EPERM */
#ifdef ENOENT
	case CE_ENOENT: return ENOENT;
#endif /* !ENOENT */
#ifdef ESRCH
	case CE_ESRCH: return ESRCH;
#endif /* !ESRCH */
#ifdef EINTR
	case CE_EINTR: return EINTR;
#endif /* !EINTR */
#ifdef EIO
	case CE_EIO: return EIO;
#endif /* !EIO */
#ifdef ENXIO
	case CE_ENXIO: return ENXIO;
#endif /* !ENXIO */
#ifdef E2BIG
	case CE_E2BIG: return E2BIG;
#endif /* !E2BIG */
#ifdef ENOEXEC
	case CE_ENOEXEC: return ENOEXEC;
#endif /* !ENOEXEC */
#ifdef EBADF
	case CE_EBADF: return EBADF;
#endif /* !EBADF */
#ifdef ECHILD
	case CE_ECHILD: return ECHILD;
#endif /* !ECHILD */
#ifdef EAGAIN
	case CE_EAGAIN: return EAGAIN;
#endif /* !EAGAIN */
#ifdef ENOMEM
	case CE_ENOMEM: return ENOMEM;
#endif /* !ENOMEM */
#ifdef EACCES
	case CE_EACCES: return EACCES;
#endif /* !EACCES */
#ifdef EFAULT
	case CE_EFAULT: return EFAULT;
#endif /* !EFAULT */
#ifdef ENOTBLK
	case CE_ENOTBLK: return ENOTBLK;
#endif /* !ENOTBLK */
#ifdef EBUSY
	case CE_EBUSY: return EBUSY;
#endif /* !EBUSY */
#ifdef EEXIST
	case CE_EEXIST: return EEXIST;
#endif /* !EEXIST */
#ifdef EXDEV
	case CE_EXDEV: return EXDEV;
#endif /* !EXDEV */
#ifdef ENODEV
	case CE_ENODEV: return ENODEV;
#endif /* !ENODEV */
#ifdef ENOTDIR
	case CE_ENOTDIR: return ENOTDIR;
#endif /* !ENOTDIR */
#ifdef EISDIR
	case CE_EISDIR: return EISDIR;
#endif /* !EISDIR */
#ifdef EINVAL
	case CE_EINVAL: return EINVAL;
#endif /* !EINVAL */
#ifdef ENFILE
	case CE_ENFILE: return ENFILE;
#endif /* !ENFILE */
#ifdef EMFILE
	case CE_EMFILE: return EMFILE;
#endif /* !EMFILE */
#ifdef ENOTTY
	case CE_ENOTTY: return ENOTTY;
#endif /* !ENOTTY */
#ifdef ETXTBSY
	case CE_ETXTBSY: return ETXTBSY;
#endif /* !ETXTBSY */
#ifdef EFBIG
	case CE_EFBIG: return EFBIG;
#endif /* !EFBIG */
#ifdef ENOSPC
	case CE_ENOSPC: return ENOSPC;
#endif /* !ENOSPC */
#ifdef ESPIPE
	case CE_ESPIPE: return ESPIPE;
#endif /* !ESPIPE */
#ifdef EROFS
	case CE_EROFS: return EROFS;
#endif /* !EROFS */
#ifdef EMLINK
	case CE_EMLINK: return EMLINK;
#endif /* !EMLINK */
#ifdef EPIPE
	case CE_EPIPE: return EPIPE;
#endif /* !EPIPE */
#ifdef EDOM
	case CE_EDOM: return EDOM;
#endif /* !EDOM */
#ifdef ERANGE
	case CE_ERANGE: return ERANGE;
#endif /* !ERANGE */
#ifdef EDEADLOCK
	case CE_EDEADLOCK: return EDEADLOCK;
#endif /* !EDEADLOCK */
#ifdef ENAMETOOLONG
	case CE_ENAMETOOLONG: return ENAMETOOLONG;
#endif /* !ENAMETOOLONG */
#ifdef ENOLCK
	case CE_ENOLCK: return ENOLCK;
#endif /* !ENOLCK */
#ifdef ENOSYS
	case CE_ENOSYS: return ENOSYS;
#endif /* !ENOSYS */
#ifdef ENOTEMPTY
	case CE_ENOTEMPTY: return ENOTEMPTY;
#endif /* !ENOTEMPTY */
#ifdef ELOOP
	case CE_ELOOP: return ELOOP;
#endif /* !ELOOP */
#ifdef ENOMSG
	case CE_ENOMSG: return ENOMSG;
#endif /* !ENOMSG */
#ifdef EIDRM
	case CE_EIDRM: return EIDRM;
#endif /* !EIDRM */
#ifdef ECHRNG
	case CE_ECHRNG: return ECHRNG;
#endif /* !ECHRNG */
#ifdef EL2NSYNC
	case CE_EL2NSYNC: return EL2NSYNC;
#endif /* !EL2NSYNC */
#ifdef EL3HLT
	case CE_EL3HLT: return EL3HLT;
#endif /* !EL3HLT */
#ifdef EL3RST
	case CE_EL3RST: return EL3RST;
#endif /* !EL3RST */
#ifdef ELNRNG
	case CE_ELNRNG: return ELNRNG;
#endif /* !ELNRNG */
#ifdef EUNATCH
	case CE_EUNATCH: return EUNATCH;
#endif /* !EUNATCH */
#ifdef ENOCSI
	case CE_ENOCSI: return ENOCSI;
#endif /* !ENOCSI */
#ifdef EL2HLT
	case CE_EL2HLT: return EL2HLT;
#endif /* !EL2HLT */
#ifdef EBADE
	case CE_EBADE: return EBADE;
#endif /* !EBADE */
#ifdef EBADR
	case CE_EBADR: return EBADR;
#endif /* !EBADR */
#ifdef EXFULL
	case CE_EXFULL: return EXFULL;
#endif /* !EXFULL */
#ifdef ENOANO
	case CE_ENOANO: return ENOANO;
#endif /* !ENOANO */
#ifdef EBADRQC
	case CE_EBADRQC: return EBADRQC;
#endif /* !EBADRQC */
#ifdef EBADSLT
	case CE_EBADSLT: return EBADSLT;
#endif /* !EBADSLT */
#ifdef EBFONT
	case CE_EBFONT: return EBFONT;
#endif /* !EBFONT */
#ifdef ENOSTR
	case CE_ENOSTR: return ENOSTR;
#endif /* !ENOSTR */
#ifdef ENODATA
	case CE_ENODATA: return ENODATA;
#endif /* !ENODATA */
#ifdef ETIME
	case CE_ETIME: return ETIME;
#endif /* !ETIME */
#ifdef ENOSR
	case CE_ENOSR: return ENOSR;
#endif /* !ENOSR */
#ifdef ENONET
	case CE_ENONET: return ENONET;
#endif /* !ENONET */
#ifdef ENOPKG
	case CE_ENOPKG: return ENOPKG;
#endif /* !ENOPKG */
#ifdef EREMOTE
	case CE_EREMOTE: return EREMOTE;
#endif /* !EREMOTE */
#ifdef ENOLINK
	case CE_ENOLINK: return ENOLINK;
#endif /* !ENOLINK */
#ifdef EADV
	case CE_EADV: return EADV;
#endif /* !EADV */
#ifdef ESRMNT
	case CE_ESRMNT: return ESRMNT;
#endif /* !ESRMNT */
#ifdef ECOMM
	case CE_ECOMM: return ECOMM;
#endif /* !ECOMM */
#ifdef EPROTO
	case CE_EPROTO: return EPROTO;
#endif /* !EPROTO */
#ifdef EMULTIHOP
	case CE_EMULTIHOP: return EMULTIHOP;
#endif /* !EMULTIHOP */
#ifdef EDOTDOT
	case CE_EDOTDOT: return EDOTDOT;
#endif /* !EDOTDOT */
#ifdef EBADMSG
	case CE_EBADMSG: return EBADMSG;
#endif /* !EBADMSG */
#ifdef EOVERFLOW
	case CE_EOVERFLOW: return EOVERFLOW;
#endif /* !EOVERFLOW */
#ifdef ENOTUNIQ
	case CE_ENOTUNIQ: return ENOTUNIQ;
#endif /* !ENOTUNIQ */
#ifdef EBADFD
	case CE_EBADFD: return EBADFD;
#endif /* !EBADFD */
#ifdef EREMCHG
	case CE_EREMCHG: return EREMCHG;
#endif /* !EREMCHG */
#ifdef ELIBACC
	case CE_ELIBACC: return ELIBACC;
#endif /* !ELIBACC */
#ifdef ELIBBAD
	case CE_ELIBBAD: return ELIBBAD;
#endif /* !ELIBBAD */
#ifdef ELIBSCN
	case CE_ELIBSCN: return ELIBSCN;
#endif /* !ELIBSCN */
#ifdef ELIBMAX
	case CE_ELIBMAX: return ELIBMAX;
#endif /* !ELIBMAX */
#ifdef ELIBEXEC
	case CE_ELIBEXEC: return ELIBEXEC;
#endif /* !ELIBEXEC */
#ifdef EILSEQ
	case CE_EILSEQ: return EILSEQ;
#endif /* !EILSEQ */
#ifdef ERESTART
	case CE_ERESTART: return ERESTART;
#endif /* !ERESTART */
#ifdef ESTRPIPE
	case CE_ESTRPIPE: return ESTRPIPE;
#endif /* !ESTRPIPE */
#ifdef EUSERS
	case CE_EUSERS: return EUSERS;
#endif /* !EUSERS */
#ifdef ENOTSOCK
	case CE_ENOTSOCK: return ENOTSOCK;
#endif /* !ENOTSOCK */
#ifdef EDESTADDRREQ
	case CE_EDESTADDRREQ: return EDESTADDRREQ;
#endif /* !EDESTADDRREQ */
#ifdef EMSGSIZE
	case CE_EMSGSIZE: return EMSGSIZE;
#endif /* !EMSGSIZE */
#ifdef EPROTOTYPE
	case CE_EPROTOTYPE: return EPROTOTYPE;
#endif /* !EPROTOTYPE */
#ifdef ENOPROTOOPT
	case CE_ENOPROTOOPT: return ENOPROTOOPT;
#endif /* !ENOPROTOOPT */
#ifdef EPROTONOSUPPORT
	case CE_EPROTONOSUPPORT: return EPROTONOSUPPORT;
#endif /* !EPROTONOSUPPORT */
#ifdef ESOCKTNOSUPPORT
	case CE_ESOCKTNOSUPPORT: return ESOCKTNOSUPPORT;
#endif /* !ESOCKTNOSUPPORT */
#ifdef ENOTSUP
	case CE_ENOTSUP: return ENOTSUP;
#endif /* !ENOTSUP */
#ifdef EPFNOSUPPORT
	case CE_EPFNOSUPPORT: return EPFNOSUPPORT;
#endif /* !EPFNOSUPPORT */
#ifdef EAFNOSUPPORT
	case CE_EAFNOSUPPORT: return EAFNOSUPPORT;
#endif /* !EAFNOSUPPORT */
#ifdef EADDRINUSE
	case CE_EADDRINUSE: return EADDRINUSE;
#endif /* !EADDRINUSE */
#ifdef EADDRNOTAVAIL
	case CE_EADDRNOTAVAIL: return EADDRNOTAVAIL;
#endif /* !EADDRNOTAVAIL */
#ifdef ENETDOWN
	case CE_ENETDOWN: return ENETDOWN;
#endif /* !ENETDOWN */
#ifdef ENETUNREACH
	case CE_ENETUNREACH: return ENETUNREACH;
#endif /* !ENETUNREACH */
#ifdef ENETRESET
	case CE_ENETRESET: return ENETRESET;
#endif /* !ENETRESET */
#ifdef ECONNABORTED
	case CE_ECONNABORTED: return ECONNABORTED;
#endif /* !ECONNABORTED */
#ifdef ECONNRESET
	case CE_ECONNRESET: return ECONNRESET;
#endif /* !ECONNRESET */
#ifdef ENOBUFS
	case CE_ENOBUFS: return ENOBUFS;
#endif /* !ENOBUFS */
#ifdef EISCONN
	case CE_EISCONN: return EISCONN;
#endif /* !EISCONN */
#ifdef ENOTCONN
	case CE_ENOTCONN: return ENOTCONN;
#endif /* !ENOTCONN */
#ifdef ESHUTDOWN
	case CE_ESHUTDOWN: return ESHUTDOWN;
#endif /* !ESHUTDOWN */
#ifdef ETOOMANYREFS
	case CE_ETOOMANYREFS: return ETOOMANYREFS;
#endif /* !ETOOMANYREFS */
#ifdef ETIMEDOUT
	case CE_ETIMEDOUT: return ETIMEDOUT;
#endif /* !ETIMEDOUT */
#ifdef ECONNREFUSED
	case CE_ECONNREFUSED: return ECONNREFUSED;
#endif /* !ECONNREFUSED */
#ifdef EHOSTDOWN
	case CE_EHOSTDOWN: return EHOSTDOWN;
#endif /* !EHOSTDOWN */
#ifdef EHOSTUNREACH
	case CE_EHOSTUNREACH: return EHOSTUNREACH;
#endif /* !EHOSTUNREACH */
#ifdef EALREADY
	case CE_EALREADY: return EALREADY;
#endif /* !EALREADY */
#ifdef EINPROGRESS
	case CE_EINPROGRESS: return EINPROGRESS;
#endif /* !EINPROGRESS */
#ifdef ESTALE
	case CE_ESTALE: return ESTALE;
#endif /* !ESTALE */
#ifdef EUCLEAN
	case CE_EUCLEAN: return EUCLEAN;
#endif /* !EUCLEAN */
#ifdef ENOTNAM
	case CE_ENOTNAM: return ENOTNAM;
#endif /* !ENOTNAM */
#ifdef ENAVAIL
	case CE_ENAVAIL: return ENAVAIL;
#endif /* !ENAVAIL */
#ifdef EISNAM
	case CE_EISNAM: return EISNAM;
#endif /* !EISNAM */
#ifdef EREMOTEIO
	case CE_EREMOTEIO: return EREMOTEIO;
#endif /* !EREMOTEIO */
#ifdef EDQUOT
	case CE_EDQUOT: return EDQUOT;
#endif /* !EDQUOT */
#ifdef ENOMEDIUM
	case CE_ENOMEDIUM: return ENOMEDIUM;
#endif /* !ENOMEDIUM */
#ifdef EMEDIUMTYPE
	case CE_EMEDIUMTYPE: return EMEDIUMTYPE;
#endif /* !EMEDIUMTYPE */
#ifdef ECANCELED
	case CE_ECANCELED: return ECANCELED;
#endif /* !ECANCELED */
#ifdef ENOKEY
	case CE_ENOKEY: return ENOKEY;
#endif /* !ENOKEY */
#ifdef EKEYEXPIRED
	case CE_EKEYEXPIRED: return EKEYEXPIRED;
#endif /* !EKEYEXPIRED */
#ifdef EKEYREVOKED
	case CE_EKEYREVOKED: return EKEYREVOKED;
#endif /* !EKEYREVOKED */
#ifdef EKEYREJECTED
	case CE_EKEYREJECTED: return EKEYREJECTED;
#endif /* !EKEYREJECTED */
#ifdef EOWNERDEAD
	case CE_EOWNERDEAD: return EOWNERDEAD;
#endif /* !EOWNERDEAD */
#ifdef ENOTRECOVERABLE
	case CE_ENOTRECOVERABLE: return ENOTRECOVERABLE;
#endif /* !ENOTRECOVERABLE */
#ifdef ERFKILL
	case CE_ERFKILL: return ERFKILL;
#endif /* !ERFKILL */
#ifdef EHWPOISON
	case CE_EHWPOISON: return EHWPOISON;
#endif /* !EHWPOISON */
	}
}
