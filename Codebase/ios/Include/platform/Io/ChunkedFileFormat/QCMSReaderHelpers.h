// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "ChunkedFileFormat.h"
#include "Types.h"

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
                
                namespace QCMSReaderHelpers
                {
                    int CalcVertexBufferElementCount(size_t vertexCount, size_t destVertexSizeBytes);
                }
            }
        }
    }
}