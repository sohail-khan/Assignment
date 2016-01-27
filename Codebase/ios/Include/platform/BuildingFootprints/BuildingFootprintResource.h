// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BuildingFootprints.h"

#include <string>
#include <vector>


namespace Eegeo
{
    namespace BuildingFootprints
    {
        struct BuildingFootprintResource : public Eegeo::NonCopyable
        {
            BuildingFootprintResource(const std::string& cellKey, const std::vector<const BuildingFootprint*>& footprints);
            
            ~BuildingFootprintResource();

            std::string CellKeyString() const { return m_cellKey; }
            const std::vector<const BuildingFootprint*>& Footprints() const { return m_footprints; }
        private:
            std::string m_cellKey;
            std::vector<const BuildingFootprint*> m_footprints;
        };
        
    }
}