// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"
#include "ICityThemeChangedObservable.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemesService : public ICityThemeChangedObservable
            {
            public:
                virtual ~ICityThemesService() {}
                virtual bool ThemeChangeInProgress() const = 0;
                virtual const CityThemeData& GetCurrentTheme() const = 0;
                virtual bool HasCurrentTheme() const = 0;
                virtual bool IsStreaming() const = 0;
                virtual void SetSpecificTheme(CityThemeData const & cityTheme) = 0;
                virtual bool RequestTransitionToState(const std::string& stateName, const float transitionSpeed) = 0;
                virtual bool RequestTransitionToGlobeView(const std::string& globeViewStateName, const float transitionSpeed) =0;
                virtual bool RequestTransitionToLastRequestedState(const float transitionSpeed) = 0;
            };
        }
    }
}