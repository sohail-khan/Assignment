// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "CollisionMaterial.h"

#include <vector>
#include <string>
#include <algorithm>

namespace Eegeo
{
    namespace Collision
    {
        struct CollisionMaterialTable
        {
            CollisionMaterialTable(const std::vector<CollisionMaterial>& collisionMaterials)
            : m_collisionMaterials(collisionMaterials)
            {}
            
            std::string IdAtIndex(int tableIndex) const { return m_collisionMaterials.at(tableIndex).MaterialId(); }
            
            bool Contains(const std::string materialId) const
            {
                return std::find_if(m_collisionMaterials.begin(), m_collisionMaterials.end(), MatchesId(materialId)) != m_collisionMaterials.end();
            }
            
            int FindIndexOf(const std::string materialId) const
            {
                std::vector<CollisionMaterial>::const_iterator iter = std::find_if(m_collisionMaterials.begin(), m_collisionMaterials.end(), MatchesId(materialId));
                if (iter == m_collisionMaterials.end())
                    return -1;
                else
                    return static_cast<int>(std::distance(m_collisionMaterials.begin(), iter));
            }
            
        private:
            std::vector<CollisionMaterial> m_collisionMaterials;
        };
    }
}