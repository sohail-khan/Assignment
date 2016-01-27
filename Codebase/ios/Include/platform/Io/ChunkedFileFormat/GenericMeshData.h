// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"


namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            template <typename TVertex>
            struct GenericMeshData
            {
                Eegeo::dv3 ecefOrigin;
                Eegeo::v3 minVertexRange;
                Eegeo::v3 maxVertexRange;
                Eegeo::v2 minUVRange;
                Eegeo::v2 maxUVRange;
                int numVerts;
                TVertex* pVertexBuffer;
                int numIndices;
                u16* pIndexBuffer;
            };
        }
    }
}
