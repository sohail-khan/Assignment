// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "IdTypes.h"
#include "GLState.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class IMaterial
            {
            public:
                virtual const TMaterialId GetId() const = 0;
                
                virtual const Shader& GetShader() const = 0;

                virtual void SetState(Rendering::GLState& glState) const = 0;
                
                virtual void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const = 0;
                
                virtual const std::string& GetName() const = 0;
                
                virtual ~IMaterial() { };
            };
        }
    }
}
