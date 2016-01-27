// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PoolHandle.h"
#include "WorkItem.h"
#include "Streaming.h"
#include "Web.h"
#include "Resources.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    { 
        class IResourceBuilder;
        class IBuiltResource;
    }
}

namespace Eegeo
{
    namespace PayloadState
    {
        enum PayloadStateValues
        {
            INVALID=0,
            TO_BE_LOADED,
            LOADING,
            READY_FOR_BUILDING,
            BUILDING,
            BUILT,
            IN_SCENE_GRAPH,
            LOAD_FAILED,
            FINAL_PLACEHOLDER,
            MAX
        };
    }
    
    namespace Streaming 
    {        
        class QuadTreeNode;
        class IResourceStream;
        class ResourceNode;
        class PayloadBuildManager;
        class ResourceNodeCache;
        
        class Payload : protected Eegeo::NonCopyable
        {       
        public:
            DataStructures::PoolHandle handle;
        private:
            uint lastVisibleUpdate;
        public:
            QuadTreeNode *node;
            bool isLocallyCached;
            
        private:
            IResourceStream *m_pStream;
            ResourceStreamComponent* m_resourceStreamComponent;
            PayloadState::PayloadStateValues m_state;		
            float m_priority;
            int m_earliestUpdateCountForLoad;
            Web::IWebLoadRequest* m_webLoadRequest;
            PayloadWebLoader* m_payloadWebLoader;
            const std::vector<Byte>* m_resourceData;
            bool m_successfulLoad;
            
            Concurrency::Tasks::WorkItem *m_pWorkItem;
            ResourceNodeCache* m_pResourceNodeCache;
            ResourceNode *m_pResourceNode;
            int m_failedLoadAttemptCount;
            bool m_shouldBuildPlaceholder;
            Resources::IBuiltResource* m_pPlaceholder;
            
            long long m_timeOfLastStateChange;
            long long m_timePerState[PayloadState::MAX];
            
            void setState(PayloadState::PayloadStateValues newState);
            bool stateIs(PayloadState::PayloadStateValues stateToCheckFor) const;
            void tryClearPlaceholder();
            
        public:
            IResourceStream* GetResourceStream() const { return m_pStream; };
            ResourceNode *resourceNode() const { return m_pResourceNode; }
            MortonKey key() const;

            bool shouldBuildPlaceholder() const { return m_shouldBuildPlaceholder; }
            Resources::IResourceBuilder* resourceBuilder() const;
            Resources::IPlaceholderBuilder* placeholderBuilder() const;
            uint StreamPriority() const;
            std::string url(bool relativeUrl = false) const;
            const std::vector<Byte>* GetResourceData() const { return m_resourceData; }
            bool SuccessfulLoad() { return m_successfulLoad; }
            
            float GetPriority() const { return m_priority; }
            void SetPriority(float priority) { m_priority = priority; }
            void SetEarliestUpdateCountForLoad(int updateCount) { m_earliestUpdateCountForLoad = updateCount; }
            
            Payload();
            ~Payload();

            void SetPlaceholder(Resources::IBuiltResource* placeholder);
            void OnAllocatedFromPool(DataStructures::PoolHandle poolHandle);            
            void init(QuadTreeNode *pNode, IResourceStream *pStream, ResourceStreamComponent* resourceStreamComponent);
            void setNeedsPlaceholder(bool dontBuildOnTopOf);
            void onReleaseToPool();            

            void SetToBeLoaded();
            void LoadStarted(PayloadWebLoader* payloadWebLoader, Web::IWebLoadRequest* webLoadRequest);
            void LoadCompleted(Web::IWebResponse& webResponse);
            
            void abortLoad();            
            
            void loadErrored();
            void loadFailed();
            void startedBuilding(Concurrency::Tasks::WorkItem *pWorkItem);
            void abortBuild();            
            void buildComplete(ResourceNode* pResourceNode, ResourceNodeCache* pResourceNodeCache);
            void addedToSceneGraph();
            
            bool hasPlaceholder() const;            
            bool isReadyForBuilding(int updateCount) const;
            bool isReadyForLoading(int updateCount) const;
            bool isReadyForSceneGraph(int updateCount) const;
            bool isLate(int updateCount) const;
            bool isInSceneGraph() const;
            bool isInSceneGraphOrHasPlaceholder() const;
            bool isBuilt() const;
            bool isLoadFailure() const;
            bool isPendingLoadCompletion(int updateCount) const;
            bool isInVisibleSet(int updateCount) const;
            bool shouldForwardErroredRequestsToBuilder() const;
            bool shouldBeLoaded() const;
            float timeInState(PayloadState::PayloadStateValues state) const;
            PayloadState::PayloadStateValues GetState() const;
            void SetLastVisibleUpdate(int updateCount) { lastVisibleUpdate = updateCount; }
            
            void LogFailedRequest();
            void LogSuccessfulRequest(Web::IWebResponse& webResponse);
        };
    }
}
