// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Style
        {
            namespace Thickness
            {
                class IRouteThicknessPolicy
                {
                public:
                    virtual ~IRouteThicknessPolicy() { }
                    
                    virtual float GetThicknessScale(const Fitting::FittedRoute& route) const = 0 ;
                };
            }
        }
    }
}
