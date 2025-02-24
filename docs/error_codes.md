# Error Codes

Error codes are defined at [`canvas/core/error.h`](@ref error.h)

Descriptions for each of the error codes can be retived with the [`ce_errstr`](@ref ce_errstr) function.
[`ce_success`](@ref ce_success) and [`ce_failure`](@ref ce_failure) can be used to check for success codes and error codes.

## Success Codes

| Value    | Meaning  |
| -------- | -------- |
| `CE_EOK` | No error |

## Error Codes

| Value                 | Meaning                                            |
| --------------------- | -------------------------------------------------- |
| `CE_EUNKNOWN        ` | Unknown/unspecified error                          |
| `CE_EPERM           ` | Operation not permitted                            |
| `CE_ENOENT          ` | No such file or directory                          |
| `CE_ESRCH           ` | No such process                                    |
| `CE_EINTR           ` | Interrupted system call                            |
| `CE_EIO             ` | Input/output error                                 |
| `CE_ENXIO           ` | No such device or address                          |
| `CE_E2BIG           ` | Argument list too long                             |
| `CE_ENOEXEC         ` | Exec format error                                  |
| `CE_EBADF           ` | Bad file descriptor                                |
| `CE_ECHILD          ` | No child processes                                 |
| `CE_EAGAIN          ` | Resource temporarily unavailable                   |
| `CE_ENOMEM          ` | Cannot allocate memory                             |
| `CE_EACCES          ` | Permission denied                                  |
| `CE_EFAULT          ` | Bad address                                        |
| `CE_ENOTBLK         ` | Block device required                              |
| `CE_EBUSY           ` | Device or resource busy                            |
| `CE_EEXIST          ` | File exists                                        |
| `CE_EXDEV           ` | Invalid cross-device link                          |
| `CE_ENODEV          ` | No such device                                     |
| `CE_ENOTDIR         ` | Not a directory                                    |
| `CE_EISDIR          ` | Is a directory                                     |
| `CE_EINVAL          ` | Invalid argument                                   |
| `CE_ENFILE          ` | Too many open files in system                      |
| `CE_EMFILE          ` | Too many open files                                |
| `CE_ENOTTY          ` | Inappropriate ioctl for device                     |
| `CE_ETXTBSY         ` | Text file busy                                     |
| `CE_EFBIG           ` | File too large                                     |
| `CE_ENOSPC          ` | No space left on device                            |
| `CE_ESPIPE          ` | Illegal seek                                       |
| `CE_EROFS           ` | Read-only file system                              |
| `CE_EMLINK          ` | Too many links                                     |
| `CE_EPIPE           ` | Broken pipe                                        |
| `CE_EDOM            ` | Numerical argument out of domain                   |
| `CE_ERANGE          ` | Numerical result out of range                      |
| `CE_EDEADLOCK       ` | Resource deadlock avoided                          |
| `CE_ENAMETOOLONG    ` | File name too long                                 |
| `CE_ENOLCK          ` | No locks available                                 |
| `CE_ENOSYS          ` | Function not implemented                           |
| `CE_ENOTEMPTY       ` | Directory not empty                                |
| `CE_ELOOP           ` | Too many levels of symbolic links                  |
| `CE_ENOMSG          ` | No message of desired type                         |
| `CE_EIDRM           ` | Identifier removed                                 |
| `CE_ECHRNG          ` | Channel number out of range                        |
| `CE_EL2NSYNC        ` | Level 2 not synchronized                           |
| `CE_EL3HLT          ` | Level 3 halted                                     |
| `CE_EL3RST          ` | Level 3 reset                                      |
| `CE_ELNRNG          ` | Link number out of range                           |
| `CE_EUNATCH         ` | Protocol driver not attached                       |
| `CE_ENOCSI          ` | No CSI structure available                         |
| `CE_EL2HLT          ` | Level 2 halted                                     |
| `CE_EBADE           ` | Invalid exchange                                   |
| `CE_EBADR           ` | Invalid request descriptor                         |
| `CE_EXFULL          ` | Exchange full                                      |
| `CE_ENOANO          ` | No anode                                           |
| `CE_EBADRQC         ` | Invalid request code                               |
| `CE_EBADSLT         ` | Invalid slot                                       |
| `CE_EBFONT          ` | Bad font file format                               |
| `CE_ENOSTR          ` | Device not a stream                                |
| `CE_ENODATA         ` | No data available                                  |
| `CE_ETIME           ` | Timer expired                                      |
| `CE_ENOSR           ` | Out of streams resources                           |
| `CE_ENONET          ` | Machine is not on the network                      |
| `CE_ENOPKG          ` | Package not installed                              |
| `CE_EREMOTE         ` | Object is remote                                   |
| `CE_ENOLINK         ` | Link has been severed                              |
| `CE_EADV            ` | Advertise error                                    |
| `CE_ESRMNT          ` | Srmount error                                      |
| `CE_ECOMM           ` | Communication error on send                        |
| `CE_EPROTO          ` | Protocol error                                     |
| `CE_EMULTIHOP       ` | Multihop attempted                                 |
| `CE_EDOTDOT         ` | RFS specific error                                 |
| `CE_EBADMSG         ` | Bad message                                        |
| `CE_EOVERFLOW       ` | Value too large for defined data type              |
| `CE_ENOTUNIQ        ` | Name not unique on network                         |
| `CE_EBADFD          ` | File descriptor in bad state                       |
| `CE_EREMCHG         ` | Remote address changed                             |
| `CE_ELIBACC         ` | Can not access a needed shared library             |
| `CE_ELIBBAD         ` | Accessing a corrupted shared library               |
| `CE_ELIBSCN         ` | .lib section in a.out corrupted                    |
| `CE_ELIBMAX         ` | Attempting to link in too many shared libraries    |
| `CE_ELIBEXEC        ` | Cannot exec a shared library directly              |
| `CE_EILSEQ          ` | Invalid or incomplete multibyte or wide character  |
| `CE_ERESTART        ` | Interrupted system call should be restarted        |
| `CE_ESTRPIPE        ` | Streams pipe error                                 |
| `CE_EUSERS          ` | Too many users                                     |
| `CE_ENOTSOCK        ` | Socket operation on non-socket                     |
| `CE_EDESTADDRREQ    ` | Destination address required                       |
| `CE_EMSGSIZE        ` | Message too long                                   |
| `CE_EPROTOTYPE      ` | Protocol wrong type for socket                     |
| `CE_ENOPROTOOPT     ` | Protocol not available                             |
| `CE_EPROTONOSUPPORT ` | Protocol not supported                             |
| `CE_ESOCKTNOSUPPORT ` | Socket type not supported                          |
| `CE_ENOTSUP         ` | Operation not supported                            |
| `CE_EPFNOSUPPORT    ` | Protocol family not supported                      |
| `CE_EAFNOSUPPORT    ` | Address family not supported by protocol           |
| `CE_EADDRINUSE      ` | Address already in use                             |
| `CE_EADDRNOTAVAIL   ` | Cannot assign requested address                    |
| `CE_ENETDOWN        ` | Network is down                                    |
| `CE_ENETUNREACH     ` | Network is unreachable                             |
| `CE_ENETRESET       ` | Network dropped connection on reset                |
| `CE_ECONNABORTED    ` | Software caused connection abort                   |
| `CE_ECONNRESET      ` | Connection reset by peer                           |
| `CE_ENOBUFS         ` | No buffer space available                          |
| `CE_EISCONN         ` | Transport endpoint is already connected            |
| `CE_ENOTCONN        ` | Transport endpoint is not connected                |
| `CE_ESHUTDOWN       ` | Cannot send after transport endpoint shutdown      |
| `CE_ETOOMANYREFS    ` | Too many references: cannot splice                 |
| `CE_ETIMEDOUT       ` | Connection timed out                               |
| `CE_ECONNREFUSED    ` | Connection refused                                 |
| `CE_EHOSTDOWN       ` | Host is down                                       |
| `CE_EHOSTUNREACH    ` | No route to host                                   |
| `CE_EALREADY        ` | Operation already in progress                      |
| `CE_EINPROGRESS     ` | Operation now in progress                          |
| `CE_ESTALE          ` | Stale file handle                                  |
| `CE_EUCLEAN         ` | Structure needs cleaning                           |
| `CE_ENOTNAM         ` | Not a XENIX named type file                        |
| `CE_ENAVAIL         ` | No XENIX semaphores available                      |
| `CE_EISNAM          ` | Is a named type file                               |
| `CE_EREMOTEIO       ` | Remote I/O error                                   |
| `CE_EDQUOT          ` | Disk quota exceeded                                |
| `CE_ENOMEDIUM       ` | No medium found                                    |
| `CE_EMEDIUMTYPE     ` | Wrong medium type                                  |
| `CE_ECANCELED       ` | Operation canceled                                 |
| `CE_ENOKEY          ` | Required key not available                         |
| `CE_EKEYEXPIRED     ` | Key has expired                                    |
| `CE_EKEYREVOKED     ` | Key has been revoked                               |
| `CE_EKEYREJECTED    ` | Key was rejected by service                        |
| `CE_EOWNERDEAD      ` | Owner died                                         |
| `CE_ENOTRECOVERABLE ` | State not recoverable                              |
| `CE_ERFKILL         ` | Operation not possible due to RF-kill              |
| `CE_EHWPOISON       ` | Memory page has hardware error                     |
| `CE_EINIT           ` | Initialization failed                              |
| `CE_EFAIL           ` | Operation failed                                   |
| `CE_EDRIVER         ` | Incompatible driver                                |
| `CE_EOBJECTS        ` | Too many objects                                   |
| `CE_EFRAG           ` | Data fragmentation                                 |
| `CE_EFORMAT         ` | Data format incompatible                           |
| `CE_ELOST           ` | Resource was lost                                  |
| `CE_EVKLAYER        ` | Vulkan layer cannot be found                       |
| `CE_EVKEXT          ` | Vulkan extension cannot be found                   |
| `CE_EVKFEAT         ` | Vulkan feature cannot be found                     |
| `CE_EVKFORMAT       ` | Vulkan format not supported by device              |
| `CE_EVKSURFACE      ` | Vulkan surface was lost                            |

<!--
/** @brief Undefined error                                    */ #define 0xFFFF
/** @brief Unknown/unspecified error                          */ #define 0x7FFF
/** @brief Operation not permitted                            */ #define 0x0001
/** @brief No such file or directory                          */ #define 0x0002
/** @brief No such process                                    */ #define 0x0003
/** @brief Interrupted system call                            */ #define 0x0004
/** @brief Input/output error                                 */ #define 0x0005
/** @brief No such device or address                          */ #define 0x0006
/** @brief Argument list too long                             */ #define 0x0007
/** @brief Exec format error                                  */ #define 0x0008
/** @brief Bad file descriptor                                */ #define 0x0009
/** @brief No child processes                                 */ #define 0x000A
/** @brief Resource temporarily unavailable                   */ #define 0x000B
/** @brief Cannot allocate memory                             */ #define 0x000C
/** @brief Permission denied                                  */ #define 0x000D
/** @brief Bad address                                        */ #define 0x000E
/** @brief Block device required                              */ #define 0x000F
/** @brief Device or resource busy                            */ #define 0x0010
/** @brief File exists                                        */ #define 0x0011
/** @brief Invalid cross-device link                          */ #define 0x0012
/** @brief No such device                                     */ #define 0x0013
/** @brief Not a directory                                    */ #define 0x0014
/** @brief Is a directory                                     */ #define 0x0015
/** @brief Invalid argument                                   */ #define 0x0016
/** @brief Too many open files in system                      */ #define 0x0017
/** @brief Too many open files                                */ #define 0x0018
/** @brief Inappropriate ioctl for device                     */ #define 0x0019
/** @brief Text file busy                                     */ #define 0x001A
/** @brief File too large                                     */ #define 0x001B
/** @brief No space left on device                            */ #define 0x001C
/** @brief Illegal seek                                       */ #define 0x001D
/** @brief Read-only file system                              */ #define 0x001E
/** @brief Too many links                                     */ #define 0x001F
/** @brief Broken pipe                                        */ #define 0x0020
/** @brief Numerical argument out of domain                   */ #define 0x0021
/** @brief Numerical result out of range                      */ #define 0x0022
/** @brief Resource deadlock avoided                          */ #define 0x0023
/** @brief File name too long                                 */ #define 0x0024
/** @brief No locks available                                 */ #define 0x0025
/** @brief Function not implemented                           */ #define 0x0026
/** @brief Directory not empty                                */ #define 0x0027
/** @brief Too many levels of symbolic links                  */ #define 0x0028
/** @brief No message of desired type                         */ #define 0x002A
/** @brief Identifier removed                                 */ #define 0x002B
/** @brief Channel number out of range                        */ #define 0x002C
/** @brief Level 2 not synchronized                           */ #define 0x002D
/** @brief Level 3 halted                                     */ #define 0x002E
/** @brief Level 3 reset                                      */ #define 0x002F
/** @brief Link number out of range                           */ #define 0x0030
/** @brief Protocol driver not attached                       */ #define 0x0031
/** @brief No CSI structure available                         */ #define 0x0032
/** @brief Level 2 halted                                     */ #define 0x0033
/** @brief Invalid exchange                                   */ #define 0x0034
/** @brief Invalid request descriptor                         */ #define 0x0035
/** @brief Exchange full                                      */ #define 0x0036
/** @brief No anode                                           */ #define 0x0037
/** @brief Invalid request code                               */ #define 0x0038
/** @brief Invalid slot                                       */ #define 0x0039
/** @brief Bad font file format                               */ #define 0x003B
/** @brief Device not a stream                                */ #define 0x003C
/** @brief No data available                                  */ #define 0x003D
/** @brief Timer expired                                      */ #define 0x003E
/** @brief Out of streams resources                           */ #define 0x003F
/** @brief Machine is not on the network                      */ #define 0x0040
/** @brief Package not installed                              */ #define 0x0041
/** @brief Object is remote                                   */ #define 0x0042
/** @brief Link has been severed                              */ #define 0x0043
/** @brief Advertise error                                    */ #define 0x0044
/** @brief Srmount error                                      */ #define 0x0045
/** @brief Communication error on send                        */ #define 0x0046
/** @brief Protocol error                                     */ #define 0x0047
/** @brief Multihop attempted                                 */ #define 0x0048
/** @brief RFS specific error                                 */ #define 0x0049
/** @brief Bad message                                        */ #define 0x004A
/** @brief Value too large for defined data type              */ #define 0x004B
/** @brief Name not unique on network                         */ #define 0x004C
/** @brief File descriptor in bad state                       */ #define 0x004D
/** @brief Remote address changed                             */ #define 0x004E
/** @brief Can not access a needed shared library             */ #define 0x004F
/** @brief Accessing a corrupted shared library               */ #define 0x0050
/** @brief .lib section in a.out corrupted                    */ #define 0x0051
/** @brief Attempting to link in too many shared libraries    */ #define 0x0052
/** @brief Cannot exec a shared library directly              */ #define 0x0053
/** @brief Invalid or incomplete multibyte or wide character  */ #define 0x0054
/** @brief Interrupted system call should be restarted        */ #define 0x0055
/** @brief Streams pipe error                                 */ #define 0x0056
/** @brief Too many users                                     */ #define 0x0057
/** @brief Socket operation on non-socket                     */ #define 0x0058
/** @brief Destination address required                       */ #define 0x0059
/** @brief Message too long                                   */ #define 0x005A
/** @brief Protocol wrong type for socket                     */ #define 0x005B
/** @brief Protocol not available                             */ #define 0x005C
/** @brief Protocol not supported                             */ #define 0x005D
/** @brief Socket type not supported                          */ #define 0x005E
/** @brief Operation not supported                            */ #define 0x005F
/** @brief Protocol family not supported                      */ #define 0x0060
/** @brief Address family not supported by protocol           */ #define 0x0061
/** @brief Address already in use                             */ #define 0x0062
/** @brief Cannot assign requested address                    */ #define 0x0063
/** @brief Network is down                                    */ #define 0x0064
/** @brief Network is unreachable                             */ #define 0x0065
/** @brief Network dropped connection on reset                */ #define 0x0066
/** @brief Software caused connection abort                   */ #define 0x0067
/** @brief Connection reset by peer                           */ #define 0x0068
/** @brief No buffer space available                          */ #define 0x0069
/** @brief Transport endpoint is already connected            */ #define 0x006A
/** @brief Transport endpoint is not connected                */ #define 0x006B
/** @brief Cannot send after transport endpoint shutdown      */ #define 0x006C
/** @brief Too many references: cannot splice                 */ #define 0x006D
/** @brief Connection timed out                               */ #define 0x006E
/** @brief Connection refused                                 */ #define 0x006F
/** @brief Host is down                                       */ #define 0x0070
/** @brief No route to host                                   */ #define 0x0071
/** @brief Operation already in progress                      */ #define 0x0072
/** @brief Operation now in progress                          */ #define 0x0073
/** @brief Stale file handle                                  */ #define 0x0074
/** @brief Structure needs cleaning                           */ #define 0x0075
/** @brief Not a XENIX named type file                        */ #define 0x0076
/** @brief No XENIX semaphores available                      */ #define 0x0077
/** @brief Is a named type file                               */ #define 0x0078
/** @brief Remote I/O error                                   */ #define 0x0079
/** @brief Disk quota exceeded                                */ #define 0x007A
/** @brief No medium found                                    */ #define 0x007B
/** @brief Wrong medium type                                  */ #define 0x007C
/** @brief Operation canceled                                 */ #define 0x007D
/** @brief Required key not available                         */ #define 0x007E
/** @brief Key has expired                                    */ #define 0x007F
/** @brief Key has been revoked                               */ #define 0x0080
/** @brief Key was rejected by service                        */ #define 0x0081
/** @brief Owner died                                         */ #define 0x0082
/** @brief State not recoverable                              */ #define 0x0083
/** @brief Operation not possible due to RF-kill              */ #define 0x0084
/** @brief Memory page has hardware error                     */ #define 0x0085
/** @brief Initialization failed                              */ #define 0x7000
/** @brief Operation failed                                   */ #define 0x7001
/** @brief Incompatible driver                                */ #define 0x7002
/** @brief Too many objects                                   */ #define 0x7003
/** @brief Data fragmentation                                 */ #define 0x7004
/** @brief Data format incompatible                           */ #define 0x7005
/** @brief Resource was lost                                  */ #define 0x7006
/** @brief Vulkan layer cannot be found                       */ #define 0x7100
/** @brief Vulkan extension cannot be found                   */ #define 0x7101
/** @brief Vulkan feature cannot be found                     */ #define 0x7102
/** @brief Vulkan format not supported by device              */ #define 0x7103
/** @brief Vulkan surface was lost                            */ #define 0x7104
-->
