// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            void TransformInputVertices(
                    const std::vector<LocalRouteVertex>& originalVerts,
                    const m33& tangentBasisTranspose,
                    std::vector<RouteVert>& outVerts);

            void TransformToRenderVerts(
                    const std::vector<RouteVert>& inputVerts,
                    const m33& basisRot,
                    std::vector<RouteRenderVertex>& outRenderVerts);
        }
    }
}