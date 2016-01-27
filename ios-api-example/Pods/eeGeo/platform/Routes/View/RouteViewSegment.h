// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "LocalRouteVertex.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewSegment
            {
            private:
                LocalRouteVertex m_start;
                LocalRouteVertex m_end;
                v3 m_direction;
                v3 m_startRight;
                v3 m_endRight;
            public:
                RouteViewSegment(const LocalRouteVertex& start,
                                 const LocalRouteVertex& end,
                                 const v3& direction)
                : m_start(start)
                , m_end(end)
                , m_direction(direction)
                {
                    
                }
                
                const LocalRouteVertex& GetStart() const { return m_start; }
                const LocalRouteVertex& GetEnd() const { return m_end; }
                const v3& GetDirection() const { return m_direction; }
                const v3& GetStartRight() const { return m_startRight; }
                const v3& GetEndRight() const { return m_endRight; }
                void SetStartRightVector(const v3& startRight) { m_startRight = startRight; }
                void SetEndRightVector(const v3& endRight) { m_endRight = endRight; }
                void SetDirection(const v3& direction) { m_direction = direction; }
            };
        }
    }
}
