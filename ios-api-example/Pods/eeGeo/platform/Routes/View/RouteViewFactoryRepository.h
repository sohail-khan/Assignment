// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteStyle.h"
#include <map>
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewFactoryRepository : public Eegeo::NonCopyable
            {
            private:
                std::map<const Route*, IRouteViewFactory*> m_routeViewFactoryMap;
                
            public:
                void AddRouteViewFactoryMapping(const Route* pRoute, IRouteViewFactory* pViewFactory);
                void RemoveRouteViewFactoryMapping(const Route* pRoute);
                
                bool HasViewFactoryForRoute(const Route* route) const;
                IRouteViewFactory* GetViewFactoryForRoute(const Route* route) const;
                bool IsEmpty() const;
            };
        }
    }
}
