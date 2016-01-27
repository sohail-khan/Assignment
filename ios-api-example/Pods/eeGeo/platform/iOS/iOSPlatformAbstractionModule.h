// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include "Web.h"
#include "Tasks.h"
#include "Concurrency.h"
#include "Rendering.h"
#include "IPlatformAbstractionModule.h"

#include "iOSUrlEncoder.h"
#include "iOSFileIO.h"
#include "iOSTextureFileLoader.h"
#include "iOSGlTaskContextFactory.h"
#include "iOSConnectivityService.h"

#include "MessageQueue.h"
#include "ITaskPoolMessage.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSPlatformAbstractionModule : public Modules::IPlatformAbstractionModule, protected Eegeo::NonCopyable
        {
        public:
            iOSPlatformAbstractionModule(Helpers::Jpeg::IJpegLoader& jpegLoader, const std::string& apiKey);

            ~iOSPlatformAbstractionModule();
            
            Helpers::ITextureFileLoader& GetTextureFileLoader() const;
            Web::IWebLoadRequestFactory& GetWebLoadRequestFactory() const;
            Web::IWebLoadRequestFactory& GetPlatformWebLoadRequestFactory() const;
            Helpers::IHttpCache& GetHttpCache() const;
            Helpers::IFileIO& GetFileIO() const;
            Helpers::UrlHelpers::IUrlEncoder& GetUrlEncoder() const;
            Concurrency::Tasks::IGlTaskContextFactory& GetGlTaskContextFactory() const;

            iOS::iOSTextureFileLoader& GetiOSTextureFileLoader() const;
            Web::IWebLoadRequestFactory& GetiOSWebLoadRequestFactory() const;
            Web::WebRequestService& GetiOSWebRequestService() const;
            Web::IWebProxySettings& GetProxySettings() const;
            Eegeo::Helpers::IHttpCache& GetiOSHttpCache() const;
            iOS::iOSFileIO& GetiOSFileIO() const;
            iOSUrlEncoder& GetiOSUrlEncoder() const;
            iOS::iOSGlTaskContextFactory& GetiOSGlTaskContextFactory() const;
            Eegeo::Web::IConnectivityService& GetConnectivityService() const;

            void SetWebIOWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool);

            void OnPause();
            void OnResume();
            void Update();
            
        private:
            iOSUrlEncoder* m_piOSUrlEncoder;
            iOS::iOSFileIO* m_piOSFileIO;
            Helpers::IHttpCache* m_piOSHttpCache;
            iOS::iOSTextureFileLoader* m_piOSTextureFileLoader;
            Web::WebModule* m_pWebModule;
            Web::IWebLoadRequestFactory* m_pPlatformWebLoadRequestFactory;
            iOS::iOSGlTaskContextFactory* m_piOSGlTaskContextFactory;
            iOS::iOSConnectivityService* m_piOSConnectivityService;
            
            Messaging::MessageQueue<Concurrency::Tasks::Messages::ITaskMessage*> m_workerMessageQueue;
            Messaging::MessageQueue<Concurrency::Tasks::Messages::ITaskPoolMessage*> m_poolMessageQueue;
            Concurrency::Tasks::TaskWorkPool* m_pGeneralWorkPool;
        };
    }
}