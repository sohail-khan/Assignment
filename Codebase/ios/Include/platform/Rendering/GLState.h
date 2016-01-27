// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Graphics.h"
#include "GLStateTypes.h"

#include <vector>

namespace Eegeo
{
    namespace Rendering
    { 
        /*!
         * \brief Wrapper for common Open GL states to filter out redundant state changes.
         *
         * Redundant state changes made through this class are filtered such that they aren't passed on to Open GL.
         */
        class GLState
        {
        private:
            static const int NumOfTextureUnits = 8;
            std::vector<GLStateFunc2<GLenum, GLuint> > m_boundTextures;
            
        public:
            GLState();
            
            GLBoolState<GL_TEXTURE_2D> Texture2D;
            GLBoolState<GL_CULL_FACE> CullFace;
            GLBoolState<GL_BLEND> Blend;
            GLBoolState<GL_DITHER> Dither;
            GLBoolState<GL_STENCIL_TEST> StencilTest;
            GLBoolState<GL_DEPTH_TEST> DepthTest;
            GLBoolState<GL_SCISSOR_TEST> ScissorTest;
            GLBoolState<GL_POLYGON_OFFSET_FILL> PolygonOffsetFill;
            GLBoolState<GL_SAMPLE_ALPHA_TO_COVERAGE> SampleAlphaToCoverage;
            GLBoolState<GL_SAMPLE_COVERAGE> SampleCoverage;
            
            GLStateFunc1<GLenum> ActiveTexture;

            inline void BindTexture2D(const GLuint textureId)
            {
                int textureUnit = (ActiveTexture.GetValue() - GL_TEXTURE0);
                Eegeo_ASSERT(textureUnit < NumOfTextureUnits);
                m_boundTextures[textureUnit].TrySet(GL_TEXTURE_2D, textureId);
            }
            
            inline void BindTextureCubeMap(const GLuint textureId)
            {
                int textureUnit = (ActiveTexture.GetValue() - GL_TEXTURE0);
                Eegeo_ASSERT(textureUnit < NumOfTextureUnits);
                m_boundTextures[textureUnit].TrySet(GL_TEXTURE_CUBE_MAP, textureId);
            }
            
            GLStateFunc1<GLuint> UseProgram;
            
            // no longer cached by GLState - now always makes gl call. Method kept for legacy support
            inline void BindArrayBuffer(GLuint bufferId)
            {
                Eegeo_GL(glBindBuffer(GL_ARRAY_BUFFER, bufferId));
            }
            
            // no longer cached by GLState - now always makes gl call. Method kept for legacy support
            inline void BindElementArrayBuffer(GLuint bufferId)
            {
                Eegeo_GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId));
            }
            
            GLStateEnumFunc1<GL_FRAMEBUFFER, GLuint> BindFramebuffer;
            GLStateEnumFunc1<GL_RENDERBUFFER, GLuint> BindRenderbuffer;
            
            GLStateFunc1<GLboolean> DepthMask;
            GLStateFunc1<GLenum> DepthFunc;
            
            #ifdef EEGEO_OSX
                GLStateFunc2<GLclampd, GLclampd> DepthRange;
            #else
                GLStateFunc2<GLfloat, GLfloat> DepthRange;
            #endif
            
            GLStateFunc1<GLenum> BlendEquation;
            GLStateFunc2<GLenum, GLenum> BlendFunc;
            
            GLStateFunc3<GLenum, GLint, GLuint> StencilFunc;
            GLStateFunc3<GLenum, GLenum, GLenum> StencilOp;
            GLStateFunc1<GLuint> StencilMask;
            GLStateFunc4<GLenum, GLenum, GLint, GLuint> StencilFuncSeparate;
            GLStateFunc4<GLenum, GLenum, GLenum, GLenum> StencilOpSeparate;
            GLStateFunc2<GLenum, GLuint> StencilMaskSeparate;
            
    
            GLStateFunc1<GLenum> CullFaceMode;
            GLStateFunc1<GLenum> FrontFace;
            
            GLStateFunc4<GLboolean, GLboolean, GLboolean, GLboolean> ColorMask;
            GLStateFunc4<float, float, float, float> ClearColor;
            GLStateFunc1<GLint> ClearStencil;
            GLStateFunc4<GLint, GLint, GLsizei, GLsizei> Viewport;
            
            GLStateFunc2<GLfloat, GLfloat> PolygonOffset;
            
            void InvalidateAll();
            u32 TrySet(const GLState& stateToSet);

            void SetDefaultState();

            void ResetCounters();
            int GetNumOfAttemptedSets() const;
            int GetNumOfActualSets() const;
            int GetNumOfValid() const;
            
            void ClearTrySetAttempted();
            u32 TrySetIfNotAttempted(const GLState& stateToSet);
        };
    }
}
