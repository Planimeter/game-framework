











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
