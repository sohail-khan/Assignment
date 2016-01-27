// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming 
    {
        class IStreamingObserver 
        {
        public:
            virtual void AddedStreamingResourceToSceneGraph(const MortonKey& key) =0;
            virtual void RemovedStreamingResourceFromSceneGraph(const MortonKey& key) =0;
        };
    }
}