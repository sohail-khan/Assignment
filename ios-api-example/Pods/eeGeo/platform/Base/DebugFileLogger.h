// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <fstream>
#include <string>
#include "Types.h"

namespace Eegeo
{
    std::string static GetTimeStamp()
    {
        char buffer[30];
#ifdef EEGEO_WIN
        SYSTEMTIME currentTime;
        GetSystemTime(&currentTime);
        sprintf(buffer, "%d-%d-%d %d:%d:%d (%d)", currentTime.wYear, currentTime.wMonth, currentTime.wDay, currentTime.wHour, currentTime.wMinute, currentTime.wSecond, GetCurrentThreadId());
#endif
        return std::string(buffer);
    }

    struct ofstreamGuard
    {
        std::ofstream file;

        ofstreamGuard(const std::string& filename)
        {
            file.open(filename.c_str(), std::iostream::app | std::iostream::out);

            Eegeo_ASSERT(file, "File cannot be opened!");
        }

        ~ofstreamGuard()
        {
            file.close();
        }
    };

    class DebugFileLogger : public NonCopyable
    {
        DebugFileLogger() {}
        ~DebugFileLogger() {}
    public:

        static void Log(const std::string& data, std::ofstream& file)
        {
            file << GetTimeStamp();
            file << "=> ";
            file << data;
            file << "\n";

            file.flush();
        }
    };
}
