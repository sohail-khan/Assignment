// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include <string>

namespace Eegeo
{
    namespace Streaming
    {
        extern const std::string CoverageTreePrefix;
        
        std::string FromMortonKey(const MortonKey &key,
                                  const std::string &serverBaseUrl,
                                  const std::string &storePrefix,
                                  const std::string &featureRelativePath,
                                  const std::string &resourceName,
                                  const std::string &resourceExtension);
        
        std::string CoverageTreeUrl(
                                    const std::string &serverBaseUrl,
                                    const std::string &storePrefix,
                                    const std::string &resourceName
                                    );
    }
}
