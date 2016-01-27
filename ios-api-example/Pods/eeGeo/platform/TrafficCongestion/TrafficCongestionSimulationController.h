// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TrafficCongestion.h"
#include "ITrafficCongestionService.h"
#include "ITrafficThemeModelObserver.h"
#include "TrafficCongestionStateChangedCallback.h"
#include "Traffic.h"
#include "Navigation.h"
#include "NavigationGraphAddedCallback.h"
#include "NavigationGraphRemovalCallback.h"
#include "MortonKey.h"
#include "VectorMathDecl.h"
#include "Rendering.h"


namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionSimulationController
                : protected Eegeo::NonCopyable,
                  public Eegeo::Traffic::Themes::ITrafficThemeModelObserver
        {
        public:
            TrafficCongestionSimulationController(
                    Eegeo::TrafficCongestion::TrafficCongestionModel& trafficCongestionModel,
                    Eegeo::Traffic::VehicleRenderablesModel& pVehicleRenderablesModel,
                    Eegeo::TrafficCongestion::TrafficCongestionVehicleFactory& pVehicleFactory,
                    const TrafficCongestionConfig& config,
                    Eegeo::Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepository,
                    Eegeo::Traffic::Themes::TrafficThemeModel& trafficThemeModel,
                    Streaming::CameraFrustumStreamingVolume& streamingVolume);

            ~TrafficCongestionSimulationController();

            void Update(float dt, const dv3& cameraEcefLocation);
            void SubmitForRendering(Eegeo::Traffic::VehicleRenderer& vehicleRenderer, const dv3& ecefCameraPosition);
            

            void ToggleEnable()
            {
                m_enabled = !m_enabled;
            }

            bool GetEnabled() { return m_enabled; }

            void OnThemeChanged(const Eegeo::Traffic::Themes::TrafficThemeModel& themeModel);
            void OnThemeStateChanged(const Eegeo::Traffic::Themes::TrafficThemeModel& themeModel);

        private:
            
            
            void HandleNavGraphAdded(const Resources::Roads::Navigation::NavigationGraph& navGraph);
            void HandleNavGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& navGraph);
            void HandleTrafficCongestionModelChanged(const TrafficCongestion::TrafficCongestionModelCell& changed);

            typedef std::map<Eegeo::Streaming::MortonKey, TrafficCongestionSimulationCell*, Streaming::MortonKeyCompare> TMortonKeyToSimulationCellMap;

            Eegeo::TrafficCongestion::TTrafficCongestionStateChangedCallback<TrafficCongestionSimulationController> m_trafficCongestionModelChangedFunctor;
            Eegeo::Resources::Roads::Navigation::TNavigationGraphAddedCallback<TrafficCongestionSimulationController> m_navGraphAddedFunctor;
            Eegeo::Resources::Roads::Navigation::TNavigationGraphRemovalCallback<TrafficCongestionSimulationController> m_navGraphRemovedFunctor;

            Eegeo::TrafficCongestion::TrafficCongestionModel& m_trafficCongestionModel;
            Eegeo::Traffic::VehicleRenderablesModel& m_vehicleRenderablesModel;
            Eegeo::TrafficCongestion::TrafficCongestionVehicleFactory& m_vehicleFactory;

            const TrafficCongestionConfig& m_config;

            TMortonKeyToSimulationCellMap m_keyToSimulationCell;
            bool m_enabled;

            Eegeo::Resources::Roads::Navigation::NavigationGraphRepository& m_navGraphRepository;
            Traffic::Themes::TrafficThemeModel& m_trafficThemeModel;
            Streaming::CameraFrustumStreamingVolume& m_streamingVolume;
        };
    }
}