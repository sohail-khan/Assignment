// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IInteriorsMaterialFactory.h"
#include "Types.h"
#include "IdTypes.h"
#include "Lighting.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsReflectionMaterialFactory : public IInteriorsMaterialFactory, private Eegeo::NonCopyable
            {
            public:

                
                InteriorsReflectionMaterialFactory(Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                                        const InteriorsDiffuseSpecularShader& shader,
                                                        const Lighting::GlobalLighting& globalLighting,
                                                        IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                                        const IInteriorsTextureResourceRepository& interiorsTextureResourceRepository);
                
                Eegeo::Rendering::Materials::IMaterial* TryCreate(const InteriorMaterialData& interiorMaterialData);
                
                
            private:
                Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
                const InteriorsDiffuseSpecularShader& m_shader;
                const Lighting::GlobalLighting& m_globalLighting;
                IInteriorsMaterialAssignmentObserver& m_materialAssignmentObserver;
                const IInteriorsTextureResourceRepository& m_interiorsTextureResourceRepository;
            };
        }
    }
}