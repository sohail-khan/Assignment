// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>

#include "ICityThemeAnimatedObjectsObserver.h"
#include "CityThemes.h"
#include "AnimatedObjects.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeAnimatedObjectsObserver : protected ICityThemeAnimatedObjectsObserver
            {
            public:
                CityThemeAnimatedObjectsObserver(AnimatedObjects::AnimatedObjectsRepository& animatedObjectsRepository,
                                                 CityThemesAnimatedObjectsLoader& cityThemesAnimatedObjectsLoader);
                
                ~CityThemeAnimatedObjectsObserver();
            private:
                void OnApplyThemeAnimatedObjects(std::vector<ModelInfoRef>& modelInfoRefs) ;
                
                AnimatedObjects::AnimatedObjectsRepository& m_animatedObjectsRepository;
                CityThemesAnimatedObjectsLoader& m_cityThemesAnimatedObjectsLoader;
            };
        }
    }
}
