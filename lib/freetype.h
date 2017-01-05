typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef int wchar_t;
typedef long double max_align_t;





typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;







typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];


struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};

struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};

struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;





void *memchr(const void *__s, int __c, size_t __n);
int memcmp(const void *__s1, const void *__s2, size_t __n);
void *memcpy(void *__dst, const void *__src, size_t __n);
void *memmove(void *__dst, const void *__src, size_t __len);
void *memset(void *__b, int __c, size_t __len);
char *strcat(char *__s1, const char *__s2);
char *strchr(const char *__s, int __c);
int strcmp(const char *__s1, const char *__s2);
int strcoll(const char *__s1, const char *__s2);
char *strcpy(char *__dst, const char *__src);
size_t strcspn(const char *__s, const char *__charset);
char *strerror(int __errnum) __asm("_" "strerror" );
size_t strlen(const char *__s);
char *strncat(char *__s1, const char *__s2, size_t __n);
int strncmp(const char *__s1, const char *__s2, size_t __n);
char *strncpy(char *__dst, const char *__src, size_t __n);
char *strpbrk(const char *__s, const char *__charset);
char *strrchr(const char *__s, int __c);
size_t strspn(const char *__s, const char *__charset);
char *strstr(const char *__big, const char *__little);
char *strtok(char *__str, const char *__sep);
size_t strxfrm(char *__s1, const char *__s2, size_t __n);
char *strtok_r(char *__str, const char *__sep, char **__lasts);
int strerror_r(int __errnum, char *__strerrbuf, size_t __buflen);
char *strdup(const char *__s1);
void *memccpy(void *__dst, const void *__src, int __c, size_t __n);
char *stpcpy(char *__dst, const char *__src);
char *stpncpy(char *__dst, const char *__src, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strndup(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
size_t strnlen(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strsignal(int __sig);







typedef __darwin_size_t rsize_t;
typedef int errno_t;


errno_t memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n) __attribute__((availability(macosx,introduced=10.9)));







typedef __darwin_ssize_t ssize_t;


void *memmem(const void *__big, size_t __big_len, const void *__little, size_t __little_len) __attribute__((availability(macosx,introduced=10.7)));
void memset_pattern4(void *__b, const void *__pattern4, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern8(void *__b, const void *__pattern8, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern16(void *__b, const void *__pattern16, size_t __len) __attribute__((availability(macosx,introduced=10.5)));

char *strcasestr(const char *__big, const char *__little);
char *strnstr(const char *__big, const char *__little, size_t __len);
size_t strlcat(char *__dst, const char *__source, size_t __size);
size_t strlcpy(char *__dst, const char *__source, size_t __size);
void strmode(int __mode, char *__bp);
char *strsep(char **__stringp, const char *__delim);


void swab(const void * restrict, void * restrict, ssize_t);


__attribute__((availability(macosx,introduced=10.12.1))) __attribute__((availability(ios,introduced=10.1)))
__attribute__((availability(tvos,introduced=10.0.1))) __attribute__((availability(watchos,introduced=3.1)))

int timingsafe_bcmp(const void *__b1, const void *__b2, size_t __len);












int bcmp(const void *, const void *, size_t) ;
void bcopy(const void *, void *, size_t) ;
void bzero(void *, size_t) ;
char *index(const char *, int) ;
char *rindex(const char *, int) ;


int ffs(int);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);





int ffsl(long) __attribute__((availability(macosx,introduced=10.5)));
int ffsll(long long) __attribute__((availability(macosx,introduced=10.9)));
int fls(int) __attribute__((availability(macosx,introduced=10.5)));
int flsl(long) __attribute__((availability(macosx,introduced=10.5)));
int flsll(long long) __attribute__((availability(macosx,introduced=10.9)));



typedef __darwin_va_list va_list;

int renameat(int, const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));






int renamex_np(const char *, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int renameatx_np(int, const char *, int, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));

typedef __darwin_off_t fpos_t;
struct __sbuf {
 unsigned char *_base;
 int _size;
};


struct __sFILEX;
typedef struct __sFILE {
 unsigned char *_p;
 int _r;
 int _w;
 short _flags;
 short _file;
 struct __sbuf _bf;
 int _lbfsize;


 void *_cookie;
 int (* _Nullable _close)(void *);
 int (* _Nullable _read) (void *, char *, int);
 fpos_t (* _Nullable _seek) (void *, fpos_t, int);
 int (* _Nullable _write)(void *, const char *, int);


 struct __sbuf _ub;
 struct __sFILEX *_extra;
 int _ur;


 unsigned char _ubuf[3];
 unsigned char _nbuf[1];


 struct __sbuf _lb;


 int _blksize;
 fpos_t _offset;
} FILE;


extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * restrict, fpos_t *);
char *fgets(char * restrict, int, FILE *);



FILE *fopen(const char * restrict __filename, const char * restrict __mode) __asm("_" "fopen" );

int fprintf(FILE * restrict, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3)));
int fputc(int, FILE *);
int fputs(const char * restrict, FILE * restrict) __asm("_" "fputs" );
size_t fread(void * restrict __ptr, size_t __size, size_t __nitems, FILE * restrict __stream);
FILE *freopen(const char * restrict, const char * restrict,
                 FILE * restrict) __asm("_" "freopen" );
int fscanf(FILE * restrict, const char * restrict, ...) __attribute__((__format__ (__scanf__, 2, 3)));
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * restrict __ptr, size_t __size, size_t __nitems, FILE * restrict __stream) __asm("_" "fwrite" );
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *);
int printf(const char * restrict, ...) __attribute__((__format__ (__printf__, 1, 2)));
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename (const char *__old, const char *__new);
void rewind(FILE *);
int scanf(const char * restrict, ...) __attribute__((__format__ (__scanf__, 1, 2)));
void setbuf(FILE * restrict, char * restrict);
int setvbuf(FILE * restrict, char * restrict, int, size_t);
int sprintf(char * restrict, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((__availability__(swift, unavailable, message="Use snprintf instead.")));
int sscanf(const char * restrict, const char * restrict, ...) __attribute__((__format__ (__scanf__, 2, 3)));
FILE *tmpfile(void);

__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((deprecated("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tmpnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * restrict, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0)));
int vprintf(const char * restrict, va_list) __attribute__((__format__ (__printf__, 1, 0)));
int vsprintf(char * restrict, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((__availability__(swift, unavailable, message="Use vsnprintf instead.")));
char *ctermid(char *);





FILE *fdopen(int, const char *) __asm("_" "fdopen" );

int fileno(FILE *);
int pclose(FILE *) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));



FILE *popen(const char *, const char *) __asm("_" "popen" ) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));
int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int __swbuf(int, FILE *);
inline __attribute__ ((__always_inline__)) int __sputc(int _c, FILE *_p) {
 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf(_c, _p));
}
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);



int getw(FILE *);
int putw(int, FILE *);


__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((deprecated("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tempnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tempnam(const char *__dir, const char *__prefix) __asm("_" "tempnam" );
typedef __darwin_off_t off_t;


int fseeko(FILE * __stream, off_t __offset, int __whence);
off_t ftello(FILE * __stream);





int snprintf(char * restrict __str, size_t __size, const char * restrict __format, ...) __attribute__((__format__ (__printf__, 3, 4)));
int vfscanf(FILE * restrict __stream, const char * restrict __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int vscanf(const char * restrict __format, va_list) __attribute__((__format__ (__scanf__, 1, 0)));
int vsnprintf(char * restrict __str, size_t __size, const char * restrict __format, va_list) __attribute__((__format__ (__printf__, 3, 0)));
int vsscanf(const char * restrict __str, const char * restrict __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int dprintf(int, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((availability(macosx,introduced=10.7)));
int vdprintf(int, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getdelim(char ** restrict __linep, size_t * restrict __linecapp, int __delimiter, FILE * restrict __stream) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getline(char ** restrict __linep, size_t * restrict __linecapp, FILE * restrict __stream) __attribute__((availability(macosx,introduced=10.7)));
extern const int sys_nerr;
extern const char *const sys_errlist[];

int asprintf(char ** restrict, const char * restrict, ...) __attribute__((__format__ (__printf__, 2, 3)));
char *ctermid_r(char *);
char *fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int fpurge(FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);
int vasprintf(char ** restrict, const char * restrict, va_list) __attribute__((__format__ (__printf__, 2, 0)));
FILE *zopen(const char *, const char *, int);





FILE *funopen(const void *,
                 int (* _Nullable)(void *, char *, int),
                 int (* _Nullable)(void *, const char *, int),
                 fpos_t (* _Nullable)(void *, fpos_t, int),
                 int (* _Nullable)(void *));
extern int __sprintf_chk (char * restrict, int, size_t,
     const char * restrict, ...);
extern int __snprintf_chk (char * restrict, size_t, int, size_t,
      const char * restrict, ...);







extern int __vsprintf_chk (char * restrict, int, size_t,
      const char * restrict, va_list);







extern int __vsnprintf_chk (char * restrict, size_t, int, size_t,
       const char * restrict, va_list);
typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;






typedef __darwin_pid_t pid_t;
typedef __darwin_id_t id_t;








typedef int sig_atomic_t;
struct __darwin_i386_thread_state
{
    unsigned int __eax;
    unsigned int __ebx;
    unsigned int __ecx;
    unsigned int __edx;
    unsigned int __edi;
    unsigned int __esi;
    unsigned int __ebp;
    unsigned int __esp;
    unsigned int __ss;
    unsigned int __eflags;
    unsigned int __eip;
    unsigned int __cs;
    unsigned int __ds;
    unsigned int __es;
    unsigned int __fs;
    unsigned int __gs;
};
struct __darwin_fp_control
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
      :2,
    __pc :2,





    __rc :2,






             :1,
      :3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
struct __darwin_fp_status
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
    __stkflt :1,
    __errsumm :1,
    __c0 :1,
    __c1 :1,
    __c2 :1,
    __tos :3,
    __c3 :1,
    __busy :1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
struct __darwin_mmst_reg
{
 char __mmst_reg[10];
 char __mmst_rsrv[6];
};
struct __darwin_xmm_reg
{
 char __xmm_reg[16];
};
struct __darwin_i386_float_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
};


struct __darwin_i386_avx_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
};
struct __darwin_i386_exception_state
{
 __uint16_t __trapno;
 __uint16_t __cpu;
 __uint32_t __err;
 __uint32_t __faultvaddr;
};
struct __darwin_x86_debug_state32
{
 unsigned int __dr0;
 unsigned int __dr1;
 unsigned int __dr2;
 unsigned int __dr3;
 unsigned int __dr4;
 unsigned int __dr5;
 unsigned int __dr6;
 unsigned int __dr7;
};
struct __darwin_x86_thread_state64
{
 __uint64_t __rax;
 __uint64_t __rbx;
 __uint64_t __rcx;
 __uint64_t __rdx;
 __uint64_t __rdi;
 __uint64_t __rsi;
 __uint64_t __rbp;
 __uint64_t __rsp;
 __uint64_t __r8;
 __uint64_t __r9;
 __uint64_t __r10;
 __uint64_t __r11;
 __uint64_t __r12;
 __uint64_t __r13;
 __uint64_t __r14;
 __uint64_t __r15;
 __uint64_t __rip;
 __uint64_t __rflags;
 __uint64_t __cs;
 __uint64_t __fs;
 __uint64_t __gs;
};
struct __darwin_x86_float_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
};


struct __darwin_x86_avx_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
};
struct __darwin_x86_exception_state64
{
    __uint16_t __trapno;
    __uint16_t __cpu;
    __uint32_t __err;
    __uint64_t __faultvaddr;
};
struct __darwin_x86_debug_state64
{
 __uint64_t __dr0;
 __uint64_t __dr1;
 __uint64_t __dr2;
 __uint64_t __dr3;
 __uint64_t __dr4;
 __uint64_t __dr5;
 __uint64_t __dr6;
 __uint64_t __dr7;
};




struct __darwin_mcontext32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_float_state __fs;
};


struct __darwin_mcontext_avx32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx_state __fs;
};
struct __darwin_mcontext64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext_avx64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};
typedef struct __darwin_mcontext64 *mcontext_t;

typedef __darwin_pthread_attr_t pthread_attr_t;

struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;
struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;



};


typedef struct __darwin_ucontext ucontext_t;


typedef __darwin_sigset_t sigset_t;
typedef __darwin_uid_t uid_t;

union sigval {

 int sival_int;
 void *sival_ptr;
};





struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};


typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;
union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
         void *);
};


struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};




struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};
typedef void (*sig_t)(int);
struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};
struct sigstack {
 char *ss_sp;
 int ss_onstack;
};
void (*signal(int, void (*)(int)))(int);
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;






typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;



typedef long int intmax_t;
typedef long unsigned int uintmax_t;







struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};








typedef __uint64_t rlim_t;
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 long ru_maxrss;

 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;


};
typedef void *rusage_info_t;

struct rusage_info_v0 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
};

struct rusage_info_v1 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
};

struct rusage_info_v2 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
};

struct rusage_info_v3 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
};

typedef struct rusage_info_v3 rusage_info_current;
struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};
struct proc_rlimit_control_wakeupmon {
 uint32_t wm_flags;
 int32_t wm_rate;
};
int getpriority(int, id_t);

int getiopolicy_np(int, int) __attribute__((availability(macosx,introduced=10.5)));

int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);

int setiopolicy_np(int, int, int) __attribute__((availability(macosx,introduced=10.5)));

int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );
static inline
__uint16_t
_OSSwapInt16(
    __uint16_t _data
)
{
    return ((__uint16_t)((_data << 8) | (_data >> 8)));
}

static inline
__uint32_t
_OSSwapInt32(
    __uint32_t _data
)
{

    return __builtin_bswap32(_data);




}


static inline
__uint64_t
_OSSwapInt64(
    __uint64_t _data
)
{
    return __builtin_bswap64(_data);
}







union wait {
 int w_status;



 struct {

  unsigned int w_Termsig:7,
    w_Coredump:1,
    w_Retcode:8,
    w_Filler:16;







 } w_T;





 struct {

  unsigned int w_Stopval:8,
    w_Stopsig:8,
    w_Filler:16;






 } w_S;
};
pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );

int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );


pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);



void *alloca(size_t);







typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;



typedef struct {
 int quot;
 int rem;
} div_t;

typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef struct {
 long long quot;
 long long rem;
} lldiv_t;



extern int __mb_cur_max;
void abort(void) __attribute__((noreturn));
int abs(int) __attribute__((const));
int atexit(void (* _Nonnull)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);

long long
  atoll(const char *);

void *bsearch(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (* _Nonnull __compar)(const void *, const void *));
void *calloc(size_t __count, size_t __size) __attribute__((__warn_unused_result__));
div_t div(int, int) __attribute__((const));
void exit(int) __attribute__((noreturn));
void free(void *);
char *getenv(const char *);
long labs(long) __attribute__((const));
ldiv_t ldiv(long, long) __attribute__((const));

long long
  llabs(long long);
lldiv_t lldiv(long long, long long);

void *malloc(size_t __size) __attribute__((__warn_unused_result__));
int mblen(const char *__s, size_t __n);
size_t mbstowcs(wchar_t * restrict , const char * restrict, size_t);
int mbtowc(wchar_t * restrict, const char * restrict, size_t);
int posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__((availability(macosx,introduced=10.6)));
void qsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));
int rand(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
void *realloc(void *__ptr, size_t __size) __attribute__((__warn_unused_result__));
void srand(unsigned) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *__str, char **__endptr, int __base);
long double
  strtold(const char *, char **);

long long
  strtoll(const char *__str, char **__endptr, int __base);

unsigned long
  strtoul(const char *__str, char **__endptr, int __base);

unsigned long long
  strtoull(const char *__str, char **__endptr, int __base);
__attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")))
__attribute__((availability(macosx,introduced=10.0)))
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
int system(const char *) __asm("_" "system" );



size_t wcstombs(char * restrict, const wchar_t * restrict, size_t);
int wctomb(char *, wchar_t);


void _Exit(int) __attribute__((noreturn));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *restrict, int *restrict);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *restrict, int *restrict);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);

char *initstate(unsigned, char *, size_t);



long jrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
long nrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int posix_openpt(int);
char *ptsname(int);
int putenv(char *) __asm("_" "putenv" );
long random(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int rand_r(unsigned *) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

char *realpath(const char * restrict, char * restrict) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
 *seed48(unsigned short[3]);
int setenv(const char * __name, const char * __value, int __overwrite) __asm("_" "setenv" );

void setkey(const char *) __asm("_" "setkey" );



char *setstate(const char *);
void srand48(long);

void srandom(unsigned);



int unlockpt(int);

int unsetenv(const char *) __asm("_" "unsetenv" );







typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;
typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;

typedef __darwin_dev_t dev_t;
typedef __darwin_mode_t mode_t;


uint32_t arc4random(void);
void arc4random_addrandom(unsigned char * , int )
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(macosx,deprecated=10.12,message="use arc4random_stir")))
    __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(tvos,introduced=2.0))) __attribute__((availability(tvos,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(watchos,introduced=1.0))) __attribute__((availability(watchos,deprecated=3.0,message="use arc4random_stir")));
void arc4random_buf(void * __buf, size_t __nbytes) __attribute__((availability(macosx,introduced=10.7)));
void arc4random_stir(void);
uint32_t
  arc4random_uniform(uint32_t __upper_bound) __attribute__((availability(macosx,introduced=10.7)));

int atexit_b(void (^ _Nonnull)(void)) __attribute__((availability(macosx,introduced=10.6)));
void *bsearch_b(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));



char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);

int daemon(int, int) __asm("_" "daemon" "$1050") __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message="Use posix_spawn APIs instead."))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);

int heapsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int heapsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

int mergesort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int mergesort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void psort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void psort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void psort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void qsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void qsort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *));
int radixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
void setprogname(const char *);
int sradixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *__ptr, size_t __size);

long long
  strtoq(const char *__str, char **__endptr, int __base);
unsigned long long
  strtouq(const char *__str, char **__endptr, int __base);

extern char *suboptarg;
void *valloc(size_t);
typedef int jmp_buf[((9 * 2) + 3 + 16)];
typedef int sigjmp_buf[((9 * 2) + 3 + 16) + 1];
extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int) __attribute__((noreturn));


int _setjmp(jmp_buf);
void _longjmp(jmp_buf, int) __attribute__((noreturn));
int sigsetjmp(sigjmp_buf, int);
void siglongjmp(sigjmp_buf, int) __attribute__((noreturn));



void longjmperror(void);
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
extern int * __error(void);

  typedef signed short FT_Int16;
  typedef unsigned short FT_UInt16;
  typedef signed int FT_Int32;
  typedef unsigned int FT_UInt32;
  typedef int FT_Fast;
  typedef unsigned int FT_UFast;
  typedef long FT_Int64;
  typedef unsigned long FT_UInt64;
  typedef struct FT_MemoryRec_* FT_Memory;
  typedef void*
  (*FT_Alloc_Func)( FT_Memory memory,
                    long size );
  typedef void
  (*FT_Free_Func)( FT_Memory memory,
                   void* block );
  typedef void*
  (*FT_Realloc_Func)( FT_Memory memory,
                      long cur_size,
                      long new_size,
                      void* block );
  struct FT_MemoryRec_
  {
    void* user;
    FT_Alloc_Func alloc;
    FT_Free_Func free;
    FT_Realloc_Func realloc;
  };
  typedef struct FT_StreamRec_* FT_Stream;
  typedef union FT_StreamDesc_
  {
    long value;
    void* pointer;

  } FT_StreamDesc;
  typedef unsigned long
  (*FT_Stream_IoFunc)( FT_Stream stream,
                       unsigned long offset,
                       unsigned char* buffer,
                       unsigned long count );
  typedef void
  (*FT_Stream_CloseFunc)( FT_Stream stream );
  typedef struct FT_StreamRec_
  {
    unsigned char* base;
    unsigned long size;
    unsigned long pos;

    FT_StreamDesc descriptor;
    FT_StreamDesc pathname;
    FT_Stream_IoFunc read;
    FT_Stream_CloseFunc close;

    FT_Memory memory;
    unsigned char* cursor;
    unsigned char* limit;

  } FT_StreamRec;
  typedef signed long FT_Pos;
  typedef struct FT_Vector_
  {
    FT_Pos x;
    FT_Pos y;

  } FT_Vector;
  typedef struct FT_BBox_
  {
    FT_Pos xMin, yMin;
    FT_Pos xMax, yMax;

  } FT_BBox;
  typedef enum FT_Pixel_Mode_
  {
    FT_PIXEL_MODE_NONE = 0,
    FT_PIXEL_MODE_MONO,
    FT_PIXEL_MODE_GRAY,
    FT_PIXEL_MODE_GRAY2,
    FT_PIXEL_MODE_GRAY4,
    FT_PIXEL_MODE_LCD,
    FT_PIXEL_MODE_LCD_V,
    FT_PIXEL_MODE_BGRA,

    FT_PIXEL_MODE_MAX

  } FT_Pixel_Mode;
  typedef struct FT_Bitmap_
  {
    unsigned int rows;
    unsigned int width;
    int pitch;
    unsigned char* buffer;
    unsigned short num_grays;
    unsigned char pixel_mode;
    unsigned char palette_mode;
    void* palette;

  } FT_Bitmap;
  typedef struct FT_Outline_
  {
    short n_contours;
    short n_points;

    FT_Vector* points;
    char* tags;
    short* contours;

    int flags;

  } FT_Outline;
  typedef int
  (*FT_Outline_MoveToFunc)( const FT_Vector* to,
                            void* user );
  typedef int
  (*FT_Outline_LineToFunc)( const FT_Vector* to,
                            void* user );
  typedef int
  (*FT_Outline_ConicToFunc)( const FT_Vector* control,
                             const FT_Vector* to,
                             void* user );
  typedef int
  (*FT_Outline_CubicToFunc)( const FT_Vector* control1,
                             const FT_Vector* control2,
                             const FT_Vector* to,
                             void* user );
  typedef struct FT_Outline_Funcs_
  {
    FT_Outline_MoveToFunc move_to;
    FT_Outline_LineToFunc line_to;
    FT_Outline_ConicToFunc conic_to;
    FT_Outline_CubicToFunc cubic_to;

    int shift;
    FT_Pos delta;

  } FT_Outline_Funcs;
  typedef enum FT_Glyph_Format_
  {
    FT_GLYPH_FORMAT_NONE = ( ( (unsigned long)0 << 24 ) | ( (unsigned long)0 << 16 ) | ( (unsigned long)0 << 8 ) | (unsigned long)0 ),

    FT_GLYPH_FORMAT_COMPOSITE = ( ( (unsigned long)'c' << 24 ) | ( (unsigned long)'o' << 16 ) | ( (unsigned long)'m' << 8 ) | (unsigned long)'p' ),
    FT_GLYPH_FORMAT_BITMAP = ( ( (unsigned long)'b' << 24 ) | ( (unsigned long)'i' << 16 ) | ( (unsigned long)'t' << 8 ) | (unsigned long)'s' ),
    FT_GLYPH_FORMAT_OUTLINE = ( ( (unsigned long)'o' << 24 ) | ( (unsigned long)'u' << 16 ) | ( (unsigned long)'t' << 8 ) | (unsigned long)'l' ),
    FT_GLYPH_FORMAT_PLOTTER = ( ( (unsigned long)'p' << 24 ) | ( (unsigned long)'l' << 16 ) | ( (unsigned long)'o' << 8 ) | (unsigned long)'t' )

  } FT_Glyph_Format;
  typedef struct FT_RasterRec_* FT_Raster;
  typedef struct FT_Span_
  {
    short x;
    unsigned short len;
    unsigned char coverage;

  } FT_Span;
  typedef void
  (*FT_SpanFunc)( int y,
                  int count,
                  const FT_Span* spans,
                  void* user );
  typedef int
  (*FT_Raster_BitTest_Func)( int y,
                             int x,
                             void* user );
  typedef void
  (*FT_Raster_BitSet_Func)( int y,
                            int x,
                            void* user );
  typedef struct FT_Raster_Params_
  {
    const FT_Bitmap* target;
    const void* source;
    int flags;
    FT_SpanFunc gray_spans;
    FT_SpanFunc black_spans;
    FT_Raster_BitTest_Func bit_test;
    FT_Raster_BitSet_Func bit_set;
    void* user;
    FT_BBox clip_box;

  } FT_Raster_Params;
  typedef int
  (*FT_Raster_NewFunc)( void* memory,
                        FT_Raster* raster );
  typedef void
  (*FT_Raster_DoneFunc)( FT_Raster raster );
  typedef void
  (*FT_Raster_ResetFunc)( FT_Raster raster,
                          unsigned char* pool_base,
                          unsigned long pool_size );
  typedef int
  (*FT_Raster_SetModeFunc)( FT_Raster raster,
                            unsigned long mode,
                            void* args );
  typedef int
  (*FT_Raster_RenderFunc)( FT_Raster raster,
                           const FT_Raster_Params* params );
  typedef struct FT_Raster_Funcs_
  {
    FT_Glyph_Format glyph_format;

    FT_Raster_NewFunc raster_new;
    FT_Raster_ResetFunc raster_reset;
    FT_Raster_SetModeFunc raster_set_mode;
    FT_Raster_RenderFunc raster_render;
    FT_Raster_DoneFunc raster_done;

  } FT_Raster_Funcs;

  typedef unsigned char FT_Bool;
  typedef signed short FT_FWord;
  typedef unsigned short FT_UFWord;
  typedef signed char FT_Char;
  typedef unsigned char FT_Byte;
  typedef const FT_Byte* FT_Bytes;
  typedef FT_UInt32 FT_Tag;
  typedef char FT_String;
  typedef signed short FT_Short;
  typedef unsigned short FT_UShort;
  typedef signed int FT_Int;
  typedef unsigned int FT_UInt;
  typedef signed long FT_Long;
  typedef unsigned long FT_ULong;
  typedef signed short FT_F2Dot14;
  typedef signed long FT_F26Dot6;
  typedef signed long FT_Fixed;
  typedef int FT_Error;
  typedef void* FT_Pointer;
  typedef size_t FT_Offset;
  typedef ptrdiff_t FT_PtrDist;
  typedef struct FT_UnitVector_
  {
    FT_F2Dot14 x;
    FT_F2Dot14 y;

  } FT_UnitVector;
  typedef struct FT_Matrix_
  {
    FT_Fixed xx, xy;
    FT_Fixed yx, yy;

  } FT_Matrix;
  typedef struct FT_Data_
  {
    const FT_Byte* pointer;
    FT_Int length;

  } FT_Data;
  typedef void (*FT_Generic_Finalizer)(void* object);
  typedef struct FT_Generic_
  {
    void* data;
    FT_Generic_Finalizer finalizer;

  } FT_Generic;
  typedef struct FT_ListNodeRec_* FT_ListNode;
  typedef struct FT_ListRec_* FT_List;
  typedef struct FT_ListNodeRec_
  {
    FT_ListNode prev;
    FT_ListNode next;
    void* data;

  } FT_ListNodeRec;
  typedef struct FT_ListRec_
  {
    FT_ListNode head;
    FT_ListNode tail;

  } FT_ListRec;
  enum {



  FT_Mod_Err_Base = 0,
  FT_Mod_Err_Autofit = 0,
  FT_Mod_Err_BDF = 0,
  FT_Mod_Err_Bzip2 = 0,
  FT_Mod_Err_Cache = 0,
  FT_Mod_Err_CFF = 0,
  FT_Mod_Err_CID = 0,
  FT_Mod_Err_Gzip = 0,
  FT_Mod_Err_LZW = 0,
  FT_Mod_Err_OTvalid = 0,
  FT_Mod_Err_PCF = 0,
  FT_Mod_Err_PFR = 0,
  FT_Mod_Err_PSaux = 0,
  FT_Mod_Err_PShinter = 0,
  FT_Mod_Err_PSnames = 0,
  FT_Mod_Err_Raster = 0,
  FT_Mod_Err_SFNT = 0,
  FT_Mod_Err_Smooth = 0,
  FT_Mod_Err_TrueType = 0,
  FT_Mod_Err_Type1 = 0,
  FT_Mod_Err_Type42 = 0,
  FT_Mod_Err_Winfonts = 0,
  FT_Mod_Err_GXvalid = 0,



  FT_Mod_Err_Max };
  enum {





  FT_Err_Ok = 0x00,


  FT_Err_Cannot_Open_Resource = 0x01 + 0,

  FT_Err_Unknown_File_Format = 0x02 + 0,

  FT_Err_Invalid_File_Format = 0x03 + 0,

  FT_Err_Invalid_Version = 0x04 + 0,

  FT_Err_Lower_Module_Version = 0x05 + 0,

  FT_Err_Invalid_Argument = 0x06 + 0,

  FT_Err_Unimplemented_Feature = 0x07 + 0,

  FT_Err_Invalid_Table = 0x08 + 0,

  FT_Err_Invalid_Offset = 0x09 + 0,

  FT_Err_Array_Too_Large = 0x0A + 0,

  FT_Err_Missing_Module = 0x0B + 0,

  FT_Err_Missing_Property = 0x0C + 0,




  FT_Err_Invalid_Glyph_Index = 0x10 + 0,

  FT_Err_Invalid_Character_Code = 0x11 + 0,

  FT_Err_Invalid_Glyph_Format = 0x12 + 0,

  FT_Err_Cannot_Render_Glyph = 0x13 + 0,

  FT_Err_Invalid_Outline = 0x14 + 0,

  FT_Err_Invalid_Composite = 0x15 + 0,

  FT_Err_Too_Many_Hints = 0x16 + 0,

  FT_Err_Invalid_Pixel_Size = 0x17 + 0,




  FT_Err_Invalid_Handle = 0x20 + 0,

  FT_Err_Invalid_Library_Handle = 0x21 + 0,

  FT_Err_Invalid_Driver_Handle = 0x22 + 0,

  FT_Err_Invalid_Face_Handle = 0x23 + 0,

  FT_Err_Invalid_Size_Handle = 0x24 + 0,

  FT_Err_Invalid_Slot_Handle = 0x25 + 0,

  FT_Err_Invalid_CharMap_Handle = 0x26 + 0,

  FT_Err_Invalid_Cache_Handle = 0x27 + 0,

  FT_Err_Invalid_Stream_Handle = 0x28 + 0,




  FT_Err_Too_Many_Drivers = 0x30 + 0,

  FT_Err_Too_Many_Extensions = 0x31 + 0,




  FT_Err_Out_Of_Memory = 0x40 + 0,

  FT_Err_Unlisted_Object = 0x41 + 0,




  FT_Err_Cannot_Open_Stream = 0x51 + 0,

  FT_Err_Invalid_Stream_Seek = 0x52 + 0,

  FT_Err_Invalid_Stream_Skip = 0x53 + 0,

  FT_Err_Invalid_Stream_Read = 0x54 + 0,

  FT_Err_Invalid_Stream_Operation = 0x55 + 0,

  FT_Err_Invalid_Frame_Operation = 0x56 + 0,

  FT_Err_Nested_Frame_Access = 0x57 + 0,

  FT_Err_Invalid_Frame_Read = 0x58 + 0,




  FT_Err_Raster_Uninitialized = 0x60 + 0,

  FT_Err_Raster_Corrupted = 0x61 + 0,

  FT_Err_Raster_Overflow = 0x62 + 0,

  FT_Err_Raster_Negative_Height = 0x63 + 0,




  FT_Err_Too_Many_Caches = 0x70 + 0,




  FT_Err_Invalid_Opcode = 0x80 + 0,

  FT_Err_Too_Few_Arguments = 0x81 + 0,

  FT_Err_Stack_Overflow = 0x82 + 0,

  FT_Err_Code_Overflow = 0x83 + 0,

  FT_Err_Bad_Argument = 0x84 + 0,

  FT_Err_Divide_By_Zero = 0x85 + 0,

  FT_Err_Invalid_Reference = 0x86 + 0,

  FT_Err_Debug_OpCode = 0x87 + 0,

  FT_Err_ENDF_In_Exec_Stream = 0x88 + 0,

  FT_Err_Nested_DEFS = 0x89 + 0,

  FT_Err_Invalid_CodeRange = 0x8A + 0,

  FT_Err_Execution_Too_Long = 0x8B + 0,

  FT_Err_Too_Many_Function_Defs = 0x8C + 0,

  FT_Err_Too_Many_Instruction_Defs = 0x8D + 0,

  FT_Err_Table_Missing = 0x8E + 0,

  FT_Err_Horiz_Header_Missing = 0x8F + 0,

  FT_Err_Locations_Missing = 0x90 + 0,

  FT_Err_Name_Table_Missing = 0x91 + 0,

  FT_Err_CMap_Table_Missing = 0x92 + 0,

  FT_Err_Hmtx_Table_Missing = 0x93 + 0,

  FT_Err_Post_Table_Missing = 0x94 + 0,

  FT_Err_Invalid_Horiz_Metrics = 0x95 + 0,

  FT_Err_Invalid_CharMap_Format = 0x96 + 0,

  FT_Err_Invalid_PPem = 0x97 + 0,

  FT_Err_Invalid_Vert_Metrics = 0x98 + 0,

  FT_Err_Could_Not_Find_Context = 0x99 + 0,

  FT_Err_Invalid_Post_Table_Format = 0x9A + 0,

  FT_Err_Invalid_Post_Table = 0x9B + 0,




  FT_Err_Syntax_Error = 0xA0 + 0,

  FT_Err_Stack_Underflow = 0xA1 + 0,

  FT_Err_Ignore = 0xA2 + 0,

  FT_Err_No_Unicode_Glyph_Name = 0xA3 + 0,

  FT_Err_Glyph_Too_Big = 0xA4 + 0,




  FT_Err_Missing_Startfont_Field = 0xB0 + 0,

  FT_Err_Missing_Font_Field = 0xB1 + 0,

  FT_Err_Missing_Size_Field = 0xB2 + 0,

  FT_Err_Missing_Fontboundingbox_Field = 0xB3 + 0,

  FT_Err_Missing_Chars_Field = 0xB4 + 0,

  FT_Err_Missing_Startchar_Field = 0xB5 + 0,

  FT_Err_Missing_Encoding_Field = 0xB6 + 0,

  FT_Err_Missing_Bbx_Field = 0xB7 + 0,

  FT_Err_Bbx_Too_Big = 0xB8 + 0,

  FT_Err_Corrupted_Font_Header = 0xB9 + 0,

  FT_Err_Corrupted_Font_Glyphs = 0xBA + 0,



  FT_Err_Max };
  typedef struct FT_Glyph_Metrics_
  {
    FT_Pos width;
    FT_Pos height;

    FT_Pos horiBearingX;
    FT_Pos horiBearingY;
    FT_Pos horiAdvance;

    FT_Pos vertBearingX;
    FT_Pos vertBearingY;
    FT_Pos vertAdvance;

  } FT_Glyph_Metrics;
  typedef struct FT_Bitmap_Size_
  {
    FT_Short height;
    FT_Short width;

    FT_Pos size;

    FT_Pos x_ppem;
    FT_Pos y_ppem;

  } FT_Bitmap_Size;
  typedef struct FT_LibraryRec_ *FT_Library;
  typedef struct FT_ModuleRec_* FT_Module;
  typedef struct FT_DriverRec_* FT_Driver;
  typedef struct FT_RendererRec_* FT_Renderer;
  typedef struct FT_FaceRec_* FT_Face;
  typedef struct FT_SizeRec_* FT_Size;
  typedef struct FT_GlyphSlotRec_* FT_GlyphSlot;
  typedef struct FT_CharMapRec_* FT_CharMap;
  typedef enum FT_Encoding_
  {
    FT_ENCODING_NONE = ( ( (FT_UInt32)(0) << 24 ) | ( (FT_UInt32)(0) << 16 ) | ( (FT_UInt32)(0) << 8 ) | (FT_UInt32)(0) ),

    FT_ENCODING_MS_SYMBOL = ( ( (FT_UInt32)('s') << 24 ) | ( (FT_UInt32)('y') << 16 ) | ( (FT_UInt32)('m') << 8 ) | (FT_UInt32)('b') ),
    FT_ENCODING_UNICODE = ( ( (FT_UInt32)('u') << 24 ) | ( (FT_UInt32)('n') << 16 ) | ( (FT_UInt32)('i') << 8 ) | (FT_UInt32)('c') ),

    FT_ENCODING_SJIS = ( ( (FT_UInt32)('s') << 24 ) | ( (FT_UInt32)('j') << 16 ) | ( (FT_UInt32)('i') << 8 ) | (FT_UInt32)('s') ),
    FT_ENCODING_GB2312 = ( ( (FT_UInt32)('g') << 24 ) | ( (FT_UInt32)('b') << 16 ) | ( (FT_UInt32)(' ') << 8 ) | (FT_UInt32)(' ') ),
    FT_ENCODING_BIG5 = ( ( (FT_UInt32)('b') << 24 ) | ( (FT_UInt32)('i') << 16 ) | ( (FT_UInt32)('g') << 8 ) | (FT_UInt32)('5') ),
    FT_ENCODING_WANSUNG = ( ( (FT_UInt32)('w') << 24 ) | ( (FT_UInt32)('a') << 16 ) | ( (FT_UInt32)('n') << 8 ) | (FT_UInt32)('s') ),
    FT_ENCODING_JOHAB = ( ( (FT_UInt32)('j') << 24 ) | ( (FT_UInt32)('o') << 16 ) | ( (FT_UInt32)('h') << 8 ) | (FT_UInt32)('a') ),


    FT_ENCODING_MS_SJIS = FT_ENCODING_SJIS,
    FT_ENCODING_MS_GB2312 = FT_ENCODING_GB2312,
    FT_ENCODING_MS_BIG5 = FT_ENCODING_BIG5,
    FT_ENCODING_MS_WANSUNG = FT_ENCODING_WANSUNG,
    FT_ENCODING_MS_JOHAB = FT_ENCODING_JOHAB,

    FT_ENCODING_ADOBE_STANDARD = ( ( (FT_UInt32)('A') << 24 ) | ( (FT_UInt32)('D') << 16 ) | ( (FT_UInt32)('O') << 8 ) | (FT_UInt32)('B') ),
    FT_ENCODING_ADOBE_EXPERT = ( ( (FT_UInt32)('A') << 24 ) | ( (FT_UInt32)('D') << 16 ) | ( (FT_UInt32)('B') << 8 ) | (FT_UInt32)('E') ),
    FT_ENCODING_ADOBE_CUSTOM = ( ( (FT_UInt32)('A') << 24 ) | ( (FT_UInt32)('D') << 16 ) | ( (FT_UInt32)('B') << 8 ) | (FT_UInt32)('C') ),
    FT_ENCODING_ADOBE_LATIN_1 = ( ( (FT_UInt32)('l') << 24 ) | ( (FT_UInt32)('a') << 16 ) | ( (FT_UInt32)('t') << 8 ) | (FT_UInt32)('1') ),

    FT_ENCODING_OLD_LATIN_2 = ( ( (FT_UInt32)('l') << 24 ) | ( (FT_UInt32)('a') << 16 ) | ( (FT_UInt32)('t') << 8 ) | (FT_UInt32)('2') ),

    FT_ENCODING_APPLE_ROMAN = ( ( (FT_UInt32)('a') << 24 ) | ( (FT_UInt32)('r') << 16 ) | ( (FT_UInt32)('m') << 8 ) | (FT_UInt32)('n') )

  } FT_Encoding;
  typedef struct FT_CharMapRec_
  {
    FT_Face face;
    FT_Encoding encoding;
    FT_UShort platform_id;
    FT_UShort encoding_id;

  } FT_CharMapRec;
  typedef struct FT_Face_InternalRec_* FT_Face_Internal;
  typedef struct FT_FaceRec_
  {
    FT_Long num_faces;
    FT_Long face_index;

    FT_Long face_flags;
    FT_Long style_flags;

    FT_Long num_glyphs;

    FT_String* family_name;
    FT_String* style_name;

    FT_Int num_fixed_sizes;
    FT_Bitmap_Size* available_sizes;

    FT_Int num_charmaps;
    FT_CharMap* charmaps;

    FT_Generic generic;




    FT_BBox bbox;

    FT_UShort units_per_EM;
    FT_Short ascender;
    FT_Short descender;
    FT_Short height;

    FT_Short max_advance_width;
    FT_Short max_advance_height;

    FT_Short underline_position;
    FT_Short underline_thickness;

    FT_GlyphSlot glyph;
    FT_Size size;
    FT_CharMap charmap;



    FT_Driver driver;
    FT_Memory memory;
    FT_Stream stream;

    FT_ListRec sizes_list;

    FT_Generic autohint;
    void* extensions;

    FT_Face_Internal internal;



  } FT_FaceRec;
  typedef struct FT_Size_InternalRec_* FT_Size_Internal;
  typedef struct FT_Size_Metrics_
  {
    FT_UShort x_ppem;
    FT_UShort y_ppem;

    FT_Fixed x_scale;
    FT_Fixed y_scale;

    FT_Pos ascender;
    FT_Pos descender;
    FT_Pos height;
    FT_Pos max_advance;

  } FT_Size_Metrics;
  typedef struct FT_SizeRec_
  {
    FT_Face face;
    FT_Generic generic;
    FT_Size_Metrics metrics;
    FT_Size_Internal internal;

  } FT_SizeRec;
  typedef struct FT_SubGlyphRec_* FT_SubGlyph;
  typedef struct FT_Slot_InternalRec_* FT_Slot_Internal;
  typedef struct FT_GlyphSlotRec_
  {
    FT_Library library;
    FT_Face face;
    FT_GlyphSlot next;
    FT_UInt reserved;
    FT_Generic generic;

    FT_Glyph_Metrics metrics;
    FT_Fixed linearHoriAdvance;
    FT_Fixed linearVertAdvance;
    FT_Vector advance;

    FT_Glyph_Format format;

    FT_Bitmap bitmap;
    FT_Int bitmap_left;
    FT_Int bitmap_top;

    FT_Outline outline;

    FT_UInt num_subglyphs;
    FT_SubGlyph subglyphs;

    void* control_data;
    long control_len;

    FT_Pos lsb_delta;
    FT_Pos rsb_delta;

    void* other;

    FT_Slot_Internal internal;

  } FT_GlyphSlotRec;
  extern FT_Error
  FT_Init_FreeType( FT_Library *alibrary );
  extern FT_Error
  FT_Done_FreeType( FT_Library library );
  typedef struct FT_Parameter_
  {
    FT_ULong tag;
    FT_Pointer data;

  } FT_Parameter;
  typedef struct FT_Open_Args_
  {
    FT_UInt flags;
    const FT_Byte* memory_base;
    FT_Long memory_size;
    FT_String* pathname;
    FT_Stream stream;
    FT_Module driver;
    FT_Int num_params;
    FT_Parameter* params;

  } FT_Open_Args;
  extern FT_Error
  FT_New_Face( FT_Library library,
               const char* filepathname,
               FT_Long face_index,
               FT_Face *aface );
  extern FT_Error
  FT_New_Memory_Face( FT_Library library,
                      const FT_Byte* file_base,
                      FT_Long file_size,
                      FT_Long face_index,
                      FT_Face *aface );
  extern FT_Error
  FT_Open_Face( FT_Library library,
                const FT_Open_Args* args,
                FT_Long face_index,
                FT_Face *aface );
  extern FT_Error
  FT_Attach_File( FT_Face face,
                  const char* filepathname );
  extern FT_Error
  FT_Attach_Stream( FT_Face face,
                    FT_Open_Args* parameters );
  extern FT_Error
  FT_Reference_Face( FT_Face face );
  extern FT_Error
  FT_Done_Face( FT_Face face );
  extern FT_Error
  FT_Select_Size( FT_Face face,
                  FT_Int strike_index );
  typedef enum FT_Size_Request_Type_
  {
    FT_SIZE_REQUEST_TYPE_NOMINAL,
    FT_SIZE_REQUEST_TYPE_REAL_DIM,
    FT_SIZE_REQUEST_TYPE_BBOX,
    FT_SIZE_REQUEST_TYPE_CELL,
    FT_SIZE_REQUEST_TYPE_SCALES,

    FT_SIZE_REQUEST_TYPE_MAX

  } FT_Size_Request_Type;
  typedef struct FT_Size_RequestRec_
  {
    FT_Size_Request_Type type;
    FT_Long width;
    FT_Long height;
    FT_UInt horiResolution;
    FT_UInt vertResolution;

  } FT_Size_RequestRec;
  typedef struct FT_Size_RequestRec_ *FT_Size_Request;
  extern FT_Error
  FT_Request_Size( FT_Face face,
                   FT_Size_Request req );
  extern FT_Error
  FT_Set_Char_Size( FT_Face face,
                    FT_F26Dot6 char_width,
                    FT_F26Dot6 char_height,
                    FT_UInt horz_resolution,
                    FT_UInt vert_resolution );
  extern FT_Error
  FT_Set_Pixel_Sizes( FT_Face face,
                      FT_UInt pixel_width,
                      FT_UInt pixel_height );
  extern FT_Error
  FT_Load_Glyph( FT_Face face,
                 FT_UInt glyph_index,
                 FT_Int32 load_flags );
  extern FT_Error
  FT_Load_Char( FT_Face face,
                FT_ULong char_code,
                FT_Int32 load_flags );
  extern void
  FT_Set_Transform( FT_Face face,
                    FT_Matrix* matrix,
                    FT_Vector* delta );
  typedef enum FT_Render_Mode_
  {
    FT_RENDER_MODE_NORMAL = 0,
    FT_RENDER_MODE_LIGHT,
    FT_RENDER_MODE_MONO,
    FT_RENDER_MODE_LCD,
    FT_RENDER_MODE_LCD_V,

    FT_RENDER_MODE_MAX

  } FT_Render_Mode;
  extern FT_Error
  FT_Render_Glyph( FT_GlyphSlot slot,
                   FT_Render_Mode render_mode );
  typedef enum FT_Kerning_Mode_
  {
    FT_KERNING_DEFAULT = 0,
    FT_KERNING_UNFITTED,
    FT_KERNING_UNSCALED

  } FT_Kerning_Mode;
  extern FT_Error
  FT_Get_Kerning( FT_Face face,
                  FT_UInt left_glyph,
                  FT_UInt right_glyph,
                  FT_UInt kern_mode,
                  FT_Vector *akerning );
  extern FT_Error
  FT_Get_Track_Kerning( FT_Face face,
                        FT_Fixed point_size,
                        FT_Int degree,
                        FT_Fixed* akerning );
  extern FT_Error
  FT_Get_Glyph_Name( FT_Face face,
                     FT_UInt glyph_index,
                     FT_Pointer buffer,
                     FT_UInt buffer_max );
  extern const char*
  FT_Get_Postscript_Name( FT_Face face );
  extern FT_Error
  FT_Select_Charmap( FT_Face face,
                     FT_Encoding encoding );
  extern FT_Error
  FT_Set_Charmap( FT_Face face,
                  FT_CharMap charmap );
  extern FT_Int
  FT_Get_Charmap_Index( FT_CharMap charmap );
  extern FT_UInt
  FT_Get_Char_Index( FT_Face face,
                     FT_ULong charcode );
  extern FT_ULong
  FT_Get_First_Char( FT_Face face,
                     FT_UInt *agindex );
  extern FT_ULong
  FT_Get_Next_Char( FT_Face face,
                    FT_ULong char_code,
                    FT_UInt *agindex );
  extern FT_UInt
  FT_Get_Name_Index( FT_Face face,
                     FT_String* glyph_name );
  extern FT_Error
  FT_Get_SubGlyph_Info( FT_GlyphSlot glyph,
                        FT_UInt sub_index,
                        FT_Int *p_index,
                        FT_UInt *p_flags,
                        FT_Int *p_arg1,
                        FT_Int *p_arg2,
                        FT_Matrix *p_transform );
  extern FT_UShort
  FT_Get_FSType_Flags( FT_Face face );
  extern FT_UInt
  FT_Face_GetCharVariantIndex( FT_Face face,
                               FT_ULong charcode,
                               FT_ULong variantSelector );
  extern FT_Int
  FT_Face_GetCharVariantIsDefault( FT_Face face,
                                   FT_ULong charcode,
                                   FT_ULong variantSelector );
  extern FT_UInt32*
  FT_Face_GetVariantSelectors( FT_Face face );
  extern FT_UInt32*
  FT_Face_GetVariantsOfChar( FT_Face face,
                             FT_ULong charcode );
  extern FT_UInt32*
  FT_Face_GetCharsOfVariant( FT_Face face,
                             FT_ULong variantSelector );
  extern FT_Long
  FT_MulDiv( FT_Long a,
             FT_Long b,
             FT_Long c );
  extern FT_Long
  FT_MulFix( FT_Long a,
             FT_Long b );
  extern FT_Long
  FT_DivFix( FT_Long a,
             FT_Long b );
  extern FT_Fixed
  FT_RoundFix( FT_Fixed a );
  extern FT_Fixed
  FT_CeilFix( FT_Fixed a );
  extern FT_Fixed
  FT_FloorFix( FT_Fixed a );
  extern void
  FT_Vector_Transform( FT_Vector* vec,
                       const FT_Matrix* matrix );
  extern void
  FT_Library_Version( FT_Library library,
                      FT_Int *amajor,
                      FT_Int *aminor,
                      FT_Int *apatch );
  extern FT_Bool
  FT_Face_CheckTrueTypePatents( FT_Face face );
  extern FT_Bool
  FT_Face_SetUnpatentedHinting( FT_Face face,
                                FT_Bool value );

