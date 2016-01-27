// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "InteriorsMaterialBase.h"
#include "PackedDiffuseMaterial.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "ICallback.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsStencilMirrorMaskMaterial : public InteriorsMaterialBase
            {
            public:
                
                InteriorsStencilMirrorMaskMaterial(
                                  const Rendering::TMaterialId materialId,
                                  const std::string& name,
                                  const Lighting::GlobalLighting& lighting,
                                  IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                  const InteriorsStencilMirrorMaskShader& shader
                                  );
                
                const Rendering::Shader& GetShader() const;
                
                void OnAssignedToRenderable(Rendering::Renderables::InteriorRenderable& renderable);
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                

            private:
                const InteriorsStencilMirrorMaskShader& m_shader;
            };
        }
    }
}
