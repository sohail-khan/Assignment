// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Base
    {
        namespace FogShaderOld
        {
            void SetPerMaterialRenderState(const Rendering::Shaders::FogShaderUniforms& fogShaderUniforms, Lighting::GlobalFoggingUniformValues fogValues);

            void SetPerModelRenderState(const Rendering::Shaders::FogShaderUniforms& fogShaderUniforms, const Eegeo::v3& cameraRelativeModelOrigin);
        }
    }
}