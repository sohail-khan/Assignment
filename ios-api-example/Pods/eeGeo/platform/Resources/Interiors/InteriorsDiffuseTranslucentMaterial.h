// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once


#include "Interiors.h"
#include "InteriorsMaterialBase.h"
#include "TextureMinifyType.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMath.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {

            class InteriorsDiffuseTranslucentMaterial : public InteriorsMaterialBase
            {
            public:
                InteriorsDiffuseTranslucentMaterial(const Rendering::TMaterialId materialId,
                                                 const Lighting::GlobalLighting& lighting,
                                                 const std::string& name,
                                                 IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                                 const InteriorsDiffuseTranslucentShader& shader);
                

                
                ~InteriorsDiffuseTranslucentMaterial();
                
                const Eegeo::Rendering:: Shader& GetShader() const;
                
                void SetState(Eegeo::Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Eegeo::Rendering::RenderableBase* renderableBase, Eegeo::Rendering::GLState& glState) const;
                
            private:
                const InteriorsDiffuseTranslucentShader& m_shader;
            };
        }
    }
}