// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IEnvironmentTexturesObserver.h"
#include "EnvironmentTextures.h"
#include "CityThemes.h"
#include "CityThemeState.h"
#include "ThemeStateTransitionController.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ThemeChangeController : protected Eegeo::NonCopyable, public Rendering::IEnvironmentTexturesObserver
            {
            public:
                ThemeChangeController(Rendering::EnvironmentTextures& environmentTextures, ThemeStateTransitionController& themeStateTransitionController)
                : m_environmentTextures(environmentTextures)
                , m_themeStateTransitionController(themeStateTransitionController)
                {
                    environmentTextures.RegisterObserver(*this);
                }
                
                ~ThemeChangeController()
                {
                    m_environmentTextures.RemoveObserver(*this);
                }
                
                void OnTexturesAddedForState(const Resources::CityThemes::CityThemeState& state, const Rendering::EnvironmentStateTextures& stateTextures)
                {
                    if(state.Name == m_themeStateTransitionController.GetTargetStateName())
                    {
                        m_themeStateTransitionController.SetState(state, stateTextures);
                    }
                }
                                    
            private:
                Rendering::EnvironmentTextures& m_environmentTextures;
                ThemeStateTransitionController& m_themeStateTransitionController;
            };
        }
    }
}
