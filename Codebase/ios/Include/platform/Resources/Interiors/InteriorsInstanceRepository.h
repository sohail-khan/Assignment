// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once


#include "Interiors.h"

#include "Types.h"
#include "Rendering.h"
#include "InteriorsCellResourceObserver.h"

#include <map>
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            struct InstanceStore
            {
                int FloorNum;
                int InteriorNum;
                Rendering::Renderables::InteriorRenderable* Renderable;

                InstanceStore() :
                    FloorNum(-1),
                    InteriorNum(-1),
                    Renderable(NULL)
                {}

                InstanceStore(Rendering::Renderables::InteriorRenderable* renderable, int floor, int interior) :
                    FloorNum(floor),
                    InteriorNum(interior),
                    Renderable(renderable)
                {}
            };

            class InteriorsInstanceRepository : private Eegeo::NonCopyable
            {
                std::map<std::string, InstanceStore> m_instanceIdMapping;
                std::vector<std::string> m_interiorIds;

                int AddAndGetInterior(const std::string& id);

                InteriorsCellResourceObserver& m_cellResourceObserver;
                Helpers::TCallback1<InteriorsInstanceRepository, const InteriorsCellResource> m_cellResourceDeletedCallback;

                void HandleFloorCellDeleted(const InteriorsCellResource& interiorCellResource);

            public:
                InteriorsInstanceRepository(InteriorsCellResourceObserver& cellResourceObserver);
                ~InteriorsInstanceRepository();

                void AddInstanceRenderable(Rendering::Renderables::InteriorRenderable* renderable, const std::string& id, int floorNum, const std::string& interiorId);
                void AddInstanceRenderable(const std::vector<Rendering::Renderables::InteriorRenderable*>& renderables, const std::vector<std::string>& ids, int floorNum, const std::string& interiorId);

                bool TryFindId(const std::string& id, InstanceStore &result);

                void RemoveId(const std::string& id);
            };
        }
    }
}