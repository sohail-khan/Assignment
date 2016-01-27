// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

#include "Types.h"
#include "Roads.h"
#include "Fonts.h"
#include "TextMeshes.h"
#include "CoverageTrees.h"
#include "Helpers.h"
#include "Rendering.h"
#include "Navigation.h"
#include "Modules.h"
#include "Collision.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TransportStreamingModule : protected Eegeo::NonCopyable
                {
                public:
                    TransportStreamingModule(
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                             Rendering::MeshFactories::TextMeshFactory& textMeshFactory,
                                             Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                             Rendering::IMaterialProvider& materialProvider,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& roadSceneElementRepository,
                                             Rendering::Scene::SceneElementRepository<Resources::Roads::RoadNamesRenderable>& roadNameSceneElementRepository,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& shadowSceneElementRepository,
                                             Resources::Roads::Navigation::NavigationGraphRepository& roadNavGraphRepository,
                                             Resources::Roads::Navigation::NavigationGraphRepository& railNavGraphRepository,
                                             Resources::Roads::Navigation::NavigationGraphRepository& tramNavGraphRepository,
                                             Collision::CollisionMeshResourceRepository& roadsCollisionMeshResourceRepository,
                                             Collision::CollisionMeshResourceRepository& railCollisionMeshResourceRepository,
                                             Collision::CollisionMeshResourceRepository& tramlinesCollisionMeshResourceRepository,
                                             Fonts::FontInstance& roadNameFont,
                                             Fonts::FontMaterialSet& roadNameFontMaterialSet,
                                             const bool generateCollision);
                    
                    ~TransportStreamingModule();
                    
                    static TransportStreamingModule* Create(Core::RenderingModule& renderingModule,
                                                            EnvironmentMaterialModule& environmentMaterialModule,
                                                            TransportModelModule& transportModelModule,
                                                            TransportPresentationModule& transportPresentationModule,
                                                            Core::FontsModule& fontsModule,
                                                            ShadowModelModule& shadowModelModule,
                                                            Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                                            const bool generateCollisionForAllResources);
                
                    Resources::Roads::RoadStreaming& GetRoadStream() const;
                    Resources::Roads::ChunkedRoadBuilder& GetRoadBuilder() const;
                    
                private:
                    Resources::Roads::RoadStreaming* m_pRoadStream;
                    Resources::Roads::ChunkedRoadBuilder* m_pRoadBuilder;
                    TextMeshes::PreTransformedTextMeshBuilder* m_pRoadNamesTextMeshBuilder;
                    
                    Resources::Roads::Navigation::NavigationGraphBuilder* m_pRoadNavGraphBuilder;
                    Resources::Roads::Navigation::NavigationGraphBuilder* m_pRailNavGraphBuilder;
                    Resources::Roads::Navigation::NavigationGraphBuilder* m_pTramNavGraphBuilder;
                };
            }
        }
    }
}