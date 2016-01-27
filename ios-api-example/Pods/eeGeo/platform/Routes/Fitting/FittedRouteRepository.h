// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "Routes.h"
#include <vector>
#include <map>


namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class FittedRouteRepository : public Eegeo::NonCopyable
            {
            private:
                typedef std::multimap<Eegeo::Streaming::MortonKey, FittedRoute*> TMapKeyToFittedRoutes;

                TMapKeyToFittedRoutes m_keysToFittedRoutes;
                
                std::vector<IFittedRouteCallback*> m_routeAddedCallbacks;
                std::vector<IFittedRouteCallback*> m_routeRemovedCallbacks;
                
                void FireCallbacks(std::vector<IFittedRouteCallback*>& callbacks, const FittedRoute& fittedRoute);
                void InsertCallback(std::vector<IFittedRouteCallback*>& callbacks, IFittedRouteCallback* callback);
                void RemoveCallback(std::vector<IFittedRouteCallback*>& callbacks, IFittedRouteCallback* callback);
                
            public:
                void AddFittedRoute(FittedRoute& fittedRoute);
                void GetFittedRoutesForKey(const Eegeo::Streaming::MortonKey& key, std::vector<FittedRoute*>& out_fittedRoutes) const;
                bool HasAnyFittedRouteForKey(const Eegeo::Streaming::MortonKey& key) const;
                
                void RemoveFittedRoutesForKey(const Eegeo::Streaming::MortonKey& key, std::vector<FittedRoute*>& out_fittedRoutes);
                void RemoveFittedRoute(const FittedRoute* pFittedRoute);
                
                FittedRoute* GetFittedRoute(const Route* pRoute, const Eegeo::Streaming::MortonKey& key) const;
                
                void GetFittedRouteKeys(std::vector<Eegeo::Streaming::MortonKey>& keys) const;
                
                void GetAll(std::vector<FittedRoute*>& out_fittedRoutes) const;
                void GetAllForRoute(const Route* pRoute, std::vector<FittedRoute*>& out_fittedRoutes) const;
                
                void RemoveAllForRoute(const Route* pRoute, std::vector<FittedRoute*>& out_removedFittedRoutes);
                
                void Clear();
                
                void RegisterFittedRouteAddedCallback(IFittedRouteCallback* callback);
                void RegisterFittedRouteRemovalCallback(IFittedRouteCallback* callback);
                void UnregisterFittedRouteAddedCallback(IFittedRouteCallback* callback);
                void UnregisterFittedRouteRemovalCallback(IFittedRouteCallback* callback);
            };
        }
    }
}
