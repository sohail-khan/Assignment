// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AnimatedObjects.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMath.h"

namespace Eegeo
{
    class Model;
    
    namespace AnimatedObjects
    {    
        class AnimatedObjectsRenderer : protected Eegeo::NonCopyable
        {
        public:
            AnimatedObjectsRenderer(const AnimatedObjectsRepository& repository,
                Lighting::GlobalFogging& globalFogging
                );
            void Render(Eegeo::Rendering::GLState& glState);

            
        private:
            const AnimatedObjectsRepository& m_animatedObjectsRepository;
            Lighting::GlobalFogging& m_globalFogging;
        };
    }
}
