// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ResourceStreamBase.h"
#include "Types.h"
#include "Helpers.h"
#include "CoverageTrees.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            class TerrainStreaming : public Eegeo::Streaming::ResourceStreamBase, protected Eegeo::NonCopyable
            {
            public:
                TerrainStreaming(Streaming::ResourceStreamComponent* pDefaultStreamComponent);
                
                static TerrainStreaming* CreateWithStoreOverrides
                (
                    IResourceBuilder& chunkedLcmResourceBuilder,
                    IResourceBuilder& rasterResourceBuilder,
                    IPlaceholderBuilder& placeholderBuilder
                );
                
                uint averageStreamingSize() { return 11; }
            };
        }
    }
}