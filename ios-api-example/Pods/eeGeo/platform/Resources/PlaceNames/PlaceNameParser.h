// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include "Streaming.h"
#include "PlaceNameCategory.h"
#include "ChunkedFileFormat.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNameParser
            {
            public:
                static bool TryParsePlaceNames(const Streaming::MortonKey& key, Eegeo::IO::ChunkedFileFormat::ChunkStream& chunkStream, std::vector<PlaceNameData>& result);
                
                static std::string ConvertV1CategoryToV2Code(PlaceNameCategory category);
                static std::string GetIconForV1Category(PlaceNameCategory category);
            };
        }
    }
}
