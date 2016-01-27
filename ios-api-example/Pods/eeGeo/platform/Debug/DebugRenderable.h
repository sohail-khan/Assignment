// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "DebugRendering.h"
#include "Camera.h"
#include <string>
#include <vector>

namespace Eegeo
{

    namespace DebugRendering
    {
        typedef struct {    
            float x, y, z;
            float r, g, b, a;
            float u, v;
            
        } Eegeo_Vertex;
        
        class DebugRenderable : protected Eegeo::NonCopyable
        {
            bool m_tesellated;
            Shader* m_pShader;
            Eegeo::v3 m_color;
            u32 *m_pTexture;
            
            u32 m_numVerts;
            u32 m_numIndices;
            u32 m_glVertexBuffer;
            u32 m_glIndexBuffer;    
            Eegeo_Vertex *m_pVertexBuffer;
            u16 *m_pIndexBuffer;
            bool m_requires32bitIndices;
            
        public:
            DebugRenderable(u32 *texture)
            : m_tesellated(false)
            , m_pShader(NULL)
            , m_color(Eegeo::v4(1,1,1,1))
            , m_pTexture(texture)
            {
                
            }
            
            ~DebugRenderable()
            {
            	DestroyGeometry();
            }
            
            void Draw(const Eegeo::v3& cameraRelativeMeshPosition, const Camera::RenderCamera& renderCamera, Eegeo::Rendering::GLState& glState);
            
            void Build(std::vector<Eegeo::v3>& verts,
                       std::vector<Eegeo::v3>& colors,
                       std::vector<u16>& indices,
                       std::vector<Eegeo::v2>& uvs,
                       Eegeo::Rendering::GLState& glState);
            
            void Build(std::vector<Eegeo::v3>& verts, 
                       std::vector<Eegeo::v4>& colors,
                       std::vector<u16>& indices,
                       std::vector<Eegeo::v2>& uvs,
                       Eegeo::Rendering::GLState& glState);
            
            static void DestroyShaderInstance();
            
        private: 
            std::string VertexShader();
            std::string FragmentShader();
            void InitMeshGLBuffers(Eegeo::Rendering::GLState& glState);
            void BuildGeometry();    
            void DestroyGeometry();
            
            static DebugShader* shaderInstance;
            static DebugShader* GetShaderInstance(Eegeo::Rendering::GLState& glState);
        };
    }
}
