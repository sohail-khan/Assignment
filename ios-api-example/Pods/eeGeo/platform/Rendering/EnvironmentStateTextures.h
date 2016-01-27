// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "IdTypes.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        class EnvironmentStateTextures
        {
        private:
            EnvironmentTexture* RailDiffuse;
            EnvironmentTexture* TreeDiffuse;
            EnvironmentTexture* TreeTopDiffuse;
            EnvironmentTexture* BuildingsDiffuse;
            EnvironmentTexture* RoadDiffuse;
            EnvironmentTexture* WaterNormal;
            EnvironmentTexture* WaterReflection;
            EnvironmentTexture* AsyncPlaceholderDiffuse;
            EnvironmentTexture* PlaceholderNoDataDiffuse;
            EnvironmentTexture* OverlayEffect;
            EnvironmentTexture* VehicleDiffuse;
            EnvironmentTexture* TrainDiffuse;
            EnvironmentTexture* TramDiffuse;
            EnvironmentTexture* PlaneDiffuse;
            std::vector<EnvironmentTexture*> LcmDiffuse;
            std::vector<EnvironmentTexture*> LcmLodDiffuse;
            
        public:
            EnvironmentStateTextures(EnvironmentTexture* railDiffuse,
                                     EnvironmentTexture* treeDiffuse,
                                     EnvironmentTexture* treeTopDiffuse,
                                     EnvironmentTexture* buildingsDiffuse,
                                     EnvironmentTexture* roadDiffuse,
                                     EnvironmentTexture* vehicleDiffuse,
                                     EnvironmentTexture* trainDiffuse,
                                     EnvironmentTexture* tramDiffuse,
                                     EnvironmentTexture* planeDiffuse,
                                     EnvironmentTexture* waterNormal,
                                     EnvironmentTexture* waterReflection,
                                     EnvironmentTexture* asyncPlaceholderDiffuse,
                                     EnvironmentTexture* placeholderNoDataDiffuse,
                                     EnvironmentTexture* overlayEffect,
                                     const std::vector<EnvironmentTexture*>& lcmDiffuse,
                                     const std::vector<EnvironmentTexture*>& lcmLodDiffuse);

            TTextureId GetRailDiffuse() const;
            TTextureId GetTreeDiffuse() const;
            TTextureId GetTreeTopDiffuse() const;
            TTextureId GetBuildingsDiffuse() const;
            TTextureId GetRoadDiffuse() const;
            TTextureId GetRoadVehicleDiffuse() const;
            TTextureId GetTrainDiffuse() const;
            TTextureId GetTramDiffuse() const;
            TTextureId GetPlaneDiffuse() const;
            TTextureId GetWaterNormal() const;
            TTextureId GetWaterReflection() const;
            TTextureId GetAsyncPlaceholderDiffuse() const;
            TTextureId GetOverlayEffect() const;
            TTextureId GetPlaceholderNoDataDiffuse() const;
            TTextureId GetLcmDiffuse(int lcmIndex) const;
            TTextureId GetLcmLodDiffuse(int lcmIndex) const;
            
            EnvironmentTexture* GetAsyncPlaceholderEnvironmentTexture() const;
            
            void ReleaseTextures();
        };
    }
}
