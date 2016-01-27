// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRunnable.h"
#include "Web.h"
#include "BidirectionalWebIOBus.h"
#include "WebIOConfig.h"

namespace Eegeo
{
    namespace Web
    {
        class WebRequestServiceBackendRunner: public Eegeo::Concurrency::IRunnable, private Eegeo::NonCopyable
        {
        public:
            WebRequestServiceBackendRunner(const WebIOConfig& webIOConfig,
                                           TMessageBus& webMessageBus);
            
            bool operator()();
            void OnStarted();
            void OnStopped();
            
        private:
            const WebIOConfig m_webIOConfig;
            TMessageBus& m_webMessageBus;
            
            WebRequestServiceBackend* m_pWebRequestServiceBackend;
        };
    }
}