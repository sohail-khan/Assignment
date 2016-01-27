//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "CatalogBinding.h"
#include "Types.h"

namespace Eegeo
{
    namespace Messaging
    {
        template <typename TMessageCatalog>
        class ImmediateMessageBus : private Eegeo::NonCopyable
        {
        private:
            TMessageCatalog m_catalog;
            
        public:
            template <typename TMessage>
            void Publish(const TMessage& message)
            {
                CatalogBinding<TMessage>& binding(m_catalog);
                binding.Dispatch(message);
            }
            
            template <typename TMessage>
            void Subscribe(Eegeo::Helpers::ICallback1<const TMessage&>& handler)
            {
                CatalogBinding<TMessage>& binding(m_catalog);
                binding.Subscribe(handler);
            }
            
            template <typename TMessage>
            void Unsubscribe(Eegeo::Helpers::ICallback1<const TMessage&>& handler)
            {
                CatalogBinding<TMessage>& binding(m_catalog);
                binding.Unsubscribe(handler);
            }
            
            void Flush() { }
        };
    }
}