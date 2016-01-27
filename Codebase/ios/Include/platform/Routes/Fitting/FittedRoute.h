// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "VectorMath.h"
#include "FittedRouteSection.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            struct FittedRoute
            {
                FittedRoute(
                            const Route* pRoute,
                            const Eegeo::Streaming::MortonKey& key,
                            const dv3& cellCentreEcef,
                            const std::vector<FittedRouteSection>& sections,
                            bool isFittedToNavigationGraph,
                            bool fittingAttempted,
                            bool terrainHeightsValid)
                : m_route(pRoute)
                , m_key(key)
                , m_cellCentreEcef(cellCentreEcef)
                , m_sections(sections)
                , m_isFittedToNavigationGraph(isFittedToNavigationGraph)
                , m_fittingAttempted(fittingAttempted)
                , m_terrainHeightsValid(terrainHeightsValid)
                {
                }
                
                const std::vector<FittedRouteSection>& GetSections() const { return m_sections; }
                const Eegeo::dv3& GetEcefPos() const { return m_cellCentreEcef; }
                const Route* GetRoute() const { return m_route; }
                const Streaming::MortonKey& GetKey() const { return m_key; }
                bool IsFittedToNavigationGraph() const { return m_isFittedToNavigationGraph; }
                bool WasFittingAttempted() const { return m_fittingAttempted; }
                bool IsTerrainHeightsValid() const { return m_terrainHeightsValid; }
                
            private:
                const Route* m_route;
                Eegeo::Streaming::MortonKey m_key;
                Eegeo::dv3 m_cellCentreEcef;
                std::vector<FittedRouteSection> m_sections;
                bool m_isFittedToNavigationGraph;
                bool m_fittingAttempted;
                bool m_terrainHeightsValid;
            };
        }
    }
}
