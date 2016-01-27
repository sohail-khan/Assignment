// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IDebugStats.h"
#include "DebugDecl.h"
#include "Streaming.h"
#include "Camera.h"
#include "Location.h"
#include "LatLongAltitude.h"
#include "RenderCamera.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Debug
    {
        
        class DebugStats : public IDebugStats
        {
        public:
            DebugStats(
                       const IMemoryStats* pMemoryStats,
                       const Location::IInterestPointProvider& interestPointProvider,
                       const Camera::RenderCamera& renderCamera,
                       IFrameTimer* pFrameTimer,
                       Streaming::ResourceNodeCache* pResourceNodeCache);
            
            virtual float FramesPerSecond() const;
            virtual float MaxFrameTime()  const;
            virtual float LastFrameTime()  const;
            virtual float AverageFramesPerSecond() const;
            
            virtual double CameraPositionLatitude() const;
            virtual double CameraPositionLongitude() const;
            virtual double CameraPositionAltitude() const;
            virtual float CameraRotationFromNorth() const;
            virtual double CameraDistanceToInterest() const;
            virtual float CameraFoVDegrees() const;
            
            virtual double CameraInterestPointLatitude() const;
            virtual double CameraInterestPointLongitude() const;
            virtual double CameraInterestPointAltitude() const;
            
            virtual size_t MemoryUsed() const;
            virtual size_t VirtualMemoryUsed() const;
            virtual size_t FreeMemory() const;
            
            virtual int ResourceNodeCacheAllocs() const;
            virtual int ResourceNodeCacheMisses() const;
            virtual int ResourceNodeCacheAdds() const;
            virtual int ResourceNodeCacheDeletions() const;
            virtual int ResourceNodeCacheSize() const;
            
            virtual int BitsPerSecond() const;
            virtual int MaxBitsPerSecond() const;
            virtual Eegeo::Debug::TotalStreamStats TotalStreamStats() const;
            
            virtual int NumberOfStreams() const;
            virtual const char* NameOfStream(int streamIndex) const;
            virtual StreamStat StreamStatsForStream(int streamIndex) const;
            
            virtual int PolyCount() const;
            virtual int DrawCalls() const;
            
            virtual void RegisterStream(Eegeo::Streaming::LoggingResourceStream* resourceStream,
                                        Eegeo::Resources::IResourceBuilder* resourceBuilder,
                                        const char*& resourceName);
            virtual void Reset();
            
            virtual void SetRenderCamera(const Camera::RenderCamera& renderCamera);
            
        private:
            Space::LatLongAltitude CameraInterestPointLatLongAltitude() const;

            float GetCameraAbsoluteBearingRadians() const;
            
            const Location::IInterestPointProvider& m_interestPointProvider;
            Camera::RenderCamera m_renderCamera;
            const IMemoryStats* m_pMemoryStats;
            IFrameTimer* m_pFrameTimer;

            Streaming::ResourceNodeCache* m_pResourceNodeCache;
            
            std::vector<Eegeo::Streaming::LoggingResourceStream*> m_resourceStreams;
            std::vector<Eegeo::Resources::IResourceBuilder*> m_resourceBuilders;
            std::vector<std::string> m_resourceStreamNames;
            mutable int m_maxBitsPerSecond;
        };
    }
}
