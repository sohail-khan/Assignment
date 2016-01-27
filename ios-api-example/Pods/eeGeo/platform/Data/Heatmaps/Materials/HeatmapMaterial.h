//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include "HeatmapShader.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            namespace Materials
            {
                class HeatmapMaterial : private Eegeo::NonCopyable, public Rendering::Materials::IMaterial
                {
                public:
                    HeatmapMaterial (
                                     const Rendering::TMaterialId materialId,
                                            const std::string& name,
                                            HeatmapShader& shader);
                    
                    const Rendering::TMaterialId GetId() const { return m_id; }
                    const Rendering::Shader& GetShader() const { return m_shader; }
                    const std::string& GetName() const { return m_name; }
                    
                    void SetState(Rendering::GLState& glState) const;
                    
                    void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                protected:
                    const Rendering::TMaterialId m_id;
                    const std::string m_name;
                    HeatmapShader& m_shader;
                };
            }
        }
    }
}