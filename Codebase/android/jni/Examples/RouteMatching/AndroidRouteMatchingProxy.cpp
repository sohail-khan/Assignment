// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "AndroidRouteMatchingProxy.h"
#include "AndroidRouteMatchingExampleView.h"

JNIEXPORT void JNICALL Java_com_eegeo_examples_routematching_RouteMatchingJniMethods_ToggleRouteMatching(
    JNIEnv* jenv, jobject obj,
    jlong nativeObjectPtr)
{
	Examples::AndroidRouteMatchingExampleView* pExample = (Examples::AndroidRouteMatchingExampleView*)(nativeObjectPtr);

	pExample->ToggleMatching();
}


