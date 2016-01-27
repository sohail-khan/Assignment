// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshFactory.h"
#include "Rendering.h"
#include "Types.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            class SceneModelMeshFactory : public MeshFactory
            {
            public:
                SceneModelMeshFactory(Rendering::GlBufferPool& glBufferPool, const VertexLayouts::VertexLayoutPool& vertexLayoutPool);
                
                TriStripMesh* CreateTriStripMesh(const void* pVertexData,
                                                 int numOfVertices,
                                                 const void* pIndexData,
                                                 size_t indexDataSize,
                                                 u32 numOfIndices,
                                                 const u32* pStripLengthData,
                                                 u32 numOfStrips,
                                                 const std::string& debugName
                                                 ) const;
            };
        }
    }
}
