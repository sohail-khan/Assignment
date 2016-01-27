//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include <algorithm>
#include <vector>
#include "ICallback.h"

namespace Eegeo
{
    namespace Messaging
    {
        template <typename TMessage>
        class CatalogBinding
        {
        private:
            typedef std::vector<Eegeo::Helpers::ICallback1<const TMessage&>* > TSubscribers;
            TSubscribers m_subscribers;
            
        public:
            void Subscribe(Eegeo::Helpers::ICallback1<const TMessage&>& subscription)
            {
                m_subscribers.push_back(&subscription);
            }
            
            void Unsubscribe(Eegeo::Helpers::ICallback1<const TMessage&>& subscription)
            {
                m_subscribers.erase(std::find(m_subscribers.begin(), m_subscribers.end(), &subscription));
            }
            
            void Dispatch(const TMessage& message)
            {
                for (typename TSubscribers::iterator it = m_subscribers.begin();
                     it != m_subscribers.end();
                     ++it)
                {
                    Eegeo::Helpers::ICallback1<const TMessage&>& func = *(*it);
                    func(message);
                }
            }
        };
    }
}