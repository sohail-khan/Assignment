// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "Resources.h"
#include "Types.h"

namespace Eegeo
{
    namespace Debug
    {
        struct TotalStreamStats
        {
            int totalRequests;
            int totalBytesLoaded;
            int totalBytesLoadedWeb;
            int totalBytesLoadedCache;
            int totalSuccessfulRequests;
            int totalFailedRequests;
            int totalPreDecompressBytesRead;
        };
        
        struct StreamStat
        {
            int bytesLoaded;
            int preDecompressBytesRead;
            int totalRequests;
            int successfulRequets;
            int failedRequests;
            int avgSizeKB;
            int loadedFromWebKB;
            int loadedFromCacheKB;
            int numberOfWebLoads;
            int numberOfCacheLoads;
            int numberOfBuilds;
            float loadTimeFromWebMS;
            float loadTimeFromCacheMS;
            float loadTimeForFailureMS;
            float inflateTimeMS;
        };
        
        class IDebugStats
        {
        public:
            virtual ~IDebugStats() {}
            virtual float FramesPerSecond() const = 0;
            virtual float MaxFrameTime() const = 0;
            virtual float LastFrameTime() const = 0;
            virtual float AverageFramesPerSecond() const = 0;
            
            virtual size_t MemoryUsed() const = 0;
            virtual size_t VirtualMemoryUsed() const = 0;
            virtual size_t FreeMemory() const = 0;
            
            virtual int ResourceNodeCacheAllocs() const = 0;
            virtual int ResourceNodeCacheMisses() const = 0;
            virtual int ResourceNodeCacheAdds() const = 0;
            virtual int ResourceNodeCacheDeletions() const = 0;
            virtual int ResourceNodeCacheSize() const = 0;
            
            virtual double CameraPositionLatitude() const = 0;
            virtual double CameraPositionLongitude() const = 0;
            virtual double CameraPositionAltitude() const = 0;
            virtual float CameraRotationFromNorth() const = 0;
            virtual double CameraDistanceToInterest() const = 0;
            virtual float CameraFoVDegrees() const = 0;
            
            virtual double CameraInterestPointLatitude() const = 0;
            virtual double CameraInterestPointLongitude() const = 0;
            virtual double CameraInterestPointAltitude() const = 0;
            
            virtual int BitsPerSecond() const = 0;
            virtual int MaxBitsPerSecond() const = 0;
            virtual Eegeo::Debug::TotalStreamStats TotalStreamStats() const = 0;
            
            virtual int NumberOfStreams() const = 0;
            virtual const char* NameOfStream(int streamIndex) const = 0;
            virtual StreamStat StreamStatsForStream(int streamIndex) const  = 0;
            
            virtual int PolyCount() const = 0;
            virtual int DrawCalls() const = 0;
            
            virtual void RegisterStream(Eegeo::Streaming::LoggingResourceStream* resourceStream,
                                        Eegeo::Resources::IResourceBuilder* resourceBuilder,
                                        const char*& resourceName) = 0;
            
            virtual void Reset() = 0;
        };
    }
}
