// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "GeofenceViewFactory.h"
#include "GeofenceController.h"
#include "GeofenceRenderer.h"
#include "RenderableFilters.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Data
        {
            class GeofenceModule : private Eegeo::NonCopyable
            {
            public:
                static GeofenceModule* Create(Modules::Core::RenderingModule& renderingModule);

                GeofenceModule(
                        Eegeo::Data::Geofencing::GeofenceController* pController,
                        Eegeo::Data::Geofencing::GeofenceViewFactory* pViewFactory,
                        Eegeo::Data::Geofencing::GeofenceRenderer* pRenderer,
                        Eegeo::Rendering::RenderableFilters& renderableFilters);

                ~GeofenceModule();

                Eegeo::Data::Geofencing::GeofenceController& GetController() { return *m_pController; }
                Eegeo::Data::Geofencing::GeofenceViewFactory& GetViewFactory() { return *m_pViewFactory; }
                Eegeo::Data::Geofencing::GeofenceRenderer& GetRenderer() { return *m_pRenderer; }

            private:
                Eegeo::Data::Geofencing::GeofenceController* m_pController;
                Eegeo::Data::Geofencing::GeofenceViewFactory* m_pViewFactory;
                Eegeo::Data::Geofencing::GeofenceRenderer* m_pRenderer;
                Eegeo::Rendering::RenderableFilters& m_renderableFilters;
            };
        }
    }
}

