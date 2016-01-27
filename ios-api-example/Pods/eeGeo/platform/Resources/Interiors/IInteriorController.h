// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorController
            {
            public:
                virtual ~IInteriorController() {}
                
                virtual void SetCurrentFloor(int floor, bool snap=false) = 0;
                virtual int GetCurrentFloorIndex() const = 0;
                
                virtual bool InteriorInScene() const = 0;
                virtual bool InteriorIsVisible() const = 0;
                
                virtual bool TryGetCurrentModel(const Resources::Interiors::InteriorsModel*& out_pModel) = 0;
                virtual bool TryGetCurrentFloorModel(const Resources::Interiors::InteriorsFloorModel*& out_pModel) = 0;
                
                virtual void ClearSelectedInterior() = 0;
                // TODO: Selection of Interiors.
            };
        }
    }
}