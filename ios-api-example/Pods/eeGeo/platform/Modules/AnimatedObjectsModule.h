// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Lighting.h"
#include "AnimatedObjects.h"
#include "CityThemes.h"
#include "VectorMathDecl.h"
#include "Camera.h"

namespace Eegeo
{
    namespace Modules
    {
        class AnimatedObjectsModule : protected Eegeo::NonCopyable
        {
            Eegeo::AnimatedObjects::AnimatedObjectsRepository* m_pAnimatedObjectsRepository;
            Eegeo::AnimatedObjects::AnimatedObjectsController* m_pAnimatedObjectsController;
            Eegeo::AnimatedObjects::AnimatedObjectsRenderer* m_pAnimatedObjectsRenderer;
            Eegeo::Rendering::Renderables::TemporaryLegacySupport::AnimatedObjectsRenderable* m_pAnimatedObjectsRenderable;
            Resources::CityThemes::CityThemeAnimatedObjectsObserver* m_pCityThemesAnimatedObjectsObserver;
            Eegeo::Rendering::Materials::NullMaterial* m_pAnimatedObjectsNullMaterial;
            
            Rendering::Filters::RenderableRepository& m_renderableRepository;
            
            AnimatedObjectsModule(Rendering::Materials::NullMaterialFactory& nullMaterialFactory,
                                  Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                  Lighting::GlobalFogging& globalFogging,
                                  Rendering::Filters::RenderableRepository& renderableRepository,
                                  Resources::CityThemes::CityThemesAnimatedObjectsLoader& cityThemesAnimatedObjectsLoader);
            
        public:
            static AnimatedObjectsModule* Create(
                    Modules::Core::CoreModule& coreModule,
                    Modules::Map::MapModule& mapModule);
            
            ~AnimatedObjectsModule();
            
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            
            AnimatedObjects::AnimatedObjectsRepository& GetAnimatedObjectsRepository() const;
            AnimatedObjects::AnimatedObjectsController& GetAnimatedObjectsController() const;
        };
    }
}
