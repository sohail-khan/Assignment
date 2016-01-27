// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemesUpdater
            {
            public:
                virtual ~ICityThemesUpdater() {}

                virtual bool GetEnabled() const = 0;
                virtual void SetEnabled(bool enabled) = 0;
                virtual void Update(float deltaSeconds, const dv3& cameraEcefLocation) = 0;
                virtual void SetThemeMustContain(const std::string& themeMustContain) = 0;
            };
        }
    }
}
