// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Bounds.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct InteriorFloorChunkDto
                {
                    InteriorFloorChunkDto(int floorNumber,
                                           const Geometry::Bounds3D& bounds,
                                           const Geometry::Bounds3D& tangentSpacebounds,
                                           const std::vector<std::vector<m44> >& instanceTransforms,
                                           const std::vector<std::string>& tags,
                                           const std::vector<int>& tagIndices,
                                           const std::vector<std::string>& instanceIds,
                                           const std::vector<int>& instanceIndices)
                    : m_floorNumber(floorNumber)
                    , m_bounds(bounds)
                    , m_tangentSpaceBounds(tangentSpacebounds)
                    , m_instanceTransforms(instanceTransforms)
                    , m_tags(tags)
                    , m_tagIndices(tagIndices)
                    , m_instanceIds(instanceIds)
                    , m_instanceIndices(instanceIndices)
                    {
                    }
                    
                    int FloorNumber() const { return m_floorNumber; }
                    Geometry::Bounds3D Bounds() const { return m_bounds; }
                    Geometry::Bounds3D TangentSpaceBounds() const { return m_tangentSpaceBounds; }

                    const std::vector< std::vector<m44> >& InstanceTransforms() const { return m_instanceTransforms; }
                    const std::vector<std::string>& GetTags() const { return m_tags; }
                    const std::vector<int>& GetTagIndices() const { return m_tagIndices; }

                    const std::vector<std::string>& GetInstanceIds() const { return m_instanceIds; }
                    const std::vector<int>& GetInstanceIndices() const { return m_instanceIndices; }


                private:
                    int m_floorNumber;
                    Geometry::Bounds3D m_bounds;
                    Geometry::Bounds3D m_tangentSpaceBounds;

                    std::vector< std::vector<m44> > m_instanceTransforms;
                    std::vector<std::string> m_tags;
                    std::vector<int> m_tagIndices;

                    std::vector<std::string> m_instanceIds;
                    std::vector<int> m_instanceIndices;

                };
            }
        }
    }
}
