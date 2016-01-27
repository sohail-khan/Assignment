// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IndexBufferRange.h"

#include <vector>

namespace Eegeo
{
    namespace Culling
    {
        template<int T_maxRange> class IndexBufferRangeMerger
        {
        private:
            int m_count;
            IndexBufferRange m_mergedRanges[T_maxRange];
            
        public:
            
         
            inline void AddRange(int startIndex, int numOfIndices)
            {
                if(!m_mergedRanges[m_count].TryExtend(startIndex, numOfIndices))
                {
                    FlushMergedRanges();
                    m_mergedRanges[m_count].Set(startIndex, numOfIndices);
                }
            }
            
            inline void GetMergedRanges(std::vector<IndexBufferRange>& mergedRanges) const
            {
                mergedRanges.assign(&m_mergedRanges[0], &m_mergedRanges[m_count]);
            }

            
            inline void FlushMergedRanges()
            {
                if(!m_mergedRanges[m_count].IsEmpty())
                {
                    Eegeo_ASSERT(m_count < T_maxRange);
                    m_count++;
                }
            }
            
            inline void Reset()
            {
                m_count = 0;
                m_mergedRanges[0].Set(0,0);
            }
        };
    }
}