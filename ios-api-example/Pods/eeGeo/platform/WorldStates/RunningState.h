// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BaseState.h"
#include "Modules.h"
#include "Profiler.h"

#include <string>

namespace Eegeo
{
    namespace WorldStates
    {
        class RunningState : public BaseState
        {
            Modules::Map::MapModule& m_mapModule;
            Modules::TrafficModule& m_trafficModule;
            Modules::AnimatedObjectsModule& m_animatedObjectsModule;
            Modules::RoutesModule& m_routesModule;
            Modules::Core::DebugRenderingModule& m_debugRenderingModule;
            Debug::Profile::Profiler& m_profiler;
            
        public:
            RunningState(std::string stateName,
                         Modules::Map::MapModule& mapModule,
                         Modules::TrafficModule& trafficModule,
                         Modules::AnimatedObjectsModule& animatedObjectsModule,
                         Modules::RoutesModule& routesModule,
                         Modules::Core::DebugRenderingModule& debugRenderingModule,
                         Debug::Profile::Profiler& profiler);
            
            void Enter();
            
            void Update(float dt,
                        const Camera::RenderCamera& renderCamera,
                        const dv3& ecefInterestPoint,
                        Streaming::IStreamingVolume& streamingVolume);
            
            void Exit();
            
            void SetChangeStateCallback(IChangeStateCallback* changeStateCallback){ }
        };
    }
}