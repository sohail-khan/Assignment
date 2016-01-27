// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
#ifdef __clang_analyzer__
    void Assert(const char* file, int line, const char* stringFormat, ...) __attribute__((analyzer_noreturn));
    void Assert(const char* file, int line) __attribute__((analyzer_noreturn));
#else
    void Assert(const char* file, int line, const char* stringFormat, ...);
    void Assert(const char* file, int line);
#endif

    namespace AssertHandler
    {
        extern bool LogOnAssert;
        extern bool BreakOnAssert;
        
        void HandleAssertLog(const char* file, int line, const char* stringFormat, ...);
        
        void HandleAssertBreak();
    }
}
