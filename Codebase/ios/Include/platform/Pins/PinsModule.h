// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "DiffuseMeshFactory.h"
#include "PinViewFactory.h"
#include "PinRepository.h"
#include "PinController.h"
#include "RenderableFilters.h"
#include "Modules.h"
#include "Helpers.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Object graph for a default implementation of Pin control and rendering.
         *
         *  This module creates an object graph to display Pins as sprites using icons from a given 
         *  texture page. It is provided in source code form as a guide for applications with a requirement
         *  to display Pins in an alternate way.
         *
         */        
        class PinsModule : protected Eegeo::NonCopyable
        {
        public:
            //! Create an object graph for rendering a set of Pins as sprites (for a simpler creation path, see the Create(..) method)
            /* \param iconsTexturePageId The GL of the the texture containing the icons that will be used to display the Pins.
             * \param iconsTexturePageLayout The layout of the icon images within the texture page.
             * \param glBufferPool reference to GLBufferPool component
             * \param shaderIdGenerator reference to the shader ID generator.
             * \param materialIdGenerator reference to the material ID generator.
             * \param vertexBindingPool reference to the vertex binding pool.
             * \param vertexLayoutPool reference to the vertex layout pool.
             * \param renderFilters reference to the RenderFilters component.
             * \param terrainHeightProvider reference to TerrainHeightProvider component
             * \param spriteWidth The width of the pins.
             * \param spriteHeigh The height of the pins.
             * \param layerId The ID of the layer that the sprites are to be rendered in.
             * \param environmentFlatteningService reference to EnvironmentFlatteningService
             * \param screen properties for correctly rendering pins depending on dimensions & dpi
             * \param useLegacyScaling Legacy scaling sizes pins based on a fixed value rather than screen size & density.
             * \return A PinModule object.
             */
            PinsModule(const Eegeo::Rendering::TTextureId iconsTexturePageId,
                       const Eegeo::Rendering::ITexturePageLayout& texturePageLayout,
                       Rendering::GlBufferPool& glBufferPool,
                       Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                       Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                       Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                       Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                       Rendering::RenderableFilters& renderableFilters,
                       Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                       const float spriteWidth,
                       const float spriteHeight,
                       const Rendering::LayerIds::Values layerId,
                       const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                       const Rendering::ScreenProperties& screenProperties,
                       const bool useLegacyScaling)
            : m_renderableFilters(renderableFilters)
            {
                m_pViewFactory = Eegeo_NEW(PinViewFactory)(spriteWidth, spriteHeight);
                
                m_pRepository = Eegeo_NEW(PinRepository)();

                m_pViewRenderer = PinViewRenderer::Create(
                        environmentFlatteningService,
                        renderableFilters,
                        shaderIdGenerator,
                        materialIdGenerator,
                        vertexLayoutPool,
                        vertexBindingPool,
                        glBufferPool,
                        texturePageLayout,
                        iconsTexturePageId,
                        layerId,
                        screenProperties,
                        useLegacyScaling);

                m_pController = Eegeo_NEW(PinController)(*m_pRepository, terrainHeightProvider, *m_pViewFactory, *m_pViewRenderer);
            }

            /*! Destroy the PinsModule.
             */
            ~PinsModule()
            {
                m_renderableFilters.RemoveRenderableFilter(*m_pViewRenderer);

                Eegeo_DELETE m_pController;
                Eegeo_DELETE m_pViewRenderer;
                Eegeo_DELETE m_pRepository;

                Eegeo_DELETE m_pViewFactory;
            }

            //! Factory method that creates an object graph for rendering a set of Pins as sprites
            /* \param renderingModule reference to RenderingModule
             * \param platformAbstractonModule reference to PlatformAbstractionModule
             * \param mapModule reference to MapModule.
             * \param pinIconsTextureId the pin icons texture id for the texture to be used for the pin sprites.
             * \param texturePageLayout the ITexturePageLayout instance that will provide the pin sprite uvs.
             * \param spriteWidth width of the pin view sprites.
             * \param spriteHeigh height of the pin view sprites.
             * \param screenProperties Screen properties defining dimensions and density of screen
             * \param useLegacyScaling Legacy scaling sizes pins based on a fixed value rather than screen size & density.
             * \return A PinModule object.
             */
            static PinsModule* Create(
                    Eegeo::Modules::Core::RenderingModule& renderingModule,
                    Eegeo::Modules::IPlatformAbstractionModule& platformAbstractonModule,
                    Eegeo::Modules::Map::MapModule& mapModule,
                    const Eegeo::Rendering::TTextureId pinIconsTextureId,
                    const Eegeo::Rendering::ITexturePageLayout& texturePageLayout,
                    const Eegeo::Rendering::LayerIds::Values layerId,
                    const float spriteWidth,
                    const float spriteHeight,
                    const Rendering::ScreenProperties& screenProperties,
                    const bool useLegacyScaling
            );

            /*! Update the state of the PinsModule with respect to elapsed time.
             *  \param dt The time elapsed, in seconds, since this method was last called.
             *  \param renderCamera The currentActiveRenderCamera
             */
            void Update(float dt, const Camera::RenderCamera& renderCamera)
            {
                m_pController->Update(dt, renderCamera);
            }
            
            /*! Update the screen properties so pins can be rendered correctly.  Should be called when screen properties change (i.e. changing orientation)
             *  \param screenProperties the updated ScreenProperties object
             */
            void UpdateScreenProperties(const Rendering::ScreenProperties& screenProperties)
            {
                m_pViewRenderer->UpdateScreenProperties(screenProperties);
            }
            
            /*! Retrieve the PinRepository from the module.
             *  \return The PinRepository.
             */
            PinRepository& GetRepository() const { return *m_pRepository; }

            /*! Retrieve the PinController from the module.
             *  \return The PinController.
             */
            PinController& GetController() const { return *m_pController; }
            
        private:
            Rendering::RenderableFilters& m_renderableFilters;
            IPinViewFactory* m_pViewFactory;
            PinRepository* m_pRepository;
            PinViewRenderer* m_pViewRenderer;
            PinController* m_pController;
        };
    }
}
