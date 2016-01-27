// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class IFittedRouteCallback
            {
            public:
                virtual void operator()(const FittedRoute& fittedRoute) = 0;
            };
            
            template <class T> class TFittedRouteCallback : public IFittedRouteCallback
            {
            private:
                void (T::*m_callback)(const FittedRoute& fittedRoute);
                T* m_context;
            public:
                TFittedRouteCallback(T* context, void (T::*callback)(const FittedRoute& fittedRoute))
                : m_context(context)
                , m_callback(callback)
                {
                }
                
                virtual void operator()(const FittedRoute& fittedRoute)
                {
                    (*m_context.*m_callback)(fittedRoute);
                }
            };
        }
    }
}
