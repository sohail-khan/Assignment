// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IPlatformAbstractionModule.h"
#include "OSXUrlEncoder.h"
#include "OSXFileIO.h"
#include "Helpers.h"
#include "OSXTextureFileLoader.h"
#include "Web.h"
#include "Tasks.h"
#include "OSXGlTaskContextFactory.h"
#include "Rendering.h"
#include "IJpegLoader.h"
#include "Web.h"
#include "OSXConnectivityService.h"
#import <OpenGL/OpenGL.h>
#import <Cocoa/Cocoa.h>

namespace Eegeo
{
    namespace OSX
    {
        class OSXPlatformAbstractionModule : public Modules::IPlatformAbstractionModule, protected Eegeo::NonCopyable
        {
        public:
            OSXPlatformAbstractionModule(Helpers::Jpeg::IJpegLoader& jpegLoader,
                                         NSOpenGLPixelFormat* pPixelFormat,
                                         const std::string& resourcePath,
                                         const std::string& apiKey);
            
            ~OSXPlatformAbstractionModule();
            
            Helpers::ITextureFileLoader& GetTextureFileLoader() const;
            Web::IWebLoadRequestFactory& GetWebLoadRequestFactory() const;
            Web::IWebLoadRequestFactory& GetPlatformWebLoadRequestFactory() const { return *m_pPlatformWebLoadRequestFactory; }
            Web::IWebProxySettings& GetProxySettings() const;
            Helpers::IHttpCache& GetHttpCache() const;
            Helpers::IFileIO& GetFileIO() const;
            Helpers::UrlHelpers::IUrlEncoder& GetUrlEncoder() const;
            Concurrency::Tasks::IGlTaskContextFactory& GetGlTaskContextFactory() const;
            Eegeo::Web::IConnectivityService& GetConnectivityService() const;
            
            void SetWebIOWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool);
            
            void OnPause();
            void Update();
            void OnResume();
            
        private:
            OSXUrlEncoder* m_pOSXUrlEncoder;
            Helpers::IFileIO* m_pOSXFileIO;
            Helpers::IHttpCache* m_pOSXHttpCache;
            OSX::OSXTextureFileLoader* m_pOSXTextureFileLoader;
            Web::WebModule* m_pWebModule;
            Web::IWebLoadRequestFactory* m_pPlatformWebLoadRequestFactory;
            OSX::OSXGlTaskContextFactory* m_pOSXGlTaskContextFactory;
            OSX::OSXConnectivityService* m_pOSXConnectivityService;
        };
    }
}

