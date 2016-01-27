// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IPlatformConfigBuilder.h"
#include "Types.h"

namespace Eegeo {
	namespace iOS {

		class iOSPlatformConfigBuilder: public Config::IPlatformConfigBuilder
		{
        public:
    
            iOSPlatformConfigBuilder(u32 deviceTypeId, bool isMultiCore, int iOSMajorVersion = 0)
            : m_deviceTypeId(deviceTypeId)
            , m_isMultiCore(isMultiCore)
            , m_iOSMajorVersion(iOSMajorVersion)
            {}
            
            Config::PlatformConfig Build();
            
        private:

            u32 m_deviceTypeId;
            bool m_isMultiCore;
            int m_iOSMajorVersion;
		};

	}
}

