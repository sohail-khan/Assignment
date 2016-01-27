// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LoggingResourceStream.h"
#include "Streaming.h"
#include "Resources.h"
#include "CoverageTrees.h"
#include "PrioritisedBlockCoverageTreeList.h"

#include <string>
#include <map>
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        class ResourceStreamBase : public LoggingResourceStream
        {
        private:
        
            std::map<std::string, Resources::IResourceBuilder*> m_keyedResourceBuilders;
            
            Resources::IPlaceholderBuilder *m_pPlaceholderBuilder;
            
            uint m_priority;
 
            std::vector<IStreamingObserver*> m_streamingObservers;
            
            BlockCoverageTrees::PrioritisedBlockCoverageTreeList* m_coverageTreeList;
            
            ResourceStreamComponent* m_defaultComponent;
            
            std::vector<ResourceStreamComponent*> m_resourceStreamComponents;
            
        protected:
            void registerPlaceholderBuilder(Resources::IPlaceholderBuilder *placeholderBuilder);
            
        public:
            uint priority() const { return m_priority; }
            
            ResourceStreamBase(
                               ResourceStreamComponent* defaultComponent,
                               IStreamingObserver *pStreamingObserver,
                               uint priority
                               );
            
            ~ResourceStreamBase();
            
            void AddStreamingObserver(IStreamingObserver *pStreamingObserver);
            void RemoveStreamingObserver(IStreamingObserver *pStreamingObserver);
            void NotifyStreamingObserversResourceAdded(const MortonKey& key);
            void NotifyStreamingObserversResourceRemoved(const MortonKey& key);
            
            ResourceStreamComponent* resourceStreamComponentFor(const MortonKey& key) const;
            bool HasResourceStreamComponentFor(const MortonKey& key) const;

            Resources::IPlaceholderBuilder* placeholderBuilder();
            
            BlockCoverageTrees::PrioritisedBlockCoverageTreeList& GetCoverageTreeList() const { return *m_coverageTreeList; }
            
            Resources::IResourceBuilder* GetDefaultResourceBuilder();
            
            void AddResourceBuilderByKey(const std::string& key, Resources::IResourceBuilder* builder);
            void RemoveResourceBuilderByKey(const std::string& key, Resources::IResourceBuilder* builder);
            Resources::IResourceBuilder* GetResourceBuilderByKey(const std::string& key);
            
            void AddResourceStreamComponent(ResourceStreamComponent* resourceStream);
            ResourceStreamComponent* FindResourceStreamComponent(const std::string& name) const;
            bool IsValid() const;
        };
    }
}


