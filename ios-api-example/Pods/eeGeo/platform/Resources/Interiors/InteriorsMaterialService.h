// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"
#include "Rendering.h"
#include "IInteriorsMaterialService.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsMaterialService : public IInteriorsMaterialService, private Eegeo::NonCopyable
            {
            public:
                InteriorsMaterialService(IInteriorsMaterialFactory& interiorsMaterialFactory,
                                         Rendering::IMaterialRepository& materialRepository);
                
                virtual ~InteriorsMaterialService();

                virtual Eegeo::Rendering::Materials::IMaterial* Create(const InteriorMaterialData& interiorMaterialData);
                virtual void Destroy(const std::string& materialName);
                virtual bool Contains(const std::string& materialName) const;
                virtual Eegeo::Rendering::Materials::IMaterial* Get(const std::string& materialName) const;
                
            private:
                void DestroyAll();
                
                IInteriorsMaterialFactory& m_interiorsMaterialFactory;
                Rendering::IMaterialRepository& m_materialRepository;
                
            };
        }
    }
}