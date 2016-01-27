// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class ICommandCallback
            {
            public:
                virtual void operator()() = 0;
            };
            
            template <class T> class TCommandCallback : public ICommandCallback
            {
            private:
                void (T::*m_callback)();
                T* m_context;
            public:
                TCommandCallback(T* context, void (T::*callback)())
                : m_context(context)
                , m_callback(callback)
                {
                }
                
                virtual void operator()()
                {
                    (*m_context.*m_callback)();
                }
            };
        }
    }
}