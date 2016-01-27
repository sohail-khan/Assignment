// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

/*! \file
 * Coordinate conversion functions.
 */

#include "Rendering.h"
#include "Camera.h"
#include "Terrain.h"
#include "VectorMath.h"
#include "EarthConstants.h"
#include "LatLongAltitude.h"
#include "MortonKey.h"
#include "CubeMap.h"
#include <math.h>

/*! \namespace Eegeo
 */
namespace Eegeo
{
    namespace Space
    {
        /*! Convert latitude, longitude and altitude to Ecef
         * \param latitudeInRadians The latitude in radians
         * \param longitudeInRadians The longitude in radians
         * \param altitudeInMetres The altitude in metres
         * \return converted Ecef coordinate */
        inline Eegeo::dv3 ConvertLatLongAltitudeToEcef(double latitudeInRadians, double longitudeInRadians, double altitudeInMetres)
        {
            // Note: implementation is in .h due to client request.
            double radius = EarthConstants::Radius + altitudeInMetres;
            
            double x = radius * cos(latitudeInRadians) * cos(longitudeInRadians);
            double y = radius * cos(latitudeInRadians) * sin(longitudeInRadians);
            double z = radius * sin(latitudeInRadians);
            
            return Eegeo::dv3(-y, z, x);
        }

        /*! Convert a LatLongAltitude instance to Ecef
         * \param latLongAltitude The LatLongAltitude to be converted
         * \return converted Ecef coordinate */
        inline dv3 ConvertLatLongAltitudeToEcef(const LatLongAltitude& latLongAltitude)
        {
            return ConvertLatLongAltitudeToEcef(latLongAltitude.GetLatitude(), latLongAltitude.GetLongitude(), latLongAltitude.GetAltitude());
        }

        /*! Convert a LatLongAltitude instance to MortonKey
         * \param latLongAltitude The LatLongAltitude to be converted
         * \param level The cubemap level for which the morton key is to be computed
         * \return the key */
        inline Eegeo::Streaming::MortonKey ConvertLatLongAltitudeToMortonKey(
                const LatLongAltitude& latLongAltitude,
                int level)
        {
            dv3 ecefPosition = ConvertLatLongAltitudeToEcef(latLongAltitude);
            return Eegeo::Space::CubeMap::EcefToKey(ecefPosition, level);
        }

        /*! Convert an Ecef position to LatLongAltitude
         * \param x Ecef x coordinate
         * \param y Ecef y coordinate
         * \param z Ecef z coordinate
         * \return converted LatLongAltitude */
        inline LatLongAltitude ConvertEcefToLatLongAltitude(double x, double y, double z)
        {
            // Note: implementation is in .h due to client request.
            double p = sqrt((z * z) + (-x * -x));
            
            double lat = atan(y / p);
            double lon = atan2(-x, z);
            double alt = (p / cos(lat)) - EarthConstants::Radius;
            
            return LatLongAltitude(lat, lon, alt);
        }

        /*! Convert an Ecef position to LatLongAltitude
         * \param ecefPosition The Ecef position to be converted
         * \return converted LatLongAltitude */
        inline LatLongAltitude ConvertEcefToLatLongAltitude(const dv3& ecefPosition)
        {
            return ConvertEcefToLatLongAltitude(ecefPosition.GetX(), ecefPosition.GetY(), ecefPosition.GetZ());
        }

        /*! Convert a MortonKey centre to ECEF
         * \param key The morton key whose center is to be converted to ECEF
         * \return converted ECEF position */
        inline dv3 ConvertMortonKeyCenterToEcef(const Eegeo::Streaming::MortonKey& key)
        {
            return Space::CubeMap::KeyToECEF(key);
        }

        /*! Convert a lat long altitude to Screen Space pixel coordinates.
         * \param latLongAltitude the lat long altitude to be converted
         * \param renderCamera the render camera
         * \param screenProperties the screen properties
         * \return a 3 component vector. The (x,y) pixel coordinates are returned as the .x and .y components of this vector. The NDC (Normalized Device Coordinate) Z coordinate is returned as the .z coordinate. If the .z component of the returned vector is positive, the projected lat long altitude is in front of the camera. If the .z component is negative, it is behind. */
        v3 ConvertLatLongAltitudeToScreenCoordinates(const LatLongAltitude& latLongAltitude,
                                                     const Eegeo::Camera::RenderCamera& renderCamera,
                                                     const Eegeo::Rendering::ScreenProperties& screenProperties);
        
        /*! Try to convert screen space pixel coordinates into a lat long altitude.
         * \param screenPixelCoordinateX the x pixel coordinate
         * \param screenPixelCoordinateY the y pixel coordinate
         * \param renderCamera render camera
         * \param terrainHeightProvider the terrain height provider
         * \param result reference to a LatLongAltitude instance that, when a conversion is possible, will be filled out with the result. Check the return value to determine whether this result is valid.
         * \return a boolean indicating whether the conversion was successful. If this boolean is true, the result is valid. If it is false, the result should not be used, as the conversion failed. */
        bool TryConvertScreenCoordinatesToLatLongAltitude(int screenPixelCoordinateX,
                                                          int screenPixelCoordinateY,
                                                          const Eegeo::Camera::RenderCamera& renderCamera,
                                                          const Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                                          LatLongAltitude& result);
    }
}
