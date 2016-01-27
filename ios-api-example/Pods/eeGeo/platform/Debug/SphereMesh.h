// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "DebugRenderable.h"
#include "Rendering.h"
#include <vector>

namespace Eegeo
{
    namespace DebugRendering
    {
        class SphereMesh : protected Eegeo::NonCopyable
        {    
            float m_radius;    
            u32 m_segmentsW;
            u32 m_segmentsH;
            Eegeo::dv3 m_pos;
            Eegeo::v3 m_color;
            DebugRendering::DebugRenderable* m_renderable;
            
        public:
            SphereMesh(float radius, u32 segmentsW, u32 segmentsH, Eegeo::dv3 pos, u32 *texture, Eegeo::v3 color)
            : m_radius(radius)
            , m_segmentsW(segmentsW)
            , m_segmentsH(segmentsH)
            , m_pos(pos)
            , m_color(color)
            {
                m_renderable = Eegeo_NEW(DebugRenderable)(texture);
            }
            
            ~SphereMesh()
            {
            	Eegeo_DELETE m_renderable;
            }
            
            void Draw(const Camera::RenderCamera& renderCamera, Eegeo::Rendering::GLState& glState);
            void Tesselate(Eegeo::Rendering::GLState& glState);
            void SetPositionECEF(const Eegeo::dv3& posECEF);
            
        private:
            void BuildGeometry(std::vector<Eegeo::v3>& verts, 
                               std::vector<Eegeo::v3>& colors, 
                               std::vector<u16>& indices, 
                               std::vector<Eegeo::v2>& uvs);
            
        };
    }
}