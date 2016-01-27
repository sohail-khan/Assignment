// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            class ISingleOptionAlertBoxDismissedHandler
            {
            public:
                virtual ~ISingleOptionAlertBoxDismissedHandler() {}
                
                virtual void HandleAlertBoxDismissed()=0;
            };
            
            template <class T>
            class TSingleOptionAlertBoxDismissedHandler : public ISingleOptionAlertBoxDismissedHandler
            {
            private:
                void (T::*m_callback)();
                T* m_context;
            public:
                TSingleOptionAlertBoxDismissedHandler(T* context, void (T::*callback)())
                : m_context(context)
                , m_callback(callback)
                {
                }
                
                virtual void HandleAlertBoxDismissed()
                {
                    (*m_context.*m_callback)();
                }
            };
        }
    }
}
