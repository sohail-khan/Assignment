// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

/*! \file
 * Helper functions for working in the ECEF (Earth Centred Earth Fixed) coordinate space.
 */

#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Space
    {
        /*! Calculates the Euclidean distance in metres between two Ecef points.
         * \param ecefPointA The first Ecef point
         * \param ecefPointB The second Ecef point
         * \return The Euclidean distance in metres between the two points. */
        double DistanceInMetresBetweenEcefPoints(const Eegeo::dv3 &ecefPointA, const Eegeo::dv3 &ecefPointB);
    }
}
