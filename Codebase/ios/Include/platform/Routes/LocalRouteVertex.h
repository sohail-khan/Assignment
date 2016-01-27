// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "Routes.h"
#include "RouteVertexClassification.h"

namespace Eegeo
{
    namespace Routes
    {
        class LocalRouteVertex
        {
            Eegeo::v3 m_localPosition;
            Eegeo::v4 m_color;
            float m_halfWidth;
            float m_speed;
            RouteVertexClassification m_classification;
            bool m_isFitted;
            bool m_isInCentralCell;
            double m_routeParam;
            const Fitting::NavGraphRoadFittingInfo* m_roadFittingInfo;
            
        public:
        
            
            
            LocalRouteVertex()
            : m_localPosition(Eegeo::v3::Zero())
            , m_color(Eegeo::v4::Zero())
            , m_halfWidth(0.f)
            , m_speed(0.f)
            , m_classification(Pedestrian)
            , m_isFitted(false)
            , m_isInCentralCell(false)
            , m_routeParam(0.0)
            , m_roadFittingInfo(NULL)
            {
                
            }
            
            LocalRouteVertex(const Eegeo::v3& localPosition,
                             const Eegeo::v4& color,
                             float halfWidth,
                             float speed,
                             RouteVertexClassification classification,
                             bool isFitted,
                             bool isInCentralCell,
                             double routeParam,
                             const Fitting::NavGraphRoadFittingInfo* roadFittingInfo)
            :m_localPosition(localPosition)
            ,m_color(color)
            ,m_halfWidth(halfWidth)
            ,m_speed(speed)
            ,m_classification(classification)
            , m_isFitted(isFitted)
            , m_isInCentralCell(isInCentralCell)
            , m_routeParam(routeParam)
            , m_roadFittingInfo(roadFittingInfo)
            {
                
            }
            
            const Eegeo::v3& GetPosition() const { return m_localPosition; }
            const Eegeo::v4& GetColor() const { return m_color; }
            float GetHalfWidth() const { return m_halfWidth; }
            float GetSpeed() const { return m_speed; }
            RouteVertexClassification GetRouteVertexClassification() const { return m_classification; }
            bool IsFitted() const { return m_isFitted; }
            bool IsInCentralCell() const { return m_isInCentralCell; }
            double GetRouteParam() const { return m_routeParam; }
            const Fitting::NavGraphRoadFittingInfo* GetRoadFittingInfo() const { return m_roadFittingInfo; }
        };
    }
}
