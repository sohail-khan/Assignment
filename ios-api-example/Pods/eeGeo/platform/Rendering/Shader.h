// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Graphics.h"
#include "VectorMathDecl.h"
#include "IdTypes.h"
#include "VertexAttribs.h"
#include <vector>
#include <map>
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief Base class for Shader programs.
         *
         * This class provides base functionality for compiling shader programs and provides an interface to the their uniforms and vertex attributes.
         */
        class Shader : protected Eegeo::NonCopyable
        {
        public:
            u32 GetId() const { return m_id; }
            
            virtual void Use(Rendering::GLState& glState) const = 0;
             
            virtual void SetMVP(const m44& mvp) const = 0;

            GLuint GetUniformLocation(const std::string& uniformName) const;
            
            inline const VertexLayouts::VertexAttribs& GetVertexAttributes() const
            {
                return m_vertexAttributes;
            }
            
            virtual ~Shader()
            {
                if (m_programHandle != 0)
                {
                    Eegeo_GL(glDeleteProgram(m_programHandle));
                    m_programHandle = 0;
                }
            }

        protected:
            Shader(const TShaderId shaderId)
            : m_programHandle(0)
            , m_id(shaderId)
            {
            }
            
            void CompileProgram(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
            void UseProgram(Rendering::GLState& glState) const;

            void SetUniformFloat(const float value, GLuint uniformLocation) const;
            void SetUniformM44(const m44& matrix, GLuint uniformLocation, bool transpose) const;
            void SetUniformV2(const v2& vec, GLuint uniformLocation) const;
            void SetUniformV3(const v3& vec, GLuint uniformLocation) const;
            void SetUniformV4(const v4& vec, GLuint uniformLocation) const;
            void SetUniformTextureSampler(Rendering::GLState& glState, GLuint samplerId, GLuint uniformLocation) const;
            void SetUniformBool(const bool value, GLuint uniformLocation) const;
            
            u32 m_programHandle;

        private:
            const TShaderId m_id;
            void DetectShaderUniforms();
            std::map<std::string, GLuint> m_uniformsToUniformLocations;
            VertexLayouts::VertexAttribs m_vertexAttributes;
        };
    }
}
