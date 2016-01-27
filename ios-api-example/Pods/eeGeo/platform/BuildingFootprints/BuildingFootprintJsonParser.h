// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BuildingFootprints.h"

#include <string>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintJsonParser : public Eegeo::NonCopyable
        {
        public:
            BuildingFootprintJsonParser();
            
            BuildingFootprintResource* TryCreate(const char* footprintResourceJson, size_t jsonSize) const;
        
        private:
            bool TryParse(const char* footprintResourceJson, size_t jsonSize) const;
        };
    }
}