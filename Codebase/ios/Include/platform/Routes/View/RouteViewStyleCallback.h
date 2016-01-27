// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class IRouteViewStyleCallback
            {
            public:
                virtual void operator()(const Route* route, const Style::RouteStyle& routeStyle) = 0;
            };
            
            template <class T> class TRouteViewStyleCallback : public IRouteViewStyleCallback
            {
            private:
                void (T::*m_callback)(const Route* route, const Style::RouteStyle& routeStyle);
                T* m_context;
            public:
                TRouteViewStyleCallback(T* context, void (T::*callback)(const Route* route, const Style::RouteStyle& routeStyle))
                : m_context(context)
                , m_callback(callback)
                {
                }
                
                virtual void operator()(const Route* route, const Style::RouteStyle& routeStyle)
                {
                    (*m_context.*m_callback)(route, routeStyle);
                }
            };
        }
    }
}
