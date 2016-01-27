// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Traffic
    {
        namespace Config
        {
            struct PlaneSimulationConfig
            {
                float MinSpawnAltitudeAboveTerrain;
                float MinSpawnAltitudeDiffBelowCamera;
                float MaxSecondsOutsideViewBeforeDespawn;
                float PlaneCullingSphereRadius;
                float SecondsBetweenTerrainQueries;
            };
        }
    }
}
