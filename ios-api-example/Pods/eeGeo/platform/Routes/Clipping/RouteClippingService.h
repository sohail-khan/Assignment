// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"

#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Clipping
        {
            class RouteClippingService : public Eegeo::NonCopyable
            {
            public:
                
                void ClipVerticesToCells(const std::vector<RouteVertex>& vertices,
                                         int maxSubdivisionLevel,
                                         ClippedRoute& out_routeClippedToCells,
                                         std::vector<RouteVertex>& out_vertices);
            };
            
        }
    }
}
