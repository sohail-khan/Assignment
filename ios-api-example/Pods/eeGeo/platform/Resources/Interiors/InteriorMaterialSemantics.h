// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IInteriorsMaterialFactory.h"
#include "Types.h"
#include "IdTypes.h"
#include "Lighting.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace InteriorMaterialSemantics
            {
                const std::string DiffuseTexture = "DiffuseTexture";
                const std::string CubeMapTexture = "CubeMapTexture";
                
                
                const std::string DiffuseColor = "DiffuseColor";
                const std::string SpecularColor = "SpecularColor";
                const std::string ReflectionColor = "ReflectionColor";
                const std::string RimColor = "RimColor";
                const std::string AmbientColor = "AmbientColor";
                const std::string MirrorClearColor = "MirrorClearColor";
                const std::string ReflectionPlane = "ReflectionPlane";
                
                const std::string SpecularPowerScalar = "SpecularPower";
                const std::string SpecularModulateTextureScalar = "SpecularModulateTexture";
                const std::string SpecularityFromTextureLuminanceScalar = "SpecularityFromTextureLuminance";
                const std::string ViewOffsetScale = "ViewOffsetScale";
                
                const std::string FresnelBias = "FresnelBias";
                const std::string FresnelScale = "FresnelScale";
                const std::string FresnelPower = "FresnelPower";
                
                const std::string IsTranslucent = "IsTranslucent";
                
                const std::string MaterialType = "MaterialType";
                
                const std::string InteriorsDiffuseUntexturedMaterial = "InteriorsDiffuseUntexturedMaterial";
                const std::string InteriorsDiffuseTexturedMaterial = "InteriorsDiffuseTexturedMaterial";
                const std::string InteriorsSpecularMaterial = "InteriorsSpecularMaterial";
                const std::string InteriorsCubeMappedMaterial = "InteriorsCubeMappedMaterial";
                const std::string InteriorsChromeMaterial = "InteriorsChromeMaterial";
                const std::string InteriorsReflectionMaterial = "InteriorsReflectionMaterial";
                const std::string InteriorsStencilMirrorMaskMaterial = "InteriorsStencilMirrorMaskMaterial";
                const std::string InteriorsStencilMirrorMaterial = "InteriorsStencilMirrorMaterial";
                const std::string InteriorsHighlightMaterial = "InteriorsHighlightMaterial";
            }
        }
    }
}