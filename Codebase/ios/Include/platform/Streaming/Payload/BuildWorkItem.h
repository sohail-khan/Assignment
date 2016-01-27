// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WorkItem.h"
#include "MortonKey.h"
#include "IResourceBuilder.h"
#include "MortonKey.h"
#include "Tasks.h"
#include "Helpers.h"
#include "Resources.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        class BuildWorkItem : public Concurrency::Tasks::WorkItem
        {
        private:
            void* m_pBuildData;
            Resources::IResourceBuilder *m_pBuilder;
            MortonKey m_key;

            const std::vector<Byte>* m_resourceData;
            bool m_useResourceData;
            
            Eegeo::Resources::BuilderTransition m_buildResult;
            PayloadBuildManager* m_pBuildManager;
            Payload * m_payload;
            
            void Cleanup();
            
        protected:
            void DoWork();
            void DoFinalizeOnMainThread();
            void DoWorkCancelled();

        public:
            BuildWorkItem();
            ~BuildWorkItem();
            
            void Setup(PayloadBuildManager& buildManager, Payload& payload, Concurrency::Tasks::Priority::Values priority);
            Payload* GetPayload() const { return m_payload; }
            
            Eegeo::Resources::BuilderTransition BuildResult() { return m_buildResult; }
            
        };
    }
}
