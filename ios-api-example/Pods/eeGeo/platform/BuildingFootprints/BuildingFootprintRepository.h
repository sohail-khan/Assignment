// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BuildingFootprints.h"
#include "MortonKey.h"

#include <vector>
#include <map>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintRepository : public Eegeo::NonCopyable
        {
        public:
            void Add(const Eegeo::Streaming::MortonKey& cellKey, const BuildingFootprintResource& footprintResource);
            void Remove(const Eegeo::Streaming::MortonKey& cellKey);
            bool Contains(const Eegeo::Streaming::MortonKey& cellKey) const;
            const BuildingFootprintResource* Get(const Eegeo::Streaming::MortonKey& cellKey) const;
            std::vector<Streaming::MortonKey> OrderedKeys() const;
        private:
            typedef std::map<Eegeo::Streaming::MortonKey, const BuildingFootprintResource*, Eegeo::Streaming::MortonKeyCompare> TKeyToResourceMap;
            TKeyToResourceMap m_footprintResources;
        };
    }
}
