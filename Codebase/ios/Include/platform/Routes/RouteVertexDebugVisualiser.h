// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Routes.h"
#include "DebugRendering.h"
#include "MortonKey.h"
#include "FittedRouteCallback.h"
#include "RouteVertexDebugVisualiser.h"
#include "RouteCallback.h"
#include "VectorMathDecl.h"

#include <vector>
#include <map>

namespace Eegeo
{
    namespace Routes
    {
        class RouteVertexDebugVisualiser
        {
        private:
            Routes::Fitting::FittedRouteRepository& m_fittedRouteRepository;
            Routes::RouteRepository& m_routeRepository;
            DebugRendering::DebugRenderer& m_debugRenderer;
            
            typedef std::vector<DebugRendering::DebugSphereData*> TSphereVector;
            std::map<Streaming::MortonKey, TSphereVector> m_sphereMap;
            bool m_enabled;
            
            Fitting::TFittedRouteCallback<RouteVertexDebugVisualiser> m_fittedRouteAddedCallback;
            Fitting::TFittedRouteCallback<RouteVertexDebugVisualiser> m_fittedRouteRemovedCallback;
            Routes::TRouteCallback<RouteVertexDebugVisualiser> m_routeRemovedCallback;
            
            void GenerateVertexDebugSpheres(const Routes::Route* pRoute, const Streaming::MortonKey& key);
            void RemoveSpheres(const Routes::Route* pRoute, const Streaming::MortonKey key);
            void RemoveAllSpheres();
            
            void HandleFittedRouteAdded(const Fitting::FittedRoute& fittedRoute);
            void HandleFittedRouteRemoved(const Fitting::FittedRoute& fittedRoute);
            void HandleRouteRemoved(const Route* route);
            
        public:
            RouteVertexDebugVisualiser(Routes::Fitting::FittedRouteRepository& fittedRouteRepository,
                                       Routes::RouteRepository& routeRepository,
                                       DebugRendering::DebugRenderer& debugRenderer);
            
            
            void RenderSpheres();
            bool GetEnabled() const { return m_enabled; };
            void ToggleEnabled();
        };
    }
}
