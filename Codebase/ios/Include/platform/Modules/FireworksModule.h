// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFireworksLocationRepository.h"
#include "Rendering.h"
#include "Types.h"
#include "VectorMath.h"
#include "Camera.h"
#include "GLHelpers.h"
#include "IRenderableFilter.h"
#include "Helpers.h"
#include "Modules.h"
#include "Fireworks.h"
#include "Random.h"
#include "Streaming.h"
#include "Terrain.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Modules
    {
        /*!
         * \brief Object graph for a default implementation of Fireworks display animation and rendering.
         *
         *  This module creates an object graph to animate & display Fireworks displays in the world.
         *  By adding a defined FireworksLocationConfiguration to the module's repository, you can register
         *  a number of potential fireworks displays to play.
         */
        class FireworksModule : protected Eegeo::NonCopyable, public Fireworks::IFireworksLocationRepository
        {
        public:
            //! Create an object graph for adding animated fireworks displays to the world (for a simpler creation path, see the Create(..) method)
            /* \param particleTextureFileName the local image file to be used for the firework particles. For best results, use a 32-bit greyscale png.
             * \param glBufferPool reference to GLBufferPool component
             * \param vertexBindingPool reference to VertexBindingPool component
             * \param vertexLayoutPool reference to VertexLayoutPool component
             * \param shaderIdGenerator reference to ShaderIdGenerator component
             * \param materialIdGenerator reference to MaterialIdGenerator component
             * \param textureFileLoader reference to ITextureFileLoader component
             * \param renderableFilters reference to RenderableFilters component
             * \param streamingController reference to StreamingController component
             * \param cameraFrustum reference to CameraFrustumStreamingVolume component
             * \param terrainHeightProvider reference to TerrainHeightProvider component
             */
            FireworksModule(const std::string& particleTextureFileName,
                            Rendering::GlBufferPool& glBufferPool,
                            Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                            Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                            Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                            Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                            Helpers::ITextureFileLoader& textureFileLoader,
                            Rendering::RenderableFilters& renderableFilters,
                            Streaming::StreamingController& streamingController,
                            Streaming::CameraFrustumStreamingVolume& cameraFrustum,
                            Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider);
            ~FireworksModule();
            
            //! Factory method that creates an object graph for displaying Fireworks displays in the world
            /* \param particleTextureFileName the local image file to be used for the firework particles. For best results, use a 32-bit greyscale png.
             * \param renderingModule reference to RenderingModule
             * \param platformAbstractonModule reference to PlatformAbstractionModule
             * \param streamingModule reference to StreamingModule.
             * \param mapModule reference to MapModule.
             * \param terrainModelModule reference to TerrainModelModule.
             * \return A FireworksModule object.
             */
            static FireworksModule* Create(const std::string& particleTextureFileName,
                                           const Modules::Core::RenderingModule& renderingModule,
                                           Modules::IPlatformAbstractionModule& platformModule,
                                           Modules::Map::StreamingModule& streamingModule,
                                           Modules::Map::MapModule& mapModule,
                                           Modules::Map::Layers::TerrainModelModule& terrainModelModule);
            
            //! Update method to tick the animation of firework displays.
            /* \param dt time in seconds that has past since last frame. Used to control the speed of the fireworks animation
             * \param renderCamera a reference to the current RenderCamera being used to display the scene.
             */
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            
            //! Add a location in the world where a Fireworks display may occur.
            /* \param uid A unique identifying number for this location. Using the same number for two different locations will result in an assert.
             * \param location A reference to a FireworksLocationConfiguration that defines all the properties you wish for this fireworks display to have, such as location, time of display and chance of appearing.
             */
            void AddFireworksLocation(u32 uid, Fireworks::FireworksLocationConfiguration& location);
            
            //! Removes a location from the world based on a previously defined unique identifier.
            // \param uid A unique identifying number for the location you wish to remove that was defined when calling AddFireworksLocation.  Calling an unrecognised uid will result in an assert.
            void RemoveFireworksLocation(u32 uid);
            
            //! Removes *all* locations from the repository, removing all fireworks displays from the world.
            void Clear();
            
        private:
            
            Random m_random;
            
            Rendering::Renderables::BatchedSpriteRenderable* m_pBatchedSpriteRenderable;
            
            Rendering::Materials::FireworksMaterial* m_pMaterial;
            Rendering::Shaders::FireworksShader* m_pShader;
            Helpers::GLHelpers::TextureInfo m_textureInfo;
            Rendering::RenderableFilters& m_renderableFilters;
            
            Fireworks::FireworksSequenceFactory* m_pSequenceFactory;
            Fireworks::FireworksLocationRepository* m_pLocationRepository;
            Fireworks::FireworksDisplayService* m_pDisplayService;
            Fireworks::FireworksRenderableFilter* m_pRenderableFilter;
        };
    }
}
