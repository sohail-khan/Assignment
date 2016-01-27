// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
    {
        class IStreamingVolume
        {
        public:
            virtual ~IStreamingVolume() { }
            
            virtual bool IntersectsKey(const MortonKey& key,
                                       bool& canRefineIntersectedKey,
                                       double& intersectedNodeDepthSortSignedDistance) = 0;
        };
    }
}
