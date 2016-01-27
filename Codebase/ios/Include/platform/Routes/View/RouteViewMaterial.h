// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "Routes.h"
#include <string>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewMaterial : Eegeo::NonCopyable, public Rendering::Materials::IMaterial
            {
            public:
                RouteViewMaterial(const Rendering::TMaterialId materialId,
                                  const std::string& name,
                                  RouteViewShader& shader);
                
                const Rendering::TMaterialId GetId() const { return m_id; }
                const Rendering::Shader& GetShader() const;
                const std::string& GetName() const { return m_name; }

                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            private:
                const Rendering::TMaterialId m_id;
                const std::string m_name;
                RouteViewShader& m_shader;
            };

        }
    }
}
