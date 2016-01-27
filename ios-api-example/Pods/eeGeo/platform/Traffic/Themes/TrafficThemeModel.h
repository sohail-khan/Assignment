// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TrafficSimulationConfiguration.h"
#include "CityThemeState.h"
#include "CityThemes.h"
#include <vector>

namespace Eegeo
{
    namespace Traffic
    {
        namespace Themes
        {
            class TrafficThemeModel : protected Eegeo::NonCopyable
            {
            private:
                typedef std::vector<ITrafficThemeModelObserver*> TObservers;

            public:
                void SetTheme(const Eegeo::Resources::CityThemes::CityThemeData& cityThemeData);
                void SetThemeState(const Eegeo::Resources::CityThemes::CityThemeState& cityThemeState);

                void RegisterObserver(ITrafficThemeModelObserver& observer);
                void UnregisterObserver(ITrafficThemeModelObserver& observer);

                const Eegeo::Traffic::Config::TrafficSimulationConfiguration& GetRoadVehiclesConfig() const
                {
                    return m_roadVehiclesConfig;
                }

                const Eegeo::Traffic::Config::TrafficSimulationConfiguration& GetRailVehiclesConfig() const
                {
                    return m_railVehiclesConfig;
                }

                const Eegeo::Traffic::Config::TrafficSimulationConfiguration& GetTramVehiclesConfig() const
                {
                    return m_tramVehiclesConfig;
                }

                const Eegeo::Traffic::Config::TrafficSimulationConfiguration& GetPlaneVehiclesConfig() const
                {
                    return m_planeVehiclesConfig;
                }

                const Eegeo::Resources::CityThemes::CityThemeState& GetCityThemeState() const
                {
                    return m_themeState;
                }

            private:
                void NotifyThemeObservers() const;
                void NotifyThemeStateObservers() const;

                Eegeo::Traffic::Config::TrafficSimulationConfiguration m_roadVehiclesConfig;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration m_railVehiclesConfig;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration m_tramVehiclesConfig;
                Eegeo::Traffic::Config::TrafficSimulationConfiguration m_planeVehiclesConfig;
                Eegeo::Resources::CityThemes::CityThemeState m_themeState;

                TObservers m_observers;
            };
        }
    }
}



