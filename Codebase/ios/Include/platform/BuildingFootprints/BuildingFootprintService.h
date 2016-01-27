// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BuildingFootprints.h"
#include "ICallback.h"

#include "MortonKey.h"
#include "BuildingFootprint.h"

#include "MortonKeyLRUCache.h"


#include "Space.h"
#include <vector>

#include <functional>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        struct BuildingFootprintServiceQueryResult
        {
            BuildingFootprintServiceQueryResult(bool success, const std::vector<BuildingFootprint>& footprints)
            : m_isSuccess(success)
            , m_footprints(footprints)
            {}
            
            bool Succeeded() const { return m_isSuccess; }
            
            const std::vector<BuildingFootprint>& Footprints() const { return m_footprints; }
        private:
            bool m_isSuccess;
            std::vector<BuildingFootprint> m_footprints;
        };

        


        
        class BuildingFootprintService : public Eegeo::NonCopyable
        {
        public:
            typedef Helpers::ICallback1<const BuildingFootprintServiceQueryResult> IQueryCallback;
            
            static const float MaxQueryRadius;
            
            BuildingFootprintService(BuildingFootprintResourceService& footprintResourceService,
                                     BuildingFootprintRepository& footprintRepository,
                                     int cacheSize);
            
            void GetFootprintsInRadius(const Eegeo::Space::LatLong& pointLatLong, float radiusMetres, int maxResults, IQueryCallback& callback);
            
            void GetClosestFootprint(const Eegeo::Space::LatLong& pointLatLong, float searchRadiusMetres, bool allFootprintsInGroup, IQueryCallback& callback);
            
            void GetClosestFootprintOverlappingAltitude(const Eegeo::Space::LatLongAltitude& pointLatLongAlt, float searchRadiusMetres, bool allFootprintsInGroup, IQueryCallback& userCallback);
            
            void ClearCache();
            
        private:
            std::vector<Streaming::MortonKey> GetKeysInUse() const;
            
            void UpdateCache();
            
            void PruneCache(int desiredCacheSize);
            
            void ExecuteQuery(const QueryParams& queryParams);
            
            void FinaliseQuery(const BuildingFootprintServiceQuery& query);
        
            BuildingFootprintResourceService& m_footprintResourceService;
            BuildingFootprintRepository& m_footprintRepository;
            
            typedef Helpers::TCallback1<BuildingFootprintService, const BuildingFootprintServiceQuery> TQueryCompleteHandler;
            TQueryCompleteHandler m_queryCompleteHandler;
            
            std::vector<BuildingFootprintServiceQuery*> m_pendingQueries;
            MortonKeyLRUCache m_keysMRU;
            const int m_cacheSize;
        };
        

    }
}