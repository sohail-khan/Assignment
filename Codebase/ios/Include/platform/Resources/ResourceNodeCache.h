// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "MortonKey.h"
#include <list>

namespace Eegeo
{
    namespace Streaming
    {
        struct CachedResourceNode
        {
        public:
            CachedResourceNode(
                               const IResourceStream* resourceStream,
                               const MortonKey key,
                               ResourceNode* resourceNode
                               ) :
            pResourceStream(resourceStream),
            mortonKey(key),
            pResourceNode(resourceNode)
            {
            }
            
            bool MatchesKey(const IResourceStream* resourceStream, const MortonKey otherKey)
            {
                return (pResourceStream == resourceStream && mortonKey == otherKey);
            }
            
            const IResourceStream* pResourceStream;
            const MortonKey mortonKey;
            ResourceNode* pResourceNode;
        };
        
        class ResourceNodeCache
        {
        public:
            ResourceNodeCache(size_t maxResourceNodes);

            ~ResourceNodeCache();
            
            ResourceNode* GetResourceNodeOrNull(const IResourceStream* resourceStream, const MortonKey mortonKey);
                       
            void AddResourceNode(
                                 const IResourceStream* resourceStream,
                                 const MortonKey mortonKey,
                                 ResourceNode* resourceNode);
                       
            int GetTotalNumOfAllocations() const { return m_totalNumOfAllocations; }
            int GetTotalNumOfMisses() const { return m_totalNumOfMisses; }
            int GetTotalNumOfDeletions() const { return m_totalNumOfDeletions; }
            int GetTotalNumOfAdds() const { return m_totalNumOfAdds; }
            int GetSize() const { return static_cast<int>(m_cachedNodes.size()); }
            
            void ResetCounters();
            
        private:
            size_t m_maxResourceNodes;
            std::list<CachedResourceNode> m_cachedNodes;
            int m_totalNumOfAllocations;
            int m_totalNumOfMisses;
            int m_totalNumOfDeletions;
            int m_totalNumOfAdds;
        };
    }
}
