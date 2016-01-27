// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"
#include "ICallback.h"


namespace Eegeo
{
    namespace CollisionVisualization
    {
        class CollisionStreamingObserver : private Eegeo::NonCopyable
        {
        public:
            CollisionStreamingObserver(Eegeo::Collision::ICollisionBvhProvider& collisionBvhProvider,
                                       MaterialSelectionController& materialSelectionController);
            
            ~CollisionStreamingObserver();
            
            void HandleCollisionResourceChanged();
        private:
            Eegeo::Collision::ICollisionBvhProvider& m_collisionBvhProvider;
            MaterialSelectionController& m_materialSelectionController;
            Helpers::TCallback0<CollisionStreamingObserver> m_collisionResourcesChanged;
        };
    }
}