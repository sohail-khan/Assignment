// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TextMeshes.h"
#include "AllVertexTypes.h"
#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace TextMeshes
    {
        namespace Internal
        {
            class ScratchGeometry
            {
            public:
                
                ScratchGeometry();
                
                void Reset(int reserveQuadCount);
                
                const std::vector<Rendering::VertexTypes::TextVertex>& Vertices() const { return m_vertices; };
                const std::vector<u16> Indices() const { return m_indices; };
                
                inline void AddVertex(const Eegeo::v3& position, float u, float v, float shadowParam, float altitude);
                
                inline void AddVertices(std::vector<Rendering::VertexTypes::TextVertex>& vertices)
                {
                    m_vertices.insert(m_vertices.end(), vertices.begin(), vertices.end());
                }
            private:
                std::vector<Rendering::VertexTypes::TextVertex> m_vertices;
                std::vector<u16> m_indices;
                
                int m_reserveQuadCount;
                
                void GrowIndexList(int quadCount);
            };
            
            inline void ScratchGeometry::AddVertex(const Eegeo::v3& position, float u, float v, float shadowParam, float altitude)
            {
                m_vertices.push_back(
                                     Rendering::VertexTypes::CreateTextVertex(
                                        position.GetX(),
                                        position.GetY(),
                                        position.GetZ(),
                                        altitude,
                                        u,
                                        v,
                                        shadowParam
                                     )
                );

            }
        }
    }
}
