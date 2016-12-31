
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

typedef unsigned int ILenum;
typedef unsigned char ILboolean;
typedef unsigned int ILbitfield;
typedef signed char ILbyte;
typedef signed short ILshort;
typedef int ILint;
typedef size_t ILsizei;
typedef unsigned char ILubyte;
typedef unsigned short ILushort;
typedef unsigned int ILuint;
typedef float ILfloat;
typedef float ILclampf;
typedef double ILdouble;
typedef double ILclampd;





typedef long long int ILint64;
typedef long long unsigned int ILuint64;









typedef void* ILHANDLE;
typedef void ( *fCloseRProc)(ILHANDLE);
typedef ILboolean ( *fEofProc) (ILHANDLE);
typedef ILint ( *fGetcProc) (ILHANDLE);
typedef ILHANDLE ( *fOpenRProc) (char const *);
typedef ILint ( *fReadProc) (void*, ILuint, ILuint, ILHANDLE);
typedef ILint ( *fSeekRProc) (ILHANDLE, ILint, ILint);
typedef ILint ( *fTellRProc) (ILHANDLE);


typedef void ( *fCloseWProc)(ILHANDLE);
typedef ILHANDLE ( *fOpenWProc) (char const *);
typedef ILint ( *fPutcProc) (ILubyte, ILHANDLE);
typedef ILint ( *fSeekWProc) (ILHANDLE, ILint, ILint);
typedef ILint ( *fTellWProc) (ILHANDLE);
typedef ILint ( *fWriteProc) (const void*, ILuint, ILuint, ILHANDLE);


typedef void* ( *mAlloc)(const ILsizei);
typedef void ( *mFree) (const void* const);


typedef ILenum ( *IL_LOADPROC)(char const *);
typedef ILenum ( *IL_SAVEPROC)(char const *);



extern ILboolean ilActiveFace(ILuint Number);
extern ILboolean ilActiveImage(ILuint Number);
extern ILboolean ilActiveLayer(ILuint Number);
extern ILboolean ilActiveMipmap(ILuint Number);
extern ILboolean ilApplyPal(char const * FileName);
extern ILboolean ilApplyProfile(char* InProfile, char* OutProfile);
extern void ilBindImage(ILuint Image);
extern ILboolean ilBlit(ILuint Source, ILint DestX, ILint DestY, ILint DestZ, ILuint SrcX, ILuint SrcY, ILuint SrcZ, ILuint Width, ILuint Height, ILuint Depth);
extern ILboolean ilClampNTSC(void);
extern void ilClearColour(ILclampf Red, ILclampf Green, ILclampf Blue, ILclampf Alpha);
extern ILboolean ilClearImage(void);
extern ILuint ilCloneCurImage(void);
extern ILubyte* ilCompressDXT(ILubyte *Data, ILuint Width, ILuint Height, ILuint Depth, ILenum DXTCFormat, ILuint *DXTCSize);
extern ILboolean ilCompressFunc(ILenum Mode);
extern ILboolean ilConvertImage(ILenum DestFormat, ILenum DestType);
extern ILboolean ilConvertPal(ILenum DestFormat);
extern ILboolean ilCopyImage(ILuint Src);
extern ILuint ilCopyPixels(ILuint XOff, ILuint YOff, ILuint ZOff, ILuint Width, ILuint Height, ILuint Depth, ILenum Format, ILenum Type, void *Data);
extern ILuint ilCreateSubImage(ILenum Type, ILuint Num);
extern ILboolean ilDefaultImage(void);
extern void ilDeleteImage(const ILuint Num);
extern void ilDeleteImages(ILsizei Num, const ILuint *Images);
extern ILenum ilDetermineType(char const * FileName);
extern ILenum ilDetermineTypeF(ILHANDLE File);
extern ILenum ilDetermineTypeL(const void *Lump, ILuint Size);
extern ILboolean ilDisable(ILenum Mode);
extern ILboolean ilDxtcDataToImage(void);
extern ILboolean ilDxtcDataToSurface(void);
extern ILboolean ilEnable(ILenum Mode);
extern void ilFlipSurfaceDxtcData(void);
extern ILboolean ilFormatFunc(ILenum Mode);
extern void ilGenImages(ILsizei Num, ILuint *Images);
extern ILuint ilGenImage(void);
extern ILubyte* ilGetAlpha(ILenum Type);
extern ILboolean ilGetBoolean(ILenum Mode);
extern void ilGetBooleanv(ILenum Mode, ILboolean *Param);
extern ILubyte* ilGetData(void);
extern ILuint ilGetDXTCData(void *Buffer, ILuint BufferSize, ILenum DXTCFormat);
extern ILenum ilGetError(void);
extern ILint ilGetInteger(ILenum Mode);
extern void ilGetIntegerv(ILenum Mode, ILint *Param);
extern ILuint ilGetLumpPos(void);
extern ILubyte* ilGetPalette(void);
extern char const * ilGetString(ILenum StringName);
extern void ilHint(ILenum Target, ILenum Mode);
extern ILboolean ilInvertSurfaceDxtcDataAlpha(void);
extern void ilInit(void);
extern ILboolean ilImageToDxtcData(ILenum Format);
extern ILboolean ilIsDisabled(ILenum Mode);
extern ILboolean ilIsEnabled(ILenum Mode);
extern ILboolean ilIsImage(ILuint Image);
extern ILboolean ilIsValid(ILenum Type, char const * FileName);
extern ILboolean ilIsValidF(ILenum Type, ILHANDLE File);
extern ILboolean ilIsValidL(ILenum Type, void *Lump, ILuint Size);
extern void ilKeyColour(ILclampf Red, ILclampf Green, ILclampf Blue, ILclampf Alpha);
extern ILboolean ilLoad(ILenum Type, char const * FileName);
extern ILboolean ilLoadF(ILenum Type, ILHANDLE File);
extern ILboolean ilLoadImage(char const * FileName);
extern ILboolean ilLoadL(ILenum Type, const void *Lump, ILuint Size);
extern ILboolean ilLoadPal(char const * FileName);
extern void ilModAlpha(ILdouble AlphaValue);
extern ILboolean ilOriginFunc(ILenum Mode);
extern ILboolean ilOverlayImage(ILuint Source, ILint XCoord, ILint YCoord, ILint ZCoord);
extern void ilPopAttrib(void);
extern void ilPushAttrib(ILuint Bits);
extern void ilRegisterFormat(ILenum Format);
extern ILboolean ilRegisterLoad(char const * Ext, IL_LOADPROC Load);
extern ILboolean ilRegisterMipNum(ILuint Num);
extern ILboolean ilRegisterNumFaces(ILuint Num);
extern ILboolean ilRegisterNumImages(ILuint Num);
extern void ilRegisterOrigin(ILenum Origin);
extern void ilRegisterPal(void *Pal, ILuint Size, ILenum Type);
extern ILboolean ilRegisterSave(char const * Ext, IL_SAVEPROC Save);
extern void ilRegisterType(ILenum Type);
extern ILboolean ilRemoveLoad(char const * Ext);
extern ILboolean ilRemoveSave(char const * Ext);
extern void ilResetMemory(void);
extern void ilResetRead(void);
extern void ilResetWrite(void);
extern ILboolean ilSave(ILenum Type, char const * FileName);
extern ILuint ilSaveF(ILenum Type, ILHANDLE File);
extern ILboolean ilSaveImage(char const * FileName);
extern ILuint ilSaveL(ILenum Type, void *Lump, ILuint Size);
extern ILboolean ilSavePal(char const * FileName);
extern ILboolean ilSetAlpha(ILdouble AlphaValue);
extern ILboolean ilSetData(void *Data);
extern ILboolean ilSetDuration(ILuint Duration);
extern void ilSetInteger(ILenum Mode, ILint Param);
extern void ilSetMemory(mAlloc, mFree);
extern void ilSetPixels(ILint XOff, ILint YOff, ILint ZOff, ILuint Width, ILuint Height, ILuint Depth, ILenum Format, ILenum Type, void *Data);
extern void ilSetRead(fOpenRProc, fCloseRProc, fEofProc, fGetcProc, fReadProc, fSeekRProc, fTellRProc);
extern void ilSetString(ILenum Mode, const char *String);
extern void ilSetWrite(fOpenWProc, fCloseWProc, fPutcProc, fSeekWProc, fTellWProc, fWriteProc);
extern void ilShutDown(void);
extern ILboolean ilSurfaceToDxtcData(ILenum Format);
extern ILboolean ilTexImage(ILuint Width, ILuint Height, ILuint Depth, ILubyte NumChannels, ILenum Format, ILenum Type, void *Data);
extern ILboolean ilTexImageDxtc(ILint w, ILint h, ILint d, ILenum DxtFormat, const ILubyte* data);
extern ILenum ilTypeFromExt(char const * FileName);
extern ILboolean ilTypeFunc(ILenum Mode);
extern ILboolean ilLoadData(char const * FileName, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
extern ILboolean ilLoadDataF(ILHANDLE File, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
extern ILboolean ilLoadDataL(void *Lump, ILuint Size, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
extern ILboolean ilSaveData(char const * FileName);
typedef struct ILinfo
{
 ILuint Id;
 ILubyte *Data;
 ILuint Width;
 ILuint Height;
 ILuint Depth;
 ILubyte Bpp;
 ILuint SizeOfData;
 ILenum Format;
 ILenum Type;
 ILenum Origin;
 ILubyte *Palette;
 ILenum PalType;
 ILuint PalSize;
 ILenum CubeFlags;
 ILuint NumNext;
 ILuint NumMips;
 ILuint NumLayers;
} ILinfo;


typedef struct ILpointf {
 ILfloat x;
 ILfloat y;
} ILpointf;

typedef struct ILpointi {
 ILint x;
 ILint y;
} ILpointi;

extern ILboolean iluAlienify(void);
extern ILboolean iluBlurAvg(ILuint Iter);
extern ILboolean iluBlurGaussian(ILuint Iter);
extern ILboolean iluBuildMipmaps(void);
extern ILuint iluColoursUsed(void);
extern ILboolean iluCompareImage(ILuint Comp);
extern ILboolean iluContrast(ILfloat Contrast);
extern ILboolean iluCrop(ILuint XOff, ILuint YOff, ILuint ZOff, ILuint Width, ILuint Height, ILuint Depth);
extern void iluDeleteImage(ILuint Id);
extern ILboolean iluEdgeDetectE(void);
extern ILboolean iluEdgeDetectP(void);
extern ILboolean iluEdgeDetectS(void);
extern ILboolean iluEmboss(void);
extern ILboolean iluEnlargeCanvas(ILuint Width, ILuint Height, ILuint Depth);
extern ILboolean iluEnlargeImage(ILfloat XDim, ILfloat YDim, ILfloat ZDim);
extern ILboolean iluEqualize(void);
extern char const * iluErrorString(ILenum Error);
extern ILboolean iluConvolution(ILint *matrix, ILint scale, ILint bias);
extern ILboolean iluFlipImage(void);
extern ILboolean iluGammaCorrect(ILfloat Gamma);
extern ILuint iluGenImage(void);
extern void iluGetImageInfo(ILinfo *Info);
extern ILint iluGetInteger(ILenum Mode);
extern void iluGetIntegerv(ILenum Mode, ILint *Param);
extern char* iluGetString(ILenum StringName);
extern void iluImageParameter(ILenum PName, ILenum Param);
extern void iluInit(void);
extern ILboolean iluInvertAlpha(void);
extern ILuint iluLoadImage(char const * FileName);
extern ILboolean iluMirror(void);
extern ILboolean iluNegative(void);
extern ILboolean iluNoisify(ILclampf Tolerance);
extern ILboolean iluPixelize(ILuint PixSize);
extern void iluRegionfv(ILpointf *Points, ILuint n);
extern void iluRegioniv(ILpointi *Points, ILuint n);
extern ILboolean iluReplaceColour(ILubyte Red, ILubyte Green, ILubyte Blue, ILfloat Tolerance);
extern ILboolean iluRotate(ILfloat Angle);
extern ILboolean iluRotate3D(ILfloat x, ILfloat y, ILfloat z, ILfloat Angle);
extern ILboolean iluSaturate1f(ILfloat Saturation);
extern ILboolean iluSaturate4f(ILfloat r, ILfloat g, ILfloat b, ILfloat Saturation);
extern ILboolean iluScale(ILuint Width, ILuint Height, ILuint Depth);
extern ILboolean iluScaleAlpha(ILfloat scale);
extern ILboolean iluScaleColours(ILfloat r, ILfloat g, ILfloat b);
extern ILboolean iluSetLanguage(ILenum Language);
extern ILboolean iluSharpen(ILfloat Factor, ILuint Iter);
extern ILboolean iluSwapColours(void);
extern ILboolean iluWave(ILfloat Angle);
extern ILboolean ilutDisable(ILenum Mode);
extern ILboolean ilutEnable(ILenum Mode);
extern ILboolean ilutGetBoolean(ILenum Mode);
extern void ilutGetBooleanv(ILenum Mode, ILboolean *Param);
extern ILint ilutGetInteger(ILenum Mode);
extern void ilutGetIntegerv(ILenum Mode, ILint *Param);
extern char* ilutGetString(ILenum StringName);
extern void ilutInit(void);
extern ILboolean ilutIsDisabled(ILenum Mode);
extern ILboolean ilutIsEnabled(ILenum Mode);
extern void ilutPopAttrib(void);
extern void ilutPushAttrib(ILuint Bits);
extern void ilutSetInteger(ILenum Mode, ILint Param);

extern ILboolean ilutRenderer(ILenum Renderer);
