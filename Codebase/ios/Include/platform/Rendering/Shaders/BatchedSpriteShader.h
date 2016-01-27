// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Graphics.h"
#include "VectorMath.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace BatchedSpriteShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";

                const std::string _vertexDecls =
                "attribute highp vec3 "+PositionName+";\n"
                "attribute mediump vec2 "+UVName+";\n"
                "attribute lowp vec4 Color;\n"

                "varying mediump vec2 DestinationUV;\n"
                "varying lowp vec4 DestinationColor;\n"
                "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n";
                
                const std::string DiffuseName = "Diffuse";

                const std::string _fragmentDecls =
                "varying mediump vec2 DestinationUV;\n"
                "varying lowp vec4 DestinationColor;\n"
                "uniform sampler2D "+DiffuseName+";\n";
                
                const std::string _vertexCode = "void main(void) { \n"
                "DestinationUV = UV;\n"
                "DestinationColor = Color;\n"
                "gl_Position = ModelViewProjectionMatrix * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentCode = "void main(void) { \n"
                 "gl_FragColor = DestinationColor * texture2D("+DiffuseName+", DestinationUV.xy);\n"
                 "}";
            }

            /*!
             * \brief Shader for drawing alpha-blended, batched sprites
            */
            class BatchedSpriteShader : public Shader
            {
            public:
                static BatchedSpriteShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(BatchedSpriteShader(
                            shaderId,
                            BatchedSpriteShaderCode::_vertexDecls + BatchedSpriteShaderCode::_vertexCode,
                            BatchedSpriteShaderCode::_fragmentDecls + BatchedSpriteShaderCode::_fragmentCode));
                }
                
                const GLuint GetDiffuseSamplerId() const { return 0; }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }

                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);
                }
                
            protected:
                BatchedSpriteShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(BatchedSpriteShaderCode::ModelViewProjectionMatrixName);
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(BatchedSpriteShaderCode::DiffuseName);
                }
                
            private:
                GLuint m_mvpUniformLocation ;
                GLuint m_diffuseTextureSamplerUniformLocation;
            };
        }
    }
}
