// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Space
    {
        //! Physical constants for Earth
        class EarthConstants
        {
        public:
            //! Radius of spherical Earth (metres)
            static const double Radius;
            
            //! Radius^2 (m^2)
            static const double RadiusSquared;
            
            //! Diameter of spherical Earth (metres)
            static const double Diameter;
            
            //! Diameter^2 (m^2)
            static const double DiameterSquared;
            
            //! Edge length of cube tightly bounding the Earth sphere (metres)
            static const double CubeSideLength;
            
            //! Half edge length of cube tightly bounding the Earth sphere (metres)
            static const double CubeSideLengthHalf;
            
            //! CubeSideLengthHalf^2
            static const double CubeSideLengthHalfSquared;
            
            //! For a face on Earth bounding cube, the distance from centre of the face to a vertex on that face (metres)
            static const double CubeSideDiagonalLengthHalf;
            
            //! Altitude above sea level of highest point on Earth's crust (metres)
            static const double MaxElevation;
        };
    }
}
