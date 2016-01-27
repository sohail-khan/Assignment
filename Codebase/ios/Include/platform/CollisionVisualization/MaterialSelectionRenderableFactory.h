// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"

#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class MaterialSelectionRenderableFactory : private Eegeo::NonCopyable
        {
        public:
            MaterialSelectionRenderableFactory(CollisionVisualizationRenderableFactory& renderableFactory)
            : m_renderableFactory(renderableFactory)
            {
                
            }
            
            CollisionVisualizationRenderable* Create(const std::string& materialId, const Collision::CollisionBvh& collisionBvh);
            
        private:
            CollisionVisualizationRenderableFactory& m_renderableFactory;
        };
    }
}