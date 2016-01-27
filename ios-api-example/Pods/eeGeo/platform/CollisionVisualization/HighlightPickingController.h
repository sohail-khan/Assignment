// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Collision.h"
#include "Rendering.h"
#include "Modules.h"
#include "PickingController.h"
#include "IInteriorController.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Picking
    {
        class HighlightPickingController : public PickingController
        {
        public:
            HighlightPickingController(Eegeo::Collision::IRayCaster& rayCaster,
                                       Eegeo::Resources::Interiors::IInteriorController& interiorController,
                                       Eegeo::Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            
            ~HighlightPickingController();
            
            void ProcessRayCastResult(const Eegeo::Collision::RayCasterResult& pickResult);
            
        private:
            Eegeo::Resources::Interiors::IInteriorController& m_interiorsController;
        };
    }
}