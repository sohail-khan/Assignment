// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Navigation.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class NavGraphFittingInfoService : Eegeo::NonCopyable
            {
            public:
                NavGraphFittingInfoService(
                                           Fitting::NavGraphFittingInfoRepository& roadNavGraphFittingInfoRepository,
                                           Fitting::NavGraphFittingInfoRepository& railNavGraphFittingInfoRepository,
                                           const Resources::Roads::Navigation::NavigationGraphRepository& roadNavigationGraphRepository,
                                           const Resources::Roads::Navigation::NavigationGraphRepository& railNavigationGraphRepository);
                
                virtual ~NavGraphFittingInfoService();
 
                void RoadNavGraphAdded(const Resources::Roads::Navigation::NavigationGraph& navGraph);
                void RoadNavGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& navGraph);
                void RailNavGraphAdded(const Resources::Roads::Navigation::NavigationGraph& navGraph);
                void RailNavGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& navGraph);
                
                // enabled/disabled by RouteObserver as Route repo is added to or becomes empty
                void Enable();
                void Disable();
                
            private:
                void NavGraphAdded(const Resources::Roads::Navigation::NavigationGraph& navGraph, Fitting::NavGraphFittingInfoRepository& fittingInfoRepository);
                void NavGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& navGraph, Fitting::NavGraphFittingInfoRepository& fittingInfoRepository);
            
                void PopulateFromNavGraphRepo(const Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepo, Fitting::NavGraphFittingInfoRepository& fittingInfoRepository);
            
                static void DestroyAll(Fitting::NavGraphFittingInfoRepository& repo);
            
                Fitting::NavGraphFittingInfoRepository& m_roadNavGraphFittingInfoRepository;
                Fitting::NavGraphFittingInfoRepository& m_railNavGraphFittingInfoRepository;
                
                const Resources::Roads::Navigation::NavigationGraphRepository& m_roadNavigationGraphRepository;
                const Resources::Roads::Navigation::NavigationGraphRepository& m_railNavigationGraphRepository;
                bool m_enabled;
            };
        }
    }
}
