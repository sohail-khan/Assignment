// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#if defined (ANDROID)
    #define EEGEO_DROID
    //#define EEGEO_DROID_EMULATOR
#elif defined (__APPLE__)
    #include "TargetConditionals.h"
    #if defined(TARGET_OS_IPHONE) && (TARGET_OS_IPHONE == 1)
        #define EEGEO_IOS
    #else
        #define EEGEO_OSX
    #endif
#elif defined (_MSC_VER)
	#define EEGEO_WIN
#endif