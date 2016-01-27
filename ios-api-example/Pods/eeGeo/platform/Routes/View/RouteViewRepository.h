// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "MortonKey.h"
#include <vector>
#include <map>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewRepository : public Eegeo::NonCopyable
            {
            public:
                
                void InsertView(RouteView& view);
               
                void RemoveViewsForRouteAtKey(const Route* route, const Streaming::MortonKey& key, std::vector<RouteView*>& out_removedViews);
                
                void GetViews(std::vector<RouteView*>& out_views) const;
                
                bool HasViewForRouteAtKey(const Route* route, const Streaming::MortonKey& key) const;
                
            private:
                typedef std::multimap<Streaming::MortonKey, RouteView*> TMapKeyToViews;
                TMapKeyToViews m_keysToViews;
            };
        }
    }
}
