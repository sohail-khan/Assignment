// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Web.h"
#include "BuildingFootprints.h"
#include "Streaming.h"
#include "CollisionVisualization.h"
#include "BuildingFootprintSelectionControllerConfig.h"
#include "CoverageTrees.h"
#include "Camera.h"


#include <string>


namespace Eegeo
{
    namespace Modules
    {
        class BuildingFootprintsModule : protected Eegeo::NonCopyable
        {
        public:
            static BuildingFootprintsModule* Create(const Modules::IPlatformAbstractionModule& platformAbstractionModule,
                                                    const Modules::Core::RenderingModule& renderingModule,
                                                    const Modules::CollisionVisualizationModule& collisionVisualizationModule,
                                                    const Modules::Map::Layers::BuildingStreamingModule& buildingStreamingModule,
                                                    const Modules::Map::CoverageTreeModule& coverageTreeModule,
                                                    const BuildingFootprints::BuildingFootprintSelectionControllerConfig& config);

            static BuildingFootprints::BuildingFootprintSelectionControllerConfig MakeDefaultConfig();
            
            virtual ~BuildingFootprintsModule();
            
            virtual BuildingFootprints::BuildingFootprintService& GetBuildingFootprintService() const { return *m_pBuildingFootprintService; }

            virtual BuildingFootprints::BuildingFootprintSelectionController& GetBuildingFootprintSelectionController() const { return *m_pBuildingFootprintSelectionController; }
            
            virtual BuildingFootprints::BuildingSelectionController& GetBuildingSelectionController() const { return *m_pBuildingSelectionController; }
            
            virtual void Update(float dt);
            
            virtual void Draw(const Eegeo::Camera::RenderCamera& renderCamera);
            
            
        private:
            BuildingFootprintsModule(Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                     const Modules::Core::RenderingModule& renderingModule,
                                     const Modules::CollisionVisualizationModule& collisionVisualizationModule,
                                     const Eegeo::Streaming::IResourceStream& buildingResourceStream,
                                     Streaming::CoverageTrees::CoverageTreeManifestNotifier& coverageTreeManifestNotifier,
                                     const BuildingFootprints::BuildingFootprintSelectionControllerConfig& config);
            
            BuildingFootprints::BuildingFootprintRepository* m_pBuildingFootprintRepository;
            BuildingFootprints::BuildingFootprintWebLoader* m_pBuildingFootprintWebLoader;
            BuildingFootprints::BuildingFootprintResourceService* m_pBuildingFootprintResourceService;
            BuildingFootprints::BuildingFootprintService* m_pBuildingFootprintService;
            BuildingFootprints::BuildingFootprintSelectionController* m_pBuildingFootprintSelectionController;
            BuildingFootprints::BuildingFootprintSelectionRenderableFactory* m_pBuildingFootprintSelectionRenderableFactory;
            BuildingFootprints::BuildingFootprintSelectionViewFactory* m_pBuildingFootprintSelectionViewFactory;
            BuildingFootprints::BuildingSelectionController* m_pBuildingSelectionController;
            BuildingFootprints::IBuildingFootprintResourceCoverageFactory* m_pBuildingFootprintResourceCoverageFactory;
            BuildingFootprints::BuildingFootprintResourceStore* m_pBuildingFootprintResourceStore;
        };
    }
}