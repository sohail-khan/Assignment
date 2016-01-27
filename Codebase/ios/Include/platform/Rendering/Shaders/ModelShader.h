// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IDiffuseMaterial.h"
#include "Types.h"
#include "GlobalLighting.h"
#include "GlobalFogging.h"
#include "Rendering.h"
#include "Shader.h"
#include "ShaderMacros.h"

#include "FogShaderIncludes.h"
#include "FogShaderUniforms.h"
#include "FogShaderOld.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace ModelShaderCode
            {
                const std::string PositionName = "Position";
                const std::string NormalName = "Normal";
                const std::string UVName = "UV";
                const std::string DiffuseName = "Diffuse";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";
                const std::string WorldInverseTransposeMatrixName = "WorldInverseTransposeMatrix";
                const std::string LightDirectionMatrixName = "LightDirections";
                const std::string LightColorMatrixName = "LightColors";
                const std::string AlphaName = "Alpha";

                const std::string _vertexDecls =
                "attribute mediump vec3 "+PositionName+";\n"
                "attribute mediump vec3 "+NormalName+";\n"
                "attribute mediump vec2 "+UVName+";\n"
                "varying lowp vec4 ColorVarying;\n"
                "varying lowp float FogDensity;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n"
                "uniform highp mat4 "+WorldInverseTransposeMatrixName+";\n"
                "uniform highp mat4 "+LightDirectionMatrixName+";\n"
                "uniform highp mat4 "+LightColorMatrixName+";\n"
                "uniform lowp float "+AlphaName+";\n"
                FOG_VERTEX_SHADER_UNIFORMS;
                
                const std::string _fragmentDecls =
                "varying lowp vec4 ColorVarying;\n"
                "varying lowp float FogDensity;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform sampler2D "+DiffuseName+";\n"
                "uniform lowp vec4 "+Rendering::FogShaderIncludes::FogColourName+";\n";
                
                const std::string _vertexCode =
                FOG_VERTEX_SHADER_FUNCTIONS
                "void main(void) { \n"
                "DestinationUV = UV;\n"
                "vec4 myNormal = vec4 ("+NormalName+", 1.0) * "+WorldInverseTransposeMatrixName+";\n"
                "myNormal.w = 0.0;\n"
                "vec4 dots = -normalize(myNormal) * "+LightDirectionMatrixName+";\n"
                "dots = clamp (dots, 0.0, 1.0);\n"
                "dots.w = 1.0;\n"
                "ColorVarying.rgb = ("+LightColorMatrixName+" * dots).rgb;\n"
                "ColorVarying.a = "+AlphaName+";\n"
                "FogDensity = CalcHeightFogDensity(Position);\n"
                "gl_Position = "+ModelViewProjectionMatrixName+" * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "gl_FragColor.rgba = mix(" TEXTURE2D(Diffuse, DestinationUV) ".rgba * ColorVarying.rgba, vec4(FogColour.rgb, ColorVarying.a), FogDensity); \n"
                "}";
            }

            
            class ModelShader : public Shader
            {
            public:
                static ModelShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(ModelShader)(
                                                  shaderId,
                                                  ModelShaderCode::_vertexDecls + ModelShaderCode::_vertexCode,
                                                  ModelShaderCode::_fragmentDecls + ModelShaderCode::_fragmentCode
                                                  );
                }
                
                const GLuint GetDiffuseSamplerId() const { return 0; }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                void SetInverseWorldMatrix(const m44& inverseWorld)
                {
                    bool transpose = false;
                    SetUniformM44(inverseWorld, m_inverseWorldUniformLocation, transpose);
                }
                
                void SetLightColors(const m44& colors) const
                {
                    bool transpose = false;
                    SetUniformM44(colors, m_lightColorsUniformLocation, transpose);
                }
                
                void SetLightDirections(const m44& dirs) const
                {
                    bool transpose = false;
                    SetUniformM44(dirs, m_lightDirectionsUniformLocation, transpose);
                }
                
                void SetAlpha(const float alpha) const
                {
                    SetUniformFloat(alpha, m_alphaUniformLocation);
                }
                
                void SetFogUniforms(Lighting::GlobalFoggingUniformValues& fogUniformValues) const
                {
                    Eegeo::Base::FogShaderOld::SetPerMaterialRenderState(m_fogShaderUniforms, fogUniformValues);
                }
                
                void SetCameraRelativeOrigin(const Eegeo::v3& cameraRelativeOrigin) const
                {
                    SetUniformV3(cameraRelativeOrigin, m_cameraRelativeModelOriginUniformLocation);
                }

                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }
                
            protected:
                ModelShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(ModelShaderCode::ModelViewProjectionMatrixName);
                    m_inverseWorldUniformLocation = GetUniformLocation(ModelShaderCode::WorldInverseTransposeMatrixName);
                    m_lightDirectionsUniformLocation = GetUniformLocation(ModelShaderCode::LightDirectionMatrixName);
                    m_lightColorsUniformLocation = GetUniformLocation(ModelShaderCode::LightColorMatrixName);
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(ModelShaderCode::DiffuseName);
                    m_alphaUniformLocation = GetUniformLocation(ModelShaderCode::AlphaName);
                    m_cameraRelativeModelOriginUniformLocation = GetUniformLocation(Eegeo::Rendering::FogShaderIncludes::CameraRelativeModelOriginName);
                    
                    m_fogShaderUniforms.DetermineUniformsFromShader(this);
                }
                
            private:
                GLuint m_mvpUniformLocation;
                GLuint m_inverseWorldUniformLocation;
                GLuint m_lightDirectionsUniformLocation;
                GLuint m_lightColorsUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
                GLuint m_alphaUniformLocation;
                GLuint m_cameraRelativeModelOriginUniformLocation;
                
                Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
            };

        }
    }
}