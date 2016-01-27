// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IVehicleModel.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Traffic
    {
        class VehicleModel : public Eegeo::Traffic::IVehicleModel
        {
            Rendering::SceneModels::SceneModelMeshResource& m_meshResource;
            
        public:
            VehicleModel(Rendering::SceneModels::SceneModelMeshResource& meshResource);
            ~VehicleModel();
            
            Rendering::SceneModels::SceneModelMeshResource& GetMeshResource() const { return m_meshResource; }

        };
    }
}