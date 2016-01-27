// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

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
            
            class InteriorsStencilMirrorClearMaterial : public Rendering::Materials::IMaterial, private Eegeo::NonCopyable
            {
            public:
                InteriorsStencilMirrorClearMaterial(const Rendering::TMaterialId materialId,
                                           const std::string& name,
                                           InteriorsStencilMirrorMaskShader& shader);
                
                
                
                ~InteriorsStencilMirrorClearMaterial();
                
                virtual const Rendering::TMaterialId GetId() const;

                
                virtual const Rendering::Shader& GetShader() const;
                
                virtual void SetState(Rendering::GLState& glState) const;
                
                virtual void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                virtual const std::string& GetName() const;
               
            private:
                const Rendering::TMaterialId m_materialId;
                const std::string m_name;
                const InteriorsStencilMirrorMaskShader& m_shader;
            };
        }
    }
}