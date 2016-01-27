// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "LatLongAltitude.h"
#include "Colors.h"
#include "StencilMapLayerMask.h"
#include "StencilAreaPaletteModel.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            typedef std::string TStencilAreaId;

            class StencilAreaModel : private Eegeo::NonCopyable
            {
            public:
                class StencilAreaBuilder : private Eegeo::NonCopyable
                {
                public:
                    StencilAreaBuilder(
                                    const TStencilAreaId& id,
                                    const StencilAreaPaletteModel& palette,
                                    const std::vector<Space::LatLongAltitude>& exteriorRingVertices,
                                    const Eegeo::Rendering::StencilMapLayerMask::Type stencilMapLayerType,
                                    const float heightInMetres)
                    : m_id(id)
                    , m_palette(palette)
                    , m_exteriorRingVertices(exteriorRingVertices)
                    , m_stencilMapLayerType(stencilMapLayerType)
                    , m_altitudeOffset(0.0f)
                    , m_height(heightInMetres)
                    , m_finished(false)
                    {
                    }
                    
                    StencilAreaBuilder(const TStencilAreaId& id,
                                       const StencilAreaPaletteModel& palette,
                                       const Space::LatLongAltitude& cylinderCentre,
                                       float radiusInMetres,
                                       const Eegeo::Rendering::StencilMapLayerMask::Type stencilMapLayerType,
                                       const float heightInMetres);
                    
                    StencilAreaBuilder& AltitudeOffset(float altitudeOffset);
                    StencilAreaModel* Build();
                    
                    const StencilAreaPaletteModel& GetPaletteModel() const { return m_palette; }
                    
                private:
                    const std::string m_id;
                    const StencilAreaPaletteModel& m_palette;
                    std::vector<Space::LatLongAltitude> m_exteriorRingVertices;
                    const Eegeo::Rendering::StencilMapLayerMask::Type m_stencilMapLayerType;
                    float m_altitudeOffset;
                    float m_height;
                    bool m_finished;
                };
                
                const TStencilAreaId& GetId() const { return m_id; }
                const dv3& GetEcefCellCenter() const { return m_ecefCellCenter; }
                
                const Eegeo::Rendering::StencilMapLayerMask::Type GetStencilMapLayerMask() const { return m_stencilMapLayerType; }
                
                const std::vector<dv3>& GetEcefTriangleVertices() const { return m_ecefTriangleVerts; }
                const std::vector<dv3>& GetExteriorEcefVertices() const { return m_exteriorEcefVerts; }
                const std::vector<Eegeo::Space::LatLongAltitude>& GetExteriorLatLongVertices() const { return m_exteriorRingVertices; }
                
                const float GetHeight() const { return m_height; }
                const StencilAreaPaletteModel& GetPaletteModel() const { return m_palette; }
            private:
                StencilAreaModel(const StencilAreaPaletteModel& palette) : m_palette(palette) { };

                float m_height;
                TStencilAreaId m_id;
                const StencilAreaPaletteModel& m_palette;
                std::vector<Eegeo::Space::LatLongAltitude> m_exteriorRingVertices;
                std::vector<dv3> m_ecefTriangleVerts;
                std::vector<dv3> m_exteriorEcefVerts;
                Eegeo::Rendering::StencilMapLayerMask::Type m_stencilMapLayerType;
                dv3 m_ecefCellCenter;
            };
        }
    }
}