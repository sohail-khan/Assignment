// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{    
    namespace Debug
    {        
        class SummaryStats : protected Eegeo::NonCopyable
        {
        public:
            SummaryStats();

            void addSample(float sample);
            float mean() const;
            int numOfSamples() const;
            float sumOfSamples() const;
            float max() const;
            float min() const;
            
            void Reset();
            
        private:
            int m_numOfSamples;
            float m_sumOfSamples;
            float m_maxSample;
            float m_minSample;
        };
    }
}