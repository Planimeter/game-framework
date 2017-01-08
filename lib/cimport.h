



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





typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;





typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;



typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;
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


typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef unsigned long u_long;


typedef unsigned short ushort;
typedef unsigned int uint;


typedef u_int64_t u_quad_t;
typedef int64_t quad_t;
typedef quad_t * qaddr_t;

typedef char * caddr_t;
typedef int32_t daddr_t;


typedef __darwin_dev_t dev_t;

typedef u_int32_t fixpt_t;


typedef __darwin_blkcnt_t blkcnt_t;
typedef __darwin_blksize_t blksize_t;
typedef __darwin_gid_t gid_t;
typedef __uint32_t in_addr_t;
typedef __uint16_t in_port_t;
typedef __darwin_ino_t ino_t;


typedef __darwin_ino64_t ino64_t;


typedef __int32_t key_t;
typedef __darwin_mode_t mode_t;
typedef __uint16_t nlink_t;
typedef __darwin_id_t id_t;
typedef __darwin_pid_t pid_t;
typedef __darwin_off_t off_t;

typedef int32_t segsz_t;
typedef int32_t swblk_t;


typedef __darwin_uid_t uid_t;
typedef __darwin_clock_t clock_t;
typedef __darwin_size_t size_t;
typedef __darwin_ssize_t ssize_t;
typedef __darwin_time_t time_t;

typedef __darwin_useconds_t useconds_t;
typedef __darwin_suseconds_t suseconds_t;


typedef __darwin_size_t rsize_t;
typedef int errno_t;








typedef struct fd_set {
 __int32_t fds_bits[((((1024) % ((sizeof(__int32_t) * 8))) == 0) ? ((1024) / ((sizeof(__int32_t) * 8))) : (((1024) / ((sizeof(__int32_t) * 8))) + 1))];
} fd_set;



static __inline int
__darwin_fd_isset(int _n, const struct fd_set *_p)
{
 return (_p->fds_bits[(unsigned long)_n/(sizeof(__int32_t) * 8)] & ((__int32_t)(((unsigned long)1)<<((unsigned long)_n % (sizeof(__int32_t) * 8)))));
}




typedef __int32_t fd_mask;










typedef __darwin_pthread_attr_t pthread_attr_t;
typedef __darwin_pthread_cond_t pthread_cond_t;
typedef __darwin_pthread_condattr_t pthread_condattr_t;
typedef __darwin_pthread_mutex_t pthread_mutex_t;
typedef __darwin_pthread_mutexattr_t pthread_mutexattr_t;
typedef __darwin_pthread_once_t pthread_once_t;
typedef __darwin_pthread_rwlock_t pthread_rwlock_t;
typedef __darwin_pthread_rwlockattr_t pthread_rwlockattr_t;
typedef __darwin_pthread_t pthread_t;



typedef __darwin_pthread_key_t pthread_key_t;




typedef __darwin_fsblkcnt_t fsblkcnt_t;
typedef __darwin_fsfilcnt_t fsfilcnt_t;
    typedef float float_t;
    typedef double double_t;
extern int __math_errhandling(void);
extern int __fpclassifyf(float);
extern int __fpclassifyd(double);
extern int __fpclassifyl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float);
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double);
inline __attribute__ ((__always_inline__)) int __inline_isinff(float);
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double);
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnand(double);
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double);
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double);
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float);
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double);
inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double);

inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float __x) {
    return __x == __x && __builtin_fabsf(__x) != __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double __x) {
    return __x == __x && __builtin_fabs(__x) != __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double __x) {
    return __x == __x && __builtin_fabsl(__x) != __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isinff(float __x) {
    return __builtin_fabsf(__x) == __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double __x) {
    return __builtin_fabs(__x) == __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double __x) {
    return __builtin_fabsl(__x) == __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnand(double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float __x) {
    union { float __f; unsigned int __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 31);
}
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double __x) {
    union { double __f; unsigned long long __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}

inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double __x) {
    union {
        long double __ld;
        struct{ unsigned long long __m; unsigned short __sexp; } __p;
    } __u;
    __u.__ld = __x;
    return (int)(__u.__p.__sexp >> 15);
}







inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float __x) {
    return __inline_isfinitef(__x) && __builtin_fabsf(__x) >= 1.17549435e-38F;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double __x) {
    return __inline_isfinited(__x) && __builtin_fabs(__x) >= 2.2250738585072014e-308;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double __x) {
    return __inline_isfinitel(__x) && __builtin_fabsl(__x) >= 3.36210314311209350626e-4932L;
}
extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);

extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);

extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);

extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);

extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);

extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);

extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);

extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);

extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);

extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);

extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);

extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);

extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);

extern float expf(float);
extern double exp(double);
extern long double expl(long double);

extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);

extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);

extern float logf(float);
extern double log(double);
extern long double logl(long double);

extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);

extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);

extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);

extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);

extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);

extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);

extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);

extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);

extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);

extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);

extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);

extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);

extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);

extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);

extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);

extern float erff(float);
extern double erf(double);
extern long double erfl(long double);

extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);




extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);

extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);

extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);

extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);

extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);

extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);

extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);

extern float roundf(float);
extern double round(double);
extern long double roundl(long double);

extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);




extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);

extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);


extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);

extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);

extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);

extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);

extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);

extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);

extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);

extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);

extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);

extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);

extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);

extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);
extern float __inff(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));
extern double __inf(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));
extern long double __infl(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern float __nan(void) __attribute__((availability(macosx,introduced=10.0)));
extern float __exp10f(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __exp10(double) __attribute__((availability(macosx,introduced=10.9)));





inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp);
extern float __cospif(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __cospi(double) __attribute__((availability(macosx,introduced=10.9)));
extern float __sinpif(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __sinpi(double) __attribute__((availability(macosx,introduced=10.9)));
extern float __tanpif(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __tanpi(double) __attribute__((availability(macosx,introduced=10.9)));
inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp);






struct __float2 { float __sinval; float __cosval; };
struct __double2 { double __sinval; double __cosval; };

extern struct __float2 __sincosf_stret(float);
extern struct __double2 __sincos_stret(double);
extern struct __float2 __sincospif_stret(float);
extern struct __double2 __sincospi_stret(double);

inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincosf_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincos_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincospif_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincospi_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}







extern double j0(double) __attribute__((availability(macosx,introduced=10.0)));
extern double j1(double) __attribute__((availability(macosx,introduced=10.0)));
extern double jn(int, double) __attribute__((availability(macosx,introduced=10.0)));
extern double y0(double) __attribute__((availability(macosx,introduced=10.0)));
extern double y1(double) __attribute__((availability(macosx,introduced=10.0)));
extern double yn(int, double) __attribute__((availability(macosx,introduced=10.0)));
extern double scalb(double, double);
extern int signgam;
extern long int rinttol(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern long int roundtol(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern double drem(double, double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern int finite(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern double gamma(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern double significand(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));


struct exception {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
};

extern int matherr(struct exception *) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));
typedef long int ptrdiff_t;
typedef int wchar_t;
typedef long double max_align_t;
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
errno_t memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n) __attribute__((availability(macosx,introduced=10.9)));
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












struct aiVector3D {
    float x, y, z;
} __attribute__((__packed__));




struct aiVector2D {
    float x, y;
};




struct aiColor4D {
    float r, g, b, a;
} __attribute__((__packed__));




struct aiMatrix3x3 {
    float a1, a2, a3;
    float b1, b2, b3;
    float c1, c2, c3;
} __attribute__((__packed__));




struct aiMatrix4x4 {
    float a1, a2, a3, a4;
    float b1, b2, b3, b4;
    float c1, c2, c3, c4;
    float d1, d2, d3, d4;
} __attribute__((__packed__));





struct aiQuaternion {
    float w, x, y, z;
};




struct aiPlane
{
    float a,b,c,d;
} __attribute__((__packed__));




struct aiRay
{
    struct aiVector3D pos, dir;
} __attribute__((__packed__));




struct aiColor3D
{
    float r, g, b;
} __attribute__((__packed__));

struct aiString
{
    size_t length;


    char data[1024];
} ;






typedef enum aiReturn
{

    aiReturn_SUCCESS = 0x0,


    aiReturn_FAILURE = -0x1,




    aiReturn_OUTOFMEMORY = -0x3,




    _AI_ENFORCE_ENUM_SIZE = 0x7fffffff


} aiReturn;
enum aiOrigin
{

    aiOrigin_SET = 0x0,


    aiOrigin_CUR = 0x1,


    aiOrigin_END = 0x2,




    _AI_ORIGIN_ENFORCE_ENUM_SIZE = 0x7fffffff


};






enum aiDefaultLogStream
{

    aiDefaultLogStream_FILE = 0x1,


    aiDefaultLogStream_STDOUT = 0x2,


    aiDefaultLogStream_STDERR = 0x4,




    aiDefaultLogStream_DEBUGGER = 0x8,




    _AI_DLS_ENFORCE_ENUM_SIZE = 0x7fffffff

};
struct aiMemoryInfo
{
    unsigned int textures;


    unsigned int materials;


    unsigned int meshes;


    unsigned int nodes;


    unsigned int animations;


    unsigned int cameras;


    unsigned int lights;


    unsigned int total;
};







enum aiImporterFlags
{


    aiImporterFlags_SupportTextFlavour = 0x1,



    aiImporterFlags_SupportBinaryFlavour = 0x2,



    aiImporterFlags_SupportCompressedFlavour = 0x4,





    aiImporterFlags_LimitedSupport = 0x8,





    aiImporterFlags_Experimental = 0x10
};
struct aiImporterDesc
{

    const char* mName;


    const char* mAuthor;


    const char* mMaintainer;


    const char* mComments;



    unsigned int mFlags;




    unsigned int mMinMajor;
    unsigned int mMinMinor;







    unsigned int mMaxMajor;
    unsigned int mMaxMinor;
    const char* mFileExtensions;
};







__attribute__ ((visibility("default"))) const struct aiImporterDesc* aiGetImporterDesc( const char *extension );





struct aiScene;
struct aiFileIO;
typedef void (*aiLogStreamCallback)(const char* , char* );
struct aiLogStream
{

    aiLogStreamCallback callback;


    char* user;
};
struct aiPropertyStore { char sentinel; };


typedef int aiBool;
__attribute__ ((visibility("default"))) const struct aiScene* aiImportFile(
    const char* pFile,
    unsigned int pFlags);
__attribute__ ((visibility("default"))) const struct aiScene* aiImportFileEx(
    const char* pFile,
    unsigned int pFlags,
    struct aiFileIO* pFS);
__attribute__ ((visibility("default"))) const struct aiScene* aiImportFileExWithProperties(
    const char* pFile,
    unsigned int pFlags,
    struct aiFileIO* pFS,
    const struct aiPropertyStore* pProps);
__attribute__ ((visibility("default"))) const struct aiScene* aiImportFileFromMemory(
    const char* pBuffer,
    unsigned int pLength,
    unsigned int pFlags,
    const char* pHint);
__attribute__ ((visibility("default"))) const struct aiScene* aiImportFileFromMemoryWithProperties(
    const char* pBuffer,
    unsigned int pLength,
    unsigned int pFlags,
    const char* pHint,
    const struct aiPropertyStore* pProps);
__attribute__ ((visibility("default"))) const struct aiScene* aiApplyPostProcessing(
    const struct aiScene* pScene,
    unsigned int pFlags);
__attribute__ ((visibility("default"))) struct aiLogStream aiGetPredefinedLogStream(
    enum aiDefaultLogStream pStreams,
    const char* file);
__attribute__ ((visibility("default"))) void aiAttachLogStream(
    const struct aiLogStream* stream);
__attribute__ ((visibility("default"))) void aiEnableVerboseLogging(aiBool d);
__attribute__ ((visibility("default"))) enum aiReturn aiDetachLogStream(
    const struct aiLogStream* stream);
__attribute__ ((visibility("default"))) void aiDetachAllLogStreams(void);







__attribute__ ((visibility("default"))) void aiReleaseImport(
    const struct aiScene* pScene);
__attribute__ ((visibility("default"))) const char* aiGetErrorString();
__attribute__ ((visibility("default"))) aiBool aiIsExtensionSupported(
    const char* szExtension);
__attribute__ ((visibility("default"))) void aiGetExtensionList(
    struct aiString* szOut);






__attribute__ ((visibility("default"))) void aiGetMemoryRequirements(
    const struct aiScene* pIn,
    struct aiMemoryInfo* in);
__attribute__ ((visibility("default"))) struct aiPropertyStore* aiCreatePropertyStore(void);





__attribute__ ((visibility("default"))) void aiReleasePropertyStore(struct aiPropertyStore* p);
__attribute__ ((visibility("default"))) void aiSetImportPropertyInteger(
    struct aiPropertyStore* store,
    const char* szName,
    int value);
__attribute__ ((visibility("default"))) void aiSetImportPropertyFloat(
    struct aiPropertyStore* store,
    const char* szName,
    float value);
__attribute__ ((visibility("default"))) void aiSetImportPropertyString(
    struct aiPropertyStore* store,
    const char* szName,
    const struct aiString* st);
__attribute__ ((visibility("default"))) void aiSetImportPropertyMatrix(
    struct aiPropertyStore* store,
    const char* szName,
    const struct aiMatrix4x4* mat);







__attribute__ ((visibility("default"))) void aiCreateQuaternionFromMatrix(
    struct aiQuaternion* quat,
    const struct aiMatrix3x3* mat);
__attribute__ ((visibility("default"))) void aiDecomposeMatrix(
    const struct aiMatrix4x4* mat,
    struct aiVector3D* scaling,
    struct aiQuaternion* rotation,
    struct aiVector3D* position);





__attribute__ ((visibility("default"))) void aiTransposeMatrix4(
    struct aiMatrix4x4* mat);





__attribute__ ((visibility("default"))) void aiTransposeMatrix3(
    struct aiMatrix3x3* mat);






__attribute__ ((visibility("default"))) void aiTransformVecByMatrix3(
    struct aiVector3D* vec,
    const struct aiMatrix3x3* mat);






__attribute__ ((visibility("default"))) void aiTransformVecByMatrix4(
    struct aiVector3D* vec,
    const struct aiMatrix4x4* mat);






__attribute__ ((visibility("default"))) void aiMultiplyMatrix4(
    struct aiMatrix4x4* dst,
    const struct aiMatrix4x4* src);






__attribute__ ((visibility("default"))) void aiMultiplyMatrix3(
    struct aiMatrix3x3* dst,
    const struct aiMatrix3x3* src);





__attribute__ ((visibility("default"))) void aiIdentityMatrix3(
    struct aiMatrix3x3* mat);





__attribute__ ((visibility("default"))) void aiIdentityMatrix4(
    struct aiMatrix4x4* mat);





__attribute__ ((visibility("default"))) size_t aiGetImportFormatCount(void);
__attribute__ ((visibility("default"))) const struct aiImporterDesc* aiGetImportFormatDescription( size_t pIndex);






struct aiTexel
{
    unsigned char b,g,r,a;
} __attribute__((__packed__));


struct aiTexture
{






    unsigned int mWidth;






    unsigned int mHeight;
    char achFormatHint[4];
    struct aiTexel* pcData;
};
struct aiFace
{


    unsigned int mNumIndices;


    unsigned int* mIndices;
};





struct aiVertexWeight
{

    unsigned int mVertexId;



    float mWeight;
};
struct aiBone
{

    struct aiString mName;



    unsigned int mNumWeights;


    struct aiVertexWeight* mWeights;


    struct aiMatrix4x4 mOffsetMatrix;
};
enum aiPrimitiveType
{





    aiPrimitiveType_POINT = 0x1,






    aiPrimitiveType_LINE = 0x2,





    aiPrimitiveType_TRIANGLE = 0x4,
    aiPrimitiveType_POLYGON = 0x8,






    _aiPrimitiveType_Force32Bit = 2147483647

};
struct aiAnimMesh
{






    struct aiVector3D* mVertices;


    struct aiVector3D* mNormals;


    struct aiVector3D* mTangents;


    struct aiVector3D* mBitangents;


    struct aiColor4D* mColors[0x8];


    struct aiVector3D* mTextureCoords[0x8];
    unsigned int mNumVertices;
};
struct aiMesh
{





    unsigned int mPrimitiveTypes;





    unsigned int mNumVertices;





    unsigned int mNumFaces;





    struct aiVector3D* mVertices;
    struct aiVector3D* mNormals;
    struct aiVector3D* mTangents;
    struct aiVector3D* mBitangents;






    struct aiColor4D* mColors[0x8];





    struct aiVector3D* mTextureCoords[0x8];
    unsigned int mNumUVComponents[0x8];







    struct aiFace* mFaces;




    unsigned int mNumBones;





    struct aiBone** mBones;






    unsigned int mMaterialIndex;
    struct aiString mName;



    unsigned int mNumAnimMeshes;




    struct aiAnimMesh** mAnimMeshes;
};
enum aiLightSourceType
{
    aiLightSource_UNDEFINED = 0x0,




    aiLightSource_DIRECTIONAL = 0x1,




    aiLightSource_POINT = 0x2,





    aiLightSource_SPOT = 0x3,






    aiLightSource_AMBIENT = 0x4,




    aiLightSource_AREA = 0x5,





    _aiLightSource_Force32Bit = 2147483647

};
struct aiLight
{






    struct aiString mName;





    enum aiLightSourceType mType;






    struct aiVector3D mPosition;







    struct aiVector3D mDirection;







    struct aiVector3D mUp;
    float mAttenuationConstant;
    float mAttenuationLinear;
    float mAttenuationQuadratic;







    struct aiColor3D mColorDiffuse;







    struct aiColor3D mColorSpecular;
    struct aiColor3D mColorAmbient;







    float mAngleInnerCone;
    float mAngleOuterCone;


    struct aiVector2D mSize;
};
struct aiCamera
{






    struct aiString mName;






    struct aiVector3D mPosition;
    struct aiVector3D mUp;
    struct aiVector3D mLookAt;
    float mHorizontalFOV;






    float mClipPlaneNear;
    float mClipPlaneFar;
    float mAspect;
};
enum aiTextureOp
{

    aiTextureOp_Multiply = 0x0,


    aiTextureOp_Add = 0x1,


    aiTextureOp_Subtract = 0x2,


    aiTextureOp_Divide = 0x3,


    aiTextureOp_SmoothAdd = 0x4,


    aiTextureOp_SignedAdd = 0x5,



    _aiTextureOp_Force32Bit = 2147483647

};






enum aiTextureMapMode
{


    aiTextureMapMode_Wrap = 0x0,




    aiTextureMapMode_Clamp = 0x1,




    aiTextureMapMode_Decal = 0x3,




    aiTextureMapMode_Mirror = 0x2,


    _aiTextureMapMode_Force32Bit = 2147483647

};
enum aiTextureMapping
{






    aiTextureMapping_UV = 0x0,


    aiTextureMapping_SPHERE = 0x1,


    aiTextureMapping_CYLINDER = 0x2,


    aiTextureMapping_BOX = 0x3,


    aiTextureMapping_PLANE = 0x4,


    aiTextureMapping_OTHER = 0x5,



    _aiTextureMapping_Force32Bit = 2147483647

};
enum aiTextureType
{






    aiTextureType_NONE = 0x0,






    aiTextureType_DIFFUSE = 0x1,




    aiTextureType_SPECULAR = 0x2,




    aiTextureType_AMBIENT = 0x3,




    aiTextureType_EMISSIVE = 0x4,






    aiTextureType_HEIGHT = 0x5,







    aiTextureType_NORMALS = 0x6,
    aiTextureType_SHININESS = 0x7,






    aiTextureType_OPACITY = 0x8,






    aiTextureType_DISPLACEMENT = 0x9,
    aiTextureType_LIGHTMAP = 0xA,






    aiTextureType_REFLECTION = 0xB,







    aiTextureType_UNKNOWN = 0xC,



    _aiTextureType_Force32Bit = 2147483647

};
enum aiShadingMode
{



    aiShadingMode_Flat = 0x1,



    aiShadingMode_Gouraud = 0x2,



    aiShadingMode_Phong = 0x3,



    aiShadingMode_Blinn = 0x4,





    aiShadingMode_Toon = 0x5,






    aiShadingMode_OrenNayar = 0x6,






    aiShadingMode_Minnaert = 0x7,





    aiShadingMode_CookTorrance = 0x8,



    aiShadingMode_NoShading = 0x9,



    aiShadingMode_Fresnel = 0xa,



    _aiShadingMode_Force32Bit = 2147483647

};
enum aiTextureFlags
{


    aiTextureFlags_Invert = 0x1,
    aiTextureFlags_UseAlpha = 0x2,






    aiTextureFlags_IgnoreAlpha = 0x4,


      _aiTextureFlags_Force32Bit = 2147483647

};
enum aiBlendMode
{






    aiBlendMode_Default = 0x0,
    aiBlendMode_Additive = 0x1,





    _aiBlendMode_Force32Bit = 2147483647

};



struct aiUVTransform
{




    struct aiVector2D mTranslation;





    struct aiVector2D mScaling;







    float mRotation;
} __attribute__((__packed__));








enum aiPropertyTypeInfo
{






    aiPTI_Float = 0x1,






    aiPTI_String = 0x3,







    aiPTI_Integer = 0x4,




    aiPTI_Buffer = 0x5,






     _aiPTI_Force32Bit = 2147483647

};
struct aiMaterialProperty
{



    struct aiString mKey;





    unsigned int mSemantic;




    unsigned int mIndex;




    unsigned int mDataLength;
    enum aiPropertyTypeInfo mType;




    char* mData;
};
struct aiMaterial

{
    struct aiMaterialProperty** mProperties;


    unsigned int mNumProperties;


    unsigned int mNumAllocated;
};
__attribute__ ((visibility("default"))) enum aiReturn aiGetMaterialProperty(
     const struct aiMaterial* pMat,
    const char* pKey,
     unsigned int type,
    unsigned int index,
    const struct aiMaterialProperty** pPropOut);
__attribute__ ((visibility("default"))) enum aiReturn aiGetMaterialFloatArray(
    const struct aiMaterial* pMat,
    const char* pKey,
    unsigned int type,
    unsigned int index,
    float* pOut,
    unsigned int* pMax);
__attribute__ ((visibility("default"))) enum aiReturn aiGetMaterialIntegerArray(const struct aiMaterial* pMat,
     const char* pKey,
     unsigned int type,
     unsigned int index,
     int* pOut,
     unsigned int* pMax);
__attribute__ ((visibility("default"))) enum aiReturn aiGetMaterialColor(const struct aiMaterial* pMat,
    const char* pKey,
    unsigned int type,
    unsigned int index,
    struct aiColor4D* pOut);







__attribute__ ((visibility("default"))) enum aiReturn aiGetMaterialUVTransform(const struct aiMaterial* pMat,
    const char* pKey,
    unsigned int type,
    unsigned int index,
    struct aiUVTransform* pOut);







__attribute__ ((visibility("default"))) enum aiReturn aiGetMaterialString(const struct aiMaterial* pMat,
    const char* pKey,
    unsigned int type,
    unsigned int index,
    struct aiString* pOut);
__attribute__ ((visibility("default"))) unsigned int aiGetMaterialTextureCount(const struct aiMaterial* pMat,
    enum aiTextureType type);
enum aiReturn aiGetMaterialTexture(const struct aiMaterial* mat,
    enum aiTextureType type,
    unsigned int index,
    struct aiString* path,
    enum aiTextureMapping* mapping ,
    unsigned int* uvindex ,
    float* blend ,
    enum aiTextureOp* op ,
    enum aiTextureMapMode* mapmode ,
    unsigned int* flags );
struct aiVectorKey
{

    double mTime;


    struct aiVector3D mValue;
};




struct aiQuatKey
{

    double mTime;


    struct aiQuaternion mValue;
};



struct aiMeshKey
{

    double mTime;





    unsigned int mValue;
};





enum aiAnimBehaviour
{

    aiAnimBehaviour_DEFAULT = 0x0,


    aiAnimBehaviour_CONSTANT = 0x1,



    aiAnimBehaviour_LINEAR = 0x2,





    aiAnimBehaviour_REPEAT = 0x3,






    _aiAnimBehaviour_Force32Bit = 2147483647

};
struct aiNodeAnim
{


    struct aiString mNodeName;


    unsigned int mNumPositionKeys;






    struct aiVectorKey* mPositionKeys;


    unsigned int mNumRotationKeys;







    struct aiQuatKey* mRotationKeys;



    unsigned int mNumScalingKeys;






    struct aiVectorKey* mScalingKeys;







    enum aiAnimBehaviour mPreState;






    enum aiAnimBehaviour mPostState;
};







struct aiMeshAnim
{




    struct aiString mName;


    unsigned int mNumKeys;


    struct aiMeshKey* mKeys;
};




struct aiAnimation
{



    struct aiString mName;


    double mDuration;


    double mTicksPerSecond;



    unsigned int mNumChannels;



    struct aiNodeAnim** mChannels;




    unsigned int mNumMeshChannels;



    struct aiMeshAnim** mMeshChannels;
};
void __assert_rtn(const char *, const char *, int, const char *) __attribute__((noreturn));





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
typedef long int intmax_t;
typedef long unsigned int uintmax_t;
typedef enum aiMetadataType
{
    AI_BOOL = 0,
    AI_INT = 1,
    AI_UINT64 = 2,
    AI_FLOAT = 3,
    AI_AISTRING = 4,
    AI_AIVECTOR3D = 5,


    FORCE_32BIT = 2147483647

} aiMetadataType;
struct aiMetadataEntry
{
    aiMetadataType mType;
    void* mData;
};
struct aiMetadata
{

    unsigned int mNumProperties;


    struct aiString* mKeys;



    struct aiMetadataEntry* mValues;
};
struct aiNode
{
    struct aiString mName;


    struct aiMatrix4x4 mTransformation;


    struct aiNode* mParent;


    unsigned int mNumChildren;


    struct aiNode** mChildren;


    unsigned int mNumMeshes;




    unsigned int* mMeshes;






    struct aiMetadata* mMetaData;
};
struct aiScene
{






    unsigned int mFlags;
    struct aiNode* mRootNode;




    unsigned int mNumMeshes;
    struct aiMesh** mMeshes;




    unsigned int mNumMaterials;
    struct aiMaterial** mMaterials;




    unsigned int mNumAnimations;






    struct aiAnimation** mAnimations;




    unsigned int mNumTextures;







    struct aiTexture** mTextures;





    unsigned int mNumLights;






    struct aiLight** mLights;





    unsigned int mNumCameras;
    struct aiCamera** mCameras;
    char* mPrivate;


};
enum aiPostProcessSteps
{
    aiProcess_CalcTangentSpace = 0x1,
    aiProcess_JoinIdenticalVertices = 0x2,
    aiProcess_MakeLeftHanded = 0x4,
    aiProcess_Triangulate = 0x8,
    aiProcess_RemoveComponent = 0x10,
    aiProcess_GenNormals = 0x20,
    aiProcess_GenSmoothNormals = 0x40,
    aiProcess_SplitLargeMeshes = 0x80,
    aiProcess_PreTransformVertices = 0x100,
    aiProcess_LimitBoneWeights = 0x200,
    aiProcess_ValidateDataStructure = 0x400,
    aiProcess_ImproveCacheLocality = 0x800,
    aiProcess_RemoveRedundantMaterials = 0x1000,
    aiProcess_FixInfacingNormals = 0x2000,
    aiProcess_SortByPType = 0x8000,
    aiProcess_FindDegenerates = 0x10000,
    aiProcess_FindInvalidData = 0x20000,
    aiProcess_GenUVCoords = 0x40000,
    aiProcess_TransformUVCoords = 0x80000,
    aiProcess_FindInstances = 0x100000,
    aiProcess_OptimizeMeshes = 0x200000,
    aiProcess_OptimizeGraph = 0x400000,
    aiProcess_FlipUVs = 0x800000,
    aiProcess_FlipWindingOrder = 0x1000000,





    aiProcess_SplitByBoneCount = 0x2000000,
    aiProcess_Debone = 0x4000000




};

