// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
	namespace Helpers
	{
        class Timer
		{
		public:
            Timer();
            long long Start();
            long long Stop();
            long long Total() const;
            int GetNumOfIntervals() const { return m_numOfIntervals; }
            void Reset();
            double Average() const;
            
        private:
            long long m_startTime;
            long long m_totalTime;
            bool m_isRunning;
            int m_numOfIntervals;
		};
	}
}

    
