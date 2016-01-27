// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ICityThemesService.h"
#include "Types.h"
#include "Rendering.h"
#include "CityThemes.h"
#include "CityThemeData.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemesService : public ICityThemesService, protected Eegeo::NonCopyable
            {
            public:
                CityThemesService(
                        CityThemesTextureUpdater& themeTextureUpdater,
                        CityThemesAnimatedObjectsLoader& animatedObjectsLoader,
                        ThemeStateTransitionController& themeStateTransitionController,
                        Rendering::EnvironmentTextures& environmentTextures);
                
                bool ThemeChangeInProgress() const { return m_themeChangeInProgress; }
                const CityThemeData& GetCurrentTheme() const { return m_currentTheme; }
                
                void RegisterThemeChangedObserver(ICityThemeChangedObserver& observerToAdd);
                void UnregisterThemeChangedObserver(ICityThemeChangedObserver& observerToRemove);
                
                bool HasCurrentTheme() const { return !m_currentTheme.Name.empty(); }
                
                bool IsStreaming() const;
                
                void Update(float deltaSeconds);
                void SetSpecificTheme(CityThemeData const & newTheme);
                
                bool RequestTransitionToState(const std::string& stateName, const float transitionSpeed);
                bool RequestTransitionToGlobeView(const std::string& globeViewStateName, const float transitionSpeed);
                bool RequestTransitionToLastRequestedState(const float transitionSpeed);

            private:
                bool BeginTransitionToState(const std::string& stateName, const float transitionSpeed);
                
                void NotifyChanged(const CityThemeData& newTheme);
                void NotifyRequsted(const CityThemeData& newTheme);
                void ApplyTheme(const CityThemeData& newTheme);
                
                CityThemesTextureUpdater& m_themeTextureUpdater;
                CityThemesAnimatedObjectsLoader& m_animatedObjectsLoader;
                ThemeStateTransitionController& m_themeStateTransitionController;
                Rendering::EnvironmentTextures& m_environmentTextures;
                
                CityThemeData m_currentTheme;
                CityThemeData m_targetTheme;
                bool m_themeChangeInProgress;
                bool m_enabled;
                std::string m_lastRequestedState;
                                
                typedef std::vector<ICityThemeChangedObserver*> TThemeChangedObservers;
                TThemeChangedObservers m_observers;
            };
        }
    }
}