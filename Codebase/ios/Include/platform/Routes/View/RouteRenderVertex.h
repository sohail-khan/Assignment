// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            struct RouteRenderVertex
            {
                float x, y, z;
                float displacementX, displacementY, displacementZ;
                float r,g,b,a;
			};
			
            
            inline void CreateRouteRenderVertex(
                    const v3& position, const v3& displacement, const v4& color, RouteRenderVertex& outVertex)
            {
                outVertex.x = position.x;
                outVertex.y = position.y;
                outVertex.z = position.z;

                outVertex.displacementX = displacement.x;
                outVertex.displacementY = displacement.y;
                outVertex.displacementZ = displacement.z;

                outVertex.r = color.x;
                outVertex.g = color.y;
                outVertex.b = color.z;
                outVertex.a = color.w;
            }
        }
    }
}
