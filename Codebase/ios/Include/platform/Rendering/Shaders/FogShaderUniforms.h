// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            struct FogShaderUniforms
            {
                int FogColourUniform;
                int CameraRelativeModelOriginUniform;
                int WorldUpUniform;
                int FogIntensitiesUniform;
                int FogRampUniform;
                
                void BindUniformLocations(u32 programHandle);
                void DetermineUniformsFromShader(Eegeo::Rendering::Shader* shader);
            };
        }        
    }
}
