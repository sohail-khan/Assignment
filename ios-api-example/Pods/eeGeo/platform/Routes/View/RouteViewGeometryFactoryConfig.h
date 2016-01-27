// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MathFunc.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            struct RouteViewGeometryFactoryConfig
            {
                bool enabledCurves;
                float roadFilterTolerance;
                float curveAngleThresholdInDegrees;
                int bezierSegmentCount;

                // Note: I mean the canonical meaning of level, not the C++ impl
                int coarsestKeyLevelToGenerateCurvedGeometry;
                
                inline float CurveAngleThresholdDot() const
                {
                    return Math::Cos(curveAngleThresholdInDegrees);
                }
                
                RouteViewGeometryFactoryConfig()
                : enabledCurves(true)
                , roadFilterTolerance(0.f)
                , curveAngleThresholdInDegrees(0.f)
                , bezierSegmentCount(5)
                , coarsestKeyLevelToGenerateCurvedGeometry(11)
                {}
            
                static RouteViewGeometryFactoryConfig DefaultConfig()
                {
                    RouteViewGeometryFactoryConfig config;
                    config.enabledCurves = true;
                    config.roadFilterTolerance = 2.f;
                    config.curveAngleThresholdInDegrees = 45.f;
                    config.bezierSegmentCount = 5;
                    config.coarsestKeyLevelToGenerateCurvedGeometry = 11;
                    
                    return config;
                }
            };
        }
    }
}