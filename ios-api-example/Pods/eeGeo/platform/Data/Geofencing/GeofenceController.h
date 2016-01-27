// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Geofencing.h"
#include "GeofenceRenderer.h"
#include "GeofenceViewFactory.h"
#include "DataEntityController.h"
#include <map>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            struct GeofenceArgs
            {
                typedef TGeofenceId TId;
                typedef GeofenceModel TModel;
                typedef GeofenceView TView;
                typedef GeofenceViewFactory TViewFactory;
                typedef GeofenceRenderer TRenderableFilter;
            };
            
            class GeofenceController : public Data::DataEntityController<GeofenceArgs>
            {
            public:
                GeofenceController(GeofenceViewFactory& viewFactory, GeofenceRenderer& renderableFilter)
                : DataEntityController(viewFactory, renderableFilter)
                {
                }

            };
        }
    }
}

