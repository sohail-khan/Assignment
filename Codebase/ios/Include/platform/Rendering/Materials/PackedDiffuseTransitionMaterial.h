// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "IdTypes.h"
#include "Lighting.h"
#include "Rendering.h"
#include "PackedDiffuseTransitionShader.h"
#include "VectorMathDecl.h"
#include "TextureMinifyType.h"
#include <string>


namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class PackedDiffuseTransitionMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                PackedDiffuseTransitionMaterial(
                                                const TMaterialId materialId,
                                                const std::string& name,
                                                Shaders::PackedDiffuseTransitionShader& shader,
                                                const Lighting::GlobalLighting& lighting,
                                                const Lighting::GlobalFogging& fogging,
                                                TTextureId fromTextureId,
                                                TTextureId toTextureId,
                                                Rendering::TextureMinifyType textureMinifyType,
                                                bool useAlternativeAmbient,
                                                bool textureRepeat
                                                );
                
                ~PackedDiffuseTransitionMaterial()
                {
                }
                
                bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                void UseAlternativeAmbient(bool useAlternativeAmbient) { m_useAlternativeAmbient = useAlternativeAmbient; }

                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetFromDiffuseTexture(TTextureId textureId) { m_fromTextureId = textureId; }
                TTextureId GetFromTextureId() const { return m_fromTextureId; }

                void SetToDiffuseTexture(TTextureId textureId) { m_toTextureId = textureId; }
                TTextureId GetToTextureId() const { return m_toTextureId; }
                
                void SetLerpParam(float t) { m_lerpParam = t; }
                float GetLerpParam() const { return m_lerpParam; }
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            protected:
                void SetMVP(const m44& mvp) const
                {
                    m_shader.SetMVP(mvp);
                }
                
                void SetUVBounds(const Eegeo::v2& min, const Eegeo::v2& max) const
                {
                    m_shader.SetUVBounds(min, max);
                }
                
                void SetLerpParam(float t) const
                {
                    m_shader.SetLerpParam(t);
                }
                
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::PackedDiffuseTransitionShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                const Lighting::GlobalFogging& m_fogging;
                TTextureId m_fromTextureId;
                TTextureId m_toTextureId;
                float m_lerpParam;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_textureRepeat;
                bool m_useAlternativeAmbient;
            };
        }
    }
}

