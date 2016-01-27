// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>

#include "CityThemes.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemeAnimatedObjectsObserver
            {
            public:
                virtual void OnApplyThemeAnimatedObjects(std::vector<ModelInfoRef>& modelInfoRefs) = 0;
                virtual ~ICityThemeAnimatedObjectsObserver() {};
            };
        }
    }
}

