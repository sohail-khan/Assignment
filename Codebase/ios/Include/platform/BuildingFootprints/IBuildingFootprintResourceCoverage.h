// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "Streaming.h"

#include <string>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class IBuildingFootprintResourceCoverage
        {
        public:
            virtual ~IBuildingFootprintResourceCoverage() {}
            
            virtual bool TryComposeUrlFor(const Eegeo::Streaming::MortonKey& key, std::string& out_url) const = 0;
        };
    }
}