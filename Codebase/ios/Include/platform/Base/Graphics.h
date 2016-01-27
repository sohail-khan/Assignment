// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#if defined (EEGEO_DROID)
#define GL_GLEXT_PROTOTYPES
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#elif defined (EEGEO_IOS)
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#elif defined (EEGEO_OSX)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif defined (EEGEO_WIN)
#include "EegeoWindowsGuard.h"
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif

#ifdef DEBUG
#define EEGEO_DEBUG_GL
#endif 

#if defined (EEGEO_DEBUG_GL)
	#if defined (EEGEO_DROID)
		#define Eegeo_GL(x)		{																				\
									(x);																		\
									EGLint eglError = eglGetError();											\
									while(eglError!=EGL_SUCCESS)												\
									{ 																			\
										Eegeo_TTY("eglError (0x%x) at %s (%d)\n", eglError, __FILE__, __LINE__);\
										eglError = eglGetError();												\
									}																			\
																												\
									GLint glError = glGetError();												\
									while(glError!=0)															\
									{																			\
										Eegeo_TTY("glError (0x%x) at %s (%d)\n", glError, __FILE__, __LINE__);	\
										glError = glGetError();													\
									}																			\
								}
	#elif defined (EEGEO_IOS)
		#define Eegeo_GL(x)		{																				\
									(x);																		\
									GLint glError = glGetError();												\
									while(glError!=0)															\
									{																			\
										Eegeo_TTY("glError (0x%x) at %s (%d)\n", glError, __FILE__, __LINE__);  \
                                        Eegeo_ASSERT(false);                                                    \
										glError = glGetError();													\
									}																			\
								}

    #elif defined (EEGEO_OSX) || defined (EEGEO_WIN)
        #define Eegeo_GL(x)		{																				\
                                    (x);																		\
                                    GLint glError = glGetError();												\
                                    while(glError!=0)															\
                                    {																			\
                                        Eegeo_TTY("glError (0x%x) at %s (%d)\n", glError, __FILE__, __LINE__);	\
                                        glError = glGetError();													\
                                    }																			\
                                }
        #endif
#else
	#define Eegeo_GL(x)			{(x);}
#endif
