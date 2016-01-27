// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include <string>

namespace Eegeo
{
    namespace Web
    {
        class IWebProxySettings
        {
        public:
            
            virtual ~IWebProxySettings() {}
            
            virtual void EnableProxy(const std::string& ipAddress, int port) = 0;
            virtual void DisableProxy() = 0;
            
            virtual const bool ProxyEnabled() const = 0;
            virtual const std::string& ProxyIpAddress() const = 0;
            virtual const int ProxyPort() const = 0;
        };
    }
}