// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            struct CurveData
            {
                v2 originalPrev;
                v2 originalCurve;
                v2 originalNext;

                // or just store the 'length' values of these points projected onto ba, bc
                v2 intersectionInner;
                v2 intersectionOuter;
                v2 intersectionPrevOuter;
                v2 intersectionNextOuter;

                u16 firstIndex;
                u16 lastIndexExclusive;

                bool swapped;
            };


            void CalculateVertexIndicesForCurveInsertion(
                    const std::vector<RouteVert>& verts,
                    float curveAngleThresholdDot,
                    std::vector<size_t>& outIndices);

            void CalculateInteriorCurveVerticesAndAddToCollection(
                    const RouteVert& inputA,
                    const RouteVert& inputB,
                    const RouteVert& inputC,
                    int bezierSegmentCount,
                    std::vector<CurveData>& addToCurveDatas,
                    std::vector<RouteVert>& addToVertices,
                    std::vector<u16>& addToIndices);

            void CorrectVerticesThatIntersectWithCurves(
                    const std::vector<CurveData>& curveDatas,
                    std::vector<RouteVert>& verts);
        }
    }
}


