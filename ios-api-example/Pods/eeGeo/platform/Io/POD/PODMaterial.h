// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <iostream>
#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODMaterial
            {
            public:
                PODMaterial();
                
                void SetName(std::string &name);
                void SetDiffuseTextureId(u32 diffuseTextureId);
                void SetShadowMapTextureId(u32 shadowMapTextureId);
                void SetMaterialEffectFile(std::string materialEffectFile);
                void SetMaterialEffectName(std::string materialEffectName);
                void SetOpacity(float opacity);
                void SetFlags(u32 flags);
                
                std::string GetName() const;
                u32 GetDiffuseTextureId() const;
                u32 GetShadowMapTextureId() const;
                std::string GetMaterialEffectFile() const;
                std::string GetMaterialEffectName() const;
                float GetOpacity() const;
                u32 GetFlags() const;
                
            private:
                std::string m_name;
                u32 m_diffuseTextureId;
                u32 m_shadowMapTextureId;
                std::string m_materialEffectFile;
                std::string m_materialEffectName;
                float m_opacity;
                u32 m_flags;
            };
        }
    }
}
