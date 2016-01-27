// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LatLongAltitude.h"
#include "VectorMath.h"
#include "RouteVertexClassification.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        class RouteVertex
        {
            Space::LatLongAltitude m_location;
            Eegeo::v4 m_color;
            float m_halfWidth;
            float m_speed;
            RouteVertexClassification m_classification;
            double m_distanceFromStartInMetres;
            double m_routeParam;
            
        public:
            RouteVertex(const Space::LatLongAltitude& location,
                        const Eegeo::v4& color,
                        float halfWidth,
                        float speed,
                        RouteVertexClassification classification,
                        double distanceFromStartInMetres,
                        double routeParam)
            :m_location(location)
            ,m_color(color)
            ,m_halfWidth(halfWidth)
            ,m_speed(speed)
            ,m_classification(classification)
            ,m_distanceFromStartInMetres(distanceFromStartInMetres)
            ,m_routeParam(routeParam)
            {
            }
            
            const Space::LatLongAltitude& GetLocation() const { return m_location; }
            const Eegeo::v4& GetColor() const { return m_color; }
            float GetHalfWidth() const { return m_halfWidth; }
            float GetSpeed() const { return m_speed; }
            RouteVertexClassification GetRouteVertexClassification() const { return m_classification; }
            double GetDistanceFromStartInMetres() const { return m_distanceFromStartInMetres; }
            double GetRouteParam() const { return m_routeParam; }
            
            Eegeo::dv3 ToECEF() const { return m_location.ToECEF(); }
            
            void FinaliseRouteParam(double routeLength);
            
            static RouteVertex Lerp(const RouteVertex& v0, const RouteVertex& v1, double t);
        };
        

    }
}
