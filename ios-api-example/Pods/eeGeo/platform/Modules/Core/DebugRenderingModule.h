// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Helpers.h"
#include "Fonts.h"
#include "DebugRendering.h"
#include "Rendering.h"
#include "Camera.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class DebugRenderingModule : protected Eegeo::NonCopyable
            {
            public:
                DebugRenderingModule(Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                     Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                     Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                     Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                     Rendering::RenderableFilters& renderableFilters,
                                     Helpers::IFileIO& fileIO,
                                     Helpers::ITextureFileLoader& textureLoader);
                
                ~DebugRenderingModule();
                
                static DebugRenderingModule* Create(Core::RenderingModule& renderingModule,
                                                    Helpers::IFileIO& fileIO,
                                                    Helpers::ITextureFileLoader& textureLoader);
                
                DebugRendering::DebugRenderer& GetDebugRenderer() const;
                Fonts::FontInstance& GetDebugFont() const;
                
                void Update(float dt, const Camera::RenderCamera& renderCamera);
            private:
                DebugRendering::DebugRenderer *m_pDebugRenderer;
                Fonts::FontInstance* m_pDebugFont;
                
                Rendering::Shaders::ColoredVertShader* m_pColoredVertShader;
                Rendering::Materials::DebugMaterial* m_pDebugMaterial;
                
                Rendering::Shaders::TextShader* m_pTextShader;
                Rendering::Materials::DebugTextMaterial* m_pDebugTextMaterial;
            };
        }
    }
}