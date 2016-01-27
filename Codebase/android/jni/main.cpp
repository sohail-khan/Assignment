// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include <jni.h>
#include "AppRunner.h"
#include "main.h"
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <pthread.h>

using namespace Eegeo::Android;
using namespace Eegeo::Android::Input;

const std::string ApiKey = "OBTAIN API_KEY FROM https://www.eegeo.com/developers/ AND INSERT IT HERE";

AndroidNativeState g_nativeState;
AppRunner* g_pAppRunner;

namespace
{
void FillEventFromJniData(
    JNIEnv* jenv,
    jint primaryActionIndex,
    jint primaryActionIdentifier,
    jint numPointers,
    jfloatArray x,
    jfloatArray y,
    jintArray pointerIdentity,
    jintArray pointerIndex,
    TouchInputEvent& event);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* pvt)
{
	g_nativeState.vm = vm;
	return JNI_VERSION_1_6;
}

//lifecycle
JNIEXPORT long JNICALL Java_com_eegeo_mobilesdkharness_NativeJniCalls_createNativeCode(JNIEnv* jenv, jobject obj, jobject activity, jobject assetManager, jfloat dpi)
{
	Eegeo_TTY("startNativeCode\n");

	g_nativeState.javaMainThread = pthread_self();
	g_nativeState.mainThreadEnv = jenv;
	g_nativeState.activity = jenv->NewGlobalRef(activity);
	g_nativeState.activityClass = (jclass)jenv->NewGlobalRef(jenv->FindClass("com/eegeo/mobilesdkharness/MainActivity"));
	g_nativeState.deviceDpi = dpi;

	jmethodID getClassLoader = jenv->GetMethodID(g_nativeState.activityClass,"getClassLoader", "()Ljava/lang/ClassLoader;");
	g_nativeState.classLoader = jenv->NewGlobalRef(jenv->CallObjectMethod(activity, getClassLoader));
	g_nativeState.classLoaderClass  = (jclass)jenv->NewGlobalRef(jenv->FindClass("java/lang/ClassLoader"));
	g_nativeState.classLoaderLoadClassMethod = jenv->GetMethodID(g_nativeState.classLoaderClass, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");

	g_nativeState.DetermineDeviceModel(jenv);

	jthrowable exc;
	exc = jenv->ExceptionOccurred();

	if (exc)
	{
		jenv->ExceptionDescribe();
		jenv->ExceptionClear();
		return 0;
	}

	g_nativeState.assetManagerGlobalRef = jenv->NewGlobalRef(assetManager);
	g_nativeState.assetManager = AAssetManager_fromJava(jenv, g_nativeState.assetManagerGlobalRef);

	g_pAppRunner = Eegeo_NEW(AppRunner)(ApiKey, &g_nativeState);

	return ((long)g_pAppRunner);
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_NativeJniCalls_destroyNativeCode(JNIEnv* jenv, jobject obj)
{
	Eegeo_TTY("stopNativeCode()\n");

	delete g_pAppRunner;
	g_pAppRunner = NULL;

	jenv->DeleteGlobalRef(g_nativeState.assetManagerGlobalRef);
	jenv->DeleteGlobalRef(g_nativeState.activity);
	jenv->DeleteGlobalRef(g_nativeState.activityClass);
	jenv->DeleteGlobalRef(g_nativeState.classLoaderClass);
	jenv->DeleteGlobalRef(g_nativeState.classLoader);
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_NativeJniCalls_pauseNativeCode(JNIEnv* jenv, jobject obj)
{
	g_pAppRunner->Pause();
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_NativeJniCalls_resumeNativeCode(JNIEnv* jenv, jobject obj)
{
	g_pAppRunner->Resume();
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_NativeJniCalls_updateNativeCode(JNIEnv* jenv, jobject obj, jfloat deltaSeconds)
{
	g_pAppRunner->Update((float)deltaSeconds);
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_NativeJniCalls_setNativeSurface(JNIEnv* jenv, jobject obj, jobject surface)
{
	if(g_nativeState.window != NULL)
	{
		ANativeWindow_release(g_nativeState.window);
		g_nativeState.window = NULL;
	}

	if (surface != NULL)
	{
		g_nativeState.window = ANativeWindow_fromSurface(jenv, surface);

		if (g_nativeState.window != NULL)
		{
			g_pAppRunner->ActivateSurface();
		}
	}
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_EegeoSurfaceView_processNativePointerDown(JNIEnv* jenv, jobject obj,
        jint primaryActionIndex,
        jint primaryActionIdentifier,
        jint numPointers,
        jfloatArray x,
        jfloatArray y,
        jintArray pointerIdentity,
        jintArray pointerIndex)
{
	TouchInputEvent event(false, true, primaryActionIndex, primaryActionIdentifier);
	FillEventFromJniData(jenv, primaryActionIndex, primaryActionIdentifier, numPointers, x, y, pointerIdentity, pointerIndex, event);
	g_pAppRunner->HandleTouchEvent(event);
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_EegeoSurfaceView_processNativePointerUp(JNIEnv* jenv, jobject obj,
        jint primaryActionIndex,
        jint primaryActionIdentifier,
        jint numPointers,
        jfloatArray x,
        jfloatArray y,
        jintArray pointerIdentity,
        jintArray pointerIndex)
{
	TouchInputEvent event(true, false, primaryActionIndex, primaryActionIdentifier);
	FillEventFromJniData(jenv, primaryActionIndex, primaryActionIdentifier, numPointers, x, y, pointerIdentity, pointerIndex, event);
	g_pAppRunner->HandleTouchEvent(event);
}

JNIEXPORT void JNICALL Java_com_eegeo_mobilesdkharness_EegeoSurfaceView_processNativePointerMove(JNIEnv* jenv, jobject obj,
        jint primaryActionIndex,
        jint primaryActionIdentifier,
        jint numPointers,
        jfloatArray x,
        jfloatArray y,
        jintArray pointerIdentity,
        jintArray pointerIndex)
{
	TouchInputEvent event(false, false, primaryActionIndex, primaryActionIdentifier);
	FillEventFromJniData(jenv, primaryActionIndex, primaryActionIdentifier, numPointers, x, y, pointerIdentity, pointerIndex, event);
	g_pAppRunner->HandleTouchEvent(event);
}

namespace
{
void FillEventFromJniData(
    JNIEnv* jenv,
    jint primaryActionIndex,
    jint primaryActionIdentifier,
    jint numPointers,
    jfloatArray x,
    jfloatArray y,
    jintArray pointerIdentity,
    jintArray pointerIndex,
    TouchInputEvent& event)
{
	jfloat* xBuffer = jenv->GetFloatArrayElements(x, 0);
	jfloat* yBuffer = jenv->GetFloatArrayElements(y, 0);
	jint* identityBuffer = jenv->GetIntArrayElements(pointerIdentity, 0);
	jint* indexBuffer = jenv->GetIntArrayElements(pointerIndex, 0);

	for(int i = 0; i < numPointers; ++ i)
	{
		TouchInputPointerEvent p(xBuffer[i], yBuffer[i], identityBuffer[i], indexBuffer[i]);
		event.pointerEvents.push_back(p);
	}

	jenv->ReleaseFloatArrayElements(x, xBuffer, 0);
	jenv->ReleaseFloatArrayElements(y, yBuffer, 0);
	jenv->ReleaseIntArrayElements(pointerIdentity, identityBuffer, 0);
	jenv->ReleaseIntArrayElements(pointerIndex, indexBuffer, 0);
}
}
