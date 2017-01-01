
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


// struct __darwin_pthread_handler_rec {
//  void (*__routine)(void *);
//  void *__arg;
//  struct __darwin_pthread_handler_rec *__next;
// };

// struct _opaque_pthread_attr_t {
//  long __sig;
//  char __opaque[56];
// };

// struct _opaque_pthread_cond_t {
//  long __sig;
//  char __opaque[40];
// };

// struct _opaque_pthread_condattr_t {
//  long __sig;
//  char __opaque[8];
// };

// struct _opaque_pthread_mutex_t {
//  long __sig;
//  char __opaque[56];
// };

// struct _opaque_pthread_mutexattr_t {
//  long __sig;
//  char __opaque[8];
// };

// struct _opaque_pthread_once_t {
//  long __sig;
//  char __opaque[8];
// };

// struct _opaque_pthread_rwlock_t {
//  long __sig;
//  char __opaque[192];
// };

// struct _opaque_pthread_rwlockattr_t {
//  long __sig;
//  char __opaque[16];
// };

// struct _opaque_pthread_t {
//  long __sig;
//  struct __darwin_pthread_handler_rec *__cleanup_stack;
//  char __opaque[8176];
// };

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



typedef __darwin_va_list va_list;
typedef __darwin_size_t size_t;

int renameat(int, const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));






int renamex_np(const char *, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int renameatx_np(int, const char *, int, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));

typedef __darwin_off_t fpos_t;
// struct __sbuf {
//  unsigned char *_base;
//  int _size;
// };


struct __sFILEX;
// typedef struct __sFILE {
//  unsigned char *_p;
//  int _r;
//  int _w;
//  short _flags;
//  short _file;
//  struct __sbuf _bf;
//  int _lbfsize;
//
//
//  void *_cookie;
//  int (* _Nullable _close)(void *);
//  int (* _Nullable _read) (void *, char *, int);
//  fpos_t (* _Nullable _seek) (void *, fpos_t, int);
//  int (* _Nullable _write)(void *, const char *, int);
//
//
//  struct __sbuf _ub;
//  struct __sFILEX *_extra;
//  int _ur;
//
//
//  unsigned char _ubuf[3];
//  unsigned char _nbuf[1];
//
//
//  struct __sbuf _lb;
//
//
//  int _blksize;
//  fpos_t _offset;
// } FILE;


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
typedef __darwin_ssize_t ssize_t;


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




enum
{
   STBI_default = 0,

   STBI_grey = 1,
   STBI_grey_alpha = 2,
   STBI_rgb = 3,
   STBI_rgb_alpha = 4
};

typedef unsigned char stbi_uc;
typedef unsigned short stbi_us;
typedef struct
{
   int (*read) (void *user,char *data,int size);
   void (*skip) (void *user,int n);
   int (*eof) (void *user);
} stbi_io_callbacks;






extern stbi_uc *stbi_load (char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
extern stbi_uc *stbi_load_from_memory (stbi_uc const *buffer, int len , int *x, int *y, int *channels_in_file, int desired_channels);
extern stbi_uc *stbi_load_from_callbacks(stbi_io_callbacks const *clbk , void *user, int *x, int *y, int *channels_in_file, int desired_channels);


extern stbi_uc *stbi_load_from_file (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
extern stbi_us *stbi_load_16(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);

extern stbi_us *stbi_load_from_file_16(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
   extern float *stbi_loadf (char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
   extern float *stbi_loadf_from_memory (stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
   extern float *stbi_loadf_from_callbacks (stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *channels_in_file, int desired_channels);


   extern float *stbi_loadf_from_file (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);




   extern void stbi_hdr_to_ldr_gamma(float gamma);
   extern void stbi_hdr_to_ldr_scale(float scale);



   extern void stbi_ldr_to_hdr_gamma(float gamma);
   extern void stbi_ldr_to_hdr_scale(float scale);



extern int stbi_is_hdr_from_callbacks(stbi_io_callbacks const *clbk, void *user);
extern int stbi_is_hdr_from_memory(stbi_uc const *buffer, int len);

extern int stbi_is_hdr (char const *filename);
extern int stbi_is_hdr_from_file(FILE *f);





extern const char *stbi_failure_reason (void);


extern void stbi_image_free (void *retval_from_stbi_load);


extern int stbi_info_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *comp);
extern int stbi_info_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *comp);


extern int stbi_info (char const *filename, int *x, int *y, int *comp);
extern int stbi_info_from_file (FILE *f, int *x, int *y, int *comp);
extern void stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremultiply);



extern void stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert);


extern void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);



extern char *stbi_zlib_decode_malloc_guesssize(const char *buffer, int len, int initial_size, int *outlen);
extern char *stbi_zlib_decode_malloc_guesssize_headerflag(const char *buffer, int len, int initial_size, int *outlen, int parse_header);
extern char *stbi_zlib_decode_malloc(const char *buffer, int len, int *outlen);
extern int stbi_zlib_decode_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);

extern char *stbi_zlib_decode_noheader_malloc(const char *buffer, int len, int *outlen);
extern int stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);
