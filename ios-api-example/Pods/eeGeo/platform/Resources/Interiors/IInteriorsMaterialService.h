// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"
#include "Rendering.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsMaterialService
            {
            public:
                virtual ~IInteriorsMaterialService() {;}
                
                virtual Eegeo::Rendering::Materials::IMaterial* Create(const InteriorMaterialData& interiorMaterialData) = 0;
                virtual void Destroy(const std::string& materialName) = 0;
                virtual bool Contains(const std::string& materialName) const = 0;
                virtual Eegeo::Rendering::Materials::IMaterial* Get(const std::string& materialName) const = 0;
            };
        }
    }
}