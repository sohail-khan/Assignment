// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "CollisionGroup.h"

#include <string>
#include <functional>

namespace Eegeo
{
    namespace Collision
    {
        struct CollisionMaterial
        {
            CollisionMaterial(CollisionGroup::Type collisionGroup, const std::string& materialId)
            : m_collisionGroup(collisionGroup)
            , m_materialId(materialId)
            {
                
            }
            
            CollisionGroup::Type CollisionGroup() const { return m_collisionGroup; }
            std::string MaterialId() const { return m_materialId; }
        private:
            CollisionGroup::Type m_collisionGroup;
            std::string m_materialId;
        };
        
        struct MatchesId : public std::unary_function<const CollisionMaterial&, bool>
        {
            MatchesId(const std::string& materialId)
            : m_materialId(materialId) {}
            
            bool operator() (const CollisionMaterial& collisionMaterial) const
            {
                return collisionMaterial.MaterialId() == m_materialId;
            }
            const std::string m_materialId;
        };
    }
}