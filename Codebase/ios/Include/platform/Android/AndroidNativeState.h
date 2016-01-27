// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <string>
#include <jni.h>
#include <android/asset_manager.h>
#include <android/native_window.h>
#include <pthread.h>


struct AndroidNativeState
{
	AndroidNativeState()
	: javaMainThread(0)
	, vm(NULL)
	, mainThreadEnv(NULL)
	, assetManagerGlobalRef(NULL)
	, assetManager(NULL)
	, window(NULL)
	, activity(NULL)
	, activityClass(NULL)
	, deviceDpi(0)
	, deviceModel(NULL)
	, versionName("")
	, versionCode(0)
	, classLoader(NULL)
	, classLoaderClass(NULL)
	, classLoaderLoadClassMethod(0)
	{ }

	pthread_t javaMainThread;

	JavaVM* vm; //the global vm pointer
	JNIEnv* mainThreadEnv; //only use this from the main thread! if attaching, use the **env from the attachment method

	//cached pointers to asset manager and main window
	jobject assetManagerGlobalRef;
    AAssetManager* assetManager;
    ANativeWindow* window;

    //main entry point activity instance and class
    jobject activity;
	jclass activityClass;

	// device Dpi
	jfloat deviceDpi;

	const char* deviceModel;

	std::string versionName;
	int versionCode;

    //cached class loader descriptions - use these to load an arbitrary application class
    jobject classLoader;
	jclass classLoaderClass;
	jmethodID classLoaderLoadClassMethod;

	//assuming an attached thread, and a valid JNIEnv, this method loads an application class
	jclass LoadClass(JNIEnv* env, jstring strClassName)
	{
		return (jclass)env->CallObjectMethod(classLoader, classLoaderLoadClassMethod, strClassName);
	}

	void DetermineDeviceModel(JNIEnv* env)
	{
		jclass buildClass = env->FindClass("android/os/Build");
		jfieldID modelMethod = env->GetStaticFieldID(buildClass, "MODEL", "Ljava/lang/String;");
		jstring deviceNameString = (jstring)env->GetStaticObjectField(buildClass, modelMethod);
		deviceModel = env->GetStringUTFChars(deviceNameString, NULL);
	}
};

class AndroidSafeNativeThreadAttachment
{
	const AndroidNativeState& nativeState;
	bool shouldBeAttached;

public:
	JNIEnv* envForThread;

	AndroidSafeNativeThreadAttachment(const AndroidNativeState& nativeState)
	:nativeState(nativeState)
	{
		int result = nativeState.vm->GetEnv((void **) &envForThread, JNI_VERSION_1_6);
		shouldBeAttached = (result == JNI_EDETACHED);

		if(shouldBeAttached)
		{
			int result = nativeState.vm->AttachCurrentThread(&envForThread, NULL);
			Eegeo_ASSERT(result == 0);
		}
	}

	~AndroidSafeNativeThreadAttachment()
	{
		if(shouldBeAttached)
		{
			nativeState.vm->DetachCurrentThread();
		}
	}
};
