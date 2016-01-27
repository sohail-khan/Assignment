// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Terrain.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSamplerFactory : public Eegeo::NonCopyable
            {
                const Fitting::FittedRouteRepository& m_fittedRouteRepository;
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                
            public:
                RouteSamplerFactory(const Fitting::FittedRouteRepository& fittedRouteRepository,
                                    const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider);
                
                RouteSampler* CreateForRoute(const Route& route) const;
            };
        }
    }
}
