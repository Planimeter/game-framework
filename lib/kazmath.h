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
extern float kmSQR(float s);
extern float kmDegreesToRadians(float degrees);
extern float kmRadiansToDegrees(float radians);

extern float kmMin(float lhs, float rhs);
extern float kmMax(float lhs, float rhs);
extern unsigned char kmAlmostEqual(float lhs, float rhs);

extern float kmClamp(float x, float min, float max);
extern float kmLerp(float x, float y, float factor);

struct kmMat3;

typedef struct kmVec2 {
    float x;
    float y;
} kmVec2;






kmVec2* kmVec2Fill(kmVec2* pOut, float x, float y);
float kmVec2Length(const kmVec2* pIn);
float kmVec2LengthSq(const kmVec2* pIn);
kmVec2* kmVec2Normalize(kmVec2* pOut, const kmVec2* pIn);
kmVec2* kmVec2Lerp(kmVec2* pOut, const kmVec2* pV1, const kmVec2* pV2, float t);
kmVec2* kmVec2Add(kmVec2* pOut, const kmVec2* pV1, const kmVec2* pV2);
float kmVec2Dot(const kmVec2* pV1, const kmVec2* pV2);
float kmVec2Cross(const kmVec2* pV1, const kmVec2* pV2);
kmVec2* kmVec2Subtract(kmVec2* pOut, const kmVec2* pV1, const kmVec2* pV2);
kmVec2* kmVec2Mul( kmVec2* pOut,const kmVec2* pV1, const kmVec2* pV2 );
kmVec2* kmVec2Div( kmVec2* pOut,const kmVec2* pV1, const kmVec2* pV2 );
kmVec2* kmVec2Transform(kmVec2* pOut, const kmVec2* pV1, const struct kmMat3* pM);
kmVec2* kmVec2TransformCoord(kmVec2* pOut, const kmVec2* pV, const struct kmMat3* pM);
kmVec2* kmVec2Scale(kmVec2* pOut, const kmVec2* pIn, const float s);
unsigned char kmVec2AreEqual(const kmVec2* p1, const kmVec2* p2);
kmVec2* kmVec2Assign(kmVec2* pOut, const kmVec2* pIn);
kmVec2* kmVec2RotateBy(kmVec2* pOut, const kmVec2* pIn, const float degrees, const kmVec2* center);
float kmVec2DegreesBetween(const kmVec2* v1, const kmVec2* v2);
float kmVec2DistanceBetween(const kmVec2* v1, const kmVec2* v2);
kmVec2* kmVec2MidPointBetween(kmVec2* pOut, const kmVec2* v1, const kmVec2* v2);
kmVec2* kmVec2Reflect(kmVec2* pOut, const kmVec2* pIn, const kmVec2* normal);

void kmVec2Swap(kmVec2* pA, kmVec2* pB);

extern const kmVec2 KM_VEC2_POS_Y;
extern const kmVec2 KM_VEC2_NEG_Y;
extern const kmVec2 KM_VEC2_NEG_X;
extern const kmVec2 KM_VEC2_POS_X;
extern const kmVec2 KM_VEC2_ZERO;
void __assert_rtn(const char *, const char *, int, const char *) __attribute__((noreturn));


struct kmMat4;
struct kmMat3;
struct kmPlane;

typedef struct kmVec3 {
 float x;
 float y;
 float z;
} kmVec3;





kmVec3* kmVec3Fill(kmVec3* pOut, float x, float y, float z);
float kmVec3Length(const kmVec3* pIn);
float kmVec3LengthSq(const kmVec3* pIn);
kmVec3* kmVec3Lerp(kmVec3* pOut, const kmVec3* pV1, const kmVec3* pV2, float t);
kmVec3* kmVec3Normalize(kmVec3* pOut, const kmVec3* pIn);
kmVec3* kmVec3Cross(kmVec3* pOut, const kmVec3* pV1, const kmVec3* pV2);
float kmVec3Dot(const kmVec3* pV1, const kmVec3* pV2);
kmVec3* kmVec3Add(kmVec3* pOut, const kmVec3* pV1, const kmVec3* pV2);
kmVec3* kmVec3Subtract(kmVec3* pOut, const kmVec3* pV1, const kmVec3* pV2);
kmVec3* kmVec3Mul( kmVec3* pOut,const kmVec3* pV1, const kmVec3* pV2 );
kmVec3* kmVec3Div( kmVec3* pOut,const kmVec3* pV1, const kmVec3* pV2 );

kmVec3* kmVec3MultiplyMat3(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat3* pM);
kmVec3* kmVec3MultiplyMat4(kmVec3* pOut, const kmVec3* pV, const struct kmMat4* pM);

kmVec3* kmVec3Transform(kmVec3* pOut, const kmVec3* pV1, const struct kmMat4* pM);
kmVec3* kmVec3TransformNormal(kmVec3* pOut, const kmVec3* pV, const struct kmMat4* pM);
kmVec3* kmVec3TransformCoord(kmVec3* pOut, const kmVec3* pV, const struct kmMat4* pM);

kmVec3* kmVec3Scale(kmVec3* pOut, const kmVec3* pIn, const float s);
unsigned char kmVec3AreEqual(const kmVec3* p1, const kmVec3* p2);
kmVec3* kmVec3InverseTransform(kmVec3* pOut, const kmVec3* pV, const struct kmMat4* pM);
kmVec3* kmVec3InverseTransformNormal(kmVec3* pOut, const kmVec3* pVect, const struct kmMat4* pM);
kmVec3* kmVec3Assign(kmVec3* pOut, const kmVec3* pIn);
kmVec3* kmVec3Zero(kmVec3* pOut);
kmVec3* kmVec3GetHorizontalAngle(kmVec3* pOut, const kmVec3 *pIn);
kmVec3* kmVec3RotationToDirection(kmVec3* pOut, const kmVec3* pIn, const kmVec3* forwards);

kmVec3* kmVec3ProjectOnToPlane(kmVec3* pOut, const kmVec3* point, const struct kmPlane* plane);
kmVec3* kmVec3ProjectOnToVec3(const kmVec3* pIn, const kmVec3* other, kmVec3* projection);

kmVec3* kmVec3Reflect(kmVec3* pOut, const kmVec3* pIn, const kmVec3* normal);

void kmVec3Swap(kmVec3* a, kmVec3* b);
void kmVec3OrthoNormalize(kmVec3* normal, kmVec3* tangent);

extern const kmVec3 KM_VEC3_NEG_Z;
extern const kmVec3 KM_VEC3_POS_Z;
extern const kmVec3 KM_VEC3_POS_Y;
extern const kmVec3 KM_VEC3_NEG_Y;
extern const kmVec3 KM_VEC3_NEG_X;
extern const kmVec3 KM_VEC3_POS_X;
extern const kmVec3 KM_VEC3_ZERO;
struct kmVec3;
struct kmQuaternion;
struct kmMat4;

typedef struct kmMat3{
 float mat[9];
} kmMat3;





kmMat3* kmMat3Fill(kmMat3* pOut, const float* pMat);
kmMat3* kmMat3Adjugate(kmMat3* pOut, const kmMat3* pIn);
kmMat3* kmMat3Identity(kmMat3* pOut);
kmMat3* kmMat3Inverse(kmMat3* pOut, const kmMat3* pM);
unsigned char kmMat3IsIdentity(const kmMat3* pIn);
kmMat3* kmMat3Transpose(kmMat3* pOut, const kmMat3* pIn);
float kmMat3Determinant(const kmMat3* pIn);
unsigned char kmMat3AreEqual(const kmMat3* pMat1, const kmMat3* pMat2);

kmMat3* kmMat3AssignMat3(kmMat3* pOut, const kmMat3* pIn);

kmMat3* kmMat3MultiplyMat3(kmMat3* pOut, const kmMat3* lhs, const kmMat3* rhs);
kmMat3* kmMat3MultiplyScalar(kmMat3* pOut, const kmMat3* lhs, const float rhs);

kmMat3* kmMat3FromRotationX(kmMat3* pOut, const float radians);
kmMat3* kmMat3FromRotationY(kmMat3* pOut, const float radians);
kmMat3* kmMat3FromRotationZ(kmMat3* pOut, const float radians);
kmMat3* kmMat3FromRotationXInDegrees(kmMat3* pOut, const float degrees);
kmMat3* kmMat3FromRotationYInDegrees(kmMat3* pOut, const float degrees);
kmMat3* kmMat3FromRotationZInDegrees(kmMat3* pOut, const float degrees);
kmMat3* kmMat3FromRotationQuaternion(kmMat3* pOut, const struct kmQuaternion* quaternion);
kmMat3* kmMat3FromRotationLookAt(kmMat3* pOut, const struct kmVec3* pEye, const struct kmVec3* pCentre, const struct kmVec3* pUp);
kmMat3* kmMat3FromScaling(kmMat3* pOut, const float x, const float y);
kmMat3* kmMat3FromTranslation(kmMat3* pOut, const float x, const float y);
kmMat3* kmMat3FromRotationAxisAngle(kmMat3* pOut, const struct kmVec3* axis, const float radians);
kmMat3* kmMat3FromRotationAxisAngleInDegrees(kmMat3* pOut, const struct kmVec3* axis, const float degrees);

void kmMat3ExtractRotationAxisAngle(const kmMat3* self, struct kmVec3* axis, float* radians);
void kmMat3ExtractRotationAxisAngleInDegrees(const kmMat3* self, struct kmVec3* axis, float* degrees);

struct kmVec3* kmMat3ExtractUpVec3(const kmMat3* self, struct kmVec3* pOut);
struct kmVec3* kmMat3ExtractRightVec3(const kmMat3* self, struct kmVec3* pOut);
struct kmVec3* kmMat3ExtractForwardVec3(const kmMat3* self, struct kmVec3* pOut);
struct kmVec3;
struct kmMat3;
struct kmQuaternion;
struct kmPlane;
typedef struct kmMat4 {
 float mat[16];
} kmMat4;

kmMat4* kmMat4Fill(kmMat4* pOut, const float* pMat);


kmMat4* kmMat4Identity(kmMat4* pOut);

kmMat4* kmMat4Inverse(kmMat4* pOut, const kmMat4* pM);


int kmMat4IsIdentity(const kmMat4* pIn);

kmMat4* kmMat4Transpose(kmMat4* pOut, const kmMat4* pIn);
kmMat4* kmMat4Multiply(kmMat4* pOut, const kmMat4* pM1, const kmMat4* pM2);

kmMat4* kmMat4Assign(kmMat4* pOut, const kmMat4* pIn);
kmMat4* kmMat4AssignMat3(kmMat4* pOut, const struct kmMat3* pIn);

int kmMat4AreEqual(const kmMat4* pM1, const kmMat4* pM2);

kmMat4* kmMat4RotationX(kmMat4* pOut, const float radians);
kmMat4* kmMat4RotationY(kmMat4* pOut, const float radians);
kmMat4* kmMat4RotationZ(kmMat4* pOut, const float radians);
kmMat4* kmMat4RotationYawPitchRoll(kmMat4* pOut, const float pitch, const float yaw, const float roll);
kmMat4* kmMat4RotationQuaternion(kmMat4* pOut, const struct kmQuaternion* pQ);
kmMat4* kmMat4RotationTranslation(kmMat4* pOut, const struct kmMat3* rotation, const struct kmVec3* translation);
kmMat4* kmMat4Scaling(kmMat4* pOut, const float x, const float y, const float z);
kmMat4* kmMat4Translation(kmMat4* pOut, const float x, const float y, const float z);

struct kmVec3* kmMat4GetUpVec3(struct kmVec3* pOut, const kmMat4* pIn);
struct kmVec3* kmMat4GetRightVec3(struct kmVec3* pOut, const kmMat4* pIn);
struct kmVec3* kmMat4GetForwardVec3RH(struct kmVec3* pOut, const kmMat4* pIn);
struct kmVec3* kmMat4GetForwardVec3LH(struct kmVec3* pOut, const kmMat4* pIn);

kmMat4* kmMat4PerspectiveProjection(kmMat4* pOut, float fovY, float aspect, float zNear, float zFar);
kmMat4* kmMat4OrthographicProjection(kmMat4* pOut, float left, float right, float bottom, float top, float nearVal, float farVal);
kmMat4* kmMat4LookAt(kmMat4* pOut, const struct kmVec3* pEye, const struct kmVec3* pCenter, const struct kmVec3* pUp);

kmMat4* kmMat4RotationAxisAngle(kmMat4* pOut, const struct kmVec3* axis, float radians);
struct kmMat3* kmMat4ExtractRotationMat3(const kmMat4* pIn, struct kmMat3* pOut);
struct kmPlane* kmMat4ExtractPlane(struct kmPlane* pOut, const kmMat4* pIn, const unsigned int plane);
struct kmVec3* kmMat4RotationToAxisAngle(struct kmVec3* pAxis, float* radians, const kmMat4* pIn);
struct kmVec3* kmMat4ExtractTranslationVec3(const kmMat4* pIn, struct kmVec3* pOut);

struct kmMat4;
struct kmMat3;
struct kmVec3;

typedef struct kmQuaternion {
 float x;
 float y;
 float z;
 float w;
} kmQuaternion;

int kmQuaternionAreEqual(const kmQuaternion* p1, const kmQuaternion* p2);
kmQuaternion* kmQuaternionFill(kmQuaternion* pOut, float x, float y, float z, float w);
float kmQuaternionDot(const kmQuaternion* q1, const kmQuaternion* q2);

kmQuaternion* kmQuaternionExp(kmQuaternion* pOut, const kmQuaternion* pIn);



kmQuaternion* kmQuaternionIdentity(kmQuaternion* pOut);



kmQuaternion* kmQuaternionInverse(kmQuaternion* pOut, const kmQuaternion* pIn);



int kmQuaternionIsIdentity(const kmQuaternion* pIn);



float kmQuaternionLength(const kmQuaternion* pIn);



float kmQuaternionLengthSq(const kmQuaternion* pIn);



kmQuaternion* kmQuaternionLn(kmQuaternion* pOut, const kmQuaternion* pIn);



kmQuaternion* kmQuaternionMultiply(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2);



kmQuaternion* kmQuaternionNormalize(kmQuaternion* pOut, const kmQuaternion* pIn);



kmQuaternion* kmQuaternionRotationAxisAngle(kmQuaternion* pOut, const struct kmVec3* pV, float angle);



kmQuaternion* kmQuaternionRotationMatrix(kmQuaternion* pOut, const struct kmMat3* pIn);



kmQuaternion* kmQuaternionRotationPitchYawRoll(kmQuaternion* pOut, float pitch, float yaw, float roll);

kmQuaternion* kmQuaternionSlerp(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2, float t);


void kmQuaternionToAxisAngle(const kmQuaternion* pIn, struct kmVec3* pVector, float* pAngle);


kmQuaternion* kmQuaternionScale(kmQuaternion* pOut, const kmQuaternion* pIn, float s);
kmQuaternion* kmQuaternionAssign(kmQuaternion* pOut, const kmQuaternion* pIn);
kmQuaternion* kmQuaternionAdd(kmQuaternion* pOut, const kmQuaternion* pQ1, const kmQuaternion* pQ2);
kmQuaternion* kmQuaternionSubtract(kmQuaternion* pOut, const kmQuaternion* pQ1, const kmQuaternion* pQ2);

kmQuaternion* kmQuaternionRotationBetweenVec3(kmQuaternion* pOut, const struct kmVec3* vec1, const struct kmVec3* vec2, const struct kmVec3* fallback);
struct kmVec3* kmQuaternionMultiplyVec3(struct kmVec3* pOut, const kmQuaternion* q, const struct kmVec3* v);

kmVec3* kmQuaternionGetUpVec3(kmVec3* pOut, const kmQuaternion* pIn);
kmVec3* kmQuaternionGetRightVec3(kmVec3* pOut, const kmQuaternion* pIn);
kmVec3* kmQuaternionGetForwardVec3RH(kmVec3* pOut, const kmQuaternion* pIn);
kmVec3* kmQuaternionGetForwardVec3LH(kmVec3* pOut, const kmQuaternion* pIn);

float kmQuaternionGetPitch(const kmQuaternion* q);
float kmQuaternionGetYaw(const kmQuaternion* q);
float kmQuaternionGetRoll(const kmQuaternion* q);

kmQuaternion* kmQuaternionLookRotation(kmQuaternion* pOut, const kmVec3* direction, const kmVec3* up);
kmQuaternion* kmQuaternionExtractRotationAroundAxis(const kmQuaternion* pIn, const kmVec3* axis, kmQuaternion* pOut);
kmQuaternion* kmQuaternionBetweenVec3(kmQuaternion* pOut, const kmVec3* v1, const kmVec3* v2);
struct kmVec3;
struct kmVec4;
struct kmMat4;

typedef struct kmPlane {
 float a, b, c, d;
} kmPlane;





typedef enum KM_POINT_CLASSIFICATION {
    POINT_BEHIND_PLANE = -1,
    POINT_ON_PLANE = 0,
    POINT_INFRONT_OF_PLANE = 1
} KM_POINT_CLASSIFICATION;

kmPlane* kmPlaneFill(kmPlane* plane, float a, float b, float c, float d);
float kmPlaneDot(const kmPlane* pP, const struct kmVec4* pV);
float kmPlaneDotCoord(const kmPlane* pP, const struct kmVec3* pV);
float kmPlaneDotNormal(const kmPlane* pP, const struct kmVec3* pV);
kmPlane* kmPlaneFromNormalAndDistance(kmPlane* plane, const struct kmVec3* normal, const float dist);
kmPlane* kmPlaneFromPointAndNormal(kmPlane* pOut, const struct kmVec3* pPoint, const struct kmVec3* pNormal);
kmPlane* kmPlaneFromPoints(kmPlane* pOut, const struct kmVec3* p1, const struct kmVec3* p2, const struct kmVec3* p3);
struct kmVec3* kmPlaneIntersectLine(struct kmVec3* pOut, const kmPlane* pP, const struct kmVec3* pV1, const struct kmVec3* pV2);
kmPlane* kmPlaneNormalize(kmPlane* pOut, const kmPlane* pP);
kmPlane* kmPlaneScale(kmPlane* pOut, const kmPlane* pP, float s);
KM_POINT_CLASSIFICATION kmPlaneClassifyPoint(const kmPlane* pIn, const struct kmVec3* pP);

kmPlane* kmPlaneExtractFromMat4(kmPlane* pOut, const struct kmMat4* pIn, int row);
struct kmVec3* kmPlaneGetIntersection(struct kmVec3* pOut, const kmPlane* p1, const kmPlane* p2, const kmPlane* p3);
typedef struct kmAABB2 {
    kmVec2 min;
    kmVec2 max;
} kmAABB2;


kmAABB2* kmAABB2Initialize(kmAABB2* pBox, const kmVec2* centre, const float width, const float height, const float depth);
kmAABB2* kmAABB2Sanitize(kmAABB2* pOut, const kmAABB2* pIn );
int kmAABB2ContainsPoint(const kmAABB2* pBox, const kmVec2* pPoint);
kmAABB2* kmAABB2Assign(kmAABB2* pOut, const kmAABB2* pIn);
kmAABB2* kmAABB2Translate(kmAABB2* pOut, const kmAABB2* pIn, const kmVec2 *translation );
kmAABB2* kmAABB2Scale(kmAABB2* pOut, const kmAABB2* pIn, float s);
kmAABB2* kmAABB2ScaleWithPivot( kmAABB2* pOut, const kmAABB2* pIn, const kmVec2 *pivot, float s );
unsigned int kmAABB2ContainsAABB(const kmAABB2* container, const kmAABB2* to_check);
float kmAABB2DiameterX(const kmAABB2* aabb);
float kmAABB2DiameterY(const kmAABB2* aabb);
kmVec2* kmAABB2Centre(const kmAABB2* aabb, kmVec2* pOut);
kmAABB2* kmAABB2ExpandToContain(kmAABB2* pOut, const kmAABB2* pIn, const kmAABB2* other);
typedef struct kmAABB3 {
    kmVec3 min;
    kmVec3 max;
} kmAABB3;


kmAABB3* kmAABB3Initialize(kmAABB3* pBox, const kmVec3* centre, const float width, const float height, const float depth);
int kmAABB3ContainsPoint(const kmAABB3* pBox, const kmVec3* pPoint);
kmAABB3* kmAABB3Assign(kmAABB3* pOut, const kmAABB3* pIn);
kmAABB3* kmAABB3Scale(kmAABB3* pOut, const kmAABB3* pIn, float s);
unsigned char kmAABB3IntersectsTriangle(kmAABB3* box, const kmVec3* p1, const kmVec3* p2, const kmVec3* p3);
unsigned char kmAABB3IntersectsAABB(const kmAABB3* box, const kmAABB3* other);
unsigned int kmAABB3ContainsAABB(const kmAABB3* container, const kmAABB3* to_check);
float kmAABB3DiameterX(const kmAABB3* aabb);
float kmAABB3DiameterY(const kmAABB3* aabb);
float kmAABB3DiameterZ(const kmAABB3* aabb);
kmVec3* kmAABB3Centre(const kmAABB3* aabb, kmVec3* pOut);
kmAABB3* kmAABB3ExpandToContain(kmAABB3* pOut, const kmAABB3* pIn, const kmAABB3* other);
typedef struct kmRay2 {
    kmVec2 start;
    kmVec2 dir;
} kmRay2;

void kmRay2Fill(kmRay2* ray, float px, float py, float vx, float vy);
void kmRay2FillWithEndpoints( kmRay2 *ray, const kmVec2 *start, const kmVec2 *end );

unsigned char kmLine2WithLineIntersection(const kmVec2 *ptA, const kmVec2 *vecA,
                                   const kmVec2 *ptB, const kmVec2 *vecB,
                                   float *outTA, float *outTB,
                                   kmVec2 *outIntersection );

unsigned char kmSegment2WithSegmentIntersection( const kmRay2 *segmentA,
                                          const kmRay2 *segmentB,
                                          kmVec2 *intersection );

unsigned char kmRay2IntersectLineSegment(const kmRay2* ray, const kmVec2* p1, const kmVec2* p2, kmVec2* intersection);
unsigned char kmRay2IntersectTriangle(const kmRay2* ray, const kmVec2* p1, const kmVec2* p2, const kmVec2* p3, kmVec2* intersection, kmVec2* normal_out, float* distance);

unsigned char kmRay2IntersectBox(const kmRay2* ray, const kmVec2* p1, const kmVec2* p2, const kmVec2* p3, const kmVec2* p4,
kmVec2* intersection, kmVec2* normal_out);

unsigned char kmRay2IntersectCircle(const kmRay2* ray, const kmVec2 centre, const float radius, kmVec2* intersection);
typedef struct kmRay3 {
    kmVec3 start;
    kmVec3 dir;
} kmRay3;

struct kmPlane;
struct kmAABB3;

kmRay3* kmRay3Fill(kmRay3* ray, float px, float py, float pz, float vx, float vy, float vz);
kmRay3* kmRay3FromPointAndDirection(kmRay3* ray, const kmVec3* point, const kmVec3* direction);
unsigned char kmRay3IntersectPlane(kmVec3* pOut, const kmRay3* ray, const struct kmPlane* plane);
unsigned char kmRay3IntersectTriangle(const kmRay3* ray, const kmVec3* v0, const kmVec3* v1, const kmVec3* v2, kmVec3* intersection, kmVec3* normal, float* distance);
unsigned char kmRay3IntersectAABB3(const kmRay3* ray, const struct kmAABB3* aabb, kmVec3* intersection, float* distance);

