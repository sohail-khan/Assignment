// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "ICollisionBvhFactory.h"
#include "Space.h"

namespace Eegeo
{
    namespace Collision
    {
        class CollisionBvhFactory : public ICollisionBvhFactory, private Eegeo::NonCopyable
        {
        public:
            CollisionBvhFactory(CollisionGroup::Type collisionGroup);
        
            virtual CollisionBvh* Create(const dv3& ecefOrigin,
                                         const ReaderCollisionResult& readerCollisionResult,
                                         const ReaderMeshResults& readerMeshResults);
        protected:
        
            virtual CollisionBvh* Create(const dv3& ecefOrigin,
                                         const ReaderCollisionResult& readerCollisionResult,
                                         const CollisionMaterialTable* pMaterialTable);

        private:
            CollisionGroup::Type m_collisionGroup;
            
        };
        
    }
}