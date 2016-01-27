// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>

#include "Types.h"
#include "Modules.h"
#include "Streaming.h"
#include "Web.h"
#include "SceneGraphCellRepository.h"
#include "Helpers.h"
#include "Tasks.h"
#include "Camera.h"
#include "Terrain.h"
#include "Buildings.h"
#include "Rendering.h"
#include "CityThemes.h"
#include "AsyncTexturing.h"
#include "AsyncModels.h"
#include "StreamingPipelineVisualiser.h"
#include "DebugRendering.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class StreamingModule : protected Eegeo::NonCopyable
            {
            public:
                StreamingModule(
                        Eegeo::Web::IWebLoadRequestFactory& webLoadRequestFactory,
                        Eegeo::Helpers::IHttpCache& httpCache,
                        Eegeo::Concurrency::Tasks::IWorkPool& workPool,
                        Eegeo::Streaming::CameraFrustumStreamingVolume& streamingVolume,
                        Eegeo::Resources::CityThemes::ICityThemesService& cityThemesService,
                        Eegeo::Rendering::AsyncTexturing::HttpAsyncTextureLoader& httpAsyncTextureLoader,
                        Eegeo::Io::AsyncModels::HttpAsyncModelLoader& asyncModelLoader,
                        Eegeo::Resources::Terrain::TerrainStreaming &terrainStreaming,
                        Eegeo::DebugRendering::DebugRenderer& debugRenderer,
                        size_t resourceNodeCacheEntries);

                ~StreamingModule();
                
                static StreamingModule* Create(Core::AsyncLoadersModule& asyncLoadersModule,
                                               Core::SceneModelsModule& sceneModelsModule,
                                               Map::Layers::TerrainStreamingModule& terrainStreamingModule,
                                               Map::CityThemesModule& cityThemesModule,
                                               Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                               Helpers::IHttpCache& httpCache,
                                               Concurrency::Tasks::IWorkPool& workPool,
                                               Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                               Eegeo::DebugRendering::DebugRenderer& debugRenderer,
                                               size_t resourceNodeCacheEntries);
                
                Web::PrecacheService& GetPrecachingService() const { return *m_pPrecachingService; }
                
                Streaming::StreamingController& GetStreamingController() const { return *m_pStreamingController; }
                Streaming::BuildPrioritiser& GetBuildPrioritiser() const { return *m_pBuildPrioritiser; }
                Streaming::PayloadBuildManager& GetPayloadBuildManager() const { return *m_pBuildManager; }
                Streaming::StreamingVolumeController& GetStreamingVolumeController() const { return *m_pStreamingVolumeController; }
                Streaming::QuadTreeCube& GetQuadTreeCube() const { return *m_pQuadTreeCube; }
                Streaming::QuadTreeVisibilityUpdater& GetQuadTreeVisibilityUpdater() const { return *m_pQuadTreeVisibilityUpdater; }
                Streaming::PayloadPriorityComparator& GetPayloadPriorityComparator() const { return *m_pPayloadPriorityComparator; }
                Streaming::PayloadSlotStreamMap& GetPayloadStreams() const { return *m_pPayloadSlotStreamMap; }
                Streaming::PayloadPlaceholderBuilder& GetPayloadPlaceholderBuilder() const { return *m_pPayloadPlaceholderBuilder; }
                Streaming::TerrainPlaceholderInserter& GetTerrainPlaceholderInserter() const { return *m_pTerrainPlaceholderInserter; }
                Streaming::LoadPrioritiser& GetLoadPrioritiser() const { return *m_pLoadPrioritiser; }
                Streaming::QuadTreeNodePool& GetQuadTreeNodePool() const { return *m_pNodePool; }
                Streaming::PayloadPool& GetPayloadPool() const { return *m_pPayloadPool; }
                Streaming::PayloadEvicter& GetPayloadEvicter() const { return *m_pPayloadEvicter; }
                Streaming::SceneGraphUpdater& GetSceneGraphUpdater() const { return *m_pSceneGraphUpdater; }
                Streaming::RedundantNodeEvicter& GetRedundantNodeEvicter() const { return *m_pNodeEvicter; }
                Streaming::ResourceNodeCache& GetResourceNodeCache() const { return *m_pResourceNodeCache; }
                Streaming::PayloadWebLoader& GetPayloadWebLoader() const { return *m_pPayloadWebLoader; }
                Streaming::SceneGraphCellRepository& GetSceneGraphCellRepository() { return m_sceneGraphCellRepository; }
                Streaming::Debug::StreamingPipelineVisualiser& GetStreamingVisauliser() { return *m_pStreamingVisualiser; }
                
                void SetStreams(const std::vector<Eegeo::Streaming::LodStreamMap>& lodStreamMaps);

                void Update(float dt,
                            const Camera::RenderCamera& renderCamera,
                            const dv3& ecefInterestPoint,
                            Streaming::IStreamingVolume& streamingVolume);
                
                void Draw(const Rendering::RenderContext& renderContext);
                
            private:
                Streaming::StreamingController* m_pStreamingController;
                Streaming::BuildPrioritiser* m_pBuildPrioritiser;
                Streaming::ResourceNodeCache* m_pResourceNodeCache;
                Streaming::PayloadBuildManager* m_pBuildManager;
                Streaming::StreamingVolumeController* m_pStreamingVolumeController;
                Streaming::QuadTreeCube* m_pQuadTreeCube;
                Streaming::SceneGraphCellRepository m_sceneGraphCellRepository;
                Streaming::QuadTreeVisibilityUpdater* m_pQuadTreeVisibilityUpdater;
                Streaming::PayloadPriorityComparator* m_pPayloadPriorityComparator;
                Streaming::PayloadSlotStreamMap* m_pPayloadSlotStreamMap;
                Streaming::PayloadPlaceholderBuilder* m_pPayloadPlaceholderBuilder;
                Streaming::TerrainPlaceholderInserter* m_pTerrainPlaceholderInserter;
                Streaming::Debug::StreamingPipelineVisualiser* m_pStreamingVisualiser;
                
                Streaming::LoadPrioritiser* m_pLoadPrioritiser;
                Streaming::QuadTreeNodePool* m_pNodePool;
                Streaming::PayloadPool* m_pPayloadPool;
                Streaming::PayloadEvicter* m_pPayloadEvicter;
                Streaming::SceneGraphUpdater* m_pSceneGraphUpdater;
                Streaming::RedundantNodeEvicter* m_pNodeEvicter;
                Streaming::PayloadWebLoader* m_pPayloadWebLoader;
                Web::PrecacheService* m_pPrecachingService;
            };
        }
    }
}
