// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Space
    {
        class LatLong
        {
        public:
            LatLong(double latitudeInRadians, double longitudeInRadians)
                    : m_latitude(latitudeInRadians)
                    , m_longitude(longitudeInRadians)
            {

            }

            inline double GetLatitude() const { return m_latitude; }
            inline double GetLongitude() const { return m_longitude; }

            inline void SetLatitude(double latitude) { m_latitude = latitude; }
            inline void SetLongitude(double longitude) { m_longitude = longitude; }

            inline double GetLatitudeInDegrees() const { return Eegeo::Math::Rad2Deg(m_latitude); }
            inline double GetLongitudeInDegrees() const { return Eegeo::Math::Rad2Deg(m_longitude); }

            Eegeo::dv3 ToECEF() const;
            double BearingToInRadians(double latitude, double longitude) const;
            double BearingToNorthPole() const;

            static LatLong FromECEF(const Eegeo::dv3& world);
            static LatLong FromDegrees(double latitudeInDegrees, double longitudeInDegrees);
            static LatLong FromRadians(double latitudeInRadians, double longitudeInRadians);

        private:
            double m_latitude;
            double m_longitude;
        };

        class LatLongAltitude 
        {
        public:
            LatLongAltitude(double latitudeInRadians, double longitudeInRadians, double altitudeInMetres)
                    : m_latLong(latitudeInRadians, longitudeInRadians)
                    , m_altitude(altitudeInMetres)
            {

            }

            inline LatLong GetLatLong() const { return m_latLong; }
            
            inline double GetAltitude() const { return m_altitude; }
            inline void SetAltitude(double altitude) { m_altitude = altitude; }
            
            inline double GetLatitude() const { return m_latLong.GetLatitude(); }
            inline double GetLongitude() const { return m_latLong.GetLongitude(); }

            inline void SetLatitude(double latitude) { m_latLong.SetLatitude(latitude); }
            inline void SetLongitude(double longitude) { m_latLong.SetLongitude(longitude); }

            inline double GetLatitudeInDegrees() const { return m_latLong.GetLatitudeInDegrees(); }
            inline double GetLongitudeInDegrees() const { return m_latLong.GetLongitudeInDegrees(); }

            Eegeo::dv3 ToECEF() const;
            double BearingToInRadians(double latitude, double longitude) const;
            double BearingToNorthPole() const;
            
            static LatLongAltitude FromDegrees(double latitudeInDegrees, double longitudeInDegrees, double altitudeInMetres);
            static LatLongAltitude FromRadians(double latitudeInRadians, double longitudeInRadians, double altitudeInMetres);
            static LatLongAltitude FromECEF(const Eegeo::dv3& world);
            static LatLongAltitude Lerp(const LatLongAltitude& from, const LatLongAltitude& to, float t);

        private:
            LatLong m_latLong;
            double m_altitude;
        };
        
        inline double SignedArea(const std::vector<Eegeo::Space::LatLongAltitude>& points)
        {
            double a = 0.0;
            double b = 0.0;
            for (int i=0; i<points.size()-1; ++i)
            {
                a += points.at(i).GetLongitude() * points.at(i+1).GetLatitude();
                b += points.at(i).GetLatitude() * points.at(i+1).GetLongitude();
            }
            return (a-b)/2.0;
        }
    }
}
