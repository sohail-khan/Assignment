// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

namespace Eegeo
{
    namespace Traffic
    {
        namespace Config
        {
             /*!
             * \brief Used to control the dynamic speed of vehicles as a function of camera altitude
             *
             *  When the camera is between the min and max altitudes, the speed of vehicles will be varied by
             *  a coefficient that is a blend between min and max vehicle speed multipliers.
             */
            struct TrafficSimulationAltitudeSpeedConfiguration
            {
                /*
                 * \brief Default values. Produces traffic that has a constant speed regardless of altitude.
                 */
                static TrafficSimulationAltitudeSpeedConfiguration CreateDefault();

                TrafficSimulationAltitudeSpeedConfiguration(
                        float vehicleSpeedMultiplierMin,
                        float vehicleSpeedMultiplierMax,
                        float vehicleSpeedAltitudeMin,
                        float vehicleSpeedAltitudeMax);

                //! speed multiplier that is applied when the camera is at an altitude that is equal to or less than VehicleSpeedAltitudeMin
                float VehicleSpeedMultiplierMin;

                //! speed multiplier that is applied when the camera is at an altitude that is equal to or greater than VehicleSpeedAltitudeMax
                float VehicleSpeedMultiplierMax;

                //! the camera altitude in metres at which the VehicleSpeedMultiplierMin is used.
                float VehicleSpeedAltitudeMin;

                //! the camera altitude in metres at which the VehicleSpeedMultiplierMax is used
                float VehicleSpeedAltitudeMax;
            };
        }
    }
}
