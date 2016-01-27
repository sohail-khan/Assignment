// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"

#include <string>
#include <map>
#include <vector>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class MaterialSelectionModel
        {
        public:
            ~MaterialSelectionModel();

            MaterialSelectionModelEntry* Add(const std::string& materialId);
            void Remove(const std::string& materialId);
            void RemoveAll();
            bool Contains(const std::string& materialId) const;
            
            MaterialSelectionModelEntry* GetModelEntryOrNull(const std::string& materialId) const;
            std::vector<std::string> GetMaterialIds() const;
        private:
            typedef std::map<std::string, MaterialSelectionModelEntry*> MaterialIdToModelEntry;
            
            MaterialIdToModelEntry m_materialIdToModelEntry;
        };
    }
}