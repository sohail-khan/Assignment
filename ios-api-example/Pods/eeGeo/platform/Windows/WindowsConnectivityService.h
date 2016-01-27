// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

//#include <jni.h>
#include "IConnectivityService.h"
#include "CallbackCollection.h"

struct WindowsNativeState;

namespace Eegeo
{
	namespace Windows
	{
		class WindowsConnectivityService : public Web::IConnectivityService
		{
		public:
			WindowsConnectivityService(WindowsNativeState* pState);
            ~WindowsConnectivityService();

            bool HasConnectivity();
            Web::ConnectivityType GetConnectivityType();
            void SetConnectivityType(int connectivityType);

            void RegisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback);
            void UnregisterConnectivityChangedCallback(Helpers::ICallback1<const bool&>& callback);

		private:
            WindowsNativeState* m_pNativeState;

            //jclass m_networkChangeReceiverClass;
            //jobject m_networkChangeReceiverInstance;

            //jclass m_networkChangeReceiverRegistrationServiceClass;
            //jobject m_networkChangeReceiverRegistrationServiceInstance;

            bool m_hasConnectivity;
            int m_connectivityType;

            Eegeo::Helpers::CallbackCollection1<const bool&> m_callbacks;

            void SetHasConnectivity(bool hasConnectivity);
            void GetInitialConnectivity();
		};
	}
}

//extern "C"
//{
//	JNIEXPORT void JNICALL Java_com_eegeo_web_ConnectivityServiceJniMethods_SetConnectivityType(
//	    JNIEnv* jenv, jobject obj,
//	    jlong nativeObjectPtr,
//	    jint connectivityType);
//}
