// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "MortonKey.h"
#include "DoublePlane.h"
#include "CubeMapCellHelpers.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Clipping
        {
            class SplitPlanes
            {
            public:
                SplitPlanes()
                : m_currentKey(0)
                , m_currentKeyValid(false)
                , m_rightPositive(Geometry::DoublePlane::Zero())
                , m_topPositive(Geometry::DoublePlane::Zero())
                {
                }
                
                inline void SetKey(const Streaming::MortonKey& key)
                {
                    if (IsSameKey(key))
                    {
                        return;
                    }
                    m_currentKeyValid = true;
                    m_currentKey = key;
                    Space::CubeMapCellHelpers::CalculateCellSplitPlanes(m_currentKey, m_rightPositive, m_topPositive);
                }
                
                inline const Geometry::DoublePlane& RightPositive() const
                {
                    Eegeo_ASSERT(m_currentKeyValid);
                    return m_rightPositive;
                }
                
                inline const Geometry::DoublePlane& TopPositive() const
                {
                    Eegeo_ASSERT(m_currentKeyValid);
                    return m_topPositive;
                }
                
                inline bool IsSameKey(const Streaming::MortonKey& key) const
                {
                    return m_currentKeyValid && m_currentKey == key;
                }
                
            private:
                Streaming::MortonKey m_currentKey;
                bool m_currentKeyValid;
                Geometry::DoublePlane m_rightPositive;
                Geometry::DoublePlane m_topPositive;
            };
        }
    }
}
