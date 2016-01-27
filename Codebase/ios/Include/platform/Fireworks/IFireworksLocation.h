// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fireworks.h"
#include "Types.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Fireworks
    {
        class IFireworksLocation : protected Eegeo::NonCopyable
        {
        public:
            
            virtual const u32 GetUID() const = 0;
            virtual const Streaming::MortonKey& GetMortonKey() const = 0;
            virtual const FireworksLocationConfiguration& GetConfiguration() const = 0;
            
        };
    }
}