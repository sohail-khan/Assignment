// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

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
        namespace Buildings
        {            
            class BuildingStreaming : public Eegeo::Streaming::ResourceStreamBase, protected Eegeo::NonCopyable
            {
            public:
                BuildingStreaming(Streaming::ResourceStreamComponent* pDefaultStreamComponent);
                
                static BuildingStreaming* CreateWithStoreOverrides(IResourceBuilder& resourceBuilder);
                
                uint averageStreamingSize() { return 32; }
            };
        }
    }
}
