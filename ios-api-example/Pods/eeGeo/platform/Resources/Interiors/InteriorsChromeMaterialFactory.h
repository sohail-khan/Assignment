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
            class InteriorsChromeMaterialFactory : public IInteriorsMaterialFactory, private Eegeo::NonCopyable
            {
            public:
                
                
                InteriorsChromeMaterialFactory(Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                                        const InteriorsChromeShader& interiorsChromeShader,
                                                        const Lighting::GlobalLighting& globalLighting,
                                                        IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                                        const IInteriorsTextureResourceRepository& interiorsTextureResourceRepository);
                
                Eegeo::Rendering::Materials::IMaterial* TryCreate(const InteriorMaterialData& interiorMaterialData);
                
                
            private:
                Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
                const InteriorsChromeShader& m_interiorsChromeShader;
                const Lighting::GlobalLighting& m_globalLighting;
                IInteriorsMaterialAssignmentObserver& m_materialAssignmentObserver;
                const IInteriorsTextureResourceRepository& m_interiorsTextureResourceRepository;
            };
        }
    }
}