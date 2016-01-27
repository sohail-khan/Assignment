// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace WorldStates
    {
        class IChangeStateCallback
        {
        public:
            virtual void operator()() = 0;
        };
        
        template <typename T> class TChangeStateCallback : public IChangeStateCallback
        {
        private:
            void (T::*m_callback)();
            T* m_context;
        
        public:
            
            TChangeStateCallback(T* context, void (T::*callback)())
            : m_context(context)
            , m_callback(callback)
            {
                
            }
            void operator()()
            {
                (*m_context.*m_callback)();
            }
        };
    }
}