// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>
#include "WorldStates.h"
#include "Timer.h"
#include "IChangeStateCallback.h"
#include "VectorMathDecl.h"
#include "Camera.h"
#include "IStreamingVolume.h"

namespace Eegeo
{
    namespace WorldStates
    {
        class WorldStateManager
        {
        public:
            WorldStateManager(const std::vector<IWorldState*>& states, const std::vector<float>& progressBarAtStateStarts);
            
            ~WorldStateManager();
            
            void RequestChangeState();
            
            void Update(float dt,
                        const Camera::RenderCamera& renderCamera,
                        const dv3& ecefInterestPoint,
                        Streaming::IStreamingVolume& streamingVolume);
            
            bool IsInLastState() const;
            float GetProgress() const;
            
        private:

            void AddState(IWorldState* stateToAdd, float progressBarAtStateStart, float progressBarAtStateEnd);
            void Start();
            
            void EnterState(IWorldState* stateToEnter);
            void ExitState(IWorldState* stateToExit);

            void ChangeState();
            
            struct StateEntry
            {
                IWorldState* state;
                float progressBarAtStateStart;
                float progressBarAtStateEnd;
                
                StateEntry(IWorldState* state, float progressBarAtStateStart, float progressBarAtStateEnd)
                : state(state), progressBarAtStateStart(progressBarAtStateStart), progressBarAtStateEnd(progressBarAtStateEnd)
                {}
            };
            typedef std::vector<StateEntry> TWorldStatesVec;
            TWorldStatesVec m_worldStates;
            TChangeStateCallback<WorldStateManager> m_changeStateCallback;
            Helpers::Timer m_stateTimer;
            bool m_stateChangeRequested;
        };
    }
}