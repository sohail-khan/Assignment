// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            namespace Camera
            {
                struct RouteSimulationGlobeCameraControllerConfig
                {
                    float FilterAlpha;
                    float FilterBeta;
                    float FixedTimeStep;
                    float MinDistanceToTerrain;
                    float TerrainCollisionRecoveryDelay;
                    float TerrainCollisionRecoveryTimeConstant;
                    
                    static RouteSimulationGlobeCameraControllerConfig CreateDefault();
                };
            }
        }
    }
}
