// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "IResourceBuilder.h"
#include "Types.h"
#include "Interiors.h"
#include "Collision.h"
#include "Rendering.h"
#include "Space.h"
#include "ChunkedFileFormat.h"
#include "CollisionBvhFactory.h"
#include "InteriorMetadataChunkDto.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                class ChunkedInteriorsBuilder : protected Eegeo::NonCopyable, public IResourceBuilder
                {
                public:
                    ChunkedInteriorsBuilder(Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                            Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                            Resources::Interiors::IInteriorsMaterialService& interiorsMaterialService,
                                            Resources::Interiors::InteriorsModelRepository& interiorsModelRepository,
                                            Resources::Interiors::InteriorsInstanceRepository& interiorsInstanceRepository,
                                            Resources::Interiors::Entities::InteriorsEntitiesRepository& interiorsEntitiesRepository,
                                            Collision::CollisionMeshResourceRepository& collisionMeshResourceRepository,
                                            Collision::CollisionMeshResourceRepository& highlightCollisionMeshResourceRepository,
                                            Resources::Interiors::InteriorsCellResourceObserver& interiorsCellResourceObserver,
                                            const Resources::Interiors::IInteriorsMaterialAssignmentObserver& interiorsMaterialAssignmentObserver,
                                            const Resources::Interiors::InteriorsStencilMirrorClearRenderableFactory& interiorsStencilMirrorClearRenderableFactory,
                                            const std::string& defaultInteriorMaterialName,
                                            const bool affectedByFlattening);
                    
                    bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result);
                    void DestroyBuiltResource(const Streaming::MortonKey& key, void* input);
                    
                    void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length);
                    
                    bool AcceptsErroredRequests();

                private:
                    
                    Rendering::MeshFactories::PackedDiffuseReadMeshFactory& m_packedDiffuseReadMeshFactory;
                    Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                    Resources::Interiors::IInteriorsMaterialService& m_interiorsMaterialService;
                    Eegeo::Collision::CollisionBvhFactory m_collisionBvhFactory;
                    Eegeo::Collision::CollisionBvhFactory m_highlightCollisionBvhFactory;
                    Resources::Interiors::InteriorsModelRepository& m_interiorsModelRepository;
                    Resources::Interiors::InteriorsInstanceRepository& m_interiorsInstanceRepository;
                    Resources::Interiors::Entities::InteriorsEntitiesRepository& m_interiorsEntitiesRepository;
                    Collision::CollisionMeshResourceRepository& m_collisionMeshResourceRepository;
                    Collision::CollisionMeshResourceRepository& m_highlightCollisionMeshResourceRepository;
                    Resources::Interiors::InteriorsCellResourceObserver& m_interiorsCellResourceObserver;
                    const Resources::Interiors::IInteriorsMaterialAssignmentObserver& m_interiorsMaterialAssignmentObserver;
                    const Resources::Interiors::InteriorsStencilMirrorClearRenderableFactory& m_interiorsStencilMirrorClearRenderableFactory;
                    const std::string m_defaultInteriorMaterialName;
                    const bool m_affectedByFlattening;
                    
                    void CreateFloorResourcesFromQuantizedMeshSet(const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                                                  IO::ChunkedFileFormat::ChunkStream& chunkStream,
                                                                  Resources::BinaryParsing::membuf& membuf,
                                                                  const int floorDrawOrder,
                                                                  std::vector<InteriorRenderableCreationData*>& out_renderableCreationDatas,
                                                                  std::vector<Collision::CollisionBvh*>& out_collisionBvhs,
                                                                  bool isHighlight);
                    
                    InteriorsCellResource* CreateInteriorsCellResource(const Streaming::MortonKey& key, const InteriorData& interiorData);
                    
                    std::vector<InteriorsFloorCell*> CreateInteriorsFloorCells(const Streaming::MortonKey& key,
                                                                               const InteriorData& interiorData,
                                                                               const InteriorsModel& interiorModel);
                    
                    InteriorRenderableCreationData* CreateInteriorRenderableCreationData(const Eegeo::dv3& ecefOrigin,
                                                                                         const IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::ReaderMeshResult& readerMeshResult,
                                                                                         const InteriorMaterialData& interiorMaterialData,
                                                                                         Rendering::LayerIds::Values layerId,
                                                                                         int floorIndex);

                    Eegeo::Resources::Interiors::Builder::InteriorInstanceChunkDto BuildInteriorInstanceChunk(
                        IO::ChunkedFileFormat::ChunkStream& chunkStream,
                        Resources::BinaryParsing::membuf& membuf,
                        const Space::CubeMap::CubeMapCellInfo& cellInfo,
                        Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::IQuantizedMeshSetChunkReaderMeshFactory& meshFactory,
                        std::vector<InteriorRenderableCreationData*>& out_renderableCreationDatas);
                };
            }
        }
    }
}