// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ResourceStreamBase.h"
#include "Helpers.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {            
            class PlaceNamesStreaming : public Eegeo::Streaming::ResourceStreamBase, protected Eegeo::NonCopyable
            {
            public:
                                
                PlaceNamesStreaming(Streaming::ResourceStreamComponent* pDefaultStreamComponent);
                
                static PlaceNamesStreaming* CreateWithStoreOverrides(IResourceBuilder& resourceBuilder);
     
                uint averageStreamingSize() { return 0; }
            };
        }
    }
}
