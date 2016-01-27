// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "BuildingFootprints.h"
#include "Types.h"
#include "CollisionVisualization.h"
#include "Collision.h"

#include <string>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingSelectionController : private Eegeo::NonCopyable
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
            
            BuildingSelectionController(Eegeo::CollisionVisualization::MaterialSelectionController& collisionMaterialSelectionController,
                                        Eegeo::BuildingFootprints::BuildingFootprintSelectionController& buildingFootprintsSelectionController);
            
            void PerformOperation(const Eegeo::Collision::RayCasterResult& pickResult, Operation operation);
            void DeselectAll();
        private:
            void PerformCollisionMaterialSelection(const std::string& collisionMaterialId, Operation operation);
        
            Eegeo::CollisionVisualization::MaterialSelectionController& m_collisionMaterialSelectionController;
            Eegeo::BuildingFootprints::BuildingFootprintSelectionController& m_buildingFootprintsSelectionController;
        };
    }
}