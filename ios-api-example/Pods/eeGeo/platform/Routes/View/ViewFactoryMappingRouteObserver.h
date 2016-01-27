// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class ViewFactoryMappingRouteObserver : public Eegeo::NonCopyable
            {
                RouteRepository& m_routeRepository;
                RouteViewFactoryRepository& m_routeViewFactoryRepository;
                
                TRouteCallback<ViewFactoryMappingRouteObserver> m_routeAddedCallback;
                TRouteCallback<ViewFactoryMappingRouteObserver> m_routeRemovedCallback;

                void HandleRouteAdded(const Route* pRoute);
                void HandleRouteRemoved(const Route* pRoute);
                
                
            public:
                ViewFactoryMappingRouteObserver(
                                         RouteRepository& routeRepository,
                                         RouteViewFactoryRepository& routeViewFactoryRepository);
                ~ViewFactoryMappingRouteObserver();
            };
        }
    }
}