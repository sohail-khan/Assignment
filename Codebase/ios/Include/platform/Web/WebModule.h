// Copyright eeGeo Ltd (2012-2015), All Rights Reserved
#pragma once
#include "Types.h"
#include "Concurrency.h"
#include "Tasks.h"
#include "Helpers.h"
#include "BidirectionalWebIOBus.h"
#include "Web.h"
#include "UrlHelpers.h"

namespace Eegeo
{
    namespace Web
    {
        class WebModule: protected Eegeo::NonCopyable
        {
        public:

            static WebModule* Create(Helpers::IFileIO& cacheFileIO,
                                    Helpers::IHttpCache& httpCache,
                                    WebIOConfig& webIOConfig,
                                    Helpers::UrlHelpers::IUrlEncoder& encoder);
            
            ~WebModule();
            
            WebRequestService& GetWebRequestService();
            
            IWebLoadRequestFactory& GetWebLoadRequestFactory();
            
            IWebProxySettings& GetWebProxySettings();
            
            void OnPause();
            void Update();
            void OnResume();
            
            void SetWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool);
            
            
            
        private:
            WebModule(Helpers::IHttpCache& httpCache,
                      TMessageBus* pWebMessageBus,
                      WebRequestServiceBackendRunner* pWebRequestServiceBackendRunner,
                      Concurrency::Thread* pWebRequestServiceBackendThread,
                      WebRequestService* pWebRequestService,
                      IWebLoadRequestFactory* pWebRequestFactory,
                      IWebProxySettings* pWebProxySettings);
            
            Helpers::IHttpCache& m_httpCache;
            TMessageBus* m_pWebMessageBus;
            WebRequestServiceBackendRunner* m_pWebRequestServiceBackendRunner;
            Concurrency::Thread* m_pWebRequestServiceBackendThread;
            WebRequestService* m_pWebRequestService;
            IWebLoadRequestFactory* m_pWebRequestFactory;
            IWebProxySettings* m_pWebProxySettings;
        };
    }
}