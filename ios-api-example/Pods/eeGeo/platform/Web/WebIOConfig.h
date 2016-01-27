// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
	namespace Web
	{
        const int WebLoadPoolSizeDefault = 10;
        const int CacheLoadPoolSizeDefault = 40;
        const int CacheStorePoolSizeDefault = 20;

        struct WebIOConfig
        {
            static WebIOConfig CreateDefaultUsingOperatingSystemCACert()
            {
                // if libcurl was compiled for a given platform's native SSL (e.g. iOS/darwinSSL),
                // there's no need to provide a CA cert -- it will use the inbuilt OS cert.

                // http://curl.haxx.se/docs/sslcerts.html ("Certificate Verification with Schannel and Secure Transport")
                const std::string UseOperatingSystemCACert = "";
                return WebIOConfig(
                        WebLoadPoolSizeDefault, CacheLoadPoolSizeDefault, CacheStorePoolSizeDefault, UseOperatingSystemCACert);
            }

            static WebIOConfig CreateDefaultUsingCustomCACert(const std::string& caCertFilePath)
            {
                return WebIOConfig(
                        WebLoadPoolSizeDefault, CacheLoadPoolSizeDefault, CacheStorePoolSizeDefault, caCertFilePath);
            }

            WebIOConfig(
                    const int webLoadPoolSize,
                    const int cacheLoadPoolSize,
                    const int cacheStorePoolSize,
                    const std::string& optionalCaCertFilePath)
            : webLoadPoolSize(webLoadPoolSize),
              cacheLoadPoolSize(cacheLoadPoolSize),
              cacheStorePoolSize(cacheStorePoolSize),
              caCertFilePath(optionalCaCertFilePath)
            {

            }

            bool ShouldUseCACertFile() const
            {
                return !caCertFilePath.empty();
            }

            int webLoadPoolSize;
            int cacheLoadPoolSize;
            int cacheStorePoolSize;

            std::string caCertFilePath;
        };
	}
}
