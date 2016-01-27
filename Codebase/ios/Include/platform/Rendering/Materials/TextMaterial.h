// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "TextShader.h"
#include "IdTypes.h"
#include "VectorMathDecl.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class TextMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                TextMaterial(const TMaterialId materialId,
                             const std::string& name,
                             Shaders::TextShader& shader,
                             TTextureId textureId,
                             bool outlinedText,
                             bool depthTest
                             );
                
                ~TextMaterial()
                {
                }
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetState(Rendering::GLState& glState) const;
                
            protected:
                inline void SetMVP(const m44& mvp) const
                {
                    m_shader.SetMVP(mvp);
                }
                
                inline void SetScale(const v3& scale) const
                {
                    m_shader.SetScale(scale);
                }
                
                inline void SetForegroundColour(const v4& colour) const
                {
                    m_shader.SetForegroundColour(colour);
                }
                
                inline void SetShadowColour(const v4& colour) const
                {
                    m_shader.SetShadowColour(colour);
                }
                
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::TextShader& m_shader;
                TTextureId m_textureId;
                bool m_outlinedText;
                bool m_depthTest;
            };
        }
    }
}
