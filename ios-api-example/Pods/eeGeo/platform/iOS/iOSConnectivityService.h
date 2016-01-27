// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IConnectivityService.h"
#include "Reachability.h"
#include "Types.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSConnectivityService;
    }
}

@interface ConnectivityQuerier : NSObject  {
	Reachability*	reachability;
	NetworkStatus 	internetStatus;
    Eegeo::Helpers::TCallback1<Eegeo::iOS::iOSConnectivityService, const bool&> *connectivityChangedCallback;
}

- (id) initWithConnectivityCallback: (Eegeo::Helpers::TCallback1<Eegeo::iOS::iOSConnectivityService, const bool&>*) callback;
- (bool)isConnected;
- (bool)isWifi;

- (void) handleNetworkChange_Callback:(NSNotification *)notice;
@end

struct ConnectivityQuerierWrapper
{
    ConnectivityQuerier* pQuerier;
};

namespace Eegeo
{
    namespace iOS
    {
        class iOSConnectivityService : public Eegeo::Web::IConnectivityService, public Eegeo::NonCopyable
        {
        public:
            iOSConnectivityService();
            
            ~iOSConnectivityService();
            
            bool HasConnectivity();
            
            Web::ConnectivityType GetConnectivityType();

            void RegisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback);
            void UnregisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback);
            
            void SetHasConnectivity(const bool& hasConnectivity);
            
            void ForceConnectivityChangedCallback();
            
        private:
            bool m_hasConnectivity;
            ConnectivityQuerierWrapper* m_pQuerierWrapper;
            Helpers::CallbackCollection1<const bool&> m_callbacks;
            
            static void NetworkChangeCallback(CFNotificationCenterRef center, void* observer, CFStringRef name, const void *object, CFDictionaryRef userInfo);
            Eegeo::Helpers::TCallback1<iOSConnectivityService, const bool&> m_setConnectivityCallback;
        };
    }
}
