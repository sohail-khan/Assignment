// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Graphics.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace WeatherOverlayShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string DiffuseName = "Diffuse";
                const std::string LayerAlphasName = "LayerAlphas";
                const std::string UvOffsetAndScaleLayerOne = "UvOffsetAndScaleLayerOne";
                const std::string UvOffsetAndScaleLayerTwo = "UvOffsetAndScaleLayerTwo";
                
                
                const std::string _vertexDecls =
                "attribute lowp vec2 "+PositionName+";\n"
                "attribute lowp vec2 "+UVName+";\n"
                "varying mediump vec2 DestUvLayerOne;\n"
                "varying mediump vec2 DestUvLayerTwo;\n"
                "uniform mediump vec4 "+UvOffsetAndScaleLayerOne+";\n"
                "uniform mediump vec4 "+UvOffsetAndScaleLayerTwo+";\n";
                
                const std::string _fragmentDecls =
                "varying mediump vec2 DestUvLayerOne;\n"
                "varying mediump vec2 DestUvLayerTwo;\n"
                "uniform sampler2D "+DiffuseName+";\n"
                "uniform lowp vec2 "+LayerAlphasName+";\n";
                
                
                const std::string _vertexCode =
                "void main()\n"
                "{\n"
                "DestUvLayerOne = UvOffsetAndScaleLayerOne.xy + (UV.xy * UvOffsetAndScaleLayerOne.zw);\n"
                "DestUvLayerTwo = UvOffsetAndScaleLayerTwo.xy + (UV.xy * UvOffsetAndScaleLayerTwo.zw);\n"
                "gl_Position = vec4(Position.xy, 0.0, 1.0);\n"
                "}\n";
                
                const std::string _fragmentCode =
                "void main()\n"
                "{\n"
                "lowp vec3 layerOne = texture2D(Diffuse, DestUvLayerOne).rgb*LayerAlphas.x;\n"
                "lowp vec3 layerTwo = texture2D(Diffuse, DestUvLayerTwo).rgb*LayerAlphas.y;\n"
                "gl_FragColor.rgb = layerOne + layerTwo;\n"
                "}\n";
            }
            
            class WeatherOverlayShader : public Shader
            {
            public:
                static WeatherOverlayShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(WeatherOverlayShader)(
                                                    shaderId,
                                                    WeatherOverlayShaderCode::_vertexDecls + WeatherOverlayShaderCode::_vertexCode,
                                                    WeatherOverlayShaderCode::_fragmentDecls + WeatherOverlayShaderCode::_fragmentCode
                                                    );
                }
                
                const GLuint GetDiffuseSamplerId() const { return 0; }
                void SetMVP(const m44& mvp) const
                {
                    
                }
                
                void SetLayerAlphas(Eegeo::v2 layerAlphas)
                {
                    SetUniformV2(layerAlphas, m_layerAlphasUniformLocation);
                }
                
                void SetUVOffsetAndScaleLayerUniforms(Eegeo::v4 UvOffsetAndScaleLayerOne, Eegeo::v4 UvOffsetAndScaleLayerTwo)
                {
                    SetUniformV4(UvOffsetAndScaleLayerOne,  m_uvOffsetAndScaleLayerOneUniformLocation);
                    SetUniformV4(UvOffsetAndScaleLayerTwo,  m_uvOffsetAndScaleLayerTwoUniformLocation);
                }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);
                }
                
            protected:
                WeatherOverlayShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(WeatherOverlayShaderCode::DiffuseName);
                    m_layerAlphasUniformLocation = GetUniformLocation(WeatherOverlayShaderCode::LayerAlphasName);
                    m_uvOffsetAndScaleLayerOneUniformLocation = GetUniformLocation(WeatherOverlayShaderCode::UvOffsetAndScaleLayerOne);
                    m_uvOffsetAndScaleLayerTwoUniformLocation = GetUniformLocation(WeatherOverlayShaderCode::UvOffsetAndScaleLayerTwo);
                }
                
            private:
                GLuint m_diffuseTextureSamplerUniformLocation;
                GLuint m_layerAlphasUniformLocation ;
                GLuint m_uvOffsetAndScaleLayerOneUniformLocation;
                GLuint m_uvOffsetAndScaleLayerTwoUniformLocation;
            };
        }
    }
}
