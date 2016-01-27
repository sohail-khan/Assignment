// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"

#include "Types.h"
#include "VectorMath.h"

#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
                struct QuantizedMeshInfo
                {
                public:
                    std::string materialName;
                    u32 vertexFormat;
                    int vertexStrideBytes;
                    int vertexCount;
                    int indexCount;
                    
                    Eegeo::v3 positionMin;
                    Eegeo::v3 positionMax;
                    float shadowExtrusionMax;
                    Eegeo::v2 uvMin;
                    Eegeo::v2 uvMax;
                    
                    int destinationVertexStrideBytes;
                    u32 destinationVertexFormat;
                    void* userData;
                    int indexOffset;
                };
            }
        }
    }
}