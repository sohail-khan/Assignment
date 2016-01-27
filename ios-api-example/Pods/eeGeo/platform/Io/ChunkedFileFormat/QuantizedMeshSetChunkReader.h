// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "AllVertexTypes.h"
#include "LayerIds.h"
#include "CullingVolume.h"
#include "CubeMap.h"
#include "ChunkedFileFormat.h"
#include "BinaryParsing.h"
#include "Rendering.h"
#include "Collision.h"
#include "IQuantizedMeshSetChunkReaderMeshFactory.h"
#include "CollisionGroup.h"
#include "QuantizedMeshInfo.h"
#include "Culling.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
                struct ReaderMeshResult
                {
                    QuantizedMeshInfo meshInfo;
                    Eegeo::Rendering::Mesh* pNewMesh;
                    Culling::CullingVolumeTree* pCullingVolumeTree;
                    
                    ReaderMeshResult()
                    : pNewMesh(NULL)
                    , pCullingVolumeTree(NULL)
                    {}
                };
                

                
                struct ReaderCollisionResult
                {
                    v3 quantizationOrigin;
                    float quantizationScale;
                    float minAltitude;
                    float maxAltitude;
                    bool collisionNeedsLegacyFixup;
                    std::vector<Eegeo::Collision::CollisionBvhNode>* collisionNodes;
                    std::vector<u16>* collisionTriListIndices;
                    std::vector<Eegeo::Rendering::VertexTypes::ShortPositionVertex>* collisionPoints;
                    std::vector<Eegeo::Collision::CollisionMaterialIndexLookupPair>* materialIndexLookupPairs;
                    
                    ReaderCollisionResult()
                    : quantizationOrigin(v3::Zero())
                    , quantizationScale(0.f)
                    , minAltitude(0.f)
                    , maxAltitude(0.f)
                    , collisionNeedsLegacyFixup(false)
                    , collisionNodes(NULL)
                    , collisionTriListIndices(NULL)
                    , collisionPoints(NULL)
                    , materialIndexLookupPairs(NULL)
                    {}
                    
                };
                
                struct ReaderResult
                {
                    std::vector<ReaderMeshResult> meshResults;
                    std::vector<ReaderCollisionResult> collisionResults;
                };
                

                

            
                typedef void (PreGeometryReadCallback)(const Space::CubeMap::CubeMapCellInfo& cellInfo, QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo);
                typedef void (PreMeshCreateCallback)(const Space::CubeMap::CubeMapCellInfo& cellInfo, const QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo, void* pVertexBuffer);
                
                void ReadMeshInfo(Eegeo::IO::ChunkedFileFormat::ChunkStream& chunkStream,
                                  Resources::BinaryParsing::membuf& streamBuf,
                                  std::vector<QuantizedMeshInfo>& results);
            
                void Read(
                    Eegeo::IO::ChunkedFileFormat::ChunkStream& chunkStream,
                    Resources::BinaryParsing::membuf& streamBuf,
                    const Space::CubeMap::CubeMapCellInfo& cellInfo,
                    void* userData,
                    PreGeometryReadCallback* preGeometryReadCallback,
                    PreMeshCreateCallback* preMeshCreateCallback,
                    const std::string& debugNamePrefix,
                    IQuantizedMeshSetChunkReaderMeshFactory& meshFactory,
                    bool generateCollision,
                    ReaderResult& result);
                
                Rendering::Renderables::PackedRenderable* CreatePackedRenderable(
                                                                                  const Rendering::LayerIds::Values layerId,
                                                                                      const Eegeo::dv3& ecefOrigin,
                                                                                      const QuantizedMeshSetChunkReader::ReaderMeshResult& readerMeshResult,
                                                                                      Rendering::Materials::IMaterial* material,
                                                                                  Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                                                      bool renderableItemOwnsMaterial);

                Rendering::Renderables::CustomLandmarkRenderable* CreateCustomLandmarkRenderable(
                                                                                  const Rendering::LayerIds::Values layerId,
                                                                                  const Eegeo::dv3& ecefOrigin,
                                                                                  const QuantizedMeshSetChunkReader::ReaderMeshResult& readerMeshResult,
                                                                                  Rendering::Materials::IMaterial* material,
                                                                                  Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                                                  bool renderableItemOwnsMaterial,
                                                                                  const std::string& landmarkMaterialName);
                
                Rendering::Renderables::PackedShadowRenderable* CreatePackedShadowRenderable(
                                                                                  const Eegeo::dv3& ecefOrigin,
                                                                                  const QuantizedMeshSetChunkReader::ReaderMeshResult& readerMeshResult,
                                                                                  Rendering::Materials::IMaterial* material,                                                                                                                                                                                Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                                                  bool renderableItemOwnsMaterial);
                
                Rendering::Renderables::LightmappedRenderable* CreateLightmappedRenderable(
                                                                                    const Rendering::LayerIds::Values layerId,
                                                                                  const Eegeo::dv3& ecefOrigin,
                                                                                  const QuantizedMeshSetChunkReader::ReaderMeshResult& readerMeshResult,
                                                                                  Rendering::Materials::IMaterial* material,                                                                                                                                                                              Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                                                  bool renderableItemOwnsMaterial);
                
                Rendering::Renderables::WaterRenderable* CreateWaterRenderable(
                                                                                            const Rendering::LayerIds::Values layerId,
                                                                                            const Eegeo::dv3& ecefOrigin,
                                                                                            const QuantizedMeshSetChunkReader::ReaderMeshResult& readerMeshResult,
                                                                                            Rendering::Materials::IMaterial* material,
                                                                                            Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                                                            bool renderableItemOwnsMaterial);


            }
        }
    }
}
