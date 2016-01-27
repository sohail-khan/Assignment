// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Roads.h"
#include "Rendering.h"
#include "Navigation.h"
#include "Types.h"
#include "IResourceBuilder.h"
#include "Fonts.h"
#include "TextMeshes.h"
#include "ChunkedFileFormat.h"
#include "RoadNamesChunkReader.h"
#include "Space.h"
#include "VectorMathDecl.h"
#include "ParsedNavGraph.h"
#include "CollisionBvhFactory.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            struct RoadBuilderOutput
            {
                RoadBuilderOutput()
                :  renderRoad(false)
                ,  roadNavGraph(NULL)
                ,  railNavGraph(NULL)
                ,  tramNavGraph(NULL)
                , pRoadsCollisionBvh(NULL)
                , pRailCollisionBvh(NULL)
                , pTramlinesCollisionBvh(NULL)
                {
                };
                
                bool renderRoad;
                std::vector<Rendering::Renderables::PackedRenderable*> newGeometryRenderables;
                std::vector<Rendering::Renderables::PackedShadowRenderable*> newShadowRenderables;
                std::vector<RoadNamesRenderable*> roadNameRenderables;
                Navigation::NavigationGraph* roadNavGraph;
                Navigation::NavigationGraph* railNavGraph;
                Navigation::NavigationGraph* tramNavGraph;
                Eegeo::Collision::CollisionBvh* pRoadsCollisionBvh;
                Eegeo::Collision::CollisionBvh* pRailCollisionBvh;
                Eegeo::Collision::CollisionBvh* pTramlinesCollisionBvh;
                

                ~RoadBuilderOutput();
                
                void RelinquishOwnership();
            };
            
            enum TransportLayerType
            {
                TransportLayerType_Invalid,
                TransportLayerType_Road,
                TransportLayerType_Rail,
                TransportLayerType_Tram
            };
            
            struct QCMSChunkBuiltResources
            {
                QCMSChunkBuiltResources()
                : pCollisionBvh(NULL)
                {}
                
                std::vector<Rendering::Renderables::PackedRenderable*> geometryRenderables;
                std::vector<Rendering::Renderables::PackedShadowRenderable*> shadowRenderables;
                Collision::CollisionBvh* pCollisionBvh;
            };
            
            class ChunkedRoadBuilder : protected Eegeo::NonCopyable, public IResourceBuilder
            {
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                Rendering::IMaterialProvider& m_materialProvider;
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_roadSceneElementRepository;
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_shadowSceneElementRepository;

                Navigation::NavigationGraphBuilder& m_roadNavGraphBuilder;
                Navigation::NavigationGraphBuilder& m_railNavGraphBuilder;
                Navigation::NavigationGraphBuilder& m_tramNavGraphBuilder;

                const Fonts::FontInstance& m_roadNameFont;
                const Fonts::FontMaterialSet& m_roadNameMaterials;
                TextMeshes::PreTransformedTextMeshBuilder& m_roadNameTextMeshBuilder;
                Rendering::Scene::SceneElementRepository<RoadNamesRenderable>& m_roadNameSceneElementRepository;
                
                float m_namesHeightAboveGroundMap[3];
                float m_namesScaleMultiplier[3];

                IO::ChunkedFileFormat::RoadNamesChunkReader::RoadNames m_currentRoadNames;
                
                std::vector<u32> m_stringScratch;
                NavGraphData m_navGraphDtoScratch;
                
                Eegeo::Collision::CollisionBvhFactory m_roadsCollisionBvhFactory;
                Eegeo::Collision::CollisionBvhFactory m_railCollisionBvhFactory;
                Eegeo::Collision::CollisionBvhFactory m_tramlinesCollisionBvhFactory;
                
                Eegeo::Collision::CollisionMeshResourceRepository& m_roadsCollisionMeshRepository;
                Eegeo::Collision::CollisionMeshResourceRepository& m_railCollisionMeshRepository;
                Eegeo::Collision::CollisionMeshResourceRepository& m_tramlinesCollisionMeshRepository;
                
                const bool m_bGenerateCollision;
                
            public:
                ChunkedRoadBuilder(
                                   Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                   Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                   Rendering::IMaterialProvider& materialProvider,
                                   Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& roadSceneElementRepository,
                                   Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& shadowSceneElementRepository,
                                   Navigation::NavigationGraphBuilder& roadNavGraphBuilder,
                                   Navigation::NavigationGraphBuilder& railNavGraphBuilder,
                                   Navigation::NavigationGraphBuilder& tramNavGraphBuilder,
                                   Eegeo::Collision::CollisionMeshResourceRepository& roadsCollisionMeshRepository,
                                   Eegeo::Collision::CollisionMeshResourceRepository& railCollisionMeshRepository,
                                   Eegeo::Collision::CollisionMeshResourceRepository& tramlinesCollisionMeshRepository,
                                   bool generateCollision,
                                   const Fonts::FontInstance& roadNameFont,
                                   const Fonts::FontMaterialSet& roadNameMaterials,
                                   TextMeshes::PreTransformedTextMeshBuilder& roadNameTextMeshBuilder,
                                   Rendering::Scene::SceneElementRepository<RoadNamesRenderable>& roadNameSceneElementRepository
                                   );
                virtual ~ChunkedRoadBuilder();
                
                virtual bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result);
                virtual void DestroyBuiltResource(const Streaming::MortonKey& key, void* input);
                virtual void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length);
                virtual bool AcceptsErroredRequests()
                {
                    return true;
                }
                
            private:
                Rendering::MeshFactories::PackedDiffuseReadMeshFactory& m_packedDiffuseReadMeshFactory;

                void GetRoadNameTransformMatrix(const Eegeo::Space::CubeMap::CubeMapCellInfo& cellInfo, const v3& ecefUp, const v3& segmentStart, const v3& segmentEnd, float textLength, Eegeo::m44& result);
                void BuildRoadNamesMeshes(Eegeo::Space::CubeMap::CubeMapCellInfo cellInfo, IO::ChunkedFileFormat::ChunkStream& chunkStream, std::vector<RoadNamesRenderable*>& out_roadNameRenderables);
                void GenerateRoadNamesGeometryVersion0(Eegeo::Space::CubeMap::CubeMapCellInfo cellInfo, std::vector<RoadNameData> roadNameDatas);
                void GenerateRoadNamesGeometryVersion1(const Eegeo::Space::CubeMap::CubeMapCellInfo& cellInfo, const IO::ChunkedFileFormat::RoadNamesChunkReader::RoadNames& roadNames, int maxCharsPerRoadName);
                

                
                QCMSChunkBuiltResources BuildResourcesFromQuantizedMeshSet(
                    IO::ChunkedFileFormat::ChunkStream& chunkStream,
                    BinaryParsing::membuf& streamBuf,
                    const Space::CubeMap::CubeMapCellInfo& cellInfo,
                    const Eegeo::dv3& ecefOrigin,
                    Collision::ICollisionBvhFactory& collisionBvhFactory);
            };
        }
    }
}
