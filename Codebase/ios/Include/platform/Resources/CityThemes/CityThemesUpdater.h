// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ICityThemesUpdater.h"
#include "CityThemes.h"
#include "Types.h"
#include "Camera.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            
            class CityThemesUpdater : public ICityThemesUpdater, protected Eegeo::NonCopyable
            {
            public:
                CityThemesUpdater(const CityThemeRepository& repository,
                                 ICityThemesService& themeService,
                                  CityThemesMissingDataHandler& cityThemesMissingDataHandler,
                                 float cameraLocationDeltaThreshold,
                                 float maxAltitudeForUpdate,
                                 const std::string& themeMustContain);
                
                void Update(float deltaSeconds, const dv3& cameraEcefPosition);
                bool GetEnabled() const { return m_enabled; }
                void SetEnabled(bool enabled) { m_enabled = enabled; }
                
                void SetThemeMustContain(const std::string& themeMustContain);
            private:
                const CityThemeRepository& m_cityThemeRepository;
                ICityThemesService& m_themeService;
                CityThemesMissingDataHandler& m_cityThemesMissingDataHandler;
                
                const float m_cameraLocationDeltaThreshold;
                const float m_maxAltitudeForUpdate;

                void TryChangeTheme(const dv3& cameraEcefLocation);
                
                Eegeo::dv3 m_locationLastUpdate;
                bool m_enabled;
                bool m_shouldTryChangeTheme;
                
                std::string m_themeMustContain;
                
                std::string m_globeViewStateName;
                float m_globeViewAltitude;
                bool m_atAltitude;
            };
            
        }
    }
}