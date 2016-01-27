// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "BuildingFootprintService.h"
#include "MortonKey.h"
#include "ICallback.h"
#include "LatLongAltitude.h"
#include "BuildingFootprintResourceService.h"

#include <vector>
#include <functional>


namespace Eegeo
{
    namespace BuildingFootprints
    {

        struct IFootprintDistanceFunctor;
        struct IFootprintAltitudeOverlapFunctor;
        
        struct QueryParams
        {
            enum DistanceSelectionType
            {
                Centroid,
                Outline
            };
            
            Space::LatLong CentreLatLong;
            double CentreAltitude;
            float SearchRadius;
            int MaxResults;
            bool AllFootprintsForGroup;
            bool OnlyOverlappingAltitude;
            DistanceSelectionType DistanceType;
            const BuildingFootprintService::IQueryCallback& UserCallback;
            
            QueryParams(const Space::LatLong& centreLatLong, float searchRadius, int maxResults, bool allFootprintsForGroup, DistanceSelectionType distanceType, const BuildingFootprintService::IQueryCallback& userCallback)
            : CentreLatLong(centreLatLong)
            , CentreAltitude(0.0)
            , SearchRadius(searchRadius)
            , MaxResults(maxResults)
            , AllFootprintsForGroup(allFootprintsForGroup)
            , OnlyOverlappingAltitude(false)
            , DistanceType(distanceType)
            , UserCallback(userCallback)
            {}
            
            QueryParams(const Space::LatLongAltitude& centreLatLongAlt, float searchRadius, int maxResults, bool allFootprintsForGroup, DistanceSelectionType distanceType, const BuildingFootprintService::IQueryCallback& userCallback)
            : CentreLatLong(centreLatLongAlt.GetLatLong())
            , CentreAltitude(centreLatLongAlt.GetAltitude())
            , SearchRadius(searchRadius)
            , MaxResults(maxResults)
            , AllFootprintsForGroup(allFootprintsForGroup)
            , OnlyOverlappingAltitude(true)
            , DistanceType(distanceType)
            , UserCallback(userCallback)
            {}
        };
        
        struct BuildingFootprintServiceQuery : public Eegeo::NonCopyable
        {
            typedef std::vector<Streaming::MortonKey> MortonKeyVector;
            typedef Helpers::TCallback1<BuildingFootprintService, const BuildingFootprintServiceQuery> TServiceCallback;
            
            BuildingFootprintServiceQuery(const QueryParams& queryParams,
                                          const TServiceCallback& serviceCallback,
                                          BuildingFootprintResourceService& footprintResourceService,
                                          BuildingFootprintRepository& footprintRepository);
            
            virtual ~BuildingFootprintServiceQuery();
            
            
            virtual void Execute();
            
            virtual bool AllSucceeded() const { return m_keysRemaining == 0 && !m_anyFail; }
            
            virtual QueryParams GetQueryParams() const { return m_queryParams; }
            
            const MortonKeyVector& GetKeysToGather() const { return m_keysToGather; }
            
            virtual void Finalise();

        private:
            
            void HandleLoadForKey(const BuildingFootprintResourceService::LoadForKeyResult& result);
            
            const QueryParams m_queryParams;

            
            typedef Helpers::TCallback1<BuildingFootprintServiceQuery, const BuildingFootprintResourceService::LoadForKeyResult> TLoadForKeyCallback;
            TLoadForKeyCallback m_loadForKeyCallback;
            
            const TServiceCallback& m_serviceCallback;
            
            BuildingFootprintResourceService& m_footprintResourceService;
            BuildingFootprintRepository& m_footprintRepository;
            
            const IFootprintDistanceFunctor* m_pDistanceFunctor;
            const IFootprintAltitudeOverlapFunctor* m_pAltitudeOverlapFunctor;
            int m_keysRemaining;
            MortonKeyVector m_keysToGather;
            bool m_anyFail;
            bool m_preventQueryDeletion;
            std::vector<const BuildingFootprint*> m_footprints;
        };
    }
}