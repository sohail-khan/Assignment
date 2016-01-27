// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"
#include "Camera.h"

namespace Eegeo
{
    namespace Location
    {
        namespace DebugPlaceJump
        {
            namespace DebugPlaces
            {
                enum Values
                {
                    Barcelona,
                    Chicago,
                    Edinburgh,
                    Gifu,
                    London,
                    LosAngeles,
                    Melbourne,
                    NewYork,
                    Niigata,
                    Osaka,
                    Phoenix,
                    Portland,
                    SanFrancisco,
                    Seattle,
                    Tokyo,
                    Toronto,
                    Paris,
                    Max
                };
            }
            
            void JumpToPlace(DebugPlaces::Values place, Eegeo::Camera::ICameraJumpController& cameraJumpController);
            Eegeo::Space::LatLong GetLatLongForPlace(DebugPlaces::Values place);
        }
    }
}