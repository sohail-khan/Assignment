// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AnimatedObjects.h"

#include <vector>

namespace Eegeo
{
    namespace AnimatedObjects
    {
        class AnimatedObjectsRepository : protected Eegeo::NonCopyable
        {
        public:
            AnimatedObjectsRepository();
            ~AnimatedObjectsRepository();
            
            void Add(AnimatedObject& animatedObject);
            void Clear();
            
            int GetAnimatedObjectCount() const { return static_cast<int>(m_animatedObjects.size()); }
            AnimatedObject* GetAnimatedObjectAt(int index) const;
    
        private:
            std::vector<AnimatedObject*> m_animatedObjects;
        };
    }
}