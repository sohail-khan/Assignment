// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Style
        {
            class RouteStyle
            {
            public:
                enum DebugStyle
                {
                    DebugStyleNone = 0,
                    DebugStyleSegmented,
                    DebugStyleSegmentedWithDirection,
                    DebugStyleCellColours,
                    DebugStyleMax
                };

                DebugStyle GetDebugStyle() const;
                const Thickness::IRouteThicknessPolicy& GetThicknessPolicy() const;
                
                RouteStyle(const Thickness::IRouteThicknessPolicy* routeThicknessPolicy, DebugStyle debugStyle);
                
            private:
                DebugStyle m_debugStyle;
                const Thickness::IRouteThicknessPolicy* m_thicknessPolicy;
            };
        }
    }
}
