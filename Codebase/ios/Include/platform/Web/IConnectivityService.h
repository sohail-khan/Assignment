// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once
#include "ICallback.h"

namespace Eegeo
{
    namespace Web
    {
        enum ConnectivityType
        {
            Unknown,
            None,
            Wifi,
            WirelessWAN
        };
        
        class IConnectivityService
        {
        public:
            virtual ~IConnectivityService() {}
            
            virtual bool HasConnectivity() = 0;
            virtual ConnectivityType GetConnectivityType() = 0;
            
            virtual void RegisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback) = 0;
            virtual void UnregisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback) = 0;
        };
    }
}
