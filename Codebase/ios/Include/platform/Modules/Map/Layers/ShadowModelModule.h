// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class ShadowModelModule : protected Eegeo::NonCopyable
                {
                public:
                    ShadowModelModule();
                    ~ShadowModelModule();
                    static ShadowModelModule* Create();
                    
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& GetShadowSceneElementRepository() const;
                    
                private:
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>* m_pShadowSceneElementRepository;
                };
            }
        }
    }
}