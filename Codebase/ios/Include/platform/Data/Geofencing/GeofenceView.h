// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "UniformColoredRenderable.h"
#include "GeofenceModel.h"

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            class GeofenceView : private Eegeo::NonCopyable
            {
            public:
                GeofenceView(GeofenceModel& model, Rendering::Renderables::UniformColoredRenderable* pRenderable);
                void Update();

                GeofenceModel& GetModel();
                Rendering::Renderables::UniformColoredRenderable* GetRenderable();
            private:
                GeofenceModel& m_model;
                Rendering::Renderables::UniformColoredRenderable* m_pRenderable;
            };
        }
    }
}

