// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include "IWebProxySettings.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Web
    {
        class WebProxySettings : public IWebProxySettings
        {
        public:
            
            WebProxySettings();
            
            void EnableProxy(const std::string& ipAddress, int port);
            void DisableProxy();
            
            const bool ProxyEnabled() const { return m_proxyEnabled; }
            const std::string& ProxyIpAddress() const { return m_proxyIp; }
            const int ProxyPort() const { return m_proxyPort; }
            
        private:
            
            std::string m_proxyIp;
            int m_proxyPort;
            bool m_proxyEnabled;
        };
    }
}