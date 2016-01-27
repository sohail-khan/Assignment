// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "tr1.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class NavGraphFittingInfoRepository : Eegeo::NonCopyable
            {
            public:
                NavGraphFittingInfoRepository()
                {
                    
                }
                
                virtual ~NavGraphFittingInfoRepository()
                {
                    
                }

                void Add(const Streaming::MortonKey& key, const NavGraphFittingInfoForKey* roadSplines);
                void Remove(const Streaming::MortonKey& key);
                bool Contains(const Streaming::MortonKey& key) const;
                const NavGraphFittingInfoForKey* Get(const Streaming::MortonKey & key) const;
                const NavGraphFittingInfoForKey* TryGet(const Streaming::MortonKey& key) const;
                
                void GetAll(std::vector<const NavGraphFittingInfoForKey*>& values) const;
                void Clear() { m_map.clear(); }
            private:
                typedef Eegeo::unordered_map<s64, const NavGraphFittingInfoForKey*>::type TMap;
                TMap m_map;
            };
        }
    }
}
