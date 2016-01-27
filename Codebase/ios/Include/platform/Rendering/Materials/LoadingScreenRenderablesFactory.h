// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "LoadingScreenRenderables.h"
#include "LoadingScreenConfig.h"


namespace Eegeo
{
    namespace Rendering
    {
        class LoadingScreenRenderablesFactory : public Eegeo::NonCopyable
        {
        public:
            LoadingScreenRenderablesFactory(Eegeo::Rendering::GlBufferPool& glBufferPool,
                                            Eegeo::Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                            Eegeo::Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                            Materials::ColorMaterial& backgroundMaterial,
                                            Materials::TexturedUniformColoredMaterial& imageMaterial,
                                            Eegeo::Rendering::LoadingScreenLayout::Values layout,
                                            float textureWidth,
                                            float textureHeight)
            : m_glBufferPool(glBufferPool)
            , m_vertexLayoutPool(vertexLayoutPool)
            , m_vertexBindingPool(vertexBindingPool)
            , m_backgroundMaterial(backgroundMaterial)
            , m_imageMaterial(imageMaterial)
            , m_layout(layout)
            , m_textureWidth(textureWidth)
            , m_textureHeight(textureHeight)
            {
            }
            
            
            LoadingScreenRenderables* CreateRenderables(float screenWidth, float screenHeight);
        private:
            Eegeo::Rendering::GlBufferPool& m_glBufferPool;
            Eegeo::Rendering::VertexLayouts::VertexLayoutPool& m_vertexLayoutPool;
            Eegeo::Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
            Materials::ColorMaterial& m_backgroundMaterial;
            Materials::TexturedUniformColoredMaterial& m_imageMaterial;
            const Eegeo::Rendering::LoadingScreenLayout::Values m_layout;
            const float m_textureWidth;
            const float m_textureHeight;
            
        };
    }
}