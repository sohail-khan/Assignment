// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"
#include "Rendering.h"
#include "Types.h"

#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
                class IQuantizedMeshSetChunkReaderMeshFactory
                {
                public:
                    virtual Rendering::Mesh* CreateMesh(const QuantizedMeshInfo& meshInfo,
                                                        const void* pVertexData,
                                                        const void* pIndexData,
                                                        const std::string& debugName) = 0;
                    
                    virtual const Eegeo::Rendering::VertexLayouts::VertexLayout& GetVertexLayoutForVertexFormat(const u32 vertexFormat) const = 0;
                    
                    virtual ~IQuantizedMeshSetChunkReaderMeshFactory() {};
                };
            }
        }
    }
}