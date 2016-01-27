// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BaseState.h"
#include "IStreamingVolume.h"
#include "Rendering.h"
#include "Modules.h"
#include "IChangeStateCallback.h"
#include "Profile.h"

namespace Eegeo
{
    class EegeoWorld;
    
    namespace WorldStates
    {
        class StreamingInitialSceneState : public BaseState
        {
            Modules::Map::MapModule& m_mapModule;
            Eegeo::Debug::Profile::Profiler& m_profiler;
        
            IChangeStateCallback* m_pChangeStateCallback;
        public:
            StreamingInitialSceneState(std::string stateName,
                                       Modules::Map::MapModule& mapModule,
                                       Eegeo::Debug::Profile::Profiler& profiler);
            
            void Enter();
            
            void Update(float dt,
                        const Camera::RenderCamera& renderCamera,
                        const dv3& ecefInterestPoint,
                        Streaming::IStreamingVolume& streamingVolume);
            
            void Exit();
            
            void SetChangeStateCallback(IChangeStateCallback* changeStateCallback);
        };
    }
}