// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "ColorShader.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include "GlobalShadowing.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class ShadowMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                ShadowMaterial(const TMaterialId materialId,
                               const std::string& name,
                               Shaders::ColorShader& shader,
                               Eegeo::Lighting::GlobalShadowing& lighting
                               );
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                const v3& GetColor() const { return m_shadowing.GetShadowColor(); }
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::ColorShader& m_shader;
                Eegeo::Lighting::GlobalShadowing& m_shadowing;
            };
        }
    }
}
