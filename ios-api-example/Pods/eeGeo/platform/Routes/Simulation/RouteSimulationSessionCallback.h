// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class IRouteSimulationSessionCallback
            {
            public:
                virtual void operator()(const RouteSimulationSession* session) = 0;
            };
            
            template <class T> class TRouteSimulationSessionCallback : public IRouteSimulationSessionCallback
            {
            private:
                void (T::*m_callback)(const RouteSimulationSession* session);
                T* m_context;
            public:
                TRouteSimulationSessionCallback(T* context, void (T::*callback)(const RouteSimulationSession* session))
                : m_callback(callback)
                , m_context(context)
                {
                    
                }
                
                virtual void operator()(const RouteSimulationSession* session)
                {
                    (*m_context.*m_callback)(session);
                }
            };
        }
    }
}