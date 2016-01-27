// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        class IRouteCallback
        {
        public:
            virtual void operator()(const Route* route) = 0;
        };
        
        template <class T> class TRouteCallback : public IRouteCallback
        {
        private:
            void (T::*m_callback)(const Route* route);
            T* m_context;
        public:
            TRouteCallback(T* context, void (T::*callback)(const Route* route))
            : m_callback(callback)
            , m_context(context)
            {
            }
            
            virtual void operator()(const Route* route)
            {
                (*m_context.*m_callback)(route);
            }
        };
    }
}