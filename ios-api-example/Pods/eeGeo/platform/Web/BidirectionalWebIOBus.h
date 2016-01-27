//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "CatalogBinding.h"
#include "MessageQueue.h"
#include "DispatchQueue.h"
#include "MainToWebIOMessageCatalog.h"
#include "WebIOToMainMessageCatalog.h"

namespace Eegeo
{
    namespace Web
    {
        struct TDefaultBusCatalogs
        {
            typedef Eegeo::Web::MainToWebIOMessageCatalog TDispatchToWebIOMessageCatalog;
            typedef Eegeo::Web::WebIOToMainMessageCatalog TDispatchToMainMessageCatalog;
        };

        template <typename TBusCatalogs = TDefaultBusCatalogs>
        class BidirectionalBus : private Eegeo::NonCopyable
        {
        private:
            typedef typename TBusCatalogs::TDispatchToWebIOMessageCatalog TDispatchToWebIOMessageCatalog;
            typedef typename TBusCatalogs::TDispatchToMainMessageCatalog TDispatchToMainMessageCatalog;

            Eegeo::Messaging::DispatchQueue<TDispatchToWebIOMessageCatalog> m_dispatchToWebIOQueue;
            Eegeo::Messaging::DispatchQueue<TDispatchToMainMessageCatalog> m_dispatchToMainQueue;

        public:

            template <typename TMessage>
            void Publish(const TMessage& message)
            {
                m_dispatchToWebIOQueue.TryEnqueue(message);
                m_dispatchToMainQueue.TryEnqueue(message);
            }

            template <typename TMessage>
            void SubscribeOnWebIO(Eegeo::Helpers::ICallback1<const TMessage&>& handler)
            {
                m_dispatchToWebIOQueue.Subscribe(handler);
            }

            template <typename TMessage>
            void UnsubscribeOnWebIO(Eegeo::Helpers::ICallback1<const TMessage&>& handler)
            {
                m_dispatchToWebIOQueue.Unsubscribe(handler);
            }

            template <typename TMessage>
            void SubscribeOnMain(Eegeo::Helpers::ICallback1<const TMessage&>& handler)
            {
                m_dispatchToMainQueue.Subscribe(handler);
            }

            template <typename TMessage>
            void UnsubscribeOnMain(Eegeo::Helpers::ICallback1<const TMessage&>& handler)
            {
                m_dispatchToMainQueue.Unsubscribe(handler);
            }

            void FlushToWebIO()
            {
                m_dispatchToWebIOQueue.Flush();
            }

            void FlushToMain()
            {
                m_dispatchToMainQueue.Flush();
            }
        };

        typedef BidirectionalBus<> TMessageBus;
    }
}