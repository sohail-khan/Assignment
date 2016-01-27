// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "VectorMath.h"
#include "RouteVertexClassification.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSample
            {
            public:
                RouteSample()
                {
                    
                }
                
                RouteSample(const dv3& positionEcef,
                                      v3 direction,
                                      v4 color,
                                      float halfWidth,
                                      float speed,
                                      RouteVertexClassification classification,
                                      double routeParam
                                      )
                : m_positionEcef(positionEcef)
                , m_direction(direction)
                , m_color(color)
                , m_halfWidth(halfWidth)
                , m_speed(speed)
                , m_classification(classification)
                , m_routeParam(routeParam)
                {
                    
                }
                
                const dv3& GetPositionEcef() const { return m_positionEcef; }
                const v3& GetDirection() const { return m_direction; }
                const v4& GetColor() const { return m_color; }
                float GetHalfWidth() const { return m_halfWidth; }
                float GetSpeed() const { return m_speed; }
                RouteVertexClassification GetClassification() const { return m_classification; }
                double GetRouteParam() const { return m_routeParam; }
                
                
                static RouteSample FromLocalRouteVertex(const LocalRouteVertex& localRouteVertex, const dv3& cellOriginEcef, const v3& direction);
                static RouteSample FromRouteVertex(const RouteVertex& routeVertex, const dv3& posEcef, const v3& direction);
                
            private:
                dv3 m_positionEcef;
                v3 m_direction;
                v4 m_color;
                float m_halfWidth;
                float m_speed;
                RouteVertexClassification m_classification;
                double m_routeParam;
            };
        }
    }
}
