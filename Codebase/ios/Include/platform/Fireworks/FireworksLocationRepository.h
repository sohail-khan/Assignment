// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFireworksLocationRepository.h"
#include "Fireworks.h"
#include "FireworksLocation.h"
#include "MortonKey.h"
#include "ICallback.h"
#include <vector>
#include <string>
#include <map>

namespace Eegeo
{
    namespace Fireworks
    {
        typedef Helpers::ICallback1<const IFireworksLocation&> TFireworkLocationAddedCallback;
        
        class FireworksLocationRepository : public IFireworksLocationRepository
        {
        public:
            
            static const int BaseCellDepth;
            
            FireworksLocationRepository();
            ~FireworksLocationRepository();
            
            void AddFireworksLocation(u32 uid, FireworksLocationConfiguration& location);
            void RemoveFireworksLocation(u32 uid);
            
            void Clear();
            
            void GetLocationsAtMortonKey(const Streaming::MortonKey& key, std::vector<IFireworksLocation*> & out_locations);
            
            void RegisterFireworksAddedCallback(TFireworkLocationAddedCallback& callback);
            void UnregisterFireworksAddedCallback(TFireworkLocationAddedCallback& callback);
            void RegisterFireworksRemovedCallback(TFireworkLocationAddedCallback& callback);
            void UnregisterFireworksRemovedCallback(TFireworkLocationAddedCallback& callback);
            
        private:
            
            void ValidateAndFindFireworksLocationForRemoval(u32 uid,
                                                            std::map<u32, FireworksLocation*>::iterator& out_iterator,
                                                            Streaming::MortonKey& out_key);
            void ValidateLocationConfig(FireworksLocationConfiguration& locationConfig);
            void CallLocationAddedCallbacks(const IFireworksLocation& location);
            void CallLocationRemovedCallbacks(const IFireworksLocation& location);
            
            typedef std::vector<FireworksLocation*> TLocations;
            std::map<u32, FireworksLocation*> m_uniqueIdToLocationMap;
            std::map<Streaming::MortonKey, TLocations> m_mortonKeyToLocationsMap;
            
            std::vector<TFireworkLocationAddedCallback*> m_locationAddedCallbacks;
            std::vector<TFireworkLocationAddedCallback*> m_locationRemovedCallbacks;
        };
    }
}