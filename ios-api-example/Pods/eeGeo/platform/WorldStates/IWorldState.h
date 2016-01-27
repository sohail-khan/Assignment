// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Camera.h"
#include "Helpers.h"
#include "IChangeStateCallback.h"
#include "IStreamingVolume.h"
#include <string>

namespace Eegeo
{
    namespace WorldStates
    {
        class IWorldState
        {
        public:
            virtual ~IWorldState(){ }
            virtual void Enter() = 0;
            
            virtual void Update(float dt,
                                const Camera::RenderCamera& renderCamera,
                                const dv3& ecefInterestPoint,
                                Streaming::IStreamingVolume& streamingVolume
                                ) = 0;
            
            virtual void Exit() = 0;
            virtual void SetChangeStateCallback(IChangeStateCallback* changeStateCallback) = 0;
            virtual std::string GetStateName() const = 0;
            virtual float GetProgress() const = 0;
        };
    }
}