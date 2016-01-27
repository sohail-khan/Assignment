// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "Traffic.h"
#include <map>

namespace Eegeo
{
    namespace Traffic
    {
        class TrafficSimulationCellsModel : protected Eegeo::NonCopyable
        {
        public:
            
            typedef std::map<Eegeo::Streaming::MortonKey, TrafficSimulationCell*, Eegeo::Streaming::MortonKeyCompare> TTrafficCellMap;
            typedef TTrafficCellMap::const_iterator TTrafficCellConstIterator;
            
            TrafficSimulationCellsModel(bool managePopulation)
            : m_managePopulation(managePopulation)
            {
                
            }
            
            TTrafficCellConstIterator Begin() const { return m_storage.begin(); }
            TTrafficCellConstIterator End() const { return m_storage.end(); }
            
            void AddCell(const Streaming::MortonKey& key, TrafficSimulationCell* cell);
            void RemoveCell(const Streaming::MortonKey& key);
            TrafficSimulationCell* GetCellWithKey(const Streaming::MortonKey& key) const;
            void Clear();
            
            bool ShouldManagePopulation() const { return m_managePopulation; }
            
        private:
            
            TTrafficCellMap m_storage;
            
            bool m_managePopulation;
        };
    }
}