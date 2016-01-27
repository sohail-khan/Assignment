// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

// FogIntensities.xyz = {HeightFogIntensity, DistanceFogIntensity, FogDensityGlobal}
// FogRamp.xyzw = {fogValues.HeightFogMinAltitudeCameraRelative, fogValues.HeightFogMaxAltitudeCameraRelative, (fogValues.DistanceFogNear)^2, (fogValues.DistanceFogFar)^2};

namespace Eegeo
{
    namespace Rendering
    {
        namespace FogShaderIncludes
        {
            const std::string CameraRelativeModelOriginName = "CameraRelativeModelOrigin";
            const std::string WorldUpName = "WorldUp";
            const std::string FogIntensitiesName = "FogIntensities";
            const std::string FogRampName = "FogRamp";
            const std::string FogColourName = "FogColour";
        }
    }
}

#define FOG_VERTEX_SHADER_UNIFORMS \
"uniform highp vec3 CameraRelativeModelOrigin;\n"     \
"uniform lowp vec3 WorldUp;\n"                          \
"uniform lowp vec3 FogIntensities;\n"                   \
"uniform highp vec4 FogRamp;\n"                                           

#define FOG_VERTEX_SHADER_FUNCTIONS \
"lowp float CalcHeightFogDensity(highp vec3 vertexPos) {\n"                                                    \
    "highp vec3 cameraRelativePos = CameraRelativeModelOrigin + vertexPos;\n"                                     \
    "highp vec2 rampParams = vec2(dot(cameraRelativePos, WorldUp), dot(cameraRelativePos, cameraRelativePos));\n" \
    "lowp vec2 ramps = smoothstep(FogRamp.yz, FogRamp.xw, rampParams);\n"                                           \
    "lowp vec2 heightAndDistanceFogParams = vec2(ramps.x*ramps.x, ramps.y); \n"                                     \
    "return clamp(dot(heightAndDistanceFogParams, FogIntensities.xy), 0.0, 1.0); \n"                                \
"}\n"


#define FOG_FRAGMENT_SHADER_UNIFORMS \
"uniform lowp vec4 FogColour;\n"
