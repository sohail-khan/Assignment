// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "BuiltResourceWithKey.h"
#include "Types.h"
#include "Interiors.h"
#include "Rendering.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsCellResource : public BuiltResourceWithKey, protected Eegeo::NonCopyable
            {
            public:
                InteriorsCellResource(const std::vector<InteriorsFloorCell*>& floorCells,
                                      const std::string& interiorName,
                                      InteriorsModelRepository& repository,
                                      Entities::InteriorsEntitiesRepository& interiorsEntitiesRepository,
                                      InteriorsCellResourceObserver& interiorsCellResourceObserver,
                                      const Streaming::MortonKey& mortonKey);
                ~InteriorsCellResource();
                
                void Unload();
                void RemovedFromSceneGraph();
                void AddedToSceneGraph();
                
                InteriorId GetInteriorId() const;
                std::vector<InteriorsFloorCell*> GetFloorCells() const;
                
            private:
                
                InteriorsModelRepository& m_repository;
                Entities::InteriorsEntitiesRepository& m_interiorsEntitiesRepository;
                InteriorsCellResourceObserver& m_interiorsCellResourceObserver;
                std::string m_interiorName;
                std::vector<InteriorsFloorCell*> m_floorCells;
                bool m_addedToSceneGraph;
            };
        }
    }
}