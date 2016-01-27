// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "VectorMath.h"
#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace PackedStencilShadowShaderCode
            {
                const std::string PositionName = "Position";
                const std::string ExtrusionUnpackName = "ExtrusionUnpack";
                const std::string UnpackModelViewProjectionMatrixName = "UnpackModelViewProjectionMatrix";
                
                const std::string _vertexCode =
                "attribute mediump vec4 "+PositionName+";\n"
                "uniform highp mat4 "+UnpackModelViewProjectionMatrixName+";\n"
                "uniform highp vec3 "+ExtrusionUnpackName+";\n"
                "void main()\n"
                "{\n"
                "highp vec3 packedPos = Position.xyz - ExtrusionUnpack*Position.w;\n"
                "gl_Position = UnpackModelViewProjectionMatrix * vec4(packedPos, 1.0);\n"
                "}";
                
                const std::string _fragmentCode =
                "void main()\n"
                "{\n"
                "gl_FragColor.rgb = vec3(1.0,0.0,0.0);\n"
                "}\n";
            }
            
            class PackedStencilShadowShader : public Shader
            {
            public:
                static PackedStencilShadowShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedStencilShadowShader)(
                                                            shaderId,
                                                            PackedStencilShadowShaderCode::_vertexCode,
                                                            PackedStencilShadowShaderCode::_fragmentCode
                                                         );
                }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                void SetExtrusionUnpack(const v3& extrusionUnpack) const
                {
                    SetUniformV3(extrusionUnpack, m_extrusionUnpackUniform);
                }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }
                
            protected:
                PackedStencilShadowShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode)
                : Shader(shaderId)
                , m_mvpUniformLocation(0)
                , m_extrusionUnpackUniform(0)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(PackedStencilShadowShaderCode::UnpackModelViewProjectionMatrixName);
                    m_extrusionUnpackUniform = GetUniformLocation(PackedStencilShadowShaderCode::ExtrusionUnpackName);
                }
                
            private:
                GLuint m_mvpUniformLocation;
                GLuint m_extrusionUnpackUniform;
            };
        }
    }
}
