// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "Navigation.h"
#include "Traffic.h"
#include "Camera.h"
#include <string>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        namespace VehicleDirection
        {
            // This is used so that we know which direction the individual congestion vehicle is travelling in.
            enum DirectionValues
            {
                FromTo = 0,
                ToFrom,
            };
        }

        class TrafficCongestionVehicleModel : Eegeo::NonCopyable
        {
        private:
            VehicleDirection::DirectionValues m_directionOfTravel;
            int m_segmentIndex;
            float m_distanceTravelledAlongCurrentSegment;
            float m_speedMultiplier;
            const std::string& m_modelNodeName;
            std::string m_modelFullName;
            float m_scale;
            bool m_drivesOnRight;

            void SubmitRenderData(
                    dv3 ecefCellOrigin,
                    const std::vector<v3>& vertices,
                    float roadHalfWidth,
                    Traffic::VehicleRenderablesModel& vehicleRenderablesModel,
                    const dv3& cameraEcefLocation);

            int GetNextSegmentId(int segmentVertexCount) const;

        public:
            TrafficCongestionVehicleModel(
                    VehicleDirection::DirectionValues directionOfTravel,
                    int segmentIndex,
                    float distanceTravelled,
                    float speedMultiplier,
                    const std::string& modelNodeName,
                    const std::string& modelNodeSuffix,
                    float scale,
                    bool drivesOnRight
            );

            ~TrafficCongestionVehicleModel();

            void Update(
                    float dt,
                    Eegeo::dv3 ecefCellOrigin,
                    const Eegeo::Resources::Roads::Navigation::NavigationGraphRoad& road,
                    Eegeo::Traffic::VehicleRenderablesModel& vehicleRenderablesModel,
                    const dv3& cameraEcefLocation);

            void SetModelNodeNameSuffix(const std::string& suffix);
            void SetDrivesOnRight(bool drivesOnRight);
        };
    }
}