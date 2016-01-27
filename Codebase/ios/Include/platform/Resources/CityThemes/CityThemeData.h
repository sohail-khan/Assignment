// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <map>
#include <string>
#include "LatLongAltitude.h"
#include "TrafficSimulationConfiguration.h"
#include "PlaceNameCategoryStyle.h"
#include "CityThemeState.h"
#include "CityThemeAnimationData.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeData
            {
            public:
                std::string Name;
                std::string AssetRoot;
                Space::LatLong Location;
                std::string CustomLandmarkTextureRepositoryUrlBase;
                std::string GlobeViewThemeStateName;
                float GlobeViewSwitchAltitude;
                std::vector<std::string> LandmarkTexturePostfixes;
                
                float BaseAltitude;
                
                std::map<std::string, CityThemeState> States;
                std::vector<CityThemeAnimationData> Animations;
                std::vector<Space::LatLong> PolygonBounds;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration RoadVehiclesConfig;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration RailVehiclesConfig;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration TramVehiclesConfig;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration PlaneVehiclesConfig;
                std::map<std::string, Resources::PlaceNames::PlaceNameCategoryStyle> PlaceNameStyleMap;
                
                CityThemeData();

                // Not data in the json, just a helper flag
                bool IsEmbeddedTheme;

                bool IsCityThemeStateSupported(const std::string& stateName) const
                {
                    return States.find(stateName) != States.end();
                }

                const CityThemeState& GetCityThemeState(const std::string& stateName) const
                {
                    return States.at(stateName);
                }
                
                std::map<std::string, std::string> GetLandmarkTexturePathsByState(const std::string& landmarkTextureName) const;
            };
        }
    }
}