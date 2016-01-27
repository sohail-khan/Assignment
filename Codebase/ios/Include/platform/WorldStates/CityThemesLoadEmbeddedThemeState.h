// Copyright eeGeo Ltd (2012-2015), All Rights Reserved
#pragma once

#include "BaseState.h"
#include "CityThemes.h"
#include "Modules.h"

namespace Eegeo
{
    namespace WorldStates
    {
        class CityThemesLoadEmbeddedThemeState : public BaseState
        {
        public:
            CityThemesLoadEmbeddedThemeState(
                    const std::string& stateName,
                    Eegeo::Modules::Map::CityThemesModule& cityThemesModule);

            virtual void Enter();

            virtual void Update(float dt,
                    const Camera::RenderCamera& renderCamera,
                    const dv3& ecefInterestPoint,
                    Streaming::IStreamingVolume& streamingVolume);

            virtual void Exit();

            void SetChangeStateCallback(IChangeStateCallback* changeStateCallback);

        private:
            Eegeo::Modules::Map::CityThemesModule& m_cityThemesModule;
            IChangeStateCallback* m_pChangeStateCallback;
        };
    }
}
