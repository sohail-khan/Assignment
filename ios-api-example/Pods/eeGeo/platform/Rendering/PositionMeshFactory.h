// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "VectorMath.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            /*!
             * \brief Factory for creating meshes with the PositionVertex vertex format from v3 points indexed with u16 triangle-list
             */
            class PositionMeshFactory : public Eegeo::NonCopyable
            {
            public:
                PositionMeshFactory(Eegeo::Rendering::GlBufferPool& glBufferPool,
                                    const VertexLayouts::VertexLayout& positionVertexLayout);
                
                Rendering::Mesh* CreateMesh(const std::vector<Eegeo::v3>& points,
                                            const std::vector<u16>& triListIndices,
                                            const std::string& debugName);
                
            private:
                Eegeo::Rendering::GlBufferPool& m_glBufferPool;
                const VertexLayouts::VertexLayout& m_positionVertexLayout;
            };
        }
    }
}
