// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace Rendering
    {    
        namespace MaterialNames
        {
            static const std::string Buildings = "buildings_01";
            static const std::string CustomLandmark = "custom_landmark";
            static const std::string CustomLandmarkPunchThrough = "custom_landmark_punchthrough";
            static const std::string Roads = "roads_01";
            static const std::string TreeTops = "trees_top_01";
            static const std::string Trees = "trees_01";
            static const std::string Rail = "rail_01";
            static const std::string Tramlines = "tramlines_01";
            static const std::string ShadowVolumeGeometry = "shadows";
            static const std::string ShadowOverlay = "shadow_overlay";
            static const std::string Text = "text";
            static const std::string RasterTerrain = "raster_terrain";
            static const std::string PlaceholderTerrain = "placeholder_terrain";
            static const std::string PlaceholderTerrainNoData = "placeholder_terrain_no_data";
            static const std::string WeatherEffects = "weather_effects_overlay";
            static const std::string RoadVehicles = "road_vehicles";
            static const std::string Trains = "trains";
            static const std::string Trams = "trams";
            static const std::string Planes = "planes";
            
            enum LcmCode
            {
                LcmCode_Terrain0 = 0,
                LcmCode_FirstTerrain = LcmCode_Terrain0,
                LcmCode_Terrain1,
                LcmCode_Terrain2,
                LcmCode_Terrain3,
                LcmCode_Terrain4,
                LcmCode_Terrain5,
                LcmCode_Terrain6,
                LcmCode_Terrain7,
                LcmCode_Terrain8,
                LcmCode_Terrain9,
                LcmCode_Terrain10,
                LcmCode_Terrain11,
                LcmCode_Terrain12,
                LcmCode_Terrain13,
                LcmCode_Terrain14,
                LcmCode_Terrain15,
                LcmCode_Terrain16,
                LcmCode_Terrain17,
                LcmCode_Terrain18,
                LcmCode_LastTerrain = LcmCode_Terrain18,
                
                LcmCode_FirstWater = 253,
                LcmCode_ShallowWater = LcmCode_FirstWater,
                LcmCode_MidWater = 254,
                LcmCode_DeepWater = 255,
                LcmCode_LastWater = LcmCode_DeepWater,
                LcmCode_MAX = LcmCode_DeepWater
            };
            
            static const int NumOfLcmCodes = (LcmCode_LastTerrain - LcmCode_FirstTerrain + 1) + (LcmCode_LastWater - LcmCode_FirstWater + 1);
            
            static const LcmCode LcmCodes[NumOfLcmCodes] = {
                LcmCode_Terrain0,
                LcmCode_Terrain1,
                LcmCode_Terrain2,
                LcmCode_Terrain3,
                LcmCode_Terrain4,
                LcmCode_Terrain5,
                LcmCode_Terrain6,
                LcmCode_Terrain7,
                LcmCode_Terrain8,
                LcmCode_Terrain9,
                LcmCode_Terrain10,
                LcmCode_Terrain11,
                LcmCode_Terrain12,
                LcmCode_Terrain13,
                LcmCode_Terrain14,
                LcmCode_Terrain15,
                LcmCode_Terrain16,
                LcmCode_Terrain17,
                LcmCode_Terrain18,
                LcmCode_ShallowWater,
                LcmCode_MidWater,
                LcmCode_DeepWater
            };
            
            bool IsValidLcmCode(int lcmCode);
            
            const std::string GetLcmMaterialName(int lcmCode);
            const std::string GetLcmLodMaterialName(int lcmCode);
            
            static const std::string DeepWater = GetLcmMaterialName(LcmCode_DeepWater);
            static const std::string MidWater = GetLcmMaterialName(LcmCode_MidWater);
            static const std::string ShallowWater = GetLcmMaterialName(LcmCode_ShallowWater);
            static const std::string DeepWaterLod = GetLcmLodMaterialName(LcmCode_DeepWater);
            static const std::string MidWaterLod = GetLcmLodMaterialName(LcmCode_MidWater);
            static const std::string ShallowWaterLod = GetLcmLodMaterialName(LcmCode_ShallowWater);
        }
    }
}
