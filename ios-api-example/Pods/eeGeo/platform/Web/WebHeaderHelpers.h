// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "IWebLoadRequest.h"
#include <string>
#include <map>

namespace Eegeo
{
    namespace Web
    {
        namespace MIMETypes
        {
            const std::string ApplicationOctetStream = "application/octet-stream";
            const std::string BinaryOctetStream = "binary/octet-stream";
            const std::string PlainText = "text/plain";
            const std::string Png = "image/png";
            const std::string XPng = "image/x-png";
        }
        
        namespace WebHeaderHelpers
        {
            void ParseHeaderDataToMap(const TResourceData& headerData, std::map<std::string, std::string>& out_map);
        }
    }
}
