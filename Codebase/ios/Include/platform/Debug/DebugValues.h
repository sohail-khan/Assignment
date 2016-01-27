// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Debug
    {
        namespace DebugValues
        {
            extern int numPayloadsToLoad;
            extern int numPayloadsFailedLoad;
            extern int numPayloadsToBuild;
            
            extern int totalDrawCalls;
            extern int totalPolysRendered;
            extern int totalShadowDrawCalls;
            extern int shadowPolysRendered;
            
            extern bool loggingAllocations;
            extern bool cycleAppRequested;
        }
    }
}
