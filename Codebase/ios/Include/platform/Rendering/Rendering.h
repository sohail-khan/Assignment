// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace AsyncTexturing
    {
        class IAsyncTexture;
    }
    
    namespace Rendering
    {
        class GLState;
        class GlBufferPool;
        class RenderContext;
        class EnvironmentFlatteningService;
        class LoadingScreen;
        class LoadingScreenRenderablesFactory;
        class LoadingScreenRenderables;
        class ITexturePageLayout;
        class Mesh;
        class TriStripMesh;
        class SortKey;
        class Shader;
        class RenderableBase;
        class IRenderableFilter;
        class RenderableFilters;
        class RenderQueue;
        class MaterialRepository;
        class IMaterialRepository;
        class IMaterialProvider;
        // todo: this should go to placenames when we're ready
        class ITextRenderablesSource;
        
        class IReferencedTexture;
        class EnvironmentStateTextures;
        class EnvironmentTexture;
        class EnvironmentTextures;
        class IEnvironmentTexturesObserver;
        class EnvironmentMaterialRepository;
        class EnvironmentMaterialFactory;
        class VAOCache;
        
        class StencilLayersController;
        struct ScreenProperties;
        
        namespace Scene
        {
            template<typename T>
            class ISceneElementFilterCriteria;
            
            template<typename T>
            class ISceneElementObservable;
            
            template<typename T>
            class ISceneElementObserver;
            
            template<typename T>
            class SceneElement;
            
            template<typename T>
            class ISceneElementRemover;

            template<class T>
            class ISceneElementSource;
            
            template<class T>
            class SceneElementRepository;
            
            template<typename T>
            class ISceneElementCriteriaFilterable;
        }
        
        namespace VertexLayouts
        {
            class VertexAttribs;
            class VertexAttribElement;
            class VertexLayoutElement;
            class VertexLayout;
            class VertexLayoutPool;
            class VertexBinding;
            class VertexBindingPool;
        }
        
        namespace MeshFactories
        {
            class MeshFactory;
            class DiffuseMeshFactory;
            class PackedTwoTextureDiffuseMeshFactory;
            class TextMeshFactory;
            
            class ReadMeshFactory;
            class PackedDiffuseReadMeshFactory;

            class LcmReadMeshFactory;
            class PositionMeshFactory;
            class SceneModelMeshFactory;
        }
        
        namespace Renderables
        {
            class MeshRenderable;
            class CulledMeshRenderable;
            class WorldMeshRenderable;
            class PackedRenderable;
            class PackedShadowRenderable;
            class LightmappedRenderable;
            class TextRenderable;
            class WaterRenderable;
            class CustomLandmarkRenderable;
            class BatchedSpriteRenderable;
            class UniqueTextureRenderable;
            class UniformColoredRenderable;
            class InteriorFloorRenderable;
            class InteriorHighlightRenderable;
            class InteriorRenderable;
            class InstancedInteriorFloorRenderable;
            
            class ModelRenderable;
            class SceneModelRenderable;
            class SceneModelMeshRenderable;
            class SceneModelTriStripMeshRenderable;

            namespace TemporaryLegacySupport
            {
                class AnimatedObjectsRenderable;
            }
        }
        
        namespace Filters
        {
            class RenderableRepository;
            class PackedRenderableFilter;
            class TextRenderableFilter;
            class WorldMeshRenderableFilter;
            class DefaultRenderableFilter;
            class SceneModelRenderableFilter;
            class InteriorsRenderableFilter;
            class ShadowPackedRenderableFilter;
        }
        
        namespace Materials
        {
            class NullMaterial;
            class NullMaterialFactory;
            class MaterialIdGenerator;
            class IMaterial;
            class IPackedMaterial;
            class ShadowMaterial;
            class PackedDiffuseMaterial;
            class PackedDiffuseTransitionMaterial;
            class PackedDiffuseFoggedMaterial;
            class PackedStencilShadowMaterial;
            class LightmappedPackedDiffuseMaterial;
            class LightmappedPackedDiffuseTransitionMaterial;
            class TextMaterial;
            class WaterMaterial;
            class WaterMaterial2;
            class WaterTransitionMaterial;
            class CustomLandmarkDiffuseMaterial;
            class CustomLandmarkDiffuseFoggedMaterial;
            class CustomLandmarkDiffuseTransitionMaterial;
            class DiffuseMaterial;
            class VertexColoredMaterial;
            class UniformColoredMaterial;
            class UniqueDiffuseMaterial;
            class BatchedSpriteMaterial;
            class WeatherOverlayMaterial2;
            class ColorMaterial;
            class DebugMaterial;
            class DebugTextMaterial;
            class FireworksMaterial;
            class TexturedUniformColoredMaterial;
            class ModelMaterial;
            class SceneModelMaterial;
            class DepthlessColorMaterial;
        }
        
        namespace Shaders
        {
            class NullShader;
            class ShaderIdGenerator;
            class ColorShader;
            class ColoredVertShader;
            class PackedDiffuseShader;
            class PackedDiffuseTransitionShader;
            class PackedDiffuseFoggedShader;
            class PackedStencilShadowShader;
            class LightmappedPackedDiffuseShader;
            class LightmappedPackedDiffuseTransitionShader;
            class TextShader;
            class WaterShader;
            class WaterTransitionShader;
            class DiffuseShader;
            class VertexColoredShader;
            class UniformColoredShader;
            class BatchedSpriteShader;
            class WeatherOverlayShader;
            struct FogShaderUniforms;
            class FireworksShader;
            class TexturedUniformColoredShader;
            class ModelShader;
            class PackedDiffuseAlphaShader;
        }
        
        namespace VertexTypes
        {
            struct TextVertex;
            struct PackedDiffuseVertex;
            struct PackedTwoTextureVertex;
            struct PackedStencilShadowVertex;
            struct ShortPositionVertex;
            struct DiffuseVertex;
            struct PositionVertex;
            struct TexturedVertex;
            struct Textured2DVertex;
            struct ColoredVertex;
            struct TexturedColoredVertex;
            struct ModelDiffuseVertex;
        }
        
        namespace SceneModels
        {
            class SceneModel;
            class SceneModelLoader;
            class SceneModelFactory;
            class SceneModelNode;
            class SceneModelRenderableNode;
            
            class ISceneModelNodeRenderVisitor;
            class ISceneModelNodeRenderElement;
            
            class SceneModelAnimator;
            class ISceneModelNodeAnimation;
            class SceneModelNodeAnimation;

            class SceneModelTextureResource;
            class SceneModelMaterialResource;
            class SceneModelMeshResource;
            class SceneModelTriStripMeshResource;
        }
    }
}
