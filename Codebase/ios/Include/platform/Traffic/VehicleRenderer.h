// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Traffic.h"
#include "Lighting.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "Streaming.h"
#include "IRenderableFilter.h"
#include "ITrafficThemeModelObserver.h"
#include <vector>

namespace Eegeo
{
    namespace Traffic
    {
        class VehicleRenderer : public Rendering::IRenderableFilter, public Themes::ITrafficThemeModelObserver, protected Eegeo::NonCopyable
        {
        public:
            
            enum MaterialType
            {
                INVALID = 0,
                RoadVehicles,
                TrainVehicles,
                TramVehicles,
                PlaneVehicles,
                MAX
            };
            
            VehicleRenderer(VehicleModelNodeRepository& vehicleModelRepository,
                            Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                            Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                            Rendering::IMaterialProvider& materialProvider,
                            Themes::TrafficThemeModel& trafficThemesModel,
                            int maxVehiclesToDraw);
            
            ~VehicleRenderer();
            
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
            void SubmitForRendering(VehicleRenderablesModel& vehicleRenderables,
                                    Streaming::CameraFrustumStreamingVolume& visibleVolume,
                                    MaterialType materialType,
                                    const dv3& ecefCameraPosition
                                    );
            
            void OnThemeChanged (const Themes::TrafficThemeModel& themeModel);
            void OnThemeStateChanged (const Themes::TrafficThemeModel& themeModel);
            
        private:

            void UpdateMaterials(const Themes::TrafficThemeModel& themeModel);

            VehicleModelNodeRepository& m_vehicleModelNodeRepository;
            Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
            Rendering::IMaterialProvider& m_materialProvider;
            
            std::vector<Rendering::Renderables::ModelRenderable*> m_renderablesPool;
            
            int m_nextRenderablesCount;
            
            Rendering::Materials::ModelMaterial& GetMaterialForType(MaterialType& type);
            
            Themes::TrafficThemeModel& m_trafficThemesModel;
            
            Rendering::Materials::ModelMaterial* m_roadVehiclesMaterial;
            Rendering::Materials::ModelMaterial* m_trainMaterial;
            Rendering::Materials::ModelMaterial* m_tramMaterial;
            Rendering::Materials::ModelMaterial* m_planeMaterial;
        };
    }
}