// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "RayMeshIntersectionResult.h"
#include "RayNodeIntersectionResult.h"
#include "RayCasterResult.h"
#include "VectorMath.h"

#include <functional>

namespace Eegeo
{
    namespace Collision
    {
        struct RayCasterFirstIntersectionBuilder : public std::unary_function<RayNodeIntersectionResult, bool>
        {
            RayCasterFirstIntersectionBuilder(const dv3& rayOriginEcef, const dv3& rayDirection, float environmentFlatteningScale);
            
            bool operator () (const RayNodeIntersectionResult& nodeIntersection);
            
            RayCasterResult BuildResult() const;
        private:
            const dv3 m_rayOriginEcef;
            const dv3 m_rayDirection;
            const float m_environmentFlatteningScale;
            RayMeshIntersectionResult m_best;
            const CollisionBvh* m_pCurrentBvh;
            const CollisionBvhNode* m_pCurrentNode;
        };
    }
}