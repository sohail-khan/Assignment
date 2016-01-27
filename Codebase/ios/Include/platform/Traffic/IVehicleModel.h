// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Lighting.h"
#include "Rendering.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Traffic
    {
        class IVehicleModel
        {
        public:
            virtual ~IVehicleModel() {}
            virtual Rendering::SceneModels::SceneModelMeshResource& GetMeshResource() const = 0;
        };
    }
}
