// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "CityThemes.h"
#include "ICityThemeChangedObserver.h"
#include "ICityThemeStateObserver.h"
#include "Traffic.h"
#include "AsyncModels.h"

#include <set>
#include <map>
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        namespace Themes
        {
            class TrafficThemeController
                : protected Eegeo::NonCopyable
                , public Eegeo::Resources::CityThemes::ICityThemeChangedObserver
                , Eegeo::Resources::CityThemes::ICityThemeStateObserver
            {
            public:
                TrafficThemeController(
                        Io::AsyncModels::HttpAsyncModelLoader& asyncModelLoader,
                        TrafficThemeModel& trafficThemeModel,
                        Traffic::VehicleModelNodeRepository& vehicleModelNodeRepository,
                        Eegeo::Resources::CityThemes::ICityThemeChangedObservable& cityThemeChangedObservable,
                        Eegeo::Resources::CityThemes::ICityThemeStateObservable& themeStateObservable);

                ~TrafficThemeController();

                void OnThemeRequested(const Eegeo::Resources::CityThemes::CityThemeData& newTheme);
                void OnThemeChanged(const Eegeo::Resources::CityThemes::CityThemeData& newTheme);
                void OnThemeStateChanged(const Eegeo::Resources::CityThemes::CityThemeState& state);

            private:
                void ClearLoadedModels();

                void LoadModelsFromConfig(
                        const Config::TrafficSimulationConfiguration* config,
                        std::set<std::string> nodeSuffixes);

                void GatherVehicleSuffixesForStates(
                        std::map<std::string,Resources::CityThemes::CityThemeState> themeStates,
                        std::set<std::string> &suffixes);

                void LoadModelsFromTheme(const Eegeo::Resources::CityThemes::CityThemeData& theme);

                typedef std::vector<Io::AsyncModels::IAsyncModel*> TAsyncModels;
                TAsyncModels m_asyncModels;
                Io::AsyncModels::HttpAsyncModelLoader& m_asyncModelLoader;
                TrafficThemeModel& m_trafficThemeModel;
                Traffic::VehicleModelNodeRepository& m_vehicleModelNodeRepository;
                Eegeo::Resources::CityThemes::ICityThemeChangedObservable& m_cityThemeChangedObservable;
                Eegeo::Resources::CityThemes::ICityThemeStateObservable& m_themeStateObservable;
            };
        }
    }
}
