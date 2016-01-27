// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsStreaming;
            
            class InteriorsCellResource;
            class InteriorsModel;
            class InteriorsFloorModel;
            class InteriorsFloorCells;
            class InteriorsFloorCell;
            
            class InteriorsModelRepository;
            class InteriorsInstanceRepository;
            class InteriorsModelEvictor;
            class IInteriorController;
            class InteriorController;
            class CurrentInteriorViewModel;
            
            class InteriorSelectionModel;
            struct InteriorId;
            class InteriorsCellResourceObserver;
            struct InteriorsConfiguration;
            
            class IInteriorsMaterialService;
            class InteriorsMaterialService;
            class InteriorsMaterialRepository;
            class IInteriorsMaterialFactory;

            class InteriorsAggregateMaterialFactory;
            class InteriorsDefaultMaterialFactory;
            struct InteriorMaterialData;
            
            class InteriorsShader;
            class InteriorsDiffuseTexturedShader;
            class InteriorsDiffuseSpecularShader;
            class InteriorsCubeMappedShader;
            class InteriorsChromeShader;
            class InteriorsStencilMirrorMaskShader;
            class InteriorsStencilMirrorShader;
            
            class InteriorsMaterial;
            class InteriorsMaterialFactory;
            
            class InteriorsDiffuseTexturedMaterial;
            class InteriorsDiffuseTexturedMaterialFactory;
            
            class InteriorsDiffuseSpecularMaterial;
            class InteriorsDiffuseSpecularMaterialFactory;
            
            class InteriorsCubeMappedMaterial;
            class InteriorsCubeMappedMaterialFactory;
            
            class InteriorsChromeMaterial;
            class InteriorsCubeMappedMaterialFactory;
            
            class InteriorsReflectionMaterial;
            class InteriorsReflectionMaterialFactory;
            
            class InteriorsStencilMirrorMaskMaterial;
            class InteriorsStencilMirrorMaskMaterialFactory;
            
            class InteriorsStencilMirrorMaterial;
            class InteriorsStencilMirrorMaterialFactory;
            
            class InteriorsStencilMirrorClearMaterial;
            class InteriorsStencilMirrorClearRenderable;
            class InteriorsStencilMirrorClearRenderableFactory;
            
            class InteriorsDiffuseTranslucentMaterial;
            class InteriorsDiffuseTranslucentMaterialFactory;
            class InteriorsDiffuseTranslucentShader;
            
            class IInteriorsTextureResource;
            class InteriorsTextureResource;
            class IInteriorsTextureResourceRepository;
            class InteriorsTextureResourceRepository;
            class IInteriorsTextureResourceBuilder;
            class IInteriorsCubeTextureResourceBuilder;
            class InteriorsTextureResourceBuilder;
            class InteriorsCubeTextureResourceBuilder;
            class IInteriorsTextureResourceService;
            class InteriorsTextureResourceService;
            
            class IInteriorsMaterialAssignmentObserver;
            class InteriorsMaterialAssignmentObserver;

            
            namespace Entities
            {
                class InteriorsEntityModel;
                class IInteriorsLabelController;
                class InteriorsEntitiesRepository;
                class InteriorsEntityGeometryView;
            }
            
            namespace Builder
            {
                class ChunkedInteriorsBuilder;
                class InteriorsJsonParser;
                struct BoundsDto;
                struct EntitiesDto;
                struct InteriorDto;
                struct InteriorMetadataChunkDto;
                struct InteriorFloorChunkDto;
                struct InteriorEntitiesChunkDto;
                struct InteriorFloorData;
                struct InteriorData;
                struct ChunkedInteriorsBuilderOutput;
                struct InteriorRenderableCreationData;
                
            }
            
            namespace Markers
            {
                class InteriorMarkerModel;
                class InteriorMarkerModelRepository;
                class InteriorMarkersCellResource;
                class InteriorMarkersCellResourceBuilder;
            }
        }
    }
}
