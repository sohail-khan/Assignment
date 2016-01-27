// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include <set>

#include "Types.h"
#include "IPlatformAbstractionModule.h"
#include "Cache.h"
#include "WindowsUrlEncoder.h"
#include "WindowsFileIO.h"
#include "WindowsGlTaskContextFactory.h"
#include "Web.h"
#include "WindowsTextureFileLoader.h"
#include "WindowsCacheFileIO.h"
#include "WindowsConnectivityService.h"
#include "Rendering.h"
#include "IWorkPool.h"
#include "Web.h"

namespace Eegeo
{
	namespace Windows
	{
		class WindowsPlatformAbstractionModule : public Modules::IPlatformAbstractionModule
		{
		public:
			WindowsPlatformAbstractionModule(WindowsNativeState& nativeState,
			                                 Helpers::Jpeg::IJpegLoader& jpegLoader,
			                                 EGLDisplay& display,
			                                 EGLContext& context,
			                                 EGLSurface& surface,
                                             const std::string& apiKey,
			                                 const std::set<std::string>& customDirectoryPaths=std::set<std::string>());

			~WindowsPlatformAbstractionModule();

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

			Windows::WindowsUrlEncoder& GetWindowsUrlEncoder() const;
			Web::IWebLoadRequestFactory& GetWindowsWebLoadRequestFactory() const;
			Web::Cache::HttpCache& GetWindowsHttpCache() const;
			Windows::WindowsFileIO& GetWindowsFileIO() const;
			Windows::WindowsTextureFileLoader& GetWindowsTextureFileLoader() const;
			Windows::WindowsGlTaskContextFactory& GetWindowsGlTaskContextFactory() const;
			Windows::WindowsCacheFileIO& GetWindowsCacheFileIO() const;

			Web::WebRequestService& GetWebRequestService() const;

			void UpdateSurface(EGLSurface& surface);
			void ReloadHttpCacheRepresentationFromStorage();
			void SetWebIOWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool);

		private:
			Windows::WindowsUrlEncoder* m_pWindowsUrlEncoder;
			Web::WebModule* m_pWebModule;
			Web::Cache::HttpCache* m_pWindowsHttpCache;
			Windows::WindowsFileIO* m_pWindowsFileIO;
			Windows::WindowsTextureFileLoader* m_pWindowsTextureFileLoader;
			Windows::WindowsGlTaskContextFactory* m_pWindowsGlTaskContextFactory;
			Web::IWebLoadRequestFactory* m_pPlatformWebLoadRequestFactory;
			Windows::WindowsConnectivityService* m_pWindowsConnectivityService;

			Windows::WindowsCacheFileIO* m_pWindowsCacheFileIO;
		};
	}
}
