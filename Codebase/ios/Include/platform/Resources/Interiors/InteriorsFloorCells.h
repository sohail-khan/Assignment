// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "Streaming.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsFloorCells : private Eegeo::NonCopyable
            {
            public:
                InteriorsFloorCells(int floorNumber);
                
                void AddCell(InteriorsFloorCell* pCell);
                void RemoveCell(const InteriorsFloorCell* pCell);
                
                std::vector<InteriorsFloorCell*> GetFloorCells() const { return m_floorCells; }
                const int GetFloorNumber() const { return m_floorNumber; }
                const size_t GetCellCount() const { return m_floorCells.size(); }
                
            private:
                bool HasCellForKey(const Streaming::MortonKey& mortonKey) const;
                
                const int m_floorNumber;
                std::vector<InteriorsFloorCell*> m_floorCells;
            };
        }
    }
}