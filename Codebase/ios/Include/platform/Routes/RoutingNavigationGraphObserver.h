// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Navigation.h"
#include "NavigationGraphAddedCallback.h"
#include "NavigationGraphRemovalCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        class RoutingNavigationGraphObserver : public Eegeo::NonCopyable
        {
            Resources::Roads::Navigation::NavigationGraphRepository& m_roadNavigationGraphRepository;
            Resources::Roads::Navigation::NavigationGraphRepository& m_railNavigationGraphRepository;
            Fitting::RouteFittingService& m_routeFittingService;
            Fitting::NavGraphFittingInfoService& m_navGraphFittingInfoService;
            
            Resources::Roads::Navigation::TNavigationGraphAddedCallback<RoutingNavigationGraphObserver> m_roadAddedCallback;
            Resources::Roads::Navigation::TNavigationGraphRemovalCallback<RoutingNavigationGraphObserver> m_roadRemovalCallback;
            Resources::Roads::Navigation::TNavigationGraphAddedCallback<RoutingNavigationGraphObserver> m_railAddedCallback;
            Resources::Roads::Navigation::TNavigationGraphRemovalCallback<RoutingNavigationGraphObserver> m_railRemovalCallback;
            
            void HandleRoadNavigationGraphAdded(const Resources::Roads::Navigation::NavigationGraph& graph);
            void HandleRoadNavigationGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& graph);
            
            void HandleRailNavigationGraphAdded(const Resources::Roads::Navigation::NavigationGraph& graph);
            void HandleRailNavigationGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& graph);
            
            void NotifyUpdateForNavGraphAndAdjacentCells(const Resources::Roads::Navigation::NavigationGraph& graph);
            
        public:
            RoutingNavigationGraphObserver(Resources::Roads::Navigation::NavigationGraphRepository& roadNavigationGraphRepository,
                                           Resources::Roads::Navigation::NavigationGraphRepository& railNavigationGraphRepository,
                                           Fitting::RouteFittingService& routeFittingService,
                                           Fitting::NavGraphFittingInfoService& navGraphFittingInfoService);

            ~RoutingNavigationGraphObserver();
        };
    }
}
