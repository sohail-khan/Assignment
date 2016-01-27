//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once
#include "LatLongAltitude.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace RouteType
        {
            enum Values
            {
                Any,
                CarOnly
            };
        }
        class IRouteCreator
        {
        public:
            virtual ~IRouteCreator(){};
            
            virtual void CreateRoute(const Space::LatLongAltitude& start, const Space::LatLongAltitude& end) = 0;
            virtual void CreateRoute(const Space::LatLongAltitude& start, const Space::LatLongAltitude& end, RouteType::Values routeType) = 0;
            virtual void ToggleFitting() = 0;
        };
    }
}
