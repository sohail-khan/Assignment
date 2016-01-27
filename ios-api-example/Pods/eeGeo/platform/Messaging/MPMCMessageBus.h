//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "CatalogBinding.h"
#include "MessageQueue.h"

namespace Eegeo
{
    namespace Messaging
    {
        template <typename TMessageCatalog>
        class MPMCMessageBus
        {
        private:
            TMessageCatalog m_catalog;
            
            class MessageInfo
            {
            public:
                virtual ~MessageInfo() {};
                virtual void Dispatch() = 0;
            };
            
            template <typename TMessage>
            class TypedMessageInfo : public MessageInfo
            {
            private:
                TMessage m_message;
                TMessageCatalog& m_catalog;
            public:
                TypedMessageInfo(const TMessage& message,
                                 TMessageCatalog& catalog)
                : m_message(message)
                , m_catalog(catalog)
                {
                }
                
                void Dispatch()
                {
                    CatalogBinding<TMessage>& binding(m_catalog);
                    binding.Dispatch(m_message);
                }
            };
            
            MessageQueue<MessageInfo*> m_messages;
            
        public:
            template <typename TMessage>
            void Publish(const TMessage& message)
            {
                m_messages.Enqueue(new TypedMessageInfo<TMessage>(message, m_catalog));
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
            
            void Flush()
            {
                MessageInfo* info;
                while (m_messages.TryDequeue(info))
                {
                    info->Dispatch();
                    delete info;
                }
            }
        };
    }
}
