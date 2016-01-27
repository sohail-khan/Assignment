//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "IdTypes.h"
#include "LatLongAltitude.h"
#include "StencilMapLayerMask.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            typedef std::string THeatmapId;
            
            class HeatmapModel : private Eegeo::NonCopyable
            {
            public:
                class HeatmapBuilder : private Eegeo::NonCopyable
                {
                public:
                    HeatmapBuilder(
                                   const THeatmapId& id,
                                   const Rendering::TTextureId& heatmapTextureId,
                                   const Rendering::TTextureId& gradientTextureId,
                                   const Space::LatLong& topLeft,
                                   const Space::LatLong& bottomRight)
                    : m_id(id)
                    , m_heatmapTextureId(heatmapTextureId)
                    , m_gradientTextureId(gradientTextureId)
                    , m_topLeft(topLeft)
                    , m_bottomRight(bottomRight)
                    , m_finished(false)
                    , m_alpha(1.0)
                    , m_minValue(0)
                    , m_maxValue(255)
                    , m_stencilMapLayerType(Eegeo::Rendering::StencilMapLayerMask::AllMapLayers)
                    {
                    }

                    HeatmapModel* Build();
                    HeatmapBuilder& MinValue(u8 minValue);
                    HeatmapBuilder& MaxValue(u8 maxValue);
                    HeatmapBuilder& Alpha(float alpha);
                    HeatmapBuilder& Layer(Eegeo::Rendering::StencilMapLayerMask::Type stencilMapLayerType);
                    
                private:
                    const std::string m_id;
                    const Rendering::TTextureId m_heatmapTextureId;
                    const Rendering::TTextureId m_gradientTextureId;
                    const Space::LatLong m_topLeft;
                    const Space::LatLong m_bottomRight;
                    bool m_finished;
                    float m_alpha;
                    u8 m_minValue;
                    u8 m_maxValue;
                    Eegeo::Rendering::StencilMapLayerMask::Type m_stencilMapLayerType;
                };
                
                const THeatmapId& GetId() const { return m_id; }
                const dv3& GetEcefCellCenter() const { return m_ecefCellCenter; }
                
                const Space::LatLong& GetTopLeft() const { return m_topLeft; }
                const Space::LatLong& GetBottomRight() const { return m_bottomRight; }
                
                const Rendering::TTextureId& GetHeatmapTextureId() const { return m_heatmapTextureId; }
                const Rendering::TTextureId& GetGradientTextureId() const { return m_gradientTextureId; }
                
                const u8 GetMinValue() const { return m_minValue; }
                const u8 GetMaxValue() const { return m_maxValue; }
                const float GetAlpha() const { return m_alpha; }
                
                const Eegeo::Rendering::StencilMapLayerMask::Type& GetStencilMapLayerMask() { return m_stencilMapLayerType; }

            private:
                HeatmapModel() : m_topLeft(0.0, 0.0), m_bottomRight(0.0, 0.0) { };
                THeatmapId m_id;
                Rendering::TTextureId m_heatmapTextureId;
                Rendering::TTextureId m_gradientTextureId;
                Space::LatLong m_topLeft;
                Space::LatLong m_bottomRight;
                dv3 m_ecefCellCenter;
                u8 m_minValue;
                u8 m_maxValue;
                float m_alpha;
                Eegeo::Rendering::StencilMapLayerMask::Type m_stencilMapLayerType;
            };
        }
    }
}