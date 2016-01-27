// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BaseState.h"
#include "Modules.h"
#include "IChangeStateCallback.h"

namespace Eegeo
{
    class EegeoWorld;
    
    namespace WorldStates
    {
        class DownloadBootstrapResourcesState : public BaseState
        {
            bool m_coverageTreesComplete;
            const bool m_startMapModeAutomatically;
            const bool m_enableInteriors;
            
            Modules::Map::MapModule& m_mapModule;
            
            IChangeStateCallback* m_pChangeStateCallback;
            
            void SetStreams();

            std::string m_stateName;
            
        public:
            DownloadBootstrapResourcesState(std::string stateName, Modules::Map::MapModule& mapModule, bool enableInteriors, bool startMapModeAutomatically);
            
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