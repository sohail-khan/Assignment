// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "CityThemes.h"

namespace Eegeo
{
    namespace Rendering
    {
        class IEnvironmentTexturesObserver
        {
        public:
            virtual void OnTexturesAddedForState(const Resources::CityThemes::CityThemeState& state, const EnvironmentStateTextures& stateTextures) = 0;
            virtual ~IEnvironmentTexturesObserver() {} ;
        };
    }
}