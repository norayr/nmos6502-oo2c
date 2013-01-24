/* lib/__config.h.  Generated automatically by configure.  */
/* lib/__config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define if you have alloca, as a function or macro.  */
//#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
//#define HAVE_ALLOCA_H 1

/* Define if your struct stat has st_blksize.  */
#define HAVE_ST_BLKSIZE 1

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
 STACK_DIRECTION > 0 => grows toward higher addresses
 STACK_DIRECTION < 0 => grows toward lower addresses
 STACK_DIRECTION = 0 => direction of growth unknown
 */
/* #undef STACK_DIRECTION */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if Boehm's conservative garbage collector is present.  Do not use
   this in a module, rather test against USE_GC.  */
#define HAVE_GC 0

/* Define to type of local size_t.  */
#define LOCAL_SIZE_T unsigned

/* Define to type of 64 bit int, or to some int type if it does not exist.  */
#define LOCAL_INT64_T long long int

/* Define to the size of the type jmp_buf. */
#define SIZEOF_JMP_BUF 156

/* Define if your struct stat has st_mtime_usec.  */
/* #undef HAVE_ST_MTIME_USEC */

/* Define target byte order.  */
#define OOC_TARGET_BYTE_ORDER 1234

/* The number of bytes in a long int.  */
#define SIZEOF_LONG_INT 4

/* The number of bytes in a long long int.  */
#define SIZEOF_LONG_LONG_INT 8

/* Define if you have the atexit function.  */
#define HAVE_ATEXIT 1

/* Define if you have the backtrace_symbols function.  */
#define HAVE_BACKTRACE_SYMBOLS 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the raise function.  */
#define HAVE_RAISE 1

/* Define if you have the settimeofday function.  */
#define HAVE_SETTIMEOFDAY 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the utimes function.  */
#define HAVE_UTIMES 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <io.h> header file.  */
/* #undef HAVE_IO_H */

/* Define if you have the <pwd.h> header file.  */
#define HAVE_PWD_H 1

/* Define if you have the <socket.h> header file.  */
/* #undef HAVE_SOCKET_H */

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <syslimits.h> header file.  */
/* #undef HAVE_SYSLIMITS_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <utime.h> header file.  */
#define HAVE_UTIME_H 1


/* unless USE_GC is already defined, set it to HAVE_GC */
#ifndef USE_GC
#  if HAVE_GC
#    define USE_GC 1
#  endif
#endif
