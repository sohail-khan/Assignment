// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Resources.h"
#include "MortonKey.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming 
    {          
        class ResourceNode : protected Eegeo::NonCopyable
        {
        private:
            typedef std::vector<Resources::IBuiltResource*> TResourceVector;
            TResourceVector m_resources;
            int m_numOfPoolAdds;
            int m_numOfPoolAllocates;
            
        public:
            ResourceNode(const std::vector<Resources::IBuiltResource*>& resources);
            
            ~ResourceNode();
            
            int count() { return static_cast<int>(m_resources.size()); }
            const std::vector<Resources::IBuiltResource*> &resources() { return m_resources; }
            
            void AddedToSceneGraph(MortonKey key);
            void RemovedFromSceneGraph();
            
            void SetAddedToPool(void)
            {
                Eegeo_ASSERT(m_numOfPoolAdds <= m_numOfPoolAllocates);
                m_numOfPoolAdds++;
            }
            
            void SetAllocatedFromPool(void)
            {
                Eegeo_ASSERT(m_numOfPoolAllocates < m_numOfPoolAdds);
                m_numOfPoolAllocates++;
            }
        };
    }
}
