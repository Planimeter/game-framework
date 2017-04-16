

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
extern ILboolean iluEqualize2(void);
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
extern ILboolean iluSepia(void);
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
