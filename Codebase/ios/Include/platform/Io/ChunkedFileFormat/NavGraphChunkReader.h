// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"
#include "VectorMathDecl.h"
#include "Roads.h"

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace NavGraphChunkReader
            {
                void SkipNavGraph(ChunkStream& chunkStream);
                void ReadNavGraph(ChunkStream& chunkStream, dv3 ecefCellOrigin, Resources::Roads::NavGraphData& preallocatedNavGraph);
            }
        }
    }
}
