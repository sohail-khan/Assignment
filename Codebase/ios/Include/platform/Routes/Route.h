// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Routes.h"
#include "ClippedRoute.h"
#include "RouteVertex.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class Route : public Eegeo::NonCopyable
        {
            std::vector<RouteVertex> m_points;
            
            Clipping::ClippedRoute m_routeClippedToCells;
        
            
            bool m_fittingToNavigationGraphEnabled;
            
        public:
            Route(const std::vector<RouteVertex>& clippedRouteVertices,
                  const Clipping::ClippedRoute& routeClippedToCells,
                  bool fittingToNavigationGraphEnabled
                  );
            
            const std::vector<RouteVertex>& GetPoints() const;
            
            
            void GetCoveredKeys(std::vector<Streaming::MortonKey>& coverage) const;
            
            bool TryGetClippedRouteSectionsForCell(const Streaming::MortonKey& key, std::vector<Clipping::ClippedRouteSection>& sections) const;
            
            bool HasClippedRouteSectionForCell(const Streaming::MortonKey& key) const;
            
            const std::vector<Clipping::ClippedRouteSection>& GetClippedRouteSectionsForCell(const Streaming::MortonKey& key) const;
            
            void GetClippedRouteSectionsForCells(const std::vector<Streaming::MortonKey>& keys, std::vector<Clipping::ClippedRouteSection>& out_clippedRouteSections) const;
            
            bool GetFittingToNavigationGraphEnabled() const;
            
            double GetLength() const;
            
            static int FindRouteVertexIndexImmediatelyBefore(const std::vector<RouteVertex>& routeVertices, const double routeParam);
            
            static RouteVertex GetInterpolatedRouteVertex(const std::vector<RouteVertex>& routeVertices, const double routeParam, v3& out_direction);
            
            static double DistanceToRoute(const std::vector<RouteVertex>& routeVertices, const dv3& pointEcef, double& out_paramAtClosestApproach, int& out_indexImmediatelyBefore);
        };
    }
}
