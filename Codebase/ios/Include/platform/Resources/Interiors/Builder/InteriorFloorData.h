// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"

#include "InteriorFloorChunkDto.h"
#include "InteriorEntitiesChunkDto.h"
#include "Rendering.h"
#include "Collision.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct InteriorFloorData : private Eegeo::NonCopyable
                {
                    InteriorFloorData(const InteriorFloorChunkDto& interiorsFloorChunkDto,
                                      const InteriorEntitiesChunkDto& interiorEntitiesChunkDto,
                                      const std::vector<InteriorRenderableCreationData*>& interiorRenderableCreationDatas,
                                      const std::vector<InteriorRenderableCreationData*>& interiorHighlightRenderableCreationDatas,
                                      const std::vector<Collision::CollisionBvh*>& collisionBvhs,
                                      const std::vector<Collision::CollisionBvh*>& highlightCollisionBvhs,
                                      const std::vector<InteriorRenderableCreationData*>& instanceSourceMeshes,
                                      const std::vector<std::vector<m44> >& instanceTransforms);
                    
                    ~InteriorFloorData();
                    
                    const InteriorFloorChunkDto& GetInteriorsFloorChunkDto() const { return m_interiorsFloorChunkDto; }
                    const InteriorEntitiesChunkDto& GetInteriorEntitiesChunkDto() const { return m_interiorEntitiesChunkDto; }

                    const std::vector<Collision::CollisionBvh*>& GetCollisionBvhs() const { return m_collisionBvhs; }
                    const std::vector<Collision::CollisionBvh*>& GetHighlightCollisionBvhs() const { return m_highlightCollisionBvhs; }
                    const std::vector<InteriorRenderableCreationData*>& GetInteriorRenderableCreationDatas() const { return m_renderableCreationDatas; }
                    const std::vector<InteriorRenderableCreationData*>& GetInteriorHighlightRenderableCreationDatas() const { return m_highlightRenderableCreationDatas; }

                    const std::vector<std::vector<m44> >& GetInstanceTransforms() const { return m_instanceTransforms; }
                    const std::vector<InteriorRenderableCreationData*>& GetInstanceSourceRenderableCreationDatas() const { return m_instanceSourceMeshRenderableCreationDatas; }
                    
                private:
                    InteriorFloorChunkDto m_interiorsFloorChunkDto;
                    InteriorEntitiesChunkDto m_interiorEntitiesChunkDto;
                    std::vector<InteriorRenderableCreationData*> m_renderableCreationDatas;
                    std::vector<InteriorRenderableCreationData*> m_highlightRenderableCreationDatas;
                    std::vector<Collision::CollisionBvh*> m_collisionBvhs;
                    std::vector<Collision::CollisionBvh*> m_highlightCollisionBvhs;
                    std::vector<InteriorRenderableCreationData*> m_instanceSourceMeshRenderableCreationDatas;
                    std::vector<std::vector<m44> > m_instanceTransforms;
                };
            }
        }
    }
}
