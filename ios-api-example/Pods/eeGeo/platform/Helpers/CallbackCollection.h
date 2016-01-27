// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <algorithm>
#include <set>
#include "Types.h"
#include "ICallback.h"

namespace Eegeo
{
    namespace Helpers
    {
        template <typename TCallback>
        class CallbackCollectionBase
        {
        protected:
            std::set<TCallback*> m_callbacks;
            
        public:
            void AddCallback(TCallback& callback)
            {
                TCallback* pCallback = &callback;
                Eegeo_ASSERT(std::find(m_callbacks.begin(), m_callbacks.end(), pCallback) == m_callbacks.end());
                m_callbacks.insert(pCallback);
            }
            
            void RemoveCallback(TCallback& callback)
            {
                TCallback* pCallback = &callback;
                Eegeo_ASSERT(std::find(m_callbacks.begin(), m_callbacks.end(), pCallback) != m_callbacks.end());
                m_callbacks.erase(pCallback);
            }
        };
        
        class CallbackCollection0 : public CallbackCollectionBase<ICallback0>
        {
        public:
            void ExecuteCallbacks()
            {
                for(std::set<ICallback0*>::iterator it = this->m_callbacks.begin();
                    it != this->m_callbacks.end();
                    ++ it)
                {
                    ICallback0& callback = **it;
                    callback();
                }
            }
        };
        
        template <typename TItem>
        class CallbackCollection1 : public CallbackCollectionBase<ICallback1<TItem> >
        {
        public:
            void ExecuteCallbacks(TItem& item)
            {
                for(typename std::set<ICallback1<TItem>*>::iterator it = this->m_callbacks.begin();
                    it != this->m_callbacks.end();
                    ++ it)
                {
                    ICallback1<TItem>& callback = **it;
                    callback(item);
                }
            }
        };
        
        template <typename TItem1, typename TItem2>
        class CallbackCollection2 : public CallbackCollectionBase<ICallback2<TItem1, TItem2> >
        {
        public:
            void ExecuteCallbacks(TItem1& item1, TItem2& item2)
            {
                for(typename std::set<ICallback2<TItem1, TItem2>*>::iterator it = this->m_callbacks.begin();
                    it != this->m_callbacks.end();
                    ++ it)
                {
                    ICallback2<TItem1, TItem2>& callback = **it;
                    callback(item1, item2);
                }
            }
        };
        
        template <typename TItem1, typename TItem2, typename TItem3>
        class CallbackCollection3 : public CallbackCollectionBase<ICallback3<TItem1, TItem2, TItem3> >
        {
        public:
            void ExecuteCallbacks(TItem1& item1, TItem2& item2, TItem3& item3)
            {
                for(typename std::set<ICallback3<TItem1, TItem2, TItem3>*>::iterator it = this->m_callbacks.begin();
                    it != this->m_callbacks.end();
                    ++ it)
                {
                    ICallback3<TItem1, TItem2, TItem3>& callback = **it;
                    callback(item1, item2, item3);
                }
            }
        };
    }
}