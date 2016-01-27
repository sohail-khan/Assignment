// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Collision.h"
#include "BuildingFootprints.h"
#include "Rendering.h"
#include "DebugRendering.h"
#include "ICallback.h"
#include "CollisionVisualization.h"


#include <string>
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace BuildingFootprints
        {
            class DebugBuildingFootprintsController : public Eegeo::NonCopyable
            {
                enum Mode
                {
                    Disabled,
                    LandmarkOrFootprint,
                    RoofOutline,
                    CentroidsInRadius,
                    MaxModes
                };
            public:
                DebugBuildingFootprintsController(Eegeo::Collision::ICollisionBvhProvider& collisionPvhProvider,
                                                  Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                  Eegeo::BuildingFootprints::BuildingFootprintService& buildingFootprintService,
                                                  Eegeo::DebugRendering::DebugRenderer& debugRenderer,
                                                  Eegeo::BuildingFootprints::BuildingSelectionController& buildingSelectionController);
                
                ~DebugBuildingFootprintsController();
                
                bool IsEnabled() const { return m_mode != Disabled; }
                void CycleMode();
                std::string GetModeDescription() const;
                
                void PerformQueryAtPickedPoint(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection);
                
            private:
                void HandleFootprintsInRadius(const Eegeo::BuildingFootprints::BuildingFootprintServiceQueryResult& result);
                void HandleHighlightRoofOutlines(const Eegeo::BuildingFootprints::BuildingFootprintServiceQueryResult& result);
                void DrawFootprintCentroid(const Eegeo::BuildingFootprints::BuildingFootprint& footprint);
                void DrawFootprintRoofOutline(const Eegeo::BuildingFootprints::BuildingFootprint& footprint);
                void SelectLandmarkOrFootprint(const Eegeo::Collision::RayCasterResult& pickResult);
                void HighlightRoofOutlines(const Eegeo::Collision::RayCasterResult& pickResult);
                void OnModeChanged();

                
                Eegeo::Collision::EnvironmentRayCaster* m_pRayCaster;
                Eegeo::DebugRendering::DebugRenderer& m_debugRenderer;

                Eegeo::BuildingFootprints::BuildingFootprintService& m_buildingFootprintService;
                Eegeo::BuildingFootprints::BuildingSelectionController& m_buildingSelectionController;
                Mode m_mode;
                
                Eegeo::Helpers::TCallback1<DebugBuildingFootprintsController, const Eegeo::BuildingFootprints::BuildingFootprintServiceQueryResult> m_footprintsInRadiusCallback;
                Eegeo::Helpers::TCallback1<DebugBuildingFootprintsController, const Eegeo::BuildingFootprints::BuildingFootprintServiceQueryResult> m_highlightRoofOutlines;
                
            };
        }
    }
}