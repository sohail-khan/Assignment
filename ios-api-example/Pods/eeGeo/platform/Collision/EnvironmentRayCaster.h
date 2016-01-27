// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionGroup.h"
#include "RayCasterResult.h"
#include "Rendering.h"
#include "IRayCaster.h"


namespace Eegeo
{
    namespace Collision
    {
        class EnvironmentRayCaster : public Eegeo::NonCopyable, public IRayCaster
        {
        public:
            EnvironmentRayCaster(const ICollisionBvhProvider& collisionBvhProvider,
                                 const Eegeo::Rendering::EnvironmentFlatteningService& environmentFlatteningService);

            virtual ~EnvironmentRayCaster() {;}
            
            virtual RayCasterResult CastRay(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection, u32 collidableGroupsMask=Collision::CollisionGroup::CollideAll);

        private:
            const ICollisionBvhProvider& m_collisionBvhProvider;
            const Eegeo::Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
        };
    }
}