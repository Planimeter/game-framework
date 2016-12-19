





typedef __signed char int8_t;
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
typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;



typedef long int intmax_t;
typedef long unsigned int uintmax_t;

typedef uint32_t GLbitfield;
typedef uint8_t GLboolean;
typedef int8_t GLbyte;
typedef float GLclampf;
typedef uint32_t GLenum;
typedef float GLfloat;
typedef int32_t GLint;
typedef int16_t GLshort;
typedef int32_t GLsizei;
typedef uint8_t GLubyte;
typedef uint32_t GLuint;
typedef uint16_t GLushort;
typedef void GLvoid;


typedef char GLchar;


typedef char GLcharARB;
typedef void *GLhandleARB;

typedef double GLdouble;
typedef double GLclampd;

typedef int32_t GLfixed;


typedef uint16_t GLhalf;


typedef uint16_t GLhalfARB;


typedef int64_t GLint64;
typedef struct __GLsync *GLsync;
typedef uint64_t GLuint64;


typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;


typedef intptr_t GLintptr;
typedef intptr_t GLsizeiptr;


typedef intptr_t GLintptrARB;
typedef intptr_t GLsizeiptrARB;


extern void glClampColorARB(GLenum target, GLenum clamp);







extern void glDrawBuffersARB(GLsizei n, const GLenum *bufs);
extern void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex);
extern void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex);
extern void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLint base_vertex);
extern void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount, const GLint *base_vertex);
extern void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
extern void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
extern GLboolean glIsRenderbuffer(GLuint renderbuffer);
extern void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
extern void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
extern void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
extern void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
extern GLboolean glIsFramebuffer(GLuint framebuffer);
extern void glBindFramebuffer(GLenum target, GLuint framebuffer);
extern void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
extern void glGenFramebuffers(GLsizei n, GLuint *framebuffers);
extern GLenum glCheckFramebufferStatus(GLenum target);
extern void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
extern void glGenerateMipmap(GLenum target);
extern void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);







extern void glVertexAttribDivisorARB(GLuint index, GLuint divisor);







extern void glSampleCoverageARB(GLclampf value, GLboolean invert);
extern void glActiveTextureARB(GLenum texture);
extern void glClientActiveTextureARB(GLenum texture);
extern void glMultiTexCoord1dARB(GLenum target, GLdouble s);
extern void glMultiTexCoord1dvARB(GLenum target, const GLdouble *v);
extern void glMultiTexCoord1fARB(GLenum target, GLfloat s);
extern void glMultiTexCoord1fvARB(GLenum target, const GLfloat *v);
extern void glMultiTexCoord1iARB(GLenum target, GLint s);
extern void glMultiTexCoord1ivARB(GLenum target, const GLint *v);
extern void glMultiTexCoord1sARB(GLenum target, GLshort s);
extern void glMultiTexCoord1svARB(GLenum target, const GLshort *v);
extern void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
extern void glMultiTexCoord2dvARB(GLenum target, const GLdouble *v);
extern void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
extern void glMultiTexCoord2fvARB(GLenum target, const GLfloat *v);
extern void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
extern void glMultiTexCoord2ivARB(GLenum target, const GLint *v);
extern void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
extern void glMultiTexCoord2svARB(GLenum target, const GLshort *v);
extern void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
extern void glMultiTexCoord3dvARB(GLenum target, const GLdouble *v);
extern void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
extern void glMultiTexCoord3fvARB(GLenum target, const GLfloat *v);
extern void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
extern void glMultiTexCoord3ivARB(GLenum target, const GLint *v);
extern void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
extern void glMultiTexCoord3svARB(GLenum target, const GLshort *v);
extern void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern void glMultiTexCoord4dvARB(GLenum target, const GLdouble *v);
extern void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void glMultiTexCoord4fvARB(GLenum target, const GLfloat *v);
extern void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
extern void glMultiTexCoord4ivARB(GLenum target, const GLint *v);
extern void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
extern void glMultiTexCoord4svARB(GLenum target, const GLshort *v);
extern void glGenQueriesARB(GLsizei n, GLuint *ids);
extern void glDeleteQueriesARB(GLsizei n, const GLuint *ids);
extern GLboolean glIsQueryARB(GLuint id);
extern void glBeginQueryARB(GLenum target, GLuint id);
extern void glEndQueryARB(GLenum target);
extern void glGetQueryivARB(GLenum target, GLenum pname, GLint *params);
extern void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint *params);
extern void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint *params);
extern void glPointParameterfARB(GLenum pname, GLfloat param);
extern void glPointParameterfvARB(GLenum pname, const GLfloat *params);







extern void glProvokingVertex(GLenum mode);
extern void glDeleteObjectARB(GLhandleARB obj);
extern GLhandleARB glGetHandleARB(GLenum pname);
extern void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
extern GLhandleARB glCreateShaderObjectARB(GLenum shaderType);
extern void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB* const *string, const GLint *length);
extern void glCompileShaderARB(GLhandleARB shaderObj);
extern GLhandleARB glCreateProgramObjectARB(void);
extern void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
extern void glLinkProgramARB(GLhandleARB programObj);
extern void glUseProgramObjectARB(GLhandleARB programObj);
extern void glValidateProgramARB(GLhandleARB programObj);
extern void glUniform1fARB(GLint location, GLfloat v0);
extern void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
extern void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void glUniform1iARB(GLint location, GLint v0);
extern void glUniform2iARB(GLint location, GLint v0, GLint v1);
extern void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
extern void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value);
extern void glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value);
extern void glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value);
extern void glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value);
extern void glUniform1ivARB(GLint location, GLsizei count, const GLint *value);
extern void glUniform2ivARB(GLint location, GLsizei count, const GLint *value);
extern void glUniform3ivARB(GLint location, GLsizei count, const GLint *value);
extern void glUniform4ivARB(GLint location, GLsizei count, const GLint *value);
extern void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params);
extern void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params);
extern void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
extern void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
extern GLint glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB *name);
extern void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
extern void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params);
extern void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint *params);
extern void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
extern GLsync glFenceSync(GLenum condition, GLbitfield flags);
extern GLboolean glIsSync(GLsync sync);
extern void glDeleteSync(GLsync sync);
extern GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void glGetInteger64v(GLenum pname, GLint64 *params);
extern void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
extern void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid *data);
extern void glLoadTransposeMatrixfARB(const GLfloat *m);
extern void glLoadTransposeMatrixdARB(const GLdouble *m);
extern void glMultTransposeMatrixfARB(const GLfloat *m);
extern void glMultTransposeMatrixdARB(const GLdouble *m);
extern void glWeightbvARB(GLint size, const GLbyte *weights);
extern void glWeightsvARB(GLint size, const GLshort *weights);
extern void glWeightivARB(GLint size, const GLint *weights);
extern void glWeightfvARB(GLint size, const GLfloat *weights);
extern void glWeightdvARB(GLint size, const GLdouble *weights);
extern void glWeightubvARB(GLint size, const GLubyte *weights);
extern void glWeightusvARB(GLint size, const GLushort *weights);
extern void glWeightuivARB(GLint size, const GLuint *weights);
extern void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glVertexBlendARB(GLint count);
extern void glBindBufferARB(GLenum target, GLuint buffer);
extern void glDeleteBuffersARB(GLsizei n, const GLuint *buffers);
extern void glGenBuffersARB(GLsizei n, GLuint *buffers);
extern GLboolean glIsBufferARB(GLuint buffer);
extern void glBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
extern void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
extern void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
extern GLvoid *glMapBufferARB(GLenum target, GLenum access);
extern GLboolean glUnmapBufferARB(GLenum target);
extern void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint *params);
extern void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid **params);
extern void glBindProgramARB(GLenum target, GLuint program);
extern void glDeleteProgramsARB(GLsizei n, const GLuint *programs);
extern void glGenProgramsARB(GLsizei n, GLuint *programs);
extern GLboolean glIsProgramARB(GLuint program);
extern void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble *params);
extern void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat *params);
extern void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble *params);
extern void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat *params);
extern void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble *params);
extern void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat *params);

extern void glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
extern void glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat *params);

extern void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble *params);
extern void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat *params);
extern void glProgramStringARB(GLenum target, GLenum format, GLsizei len, const GLvoid *string);
extern void glGetProgramStringARB(GLenum target, GLenum pname, GLvoid *string);
extern void glGetProgramivARB(GLenum target, GLenum pname, GLint *params);
extern void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB *name);
extern void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
extern GLint glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB *name);
extern void glVertexAttrib1dARB(GLuint index, GLdouble x);
extern void glVertexAttrib1dvARB(GLuint index, const GLdouble *v);
extern void glVertexAttrib1fARB(GLuint index, GLfloat x);
extern void glVertexAttrib1fvARB(GLuint index, const GLfloat *v);
extern void glVertexAttrib1sARB(GLuint index, GLshort x);
extern void glVertexAttrib1svARB(GLuint index, const GLshort *v);
extern void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
extern void glVertexAttrib2dvARB(GLuint index, const GLdouble *v);
extern void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
extern void glVertexAttrib2fvARB(GLuint index, const GLfloat *v);
extern void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
extern void glVertexAttrib2svARB(GLuint index, const GLshort *v);
extern void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void glVertexAttrib3dvARB(GLuint index, const GLdouble *v);
extern void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void glVertexAttrib3fvARB(GLuint index, const GLfloat *v);
extern void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
extern void glVertexAttrib3svARB(GLuint index, const GLshort *v);
extern void glVertexAttrib4NbvARB(GLuint index, const GLbyte *v);
extern void glVertexAttrib4NivARB(GLuint index, const GLint *v);
extern void glVertexAttrib4NsvARB(GLuint index, const GLshort *v);
extern void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void glVertexAttrib4NubvARB(GLuint index, const GLubyte *v);
extern void glVertexAttrib4NuivARB(GLuint index, const GLuint *v);
extern void glVertexAttrib4NusvARB(GLuint index, const GLushort *v);
extern void glVertexAttrib4bvARB(GLuint index, const GLbyte *v);
extern void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void glVertexAttrib4dvARB(GLuint index, const GLdouble *v);
extern void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void glVertexAttrib4fvARB(GLuint index, const GLfloat *v);
extern void glVertexAttrib4ivARB(GLuint index, const GLint *v);
extern void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void glVertexAttrib4svARB(GLuint index, const GLshort *v);
extern void glVertexAttrib4ubvARB(GLuint index, const GLubyte *v);
extern void glVertexAttrib4uivARB(GLuint index, const GLuint *v);
extern void glVertexAttrib4usvARB(GLuint index, const GLushort *v);
extern void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
extern void glDisableVertexAttribArrayARB(GLuint index);
extern void glEnableVertexAttribArrayARB(GLuint index);
extern void glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid **pointer);
extern void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble *params);
extern void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat *params);
extern void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint *params);
extern void glWindowPos2dARB(GLdouble x, GLdouble y);
extern void glWindowPos2dvARB(const GLdouble *p);
extern void glWindowPos2fARB(GLfloat x, GLfloat y);
extern void glWindowPos2fvARB(const GLfloat *p);
extern void glWindowPos2iARB(GLint x, GLint y);
extern void glWindowPos2ivARB(const GLint *p);
extern void glWindowPos2sARB(GLshort x, GLshort y);
extern void glWindowPos2svARB(const GLshort *p);
extern void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
extern void glWindowPos3dvARB(const GLdouble *p);
extern void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
extern void glWindowPos3fvARB(const GLfloat *p);
extern void glWindowPos3iARB(GLint x, GLint y, GLint z);
extern void glWindowPos3ivARB(const GLint *p);
extern void glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
extern void glWindowPos3svARB(const GLshort *p);
extern void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer);
extern GLint glGetUniformBufferSizeEXT(GLuint program, GLint location);
extern GLintptr glGetUniformOffsetEXT(GLuint program, GLint location);







extern void glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);







extern void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);







extern void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);







extern void glBlendEquationEXT(GLenum mode);
extern void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar *label);
extern void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
extern void glInsertEventMarkerEXT(GLsizei length, const char *marker);
extern void glPushGroupMarkerEXT(GLsizei length, const char *marker);
extern void glPopGroupMarkerEXT(void);







extern void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax);
extern void glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
extern void glEnableIndexedEXT(GLenum target, GLuint index);
extern void glDisableIndexedEXT(GLenum target, GLuint index);
extern GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index);







extern void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
extern void glFogCoordfEXT(GLfloat coord);
extern void glFogCoordfvEXT(const GLfloat *coord);
extern void glFogCoorddEXT(GLdouble coord);
extern void glFogCoorddvEXT(const GLdouble *coord);
extern void glFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer);







extern void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);







extern void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern GLboolean glIsRenderbufferEXT(GLuint renderbuffer);
extern void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
extern void glDeleteRenderbuffersEXT(GLsizei n, const GLuint *renderbuffers);
extern void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers);
extern void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint *params);
extern GLboolean glIsFramebufferEXT(GLuint framebuffer);
extern void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
extern void glDeleteFramebuffersEXT(GLsizei n, const GLuint *framebuffers);
extern void glGenFramebuffersEXT(GLsizei n, GLuint *framebuffers);
extern GLenum glCheckFramebufferStatusEXT(GLenum target);
extern void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params);
extern void glGenerateMipmapEXT(GLenum target);
extern void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
extern void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);







extern void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void glVertexAttribI1iEXT(GLuint index, GLint x);
extern void glVertexAttribI2iEXT(GLuint index, GLint x, GLint y);
extern void glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z);
extern void glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void glVertexAttribI1uiEXT(GLuint index, GLuint x);
extern void glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y);
extern void glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z);
extern void glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void glVertexAttribI1ivEXT(GLuint index, const GLint *v);
extern void glVertexAttribI2ivEXT(GLuint index, const GLint *v);
extern void glVertexAttribI3ivEXT(GLuint index, const GLint *v);
extern void glVertexAttribI4ivEXT(GLuint index, const GLint *v);
extern void glVertexAttribI1uivEXT(GLuint index, const GLuint *v);
extern void glVertexAttribI2uivEXT(GLuint index, const GLuint *v);
extern void glVertexAttribI3uivEXT(GLuint index, const GLuint *v);
extern void glVertexAttribI4uivEXT(GLuint index, const GLuint *v);
extern void glVertexAttribI4bvEXT(GLuint index, const GLbyte *v);
extern void glVertexAttribI4svEXT(GLuint index, const GLshort *v);
extern void glVertexAttribI4ubvEXT(GLuint index, const GLubyte *v);
extern void glVertexAttribI4usvEXT(GLuint index, const GLushort *v);
extern void glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint *params);
extern void glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint *params);
extern void glUniform1uiEXT(GLint location, GLuint v0);
extern void glUniform2uiEXT(GLint location, GLuint v0, GLuint v1);
extern void glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void glUniform1uivEXT(GLint location, GLsizei count, const GLuint *value);
extern void glUniform2uivEXT(GLint location, GLsizei count, const GLuint *value);
extern void glUniform3uivEXT(GLint location, GLsizei count, const GLuint *value);
extern void glUniform4uivEXT(GLint location, GLsizei count, const GLuint *value);
extern void glGetUniformuivEXT(GLuint program, GLint location, GLuint *params);
extern void glBindFragDataLocationEXT(GLuint program, GLuint colorNumber, const GLchar *name);
extern GLint glGetFragDataLocationEXT(GLuint program, const GLchar *name);
extern void glMultiDrawArraysEXT(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
extern void glMultiDrawElementsEXT(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount);
extern void glProvokingVertexEXT(GLenum mode);
extern void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
extern void glSecondaryColor3bvEXT(const GLbyte *v);
extern void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
extern void glSecondaryColor3dvEXT(const GLdouble *v);
extern void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
extern void glSecondaryColor3fvEXT(const GLfloat *v);
extern void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
extern void glSecondaryColor3ivEXT(const GLint *v);
extern void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
extern void glSecondaryColor3svEXT(const GLshort *v);
extern void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
extern void glSecondaryColor3ubvEXT(const GLubyte *v);
extern void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
extern void glSecondaryColor3uivEXT(const GLuint *v);
extern void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
extern void glSecondaryColor3usvEXT(const GLushort *v);
extern void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);







extern void glActiveStencilFaceEXT(GLenum face);
extern void glClearColorIiEXT( GLint r, GLint g, GLint b, GLint a );
extern void glClearColorIuiEXT( GLuint r, GLuint g, GLuint b, GLuint a );
extern void glTexParameterIivEXT( GLenum target, GLenum pname, GLint *params );
extern void glTexParameterIuivEXT( GLenum target, GLenum pname, GLuint *params );
extern void glGetTexParameterIivEXT( GLenum target, GLenum pname, GLint *params);
extern void glGetTexParameterIuivEXT( GLenum target, GLenum pname, GLuint *params);
extern void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT *params);
extern void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT *params);
extern void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
extern void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer);
extern void glBeginTransformFeedbackEXT(GLenum primitiveMode);
extern void glEndTransformFeedbackEXT(void);
extern void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode);
extern void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
extern void glGetIntegerIndexedvEXT(GLenum param, GLuint index, GLint *values);
extern void glGetBooleanIndexedvEXT(GLenum param, GLuint index, GLboolean *values);
extern void glElementPointerAPPLE(GLenum type, const GLvoid *pointer);
extern void glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count);
extern void glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
extern void glMultiDrawElementArrayAPPLE(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
extern void glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
extern void glGenFencesAPPLE(GLsizei n, GLuint *fences);
extern void glDeleteFencesAPPLE(GLsizei n, const GLuint *fences);
extern void glSetFenceAPPLE(GLuint fence);
extern GLboolean glIsFenceAPPLE(GLuint fence);
extern GLboolean glTestFenceAPPLE(GLuint fence);
extern void glFinishFenceAPPLE(GLuint fence);
extern GLboolean glTestObjectAPPLE(GLenum object, GLuint name);
extern void glFinishObjectAPPLE(GLenum object, GLuint name);
extern void glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param);
extern void glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size);
extern void glFlushRenderAPPLE(void);
extern void glFinishRenderAPPLE(void);
extern void glSwapAPPLE(void);
extern GLenum glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
extern GLenum glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
extern void glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint *params);
extern void glTextureRangeAPPLE(GLenum target, GLsizei length, const GLvoid *pointer);
extern void glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid **params);
extern void glBindVertexArrayAPPLE(GLuint id);
extern void glDeleteVertexArraysAPPLE(GLsizei n, const GLuint *ids);
extern void glGenVertexArraysAPPLE(GLsizei n, GLuint *ids);
extern GLboolean glIsVertexArrayAPPLE(GLuint id);
extern void glVertexArrayRangeAPPLE(GLsizei length, const GLvoid *pointer);
extern void glFlushVertexArrayRangeAPPLE(GLsizei length, const GLvoid *pointer);
extern void glVertexArrayParameteriAPPLE(GLenum pname, GLint param);
extern void glPointSizePointerAPPLE(GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glVertexPointSizefAPPLE(GLfloat size);
extern void glEnableVertexAttribAPPLE(GLuint index, GLenum pname);
extern void glDisableVertexAttribAPPLE(GLuint index, GLenum pname);
extern GLboolean glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname);
extern void glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
extern void glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
extern void glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
extern void glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);







extern void glBlendEquationSeparateATI(GLenum equationRGB, GLenum equationAlpha);
extern void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
extern void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
extern void glBeginConditionalRenderNV(GLuint id, GLenum mode);
extern void glEndConditionalRenderNV(void);
extern void glPointParameteriNV(GLenum pname, GLint param);
extern void glPointParameterivNV(GLenum pname, const GLint *params);
extern void glTextureBarrierNV (void);
extern void glAccum (GLenum op, GLfloat value);
extern void glAlphaFunc (GLenum func, GLclampf ref);
extern GLboolean glAreTexturesResident (GLsizei n, const GLuint *textures, GLboolean *residences);
extern void glArrayElement (GLint i);
extern void glBegin (GLenum mode);
extern void glBindTexture (GLenum target, GLuint texture);
extern void glBitmap (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
extern void glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern void glBlendEquation (GLenum mode);
extern void glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
extern void glBlendFunc (GLenum sfactor, GLenum dfactor);
extern void glCallList (GLuint list);
extern void glCallLists (GLsizei n, GLenum type, const GLvoid *lists);
extern void glClear (GLbitfield mask);
extern void glClearAccum (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern void glClearDepth (GLclampd depth);
extern void glClearIndex (GLfloat c);
extern void glClearStencil (GLint s);
extern void glClipPlane (GLenum plane, const GLdouble *equation);
extern void glColor3b (GLbyte red, GLbyte green, GLbyte blue);
extern void glColor3bv (const GLbyte *v);
extern void glColor3d (GLdouble red, GLdouble green, GLdouble blue);
extern void glColor3dv (const GLdouble *v);
extern void glColor3f (GLfloat red, GLfloat green, GLfloat blue);
extern void glColor3fv (const GLfloat *v);
extern void glColor3i (GLint red, GLint green, GLint blue);
extern void glColor3iv (const GLint *v);
extern void glColor3s (GLshort red, GLshort green, GLshort blue);
extern void glColor3sv (const GLshort *v);
extern void glColor3ub (GLubyte red, GLubyte green, GLubyte blue);
extern void glColor3ubv (const GLubyte *v);
extern void glColor3ui (GLuint red, GLuint green, GLuint blue);
extern void glColor3uiv (const GLuint *v);
extern void glColor3us (GLushort red, GLushort green, GLushort blue);
extern void glColor3usv (const GLushort *v);
extern void glColor4b (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
extern void glColor4bv (const GLbyte *v);
extern void glColor4d (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
extern void glColor4dv (const GLdouble *v);
extern void glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void glColor4fv (const GLfloat *v);
extern void glColor4i (GLint red, GLint green, GLint blue, GLint alpha);
extern void glColor4iv (const GLint *v);
extern void glColor4s (GLshort red, GLshort green, GLshort blue, GLshort alpha);
extern void glColor4sv (const GLshort *v);
extern void glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
extern void glColor4ubv (const GLubyte *v);
extern void glColor4ui (GLuint red, GLuint green, GLuint blue, GLuint alpha);
extern void glColor4uiv (const GLuint *v);
extern void glColor4us (GLushort red, GLushort green, GLushort blue, GLushort alpha);
extern void glColor4usv (const GLushort *v);
extern void glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void glColorMaterial (GLenum face, GLenum mode);
extern void glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glColorSubTable (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
extern void glColorTable (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
extern void glColorTableParameterfv (GLenum target, GLenum pname, const GLfloat *params);
extern void glColorTableParameteriv (GLenum target, GLenum pname, const GLint *params);
extern void glConvolutionFilter1D (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
extern void glConvolutionFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
extern void glConvolutionParameterf (GLenum target, GLenum pname, GLfloat params);
extern void glConvolutionParameterfv (GLenum target, GLenum pname, const GLfloat *params);
extern void glConvolutionParameteri (GLenum target, GLenum pname, GLint params);
extern void glConvolutionParameteriv (GLenum target, GLenum pname, const GLint *params);
extern void glCopyColorSubTable (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
extern void glCopyColorTable (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
extern void glCopyConvolutionFilter1D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
extern void glCopyConvolutionFilter2D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
extern void glCopyPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
extern void glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void glCullFace (GLenum mode);
extern void glDeleteLists (GLuint list, GLsizei range);
extern void glDeleteTextures (GLsizei n, const GLuint *textures);
extern void glDepthFunc (GLenum func);
extern void glDepthMask (GLboolean flag);
extern void glDepthRange (GLclampd zNear, GLclampd zFar);
extern void glDisable (GLenum cap);
extern void glDisableClientState (GLenum array);
extern void glDrawArrays (GLenum mode, GLint first, GLsizei count);
extern void glDrawBuffer (GLenum mode);
extern void glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
extern void glDrawPixels (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern void glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
extern void glEdgeFlag (GLboolean flag);
extern void glEdgeFlagPointer (GLsizei stride, const GLvoid *pointer);
extern void glEdgeFlagv (const GLboolean *flag);
extern void glEnable (GLenum cap);
extern void glEnableClientState (GLenum array);
extern void glEnd (void);
extern void glEndList (void);
extern void glEvalCoord1d (GLdouble u);
extern void glEvalCoord1dv (const GLdouble *u);
extern void glEvalCoord1f (GLfloat u);
extern void glEvalCoord1fv (const GLfloat *u);
extern void glEvalCoord2d (GLdouble u, GLdouble v);
extern void glEvalCoord2dv (const GLdouble *u);
extern void glEvalCoord2f (GLfloat u, GLfloat v);
extern void glEvalCoord2fv (const GLfloat *u);
extern void glEvalMesh1 (GLenum mode, GLint i1, GLint i2);
extern void glEvalMesh2 (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
extern void glEvalPoint1 (GLint i);
extern void glEvalPoint2 (GLint i, GLint j);
extern void glFeedbackBuffer (GLsizei size, GLenum type, GLfloat *buffer);
extern void glFinish (void);
extern void glFlush (void);
extern void glFogf (GLenum pname, GLfloat param);
extern void glFogfv (GLenum pname, const GLfloat *params);
extern void glFogi (GLenum pname, GLint param);
extern void glFogiv (GLenum pname, const GLint *params);
extern void glFrontFace (GLenum mode);
extern void glFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern GLuint glGenLists (GLsizei range);
extern void glGenTextures (GLsizei n, GLuint *textures);
extern void glGetBooleanv (GLenum pname, GLboolean *params);
extern void glGetClipPlane (GLenum plane, GLdouble *equation);
extern void glGetColorTable (GLenum target, GLenum format, GLenum type, GLvoid *table);
extern void glGetColorTableParameterfv (GLenum target, GLenum pname, GLfloat *params);
extern void glGetColorTableParameteriv (GLenum target, GLenum pname, GLint *params);
extern void glGetConvolutionFilter (GLenum target, GLenum format, GLenum type, GLvoid *image);
extern void glGetConvolutionParameterfv (GLenum target, GLenum pname, GLfloat *params);
extern void glGetConvolutionParameteriv (GLenum target, GLenum pname, GLint *params);
extern void glGetDoublev (GLenum pname, GLdouble *params);
extern GLenum glGetError (void);
extern void glGetFloatv (GLenum pname, GLfloat *params);
extern void glGetHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
extern void glGetHistogramParameterfv (GLenum target, GLenum pname, GLfloat *params);
extern void glGetHistogramParameteriv (GLenum target, GLenum pname, GLint *params);
extern void glGetIntegerv (GLenum pname, GLint *params);
extern void glGetLightfv (GLenum light, GLenum pname, GLfloat *params);
extern void glGetLightiv (GLenum light, GLenum pname, GLint *params);
extern void glGetMapdv (GLenum target, GLenum query, GLdouble *v);
extern void glGetMapfv (GLenum target, GLenum query, GLfloat *v);
extern void glGetMapiv (GLenum target, GLenum query, GLint *v);
extern void glGetMaterialfv (GLenum face, GLenum pname, GLfloat *params);
extern void glGetMaterialiv (GLenum face, GLenum pname, GLint *params);
extern void glGetMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
extern void glGetMinmaxParameterfv (GLenum target, GLenum pname, GLfloat *params);
extern void glGetMinmaxParameteriv (GLenum target, GLenum pname, GLint *params);
extern void glGetPixelMapfv (GLenum map, GLfloat *values);
extern void glGetPixelMapuiv (GLenum map, GLuint *values);
extern void glGetPixelMapusv (GLenum map, GLushort *values);
extern void glGetPointerv (GLenum pname, GLvoid **params);
extern void glGetPolygonStipple (GLubyte *mask);
extern void glGetSeparableFilter (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
extern const GLubyte *glGetString (GLenum name);
extern void glGetTexEnvfv (GLenum target, GLenum pname, GLfloat *params);
extern void glGetTexEnviv (GLenum target, GLenum pname, GLint *params);
extern void glGetTexGendv (GLenum coord, GLenum pname, GLdouble *params);
extern void glGetTexGenfv (GLenum coord, GLenum pname, GLfloat *params);
extern void glGetTexGeniv (GLenum coord, GLenum pname, GLint *params);
extern void glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
extern void glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
extern void glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
extern void glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
extern void glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
extern void glHint (GLenum target, GLenum mode);
extern void glHistogram (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
extern void glIndexMask (GLuint mask);
extern void glIndexPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glIndexd (GLdouble c);
extern void glIndexdv (const GLdouble *c);
extern void glIndexf (GLfloat c);
extern void glIndexfv (const GLfloat *c);
extern void glIndexi (GLint c);
extern void glIndexiv (const GLint *c);
extern void glIndexs (GLshort c);
extern void glIndexsv (const GLshort *c);
extern void glIndexub (GLubyte c);
extern void glIndexubv (const GLubyte *c);
extern void glInitNames (void);
extern void glInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer);
extern GLboolean glIsEnabled (GLenum cap);
extern GLboolean glIsList (GLuint list);
extern GLboolean glIsTexture (GLuint texture);
extern void glLightModelf (GLenum pname, GLfloat param);
extern void glLightModelfv (GLenum pname, const GLfloat *params);
extern void glLightModeli (GLenum pname, GLint param);
extern void glLightModeliv (GLenum pname, const GLint *params);
extern void glLightf (GLenum light, GLenum pname, GLfloat param);
extern void glLightfv (GLenum light, GLenum pname, const GLfloat *params);
extern void glLighti (GLenum light, GLenum pname, GLint param);
extern void glLightiv (GLenum light, GLenum pname, const GLint *params);
extern void glLineStipple (GLint factor, GLushort pattern);
extern void glLineWidth (GLfloat width);
extern void glListBase (GLuint base);
extern void glLoadIdentity (void);
extern void glLoadMatrixd (const GLdouble *m);
extern void glLoadMatrixf (const GLfloat *m);
extern void glLoadName (GLuint name);
extern void glLogicOp (GLenum opcode);
extern void glMap1d (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
extern void glMap1f (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
extern void glMap2d (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
extern void glMap2f (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
extern void glMapGrid1d (GLint un, GLdouble u1, GLdouble u2);
extern void glMapGrid1f (GLint un, GLfloat u1, GLfloat u2);
extern void glMapGrid2d (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
extern void glMapGrid2f (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
extern void glMaterialf (GLenum face, GLenum pname, GLfloat param);
extern void glMaterialfv (GLenum face, GLenum pname, const GLfloat *params);
extern void glMateriali (GLenum face, GLenum pname, GLint param);
extern void glMaterialiv (GLenum face, GLenum pname, const GLint *params);
extern void glMatrixMode (GLenum mode);
extern void glMinmax (GLenum target, GLenum internalformat, GLboolean sink);
extern void glMultMatrixd (const GLdouble *m);
extern void glMultMatrixf (const GLfloat *m);
extern void glNewList (GLuint list, GLenum mode);
extern void glNormal3b (GLbyte nx, GLbyte ny, GLbyte nz);
extern void glNormal3bv (const GLbyte *v);
extern void glNormal3d (GLdouble nx, GLdouble ny, GLdouble nz);
extern void glNormal3dv (const GLdouble *v);
extern void glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz);
extern void glNormal3fv (const GLfloat *v);
extern void glNormal3i (GLint nx, GLint ny, GLint nz);
extern void glNormal3iv (const GLint *v);
extern void glNormal3s (GLshort nx, GLshort ny, GLshort nz);
extern void glNormal3sv (const GLshort *v);
extern void glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern void glPassThrough (GLfloat token);
extern void glPixelMapfv (GLenum map, GLint mapsize, const GLfloat *values);
extern void glPixelMapuiv (GLenum map, GLint mapsize, const GLuint *values);
extern void glPixelMapusv (GLenum map, GLint mapsize, const GLushort *values);
extern void glPixelStoref (GLenum pname, GLfloat param);
extern void glPixelStorei (GLenum pname, GLint param);
extern void glPixelTransferf (GLenum pname, GLfloat param);
extern void glPixelTransferi (GLenum pname, GLint param);
extern void glPixelZoom (GLfloat xfactor, GLfloat yfactor);
extern void glPointSize (GLfloat size);
extern void glPolygonMode (GLenum face, GLenum mode);
extern void glPolygonOffset (GLfloat factor, GLfloat units);
extern void glPolygonStipple (const GLubyte *mask);
extern void glPopAttrib (void);
extern void glPopClientAttrib (void);
extern void glPopMatrix (void);
extern void glPopName (void);
extern void glPrioritizeTextures (GLsizei n, const GLuint *textures, const GLclampf *priorities);
extern void glPushAttrib (GLbitfield mask);
extern void glPushClientAttrib (GLbitfield mask);
extern void glPushMatrix (void);
extern void glPushName (GLuint name);
extern void glRasterPos2d (GLdouble x, GLdouble y);
extern void glRasterPos2dv (const GLdouble *v);
extern void glRasterPos2f (GLfloat x, GLfloat y);
extern void glRasterPos2fv (const GLfloat *v);
extern void glRasterPos2i (GLint x, GLint y);
extern void glRasterPos2iv (const GLint *v);
extern void glRasterPos2s (GLshort x, GLshort y);
extern void glRasterPos2sv (const GLshort *v);
extern void glRasterPos3d (GLdouble x, GLdouble y, GLdouble z);
extern void glRasterPos3dv (const GLdouble *v);
extern void glRasterPos3f (GLfloat x, GLfloat y, GLfloat z);
extern void glRasterPos3fv (const GLfloat *v);
extern void glRasterPos3i (GLint x, GLint y, GLint z);
extern void glRasterPos3iv (const GLint *v);
extern void glRasterPos3s (GLshort x, GLshort y, GLshort z);
extern void glRasterPos3sv (const GLshort *v);
extern void glRasterPos4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void glRasterPos4dv (const GLdouble *v);
extern void glRasterPos4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void glRasterPos4fv (const GLfloat *v);
extern void glRasterPos4i (GLint x, GLint y, GLint z, GLint w);
extern void glRasterPos4iv (const GLint *v);
extern void glRasterPos4s (GLshort x, GLshort y, GLshort z, GLshort w);
extern void glRasterPos4sv (const GLshort *v);
extern void glReadBuffer (GLenum mode);
extern void glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
extern void glRectd (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
extern void glRectdv (const GLdouble *v1, const GLdouble *v2);
extern void glRectf (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
extern void glRectfv (const GLfloat *v1, const GLfloat *v2);
extern void glRecti (GLint x1, GLint y1, GLint x2, GLint y2);
extern void glRectiv (const GLint *v1, const GLint *v2);
extern void glRects (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
extern void glRectsv (const GLshort *v1, const GLshort *v2);
extern GLint glRenderMode (GLenum mode);
extern void glResetHistogram (GLenum target);
extern void glResetMinmax (GLenum target);
extern void glRotated (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
extern void glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void glScaled (GLdouble x, GLdouble y, GLdouble z);
extern void glScalef (GLfloat x, GLfloat y, GLfloat z);
extern void glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
extern void glSelectBuffer (GLsizei size, GLuint *buffer);
extern void glSeparableFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
extern void glShadeModel (GLenum mode);
extern void glStencilFunc (GLenum func, GLint ref, GLuint mask);
extern void glStencilMask (GLuint mask);
extern void glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
extern void glTexCoord1d (GLdouble s);
extern void glTexCoord1dv (const GLdouble *v);
extern void glTexCoord1f (GLfloat s);
extern void glTexCoord1fv (const GLfloat *v);
extern void glTexCoord1i (GLint s);
extern void glTexCoord1iv (const GLint *v);
extern void glTexCoord1s (GLshort s);
extern void glTexCoord1sv (const GLshort *v);
extern void glTexCoord2d (GLdouble s, GLdouble t);
extern void glTexCoord2dv (const GLdouble *v);
extern void glTexCoord2f (GLfloat s, GLfloat t);
extern void glTexCoord2fv (const GLfloat *v);
extern void glTexCoord2i (GLint s, GLint t);
extern void glTexCoord2iv (const GLint *v);
extern void glTexCoord2s (GLshort s, GLshort t);
extern void glTexCoord2sv (const GLshort *v);
extern void glTexCoord3d (GLdouble s, GLdouble t, GLdouble r);
extern void glTexCoord3dv (const GLdouble *v);
extern void glTexCoord3f (GLfloat s, GLfloat t, GLfloat r);
extern void glTexCoord3fv (const GLfloat *v);
extern void glTexCoord3i (GLint s, GLint t, GLint r);
extern void glTexCoord3iv (const GLint *v);
extern void glTexCoord3s (GLshort s, GLshort t, GLshort r);
extern void glTexCoord3sv (const GLshort *v);
extern void glTexCoord4d (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern void glTexCoord4dv (const GLdouble *v);
extern void glTexCoord4f (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void glTexCoord4fv (const GLfloat *v);
extern void glTexCoord4i (GLint s, GLint t, GLint r, GLint q);
extern void glTexCoord4iv (const GLint *v);
extern void glTexCoord4s (GLshort s, GLshort t, GLshort r, GLshort q);
extern void glTexCoord4sv (const GLshort *v);
extern void glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glTexEnvf (GLenum target, GLenum pname, GLfloat param);
extern void glTexEnvfv (GLenum target, GLenum pname, const GLfloat *params);
extern void glTexEnvi (GLenum target, GLenum pname, GLint param);
extern void glTexEnviv (GLenum target, GLenum pname, const GLint *params);
extern void glTexGend (GLenum coord, GLenum pname, GLdouble param);
extern void glTexGendv (GLenum coord, GLenum pname, const GLdouble *params);
extern void glTexGenf (GLenum coord, GLenum pname, GLfloat param);
extern void glTexGenfv (GLenum coord, GLenum pname, const GLfloat *params);
extern void glTexGeni (GLenum coord, GLenum pname, GLint param);
extern void glTexGeniv (GLenum coord, GLenum pname, const GLint *params);
extern void glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTexParameterf (GLenum target, GLenum pname, GLfloat param);
extern void glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
extern void glTexParameteri (GLenum target, GLenum pname, GLint param);
extern void glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
extern void glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTranslated (GLdouble x, GLdouble y, GLdouble z);
extern void glTranslatef (GLfloat x, GLfloat y, GLfloat z);
extern void glVertex2d (GLdouble x, GLdouble y);
extern void glVertex2dv (const GLdouble *v);
extern void glVertex2f (GLfloat x, GLfloat y);
extern void glVertex2fv (const GLfloat *v);
extern void glVertex2i (GLint x, GLint y);
extern void glVertex2iv (const GLint *v);
extern void glVertex2s (GLshort x, GLshort y);
extern void glVertex2sv (const GLshort *v);
extern void glVertex3d (GLdouble x, GLdouble y, GLdouble z);
extern void glVertex3dv (const GLdouble *v);
extern void glVertex3f (GLfloat x, GLfloat y, GLfloat z);
extern void glVertex3fv (const GLfloat *v);
extern void glVertex3i (GLint x, GLint y, GLint z);
extern void glVertex3iv (const GLint *v);
extern void glVertex3s (GLshort x, GLshort y, GLshort z);
extern void glVertex3sv (const GLshort *v);
extern void glVertex4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void glVertex4dv (const GLdouble *v);
extern void glVertex4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void glVertex4fv (const GLfloat *v);
extern void glVertex4i (GLint x, GLint y, GLint z, GLint w);
extern void glVertex4iv (const GLint *v);
extern void glVertex4s (GLshort x, GLshort y, GLshort z, GLshort w);
extern void glVertex4sv (const GLshort *v);
extern void glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glViewport (GLint x, GLint y, GLsizei width, GLsizei height);

extern void glSampleCoverage (GLclampf value, GLboolean invert);

extern void glLoadTransposeMatrixf (const GLfloat *m);
extern void glLoadTransposeMatrixd (const GLdouble *m);
extern void glMultTransposeMatrixf (const GLfloat *m);
extern void glMultTransposeMatrixd (const GLdouble *m);

extern void glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glGetCompressedTexImage (GLenum target, GLint lod, GLvoid *img);

extern void glActiveTexture (GLenum texture);
extern void glClientActiveTexture (GLenum texture);
extern void glMultiTexCoord1d (GLenum target, GLdouble s);
extern void glMultiTexCoord1dv (GLenum target, const GLdouble *v);
extern void glMultiTexCoord1f (GLenum target, GLfloat s);
extern void glMultiTexCoord1fv (GLenum target, const GLfloat *v);
extern void glMultiTexCoord1i (GLenum target, GLint s);
extern void glMultiTexCoord1iv (GLenum target, const GLint *v);
extern void glMultiTexCoord1s (GLenum target, GLshort s);
extern void glMultiTexCoord1sv (GLenum target, const GLshort *v);
extern void glMultiTexCoord2d (GLenum target, GLdouble s, GLdouble t);
extern void glMultiTexCoord2dv (GLenum target, const GLdouble *v);
extern void glMultiTexCoord2f (GLenum target, GLfloat s, GLfloat t);
extern void glMultiTexCoord2fv (GLenum target, const GLfloat *v);
extern void glMultiTexCoord2i (GLenum target, GLint s, GLint t);
extern void glMultiTexCoord2iv (GLenum target, const GLint *v);
extern void glMultiTexCoord2s (GLenum target, GLshort s, GLshort t);
extern void glMultiTexCoord2sv (GLenum target, const GLshort *v);
extern void glMultiTexCoord3d (GLenum target, GLdouble s, GLdouble t, GLdouble r);
extern void glMultiTexCoord3dv (GLenum target, const GLdouble *v);
extern void glMultiTexCoord3f (GLenum target, GLfloat s, GLfloat t, GLfloat r);
extern void glMultiTexCoord3fv (GLenum target, const GLfloat *v);
extern void glMultiTexCoord3i (GLenum target, GLint s, GLint t, GLint r);
extern void glMultiTexCoord3iv (GLenum target, const GLint *v);
extern void glMultiTexCoord3s (GLenum target, GLshort s, GLshort t, GLshort r);
extern void glMultiTexCoord3sv (GLenum target, const GLshort *v);
extern void glMultiTexCoord4d (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern void glMultiTexCoord4dv (GLenum target, const GLdouble *v);
extern void glMultiTexCoord4f (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void glMultiTexCoord4fv (GLenum target, const GLfloat *v);
extern void glMultiTexCoord4i (GLenum target, GLint s, GLint t, GLint r, GLint q);
extern void glMultiTexCoord4iv (GLenum target, const GLint *v);
extern void glMultiTexCoord4s (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
extern void glMultiTexCoord4sv (GLenum target, const GLshort *v);

extern void glFogCoordf (GLfloat coord);
extern void glFogCoordfv (const GLfloat *coord);
extern void glFogCoordd (GLdouble coord);
extern void glFogCoorddv (const GLdouble *coord);
extern void glFogCoordPointer (GLenum type, GLsizei stride, const GLvoid *pointer);

extern void glSecondaryColor3b (GLbyte red, GLbyte green, GLbyte blue);
extern void glSecondaryColor3bv (const GLbyte *v);
extern void glSecondaryColor3d (GLdouble red, GLdouble green, GLdouble blue);
extern void glSecondaryColor3dv (const GLdouble *v);
extern void glSecondaryColor3f (GLfloat red, GLfloat green, GLfloat blue);
extern void glSecondaryColor3fv (const GLfloat *v);
extern void glSecondaryColor3i (GLint red, GLint green, GLint blue);
extern void glSecondaryColor3iv (const GLint *v);
extern void glSecondaryColor3s (GLshort red, GLshort green, GLshort blue);
extern void glSecondaryColor3sv (const GLshort *v);
extern void glSecondaryColor3ub (GLubyte red, GLubyte green, GLubyte blue);
extern void glSecondaryColor3ubv (const GLubyte *v);
extern void glSecondaryColor3ui (GLuint red, GLuint green, GLuint blue);
extern void glSecondaryColor3uiv (const GLuint *v);
extern void glSecondaryColor3us (GLushort red, GLushort green, GLushort blue);
extern void glSecondaryColor3usv (const GLushort *v);
extern void glSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

extern void glPointParameterf (GLenum pname, GLfloat param);
extern void glPointParameterfv (GLenum pname, const GLfloat *params);
extern void glPointParameteri (GLenum pname, GLint param);
extern void glPointParameteriv (GLenum pname, const GLint *params);

extern void glBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

extern void glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
extern void glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount);

extern void glWindowPos2d (GLdouble x, GLdouble y);
extern void glWindowPos2dv (const GLdouble *v);
extern void glWindowPos2f (GLfloat x, GLfloat y);
extern void glWindowPos2fv (const GLfloat *v);
extern void glWindowPos2i (GLint x, GLint y);
extern void glWindowPos2iv (const GLint *v);
extern void glWindowPos2s (GLshort x, GLshort y);
extern void glWindowPos2sv (const GLshort *v);
extern void glWindowPos3d (GLdouble x, GLdouble y, GLdouble z);
extern void glWindowPos3dv (const GLdouble *v);
extern void glWindowPos3f (GLfloat x, GLfloat y, GLfloat z);
extern void glWindowPos3fv (const GLfloat *v);
extern void glWindowPos3i (GLint x, GLint y, GLint z);
extern void glWindowPos3iv (const GLint *v);
extern void glWindowPos3s (GLshort x, GLshort y, GLshort z);
extern void glWindowPos3sv (const GLshort *v);

extern void glGenQueries (GLsizei n, GLuint *ids);
extern void glDeleteQueries (GLsizei n, const GLuint *ids);
extern GLboolean glIsQuery (GLuint id);
extern void glBeginQuery (GLenum target, GLuint id);
extern void glEndQuery (GLenum target);
extern void glGetQueryiv (GLenum target, GLenum pname, GLint *params);
extern void glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
extern void glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);

extern void glBindBuffer (GLenum target, GLuint buffer);
extern void glDeleteBuffers (GLsizei n, const GLuint *buffers);
extern void glGenBuffers (GLsizei n, GLuint *buffers);
extern GLboolean glIsBuffer (GLuint buffer);
extern void glBufferData (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
extern void glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
extern void glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
extern GLvoid *glMapBuffer (GLenum target, GLenum access);
extern GLboolean glUnmapBuffer (GLenum target);
extern void glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
extern void glGetBufferPointerv (GLenum target, GLenum pname, GLvoid **params);

extern void glDrawBuffers (GLsizei n, const GLenum *bufs);
extern void glVertexAttrib1d (GLuint index, GLdouble x);
extern void glVertexAttrib1dv (GLuint index, const GLdouble *v);
extern void glVertexAttrib1f (GLuint index, GLfloat x);
extern void glVertexAttrib1fv (GLuint index, const GLfloat *v);
extern void glVertexAttrib1s (GLuint index, GLshort x);
extern void glVertexAttrib1sv (GLuint index, const GLshort *v);
extern void glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
extern void glVertexAttrib2dv (GLuint index, const GLdouble *v);
extern void glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
extern void glVertexAttrib2fv (GLuint index, const GLfloat *v);
extern void glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
extern void glVertexAttrib2sv (GLuint index, const GLshort *v);
extern void glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void glVertexAttrib3dv (GLuint index, const GLdouble *v);
extern void glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void glVertexAttrib3fv (GLuint index, const GLfloat *v);
extern void glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
extern void glVertexAttrib3sv (GLuint index, const GLshort *v);
extern void glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
extern void glVertexAttrib4Niv (GLuint index, const GLint *v);
extern void glVertexAttrib4Nsv (GLuint index, const GLshort *v);
extern void glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
extern void glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
extern void glVertexAttrib4Nusv (GLuint index, const GLushort *v);
extern void glVertexAttrib4bv (GLuint index, const GLbyte *v);
extern void glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void glVertexAttrib4dv (GLuint index, const GLdouble *v);
extern void glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void glVertexAttrib4fv (GLuint index, const GLfloat *v);
extern void glVertexAttrib4iv (GLuint index, const GLint *v);
extern void glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void glVertexAttrib4sv (GLuint index, const GLshort *v);
extern void glVertexAttrib4ubv (GLuint index, const GLubyte *v);
extern void glVertexAttrib4uiv (GLuint index, const GLuint *v);
extern void glVertexAttrib4usv (GLuint index, const GLushort *v);
extern void glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
extern void glEnableVertexAttribArray (GLuint index);
extern void glDisableVertexAttribArray (GLuint index);
extern void glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
extern void glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
extern void glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
extern void glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid **pointer);
extern void glDeleteShader (GLuint shader);
extern void glDetachShader (GLuint program, GLuint shader);
extern GLuint glCreateShader (GLenum type);
extern void glShaderSource (GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length);
extern void glCompileShader (GLuint shader);
extern GLuint glCreateProgram (void);
extern void glAttachShader (GLuint program, GLuint shader);
extern void glLinkProgram (GLuint program);
extern void glUseProgram (GLuint program);
extern void glDeleteProgram (GLuint program);
extern void glValidateProgram (GLuint program);
extern void glUniform1f (GLint location, GLfloat v0);
extern void glUniform2f (GLint location, GLfloat v0, GLfloat v1);
extern void glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void glUniform1i (GLint location, GLint v0);
extern void glUniform2i (GLint location, GLint v0, GLint v1);
extern void glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
extern void glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
extern void glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
extern void glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
extern void glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
extern void glUniform1iv (GLint location, GLsizei count, const GLint *value);
extern void glUniform2iv (GLint location, GLsizei count, const GLint *value);
extern void glUniform3iv (GLint location, GLsizei count, const GLint *value);
extern void glUniform4iv (GLint location, GLsizei count, const GLint *value);
extern void glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern GLboolean glIsShader (GLuint shader);
extern GLboolean glIsProgram (GLuint program);
extern void glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
extern void glGetProgramiv (GLuint program, GLenum pname, GLint *params);
extern void glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
extern void glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern void glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern GLint glGetUniformLocation (GLuint program, const GLchar *name);
extern void glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
extern void glGetUniformfv (GLuint program, GLint location, GLfloat *params);
extern void glGetUniformiv (GLuint program, GLint location, GLint *params);
extern void glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
extern void glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
extern void glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
extern GLint glGetAttribLocation (GLuint program, const GLchar *name);
extern void glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
extern void glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
extern void glStencilMaskSeparate (GLenum face, GLuint mask);

extern void glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern void glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
