// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "BuildingFootprint.h"
#include "Types.h"
#include <string>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintSelectionModel : private Eegeo::NonCopyable
        {
        public:
            typedef std::string ModelId;
            
            BuildingFootprintSelectionModel(const ModelId& modelId, const std::vector<BuildingFootprint>& footprints)
            : m_modelId(modelId)
            , m_footprints(footprints)
            , m_flashing(false)
            {}
            
            ModelId GetId() const { return m_modelId; }
            std::vector<BuildingFootprint> GetFootprints() const { return m_footprints; }
            bool IsFlashing() const { return m_flashing; }
            void SetFlashing(bool enabled) { m_flashing = enabled; }
        private:
            const std::string m_modelId;
            const std::vector<BuildingFootprint> m_footprints;
            bool m_flashing;
        };
    }
}