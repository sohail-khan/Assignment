// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TrafficCongestion.h"
#include "VectorMathDecl.h"
#include "Navigation.h"
#include "Traffic.h"
#include "Camera.h"

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionVehicles : Eegeo::NonCopyable
        {
        public:
            typedef std::vector<Eegeo::TrafficCongestion::TrafficCongestionVehicleModel*> TVectorVehiclePtrs;

        private:
            TVectorVehiclePtrs m_vehicles;

        public:
            TrafficCongestionVehicles();
            ~TrafficCongestionVehicles();

            size_t VehicleCount() const;

            void AddVehicle(Eegeo::TrafficCongestion::TrafficCongestionVehicleModel* model);
            bool RemoveVehicle(Eegeo::TrafficCongestion::TrafficCongestionVehicleModel* model);

            void Update(
                    float dt,
                    Eegeo::dv3 ecefCellOrigin,
                    const Eegeo::Resources::Roads::Navigation::NavigationGraphRoad& road,
                    Traffic::VehicleRenderablesModel& vehicleRenderablesModel,
                    const dv3& cameraEcefLocation
            );

            void HandleStateChanged(const TrafficCongestionStateData& state);
            void HandleThemeChanged(const TrafficCongestionThemeData& data);
        };
    }
}