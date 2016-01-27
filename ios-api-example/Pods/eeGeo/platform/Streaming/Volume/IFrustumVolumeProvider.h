// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
    {
        class IFrustumVolumeProvider
        {
        public:
            virtual ~IFrustumVolumeProvider(){}
            virtual Streaming::FrustumStreamingVolume BuildFrustumVolume() = 0;
        };
    }
}