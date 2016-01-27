// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "MortonKey.h"
#include "ClippedRouteSection.h"
#include "MathFunc.h"
#include "VectorMath.h"

#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Clipping
        {
            struct RouteClippedLineSegment
            {
                RouteClippedLineSegment(const Streaming::MortonKey& key,
                                        int startVertexIndex,
                                        double t0,
                                        double t1)
                : m_key(key)
                , m_startVertexIndex(startVertexIndex)
                , m_t0(t0)
                , m_t1(t1)
                {
                }
                
                inline int StartVertexIndex() const { return m_startVertexIndex; }
                inline double LerpParam(double s) const { return Math::Lerp(m_t0, m_t1, s); }
                inline const Streaming::MortonKey& Key() const { return m_key; }
                
                inline dv3 Point0(const std::vector<dv3>& routePointsEcef) const
                {
                    return dv3::Lerp(routePointsEcef.at(m_startVertexIndex), routePointsEcef.at(m_startVertexIndex + 1), m_t0);
                }
                
                inline dv3 Point1(const std::vector<dv3>& routePointsEcef) const
                {
                    return dv3::Lerp(routePointsEcef.at(m_startVertexIndex), routePointsEcef.at(m_startVertexIndex + 1), m_t1);
                }
                
                inline ClippedRouteSection ToClippedRouteSection() const
                {
                    ClippedRouteSection section(m_key);
                    section.Start = ClippedRouteVertex(m_startVertexIndex, m_t0);
                    section.End = ClippedRouteVertex(m_startVertexIndex, m_t1);
                    return section;
                }
            private:
                Streaming::MortonKey m_key;
                int m_startVertexIndex;
                double m_t0;
                double m_t1;
            };
        }
    }
}