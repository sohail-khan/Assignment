// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LoadingScreenConfig.h"
#include "GLHelpers.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Helpers.h"
#include "Lighting.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        class LoadingScreen : public Eegeo::NonCopyable
        {
        public:
            ~LoadingScreen();
            
            static LoadingScreen* Create(std::string splashScreenImageFilename,
                                         LoadingScreenConfig config,
                                         Eegeo::Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                         Eegeo::Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                         Eegeo::Rendering::GlBufferPool& glBufferPool,
                                         Eegeo::Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                         Eegeo::Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                         Eegeo::Helpers::ITextureFileLoader& textureLoader);
            
            void Dismiss();
            void SetProgress(float progress) { m_progress = Math::Clamp01(progress); }
            void Update(float dt);
            
            void NotifyScreenDimensionsChanged(float screenWidth, float screenHeight);

            bool IsVisible() const { return m_state != Hidden; }
            bool IsDismissed() const { return m_state != Displayed; }
            
            void Draw();
            
        private:
            LoadingScreen(
                          LoadingScreenRenderablesFactory* pRenderablesFactory,
                          const Eegeo::Helpers::GLHelpers::TextureInfo& imageTextureInfo,
                          Eegeo::Rendering::Shaders::ColorShader* pColorShader,
                          Eegeo::Rendering::Materials::ColorMaterial* pColorMaterial,
                          Eegeo::Rendering::Shaders::TexturedUniformColoredShader* pTexturedColoredShader,
                          Eegeo::Rendering::Materials::TexturedUniformColoredMaterial* pTexturedColoredMaterial,
                          LoadingScreenRenderables* pLoadingScreenRenderables,
                          const v4& backgroundColor,
                          bool hasProgressBar,
                          const v4& loadingBarColor,
                          const v4& loadingBarBackgroundColor,
                          const v2& loadingBarOffset,
                          float fadeOutDurationSeconds,
                          bool dismissAfterTimeout,
                          float timeoutSeconds);

            void DestroyResources();
            
            void RecreateRenderables(float screenWidth, float screenHeight);
            
            
            LoadingScreenRenderablesFactory* m_pRenderablesFactory;

            Eegeo::Helpers::GLHelpers::TextureInfo m_imageTextureInfo;
            
            Eegeo::Rendering::Shaders::ColorShader* m_pColorShader;
            Eegeo::Rendering::Materials::ColorMaterial* m_pColorMaterial;
            Eegeo::Rendering::Shaders::TexturedUniformColoredShader* m_pTexturedColoredShader;
            Eegeo::Rendering::Materials::TexturedUniformColoredMaterial* m_pTexturedColoredMaterial;
            
            LoadingScreenRenderables* m_pRenderables;

            enum LoadingScreenState
            {
                Displayed,
                FadeOut,
                Hidden
            };

            LoadingScreenState m_state;
            const v4 m_backgroundColor;
            const v4 m_loadingBarColor;
            const v4 m_loadingBarBackgroundColor;
            const v2 m_loadingBarOffset;

            float m_progress;
            float m_loadingTime;
            float m_fadeTime;

            const float m_fadeDuration;
            const float m_timeoutSeconds;
            
            const bool m_hasProgressBar;
            const bool m_dismissAfterTimeout;

            void DrawLoadingBar(Rendering::GLState& glState, const float t);
        };
    }
}