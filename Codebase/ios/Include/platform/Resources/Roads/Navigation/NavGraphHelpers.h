// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {

                class NavGraphHelpers
                {
                public:
                    enum ConnectivityFlags
                    {
                        NotConnected = 0x0,
                        StartA_StartB = 0x1,
                        StartA_EndB = 0x2,
                        EndA_StartB = 0x4,
                        EndA_EndB = 0x8
                    };
                    
                    static int FindRoadIndex(const NavigationGraphRoad& road, const NavigationGraph& navGraph);
                    
                    static uint GetConnectivity(const NavigationGraphRoad& roadA, const NavigationGraphRoad& roadB,
                                                const NavigationGraph& navGraphA, const NavigationGraph& navGraphB);
                    
                    static uint GetInternalConnectivity(const NavigationGraphRoad& roadA, const NavigationGraphRoad& roadB, const NavigationGraph& navGraph);
                    
                    static uint GetLinkConnectivity(const NavigationGraphRoad& roadA, const NavigationGraphRoad& roadB,
                                                    const NavigationGraph& navGraphA, const NavigationGraph& navGraphB);
                    
                    
                    
                    
                };
            }
        }
    }
}
