// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IMaterialRepository.h"
#include <string>
#include <map>

namespace Eegeo
{
    namespace Rendering
    {
        class MaterialRepository : protected Eegeo::NonCopyable, public IMaterialRepository
        {
        public:
            
            ~MaterialRepository();
            void AddMaterial(Rendering::Materials::IMaterial* material);
            void RemoveMaterial(Rendering::Materials::IMaterial* material);
            bool ContainsMaterial(const std::string& materialName) const;
            Rendering::Materials::IMaterial* GetMaterial(const std::string& materialName) const;
            std::vector<Rendering::Materials::IMaterial*> GetMaterials() const;
        private:
            typedef std::map<std::string, Rendering::Materials::IMaterial*> TNameToMaterial;
            TNameToMaterial m_materials;

        };
    }
}
