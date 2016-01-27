// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IRouteThicknessPolicy.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Style
        {
            namespace Thickness
            {
                class IdentityRouteThicknessPolicy : public IRouteThicknessPolicy
                {
                public:
                    virtual float GetThicknessScale(const Fitting::FittedRoute& route) const;
                };
            }
        }
    }
}
