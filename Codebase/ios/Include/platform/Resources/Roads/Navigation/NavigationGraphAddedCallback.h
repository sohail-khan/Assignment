// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Navigation.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class INavigationGraphAddedCallback
                {
                public:
                    virtual void operator()(const NavigationGraph& navGraph) = 0;
                };
                
                template <class T> class TNavigationGraphAddedCallback : public INavigationGraphAddedCallback
                {
                private:
                    void (T::*m_callback)(const NavigationGraph& navGraph);
                    T* m_context;
                public:
                    TNavigationGraphAddedCallback(T* context, void (T::*callback)(const NavigationGraph& navGraph))
                    : m_context(context)
                    , m_callback(callback)
                    {
                    }
                    
                    virtual void operator()(const NavigationGraph& navGraph)
                    {
                        (*m_context.*m_callback)(navGraph);
                    }
                };
            }
        }
    }
}
