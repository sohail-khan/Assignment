// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Tasks.h"
#include "Streaming.h"
#include "Resources.h"
#include "Helpers.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        class ResourceNodeCache;
        class BuildWorkItem;
        
        class PayloadBuildManager : protected Eegeo::NonCopyable
        {
            // this limits total number of async inflates in progress. We can't cancel a build job once issued,
            // so need to keep this reasonably small to avoid a backlog of unwanted builds when moving around rapidly
            // static const int buildWorkItemPoolSize = 20;
            
            // alter this to throttle number of async builds issued in any one frame. Smaller values
            // help avoid many requests completing on same frame and causing hitching as we do finalise on
            // main thread
            static const int maxPayloadBuildsIssuedPerFrame = 5;
            
        private:
            BuildPrioritiser& m_buildPrioritiser;
            ResourceNodeCache& m_resourceNodeCache;
            Concurrency::Tasks::IWorkPool& m_workPool;
            Helpers::IHttpCache& m_httpCache;
            size_t m_activeJobs;
            
            std::vector<Payload*> m_prioritisedPayloads;
            
        public:
            PayloadBuildManager(
                                BuildPrioritiser& buildPrioritiser,
                                ResourceNodeCache& resourceNodeCache,
                                Concurrency::Tasks::IWorkPool& workPool,
                                Helpers::IHttpCache& httpCache);
            ~PayloadBuildManager();
            void UpdateBuilds(float deltaTimeMs, int updateCount);
            void HandleWorkItemCompleted(BuildWorkItem* pCompletedItem);
            Helpers::IHttpCache& GetHttpCache() const;
            
        private:
            BuildWorkItem* GetNextAvailableWorkItem();
            void BuildAsync(BuildWorkItem& workItem, Payload& pPayload, Concurrency::Tasks::Priority::Values priority);
        };
    }
}
