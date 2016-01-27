// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Terrain.h"
#include "VectorMathDecl.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSampler
            {
            public:
                RouteSampler(const Route& route,
                             const Fitting::FittedRouteRepository& fittedRouteRepository,
                             const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider)
                : m_fittedRouteSection(NULL)
                , m_route(route)
                , m_fittedRouteRepository(fittedRouteRepository)
                , m_terrainHeightProvider(terrainHeightProvider)
                {
                    
                }
                
                void Invalidate()
                {
                    m_fittedRouteSection = NULL;
                }
                
                void InvalidateFittedRouteSectionForKey(const double routeParam, const Eegeo::Streaming::MortonKey& key);
                
                void UpdateFittedRouteSection(const double routeParam);
                
                RouteSample RouteSimVertexAtRouteParam(const double routeParam) const;
                
            private:
                const Fitting::FittedRouteSection* FindFittedRouteSection(const double routeParam) const;
                
                bool TryGetLocalRouteVertex(const double routeParam, LocalRouteVertex& out_localRouteVertex, dv3& out_cellOrigin, v3& out_direction) const;
                
                bool TryGetInterpolatedLocalRouteVertex(const double routeParam, const Fitting::FittedRouteSection& fittedRouteSection, LocalRouteVertex& out_interpolatedVertex, v3& out_direction) const;
                
                dv3 ProjectOntoTerrain(const dv3& pointEcef) const;
            
            
                const Route& m_route;
                const Fitting::FittedRouteRepository& m_fittedRouteRepository;
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                const Fitting::FittedRouteSection* m_fittedRouteSection;
            };
            

        }
    }
}
