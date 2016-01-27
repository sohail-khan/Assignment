// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Pins.h"
#include "Camera.h"
#include "Rendering.h"
#include "IRenderableFilter.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "LayerIds.h"
#include "IdTypes.h"

#include <vector>

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Renderer for a collection of PinView objects.
         *
         *  This class deals with the on-screen representation of a collection of PinView objects.
         *
         */
        class PinViewRenderer : protected Eegeo::NonCopyable, public Rendering::IRenderableFilter
        {
        public:
            /*! Factory method for creating an empty PinViewRenderer object.
             * \param renderableFilters the renderable filters to which the pins will be registered
             * \param texturePageLayout an ITexturePageLayout instance which will be used to map category ids to texture uvs
             * \param textureId the TextureId associated with the pins texture to be used for rendering pins
             * \param layerId the layer to which the pins will be rendered
             * \param screenProperties The ScreenProperties defining screen size and density
             * \param useLegacyScaling Legacy scaling sizes pins based on a fixed value rather than screen size & density.
             * \return A new, empty PinViewRenderer object.
             */
            static PinViewRenderer* Create(
                    const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                    Eegeo::Rendering::RenderableFilters& renderableFilters,
                    Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                    Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                    Eegeo::Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                    Eegeo::Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                    Eegeo::Rendering::GlBufferPool& glBufferPool,
                    const Eegeo::Rendering::ITexturePageLayout& texturePageLayout,
                    const Eegeo::Rendering::TTextureId textureId,
                    const Eegeo::Rendering::LayerIds::Values layerId,
                    const Rendering::ScreenProperties& screenProperties,
                    const bool useLegacyScaling
            );

            /*! Create an empty PinViewRenderer object.
             * \param renderableFilters the renderable filters to which the pins will be registered
             * \param texturePageLayout an ITexturePageLayout instance which will be used to map category ids to texture uvs
             * \param pRenderable pointer to a renderable that will be used to render sprites. Deleted when class is destroyed.
             * \param pMaterial pointer to a material that will be used to render sprites. Deleted when class is destroyed.
             * \param pShader pointer to a shader that will be used to render sprites. Deleted when class is destroyed.
             * \param screenProperties The ScreenProperties defining screen size and density
             * \param useLegacyScaling Legacy scaling sizes pins based on a fixed value rather than screen size & density.
             * \return A new, empty PinViewRenderer object.
             */
            PinViewRenderer(
                    const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                    Eegeo::Rendering::RenderableFilters& renderableFilters,
                    const Eegeo::Rendering::ITexturePageLayout& texturePageLayout,
                    Rendering::Renderables::BatchedSpriteRenderable* pRenderable,
                    Rendering::Materials::BatchedSpriteMaterial* pMaterial,
                    Rendering::Shaders::BatchedSpriteShader* pShader,
                    const Eegeo::Rendering::ScreenProperties& screenProperties,
                    const bool useLegacyScaling);
        
            ~PinViewRenderer();
            
            /*! Add a PinView to the PinViewRenderer.
             * \param viewToAdd The view to add to the renderer.
             */
            void AddView(PinView& viewToAdd);

            /*! Remove a PinView to the PinViewRenderer.
             * \param viewToRemove The view to remove from the renderer.
             */
            void RemoveView(PinView& viewToRemove);
            
            /*! Update the model-view-projections, bounds and on-screen visibility for the PinViews in the renderer.
             */
            void Update(const Camera::RenderCamera& renderCamera);
            
            /*! Update the screen properties of the renderer so it draws pins at the correct size
             */
            void UpdateScreenProperties(const Eegeo::Rendering::ScreenProperties& screenProperties);
            
            /*! Test the PinViews in the renderer for intersection with a given screen point.
             * \param screenPoint The screen point (in screen pixel coordinates) to test for intersection with the PinViews.
             * \param outIntersectingViews A vector to be populated, in order of increasing distance from the camera, with the PinViews which intersect screenPoint.
             * \return true if any views intersected screenPoint, otherwise false.
             */
            bool TryGetViewsIntersectingScreenPoint(const v2& screenPoint, std::vector<PinView*>& outIntersectingViews) const;

            /*! Enque the renderables for the views to be rendered.
             * \param renderContext the current render context.
             * \param renderQueue the render queue to which renderables will be enqueued.
             */
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);

        private:
            
            static const float LegacyScaleModifier;
            
            Eegeo::Rendering::Materials::BatchedSpriteMaterial* m_pMaterial;
            Rendering::Shaders::BatchedSpriteShader* m_pShader;
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            Eegeo::Rendering::Renderables::BatchedSpriteRenderable* m_pBatchedSpriteRenderable;
            const Eegeo::Rendering::ITexturePageLayout& m_pinIconsTexturePageLayout;
            
            typedef std::vector<PinView*> TViews;
            TViews m_views;
            TViews m_visibleViews;
            
            float m_screenHeight;
            float m_screenPixelScale;
            
            const bool m_useLegacyScaling;
            
            bool ContainsView(const PinView& view) const;
        };
    }
}

