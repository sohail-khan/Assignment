// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fireworks.h"
#include "Types.h"

namespace Eegeo
{
    namespace Fireworks
    {
        class IFireworksLocationRepository
        {
            
        public:
            
            virtual ~IFireworksLocationRepository() {}
            
            virtual void AddFireworksLocation(u32 uid, FireworksLocationConfiguration& location) = 0;
            virtual void RemoveFireworksLocation(u32 uid) = 0;
            virtual void Clear() = 0;

        };
    }
}