// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IdTypes.h"
#include "CityThemes.h"
#include <string>
#include <vector>
#include <map>

#define LOG_ENVIRONMENT_TEXTURES_DEBUG_MESSAGES

#if defined (LOG_ENVIRONMENT_TEXTURES_DEBUG_MESSAGES)
#define DEBUG_LOG Eegeo_TTY
#else
#define DEBUG_LOG if (1) {} else Eegeo_TTY
#endif

namespace Eegeo
{
    namespace Rendering
    {        
        class EnvironmentTextures : protected Eegeo::NonCopyable
        {
            
        private:
            typedef std::vector<IEnvironmentTexturesObserver*> TObservers;
            
            typedef std::map<std::string, EnvironmentTexture*> TEnvironmentTextures;
            typedef std::map<std::string, EnvironmentStateTextures*> TEnvironmentStates;
            
            TEnvironmentStates m_currentEnvironmentStates;
            TEnvironmentTextures m_urlToEnvironmentTexture;
            TObservers m_observers;
            
        public:
            ~EnvironmentTextures();
            
            bool HasEnvironmentTexture(const std::string& textureUrl);
            EnvironmentTexture& AddOrUseEnvironmentTexture(const std::string& textureUrl, TTextureId textureId);
            void ReleaseTexturesForAllStates();
            void ReleaseTexturesForState(std::string& stateName);
            void FreeUnusedTextures();
            void AddTexturesForState(const Resources::CityThemes::CityThemeState& state, EnvironmentStateTextures* stateTextures);
            void RegisterObserver(IEnvironmentTexturesObserver& observer);
            void RemoveObserver(IEnvironmentTexturesObserver& observer);
            const EnvironmentStateTextures& GetTexturesForState(const std::string& stateName);
        };
    }
}
