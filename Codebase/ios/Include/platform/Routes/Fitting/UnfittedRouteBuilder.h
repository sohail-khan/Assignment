// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Streaming.h"
#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class Route;
        
        namespace Fitting
        {
            class UnfittedRouteBuilder : Eegeo::NonCopyable
            {
            public:
                UnfittedRouteBuilder(const Route& route,
                                     const Streaming::MortonKey& key,
                                     const FittingTerrainProjector& fittingTerrainProjector,
                                     const Eegeo::v4* pOptionalColorOverride,
                                     const bool fittingAttempted);
                
                
                FittedRoute* Create() const;
            private:

                
                bool InsertEdgeClippedVertexWithTerrainHeight(const Clipping::ClippedRouteVertex& vertex,
                                                              const Eegeo::dv3& ecefPos,
                                                              std::vector<LocalRouteVertex>& output) const;
                
                bool CreateVertexWithTerrainFromIndex(int index,const dv3& cellCentre, LocalRouteVertex& out_localRouteVertex) const;
                
                const Eegeo::v4& CalcVertexColour(const RouteVertex& routeVertex) const;
                
                const Route& m_route;
                const Streaming::MortonKey& m_key;
                const FittingTerrainProjector& m_fittingTerrainProjector;
                const Eegeo::v4 m_colorOverride;
                const bool m_useColorOverride;
                bool m_fittingAttempted;
            };
        }
    }
}
