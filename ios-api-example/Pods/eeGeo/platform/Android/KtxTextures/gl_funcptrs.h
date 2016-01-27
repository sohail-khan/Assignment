// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* remove these where already defined as typedefs (GCC 4 complains of duplicate definitions) */
typedef void (GL_APIENTRY* PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GL_APIENTRY* PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GL_APIENTRY* PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GL_APIENTRY* PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GL_APIENTRY* PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GL_APIENTRY* PFNGLGENERATEMIPMAPPROC) (GLenum target);


/* Uncomment these where not already defined as functions. If GLEW
 * is being used, they will most likely already be defined. */
/* PFNGLTEXIMAGE1DPROC glTexImage1D = 0; */
/* PFNGLTEXIMAGE3DPROC glTexImage3D = 0; */
/* PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = 0; */
/* PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = 0; */
/* PFNGLGENERATEMIPMAPPROC glGenerateMipmap = 0; */

/* remove these where already defined as functions. GLEW probably
 * already causes them to be defined and initializes them. */
extern PFNGLTEXIMAGE3DPROC glTexImage3D;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;

/* and these */
#define DECLARE_GL_FUNCPTRS \
    PFNGLTEXIMAGE3DPROC glTexImage3D = 0; \
    PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = 0; \
    PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = 0; \
    PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = 0; \
    PFNGLGENERATEMIPMAPPROC glGenerateMipmap = 0;

/* remove this if you use GLEW and already have this */
extern int GLEW_OES_compressed_ETC1_RGB8_texture;

/* and make this macro empty */
#define DECLARE_GL_EXTGLOBALS \
	int GLEW_OES_compressed_ETC1_RGB8_texture = 0;

#ifdef __cplusplus
}
#endif

