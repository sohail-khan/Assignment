// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Streaming.h"
#include "UniqueKeyFifo.h"

#include <vector>
#include <deque>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class RouteFittingService : public Eegeo::NonCopyable
            {
                FittedRouteRepository& m_fittedRouteRepository;
                FittedRouteFactory& m_fittedRouteFactory;
                const RouteRepository& m_routeRepository;
                const Streaming::SceneGraphCellRepository& m_sceneGraphCellRepository;
                
                UniqueKeyFifo m_keysNeedingRefresh;
                std::deque<Streaming::MortonKey> m_keysNotInSceneGraphScratch;
                
                bool m_enabled;
            public:
                RouteFittingService(FittedRouteRepository& fittedRouteRepository,
                                    FittedRouteFactory& fittedRouteFactory,
                                    const RouteRepository& routeRepository,
                                    const Streaming::SceneGraphCellRepository& sceneGraphCellRepository);
                
                virtual ~RouteFittingService();
                
                const FittedRoute* GetFittedRoute(const Route* pRoute, const Eegeo::Streaming::MortonKey& key) const;
                
                void DestroyFittedRoutesForKey(const Eegeo::Streaming::MortonKey& key);
                
                void DestroyFittedRoutesForRoute(const Route* pRoute);
                
                void SetNeedsUpdatingForKey(const Eegeo::Streaming::MortonKey& key);
                
                void SetNeedsUpdatingForKeys(const std::vector<Eegeo::Streaming::MortonKey>& keys);
                
                void Update();
                
                void FlushPendingUpdates();
                
                void RefitAll();
                
                
                bool IsEnabled() const { return m_enabled; }
                
                // enabled/disabled by RouteObserver when Route repo gets entry / becomes emtpy
                void Enable();
                
                void Disable();
            private:
                
                void DestroyAll();

                void CreateFittedRoutesForKey(const Eegeo::Streaming::MortonKey& key, bool attemptNavGraphConforming, std::vector<FittedRoute*>& out_fittedRoutes);
                               
                void UpdateRepositoryWithFittedRoutes(std::vector<FittedRoute*>& fittedRoutes);
            };
        }
    }
}
