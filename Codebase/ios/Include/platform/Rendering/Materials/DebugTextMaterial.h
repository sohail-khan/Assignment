// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextMaterial.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class DebugTextMaterial : public TextMaterial
            {
            public:
                DebugTextMaterial(const TMaterialId materialId,
                                  const std::string& name,
                                  Shaders::TextShader& shader,
                                  TTextureId textureId,
                                  bool outlinedText,
                                  bool depthTest);
                
                void SetState(GLState& glState) const;
                void SetStatePerRenderable(const RenderableBase* renderableBase, GLState& glState) const;
            };
        }
    }
}