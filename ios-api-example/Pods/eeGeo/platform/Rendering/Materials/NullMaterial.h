// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMaterial.h"
#include "Rendering.h"
#include "GLState.h"
#include "IdTypes.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class NullMaterial : public IMaterial
            {
            public:
                NullMaterial(TMaterialId materialId, Shader& shader, const std::string& name)
                : m_materialId(materialId)
                , m_shader(shader)
                , m_name(name)
                {
                }
                
                const TMaterialId GetId() const { return m_materialId; }
                
                const Shader& GetShader() const { return m_shader; }
                
                void SetState(Rendering::GLState& glState) const {}
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const {}
                
                const std::string& GetName() const { return m_name; }
                
            private:
                const TMaterialId m_materialId;
                Shader& m_shader;
                const std::string m_name;
            };            
        }
    }
}
