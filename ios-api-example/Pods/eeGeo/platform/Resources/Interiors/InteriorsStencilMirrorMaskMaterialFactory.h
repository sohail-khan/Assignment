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
            class InteriorsStencilMirrorMaskMaterialFactory : public IInteriorsMaterialFactory, private Eegeo::NonCopyable
            {
            public:
                InteriorsStencilMirrorMaskMaterialFactory(Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                         const InteriorsStencilMirrorMaskShader& interiorsStencilMirrorMaskShader,
                                         const Lighting::GlobalLighting& globalLighting,
                                         IInteriorsMaterialAssignmentObserver& materialAssignmentObserver);
                
                Eegeo::Rendering::Materials::IMaterial* TryCreate(const InteriorMaterialData& interiorMaterialData);
                
                
            private:
                Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
                const InteriorsStencilMirrorMaskShader& m_interiorsStencilMirrorMaskShader;
                const Lighting::GlobalLighting& m_globalLighting;
                IInteriorsMaterialAssignmentObserver& m_materialAssignmentObserver;
            };
        }
    }
}