// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "ThemeStateController.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ThemeStateTransitionController
            {
            public:
                ThemeStateTransitionController(
                        const std::string& initialStateName,
                        ThemeStateController& themeStateController)
                : m_themeStateController(themeStateController)
                , m_targetStateName(initialStateName)
                , m_pTargetState(NULL)
                , m_pTargetStateTextures(NULL)            
                , m_transitionParam(0.0f)
                , m_transitionSpeed(0.0f)
                {
                }
                
                void StartTransitionToState(const Resources::CityThemes::CityThemeState& targetState, const Rendering::EnvironmentStateTextures& targetStateTextures, float transitionSpeed )
                {
                    m_pTargetState = &targetState;
                    m_pTargetStateTextures = &targetStateTextures;
                    m_targetStateName = m_pTargetState->Name;
                    
                    m_themeStateController.StartTransitionToState(targetState, targetStateTextures);
                    
                    m_transitionParam = 0.0f;
                    m_transitionSpeed = transitionSpeed;
                }
                
                void SetState(const Resources::CityThemes::CityThemeState& targetState, const Rendering::EnvironmentStateTextures& targetStateTextures)
                {
                    m_pTargetState = &targetState;
                    m_pTargetStateTextures = &targetStateTextures;
                    m_targetStateName = m_pTargetState->Name;
                    
                    m_themeStateController.SetState(targetState, targetStateTextures);
                    
                    m_transitionParam = 0.0f;
                    m_transitionSpeed = 0.0f;
                }
                
                void Update(float dt, const dv3& ecefInterestPoint)
                {
                    m_transitionParam += (dt * m_transitionSpeed);
                    
                    if(m_transitionParam < 1.0f)
                    {
                        m_themeStateController.SetTransition(m_transitionParam, ecefInterestPoint);
                    }
                    else
                    {
                        m_transitionParam = 0.0f;
                        m_transitionSpeed = 0.0f;
                        m_themeStateController.SetState(*m_pTargetState, *m_pTargetStateTextures);
                        m_themeStateController.SetTransition(m_transitionParam, ecefInterestPoint);
                    }
                }
                
                const std::string& GetTargetStateName() const
                {
                    return m_targetStateName;
                }
                
            private:
                ThemeStateController& m_themeStateController;
                
                std::string m_targetStateName;
                const Resources::CityThemes::CityThemeState* m_pTargetState;
                const Rendering::EnvironmentStateTextures* m_pTargetStateTextures;
                       
                float m_transitionParam;
                float m_transitionSpeed;
            };
        }
    }
}
