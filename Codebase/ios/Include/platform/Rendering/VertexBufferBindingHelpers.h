// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Graphics.h"
#include "IdTypes.h"
#include "VertexBinding.h"
#include "VAOCache.h"
#include "Rendering.h"

#ifdef EEGEO_IOS
    #define BindVertexArray(va) Eegeo_GL(glBindVertexArrayOES(va))
#elif defined(EEGEO_OSX)
    #define BindVertexArray(va) Eegeo_GL(glBindVertexArrayAPPLE(va))
#else
    #define BindVertexArray(va)
#endif

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexBufferBindingHelpers
        {
            inline void UnbindVertexBuffers()
            {
#ifdef EEGEO_IOS
                Eegeo_GL(glBindVertexArrayOES(0));
#else
                Eegeo_GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
                Eegeo_GL(glBindBuffer(GL_ARRAY_BUFFER, 0));
#endif
            }
            
            inline void BindVertexBuffersImmediate(const TVertexBufferId vertexBuffer,
                                                   const TIndexBufferId indexBuffer,
                                                   const VertexLayouts::VertexBinding* pVertexBinding,
                                                   Rendering::GLState& glState)
            {
                Eegeo_ASSERT(pVertexBinding != NULL);
                
                Eegeo_GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer));
                Eegeo_GL(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
                
                pVertexBinding->BindVertices();
            }
            
            inline void BindVertexBuffersImmediate(const TVertexBufferId vertexBuffer,
                                                   const VertexLayouts::VertexBinding* pVertexBinding,
                                                   Rendering::GLState& glState)
            {
                Eegeo_ASSERT(pVertexBinding != NULL);
                
                Eegeo_GL(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
                Eegeo_GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
                
                pVertexBinding->BindVertices();
            }
            
#if defined(EEGEO_IOS)
            inline void BindVertexBuffersVAO(const TVertexBufferId vertexBuffer,
                                             const TIndexBufferId indexBuffer,
                                             const VertexLayouts::VertexBinding* pVertexBinding,
                                             Rendering::GLState& glState,
                                             VAOCache& vaoCache)
            {
                GLuint vertexArrayObject;
                
                if(!vaoCache.TryGetVAOForVertexBinding(pVertexBinding, &vertexArrayObject))
                {
                    vertexArrayObject = vaoCache.CreateVAOForVertexBinding(pVertexBinding);
                    
                    BindVertexArray(vertexArrayObject);

                    BindVertexBuffersImmediate(vertexBuffer, indexBuffer, pVertexBinding, glState);
                    Eegeo_GL(glBindBuffer(GL_ARRAY_BUFFER, 0));
                    
                    BindVertexArray(0);
                }
                BindVertexArray(vertexArrayObject);
            }
            
            inline void BindVertexBuffersVAO(const TVertexBufferId vertexBuffer,
                                             const VertexLayouts::VertexBinding* pVertexBinding,
                                             Rendering::GLState& glState,
                                             VAOCache& vaoCache)
            {
                GLuint vertexArrayObject;
                
                if(!vaoCache.TryGetVAOForVertexBinding(pVertexBinding, &vertexArrayObject))
                {
                    vertexArrayObject = vaoCache.CreateVAOForVertexBinding(pVertexBinding);
                    
                    BindVertexArray(vertexArrayObject);
                    
                    BindVertexBuffersImmediate(vertexBuffer, pVertexBinding, glState);
                    Eegeo_GL(glBindBuffer(GL_ARRAY_BUFFER, 0));
                    
                    BindVertexArray(0);
                }
                BindVertexArray(vertexArrayObject);
            }
#endif
        }
    }
}