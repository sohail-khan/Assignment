// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITrafficThemeModelObserver.h"
#include "Navigation.h"
#include "Streaming.h"
#include "Terrain.h"
#include "Rendering.h"
#include "Camera.h"
#include "TrafficSimulationAltitudeSpeedConfiguration.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        class TrafficSimulationController : protected Eegeo::NonCopyable, public Themes::ITrafficThemeModelObserver
        {
        public:
            
            TrafficSimulationController(
                    TrafficSimulationFactory& trafficSimFactory,
                    Resources::Roads::Navigation::NavigationGraphRepository& roadNavGraphRepository,
                    Resources::Roads::Navigation::NavigationGraphRepository& railNavGraphRepository,
                    Resources::Roads::Navigation::NavigationGraphRepository& tramNavGraphRepository,
                    Eegeo::Streaming::CameraFrustumStreamingVolume& streamingVolume,
                    Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                    Eegeo::Traffic::Themes::TrafficThemeModel& trafficThemeModel,
                    const Config::PlaneSimulationConfig& planeSimulationConfig);

            ~TrafficSimulationController();
            
            bool Enabled() const
            {
                return m_enabled;
            }

            void SetEnabled(bool enabled);
            void OnThemeChanged(const Themes::TrafficThemeModel& themeModel);
            void OnThemeStateChanged(const Themes::TrafficThemeModel& themeModel);
            void Update(float dt, const Camera::RenderCamera& renderCamera, const dv3& ecefInterestPoint);
            void SubmitForRendering(Eegeo::Traffic::VehicleRenderer& m_pTrafficVehicleRenderer, const dv3& ecefCameraPosition);

            void SetAltitudeSpeedConfiguration(Eegeo::Traffic::Config::TrafficSimulationAltitudeSpeedConfiguration config);
            
            Eegeo::Traffic::PlaneSimulation& GetPlaneSimulation() const { return *m_pPlaneSimulation; }
            
        private:
            void ApplyVehicleSuffixChange(const std::string &suffix);
           
            Eegeo::Traffic::Config::TrafficSimulationAltitudeSpeedConfiguration m_altitudeSpeedConfig;

            TrafficSimulationFactory& m_trafficSimFactory;
            Eegeo::Traffic::VehiclesOnNavigationGraphSimulation* m_pRoadTrafficSimulation;
            Eegeo::Traffic::VehiclesOnNavigationGraphSimulation* m_pRailTrafficSimulation;
            Eegeo::Traffic::VehiclesOnNavigationGraphSimulation* m_pTramTrafficSimulation;
            Eegeo::Traffic::PlaneSimulation *m_pPlaneSimulation;
            bool m_enabled;

            Resources::Roads::Navigation::NavigationGraphRepository& m_roadNavGraphRepository;
            Resources::Roads::Navigation::NavigationGraphRepository& m_railNavGraphRepository;
            Resources::Roads::Navigation::NavigationGraphRepository& m_tramNavGraphRepository;
            
            Config::TrafficSimulationConfiguration* m_pDefaultTrafficConfig;
            
            Eegeo::Streaming::CameraFrustumStreamingVolume& m_streamingVolume;
            Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            Eegeo::Traffic::Themes::TrafficThemeModel& m_trafficThemeModel;
        };
    }
}
