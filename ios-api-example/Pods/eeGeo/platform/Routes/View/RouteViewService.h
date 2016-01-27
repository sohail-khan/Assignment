// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewService : public Eegeo::NonCopyable
            {
                RouteViewRepository& m_routeViewRepository;
                RouteStyleRepository& m_routeStyleRepository;
                RouteViewFactoryRepository& m_routeViewFactoryRepository;
                
            public:
                RouteViewService(
                                 RouteViewRepository& routeViewRepository,
                                 RouteStyleRepository& routeStyleRepository,
                                 RouteViewFactoryRepository& routeViewFactoryRepository
                                 );
                
                void CreateInsertViews(const Fitting::FittedRoute& fittedRoute);
                
                void RemoveDestroyViews(const Fitting::FittedRoute& fittedRoute);
                
                void RefreshViews(const Fitting::FittedRoute& fittedRoute);
            };
        }
    }
}
