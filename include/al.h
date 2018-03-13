typedef char ALboolean;


typedef char ALchar;


typedef char ALbyte;


typedef unsigned char ALubyte;


typedef short ALshort;


typedef unsigned short ALushort;


typedef int ALint;


typedef unsigned int ALuint;


typedef int ALsizei;


typedef int ALenum;


typedef float ALfloat;


typedef double ALdouble;


typedef void ALvoid;
extern void alEnable( ALenum capability );

extern void alDisable( ALenum capability );

extern ALboolean alIsEnabled( ALenum capability );





extern const ALchar* alGetString( ALenum param );

extern void alGetBooleanv( ALenum param, ALboolean* data );

extern void alGetIntegerv( ALenum param, ALint* data );

extern void alGetFloatv( ALenum param, ALfloat* data );

extern void alGetDoublev( ALenum param, ALdouble* data );

extern ALboolean alGetBoolean( ALenum param );

extern ALint alGetInteger( ALenum param );

extern ALfloat alGetFloat( ALenum param );

extern ALdouble alGetDouble( ALenum param );






extern ALenum alGetError( void );







extern ALboolean alIsExtensionPresent( const ALchar* extname );

extern void* alGetProcAddress( const ALchar* fname );

extern ALenum alGetEnumValue( const ALchar* ename );
extern void alListenerf( ALenum param, ALfloat value );

extern void alListener3f( ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );

extern void alListenerfv( ALenum param, const ALfloat* values );

extern void alListeneri( ALenum param, ALint value );

extern void alListener3i( ALenum param, ALint value1, ALint value2, ALint value3 );

extern void alListeneriv( ALenum param, const ALint* values );




extern void alGetListenerf( ALenum param, ALfloat* value );

extern void alGetListener3f( ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3 );

extern void alGetListenerfv( ALenum param, ALfloat* values );

extern void alGetListeneri( ALenum param, ALint* value );

extern void alGetListener3i( ALenum param, ALint *value1, ALint *value2, ALint *value3 );

extern void alGetListeneriv( ALenum param, ALint* values );
extern void alGenSources( ALsizei n, ALuint* sources );


extern void alDeleteSources( ALsizei n, const ALuint* sources );


extern ALboolean alIsSource( ALuint sid );




extern void alSourcef( ALuint sid, ALenum param, ALfloat value );

extern void alSource3f( ALuint sid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );

extern void alSourcefv( ALuint sid, ALenum param, const ALfloat* values );

extern void alSourcei( ALuint sid, ALenum param, ALint value );

extern void alSource3i( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 );

extern void alSourceiv( ALuint sid, ALenum param, const ALint* values );




extern void alGetSourcef( ALuint sid, ALenum param, ALfloat* value );

extern void alGetSource3f( ALuint sid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);

extern void alGetSourcefv( ALuint sid, ALenum param, ALfloat* values );

extern void alGetSourcei( ALuint sid, ALenum param, ALint* value );

extern void alGetSource3i( ALuint sid, ALenum param, ALint* value1, ALint* value2, ALint* value3);

extern void alGetSourceiv( ALuint sid, ALenum param, ALint* values );







extern void alSourcePlayv( ALsizei ns, const ALuint *sids );


extern void alSourceStopv( ALsizei ns, const ALuint *sids );


extern void alSourceRewindv( ALsizei ns, const ALuint *sids );


extern void alSourcePausev( ALsizei ns, const ALuint *sids );






extern void alSourcePlay( ALuint sid );


extern void alSourceStop( ALuint sid );


extern void alSourceRewind( ALuint sid );


extern void alSourcePause( ALuint sid );




extern void alSourceQueueBuffers( ALuint sid, ALsizei numEntries, const ALuint *bids );

extern void alSourceUnqueueBuffers( ALuint sid, ALsizei numEntries, ALuint *bids );
extern void alGenBuffers( ALsizei n, ALuint* buffers );


extern void alDeleteBuffers( ALsizei n, const ALuint* buffers );


extern ALboolean alIsBuffer( ALuint bid );


extern void alBufferData( ALuint bid, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq );




extern void alBufferf( ALuint bid, ALenum param, ALfloat value );

extern void alBuffer3f( ALuint bid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );

extern void alBufferfv( ALuint bid, ALenum param, const ALfloat* values );

extern void alBufferi( ALuint bid, ALenum param, ALint value );

extern void alBuffer3i( ALuint bid, ALenum param, ALint value1, ALint value2, ALint value3 );

extern void alBufferiv( ALuint bid, ALenum param, const ALint* values );




extern void alGetBufferf( ALuint bid, ALenum param, ALfloat* value );

extern void alGetBuffer3f( ALuint bid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);

extern void alGetBufferfv( ALuint bid, ALenum param, ALfloat* values );

extern void alGetBufferi( ALuint bid, ALenum param, ALint* value );

extern void alGetBuffer3i( ALuint bid, ALenum param, ALint* value1, ALint* value2, ALint* value3);

extern void alGetBufferiv( ALuint bid, ALenum param, ALint* values );





extern void alDopplerFactor( ALfloat value );

extern void alDopplerVelocity( ALfloat value );

extern void alSpeedOfSound( ALfloat value );

extern void alDistanceModel( ALenum distanceModel );




typedef void ( *LPALENABLE)( ALenum capability );
typedef void ( *LPALDISABLE)( ALenum capability );
typedef ALboolean ( *LPALISENABLED)( ALenum capability );
typedef const ALchar* ( *LPALGETSTRING)( ALenum param );
typedef void ( *LPALGETBOOLEANV)( ALenum param, ALboolean* data );
typedef void ( *LPALGETINTEGERV)( ALenum param, ALint* data );
typedef void ( *LPALGETFLOATV)( ALenum param, ALfloat* data );
typedef void ( *LPALGETDOUBLEV)( ALenum param, ALdouble* data );
typedef ALboolean ( *LPALGETBOOLEAN)( ALenum param );
typedef ALint ( *LPALGETINTEGER)( ALenum param );
typedef ALfloat ( *LPALGETFLOAT)( ALenum param );
typedef ALdouble ( *LPALGETDOUBLE)( ALenum param );
typedef ALenum ( *LPALGETERROR)( void );
typedef ALboolean ( *LPALISEXTENSIONPRESENT)(const ALchar* extname );
typedef void* ( *LPALGETPROCADDRESS)( const ALchar* fname );
typedef ALenum ( *LPALGETENUMVALUE)( const ALchar* ename );
typedef void ( *LPALLISTENERF)( ALenum param, ALfloat value );
typedef void ( *LPALLISTENER3F)( ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
typedef void ( *LPALLISTENERFV)( ALenum param, const ALfloat* values );
typedef void ( *LPALLISTENERI)( ALenum param, ALint value );
typedef void ( *LPALLISTENER3I)( ALenum param, ALint value1, ALint value2, ALint value3 );
typedef void ( *LPALLISTENERIV)( ALenum param, const ALint* values );
typedef void ( *LPALGETLISTENERF)( ALenum param, ALfloat* value );
typedef void ( *LPALGETLISTENER3F)( ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3 );
typedef void ( *LPALGETLISTENERFV)( ALenum param, ALfloat* values );
typedef void ( *LPALGETLISTENERI)( ALenum param, ALint* value );
typedef void ( *LPALGETLISTENER3I)( ALenum param, ALint *value1, ALint *value2, ALint *value3 );
typedef void ( *LPALGETLISTENERIV)( ALenum param, ALint* values );
typedef void ( *LPALGENSOURCES)( ALsizei n, ALuint* sources );
typedef void ( *LPALDELETESOURCES)( ALsizei n, const ALuint* sources );
typedef ALboolean ( *LPALISSOURCE)( ALuint sid );
typedef void ( *LPALSOURCEF)( ALuint sid, ALenum param, ALfloat value);
typedef void ( *LPALSOURCE3F)( ALuint sid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
typedef void ( *LPALSOURCEFV)( ALuint sid, ALenum param, const ALfloat* values );
typedef void ( *LPALSOURCEI)( ALuint sid, ALenum param, ALint value);
typedef void ( *LPALSOURCE3I)( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 );
typedef void ( *LPALSOURCEIV)( ALuint sid, ALenum param, const ALint* values );
typedef void ( *LPALGETSOURCEF)( ALuint sid, ALenum param, ALfloat* value );
typedef void ( *LPALGETSOURCE3F)( ALuint sid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
typedef void ( *LPALGETSOURCEFV)( ALuint sid, ALenum param, ALfloat* values );
typedef void ( *LPALGETSOURCEI)( ALuint sid, ALenum param, ALint* value );
typedef void ( *LPALGETSOURCE3I)( ALuint sid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
typedef void ( *LPALGETSOURCEIV)( ALuint sid, ALenum param, ALint* values );
typedef void ( *LPALSOURCEPLAYV)( ALsizei ns, const ALuint *sids );
typedef void ( *LPALSOURCESTOPV)( ALsizei ns, const ALuint *sids );
typedef void ( *LPALSOURCEREWINDV)( ALsizei ns, const ALuint *sids );
typedef void ( *LPALSOURCEPAUSEV)( ALsizei ns, const ALuint *sids );
typedef void ( *LPALSOURCEPLAY)( ALuint sid );
typedef void ( *LPALSOURCESTOP)( ALuint sid );
typedef void ( *LPALSOURCEREWIND)( ALuint sid );
typedef void ( *LPALSOURCEPAUSE)( ALuint sid );
typedef void ( *LPALSOURCEQUEUEBUFFERS)(ALuint sid, ALsizei numEntries, const ALuint *bids );
typedef void ( *LPALSOURCEUNQUEUEBUFFERS)(ALuint sid, ALsizei numEntries, ALuint *bids );
typedef void ( *LPALGENBUFFERS)( ALsizei n, ALuint* buffers );
typedef void ( *LPALDELETEBUFFERS)( ALsizei n, const ALuint* buffers );
typedef ALboolean ( *LPALISBUFFER)( ALuint bid );
typedef void ( *LPALBUFFERDATA)( ALuint bid, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq );
typedef void ( *LPALBUFFERF)( ALuint bid, ALenum param, ALfloat value);
typedef void ( *LPALBUFFER3F)( ALuint bid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
typedef void ( *LPALBUFFERFV)( ALuint bid, ALenum param, const ALfloat* values );
typedef void ( *LPALBUFFERI)( ALuint bid, ALenum param, ALint value);
typedef void ( *LPALBUFFER3I)( ALuint bid, ALenum param, ALint value1, ALint value2, ALint value3 );
typedef void ( *LPALBUFFERIV)( ALuint bid, ALenum param, const ALint* values );
typedef void ( *LPALGETBUFFERF)( ALuint bid, ALenum param, ALfloat* value );
typedef void ( *LPALGETBUFFER3F)( ALuint bid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
typedef void ( *LPALGETBUFFERFV)( ALuint bid, ALenum param, ALfloat* values );
typedef void ( *LPALGETBUFFERI)( ALuint bid, ALenum param, ALint* value );
typedef void ( *LPALGETBUFFER3I)( ALuint bid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
typedef void ( *LPALGETBUFFERIV)( ALuint bid, ALenum param, ALint* values );
typedef void ( *LPALDOPPLERFACTOR)( ALfloat value );
typedef void ( *LPALDOPPLERVELOCITY)( ALfloat value );
typedef void ( *LPALSPEEDOFSOUND)( ALfloat value );
typedef void ( *LPALDISTANCEMODEL)( ALenum distanceModel );
typedef struct ALCdevice_struct ALCdevice;
typedef struct ALCcontext_struct ALCcontext;



typedef char ALCboolean;


typedef char ALCchar;


typedef char ALCbyte;


typedef unsigned char ALCubyte;


typedef short ALCshort;


typedef unsigned short ALCushort;


typedef int ALCint;


typedef unsigned int ALCuint;


typedef int ALCsizei;


typedef int ALCenum;


typedef float ALCfloat;


typedef double ALCdouble;


typedef void ALCvoid;
extern ALCcontext * alcCreateContext( ALCdevice *device, const ALCint* attrlist );

extern ALCboolean alcMakeContextCurrent( ALCcontext *context );

extern void alcProcessContext( ALCcontext *context );

extern void alcSuspendContext( ALCcontext *context );

extern void alcDestroyContext( ALCcontext *context );

extern ALCcontext * alcGetCurrentContext( void );

extern ALCdevice* alcGetContextsDevice( ALCcontext *context );





extern ALCdevice * alcOpenDevice( const ALCchar *devicename );

extern ALCboolean alcCloseDevice( ALCdevice *device );






extern ALCenum alcGetError( ALCdevice *device );







extern ALCboolean alcIsExtensionPresent( ALCdevice *device, const ALCchar *extname );

extern void * alcGetProcAddress( ALCdevice *device, const ALCchar *funcname );

extern ALCenum alcGetEnumValue( ALCdevice *device, const ALCchar *enumname );





extern const ALCchar * alcGetString( ALCdevice *device, ALCenum param );

extern void alcGetIntegerv( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *data );





extern ALCdevice* alcCaptureOpenDevice( const ALCchar *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize );

extern ALCboolean alcCaptureCloseDevice( ALCdevice *device );

extern void alcCaptureStart( ALCdevice *device );

extern void alcCaptureStop( ALCdevice *device );

extern void alcCaptureSamples( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );




typedef ALCcontext * ( *LPALCCREATECONTEXT) (ALCdevice *device, const ALCint *attrlist);
typedef ALCboolean ( *LPALCMAKECONTEXTCURRENT)( ALCcontext *context );
typedef void ( *LPALCPROCESSCONTEXT)( ALCcontext *context );
typedef void ( *LPALCSUSPENDCONTEXT)( ALCcontext *context );
typedef void ( *LPALCDESTROYCONTEXT)( ALCcontext *context );
typedef ALCcontext * ( *LPALCGETCURRENTCONTEXT)( void );
typedef ALCdevice * ( *LPALCGETCONTEXTSDEVICE)( ALCcontext *context );
typedef ALCdevice * ( *LPALCOPENDEVICE)( const ALCchar *devicename );
typedef ALCboolean ( *LPALCCLOSEDEVICE)( ALCdevice *device );
typedef ALCenum ( *LPALCGETERROR)( ALCdevice *device );
typedef ALCboolean ( *LPALCISEXTENSIONPRESENT)( ALCdevice *device, const ALCchar *extname );
typedef void * ( *LPALCGETPROCADDRESS)(ALCdevice *device, const ALCchar *funcname );
typedef ALCenum ( *LPALCGETENUMVALUE)(ALCdevice *device, const ALCchar *enumname );
typedef const ALCchar* ( *LPALCGETSTRING)( ALCdevice *device, ALCenum param );
typedef void ( *LPALCGETINTEGERV)( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *dest );
typedef ALCdevice * ( *LPALCCAPTUREOPENDEVICE)( const ALCchar *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize );
typedef ALCboolean ( *LPALCCAPTURECLOSEDEVICE)( ALCdevice *device );
typedef void ( *LPALCCAPTURESTART)( ALCdevice *device );
typedef void ( *LPALCCAPTURESTOP)( ALCdevice *device );
typedef void ( *LPALCCAPTURESAMPLES)( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );

