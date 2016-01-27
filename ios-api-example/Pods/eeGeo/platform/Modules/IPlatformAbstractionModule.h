// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include "Web.h"
#include "UrlHelpers.h"
#include "Location.h"
#include "IGlTaskContextFactory.h"
#include "IConnectivityService.h"
#include "IWorkPool.h"

namespace Eegeo
{
    namespace Modules
    {
        class IPlatformAbstractionModule
        {
        public:
            virtual ~IPlatformAbstractionModule() {}
            virtual Helpers::ITextureFileLoader& GetTextureFileLoader() const = 0;
            virtual Web::IWebLoadRequestFactory& GetWebLoadRequestFactory() const = 0;
            virtual Web::IWebLoadRequestFactory& GetPlatformWebLoadRequestFactory() const = 0;
            virtual Web::IWebProxySettings& GetProxySettings() const = 0;
            virtual Helpers::IHttpCache& GetHttpCache() const = 0;
            virtual Helpers::IFileIO& GetFileIO() const = 0;
            virtual Helpers::UrlHelpers::IUrlEncoder& GetUrlEncoder() const = 0;
            virtual Concurrency::Tasks::IGlTaskContextFactory& GetGlTaskContextFactory() const = 0;
            virtual Eegeo::Web::IConnectivityService& GetConnectivityService() const = 0;
            
            virtual void SetWebIOWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool) = 0;
            
            virtual void OnPause() = 0;
            virtual void Update() = 0;
            virtual void OnResume(){}
        };
    }
}