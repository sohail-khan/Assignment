// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "QuantizedMeshSetChunkReader.h"
#include "Mesh.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            /*!
             * \brief Base class for mesh factories that create meshes from QuantizedMeshInfo objects.
             */
            class ReadMeshFactory : protected Eegeo::NonCopyable
            {
            public:
                ReadMeshFactory(Eegeo::Rendering::GlBufferPool& glBufferPool);
                
            protected:
                Eegeo::Rendering::Mesh* CreateMeshWithVertexLayout(const Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo,
                                                                   const void* pVertexData,
                                                                   const void* pIndexData,
                                                                   const std::string& debugName,
                                                                   const Eegeo::Rendering::VertexLayouts::VertexLayout& vertexLayout);
                
            private:
                Eegeo::Rendering::GlBufferPool& m_glBufferPool;
            };
        }
    }
}