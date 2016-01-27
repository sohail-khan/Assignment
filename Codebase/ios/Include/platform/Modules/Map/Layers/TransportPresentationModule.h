// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include "Fonts.h"
#include "Roads.h"
#include "Rendering.h"
#include "Location.h"
#include "Camera.h"
#include "Streaming.h"
#include "Modules.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TransportPresentationModule : Eegeo::NonCopyable
                {
                public:
                    TransportPresentationModule(Fonts::FontInstance& environmentFont,
                                                Rendering::Shaders::TextShader& textShader,
                                                Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& roadsSceneElementRepository,
                                                Rendering::Scene::SceneElementRepository<Resources::Roads::RoadNamesRenderable>& roadNamesSceneElementRepository,
                                                Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                                Rendering::EnvironmentFlatteningService& environmentFlatteningService);
                    
                    ~TransportPresentationModule();
                    
                    static TransportPresentationModule* Create(Core::FontsModule& fontsModule,
                                                               Core::RenderingModule& renderingModule,
                                                               TransportModelModule& transportModelModule,
                                                               Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                                               Rendering::EnvironmentFlatteningService& environmentFlatteningService);
                    
                    Fonts::FontMaterialSet& GetRoadNamesFontMaterialSet() const;
                    Resources::Roads::RoadNamesFadeController& GetRoadNamesFadeController() const;
                    Rendering::Filters::PackedRenderableFilter& GetRoadsRenderableFilter() const;
                    Resources::Roads::RoadNamesRenderableFilter& GetRoadNamesRenderableFilter() const;

                    void Update(float dt, const double& cameraAltitude, const dv3& ecefInterestPoint);
                    
                private:
                    Fonts::FontMaterialSet* m_pRoadNamesFontMaterialSet;
                    Resources::Roads::RoadNamesFadeController* m_pRoadNamesFadeController;
                    Rendering::Filters::PackedRenderableFilter* m_pRoadsPackedRenderableFilter;
                    Resources::Roads::RoadNamesRenderableFilter* m_pRoadNamesRenderableFilter;
                };
            }
        }
    }
}