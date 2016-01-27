// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionGroup.h"
#include "AllVertexTypes.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Collision
    {
        struct CollisionSubMesh
        {
            dv3 originEcef;
            v3 quantizationRelativeOrigin;
            float quantizationScale;
            
            CollisionGroup::Type collisionGroup;
            std::string collisionMaterialId;
            std::vector<Rendering::VertexTypes::ShortPositionVertex> points;
            std::vector<u16> triListIndices;
            
            v3 GetInflatedPoint(const Rendering::VertexTypes::ShortPositionVertex& q) const
            {
                v3 p(q.x, q.y, q.z);
                p *= quantizationScale;
                p += quantizationRelativeOrigin;
                return p;
            }
        };
    }
}