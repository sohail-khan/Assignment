// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ChunkedFileFormat.h"

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace CellModelChunkReader
            {
                u32 ReadCellModelChunk(ChunkStream* pChunkStream);
            }
        }
    }
}
