// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoPlatformMacros.h"

#include "AssertHandler.h"
#include "TtyHandler.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlong-long"


#if defined (EEGEO_WIN)
typedef unsigned int uint;
#endif
typedef unsigned long long UInt64;
typedef long long unsigned int u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long signed int s64;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;

#pragma clang diagnostic pop

#if defined (EEGEO_DROID) || defined (EEGEO_WIN)
typedef unsigned char Byte;
#elif defined EEGEO_IOS
#include "MacTypes.h"
#elif defined OVR_OS_MAC
typedef unsigned char Byte;
#elif defined EEGEO_OSX
#include "MacTypes.h"
#endif

#if defined (EEGEO_WIN)
#include "EegeoWindowsGuard.h"
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvariadic-macros"
#pragma clang diagnostic ignored "-Wgnu"
#define Eegeo_TTY(...)		Eegeo::TtyHandler::HandleTty(__VA_ARGS__)
#define Eegeo_ERROR(...)    Eegeo::TtyHandler::HandleTty(__VA_ARGS__)
#define ENABLE_ASSERT

#if defined (ENABLE_ASSERT)
#define Eegeo_ASSERT(x, ...)	if(!(x)) { Eegeo::Assert(__FILE__, __LINE__, ##__VA_ARGS__);  }
#else
#define Eegeo_ASSERT(x, ...)
#endif

#if defined (DEBUG)
#define Eegeo_ASSERT_SLOW Eegeo_ASSERT
#else
#define Eegeo_ASSERT_SLOW(x, ...)
#endif
#pragma clang diagnostic pop

#if defined (EEGEO_WIN)
#define Eegeo_STATIC_ASSERT( condition, name )
#else
// Compile time verification. We cannot use static_assert, as it's a C++11 feature.
// http://stackoverflow.com/questions/6765770/compile-time-assertion
#define Eegeo_STATIC_ASSERT( condition, name ) typedef char assert_failed_ ## name [ (condition) ? 1 : -1 ] __attribute__((unused));
#endif

#define Eegeo_TRACE()			Eegeo_TTY("Trace %s(%d)", __FILE__, __LINE__);

//#define Eegeo_NOISY_NEW_ALL
//#define Eegeo_NOISY_NEW_MAIN_THREAD

#if defined(Eegeo_NOISY_NEW_ALL)
    #include "DebugValues.h"
    #define Eegeo_LOG_ALLOCATIONS Eegeo::Debug::DebugValues::loggingAllocations
    #define Eegeo_NEW(type) (!Eegeo_LOG_ALLOCATIONS ? 0 : Eegeo_TTY("Scalar new at %s :: %d --> size %lu\n", __FILE__, __LINE__, sizeof(type))) && 0 ? 0 : new type
    #define Eegeo_DELETE if(Eegeo_LOG_ALLOCATIONS) {Eegeo_TTY("Scalar delete at %s :: %d\n", __FILE__, __LINE__);} delete
    #define Eegeo_ARRAY_NEW(type, num)  (!Eegeo_LOG_ALLOCATIONS ? 0 : Eegeo_TTY("Array new at %s :: %d --> size %lu\n", __FILE__, __LINE__, sizeof(type))) && 0 ? 0 : new type[num]
    #define Eegeo_ARRAY_DELETE if(Eegeo_LOG_ALLOCATIONS) {Eegeo_TTY("Array delete at %s :: %d\n", __FILE__, __LINE__);} delete[]
#elif defined(Eegeo_NOISY_NEW_MAIN_THREAD)
    #include "DebugValues.h"
    #define Eegeo_LOG_ALLOCATIONS Eegeo::Debug::DebugValues::loggingAllocations
    #include "ThreadHelpers.h"
    #define Eegeo_MAIN_THREAD Eegeo::Helpers::ThreadHelpers::IsMainThread()
    #define Eegeo_NEW(type) ((!Eegeo_MAIN_THREAD || !Eegeo_LOG_ALLOCATIONS) ? 0 : Eegeo_TTY("Scalar new at %s :: %d --> size %lu\n", __FILE__, __LINE__, sizeof(type))) && 0 ? 0 : new type
    #define Eegeo_DELETE if(Eegeo_MAIN_THREAD && Eegeo_LOG_ALLOCATIONS) {Eegeo_TTY("Scalar delete at %s :: %d\n", __FILE__, __LINE__);} delete
    #define Eegeo_ARRAY_NEW(type, num) ((!Eegeo_MAIN_THREAD || !Eegeo_LOG_ALLOCATIONS) ? 0 : Eegeo_TTY("Array new at %s :: %d --> size %lu\n", __FILE__, __LINE__, sizeof(type))) && 0 ? 0 : new type[num]
    #define Eegeo_ARRAY_DELETE  if(Eegeo_MAIN_THREAD && Eegeo_LOG_ALLOCATIONS) {Eegeo_TTY("Array delete at %s :: %d\n", __FILE__, __LINE__);} delete[]
#else
    #define Eegeo_NEW(type) new type
    #define Eegeo_DELETE delete
    #define Eegeo_ARRAY_NEW(type, num) new type[num]
    #define Eegeo_ARRAY_DELETE delete[]
#endif




namespace Eegeo
{
    class NonCopyable
    {
    protected:
        NonCopyable () {}
        ~NonCopyable () {} 
    private: 
        NonCopyable (const NonCopyable &);
        NonCopyable & operator = (const NonCopyable &);
    };
}
