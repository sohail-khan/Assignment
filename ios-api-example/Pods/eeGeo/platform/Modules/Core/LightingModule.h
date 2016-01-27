// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Lighting.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class LightingModule : protected Eegeo::NonCopyable
            {
            public:
                LightingModule();
                
                ~LightingModule();
                static LightingModule* Create();
                
                Lighting::GlobalShadowing& GetGlobalShadowing() const;
                Lighting::GlobalLighting& GetGlobalLighting() const;
                Lighting::GlobalFogging& GetGlobalFogging() const;
                
            private:
                Lighting::GlobalShadowing* m_pGlobalShadowing;
                Lighting::GlobalLighting* m_pGlobalLighting;
                Lighting::GlobalFogging* m_pGlobalFogging;
            };
        }
    }
}