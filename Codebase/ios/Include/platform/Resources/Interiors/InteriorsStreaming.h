// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "ResourceStreamBase.h"
#include "Types.h"
#include "Resources.h"
#include "CoverageTrees.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsStreaming : public Eegeo::Streaming::ResourceStreamBase, protected Eegeo::NonCopyable
            {
            public:
                InteriorsStreaming(Streaming::ResourceStreamComponent* pDefaultStreamComponent);
                
                static InteriorsStreaming* CreateWithStoreOverrides(IResourceBuilder& resourceBuilder);
                
                uint averageStreamingSize() { return 0; }
            };
        }
    }
}
