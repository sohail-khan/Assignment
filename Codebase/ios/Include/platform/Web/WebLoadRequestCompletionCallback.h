// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Web.h"

namespace Eegeo
{
    namespace Web
    {
        // TODO: move to using ICallback1/TCallback1
        class IWebLoadRequestCompletionCallback
        {
        public:
        	virtual ~IWebLoadRequestCompletionCallback() {;}
            virtual void operator()(IWebResponse& webResponse) = 0;
        };

        template <class T> class
        TWebLoadRequestCompletionCallback : public IWebLoadRequestCompletionCallback
        {
        public:
            TWebLoadRequestCompletionCallback(T* context, void (T::*callback)(IWebResponse& webResponse))
            : m_callback(callback)
            , m_context(context)
            {
            }
            
            virtual void operator()(IWebResponse& webResponse)
            {
                (*m_context.*m_callback)(webResponse);
            }

        private:
            void (T::*m_callback)(IWebResponse& webResponse);
            T* m_context;
        };
    }
}
