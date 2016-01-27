// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"

#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class DebugMaterial : public Eegeo::NonCopyable, public IMaterial
            {
            public:
                DebugMaterial(const TMaterialId& materialId,
                              const std::string& materialName,
                              Rendering::Shaders::ColoredVertShader& shader);
                
                const TMaterialId GetId() const;
                
                const Shader& GetShader() const;
                
                void SetState(Rendering::GLState& glState) const;
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                const std::string& GetName() const;
            private:
                
                Rendering::Shaders::ColoredVertShader& m_shader;
                const std::string& m_name;
                const TMaterialId m_materialId;
            };
        }
    }
}