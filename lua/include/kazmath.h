

extern float kmSQR(float s);
extern float kmDegreesToRadians(float degrees);
extern float kmRadiansToDegrees(float radians);

extern float kmMin(float lhs, float rhs);
extern float kmMax(float lhs, float rhs);
extern unsigned char kmAlmostEqual(float lhs, float rhs);

extern float kmClamp(float x, float min, float max);
extern float kmLerp(float x, float y, float factor);

struct kmMat3;

#pragma pack(push)
#pragma pack(1)
typedef struct kmVec2 {
    float x;
    float y;
} kmVec2;

#pragma pack(pop)





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
