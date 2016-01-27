// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"
#include "VectorMath.h"
#include "Camera.h"

#include <map>
#include <vector>
#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class MaterialSelectionController : private Eegeo::NonCopyable
        {
        public:
            MaterialSelectionController(const MaterialSelectionControllerConfig& config,
                                        MaterialSelectionModel& model,
                                        const Collision::ICollisionBvhProvider& collisionBvhProvider,
                                        MaterialSelectionRenderableFactory& renderableFactory,
                                        CollisionVisualizationRenderer& renderer);
            
            ~MaterialSelectionController();
            
            bool IsSelected(const std::string& materialId) const;
            bool IsFlashing(const std::string& materialId) const;
            
            void Select(const std::string& materialId);
            void SetFlashingState(const std::string& materialId, bool flashing);
            void CycleFlashing(const std::string& materialId);
            void Deselect(const std::string& materialId);
            void DeselectAll();
            
            void Update(float dt);
            void Draw(const Eegeo::Camera::RenderCamera& renderCamera);
            
            void NotifyCollisionResourcesChanged();
        private:
            typedef std::map<const MaterialSelectionModelEntry*, MaterialSelectionView*> ModelEntryToView;
            
            void RefreshViewRenderables(const std::vector<const Collision::CollisionBvh*>& gatheredCollisionBvhs);
            void RemoveAllViews();
            
            ModelEntryToView m_modelEntryToView;

            float m_flashingPhase;
            bool m_needRefreshViewRenderables;
            
            const v4 m_color;
            const float m_flashFrequency;
            const float m_flashSaturateScale;
            const float m_flashAlphaMin;
            const float m_flashAlphaMax;
            
            MaterialSelectionModel& m_model;
            const Collision::ICollisionBvhProvider& m_collisionBvhProvider;
            MaterialSelectionRenderableFactory& m_renderableFactory;
            CollisionVisualizationRenderer& m_renderer;
        };

    }
}
