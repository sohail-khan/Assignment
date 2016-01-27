// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "LatLongAltitude.h"
#include "Colors.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            typedef std::string TGeofenceId;

            class GeofenceModel : private Eegeo::NonCopyable
            {
            public:
                class GeofenceBuilder : private Eegeo::NonCopyable
                {
                public:
                    GeofenceBuilder(
                            const TGeofenceId& id,
                            const v4& geofencePolygonColor,
                            const std::vector<Space::LatLongAltitude>& exteriorRingVertices)
                    : m_id(id)
                    , m_exteriorRingVertices(exteriorRingVertices)
                    , m_polygonColor(geofencePolygonColor)
                    , m_altitudeOffset(0.0f)
                    , m_finished(false)
                    {

                    }

                    GeofenceBuilder& AltitudeOffset(float altitudeOffset);
                    GeofenceBuilder& AddInteriorRing(const std::vector<Space::LatLongAltitude>& interiorRing);
                    GeofenceModel* Build();

                private:
                    const std::string m_id;
                    const std::vector<Space::LatLongAltitude> m_exteriorRingVertices;
                    std::vector<std::vector<Space::LatLongAltitude> > m_interiorRings;
                    const v4 m_polygonColor;
                    float m_altitudeOffset;
                    bool m_finished;
                };

                const TGeofenceId& GetId() const { return m_id; }
                const dv3& GetEcefCellCenter() const { return m_ecefCellCenter; }

                const v4 GetPolygonColor() const { return m_polygonColor; }
                void SetPolygonColor(const v4& polygonColor) { m_polygonColor = polygonColor; }

                const std::vector<dv3>& GetEcefTriangleVertices() const { return m_ecefTriangleVerts; }

            private:
                GeofenceModel() { };
                TGeofenceId m_id;
                std::vector<Eegeo::Space::LatLongAltitude> m_exteriorRingVertices;
                std::vector<std::vector<Eegeo::Space::LatLongAltitude> > m_interiorRings;
                std::vector<dv3> m_ecefTriangleVerts;
                v4 m_polygonColor;
                dv3 m_ecefCellCenter;
            };
        }
    }
}

