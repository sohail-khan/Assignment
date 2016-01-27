// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Space.h"
#include "VectorMath.h"
#include "RouteVertexClassification.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class RouteBuilder : public Eegeo::NonCopyable
        {
            std::vector<RouteVertex> m_verts;
            bool m_started;
            Eegeo::v4 m_color;
            float m_halfWidth;
            float m_speed;
            RouteVertexClassification m_classification;
            double m_distanceFromStartInMetres;
            std::vector<RouteVertex>::iterator m_sectionStart;
            
            bool IsNewSection() const { return m_sectionStart == m_verts.end(); }
            
        public:
            RouteBuilder();
            
            RouteBuilder& Start(const Eegeo::v4& color, float halfWidth, float speed, RouteVertexClassification classification);
            
            RouteBuilder& ChangeClassification(RouteVertexClassification classification);
            
            RouteBuilder& ChangeColor(const Eegeo::v4& color);
            
            RouteBuilder& ChangeHalfWidth(float halfWidth);
            
            RouteBuilder& ChangeSpeed(float speed);
            
            RouteBuilder& ChangeSection();
            
            RouteBuilder& AddPoint(double latDegrees, double lonDegrees, float altMeters);
            
            RouteBuilder& AddPoint(const Space::LatLongAltitude& location);
            
            std::vector<RouteVertex> FinishRoute();
        };
    }
}