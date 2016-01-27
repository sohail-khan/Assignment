// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "EcefTangentBasis.h"
#include "RouteViewGeometryFactoryConfig.h"
#include "Types.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewGeometryFactory
            {
            private:
                RouteViewGeometryFactory(const Fitting::FittedRoute& route,
                                       const Eegeo::Space::EcefTangentBasis& basis,
                                       const RouteViewGeometryFactoryConfig& config);

                const Fitting::FittedRoute& m_route;
                const Eegeo::Space::EcefTangentBasis m_ecefTangentBasis;
                const RouteViewGeometryFactoryConfig m_config;

            public:
                void CreateGeometry(
                        const std::vector<LocalRouteVertex>& vertices,
                        std::vector<RouteRenderVertex>& outVertices,
                        std::vector<u16>& outIndices);

                static RouteViewGeometryFactory Create(const Fitting::FittedRoute& route);
            };
        }
    }
}