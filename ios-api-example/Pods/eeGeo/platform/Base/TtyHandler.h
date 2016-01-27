// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace TtyHandler
    {
        extern bool TtyEnabled;
        
        int HandleTty(const char* stringFormat, ...);
    }
}

