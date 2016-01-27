// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Streaming.h"
#include "SceneGraphCellCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        class RoutingSceneGraphObserver : public Eegeo::NonCopyable
        {
            Streaming::SceneGraphCellRepository& m_sceneGraphCellRepository;
            Fitting::RouteFittingService& m_routeFittingService;
            
            Streaming::TSceneGraphCellCallback<RoutingSceneGraphObserver> m_addedCallback;
            Streaming::TSceneGraphCellCallback<RoutingSceneGraphObserver> m_removalCallback;
            
            void HandleCellAdded(const Streaming::MortonKey& key);
            void HandleCellRemoved(const Streaming::MortonKey& key);
            
        public:
            RoutingSceneGraphObserver(Streaming::SceneGraphCellRepository& sceneGraphCellRepository,
                                      Fitting::RouteFittingService& routeFittingService);
            
            ~RoutingSceneGraphObserver();
        };
    }
}
