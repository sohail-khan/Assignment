// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"
#include "VectorMath.h"
#include "ICallback.h"
#include "Camera.h"
#include "BuildingFootprintSelectionModel.h"

#include <map>
#include <vector>
#include <string>


namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintSelectionController : private Eegeo::NonCopyable
        {
        public:
            enum Operation
            {
                Select,
                Deselect,
                Toggle,
                SetFlashing,
                CycleFlashing
            };
            
            
            typedef Eegeo::Helpers::TCallback2<BuildingFootprintSelectionController, const BuildingFootprintServiceQueryResult, const Operation> OperationCallback;
            
            typedef std::vector<BuildingFootprint> FootprintVector;
            typedef BuildingFootprintSelectionModel::ModelId ModelId;
            
            BuildingFootprintSelectionController(BuildingFootprintService& buildingFootprintService,
                                                 BuildingFootprintSelectionViewFactory& viewFactory,
                                                 CollisionVisualization::CollisionVisualizationRenderer& collisionVisualizationRenderer,
                                                 const BuildingFootprints::BuildingFootprintSelectionControllerConfig& config);
            
            ~BuildingFootprintSelectionController();
            
            void OperateOnClosestGroup(const dv3& pointEcef, Operation operation);

            void DeselectAll();
            
            void Update(float dt);
            void Draw(const Eegeo::Camera::RenderCamera& renderCamera);
            
        private:
            typedef std::map<ModelId, BuildingFootprintSelectionModel*> IdToModel;
            typedef std::map<const BuildingFootprintSelectionModel*, BuildingFootprintSelectionView*> ModelToView;
            
            void HandleOperationCallback(const Eegeo::BuildingFootprints::BuildingFootprintServiceQueryResult& result, const Operation& operation);
            
            bool IsSelected(const ModelId& modelId) const;
            BuildingFootprintSelectionModel* GetModelOrNull(const ModelId& modelId) const;
            void SelectModel(const ModelId& modelId, const FootprintVector& footprints);
            void DeselectModel(const ModelId& modelId);
            
            void RemoveAllModels();
            void RemoveAllViews();
            void PerformOperation(const ModelId& modelId, const FootprintVector& footprints, Operation operation);
            
            
            IdToModel m_idToModel;
            ModelToView m_modelToView;
            
            BuildingFootprintService& m_buildingFootprintService;
            BuildingFootprintSelectionViewFactory& m_viewFactory;
            CollisionVisualization::CollisionVisualizationRenderer& m_collisionVisualizationRenderer;
            
            OperationCallback m_operationCallback;
            
            float m_flashingPhase;
           
            const v4 m_color;
            const float m_flashFrequency;
            const float m_flashSaturateScale;
            const float m_flashAlphaMin;
            const float m_flashAlphaMax;
        };
    }
}
