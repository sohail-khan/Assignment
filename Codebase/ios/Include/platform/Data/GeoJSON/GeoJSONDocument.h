//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "GeoJSONObject.h"
#include "document.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class GeoJSONDocument : Eegeo::NonCopyable
            {
            public:
                GeoJSONDocument(const std::string& document);
                GeoJSONObject Parse();
            private:
                bool m_parsed;
                std::string m_documentStr;
                rapidjson::Document m_document;
            };
        }
    }
}