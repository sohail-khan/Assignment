// Copyright (c) 2014 eeGeo. All rights reserved.
#pragma once

#include <string>

namespace Eegeo
{
    struct AppInfo
    {
        class AppInfoBuilder
        {
        public:
            AppInfoBuilder(
                    const std::string& apiKey,
                    const std::string& platformVersionNumber,
                    const std::string& platformVersionHash);

            AppInfoBuilder& AppName(const std::string& s);
            AppInfoBuilder& UserId(const std::string& s);
            AppInfoBuilder& DeviceType(const std::string& s);
            AppInfoBuilder& OSName(const std::string& s);
            AppInfoBuilder& OSVersion(const std::string& s);
            AppInfoBuilder& Locale(const std::string& s);
            AppInfoBuilder& AppBase(const std::string& s);

            AppInfo Build();

        private:
            std::string m_appName;
            std::string m_appId;
            std::string m_platformVersionNumber;
            std::string m_platformVersionHash;
            std::string m_userId;
            std::string m_deviceType;
            std::string m_OSName;
            std::string m_OSVersion;
            std::string m_locale;
            std::string m_appBase;
        };

        std::string AppName;
        std::string AppId;
        std::string PlatformVersionNumber;
        std::string PlatformVersionHash;
        std::string UserId;
        std::string DeviceType;
        std::string OSName;
        std::string OSVersion;
        std::string Locale;
        std::string AppBase;

    private:
        // use the nested builder ctor
        AppInfo() {}
    };
}


