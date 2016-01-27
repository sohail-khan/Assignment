// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IDiffuseMaterial.h"
#include "Types.h"
#include "Rendering.h"
#include "GlobalLighting.h"
#include "GlobalFogging.h"
#include "TextureMinifyType.h"
#include "ModelShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            namespace
            {
                const float DefaultDepthRangeNear = 0.f;
                const float DefaultDepthRangeFar = 1.f;
            }
            
            class ModelMaterial : public Materials::IDiffuseMaterial, private Eegeo::NonCopyable
            {
            public:
                ModelMaterial(const TMaterialId materialId,
                              const std::string& name,
                              Shaders::ModelShader& shader,
                              const Lighting::GlobalLighting& lighting,
                              const Lighting::GlobalFogging& fogging,
                              TTextureId texture,
                              Rendering::TextureMinifyType textureMinifyType,
                              bool textureRepeat,
                              bool usesAlternateAmbient);
                ~ModelMaterial();
                
                const TMaterialId GetId() const { return m_id; }
                const std::string& GetName() const { return m_name; }
                const Shader& GetShader() const { return m_shader; }
                const float GetAlpha() const { return m_alpha; }
                void SetAlpha(float alpha);
                void SetDepthTestingEnabled(bool enabled);
                const bool GetDepthTestingEnabled() const { return m_depthTesting; }
                
                void SetDepthRange(float near, float far);
                
                void SetState(Rendering::GLState& glState) const;
                virtual void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                virtual void SetDiffuseTexture(TTextureId textureId);
                
                virtual TTextureId GetTextureId() const { return m_textureId; }
                
            protected:
                
                const TMaterialId m_id;
                const std::string m_name;
                
                float m_alpha;
                bool m_usesAlternateAmbient;
                
                Shaders::ModelShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                const Lighting::GlobalFogging& m_fogging;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_textureRepeat;
                bool m_depthTesting;
                TTextureId m_textureId;
                
                float m_depthRangeNear;
                float m_depthRangeFar;
            };
        }
    }
}