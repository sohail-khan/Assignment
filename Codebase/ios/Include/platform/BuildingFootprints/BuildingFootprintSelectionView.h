// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "CollisionVisualization.h"
#include "VectorMath.h"
#include "Types.h"
#include "Geometry.h"

#include <vector>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintSelectionView : private Eegeo::NonCopyable
        {
        public:
            BuildingFootprintSelectionView(CollisionVisualization::CollisionVisualizationRenderable* pRenderable);
            
            ~BuildingFootprintSelectionView();
            
            void SetColor(const v4& color);
            
            bool IsPotentiallyVisible(const dv3& cameraOrigin, const Eegeo::Geometry::Frustum& frustum) const;
            
            void SubmitRenderables(CollisionVisualization::CollisionVisualizationRenderer& renderer);
        private:
            CollisionVisualization::CollisionVisualizationRenderable* m_pRenderable;
        };
    }
}