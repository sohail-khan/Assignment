// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Debug
    {
        // stats
        class IMemoryStats;
        class IFrameTimer;
        class IDebugStats;
        class SummaryStats;
        struct TotalStreamStats;
        struct StreamStat;

        namespace Profile
        {
            class PerformanceTestRunner;
            struct SplineData;
            struct PerformanceTestReport;
        }
        
        namespace SplinePlayback
        {
            class DebugCameraSplinePlaybackService;
        }
        
        namespace Picking
        {
            class DebugPickingController;
        }
        
        namespace BuildingFootprints
        {
            class DebugBuildingFootprintsController;
        }
        
        namespace Interiors
        {
            class DebugInteriorsController;
        }
    }
}