// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include "Web.h"
#include "Tasks.h"
#include "Concurrency.h"
#include "Rendering.h"
#include "IPlatformAbstractionModule.h"

#include "AndroidUrlEncoder.h"
#include "AndroidFileIO.h"
#include "AndroidGlTaskContextFactory.h"
#include "AndroidTextureFileLoader.h"
#include "AndroidCacheFileIO.h"
#include "AndroidConnectivityService.h"
#include "Rendering.h"
#include "IWorkPool.h"

#include <string>
#include <set>
#include <EGL/egl.h>


namespace Eegeo
{
	namespace Android
	{
		class AndroidPlatformAbstractionModule : public Modules::IPlatformAbstractionModule
		{
		public:
			AndroidPlatformAbstractionModule(AndroidNativeState& nativeState,
			                                 Helpers::Jpeg::IJpegLoader& jpegLoader,
			                                 EGLDisplay& display,
			                                 EGLContext& context,
			                                 EGLSurface& surface,
                                             const std::string& apiKey,
			                                 const std::set<std::string>& customDirectoryPaths=std::set<std::string>());

			~AndroidPlatformAbstractionModule();

			Helpers::ITextureFileLoader& GetTextureFileLoader() const;
			Web::IWebLoadRequestFactory& GetWebLoadRequestFactory() const;
			Web::IWebLoadRequestFactory& GetPlatformWebLoadRequestFactory() const;
            Web::IWebProxySettings& GetProxySettings() const;
			Helpers::IHttpCache& GetHttpCache() const;
			Helpers::IFileIO& GetFileIO() const;
			Helpers::UrlHelpers::IUrlEncoder& GetUrlEncoder() const;
			Concurrency::Tasks::IGlTaskContextFactory& GetGlTaskContextFactory() const;
			Eegeo::Web::IConnectivityService& GetConnectivityService() const;

			void OnPause();
			void OnResume();
			void Update();

			Android::AndroidUrlEncoder& GetAndroidUrlEncoder() const;
			Web::IWebLoadRequestFactory& GetAndroidWebLoadRequestFactory() const;
			Helpers::IHttpCache& GetAndroidHttpCache() const;
			Helpers::IFileIO& GetAndroidFileIO() const;
			Android::AndroidTextureFileLoader& GetAndroidTextureFileLoader() const;
			Android::AndroidGlTaskContextFactory& GetAndroidGlTaskContextFactory() const;
			Android::AndroidCacheFileIO& GetAndroidCacheFileIO() const;

			void UpdateSurface(EGLSurface& surface);
			void ReloadHttpCacheRepresentationFromStorage();
			void SetWebIOWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool);

		private:
			Android::AndroidUrlEncoder* m_pAndroidUrlEncoder;
			Android::AndroidFileIO* m_pAndroidFileIO;
			Helpers::IHttpCache* m_pAndroidHttpCache;
			Android::AndroidCacheFileIO* m_pAndroidCacheFileIO;
			Android::AndroidTextureFileLoader* m_pAndroidTextureFileLoader;
			Web::WebModule* m_pWebModule;
			Android::AndroidGlTaskContextFactory* m_pAndroidGlTaskContextFactory;
			Web::IWebLoadRequestFactory* m_pPlatformWebLoadRequestFactory;
			Android::AndroidConnectivityService* m_pAndroidConnectivityService;
		};
	}
}
