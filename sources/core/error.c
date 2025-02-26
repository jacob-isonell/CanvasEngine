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
	case CE_EOK              : return "No error";
	
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
	
	case CE_EINIT            : return "Initialization failed";
	case CE_EFAIL            : return "Operation failed";
	case CE_EDRIVER          : return "Incompatible driver";
	case CE_EOBJECTS         : return "Too many objects";
	case CE_EFRAG            : return "Data fragmentation";
	case CE_EFORMAT          : return "Data format incompatible";
	case CE_ELOST            : return "Resource was lost";
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
	case 0: return CE_EOK;
	default: return CE_EUNKNOWN;
#ifdef EPERM
	case EPERM: return CE_EPERM;
#endif /* !EPERM */
#ifdef ENOENT
	case ENOENT: return CE_ENOENT;
#endif /* !ENOENT */
#ifdef ESRCH
	case ESRCH: return CE_ESRCH;
#endif /* !ESRCH */
#ifdef EINTR
	case EINTR: return CE_EINTR;
#endif /* !EINTR */
#ifdef EIO
	case EIO: return CE_EIO;
#endif /* !EIO */
#ifdef ENXIO
	case ENXIO: return CE_ENXIO;
#endif /* !ENXIO */
#ifdef E2BIG
	case E2BIG: return CE_E2BIG;
#endif /* !E2BIG */
#ifdef ENOEXEC
	case ENOEXEC: return CE_ENOEXEC;
#endif /* !ENOEXEC */
#ifdef EBADF
	case EBADF: return CE_EBADF;
#endif /* !EBADF */
#ifdef ECHILD
	case ECHILD: return CE_ECHILD;
#endif /* !ECHILD */
#ifdef EAGAIN
	case EAGAIN: return CE_EAGAIN;
#endif /* !EAGAIN */
#ifdef ENOMEM
	case ENOMEM: return CE_ENOMEM;
#endif /* !ENOMEM */
#ifdef EACCES
	case EACCES: return CE_EACCES;
#endif /* !EACCES */
#ifdef EFAULT
	case EFAULT: return CE_EFAULT;
#endif /* !EFAULT */
#ifdef ENOTBLK
	case ENOTBLK: return CE_ENOTBLK;
#endif /* !ENOTBLK */
#ifdef EBUSY
	case EBUSY: return CE_EBUSY;
#endif /* !EBUSY */
#ifdef EEXIST
	case EEXIST: return CE_EEXIST;
#endif /* !EEXIST */
#ifdef EXDEV
	case EXDEV: return CE_EXDEV;
#endif /* !EXDEV */
#ifdef ENODEV
	case ENODEV: return CE_ENODEV;
#endif /* !ENODEV */
#ifdef ENOTDIR
	case ENOTDIR: return CE_ENOTDIR;
#endif /* !ENOTDIR */
#ifdef EISDIR
	case EISDIR: return CE_EISDIR;
#endif /* !EISDIR */
#ifdef EINVAL
	case EINVAL: return CE_EINVAL;
#endif /* !EINVAL */
#ifdef ENFILE
	case ENFILE: return CE_ENFILE;
#endif /* !ENFILE */
#ifdef EMFILE
	case EMFILE: return CE_EMFILE;
#endif /* !EMFILE */
#ifdef ENOTTY
	case ENOTTY: return CE_ENOTTY;
#endif /* !ENOTTY */
#ifdef ETXTBSY
	case ETXTBSY: return CE_ETXTBSY;
#endif /* !ETXTBSY */
#ifdef EFBIG
	case EFBIG: return CE_EFBIG;
#endif /* !EFBIG */
#ifdef ENOSPC
	case ENOSPC: return CE_ENOSPC;
#endif /* !ENOSPC */
#ifdef ESPIPE
	case ESPIPE: return CE_ESPIPE;
#endif /* !ESPIPE */
#ifdef EROFS
	case EROFS: return CE_EROFS;
#endif /* !EROFS */
#ifdef EMLINK
	case EMLINK: return CE_EMLINK;
#endif /* !EMLINK */
#ifdef EPIPE
	case EPIPE: return CE_EPIPE;
#endif /* !EPIPE */
#ifdef EDOM
	case EDOM: return CE_EDOM;
#endif /* !EDOM */
#ifdef ERANGE
	case ERANGE: return CE_ERANGE;
#endif /* !ERANGE */
#ifdef EDEADLOCK
	case EDEADLOCK: return CE_EDEADLOCK;
#endif /* !EDEADLOCK */
#ifdef ENAMETOOLONG
	case ENAMETOOLONG: return CE_ENAMETOOLONG;
#endif /* !ENAMETOOLONG */
#ifdef ENOLCK
	case ENOLCK: return CE_ENOLCK;
#endif /* !ENOLCK */
#ifdef ENOSYS
	case ENOSYS: return CE_ENOSYS;
#endif /* !ENOSYS */
#ifdef ENOTEMPTY
	case ENOTEMPTY: return CE_ENOTEMPTY;
#endif /* !ENOTEMPTY */
#ifdef ELOOP
	case ELOOP: return CE_ELOOP;
#endif /* !ELOOP */
#ifdef ENOMSG
	case ENOMSG: return CE_ENOMSG;
#endif /* !ENOMSG */
#ifdef EIDRM
	case EIDRM: return CE_EIDRM;
#endif /* !EIDRM */
#ifdef ECHRNG
	case ECHRNG: return CE_ECHRNG;
#endif /* !ECHRNG */
#ifdef EL2NSYNC
	case EL2NSYNC: return CE_EL2NSYNC;
#endif /* !EL2NSYNC */
#ifdef EL3HLT
	case EL3HLT: return CE_EL3HLT;
#endif /* !EL3HLT */
#ifdef EL3RST
	case EL3RST: return CE_EL3RST;
#endif /* !EL3RST */
#ifdef ELNRNG
	case ELNRNG: return CE_ELNRNG;
#endif /* !ELNRNG */
#ifdef EUNATCH
	case EUNATCH: return CE_EUNATCH;
#endif /* !EUNATCH */
#ifdef ENOCSI
	case ENOCSI: return CE_ENOCSI;
#endif /* !ENOCSI */
#ifdef EL2HLT
	case EL2HLT: return CE_EL2HLT;
#endif /* !EL2HLT */
#ifdef EBADE
	case EBADE: return CE_EBADE;
#endif /* !EBADE */
#ifdef EBADR
	case EBADR: return CE_EBADR;
#endif /* !EBADR */
#ifdef EXFULL
	case EXFULL: return CE_EXFULL;
#endif /* !EXFULL */
#ifdef ENOANO
	case ENOANO: return CE_ENOANO;
#endif /* !ENOANO */
#ifdef EBADRQC
	case EBADRQC: return CE_EBADRQC;
#endif /* !EBADRQC */
#ifdef EBADSLT
	case EBADSLT: return CE_EBADSLT;
#endif /* !EBADSLT */
#ifdef EBFONT
	case EBFONT: return CE_EBFONT;
#endif /* !EBFONT */
#ifdef ENOSTR
	case ENOSTR: return CE_ENOSTR;
#endif /* !ENOSTR */
#ifdef ENODATA
	case ENODATA: return CE_ENODATA;
#endif /* !ENODATA */
#ifdef ETIME
	case ETIME: return CE_ETIME;
#endif /* !ETIME */
#ifdef ENOSR
	case ENOSR: return CE_ENOSR;
#endif /* !ENOSR */
#ifdef ENONET
	case ENONET: return CE_ENONET;
#endif /* !ENONET */
#ifdef ENOPKG
	case ENOPKG: return CE_ENOPKG;
#endif /* !ENOPKG */
#ifdef EREMOTE
	case EREMOTE: return CE_EREMOTE;
#endif /* !EREMOTE */
#ifdef ENOLINK
	case ENOLINK: return CE_ENOLINK;
#endif /* !ENOLINK */
#ifdef EADV
	case EADV: return CE_EADV;
#endif /* !EADV */
#ifdef ESRMNT
	case ESRMNT: return CE_ESRMNT;
#endif /* !ESRMNT */
#ifdef ECOMM
	case ECOMM: return CE_ECOMM;
#endif /* !ECOMM */
#ifdef EPROTO
	case EPROTO: return CE_EPROTO;
#endif /* !EPROTO */
#ifdef EMULTIHOP
	case EMULTIHOP: return CE_EMULTIHOP;
#endif /* !EMULTIHOP */
#ifdef EDOTDOT
	case EDOTDOT: return CE_EDOTDOT;
#endif /* !EDOTDOT */
#ifdef EBADMSG
	case EBADMSG: return CE_EBADMSG;
#endif /* !EBADMSG */
#ifdef EOVERFLOW
	case EOVERFLOW: return CE_EOVERFLOW;
#endif /* !EOVERFLOW */
#ifdef ENOTUNIQ
	case ENOTUNIQ: return CE_ENOTUNIQ;
#endif /* !ENOTUNIQ */
#ifdef EBADFD
	case EBADFD: return CE_EBADFD;
#endif /* !EBADFD */
#ifdef EREMCHG
	case EREMCHG: return CE_EREMCHG;
#endif /* !EREMCHG */
#ifdef ELIBACC
	case ELIBACC: return CE_ELIBACC;
#endif /* !ELIBACC */
#ifdef ELIBBAD
	case ELIBBAD: return CE_ELIBBAD;
#endif /* !ELIBBAD */
#ifdef ELIBSCN
	case ELIBSCN: return CE_ELIBSCN;
#endif /* !ELIBSCN */
#ifdef ELIBMAX
	case ELIBMAX: return CE_ELIBMAX;
#endif /* !ELIBMAX */
#ifdef ELIBEXEC
	case ELIBEXEC: return CE_ELIBEXEC;
#endif /* !ELIBEXEC */
#ifdef EILSEQ
	case EILSEQ: return CE_EILSEQ;
#endif /* !EILSEQ */
#ifdef ERESTART
	case ERESTART: return CE_ERESTART;
#endif /* !ERESTART */
#ifdef ESTRPIPE
	case ESTRPIPE: return CE_ESTRPIPE;
#endif /* !ESTRPIPE */
#ifdef EUSERS
	case EUSERS: return CE_EUSERS;
#endif /* !EUSERS */
#ifdef ENOTSOCK
	case ENOTSOCK: return CE_ENOTSOCK;
#endif /* !ENOTSOCK */
#ifdef EDESTADDRREQ
	case EDESTADDRREQ: return CE_EDESTADDRREQ;
#endif /* !EDESTADDRREQ */
#ifdef EMSGSIZE
	case EMSGSIZE: return CE_EMSGSIZE;
#endif /* !EMSGSIZE */
#ifdef EPROTOTYPE
	case EPROTOTYPE: return CE_EPROTOTYPE;
#endif /* !EPROTOTYPE */
#ifdef ENOPROTOOPT
	case ENOPROTOOPT: return CE_ENOPROTOOPT;
#endif /* !ENOPROTOOPT */
#ifdef EPROTONOSUPPORT
	case EPROTONOSUPPORT: return CE_EPROTONOSUPPORT;
#endif /* !EPROTONOSUPPORT */
#ifdef ESOCKTNOSUPPORT
	case ESOCKTNOSUPPORT: return CE_ESOCKTNOSUPPORT;
#endif /* !ESOCKTNOSUPPORT */
#ifdef ENOTSUP
	case ENOTSUP: return CE_ENOTSUP;
#endif /* !ENOTSUP */
#ifdef EPFNOSUPPORT
	case EPFNOSUPPORT: return CE_EPFNOSUPPORT;
#endif /* !EPFNOSUPPORT */
#ifdef EAFNOSUPPORT
	case EAFNOSUPPORT: return CE_EAFNOSUPPORT;
#endif /* !EAFNOSUPPORT */
#ifdef EADDRINUSE
	case EADDRINUSE: return CE_EADDRINUSE;
#endif /* !EADDRINUSE */
#ifdef EADDRNOTAVAIL
	case EADDRNOTAVAIL: return CE_EADDRNOTAVAIL;
#endif /* !EADDRNOTAVAIL */
#ifdef ENETDOWN
	case ENETDOWN: return CE_ENETDOWN;
#endif /* !ENETDOWN */
#ifdef ENETUNREACH
	case ENETUNREACH: return CE_ENETUNREACH;
#endif /* !ENETUNREACH */
#ifdef ENETRESET
	case ENETRESET: return CE_ENETRESET;
#endif /* !ENETRESET */
#ifdef ECONNABORTED
	case ECONNABORTED: return CE_ECONNABORTED;
#endif /* !ECONNABORTED */
#ifdef ECONNRESET
	case ECONNRESET: return CE_ECONNRESET;
#endif /* !ECONNRESET */
#ifdef ENOBUFS
	case ENOBUFS: return CE_ENOBUFS;
#endif /* !ENOBUFS */
#ifdef EISCONN
	case EISCONN: return CE_EISCONN;
#endif /* !EISCONN */
#ifdef ENOTCONN
	case ENOTCONN: return CE_ENOTCONN;
#endif /* !ENOTCONN */
#ifdef ESHUTDOWN
	case ESHUTDOWN: return CE_ESHUTDOWN;
#endif /* !ESHUTDOWN */
#ifdef ETOOMANYREFS
	case ETOOMANYREFS: return CE_ETOOMANYREFS;
#endif /* !ETOOMANYREFS */
#ifdef ETIMEDOUT
	case ETIMEDOUT: return CE_ETIMEDOUT;
#endif /* !ETIMEDOUT */
#ifdef ECONNREFUSED
	case ECONNREFUSED: return CE_ECONNREFUSED;
#endif /* !ECONNREFUSED */
#ifdef EHOSTDOWN
	case EHOSTDOWN: return CE_EHOSTDOWN;
#endif /* !EHOSTDOWN */
#ifdef EHOSTUNREACH
	case EHOSTUNREACH: return CE_EHOSTUNREACH;
#endif /* !EHOSTUNREACH */
#ifdef EALREADY
	case EALREADY: return CE_EALREADY;
#endif /* !EALREADY */
#ifdef EINPROGRESS
	case EINPROGRESS: return CE_EINPROGRESS;
#endif /* !EINPROGRESS */
#ifdef ESTALE
	case ESTALE: return CE_ESTALE;
#endif /* !ESTALE */
#ifdef EUCLEAN
	case EUCLEAN: return CE_EUCLEAN;
#endif /* !EUCLEAN */
#ifdef ENOTNAM
	case ENOTNAM: return CE_ENOTNAM;
#endif /* !ENOTNAM */
#ifdef ENAVAIL
	case ENAVAIL: return CE_ENAVAIL;
#endif /* !ENAVAIL */
#ifdef EISNAM
	case EISNAM: return CE_EISNAM;
#endif /* !EISNAM */
#ifdef EREMOTEIO
	case EREMOTEIO: return CE_EREMOTEIO;
#endif /* !EREMOTEIO */
#ifdef EDQUOT
	case EDQUOT: return CE_EDQUOT;
#endif /* !EDQUOT */
#ifdef ENOMEDIUM
	case ENOMEDIUM: return CE_ENOMEDIUM;
#endif /* !ENOMEDIUM */
#ifdef EMEDIUMTYPE
	case EMEDIUMTYPE: return CE_EMEDIUMTYPE;
#endif /* !EMEDIUMTYPE */
#ifdef ECANCELED
	case ECANCELED: return CE_ECANCELED;
#endif /* !ECANCELED */
#ifdef ENOKEY
	case ENOKEY: return CE_ENOKEY;
#endif /* !ENOKEY */
#ifdef EKEYEXPIRED
	case EKEYEXPIRED: return CE_EKEYEXPIRED;
#endif /* !EKEYEXPIRED */
#ifdef EKEYREVOKED
	case EKEYREVOKED: return CE_EKEYREVOKED;
#endif /* !EKEYREVOKED */
#ifdef EKEYREJECTED
	case EKEYREJECTED: return CE_EKEYREJECTED;
#endif /* !EKEYREJECTED */
#ifdef EOWNERDEAD
	case EOWNERDEAD: return CE_EOWNERDEAD;
#endif /* !EOWNERDEAD */
#ifdef ENOTRECOVERABLE
	case ENOTRECOVERABLE: return CE_ENOTRECOVERABLE;
#endif /* !ENOTRECOVERABLE */
#ifdef ERFKILL
	case ERFKILL: return CE_ERFKILL;
#endif /* !ERFKILL */
#ifdef EHWPOISON
	case EHWPOISON: return CE_EHWPOISON;
#endif /* !EHWPOISON */
	}
}

ICE_API ce_err ierrno_cls(int in) {
	switch (in) {
	case 0: return CE_EOK;
	default: {
		const ce_err out = ierrno(in);
		errno = 0; // Clear error.
		return out;
	}
	}
}
