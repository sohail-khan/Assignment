// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        class IMaterialProvider
        {
        public:
            virtual ~IMaterialProvider() {}
            virtual bool ContainsMaterial(const std::string& materialName) const = 0;
            virtual Rendering::Materials::IMaterial* GetMaterial(const std::string& materialName) const = 0;
            virtual std::vector<Rendering::Materials::IMaterial*> GetMaterials() const = 0;
        };
    }
}