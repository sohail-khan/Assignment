// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "SelectedRoad.h"
#include <set>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class SelectedRoadRepository : Eegeo::NonCopyable
                {
                public:
                    
                    bool Contains(const SelectedRoad& selectedRoad) const;
                    
                    bool TryInsert(const SelectedRoad& selectedRoad);
                    
                    void Clear();
                    
                private:
                    std::set<SelectedRoad> m_selectedRoads;
                };
            }
        }
    }
}
