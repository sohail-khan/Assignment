// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IRouteThicknessPolicy.h"
#include "Camera.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Style
        {
            namespace Thickness
            {
                class LinearAltitudeBasedRouteThicknessPolicy : public IRouteThicknessPolicy
                {
                    float m_altitude;
                    float m_scaleFactor;
                    
                public:
                    LinearAltitudeBasedRouteThicknessPolicy();
                    
                    void SetScaleFactor(float scaleFactor);
                    
                    void SetAltitude(float altitudeMetres);
                    
                    virtual float GetThicknessScale(const Fitting::FittedRoute& route) const;
                };
            }
        }
    }
}
