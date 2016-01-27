// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "CollisionVisualization.h"
#include "Rendering.h"
#include "Collision.h"
#include "Types.h"

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintSelectionViewFactory : private Eegeo::NonCopyable
        {
        public:
            BuildingFootprintSelectionViewFactory(BuildingFootprintSelectionRenderableFactory& renderableFactory)
            : m_renderableFactory(renderableFactory)
            {}
            
            BuildingFootprintSelectionView* Create(const BuildingFootprintSelectionModel& model);
        private:
            BuildingFootprintSelectionRenderableFactory& m_renderableFactory;
        };
    }
}

