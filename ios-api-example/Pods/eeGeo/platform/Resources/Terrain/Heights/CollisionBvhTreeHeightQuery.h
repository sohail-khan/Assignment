// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "Terrain.h"
#include "VectorMathDecl.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Heights
            {
                // todo make general CollisionBvhIntersectionQuery
                class CollisionBvhHeightQuery
                {
                public:
                    static bool TryGetHeight(const Eegeo::dv3 &ecefCellCenter,
                                             const Eegeo::Collision::CollisionBvh& collisionBvh,
                                             const Eegeo::dv3 &upDirection,
                                             const Eegeo::dv3 &rayStartPoint,
                                             const Eegeo::dv3 &localRayStartPoint,
                                             const Eegeo::dv3 &localRayEndPoint,
                                             float &height);
                    
                                        
                };
            }
        }
	}
}
