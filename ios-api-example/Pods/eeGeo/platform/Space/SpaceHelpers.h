// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"
#include "VectorMathDecl.h"
#include "MortonKey.h"

#include <vector>

namespace Eegeo
{
    namespace Space
    {
        //! Helper functions for coordinate conversion operations
        namespace SpaceHelpers
        {
            //! Calculate the altitude above sea level, in metres, of an ECEF point
            //! \param pointEcef point in ECEF coordinates
            //! \return height above sea level in metres
            double GetAltitude(const dv3& pointEcef);
            
            v3 LocalEcefToZeroAltitudeLocalEcef(const v3& localEcef, const dv3& ecefCellOrigin);
            
            double GreatCircleDistance(const LatLong& a, const LatLong& b, double sphereRadius);
            
            void LatLongBounds(const LatLong& p, double greatCircleRadius, double sphereRadius, LatLong& out_min, LatLong& out_max);
            
            bool LatLongBoundsIntersect(const Space::LatLong& southWestA, const Space::LatLong& northEastA,
                                        const Space::LatLong& southWestB, const Space::LatLong& northEastB);
            
            std::vector<Streaming::MortonKey> CalculateMortonKeysIntersectingBounds(const int keyDepth, const Space::LatLong& southWestLatLong, const Space::LatLong& northEastLatLong);
        }
    }
}