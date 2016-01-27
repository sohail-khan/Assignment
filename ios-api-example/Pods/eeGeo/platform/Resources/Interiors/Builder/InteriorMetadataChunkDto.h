// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Bounds.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct InteriorInstanceChunkDto
                {
                    InteriorInstanceChunkDto()
                    {

                    }

                    InteriorInstanceChunkDto(const std::vector<int>& _meshCountPerInstanceSource)
                        : m_meshCountPerInstanceSource(_meshCountPerInstanceSource)
                    {

                    }

                    const std::vector<int>& GetMeshCountPerInstanceSource() const {
                        return m_meshCountPerInstanceSource;
                    }

                private:

                    std::vector<int> m_meshCountPerInstanceSource;
                };

                struct InteriorMetadataChunkDto
                {
                    InteriorMetadataChunkDto()
                    : m_bounds(Geometry::Bounds3D::Empty())
                    , m_tangentSpacebounds(Geometry::Bounds3D::Empty())
                    {
                        
                    }
                    
                    InteriorMetadataChunkDto(const Geometry::Bounds3D& bounds, const Geometry::Bounds3D& tangentSpacebounds)
                    : m_bounds(bounds)
                    , m_tangentSpacebounds(tangentSpacebounds)
                    {
                        
                    }
                    
                    Geometry::Bounds3D Bounds() const { return m_bounds; }
                    Geometry::Bounds3D TangentSpacebounds() const { return m_tangentSpacebounds; }
                private:
                    Geometry::Bounds3D m_bounds;
                    Geometry::Bounds3D m_tangentSpacebounds;
                };
            }
        }
    }
}