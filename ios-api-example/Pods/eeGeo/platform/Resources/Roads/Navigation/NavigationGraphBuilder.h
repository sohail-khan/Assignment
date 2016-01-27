// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "Roads.h"
#include "CubeMap.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraphBuilder : protected Eegeo::NonCopyable
                {
                public:                    
                    static const double RoadsHeightAboveGround;
                    
                    NavigationGraphBuilder(
                    		NavigationGraphRepository* navigationGraphRepository)
                    : m_navigationGraphRepository( navigationGraphRepository)
                    {
                    }
                    
                    NavigationGraph* Build(const Eegeo::Space::CubeMap::CubeMapCellInfo& cellInfo, NavGraphData& navGraphData);
                    void Flush(NavigationGraph* navGraph);
                    
                private:
                    NavigationGraphRepository* m_navigationGraphRepository;
                };
            }
        }
    }
}
