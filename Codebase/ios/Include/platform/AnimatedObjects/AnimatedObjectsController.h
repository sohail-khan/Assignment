// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AnimatedObjects.h"
#include "Camera.h"
#include "VectorMathDecl.h"
#include "Models.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace AnimatedObjects
    {
        const float HeightFadedIn = 5000.f;
        const float HeightFadedOut = 8000.f;
        
        class AnimatedObjectsController : protected Eegeo::NonCopyable
        {
        public:
            AnimatedObjectsController(AnimatedObjectsRepository& repository,
                                      Rendering::EnvironmentFlatteningService& environmentFlatteningService)
            : m_animatedObjectsRepository(repository)
            , m_environmentFlatteningService(environmentFlatteningService)
            {
            }
            
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            
        private:
            
            void SetModelAlphaFromAltitude(const float cameraAltitude, Model& model);
            void UpdateTransformsAndVisibility(const Camera::RenderCamera& renderCamera, AnimatedObject& animatedObject);
            
            AnimatedObjectsRepository& m_animatedObjectsRepository;
            Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
        };
    }
}
