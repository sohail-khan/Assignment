// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "VectorMath.h"
#include "Bounds.h"
#include "Interiors.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsFloorModel
            {
            public:
                InteriorsFloorModel(const std::string& floorName,
                                    const std::string& floorReadableName,
                                    int floorNumber,
                                    const dv3& cellOrigin,
                                    const Geometry::Bounds3D& localEcefBounds,
                                    const Geometry::Bounds3D& tangentSpaceBounds);
                
                std::string GetFloorName() const;
                
                std::string GetReadableFloorName() const;
                
                int GetFloorNumber() const;
                
                void SetHighlightOffset(float offset);
                
                const float GetHighlightOffset() const { return m_highlightOffset; }
                
                const Geometry::Bounds3D& GetLocalEcefBounds() const { return m_localEcefBounds; }
                const Geometry::Bounds3D& GetTangentSpaceBounds() const { return m_tangentSpaceBounds; }
                
                const dv3& GetFloorBoundsCenterEcef() const;
            private:
                
                std::string m_floorName;
                std::string m_floorReadableName;
                dv3 m_floorBoundsCenterEcef;
                Geometry::Bounds3D m_localEcefBounds;
                Geometry::Bounds3D m_tangentSpaceBounds;
                float m_highlightOffset;
                int m_floorNumber;
            };
        }
    }
}