// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Web.h"
#include "AsyncTexturing.h"
#include "AsyncModels.h"
#include "Rendering.h"
#include "CameraFrustumStreamingVolume.h"
#include "Camera.h"
#include "MortonKey.h"
#include "ICallback.h"
#include <vector>

namespace Eegeo
{    
    namespace Streaming
    {
        typedef Helpers::ICallback1<const std::vector<MortonKey>&> TKeysCallback;

        class StreamingController : public Eegeo::NonCopyable
        {
        private:
            
            std::vector<MortonKey> m_keysThatAreNowVisible;
            std::vector<MortonKey> m_keysThatAreNoLongerVisible;
            std::vector<MortonKey> m_currentlyVisibleKeys;
            
            PayloadWebLoader* m_pPayloadWebLoader;
            PayloadBuildManager *m_pBuildManager;           
            CameraFrustumStreamingVolume *m_pStreamingVolume;
            StreamingVolumeController *m_pStreamingVolumeController;            
            QuadTreeCube *m_pQuadTreeCube;
            QuadTreeVisibilityUpdater *m_pVisibilityUpdater;
            LoadPrioritiser *m_pLoadPrioritiser;      
            PayloadPool *m_pPayloadPool;     
            PayloadEvicter *m_pPayloadEvicter;            
            SceneGraphUpdater *m_pSceneGraphUpdater;            
            RedundantNodeEvicter *m_pNodeEvicter;
            PayloadSlotStreamMap *m_pPayloadSlotStreamMap;
            PayloadPlaceholderBuilder *m_pPayloadPlaceholderBuilder;
            TerrainPlaceholderInserter *m_pTerrainPlaceholderInserter;
            ResourceNodeCache* m_pResourceNodeCache;
            Web::PrecacheService *m_pPrecachingService;
            Rendering::AsyncTexturing::HttpAsyncTextureLoader& m_httpAsyncTextureLoader;
            Io::AsyncModels::HttpAsyncModelLoader& m_asyncModelLoader;
            
            int m_updateCount;
            bool m_enabled;
            bool m_evictAllOnNextUpdate;
            
            std::vector<Payload*> m_payloadsToLoadInPriorityOrder;
            
            // Temporary visibility set observation
            std::vector<TKeysCallback*> m_keyVisibleCallbacks;
            std::vector<TKeysCallback*> m_keyInvisibleCallbacks;
            
        public:
            StreamingController(PayloadWebLoader* pPayloadWebLoader,
                                PayloadBuildManager *pBuildManager,           
                                CameraFrustumStreamingVolume *pStreamingVolume,
                                StreamingVolumeController *pStreamingVolumeController,            
                                QuadTreeCube *pQuadTreeCube,
                                QuadTreeVisibilityUpdater *pVisibilityUpdater,	            
                                LoadPrioritiser *pLoadPrioritiser,    
                                PayloadPool *pPayloadPool,   
                                PayloadEvicter *pPayloadEvicter,            
                                SceneGraphUpdater *pSceneGraphUpdater,            
                                RedundantNodeEvicter *pNodeEvicter,
                                PayloadSlotStreamMap *pPayloadSlotStreamMap,
                                PayloadPlaceholderBuilder *pPayloadPlaceholderBuilder,
                                TerrainPlaceholderInserter *pTerrainPlaceholderInserter,
                                ResourceNodeCache* pResourceNodeCache,
                                Web::PrecacheService *pPrecachingService,
                                Rendering::AsyncTexturing::HttpAsyncTextureLoader& httpAsyncTextureLoader,
                                Eegeo::Io::AsyncModels::HttpAsyncModelLoader& asyncModelLoader
                                );
     
            virtual ~StreamingController() {;}

            void SetLODStreams(const std::vector<Eegeo::Streaming::LodStreamMap>& lodStreamMaps);
            void Render();
            void Update(float deltaSeconds,
                        const Camera::RenderCamera& renderCamera,
                        const dv3& ecefInterestPoint,
                        Streaming::IStreamingVolume& streamingVolume);
            int numPayloadsWaitingToLoad();
            int numPayloadsWaitingToBuild();
            int numPayloadsPendingLoadCompletion() const;
            int numPayloadsFailedLoad();
            int numPayloadsCompleted() const;
            int totalPayloadsAllocated() const;
            bool AllPayloadsAreInSceneOrErrored();
            bool AnyPayloadsInScene() const;
            PayloadStateStats GetPayloadStateStats() const;
            void evictAllOnNextUpdate();
            void SetEnabled(bool enabled);
            bool Enabled();

            
            void RegisterKeyVisibleCallback(TKeysCallback* callback);
            void UnregisterKeyVisibleCallback(TKeysCallback* callback);
            void RegisterKeyInvisibleCallback(TKeysCallback* callback);
            void UnregisterKeyInvisibleCallback(TKeysCallback* callback);

            void CallKeyVisibleCallbacks(const std::vector<MortonKey>& newlyVisibleKeys);
            void CallKeyInvisibleCallbacks(const std::vector<MortonKey>& newlyInvisibleKeys);
            
            const std::vector<MortonKey>& GetCurrentlyVisibleMortonKeys() const;
            
        private:            
            void issueLoadRequests(int updateCount);  
        };
    }
}
