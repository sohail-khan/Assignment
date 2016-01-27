// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ReadMeshFactory.h"
#include "QuantizedMeshSetChunkReader.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            class LcmReadMeshFactory : protected ReadMeshFactory, public Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::IQuantizedMeshSetChunkReaderMeshFactory
            {
            public:
                LcmReadMeshFactory(Eegeo::Rendering::GlBufferPool& glBufferPool,
                                   const VertexLayouts::VertexLayout& packedTwoTextureVertexLayout);
                
                Rendering::Mesh* CreateMesh(const Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo,
                                            const void* pVertexData,
                                            const void* pIndexData,
                                            const std::string& debugName);
                
                const Eegeo::Rendering::VertexLayouts::VertexLayout& GetVertexLayoutForVertexFormat(const u32 vertexFormat) const;                            
                
            private:
                const VertexLayouts::VertexLayout& m_packedTwoTextureVertexLayout;
            };
        }
    }
}