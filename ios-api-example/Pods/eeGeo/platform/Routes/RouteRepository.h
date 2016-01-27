// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class RouteRepository : public Eegeo::NonCopyable
        {
        private:
            std::vector<const Route*> m_routes;
            std::vector<IRouteCallback*> m_routeAddedCallbacks;
            std::vector<IRouteCallback*> m_routeRemovedCallbacks;
            
            void FireCallbacks(std::vector<IRouteCallback*>& callbacks, const Route* route);
            void InsertCallback(std::vector<IRouteCallback*>& callbacks, IRouteCallback* callback);
            void RemoveCallback(std::vector<IRouteCallback*>& callbacks, IRouteCallback* callback);
            
        public:
            void AddRoute(const Route* route);
            bool RemoveRoute(const Route* route);
            void RemoveAll();
            std::vector<const Route*> GetRoutes() const;
            bool IsEmpty() const;
            
            void RegisterRouteAddedCallback(IRouteCallback* callback);
            void RegisterRouteRemovalCallback(IRouteCallback* callback);
            void UnregisterRouteAddedCallback(IRouteCallback* callback);
            void UnregisterRouteRemovalCallback(IRouteCallback* callback);
        };
    }
}
