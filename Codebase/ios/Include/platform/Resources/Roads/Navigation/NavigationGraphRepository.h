// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "MortonKey.h"
#include <map>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraphRepository : protected Eegeo::NonCopyable
                {
                public:
                    typedef std::map<Eegeo::Streaming::MortonKey, NavigationGraph*, Eegeo::Streaming::MortonKeyCompare> TMap;
                    typedef TMap::const_iterator TConstIterator;
                    
                    NavigationGraphRepository(NavigationGraphLinkManager& linkManager)
                    : m_linkManager(linkManager)
                    {
                        
                    }
                    
                    void Add(NavigationGraph& navGraph);
                    void Remove(const NavigationGraph& navigationGraph);
                    bool TryGetByMortonKey(const Eegeo::Streaming::MortonKey& key, NavigationGraph*& graph) const;
                    
                    void RegisterAddedCallback(INavigationGraphAddedCallback* callback);
                    void UnregisterAddedCallback(INavigationGraphAddedCallback* callback);
                    void RegisterRemovalCallback(INavigationGraphRemovalCallback* callback);
                    void UnregisterRemovalCallback(INavigationGraphRemovalCallback* callback);
                    
                    TConstIterator Begin() const { return m_storage.begin(); }
                    TConstIterator End() const { return m_storage.end(); }

                private:
                    void CallAddedCallbacks(const NavigationGraph& navGraph);
                    void CallRemovalCallbacks(const NavigationGraph& navGraph);

                    TMap m_storage;
                    std::vector<INavigationGraphAddedCallback*> m_addedCallbacks;
                    std::vector<INavigationGraphRemovalCallback*> m_removalCallbacks;
                    NavigationGraphLinkManager& m_linkManager;
                };
            }
        }
    }
}