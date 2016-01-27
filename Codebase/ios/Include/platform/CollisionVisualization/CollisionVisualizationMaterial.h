// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMaterial.h"
#include "Types.h"
#include "Rendering.h"
#include "Collision.h"
#include "CollisionVisualization.h"

#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class CollisionVisualizationMaterial : public Eegeo::Rendering::Materials::IMaterial, private Eegeo::NonCopyable
        {
        public:
            CollisionVisualizationMaterial(const Eegeo::Rendering::TMaterialId materialId,
                                           const std::string& debugName,
                                           Eegeo::Rendering::Shaders::UniformColoredShader& shader);
            
            const Eegeo::Rendering::TMaterialId GetId() const { return m_id; }
            const Eegeo::Rendering::Shader& GetShader() const;
            const std::string& GetName() const { return m_debugName; }
            
            void SetState(Eegeo::Rendering::GLState& glState) const;
            
            void SetStatePerRenderable(const Eegeo::Rendering::RenderableBase* renderableBase, Eegeo::Rendering::GLState& glState) const;
        protected:
            const Eegeo::Rendering::TMaterialId m_id;
            const std::string m_debugName;
            Eegeo::Rendering::Shaders::UniformColoredShader& m_shader;
        };
    }
}