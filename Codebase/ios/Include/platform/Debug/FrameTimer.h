// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <deque>

namespace Eegeo
{
    namespace Debug
    {
        class IFrameTimer
        {
        public:
            virtual void StartFrame() = 0;
            virtual void EndFrame() = 0;
            virtual void ResetCounters() = 0;
            virtual float LastFrameTimeMS() const = 0;
            virtual float MaxFrameTimeMS() const = 0;
            virtual float FramesPerSecond() const = 0;
            virtual float SmoothedFrameDurationMS() const = 0;
            virtual float AverageFramesPerSecond() const = 0;
        };
        
        struct FrameTime
        {
            float updateTime;
            float drawTime;
            float frameTime;
        };

        class FrameTimer : public Debug::IFrameTimer
		{
		public:
			FrameTimer();
			virtual ~FrameTimer() { };
			virtual void StartFrame();
			virtual void EndFrame();
            virtual void StartUpdate();
            virtual void EndUpdate();
            virtual void StartDraw();
            virtual void EndDraw();
			virtual void ResetCounters();
			virtual float LastFrameTimeMS() const;
			virtual float MaxFrameTimeMS() const;
			virtual float FramesPerSecond() const;
			virtual float SmoothedFrameDurationMS() const;
			virtual float AverageFramesPerSecond() const;
            
            virtual int GetNumberOfSamples() const;
            const FrameTime& GetFrameSample(int index) const;
		private:
			double m_previousTimestamp;
			double m_frameStarted;
            double m_updateStarted;
            double m_drawStarted;
			double m_lastFrameDuration;
			double m_smoothedDuration;
			double m_averageFPSStartTime;
			double m_maxFrameDuration;
			int m_frameCount;
            std::deque<FrameTime> m_statsPerFrame;
            FrameTime m_currentStat;
		};
    }
}