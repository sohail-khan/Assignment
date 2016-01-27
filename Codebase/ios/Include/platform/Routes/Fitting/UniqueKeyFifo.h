// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "tr1.h"

#include <deque>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class UniqueKeyFifo
            {
            public:
                void PushBack(const Streaming::MortonKey& key);
                void PopFront();
                
                inline const Streaming::MortonKey& Front() const
                {
                    return m_keys.front();
                }
                
                inline bool Empty() const
                {
                    return m_keys.empty();
                }
                                
                inline const std::deque<Streaming::MortonKey>& Fifo() const
                {
                    return m_keys;
                }
                
                template <class OutputIterator, class UnaryPredicate>
                inline OutputIterator RemoveIf(OutputIterator removed, UnaryPredicate predicate)
                {
                    std::deque<Streaming::MortonKey>::iterator remainingIter = m_keys.begin();
                    for (std::deque<Streaming::MortonKey>::const_iterator iter = m_keys.begin(); iter != m_keys.end(); ++iter)
                    {
                        const Streaming::MortonKey& key = *iter;
                        if (predicate(key))
                        {
                            m_uniqueSet.erase(key.RawValue());
                            *removed = key;
                            ++removed;
                        }
                        else
                        {
                            *remainingIter = key;
                            ++remainingIter;
                        }
                    }

                    m_keys.erase(remainingIter, m_keys.end());
                    
                    Eegeo_ASSERT(m_keys.size() == m_uniqueSet.size());

                    return removed;
                }
                
            private:
                Eegeo::unordered_set<s64>::type m_uniqueSet;
                std::deque<Streaming::MortonKey> m_keys;
            };

        }
    }
}