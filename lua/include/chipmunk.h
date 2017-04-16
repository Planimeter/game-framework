








          void cpMessage(const char *condition, const char *file, int line, int isError, int isHardError, const char *message, ...);






 typedef double cpFloat;
static inline cpFloat cpfmax(cpFloat a, cpFloat b)
{
 return (a > b) ? a : b;
}


static inline cpFloat cpfmin(cpFloat a, cpFloat b)
{
 return (a < b) ? a : b;
}


static inline cpFloat cpfabs(cpFloat f)
{
 return (f < 0) ? -f : f;
}


static inline cpFloat cpfclamp(cpFloat f, cpFloat min, cpFloat max)
{
 return cpfmin(cpfmax(f, min), max);
}


static inline cpFloat cpfclamp01(cpFloat f)
{
 return cpfmax(0.0f, cpfmin(f, 1.0f));
}




static inline cpFloat cpflerp(cpFloat f1, cpFloat f2, cpFloat t)
{
 return f1*(1.0f - t) + f2*t;
}


static inline cpFloat cpflerpconst(cpFloat f1, cpFloat f2, cpFloat d)
{
 return f1 + cpfclamp(f2 - f1, -d, d);
}





 typedef uintptr_t cpHashValue;




typedef uint32_t cpCollisionID;






 typedef unsigned char cpBool;
 typedef void * cpDataPointer;






 typedef uintptr_t cpCollisionType;






 typedef uintptr_t cpGroup;






 typedef unsigned int cpBitmask;






 typedef unsigned int cpTimestamp;
 typedef struct cpVect{cpFloat x,y;} cpVect;






 typedef struct cpTransform {
  cpFloat a, b, c, d, tx, ty;
 } cpTransform;



typedef struct cpMat2x2 {

 cpFloat a, b, c, d;
} cpMat2x2;
typedef struct cpArray cpArray;
typedef struct cpHashSet cpHashSet;

typedef struct cpBody cpBody;

typedef struct cpShape cpShape;
typedef struct cpCircleShape cpCircleShape;
typedef struct cpSegmentShape cpSegmentShape;
typedef struct cpPolyShape cpPolyShape;

typedef struct cpConstraint cpConstraint;
typedef struct cpPinJoint cpPinJoint;
typedef struct cpSlideJoint cpSlideJoint;
typedef struct cpPivotJoint cpPivotJoint;
typedef struct cpGrooveJoint cpGrooveJoint;
typedef struct cpDampedSpring cpDampedSpring;
typedef struct cpDampedRotarySpring cpDampedRotarySpring;
typedef struct cpRotaryLimitJoint cpRotaryLimitJoint;
typedef struct cpRatchetJoint cpRatchetJoint;
typedef struct cpGearJoint cpGearJoint;
typedef struct cpSimpleMotorJoint cpSimpleMotorJoint;

typedef struct cpCollisionHandler cpCollisionHandler;
typedef struct cpContactPointSet cpContactPointSet;
typedef struct cpArbiter cpArbiter;

typedef struct cpSpace cpSpace;


static const cpVect cpvzero = {0.0f,0.0f};


static inline cpVect cpv(const cpFloat x, const cpFloat y)
{
 cpVect v = {x, y};
 return v;
}


static inline cpBool cpveql(const cpVect v1, const cpVect v2)
{
 return (v1.x == v2.x && v1.y == v2.y);
}


static inline cpVect cpvadd(const cpVect v1, const cpVect v2)
{
 return cpv(v1.x + v2.x, v1.y + v2.y);
}


static inline cpVect cpvsub(const cpVect v1, const cpVect v2)
{
 return cpv(v1.x - v2.x, v1.y - v2.y);
}


static inline cpVect cpvneg(const cpVect v)
{
 return cpv(-v.x, -v.y);
}


static inline cpVect cpvmult(const cpVect v, const cpFloat s)
{
 return cpv(v.x*s, v.y*s);
}


static inline cpFloat cpvdot(const cpVect v1, const cpVect v2)
{
 return v1.x*v2.x + v1.y*v2.y;
}




static inline cpFloat cpvcross(const cpVect v1, const cpVect v2)
{
 return v1.x*v2.y - v1.y*v2.x;
}


static inline cpVect cpvperp(const cpVect v)
{
 return cpv(-v.y, v.x);
}


static inline cpVect cpvrperp(const cpVect v)
{
 return cpv(v.y, -v.x);
}


static inline cpVect cpvproject(const cpVect v1, const cpVect v2)
{
 return cpvmult(v2, cpvdot(v1, v2)/cpvdot(v2, v2));
}


static inline cpVect cpvforangle(const cpFloat a)
{
 return cpv(cos(a), sin(a));
}


static inline cpFloat cpvtoangle(const cpVect v)
{
 return atan2(v.y, v.x);
}


static inline cpVect cpvrotate(const cpVect v1, const cpVect v2)
{
 return cpv(v1.x*v2.x - v1.y*v2.y, v1.x*v2.y + v1.y*v2.x);
}


static inline cpVect cpvunrotate(const cpVect v1, const cpVect v2)
{
 return cpv(v1.x*v2.x + v1.y*v2.y, v1.y*v2.x - v1.x*v2.y);
}


static inline cpFloat cpvlengthsq(const cpVect v)
{
 return cpvdot(v, v);
}


static inline cpFloat cpvlength(const cpVect v)
{
 return sqrt(cpvdot(v, v));
}


static inline cpVect cpvlerp(const cpVect v1, const cpVect v2, const cpFloat t)
{
 return cpvadd(cpvmult(v1, 1.0f - t), cpvmult(v2, t));
}


static inline cpVect cpvnormalize(const cpVect v)
{

 return cpvmult(v, 1.0f/(cpvlength(v) + DBL_MIN));
}


static inline cpVect
cpvslerp(const cpVect v1, const cpVect v2, const cpFloat t)
{
 cpFloat dot = cpvdot(cpvnormalize(v1), cpvnormalize(v2));
 cpFloat omega = acos(cpfclamp(dot, -1.0f, 1.0f));

 if(omega < 1e-3){

  return cpvlerp(v1, v2, t);
 } else {
  cpFloat denom = 1.0f/sin(omega);
  return cpvadd(cpvmult(v1, sin((1.0f - t)*omega)*denom), cpvmult(v2, sin(t*omega)*denom));
 }
}


static inline cpVect
cpvslerpconst(const cpVect v1, const cpVect v2, const cpFloat a)
{
 cpFloat dot = cpvdot(cpvnormalize(v1), cpvnormalize(v2));
 cpFloat omega = acos(cpfclamp(dot, -1.0f, 1.0f));

 return cpvslerp(v1, v2, cpfmin(a, omega)/omega);
}


static inline cpVect cpvclamp(const cpVect v, const cpFloat len)
{
 return (cpvdot(v,v) > len*len) ? cpvmult(cpvnormalize(v), len) : v;
}


static inline cpVect cpvlerpconst(cpVect v1, cpVect v2, cpFloat d)
{
 return cpvadd(v1, cpvclamp(cpvsub(v2, v1), d));
}


static inline cpFloat cpvdist(const cpVect v1, const cpVect v2)
{
 return cpvlength(cpvsub(v1, v2));
}


static inline cpFloat cpvdistsq(const cpVect v1, const cpVect v2)
{
 return cpvlengthsq(cpvsub(v1, v2));
}


static inline cpBool cpvnear(const cpVect v1, const cpVect v2, const cpFloat dist)
{
 return cpvdistsq(v1, v2) < dist*dist;
}
static inline cpMat2x2
cpMat2x2New(cpFloat a, cpFloat b, cpFloat c, cpFloat d)
{
 cpMat2x2 m = {a, b, c, d};
 return m;
}

static inline cpVect
cpMat2x2Transform(cpMat2x2 m, cpVect v)
{
 return cpv(v.x*m.a + v.y*m.b, v.x*m.c + v.y*m.d);
}
typedef struct cpBB{
 cpFloat l, b, r ,t;
} cpBB;


static inline cpBB cpBBNew(const cpFloat l, const cpFloat b, const cpFloat r, const cpFloat t)
{
 cpBB bb = {l, b, r, t};
 return bb;
}


static inline cpBB
cpBBNewForExtents(const cpVect c, const cpFloat hw, const cpFloat hh)
{
 return cpBBNew(c.x - hw, c.y - hh, c.x + hw, c.y + hh);
}


static inline cpBB cpBBNewForCircle(const cpVect p, const cpFloat r)
{
 return cpBBNewForExtents(p, r, r);
}


static inline cpBool cpBBIntersects(const cpBB a, const cpBB b)
{
 return (a.l <= b.r && b.l <= a.r && a.b <= b.t && b.b <= a.t);
}


static inline cpBool cpBBContainsBB(const cpBB bb, const cpBB other)
{
 return (bb.l <= other.l && bb.r >= other.r && bb.b <= other.b && bb.t >= other.t);
}


static inline cpBool cpBBContainsVect(const cpBB bb, const cpVect v)
{
 return (bb.l <= v.x && bb.r >= v.x && bb.b <= v.y && bb.t >= v.y);
}


static inline cpBB cpBBMerge(const cpBB a, const cpBB b){
 return cpBBNew(
  cpfmin(a.l, b.l),
  cpfmin(a.b, b.b),
  cpfmax(a.r, b.r),
  cpfmax(a.t, b.t)
 );
}


static inline cpBB cpBBExpand(const cpBB bb, const cpVect v){
 return cpBBNew(
  cpfmin(bb.l, v.x),
  cpfmin(bb.b, v.y),
  cpfmax(bb.r, v.x),
  cpfmax(bb.t, v.y)
 );
}


static inline cpVect
cpBBCenter(cpBB bb)
{
 return cpvlerp(cpv(bb.l, bb.b), cpv(bb.r, bb.t), 0.5f);
}


static inline cpFloat cpBBArea(cpBB bb)
{
 return (bb.r - bb.l)*(bb.t - bb.b);
}


static inline cpFloat cpBBMergedArea(cpBB a, cpBB b)
{
 return (cpfmax(a.r, b.r) - cpfmin(a.l, b.l))*(cpfmax(a.t, b.t) - cpfmin(a.b, b.b));
}


static inline cpFloat cpBBSegmentQuery(cpBB bb, cpVect a, cpVect b)
{
 cpFloat idx = 1.0f/(b.x - a.x);



 cpFloat tx1 = (bb.l == a.x ? -(__builtin_inf()) : (bb.l - a.x)*idx);
 cpFloat tx2 = (bb.r == a.x ? (__builtin_inf()) : (bb.r - a.x)*idx);
 cpFloat txmin = cpfmin(tx1, tx2);
 cpFloat txmax = cpfmax(tx1, tx2);

 cpFloat idy = 1.0f/(b.y - a.y);
 cpFloat ty1 = (bb.b == a.y ? -(__builtin_inf()) : (bb.b - a.y)*idy);
 cpFloat ty2 = (bb.t == a.y ? (__builtin_inf()) : (bb.t - a.y)*idy);



 cpFloat tymin = cpfmin(ty1, ty2);
 cpFloat tymax = cpfmax(ty1, ty2);

 if(tymin <= txmax && txmin <= tymax){
  cpFloat min = cpfmax(txmin, tymin);
  cpFloat max = cpfmin(txmax, tymax);

  if(0.0 <= max && min <= 1.0) return cpfmax(min, 0.0);
 }

 return (__builtin_inf());
}


static inline cpBool cpBBIntersectsSegment(cpBB bb, cpVect a, cpVect b)
{
 return (cpBBSegmentQuery(bb, a, b) != (__builtin_inf()));
}


static inline cpVect
cpBBClampVect(const cpBB bb, const cpVect v)
{
 return cpv(cpfclamp(v.x, bb.l, bb.r), cpfclamp(v.y, bb.b, bb.t));
}


static inline cpVect
cpBBWrapVect(const cpBB bb, const cpVect v)
{
 cpFloat dx = cpfabs(bb.r - bb.l);
 cpFloat modx = fmod(v.x - bb.l, dx);
 cpFloat x = (modx > 0.0f) ? modx : modx + dx;

 cpFloat dy = cpfabs(bb.t - bb.b);
 cpFloat mody = fmod(v.y - bb.b, dy);
 cpFloat y = (mody > 0.0f) ? mody : mody + dy;

 return cpv(x + bb.l, y + bb.b);
}


static inline cpBB
cpBBOffset(const cpBB bb, const cpVect v)
{
 return cpBBNew(
  bb.l + v.x,
  bb.b + v.y,
  bb.r + v.x,
  bb.t + v.y
 );
}
static const cpTransform cpTransformIdentity = {1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};





static inline cpTransform
cpTransformNew(cpFloat a, cpFloat b, cpFloat c, cpFloat d, cpFloat tx, cpFloat ty)
{
 cpTransform t = {a, b, c, d, tx, ty};
 return t;
}


static inline cpTransform
cpTransformNewTranspose(cpFloat a, cpFloat c, cpFloat tx, cpFloat b, cpFloat d, cpFloat ty)
{
 cpTransform t = {a, b, c, d, tx, ty};
 return t;
}


static inline cpTransform
cpTransformInverse(cpTransform t)
{
  cpFloat inv_det = 1.0/(t.a*t.d - t.c*t.b);
  return cpTransformNewTranspose(
     t.d*inv_det, -t.c*inv_det, (t.c*t.ty - t.tx*t.d)*inv_det,
    -t.b*inv_det, t.a*inv_det, (t.tx*t.b - t.a*t.ty)*inv_det
  );
}


static inline cpTransform
cpTransformMult(cpTransform t1, cpTransform t2)
{
  return cpTransformNewTranspose(
    t1.a*t2.a + t1.c*t2.b, t1.a*t2.c + t1.c*t2.d, t1.a*t2.tx + t1.c*t2.ty + t1.tx,
    t1.b*t2.a + t1.d*t2.b, t1.b*t2.c + t1.d*t2.d, t1.b*t2.tx + t1.d*t2.ty + t1.ty
  );
}


static inline cpVect
cpTransformPoint(cpTransform t, cpVect p)
{
  return cpv(t.a*p.x + t.c*p.y + t.tx, t.b*p.x + t.d*p.y + t.ty);
}


static inline cpVect
cpTransformVect(cpTransform t, cpVect v)
{
  return cpv(t.a*v.x + t.c*v.y, t.b*v.x + t.d*v.y);
}


static inline cpBB
cpTransformbBB(cpTransform t, cpBB bb)
{
 cpVect center = cpBBCenter(bb);
 cpFloat hw = (bb.r - bb.l)*0.5;
 cpFloat hh = (bb.t - bb.b)*0.5;

 cpFloat a = t.a*hw, b = t.c*hh, d = t.b*hw, e = t.d*hh;
 cpFloat hw_max = cpfmax(cpfabs(a + b), cpfabs(a - b));
 cpFloat hh_max = cpfmax(cpfabs(d + e), cpfabs(d - e));
 return cpBBNewForExtents(cpTransformPoint(t, center), hw_max, hh_max);
}


static inline cpTransform
cpTransformTranslate(cpVect translate)
{
  return cpTransformNewTranspose(
    1.0, 0.0, translate.x,
    0.0, 1.0, translate.y
  );
}


static inline cpTransform
cpTransformScale(cpFloat scaleX, cpFloat scaleY)
{
 return cpTransformNewTranspose(
  scaleX, 0.0, 0.0,
     0.0, scaleY, 0.0
 );
}


static inline cpTransform
cpTransformRotate(cpFloat radians)
{
 cpVect rot = cpvforangle(radians);
 return cpTransformNewTranspose(
  rot.x, -rot.y, 0.0,
  rot.y, rot.x, 0.0
 );
}


static inline cpTransform
cpTransformRigid(cpVect translate, cpFloat radians)
{
 cpVect rot = cpvforangle(radians);
 return cpTransformNewTranspose(
  rot.x, -rot.y, translate.x,
  rot.y, rot.x, translate.y
 );
}


static inline cpTransform
cpTransformRigidInverse(cpTransform t)
{
  return cpTransformNewTranspose(
     t.d, -t.c, (t.c*t.ty - t.tx*t.d),
    -t.b, t.a, (t.tx*t.b - t.a*t.ty)
  );
}




static inline cpTransform
cpTransformWrap(cpTransform outer, cpTransform inner)
{
  return cpTransformMult(cpTransformInverse(outer), cpTransformMult(inner, outer));
}

static inline cpTransform
cpTransformWrapInverse(cpTransform outer, cpTransform inner)
{
  return cpTransformMult(outer, cpTransformMult(inner, cpTransformInverse(outer)));
}

static inline cpTransform
cpTransformOrtho(cpBB bb)
{
  return cpTransformNewTranspose(
    2.0/(bb.r - bb.l), 0.0, -(bb.r + bb.l)/(bb.r - bb.l),
    0.0, 2.0/(bb.t - bb.b), -(bb.t + bb.b)/(bb.t - bb.b)
  );
}

static inline cpTransform
cpTransformBoneScale(cpVect v0, cpVect v1)
{
  cpVect d = cpvsub(v1, v0);
  return cpTransformNewTranspose(
    d.x, -d.y, v0.x,
    d.y, d.x, v0.y
  );
}

static inline cpTransform
cpTransformAxialScale(cpVect axis, cpVect pivot, cpFloat scale)
{
  cpFloat A = axis.x*axis.y*(scale - 1.0);
  cpFloat B = cpvdot(axis, pivot)*(1.0 - scale);

  return cpTransformNewTranspose(
    scale*axis.x*axis.x + axis.y*axis.y, A, axis.x*B,
    A, axis.x*axis.x + scale*axis.y*axis.y, axis.y*B
  );
}
typedef cpBB (*cpSpatialIndexBBFunc)(void *obj);

typedef void (*cpSpatialIndexIteratorFunc)(void *obj, void *data);

typedef cpCollisionID (*cpSpatialIndexQueryFunc)(void *obj1, void *obj2, cpCollisionID id, void *data);

typedef cpFloat (*cpSpatialIndexSegmentQueryFunc)(void *obj1, void *obj2, void *data);


typedef struct cpSpatialIndexClass cpSpatialIndexClass;
typedef struct cpSpatialIndex cpSpatialIndex;


struct cpSpatialIndex {
 cpSpatialIndexClass *klass;

 cpSpatialIndexBBFunc bbfunc;

 cpSpatialIndex *staticIndex, *dynamicIndex;
};




typedef struct cpSpaceHash cpSpaceHash;


          cpSpaceHash* cpSpaceHashAlloc(void);

          cpSpatialIndex* cpSpaceHashInit(cpSpaceHash *hash, cpFloat celldim, int numcells, cpSpatialIndexBBFunc bbfunc, cpSpatialIndex *staticIndex);

          cpSpatialIndex* cpSpaceHashNew(cpFloat celldim, int cells, cpSpatialIndexBBFunc bbfunc, cpSpatialIndex *staticIndex);





          void cpSpaceHashResize(cpSpaceHash *hash, cpFloat celldim, int numcells);



typedef struct cpBBTree cpBBTree;


          cpBBTree* cpBBTreeAlloc(void);

          cpSpatialIndex* cpBBTreeInit(cpBBTree *tree, cpSpatialIndexBBFunc bbfunc, cpSpatialIndex *staticIndex);

          cpSpatialIndex* cpBBTreeNew(cpSpatialIndexBBFunc bbfunc, cpSpatialIndex *staticIndex);


          void cpBBTreeOptimize(cpSpatialIndex *index);



typedef cpVect (*cpBBTreeVelocityFunc)(void *obj);

          void cpBBTreeSetVelocityFunc(cpSpatialIndex *index, cpBBTreeVelocityFunc func);



typedef struct cpSweep1D cpSweep1D;


          cpSweep1D* cpSweep1DAlloc(void);

          cpSpatialIndex* cpSweep1DInit(cpSweep1D *sweep, cpSpatialIndexBBFunc bbfunc, cpSpatialIndex *staticIndex);

          cpSpatialIndex* cpSweep1DNew(cpSpatialIndexBBFunc bbfunc, cpSpatialIndex *staticIndex);



typedef void (*cpSpatialIndexDestroyImpl)(cpSpatialIndex *index);

typedef int (*cpSpatialIndexCountImpl)(cpSpatialIndex *index);
typedef void (*cpSpatialIndexEachImpl)(cpSpatialIndex *index, cpSpatialIndexIteratorFunc func, void *data);

typedef cpBool (*cpSpatialIndexContainsImpl)(cpSpatialIndex *index, void *obj, cpHashValue hashid);
typedef void (*cpSpatialIndexInsertImpl)(cpSpatialIndex *index, void *obj, cpHashValue hashid);
typedef void (*cpSpatialIndexRemoveImpl)(cpSpatialIndex *index, void *obj, cpHashValue hashid);

typedef void (*cpSpatialIndexReindexImpl)(cpSpatialIndex *index);
typedef void (*cpSpatialIndexReindexObjectImpl)(cpSpatialIndex *index, void *obj, cpHashValue hashid);
typedef void (*cpSpatialIndexReindexQueryImpl)(cpSpatialIndex *index, cpSpatialIndexQueryFunc func, void *data);

typedef void (*cpSpatialIndexQueryImpl)(cpSpatialIndex *index, void *obj, cpBB bb, cpSpatialIndexQueryFunc func, void *data);
typedef void (*cpSpatialIndexSegmentQueryImpl)(cpSpatialIndex *index, void *obj, cpVect a, cpVect b, cpFloat t_exit, cpSpatialIndexSegmentQueryFunc func, void *data);

struct cpSpatialIndexClass {
 cpSpatialIndexDestroyImpl destroy;

 cpSpatialIndexCountImpl count;
 cpSpatialIndexEachImpl each;

 cpSpatialIndexContainsImpl contains;
 cpSpatialIndexInsertImpl insert;
 cpSpatialIndexRemoveImpl remove;

 cpSpatialIndexReindexImpl reindex;
 cpSpatialIndexReindexObjectImpl reindexObject;
 cpSpatialIndexReindexQueryImpl reindexQuery;

 cpSpatialIndexQueryImpl query;
 cpSpatialIndexSegmentQueryImpl segmentQuery;
};


void cpSpatialIndexFree(cpSpatialIndex *index);

void cpSpatialIndexCollideStatic(cpSpatialIndex *dynamicIndex, cpSpatialIndex *staticIndex, cpSpatialIndexQueryFunc func, void *data);


static inline void cpSpatialIndexDestroy(cpSpatialIndex *index)
{
 if(index->klass) index->klass->destroy(index);
}


static inline int cpSpatialIndexCount(cpSpatialIndex *index)
{
 return index->klass->count(index);
}


static inline void cpSpatialIndexEach(cpSpatialIndex *index, cpSpatialIndexIteratorFunc func, void *data)
{
 index->klass->each(index, func, data);
}



static inline cpBool cpSpatialIndexContains(cpSpatialIndex *index, void *obj, cpHashValue hashid)
{
 return index->klass->contains(index, obj, hashid);
}



static inline void cpSpatialIndexInsert(cpSpatialIndex *index, void *obj, cpHashValue hashid)
{
 index->klass->insert(index, obj, hashid);
}



static inline void cpSpatialIndexRemove(cpSpatialIndex *index, void *obj, cpHashValue hashid)
{
 index->klass->remove(index, obj, hashid);
}


static inline void cpSpatialIndexReindex(cpSpatialIndex *index)
{
 index->klass->reindex(index);
}


static inline void cpSpatialIndexReindexObject(cpSpatialIndex *index, void *obj, cpHashValue hashid)
{
 index->klass->reindexObject(index, obj, hashid);
}


static inline void cpSpatialIndexQuery(cpSpatialIndex *index, void *obj, cpBB bb, cpSpatialIndexQueryFunc func, void *data)
{
 index->klass->query(index, obj, bb, func, data);
}


static inline void cpSpatialIndexSegmentQuery(cpSpatialIndex *index, void *obj, cpVect a, cpVect b, cpFloat t_exit, cpSpatialIndexSegmentQueryFunc func, void *data)
{
 index->klass->segmentQuery(index, obj, a, b, t_exit, func, data);
}




static inline void cpSpatialIndexReindexQuery(cpSpatialIndex *index, cpSpatialIndexQueryFunc func, void *data)
{
 index->klass->reindexQuery(index, func, data);
}

          cpFloat cpArbiterGetRestitution(const cpArbiter *arb);

          void cpArbiterSetRestitution(cpArbiter *arb, cpFloat restitution);

          cpFloat cpArbiterGetFriction(const cpArbiter *arb);

          void cpArbiterSetFriction(cpArbiter *arb, cpFloat friction);


          cpVect cpArbiterGetSurfaceVelocity(cpArbiter *arb);



          void cpArbiterSetSurfaceVelocity(cpArbiter *arb, cpVect vr);


          cpDataPointer cpArbiterGetUserData(const cpArbiter *arb);


          void cpArbiterSetUserData(cpArbiter *arb, cpDataPointer userData);



          cpVect cpArbiterTotalImpulse(const cpArbiter *arb);


          cpFloat cpArbiterTotalKE(const cpArbiter *arb);



          cpBool cpArbiterIgnore(cpArbiter *arb);




          void cpArbiterGetShapes(const cpArbiter *arb, cpShape **a, cpShape **b);







          void cpArbiterGetBodies(const cpArbiter *arb, cpBody **a, cpBody **b);





struct cpContactPointSet {

 int count;


 cpVect normal;


 struct {

  cpVect pointA, pointB;


  cpFloat distance;
 } points[2];
};


          cpContactPointSet cpArbiterGetContactPointSet(const cpArbiter *arb);



          void cpArbiterSetContactPointSet(cpArbiter *arb, cpContactPointSet *set);


          cpBool cpArbiterIsFirstContact(const cpArbiter *arb);

          cpBool cpArbiterIsRemoval(const cpArbiter *arb);


          int cpArbiterGetCount(const cpArbiter *arb);

          cpVect cpArbiterGetNormal(const cpArbiter *arb);

          cpVect cpArbiterGetPointA(const cpArbiter *arb, int i);

          cpVect cpArbiterGetPointB(const cpArbiter *arb, int i);

          cpFloat cpArbiterGetDepth(const cpArbiter *arb, int i);



          cpBool cpArbiterCallWildcardBeginA(cpArbiter *arb, cpSpace *space);


          cpBool cpArbiterCallWildcardBeginB(cpArbiter *arb, cpSpace *space);



          cpBool cpArbiterCallWildcardPreSolveA(cpArbiter *arb, cpSpace *space);


          cpBool cpArbiterCallWildcardPreSolveB(cpArbiter *arb, cpSpace *space);


          void cpArbiterCallWildcardPostSolveA(cpArbiter *arb, cpSpace *space);

          void cpArbiterCallWildcardPostSolveB(cpArbiter *arb, cpSpace *space);


          void cpArbiterCallWildcardSeparateA(cpArbiter *arb, cpSpace *space);

          void cpArbiterCallWildcardSeparateB(cpArbiter *arb, cpSpace *space);

typedef enum cpBodyType {


 CP_BODY_TYPE_DYNAMIC,




 CP_BODY_TYPE_KINEMATIC,



 CP_BODY_TYPE_STATIC,
} cpBodyType;


typedef void (*cpBodyVelocityFunc)(cpBody *body, cpVect gravity, cpFloat damping, cpFloat dt);

typedef void (*cpBodyPositionFunc)(cpBody *body, cpFloat dt);


          cpBody* cpBodyAlloc(void);

          cpBody* cpBodyInit(cpBody *body, cpFloat mass, cpFloat moment);

          cpBody* cpBodyNew(cpFloat mass, cpFloat moment);


          cpBody* cpBodyNewKinematic(void);

          cpBody* cpBodyNewStatic(void);


          void cpBodyDestroy(cpBody *body);

          void cpBodyFree(cpBody *body);



          void cpBodyActivate(cpBody *body);

          void cpBodyActivateStatic(cpBody *body, cpShape *filter);


          void cpBodySleep(cpBody *body);

          void cpBodySleepWithGroup(cpBody *body, cpBody *group);


          cpBool cpBodyIsSleeping(const cpBody *body);


          cpBodyType cpBodyGetType(cpBody *body);

          void cpBodySetType(cpBody *body, cpBodyType type);


          cpSpace* cpBodyGetSpace(const cpBody *body);


          cpFloat cpBodyGetMass(const cpBody *body);

          void cpBodySetMass(cpBody *body, cpFloat m);


          cpFloat cpBodyGetMoment(const cpBody *body);

          void cpBodySetMoment(cpBody *body, cpFloat i);


          cpVect cpBodyGetPosition(const cpBody *body);

          void cpBodySetPosition(cpBody *body, cpVect pos);


          cpVect cpBodyGetCenterOfGravity(const cpBody *body);

          void cpBodySetCenterOfGravity(cpBody *body, cpVect cog);


          cpVect cpBodyGetVelocity(const cpBody *body);

          void cpBodySetVelocity(cpBody *body, cpVect velocity);


          cpVect cpBodyGetForce(const cpBody *body);

          void cpBodySetForce(cpBody *body, cpVect force);


          cpFloat cpBodyGetAngle(const cpBody *body);

          void cpBodySetAngle(cpBody *body, cpFloat a);


          cpFloat cpBodyGetAngularVelocity(const cpBody *body);

          void cpBodySetAngularVelocity(cpBody *body, cpFloat angularVelocity);


          cpFloat cpBodyGetTorque(const cpBody *body);

          void cpBodySetTorque(cpBody *body, cpFloat torque);


          cpVect cpBodyGetRotation(const cpBody *body);


          cpDataPointer cpBodyGetUserData(const cpBody *body);

          void cpBodySetUserData(cpBody *body, cpDataPointer userData);


          void cpBodySetVelocityUpdateFunc(cpBody *body, cpBodyVelocityFunc velocityFunc);


          void cpBodySetPositionUpdateFunc(cpBody *body, cpBodyPositionFunc positionFunc);


          void cpBodyUpdateVelocity(cpBody *body, cpVect gravity, cpFloat damping, cpFloat dt);

          void cpBodyUpdatePosition(cpBody *body, cpFloat dt);


          cpVect cpBodyLocalToWorld(const cpBody *body, const cpVect point);

          cpVect cpBodyWorldToLocal(const cpBody *body, const cpVect point);


          void cpBodyApplyForceAtWorldPoint(cpBody *body, cpVect force, cpVect point);

          void cpBodyApplyForceAtLocalPoint(cpBody *body, cpVect force, cpVect point);


          void cpBodyApplyImpulseAtWorldPoint(cpBody *body, cpVect impulse, cpVect point);

          void cpBodyApplyImpulseAtLocalPoint(cpBody *body, cpVect impulse, cpVect point);


          cpVect cpBodyGetVelocityAtWorldPoint(const cpBody *body, cpVect point);

          cpVect cpBodyGetVelocityAtLocalPoint(const cpBody *body, cpVect point);


          cpFloat cpBodyKineticEnergy(const cpBody *body);


typedef void (*cpBodyShapeIteratorFunc)(cpBody *body, cpShape *shape, void *data);

          void cpBodyEachShape(cpBody *body, cpBodyShapeIteratorFunc func, void *data);


typedef void (*cpBodyConstraintIteratorFunc)(cpBody *body, cpConstraint *constraint, void *data);

          void cpBodyEachConstraint(cpBody *body, cpBodyConstraintIteratorFunc func, void *data);


typedef void (*cpBodyArbiterIteratorFunc)(cpBody *body, cpArbiter *arbiter, void *data);

          void cpBodyEachArbiter(cpBody *body, cpBodyArbiterIteratorFunc func, void *data);
typedef struct cpPointQueryInfo {

 const cpShape *shape;

 cpVect point;

 cpFloat distance;


 cpVect gradient;
} cpPointQueryInfo;


typedef struct cpSegmentQueryInfo {

 const cpShape *shape;

 cpVect point;

 cpVect normal;

 cpFloat alpha;
} cpSegmentQueryInfo;


typedef struct cpShapeFilter {


 cpGroup group;


 cpBitmask categories;


 cpBitmask mask;
} cpShapeFilter;


static const cpShapeFilter CP_SHAPE_FILTER_ALL = {((cpGroup)0), (~(cpBitmask)0), (~(cpBitmask)0)};

static const cpShapeFilter CP_SHAPE_FILTER_NONE = {((cpGroup)0), ~(~(cpBitmask)0), ~(~(cpBitmask)0)};


static inline cpShapeFilter
cpShapeFilterNew(cpGroup group, cpBitmask categories, cpBitmask mask)
{
 cpShapeFilter filter = {group, categories, mask};
 return filter;
}


          void cpShapeDestroy(cpShape *shape);

          void cpShapeFree(cpShape *shape);


          cpBB cpShapeCacheBB(cpShape *shape);

          cpBB cpShapeUpdate(cpShape *shape, cpTransform transform);



          cpFloat cpShapePointQuery(const cpShape *shape, cpVect p, cpPointQueryInfo *out);


          cpBool cpShapeSegmentQuery(const cpShape *shape, cpVect a, cpVect b, cpFloat radius, cpSegmentQueryInfo *info);


          cpContactPointSet cpShapesCollide(const cpShape *a, const cpShape *b);


          cpSpace* cpShapeGetSpace(const cpShape *shape);


          cpBody* cpShapeGetBody(const cpShape *shape);


          void cpShapeSetBody(cpShape *shape, cpBody *body);


cpFloat cpShapeGetMass(cpShape *shape);

          void cpShapeSetMass(cpShape *shape, cpFloat mass);


          cpFloat cpShapeGetDensity(cpShape *shape);

          void cpShapeSetDensity(cpShape *shape, cpFloat density);


          cpFloat cpShapeGetMoment(cpShape *shape);

          cpFloat cpShapeGetArea(cpShape *shape);

          cpVect cpShapeGetCenterOfGravity(cpShape *shape);


          cpBB cpShapeGetBB(const cpShape *shape);


          cpBool cpShapeGetSensor(const cpShape *shape);

          void cpShapeSetSensor(cpShape *shape, cpBool sensor);


          cpFloat cpShapeGetElasticity(const cpShape *shape);

          void cpShapeSetElasticity(cpShape *shape, cpFloat elasticity);


          cpFloat cpShapeGetFriction(const cpShape *shape);

          void cpShapeSetFriction(cpShape *shape, cpFloat friction);


          cpVect cpShapeGetSurfaceVelocity(const cpShape *shape);

          void cpShapeSetSurfaceVelocity(cpShape *shape, cpVect surfaceVelocity);


          cpDataPointer cpShapeGetUserData(const cpShape *shape);

          void cpShapeSetUserData(cpShape *shape, cpDataPointer userData);


          cpCollisionType cpShapeGetCollisionType(const cpShape *shape);

          void cpShapeSetCollisionType(cpShape *shape, cpCollisionType collisionType);


          cpShapeFilter cpShapeGetFilter(const cpShape *shape);

          void cpShapeSetFilter(cpShape *shape, cpShapeFilter filter);






          cpCircleShape* cpCircleShapeAlloc(void);

          cpCircleShape* cpCircleShapeInit(cpCircleShape *circle, cpBody *body, cpFloat radius, cpVect offset);

          cpShape* cpCircleShapeNew(cpBody *body, cpFloat radius, cpVect offset);


          cpVect cpCircleShapeGetOffset(const cpShape *shape);

          cpFloat cpCircleShapeGetRadius(const cpShape *shape);





          cpSegmentShape* cpSegmentShapeAlloc(void);

          cpSegmentShape* cpSegmentShapeInit(cpSegmentShape *seg, cpBody *body, cpVect a, cpVect b, cpFloat radius);

          cpShape* cpSegmentShapeNew(cpBody *body, cpVect a, cpVect b, cpFloat radius);


          void cpSegmentShapeSetNeighbors(cpShape *shape, cpVect prev, cpVect next);


          cpVect cpSegmentShapeGetA(const cpShape *shape);

          cpVect cpSegmentShapeGetB(const cpShape *shape);

          cpVect cpSegmentShapeGetNormal(const cpShape *shape);

          cpFloat cpSegmentShapeGetRadius(const cpShape *shape);
          cpPolyShape* cpPolyShapeAlloc(void);


          cpPolyShape* cpPolyShapeInit(cpPolyShape *poly, cpBody *body, int count, const cpVect *verts, cpTransform transform, cpFloat radius);


          cpPolyShape* cpPolyShapeInitRaw(cpPolyShape *poly, cpBody *body, int count, const cpVect *verts, cpFloat radius);


          cpShape* cpPolyShapeNew(cpBody *body, int count, const cpVect *verts, cpTransform transform, cpFloat radius);


          cpShape* cpPolyShapeNewRaw(cpBody *body, int count, const cpVect *verts, cpFloat radius);


          cpPolyShape* cpBoxShapeInit(cpPolyShape *poly, cpBody *body, cpFloat width, cpFloat height, cpFloat radius);

          cpPolyShape* cpBoxShapeInit2(cpPolyShape *poly, cpBody *body, cpBB box, cpFloat radius);

          cpShape* cpBoxShapeNew(cpBody *body, cpFloat width, cpFloat height, cpFloat radius);

          cpShape* cpBoxShapeNew2(cpBody *body, cpBB box, cpFloat radius);


          int cpPolyShapeGetCount(const cpShape *shape);

          cpVect cpPolyShapeGetVert(const cpShape *shape, int index);

          cpFloat cpPolyShapeGetRadius(const cpShape *shape);

typedef void (*cpConstraintPreSolveFunc)(cpConstraint *constraint, cpSpace *space);

typedef void (*cpConstraintPostSolveFunc)(cpConstraint *constraint, cpSpace *space);


          void cpConstraintDestroy(cpConstraint *constraint);

          void cpConstraintFree(cpConstraint *constraint);


          cpSpace* cpConstraintGetSpace(const cpConstraint *constraint);


          cpBody* cpConstraintGetBodyA(const cpConstraint *constraint);


          cpBody* cpConstraintGetBodyB(const cpConstraint *constraint);


          cpFloat cpConstraintGetMaxForce(const cpConstraint *constraint);

          void cpConstraintSetMaxForce(cpConstraint *constraint, cpFloat maxForce);


          cpFloat cpConstraintGetErrorBias(const cpConstraint *constraint);



          void cpConstraintSetErrorBias(cpConstraint *constraint, cpFloat errorBias);


          cpFloat cpConstraintGetMaxBias(const cpConstraint *constraint);

          void cpConstraintSetMaxBias(cpConstraint *constraint, cpFloat maxBias);


          cpBool cpConstraintGetCollideBodies(const cpConstraint *constraint);

          void cpConstraintSetCollideBodies(cpConstraint *constraint, cpBool collideBodies);


          cpConstraintPreSolveFunc cpConstraintGetPreSolveFunc(const cpConstraint *constraint);

          void cpConstraintSetPreSolveFunc(cpConstraint *constraint, cpConstraintPreSolveFunc preSolveFunc);


          cpConstraintPostSolveFunc cpConstraintGetPostSolveFunc(const cpConstraint *constraint);

          void cpConstraintSetPostSolveFunc(cpConstraint *constraint, cpConstraintPostSolveFunc postSolveFunc);


          cpDataPointer cpConstraintGetUserData(const cpConstraint *constraint);

          void cpConstraintSetUserData(cpConstraint *constraint, cpDataPointer userData);


          cpFloat cpConstraintGetImpulse(cpConstraint *constraint);


          cpBool cpConstraintIsPinJoint(const cpConstraint *constraint);


          cpPinJoint* cpPinJointAlloc(void);

          cpPinJoint* cpPinJointInit(cpPinJoint *joint, cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB);

          cpConstraint* cpPinJointNew(cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB);


          cpVect cpPinJointGetAnchorA(const cpConstraint *constraint);

          void cpPinJointSetAnchorA(cpConstraint *constraint, cpVect anchorA);


          cpVect cpPinJointGetAnchorB(const cpConstraint *constraint);

          void cpPinJointSetAnchorB(cpConstraint *constraint, cpVect anchorB);


          cpFloat cpPinJointGetDist(const cpConstraint *constraint);

          void cpPinJointSetDist(cpConstraint *constraint, cpFloat dist);
          cpBool cpConstraintIsSlideJoint(const cpConstraint *constraint);


          cpSlideJoint* cpSlideJointAlloc(void);

          cpSlideJoint* cpSlideJointInit(cpSlideJoint *joint, cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max);

          cpConstraint* cpSlideJointNew(cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB, cpFloat min, cpFloat max);


          cpVect cpSlideJointGetAnchorA(const cpConstraint *constraint);

          void cpSlideJointSetAnchorA(cpConstraint *constraint, cpVect anchorA);


          cpVect cpSlideJointGetAnchorB(const cpConstraint *constraint);

          void cpSlideJointSetAnchorB(cpConstraint *constraint, cpVect anchorB);


          cpFloat cpSlideJointGetMin(const cpConstraint *constraint);

          void cpSlideJointSetMin(cpConstraint *constraint, cpFloat min);


          cpFloat cpSlideJointGetMax(const cpConstraint *constraint);

          void cpSlideJointSetMax(cpConstraint *constraint, cpFloat max);
          cpBool cpConstraintIsPivotJoint(const cpConstraint *constraint);


          cpPivotJoint* cpPivotJointAlloc(void);

          cpPivotJoint* cpPivotJointInit(cpPivotJoint *joint, cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB);

          cpConstraint* cpPivotJointNew(cpBody *a, cpBody *b, cpVect pivot);

          cpConstraint* cpPivotJointNew2(cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB);


          cpVect cpPivotJointGetAnchorA(const cpConstraint *constraint);

          void cpPivotJointSetAnchorA(cpConstraint *constraint, cpVect anchorA);


          cpVect cpPivotJointGetAnchorB(const cpConstraint *constraint);

          void cpPivotJointSetAnchorB(cpConstraint *constraint, cpVect anchorB);
          cpBool cpConstraintIsGrooveJoint(const cpConstraint *constraint);


          cpGrooveJoint* cpGrooveJointAlloc(void);

          cpGrooveJoint* cpGrooveJointInit(cpGrooveJoint *joint, cpBody *a, cpBody *b, cpVect groove_a, cpVect groove_b, cpVect anchorB);

          cpConstraint* cpGrooveJointNew(cpBody *a, cpBody *b, cpVect groove_a, cpVect groove_b, cpVect anchorB);


          cpVect cpGrooveJointGetGrooveA(const cpConstraint *constraint);

          void cpGrooveJointSetGrooveA(cpConstraint *constraint, cpVect grooveA);


          cpVect cpGrooveJointGetGrooveB(const cpConstraint *constraint);

          void cpGrooveJointSetGrooveB(cpConstraint *constraint, cpVect grooveB);


          cpVect cpGrooveJointGetAnchorB(const cpConstraint *constraint);

          void cpGrooveJointSetAnchorB(cpConstraint *constraint, cpVect anchorB);
          cpBool cpConstraintIsDampedSpring(const cpConstraint *constraint);


typedef cpFloat (*cpDampedSpringForceFunc)(cpConstraint *spring, cpFloat dist);


          cpDampedSpring* cpDampedSpringAlloc(void);

          cpDampedSpring* cpDampedSpringInit(cpDampedSpring *joint, cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping);

          cpConstraint* cpDampedSpringNew(cpBody *a, cpBody *b, cpVect anchorA, cpVect anchorB, cpFloat restLength, cpFloat stiffness, cpFloat damping);


          cpVect cpDampedSpringGetAnchorA(const cpConstraint *constraint);

          void cpDampedSpringSetAnchorA(cpConstraint *constraint, cpVect anchorA);


          cpVect cpDampedSpringGetAnchorB(const cpConstraint *constraint);

          void cpDampedSpringSetAnchorB(cpConstraint *constraint, cpVect anchorB);


          cpFloat cpDampedSpringGetRestLength(const cpConstraint *constraint);

          void cpDampedSpringSetRestLength(cpConstraint *constraint, cpFloat restLength);


          cpFloat cpDampedSpringGetStiffness(const cpConstraint *constraint);

          void cpDampedSpringSetStiffness(cpConstraint *constraint, cpFloat stiffness);


          cpFloat cpDampedSpringGetDamping(const cpConstraint *constraint);

          void cpDampedSpringSetDamping(cpConstraint *constraint, cpFloat damping);


          cpDampedSpringForceFunc cpDampedSpringGetSpringForceFunc(const cpConstraint *constraint);

          void cpDampedSpringSetSpringForceFunc(cpConstraint *constraint, cpDampedSpringForceFunc springForceFunc);
          cpBool cpConstraintIsDampedRotarySpring(const cpConstraint *constraint);


typedef cpFloat (*cpDampedRotarySpringTorqueFunc)(struct cpConstraint *spring, cpFloat relativeAngle);


          cpDampedRotarySpring* cpDampedRotarySpringAlloc(void);

          cpDampedRotarySpring* cpDampedRotarySpringInit(cpDampedRotarySpring *joint, cpBody *a, cpBody *b, cpFloat restAngle, cpFloat stiffness, cpFloat damping);

          cpConstraint* cpDampedRotarySpringNew(cpBody *a, cpBody *b, cpFloat restAngle, cpFloat stiffness, cpFloat damping);


          cpFloat cpDampedRotarySpringGetRestAngle(const cpConstraint *constraint);

          void cpDampedRotarySpringSetRestAngle(cpConstraint *constraint, cpFloat restAngle);


          cpFloat cpDampedRotarySpringGetStiffness(const cpConstraint *constraint);

          void cpDampedRotarySpringSetStiffness(cpConstraint *constraint, cpFloat stiffness);


          cpFloat cpDampedRotarySpringGetDamping(const cpConstraint *constraint);

          void cpDampedRotarySpringSetDamping(cpConstraint *constraint, cpFloat damping);


          cpDampedRotarySpringTorqueFunc cpDampedRotarySpringGetSpringTorqueFunc(const cpConstraint *constraint);

          void cpDampedRotarySpringSetSpringTorqueFunc(cpConstraint *constraint, cpDampedRotarySpringTorqueFunc springTorqueFunc);
          cpBool cpConstraintIsRotaryLimitJoint(const cpConstraint *constraint);


          cpRotaryLimitJoint* cpRotaryLimitJointAlloc(void);

          cpRotaryLimitJoint* cpRotaryLimitJointInit(cpRotaryLimitJoint *joint, cpBody *a, cpBody *b, cpFloat min, cpFloat max);

          cpConstraint* cpRotaryLimitJointNew(cpBody *a, cpBody *b, cpFloat min, cpFloat max);


          cpFloat cpRotaryLimitJointGetMin(const cpConstraint *constraint);

          void cpRotaryLimitJointSetMin(cpConstraint *constraint, cpFloat min);


          cpFloat cpRotaryLimitJointGetMax(const cpConstraint *constraint);

          void cpRotaryLimitJointSetMax(cpConstraint *constraint, cpFloat max);
          cpBool cpConstraintIsRatchetJoint(const cpConstraint *constraint);


          cpRatchetJoint* cpRatchetJointAlloc(void);

          cpRatchetJoint* cpRatchetJointInit(cpRatchetJoint *joint, cpBody *a, cpBody *b, cpFloat phase, cpFloat ratchet);

          cpConstraint* cpRatchetJointNew(cpBody *a, cpBody *b, cpFloat phase, cpFloat ratchet);


          cpFloat cpRatchetJointGetAngle(const cpConstraint *constraint);

          void cpRatchetJointSetAngle(cpConstraint *constraint, cpFloat angle);


          cpFloat cpRatchetJointGetPhase(const cpConstraint *constraint);

          void cpRatchetJointSetPhase(cpConstraint *constraint, cpFloat phase);


          cpFloat cpRatchetJointGetRatchet(const cpConstraint *constraint);

          void cpRatchetJointSetRatchet(cpConstraint *constraint, cpFloat ratchet);
          cpBool cpConstraintIsGearJoint(const cpConstraint *constraint);


          cpGearJoint* cpGearJointAlloc(void);

          cpGearJoint* cpGearJointInit(cpGearJoint *joint, cpBody *a, cpBody *b, cpFloat phase, cpFloat ratio);

          cpConstraint* cpGearJointNew(cpBody *a, cpBody *b, cpFloat phase, cpFloat ratio);


          cpFloat cpGearJointGetPhase(const cpConstraint *constraint);

          void cpGearJointSetPhase(cpConstraint *constraint, cpFloat phase);


          cpFloat cpGearJointGetRatio(const cpConstraint *constraint);

          void cpGearJointSetRatio(cpConstraint *constraint, cpFloat ratio);
typedef struct cpSimpleMotor cpSimpleMotor;


          cpBool cpConstraintIsSimpleMotor(const cpConstraint *constraint);


          cpSimpleMotor* cpSimpleMotorAlloc(void);

          cpSimpleMotor* cpSimpleMotorInit(cpSimpleMotor *joint, cpBody *a, cpBody *b, cpFloat rate);

          cpConstraint* cpSimpleMotorNew(cpBody *a, cpBody *b, cpFloat rate);


          cpFloat cpSimpleMotorGetRate(const cpConstraint *constraint);

          void cpSimpleMotorSetRate(cpConstraint *constraint, cpFloat rate);

typedef cpBool (*cpCollisionBeginFunc)(cpArbiter *arb, cpSpace *space, cpDataPointer userData);


typedef cpBool (*cpCollisionPreSolveFunc)(cpArbiter *arb, cpSpace *space, cpDataPointer userData);

typedef void (*cpCollisionPostSolveFunc)(cpArbiter *arb, cpSpace *space, cpDataPointer userData);

typedef void (*cpCollisionSeparateFunc)(cpArbiter *arb, cpSpace *space, cpDataPointer userData);



struct cpCollisionHandler {


 const cpCollisionType typeA;


 const cpCollisionType typeB;

 cpCollisionBeginFunc beginFunc;


 cpCollisionPreSolveFunc preSolveFunc;


 cpCollisionPostSolveFunc postSolveFunc;

 cpCollisionSeparateFunc separateFunc;

 cpDataPointer userData;
};







          cpSpace* cpSpaceAlloc(void);

          cpSpace* cpSpaceInit(cpSpace *space);

          cpSpace* cpSpaceNew(void);


          void cpSpaceDestroy(cpSpace *space);

          void cpSpaceFree(cpSpace *space);





          int cpSpaceGetIterations(const cpSpace *space);
          void cpSpaceSetIterations(cpSpace *space, int iterations);


          cpVect cpSpaceGetGravity(const cpSpace *space);
          void cpSpaceSetGravity(cpSpace *space, cpVect gravity);





          cpFloat cpSpaceGetDamping(const cpSpace *space);
          void cpSpaceSetDamping(cpSpace *space, cpFloat damping);



          cpFloat cpSpaceGetIdleSpeedThreshold(const cpSpace *space);
          void cpSpaceSetIdleSpeedThreshold(cpSpace *space, cpFloat idleSpeedThreshold);




          cpFloat cpSpaceGetSleepTimeThreshold(const cpSpace *space);
          void cpSpaceSetSleepTimeThreshold(cpSpace *space, cpFloat sleepTimeThreshold);





          cpFloat cpSpaceGetCollisionSlop(const cpSpace *space);
          void cpSpaceSetCollisionSlop(cpSpace *space, cpFloat collisionSlop);




          cpFloat cpSpaceGetCollisionBias(const cpSpace *space);
          void cpSpaceSetCollisionBias(cpSpace *space, cpFloat collisionBias);



          cpTimestamp cpSpaceGetCollisionPersistence(const cpSpace *space);
          void cpSpaceSetCollisionPersistence(cpSpace *space, cpTimestamp collisionPersistence);




          cpDataPointer cpSpaceGetUserData(const cpSpace *space);
          void cpSpaceSetUserData(cpSpace *space, cpDataPointer userData);



          cpBody* cpSpaceGetStaticBody(const cpSpace *space);



          cpFloat cpSpaceGetCurrentTimeStep(const cpSpace *space);


          cpBool cpSpaceIsLocked(cpSpace *space);





          cpCollisionHandler *cpSpaceAddDefaultCollisionHandler(cpSpace *space);


          cpCollisionHandler *cpSpaceAddCollisionHandler(cpSpace *space, cpCollisionType a, cpCollisionType b);

          cpCollisionHandler *cpSpaceAddWildcardHandler(cpSpace *space, cpCollisionType type);






          cpShape* cpSpaceAddShape(cpSpace *space, cpShape *shape);

          cpBody* cpSpaceAddBody(cpSpace *space, cpBody *body);

          cpConstraint* cpSpaceAddConstraint(cpSpace *space, cpConstraint *constraint);


          void cpSpaceRemoveShape(cpSpace *space, cpShape *shape);

          void cpSpaceRemoveBody(cpSpace *space, cpBody *body);

          void cpSpaceRemoveConstraint(cpSpace *space, cpConstraint *constraint);


          cpBool cpSpaceContainsShape(cpSpace *space, cpShape *shape);

          cpBool cpSpaceContainsBody(cpSpace *space, cpBody *body);

          cpBool cpSpaceContainsConstraint(cpSpace *space, cpConstraint *constraint);




typedef void (*cpPostStepFunc)(cpSpace *space, void *key, void *data);




          cpBool cpSpaceAddPostStepCallback(cpSpace *space, cpPostStepFunc func, void *key, void *data);
typedef void (*cpSpacePointQueryFunc)(cpShape *shape, cpVect point, cpFloat distance, cpVect gradient, void *data);

          void cpSpacePointQuery(cpSpace *space, cpVect point, cpFloat maxDistance, cpShapeFilter filter, cpSpacePointQueryFunc func, void *data);

          cpShape *cpSpacePointQueryNearest(cpSpace *space, cpVect point, cpFloat maxDistance, cpShapeFilter filter, cpPointQueryInfo *out);


typedef void (*cpSpaceSegmentQueryFunc)(cpShape *shape, cpVect point, cpVect normal, cpFloat alpha, void *data);

          void cpSpaceSegmentQuery(cpSpace *space, cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, cpSpaceSegmentQueryFunc func, void *data);

          cpShape *cpSpaceSegmentQueryFirst(cpSpace *space, cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, cpSegmentQueryInfo *out);


typedef void (*cpSpaceBBQueryFunc)(cpShape *shape, void *data);


          void cpSpaceBBQuery(cpSpace *space, cpBB bb, cpShapeFilter filter, cpSpaceBBQueryFunc func, void *data);


typedef void (*cpSpaceShapeQueryFunc)(cpShape *shape, cpContactPointSet *points, void *data);

          cpBool cpSpaceShapeQuery(cpSpace *space, cpShape *shape, cpSpaceShapeQueryFunc func, void *data);





typedef void (*cpSpaceBodyIteratorFunc)(cpBody *body, void *data);

          void cpSpaceEachBody(cpSpace *space, cpSpaceBodyIteratorFunc func, void *data);


typedef void (*cpSpaceShapeIteratorFunc)(cpShape *shape, void *data);

          void cpSpaceEachShape(cpSpace *space, cpSpaceShapeIteratorFunc func, void *data);


typedef void (*cpSpaceConstraintIteratorFunc)(cpConstraint *constraint, void *data);

          void cpSpaceEachConstraint(cpSpace *space, cpSpaceConstraintIteratorFunc func, void *data);





          void cpSpaceReindexStatic(cpSpace *space);

          void cpSpaceReindexShape(cpSpace *space, cpShape *shape);

          void cpSpaceReindexShapesForBody(cpSpace *space, cpBody *body);


          void cpSpaceUseSpatialHash(cpSpace *space, cpFloat dim, int count);





          void cpSpaceStep(cpSpace *space, cpFloat dt);







typedef struct cpSpaceDebugColor {
 float r, g, b, a;
} cpSpaceDebugColor;


typedef void (*cpSpaceDebugDrawCircleImpl)(cpVect pos, cpFloat angle, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor, cpDataPointer data);

typedef void (*cpSpaceDebugDrawSegmentImpl)(cpVect a, cpVect b, cpSpaceDebugColor color, cpDataPointer data);

typedef void (*cpSpaceDebugDrawFatSegmentImpl)(cpVect a, cpVect b, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor, cpDataPointer data);

typedef void (*cpSpaceDebugDrawPolygonImpl)(int count, const cpVect *verts, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor, cpDataPointer data);

typedef void (*cpSpaceDebugDrawDotImpl)(cpFloat size, cpVect pos, cpSpaceDebugColor color, cpDataPointer data);

typedef cpSpaceDebugColor (*cpSpaceDebugDrawColorForShapeImpl)(cpShape *shape, cpDataPointer data);

typedef enum cpSpaceDebugDrawFlags {
 CP_SPACE_DEBUG_DRAW_SHAPES = 1<<0,
 CP_SPACE_DEBUG_DRAW_CONSTRAINTS = 1<<1,
 CP_SPACE_DEBUG_DRAW_COLLISION_POINTS = 1<<2,
} cpSpaceDebugDrawFlags;


typedef struct cpSpaceDebugDrawOptions {

 cpSpaceDebugDrawCircleImpl drawCircle;

 cpSpaceDebugDrawSegmentImpl drawSegment;

 cpSpaceDebugDrawFatSegmentImpl drawFatSegment;

 cpSpaceDebugDrawPolygonImpl drawPolygon;

 cpSpaceDebugDrawDotImpl drawDot;


 cpSpaceDebugDrawFlags flags;

 cpSpaceDebugColor shapeOutlineColor;

 cpSpaceDebugDrawColorForShapeImpl colorForShape;

 cpSpaceDebugColor constraintColor;

 cpSpaceDebugColor collisionPointColor;


 cpDataPointer data;
} cpSpaceDebugDrawOptions;


          void cpSpaceDebugDraw(cpSpace *space, cpSpaceDebugDrawOptions *options);







          extern const char *cpVersionString;



          cpFloat cpMomentForCircle(cpFloat m, cpFloat r1, cpFloat r2, cpVect offset);



          cpFloat cpAreaForCircle(cpFloat r1, cpFloat r2);



          cpFloat cpMomentForSegment(cpFloat m, cpVect a, cpVect b, cpFloat radius);


          cpFloat cpAreaForSegment(cpVect a, cpVect b, cpFloat radius);


          cpFloat cpMomentForPoly(cpFloat m, int count, const cpVect *verts, cpVect offset, cpFloat radius);



          cpFloat cpAreaForPoly(const int count, const cpVect *verts, cpFloat radius);


          cpVect cpCentroidForPoly(const int count, const cpVect *verts);


          cpFloat cpMomentForBox(cpFloat m, cpFloat width, cpFloat height);


          cpFloat cpMomentForBox2(cpFloat m, cpBB box);





          int cpConvexHull(int count, const cpVect *verts, cpVect *result, int *first, cpFloat tol);
static inline cpVect
cpClosetPointOnSegment(const cpVect p, const cpVect a, const cpVect b)
{
 cpVect delta = cpvsub(a, b);
 cpFloat t = cpfclamp01(cpvdot(delta, cpvsub(p, b))/cpvlengthsq(delta));
 return cpvadd(b, cpvmult(delta, t));
}







void cpSpaceEachBody_b(cpSpace *space, void (^block)(cpBody *body));
void cpSpaceEachShape_b(cpSpace *space, void (^block)(cpShape *shape));
void cpSpaceEachConstraint_b(cpSpace *space, void (^block)(cpConstraint *constraint));

void cpBodyEachShape_b(cpBody *body, void (^block)(cpShape *shape));
void cpBodyEachConstraint_b(cpBody *body, void (^block)(cpConstraint *constraint));
void cpBodyEachArbiter_b(cpBody *body, void (^block)(cpArbiter *arbiter));

typedef void (^cpSpacePointQueryBlock)(cpShape *shape, cpVect point, cpFloat distance, cpVect gradient);
void cpSpacePointQuery_b(cpSpace *space, cpVect point, cpFloat maxDistance, cpShapeFilter filter, cpSpacePointQueryBlock block);

typedef void (^cpSpaceSegmentQueryBlock)(cpShape *shape, cpVect point, cpVect normal, cpFloat alpha);
void cpSpaceSegmentQuery_b(cpSpace *space, cpVect start, cpVect end, cpFloat radius, cpShapeFilter filter, cpSpaceSegmentQueryBlock block);

typedef void (^cpSpaceBBQueryBlock)(cpShape *shape);
void cpSpaceBBQuery_b(cpSpace *space, cpBB bb, cpShapeFilter filter, cpSpaceBBQueryBlock block);

typedef void (^cpSpaceShapeQueryBlock)(cpShape *shape, cpContactPointSet *points);
cpBool cpSpaceShapeQuery_b(cpSpace *space, cpShape *shape, cpSpaceShapeQueryBlock block);
