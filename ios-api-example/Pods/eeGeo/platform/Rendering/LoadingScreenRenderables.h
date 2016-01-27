// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Types.h"

namespace Eegeo
{
    namespace Rendering
    {
        class LoadingScreenRenderables : public Eegeo::NonCopyable
        {
        public:
            LoadingScreenRenderables(float screenWidth,
                                     float screenHeight,
                                     Renderables::WorldMeshRenderable* pNineSliceBorderRenderable,
                                     Renderables::WorldMeshRenderable* pImageRenderable,
                                     Renderables::WorldMeshRenderable* pLoadingBarQuadRenderable);
            
            ~LoadingScreenRenderables();
            
            float GetScreenWidth() const { return m_screenWidth; }
            float GetScreenHeight() const { return m_screenHeight; }
            
            Renderables::WorldMeshRenderable& GetNineSliceBorder() const { return *m_pNineSliceBorderRenderable; }
            Renderables::WorldMeshRenderable& GetImage() const { return *m_pImageRenderable; }
            Renderables::WorldMeshRenderable& GetLoadingBar() const { return *m_pLoadingBarQuadRenderable; }
            
        private:
            const float m_screenWidth;
            const float m_screenHeight;
            Renderables::WorldMeshRenderable* const m_pNineSliceBorderRenderable;
            Renderables::WorldMeshRenderable* const m_pImageRenderable;
            Renderables::WorldMeshRenderable* const m_pLoadingBarQuadRenderable;
        };
    }
}