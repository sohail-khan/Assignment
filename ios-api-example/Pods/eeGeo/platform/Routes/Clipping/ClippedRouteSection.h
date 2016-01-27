// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "MortonKey.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Clipping
        {
            struct ClippedRouteVertex
            {
            private:
                int m_startIndex;
                double m_t;
                
            public:
                ClippedRouteVertex()
                : m_startIndex(-1)
                , m_t(-1.0)
                {
                }
                
                ClippedRouteVertex(const ClippedRouteVertex& src)
                : m_startIndex(src.m_startIndex)
                , m_t(src.m_t)
                {
                }
                
                ClippedRouteVertex(int startIndex, double t)
                : m_startIndex(startIndex)
                , m_t(t)
                { }
                
                
                bool operator==(const ClippedRouteVertex& other) const
                {
                    return m_startIndex == other.m_startIndex &&
                    m_t == other.m_t;
                }
                
                int StartIndex() const { return m_startIndex; }
                int EndIndex() const { return m_startIndex + 1; }
                double ClipParam() const { return m_t; }

                
                Eegeo::Routes::RouteVertex GetInterpolatedRouteVertex(const std::vector<RouteVertex>& routeVertices) const;
                double GetInterpolatedRouteParam(const std::vector<RouteVertex>& routeVertices) const;
                
                bool CanMergeWith(const ClippedRouteVertex& b) const
                {
                    return (EndIndex() == b.StartIndex() &&
                        m_t == 1.0 &&
                        b.m_t == 0.0);
                    
                }
            };
            
            struct ClippedRouteSection
            {
                ClippedRouteSection(const Streaming::MortonKey& key);
                ClippedRouteSection(const ClippedRouteSection& src);
                
                ClippedRouteVertex Start;
                ClippedRouteVertex End;
                Streaming::MortonKey Key;
            };
        }
    }
}
