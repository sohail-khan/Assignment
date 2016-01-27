// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            class NullShader : public Shader
            {
            public:
                NullShader(const TShaderId shaderId)
                : Shader(shaderId)
                {
                }
                
                void Use(Rendering::GLState& glState) const {}
                void SetMVP(const m44& mvp) const {}
                
            };
        }        
    }
}
