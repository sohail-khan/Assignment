// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once
#include "Types.h"
#include "IConnectivityService.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace OSX
    {
        class OSXConnectivityService: public Web::IConnectivityService, private Eegeo::NonCopyable
        {
        public:
            OSXConnectivityService();
            
            bool HasConnectivity();
            Web::ConnectivityType GetConnectivityType();
            
            void RegisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback);
            void UnregisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback);
            
        private:
            Eegeo::Helpers::CallbackCollection1<const bool&> m_callbacks;
            Web::ConnectivityType m_connectivityType;
            bool m_hasConnectivity;
        };
    }
}