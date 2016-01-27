// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionGroup.h"
#include "ICollisionBvhProvider.h"
#include "CollisionBvhRayCaster.h"


#include <vector>
#include <algorithm>

namespace Eegeo
{
    namespace Collision
    {
        class CollisionBvhGatherer : public Eegeo::NonCopyable
        {
        public:
            typedef std::vector<const CollisionBvh*> CollisionBvhVector;

            
            CollisionBvhGatherer(const ICollisionBvhProvider& collisionBvhProvider)
            : m_collisionBvhProvider(collisionBvhProvider)
            {
                
            }
            
            template <typename TPredicate, typename TOutIter>
            TOutIter Gather(const u32 collidableGroupsMask, TOutIter outIter, TPredicate predicate)
            {
                const size_t totalCount = m_collisionBvhProvider.CountCollisionBvhsForGroups(collidableGroupsMask);
                CollisionBvhVector collisionBvhBuffer;
                collisionBvhBuffer.resize(totalCount);
                m_collisionBvhProvider.CopyCollisionBvhsForGroups(collidableGroupsMask, collisionBvhBuffer.data(), collisionBvhBuffer.size());
                
                return std::remove_copy_if(collisionBvhBuffer.begin(), collisionBvhBuffer.end(), outIter, std::not1(predicate));
            }
        private:
            const ICollisionBvhProvider& m_collisionBvhProvider;
            
        };
        
        struct ContainsCollisionMaterial : public std::unary_function<const Collision::CollisionBvh*, bool>
        {
            ContainsCollisionMaterial(std::string collisionMaterialId)
            : m_collisionMaterialId(collisionMaterialId)
            {}
            
            bool operator() (const Collision::CollisionBvh* pCollisionBvh) const
            {
                return pCollisionBvh->GetCollisionMaterialTable().Contains(m_collisionMaterialId);
            }
        private:
            std::string m_collisionMaterialId;
        };
        
        struct ContainsAnyOfCollisionMaterials : public std::unary_function<const Collision::CollisionBvh*, bool>
        {
            ContainsAnyOfCollisionMaterials(const std::vector<std::string>& collisionMaterialIds)
            : m_collisionMaterialIds(collisionMaterialIds)
            {}
            
            bool operator() (const Collision::CollisionBvh* pCollisionBvh) const
            {
                Eegeo_ASSERT(pCollisionBvh != NULL);
                const CollisionMaterialTable& table = pCollisionBvh->GetCollisionMaterialTable();
                for (std::vector<std::string>::const_iterator iter = m_collisionMaterialIds.begin(); iter != m_collisionMaterialIds.end(); ++iter)
                {
                    const std::string& materialId = *iter;
                    if (table.Contains(materialId))
                    {
                        return true;
                    }
                }
                return false;
            }
        private:
            const std::vector<std::string>& m_collisionMaterialIds;
        };
    }
}