// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFireworksLocation.h"
#include "Fireworks.h"
#include "Types.h"
#include "Streaming.h"
#include "FireworksLocationConfiguration.h"
#include "MortonKey.h"

namespace Eegeo
{
    namespace Fireworks
    {
        class FireworksLocation : public IFireworksLocation
        {
        public:
            
            FireworksLocation(const u32 uid,
                              const FireworksLocationConfiguration& config,
                              const Streaming::MortonKey& key);
            virtual ~FireworksLocation()
            {
            }
            
            const FireworksLocationConfiguration& GetConfiguration() const;
            const u32 GetUID() const;
            const Streaming::MortonKey& GetMortonKey() const;
            
        private:
            
            const FireworksLocationConfiguration m_config;
            const u32 m_uid;
            const Streaming::MortonKey m_key;
        };
    }
}