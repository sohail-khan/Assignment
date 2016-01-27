// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PlatformConfig.h"
#include <string>

namespace Eegeo
{
    namespace Config
    {
        class IPlatformConfigBuilder
        {
        public:
        	virtual ~IPlatformConfigBuilder() {}

            virtual PlatformConfig Build() = 0;
        };
    }
}

