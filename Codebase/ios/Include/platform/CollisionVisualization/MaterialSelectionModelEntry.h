// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"

#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class MaterialSelectionModelEntry
        {
        public:
            MaterialSelectionModelEntry(const std::string& materialId)
            : m_materialId(materialId)
            , m_flashing(false)
            {}
            
            std::string MaterialId() const { return m_materialId; }
            bool IsFlashing() const { return m_flashing; }
            void SetFlashing(bool enabled) { m_flashing = enabled; }
        private:
            std::string m_materialId;
            bool m_flashing;
        };
    }
}