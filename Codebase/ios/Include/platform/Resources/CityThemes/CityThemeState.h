// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>
#include <string>
#include "VectorMath.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeState
            {
            public:
                std::string Name;
                std::string RoadDiffuse;
                std::string RailDiffuse;
                std::string BuildingDiffuse;
                std::string TreeTopDiffuse;
                std::string TreeSideDiffuse;
                std::string VehicleDiffuse;
                std::string PlaneDiffuse;
                std::string TrainDiffuse;
                std::string TramDiffuse;
                std::string WaterNormal;
                std::string WaterReflection;
                std::string AsyncPlaceholderDiffuse;
                std::string PlaceholderNoDataDiffuse;
                std::vector<std::string> LcmTerrainDiffuse;
                std::vector<std::string> LcmTerrainLodDiffuse;
                
                Eegeo::m44 Lighting;
                Eegeo::v3 AlternativeAmbientLight; // used for various effects, including night lighting on buildings, vehicles.
                Eegeo::v3 FogColor;
                float FogIntensity;

                std::string LandmarkPostfix;
                std::string VehicleNodeSuffix;
                
                // If FogIntensity or LightMapIntensity > 0.f, then ShadowColor is white (off)
                Eegeo::v3 ShadowColor;
                
                Eegeo::v3 LightMapColor;
                float LightMapIntensity;
                
                std::string OverlayEffect;
                float OverlayIntensity;
                
                Eegeo::v2 OverlayLayerOneOffset;
                Eegeo::v2 OverlayLayerOneVelocity;
                float OverlayLayerOneAlpha;
                float OverlayLayerOneScale;
                
                Eegeo::v2 OverlayLayerTwoOffset;
                Eegeo::v2 OverlayLayerTwoVelocity;
                float OverlayLayerTwoAlpha;
                float OverlayLayerTwoScale;
                
                const std::string& GetLandmarkPostfix() const { return LandmarkPostfix; }
            };
        }
    }
}
