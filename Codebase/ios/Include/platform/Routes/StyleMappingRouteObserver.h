// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        class StyleMappingRouteObserver : public Eegeo::NonCopyable
        {
            RouteRepository& m_routeRepository;
            RouteStyleRepository& m_routeStyleRepository;
            
            TRouteCallback<StyleMappingRouteObserver> m_routeAddedCallback;
            TRouteCallback<StyleMappingRouteObserver> m_routeRemovedCallback;

            void HandleRouteAdded(const Route* pRoute);
            void HandleRouteRemoved(const Route* pRoute);
            
            
        public:
            StyleMappingRouteObserver(
                                     RouteRepository& routeRepository,
                                     RouteStyleRepository& routeStyleRepository);
            ~StyleMappingRouteObserver();
        };
    }
}