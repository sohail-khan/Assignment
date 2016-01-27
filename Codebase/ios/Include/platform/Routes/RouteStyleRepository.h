// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteStyle.h"
#include <map>
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class RouteStyleRepository : public Eegeo::NonCopyable
        {
        private:
            std::map<const Route*, Style::RouteStyle> m_routeStyleMap;
            std::vector<View::IRouteViewStyleCallback*> m_styleChangedCallbacks;
            
            typedef std::vector<View::IRouteViewStyleCallback*>::iterator TCallbackIter;
            
            void FireCallbacks(std::vector<View::IRouteViewStyleCallback*>& callbacks, const Route* route, const Style::RouteStyle& routeStyle);
            void InsertCallback(std::vector<View::IRouteViewStyleCallback*>& callbacks, View::IRouteViewStyleCallback* callback);
            void RemoveCallback(std::vector<View::IRouteViewStyleCallback*>& callbacks, View::IRouteViewStyleCallback* callback);
        public:
            void AddRouteStyleMapping(const Route* pRoute, Style::RouteStyle routeStyle);
            void SetRouteStyleMapping(const Route* pRoute, Style::RouteStyle routeStyle);
            void RemoveRouteStyleMapping(const Route* pRoute);
            
            bool HasStyleForRoute(const Route* route) const;
            Style::RouteStyle GetStyleForRoute(const Route* route) const;
            bool IsEmpty() const;
            
            void RegisterStyleChangedCallback(View::IRouteViewStyleCallback* callback);
            void UnregisterStyleChangedCallback(View::IRouteViewStyleCallback* callback);
        };
    }
}
