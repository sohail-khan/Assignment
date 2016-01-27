// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Collision.h"
#include "Camera.h"

#include "CollisionVisualization.h"
#include "MaterialSelectionControllerConfig.h"
#include "ICallback.h"


namespace Eegeo
{
    namespace Modules
    {
        class CollisionVisualizationModule : private Eegeo::NonCopyable
        {
        public:
            static CollisionVisualizationModule* Create(const Core::RenderingModule& renderingModule, const Map::MapModule& mapModule, const Eegeo::CollisionVisualization::MaterialSelectionControllerConfig& materialSelectionControllerConfig);
            
            static Eegeo::CollisionVisualization::MaterialSelectionControllerConfig MakeDefaultConfig();
            
            ~CollisionVisualizationModule();
            
            CollisionVisualization::CollisionVisualizationRenderableFactory& GetRenderableFactory() const;
            
            CollisionVisualization::CollisionVisualizationRenderer& GetRenderer() const;
            
            CollisionVisualization::MaterialSelectionController& GetMaterialSelectionController() const;
            
            CollisionVisualization::CollisionVisualizationMaterial& GetCollisionVisualizationMaterial() const;
            
            void Update(float frameDeltaTimeSeconds);
            void Draw(const Eegeo::Camera::RenderCamera& renderCamera);

        private:
            CollisionVisualizationModule(const Core::RenderingModule& renderingModule,
                                         const Map::MapModule& mapModule,
                                         const CollisionVisualization::MaterialSelectionControllerConfig& materialSelectionControllerConfig);

            CollisionVisualization::CollisionVisualizationRenderableFactory* m_pCollisionVisualizationRenderableFactory;
            CollisionVisualization::CollisionVisualizationRenderer* m_pCollisionVisualizationRenderer;
            CollisionVisualization::CollisionVisualizationMaterial* m_pCollisionVisualizationMaterial;
            Rendering::Shaders::UniformColoredShader* m_pCollisionVisualizationShader;
            
            CollisionVisualization::MaterialSelectionRenderableFactory* m_pMaterialSelectionRenderableFactory;
            CollisionVisualization::MaterialSelectionModel* m_pMaterialSelectionModel;
            CollisionVisualization::MaterialSelectionController* m_pMaterialSelectionController;
            CollisionVisualization::CollisionStreamingObserver* m_pCollisionStreamingObserver;
        };
    }
}