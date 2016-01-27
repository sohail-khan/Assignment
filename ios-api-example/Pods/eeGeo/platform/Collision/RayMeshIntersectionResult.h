// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"

namespace Eegeo
{
    namespace Collision
    {
        struct RayMeshIntersectionResult
        {
            RayMeshIntersectionResult(int triListOffset, double intersectionParam)
            : m_triListOffset(triListOffset)
            , m_intersectionParam(intersectionParam)
            {}
            
            bool Intersects() const { return m_triListOffset >= 0; }
            int TriListOffset() const { return m_triListOffset; }
            double IntersectionParam() const { return m_intersectionParam; }
        private:
            int m_triListOffset;
            double m_intersectionParam;
        };
    }
}