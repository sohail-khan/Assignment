// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "Rendering.h"
#include "Modules.h"
#include "CityThemes.h"
#include "AsyncTexturing.h"
#include "Collision.h"
#include "IdTypes.h"
#include "Lighting.h"
#include "Helpers.h"

#include <string>

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class InteriorsStreamingModule : private Eegeo::NonCopyable
                {
                public:
                    InteriorsStreamingModule(Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                             Rendering::GlBufferPool& glBufferPool,
                                             Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                             Resources::Interiors::InteriorsModelRepository& interiorsModelRepository,
                                             Resources::Interiors::InteriorsInstanceRepository& interiorsInstanceRepository,
                                             Resources::Interiors::Entities::InteriorsEntitiesRepository& interiorsEntitiesRepository,
                                             Resources::Interiors::Markers::InteriorMarkerModelRepository& interiorMarkerModelRepository,
                                             Collision::CollisionMeshResourceRepository& collisionMeshResourceRepository,
                                             Collision::CollisionMeshResourceRepository& highlightCollisionMeshResourceRepository,
                                             Resources::Interiors::InteriorsCellResourceObserver& interiorsCellResourceObserver,
                                             Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                             Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                             const Lighting::GlobalLighting& globalLighting,
                                             Eegeo::Helpers::ITextureFileLoader& textureFileLoader,
                                             const bool interiorsAffectedByFlattening);
                    
                    virtual ~InteriorsStreamingModule();
                    
                    static InteriorsStreamingModule* Create(Modules::Core::RenderingModule& renderingModule,
                                                            Modules::Map::Layers::InteriorsModelModule& interiorsModelModule,
                                                            Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                                            Modules::Core::LightingModule& lightingModule,
                                                            Helpers::ITextureFileLoader& textureFileLoader,
                                                            const bool interiorsAffectedByFlattening);
                    
                    virtual Resources::Interiors::InteriorsStreaming& GetInteriorsStream() const;
                    
                    virtual Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder& GetInteriorMarkersCellResourceBuilder() const;
                    
                    virtual Rendering::IMaterialRepository& GetInteriorsMaterialRepository() const;
                    
                    
                    
                    virtual const Resources::Interiors::InteriorsShader& GetInteriorsShader() const;
                    
                    virtual const Resources::Interiors::InteriorsDiffuseTexturedShader& GetInteriorsDiffuseTexturedShader() const;
                    
                    virtual const Resources::Interiors::InteriorsDiffuseSpecularShader& GetInteriorsDiffuseSpecularShader() const;
                    
                    virtual const Resources::Interiors::InteriorsCubeMappedShader& GetInteriorsCubeMappedShader() const;
                    
                    virtual const Resources::Interiors::InteriorsChromeShader& GetInteriorsChromeShader() const;


                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsMaterialFactory() const;
                    
                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsDiffuseTexturedMaterialFactory() const;

                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsDiffuseTranslucentMaterialFactory() const;
                    
                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsDiffuseSpecularMaterialFactory() const;
                    
                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsCubeMappedMaterialFactory() const;
                    
                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsChromeMaterialFactory() const;
                    
                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsReflectionMaterialFactory() const;
                    
                    virtual Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsStencilMirrorMaterialFactory() const;
                    
                    virtual void AddInteriorsMaterialFactory(Resources::Interiors::IInteriorsMaterialFactory* pInteriorsMaterialFactory);
                    
                    virtual Resources::Interiors::IInteriorsTextureResourceService& GetInteriorsTextureResourceService() const;
                    
                    virtual Resources::Interiors::InteriorsStencilMirrorClearRenderableFactory& GetInteriorsStencilMirrorClearRenderableFactory() const;
                    
                private:
                    Resources::Interiors::InteriorsStreaming* m_pInteriorsStreaming;
                    Resources::Interiors::Builder::ChunkedInteriorsBuilder* m_pChunkedInteriorsBuilder;
                    Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder* m_pInteriorMarkersCellResourceBuilder;
                    
                    Resources::Interiors::InteriorsShader* m_pInteriorsShader;
                    Resources::Interiors::InteriorsDiffuseTexturedShader* m_pInteriorsDiffuseTexturedShader;
                    Resources::Interiors::InteriorsDiffuseSpecularShader* m_pInteriorsDiffuseSpecularShader;
                    Resources::Interiors::InteriorsDiffuseTranslucentShader* m_pInteriorsDiffuseTranslucentShader;
                    Resources::Interiors::InteriorsCubeMappedShader* m_pInteriorsCubeMappedShader;
                    Resources::Interiors::InteriorsChromeShader* m_pInteriorsChromeShader;
                    Resources::Interiors::InteriorsStencilMirrorShader* m_pInteriorsStencilMirrorShader;
                    Resources::Interiors::InteriorsStencilMirrorMaskShader* m_pInteriorsStencilMirrorMaskShader;
                    
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsDiffuseTexturedMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsDiffuseSpecularMaterialFactory;
                    Resources::Interiors::InteriorsDiffuseTranslucentMaterialFactory* m_pInteriorsDiffuseTranslucentMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsCubeMappedMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsChromeMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsReflectionMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsStencilMirrorMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsStencilMirrorMaskMaterialFactory;
                    
                    
                    Resources::Interiors::InteriorsStencilMirrorClearMaterial* m_pInteriorsStencilMirrorClearMaterial;
                    Eegeo::Rendering::Mesh* m_pFullScreenQuadMesh;
                    Resources::Interiors::InteriorsStencilMirrorClearRenderableFactory* m_pInteriorsStencilMirrorClearRenderableFactory;
                    
                    
                    Resources::Interiors::IInteriorsMaterialService* m_pInteriorsMaterialService;
                    Rendering::IMaterialRepository* m_pInteriorsMaterialRepository;
                    
                    Resources::Interiors::InteriorsDefaultMaterialFactory* m_pInteriorsDefaultMaterialFactory;
                    Resources::Interiors::InteriorsAggregateMaterialFactory* m_pInteriorsAggregateMaterialFactory;
                    
                    Resources::Interiors::IInteriorsTextureResourceRepository* m_pInteriorsTextureResourceRepository;
                    
                    Resources::Interiors::IInteriorsTextureResourceBuilder* m_pInteriorsTextureResourceBuilder;
                    Resources::Interiors::IInteriorsCubeTextureResourceBuilder* m_pInteriorsCubeTextureResourceBuilder;
                    
                    Resources::Interiors::IInteriorsTextureResourceService* m_pInteriorsTextureResourceService;
                    
                    Resources::Interiors::IInteriorsMaterialAssignmentObserver* m_pInteriorsMaterialAssignmentObserver;
                };
            }
        }
    }
}