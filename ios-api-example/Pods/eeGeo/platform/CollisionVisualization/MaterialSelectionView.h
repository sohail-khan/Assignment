// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"
#include "CollisionVisualizationRenderable.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class MaterialSelectionView : private Eegeo::NonCopyable
        {
        public:
            MaterialSelectionView()
            : m_color(v4::Zero())
            {}
            
            ~MaterialSelectionView();
            
            void SetColor(const v4& color) { m_color = color; }
            
            void SubmitRenderables(CollisionVisualizationRenderer& renderer);
            
            void RefreshRenderables(const std::string& materialId, const std::vector<const Collision::CollisionBvh*>& collisionBvhsForView, MaterialSelectionRenderableFactory& renderableFactory);
            
            typedef std::pair<const Collision::CollisionBvh*, CollisionVisualizationRenderable*> BvhRenderablePair;
        private:
            typedef std::vector<BvhRenderablePair> BvhRenderablePairs;
            
            BvhRenderablePairs m_pairs;
            v4 m_color;
            
        };
    }
}