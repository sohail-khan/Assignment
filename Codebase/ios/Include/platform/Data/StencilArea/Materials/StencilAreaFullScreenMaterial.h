//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include "ColorShader.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            namespace Materials
            {
                class StencilAreaFullScreenMaterial : protected Eegeo::NonCopyable, public Rendering::Materials::IMaterial
                {
                public:
                    StencilAreaFullScreenMaterial(
                                        const Rendering::TMaterialId materialId,
                                        const std::string& name,
                                        const Eegeo::v4& color,
                                        Eegeo::Rendering::Shaders::ColorShader& shader
                                        );
                    
                    const Rendering::TMaterialId GetId() const { return m_id; }
                    const Rendering::Shader& GetShader() const { return m_shader; }
                    const std::string& GetName() const { return m_name; }
                    
                    void SetState(Rendering::GLState& glState) const;
                    
                    void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                protected:
                    const Rendering::TMaterialId m_id;
                    const std::string m_name;
                    const Eegeo::v4 m_color;
                    Eegeo::Rendering::Shaders::ColorShader& m_shader;
                };
            }
        }
    }
}