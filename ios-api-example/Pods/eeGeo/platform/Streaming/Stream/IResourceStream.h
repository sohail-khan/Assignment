// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Resources.h"
#include "BlockCoverageTrees.h"
#include <string>

namespace Eegeo
{
    namespace Streaming 
    {         
        class IResourceStream
        {
        public:
            virtual ~IResourceStream() { }
            
            virtual uint averageStreamingSize() = 0;
            virtual uint priority() const = 0;
            virtual Resources::IPlaceholderBuilder *placeholderBuilder() = 0;
            virtual ResourceStreamComponent* resourceStreamComponentFor(const MortonKey& key) const = 0;
            virtual bool HasResourceStreamComponentFor(const MortonKey& key) const = 0;
            
            virtual Resources::IResourceBuilder* GetDefaultResourceBuilder() = 0;
            virtual Resources::IResourceBuilder* GetResourceBuilderByKey(const std::string& key) = 0;
            
            virtual void AddStreamingObserver(IStreamingObserver *pStreamingObserver)=0;
            virtual void RemoveStreamingObserver(IStreamingObserver *pStreamingObserver)=0;
            virtual void NotifyStreamingObserversResourceAdded(const MortonKey& key)=0;
            virtual void NotifyStreamingObserversResourceRemoved(const MortonKey& key)=0;
            
            virtual void LogFailedRequest(const MortonKey& key, float totalTimeTakenMilliseconds) = 0;
            
            virtual void LogSuccessfulRequest(const MortonKey& key,
                                              size_t rawResourceSize,
                                              bool loadedFromCache,
                                              float totalTimeTakenMilliseconds,
                                              size_t preDecompressBytesRead) = 0;
            
            virtual BlockCoverageTrees::PrioritisedBlockCoverageTreeList& GetCoverageTreeList() const = 0;
            virtual ResourceStreamComponent* FindResourceStreamComponent(const std::string& name) const = 0;
            virtual bool IsValid() const = 0;
        };
    }
}
    
    
