// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include "Camera.h"
#include "Rendering.h"
#include "CityThemes.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesControllerFactory : protected Eegeo::NonCopyable
            {
            public:
                static PlaceNamesController* CreateForDevice(
                                                             float dpi,
                                                             PlaceNamesRepository& placeNamesRepository,
                                                             const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                             CityThemes::ICityThemesService& cityThemesService
                                                             );
            };
        }
    }
}

