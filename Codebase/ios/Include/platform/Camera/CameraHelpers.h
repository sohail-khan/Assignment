// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Camera.h"
#include "Space.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace CameraHelpers
        {
            /*! \brief calculate a coordinate frame for positioning and orienting a camera to look towards an interest point
             *  \param interestPointEcef location of camera interest point in ECEF coordinates
             *  \param interestBasisFoward direction vector defining the azimuth orientation of the camera direction
             *  \param pitchRadians elevation angle in radians between the Earth tangent plane at interest point and the camera view direction
             *  \param distanceCameraToInterest desired distance in metres from camera origin to interest point
             *  \param out_cameraLocation [out] Camera origin in ECEF coordinates
             *  \param out_cameraDirection [out] Camera view direction in ECEF space
             *  \param out_cameraUp [out] Camera up direction in ECEF space
             */
            void CalculateLookAt(
                const dv3& interestPointEcef,
                const v3& interestBasisFoward,
                float pitchRadians,
                float distanceCameraToInterest,
                dv3& out_cameraLocation,
                v3& out_cameraDirection,
                v3& out_cameraUp);
            
            /*! \brief create a rotation matrix suitable for orienting a camera
             *  \param viewDirection view direction of camera in ECEF space
             *  \param upAxis up direction of camera in ECEF space.
             *  \param out_cameraOrientation [out] resultant camera model-to-world rotation matrix
             */
            void CalculateCameraOrientation(const v3& viewDirection, const v3& upAxis, m33& out_cameraOrientation);
            
            /*! \brief calculate an absolute bearing in radians from an ECEF point and heading direction
             *  \param pointEcef point in ECEF coordinates
             *  \param headingDirection direction vector in ECEF space defining an orientation at pointECEF. 
             *  The heading is projected onto the Earth tangent plane at pointECEF. The bearing angle is the angle between 
             *  the resultant direction, and a vector on the tangent plane pointing towards the North Pole
             *  \return absolute bearing angle in radians, with 0=North, and increasing positive angles rotating clockwise through compass directions (North -> East -> South -> West)
             */
            float GetAbsoluteBearingRadians(const dv3& pointEcef, const v3& headingDirection);
            
            /*! \brief create a ray in ECEF coordinates passing through camera origin and a screen at pixel coordinates
             *  \param renderCamera camera object defining world, view and projection camera transforms
             *  \param screenPixelX horizonal screen coordinate in pixels
             *  \param screenPixelY vertical screen coordinate in pixels
             *  \param out_rayDirection [out] resultant ray direction. The ray origin is renderCamera.GetEcefLocation()
             */
            void GetScreenPickRay(const RenderCamera& renderCamera, float screenPixelX, float screenPixelY, dv3& out_rayDirection);
            
            /*! \brief Attempt to find the intersection point of a sphere centred at ECEF origin, with a ray from camera origin and passing through a point defined in screenspace
             *  \param renderCamera camera object defining world, view and projection camera transforms
             *  \param screenPixelX horizonal screen coordinate in pixels
             *  \param screenPixelY vertical screen coordinate in pixels
             *  \param sphereRadius radius of sphere in metres, typically Eegeo::Space::EarthConstants::Radius for the Earth
             *  \param out_ecefIntersectionPoint [out] intersection point between ray and sphere, in ECEF space
             *  \return true if ray and sphere intersect, false otherwise 
             */
            bool TryGetScreenPickIntersectionWithEarthCentredSphere(const RenderCamera& renderCamera, float screenPixelX, float screenPixelY, double sphereRadius, dv3& out_ecefIntersectionPoint);
            
            /*! \brief Create an Ecef tangent space coordinate frame from a point and a bearing angle
             *  \param pointEcef point in ECEF coordinates
             *  \param absoluteHeadingDegrees bearing angle in degrees, clockwise from North
             *  \param out_basis [out] resultant EcefTangentBasis located at pointEcef, and oriented to that out_basis.GetForward() points in the direction specified by bearing angle
             */
            void EcefTangentBasisFromPointAndHeading(const dv3& pointEcef, float absoluteHeadingDegrees, Space::EcefTangentBasis& out_basis);
            
            /*! \brief calculate the single-precision vector to translate from cameraOrigin to pointEcef
             *  \param pointEcef point in ECEF coordinates
             *  \param cameraOrigin camera origin location in ECEF coordinates
             *  \return (pointEcef - cameraOrigin) as a single-precision vector
             */
            v3 CameraRelativePoint(const dv3& pointEcef, const dv3& cameraOrigin);
            
            /*! \brief calculate a recommended near and far clipping plane distance based on camera altitude and height of terrain to ensure everything is within the frustum
             * \param The altitude in meters of the camera
             * \param The approximate altitude of the highest terrain in the scene
             * \param The difference between the highest and lowest terrain in the scene
             * \param Altitude at which the method for scaling the near/far bounds changes (Default 15000m)
             * \param out_nearDistance [out] resultant recommended Near value based on the provided altitudes
             * \param out_farDistance [out] resultant reecommended Far value based on the provided altitudes
             */
            void GetAltitudeInterpolatedNearFar(float absoluteCameraAltitude, float approxTerrainAltitude, float approxTerrainAltitudeDelta, const double scalingFunctionAltitudeThreshold, float& out_nearDistance, float& out_farDistance);
        }
    }
}