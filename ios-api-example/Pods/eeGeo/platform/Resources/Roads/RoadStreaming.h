// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ResourceStreamBase.h"
#include "Streaming.h"
#include "Resources.h"
#include "Helpers.h"
#include "CoverageTrees.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {     
        namespace Roads
        {
            class RoadStreaming : public Eegeo::Streaming::ResourceStreamBase, protected Eegeo::NonCopyable
            {
            public:
                RoadStreaming(Streaming::ResourceStreamComponent* pDefaultStreamComponent);
                
                static RoadStreaming* CreateWithStoreOverrides(IResourceBuilder& resourceBuilder);
                
                uint averageStreamingSize() { return 30; }
            };
        }
    }
}
