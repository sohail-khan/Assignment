// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "BaseState.h"
#include "Web.h"

namespace Eegeo
{
    namespace WorldStates
    {
        class ValidateApiTokenState : public BaseState
        {
            Web::ApiTokenValidator& m_apiTokenValidator;
            const std::string m_apiToken;
            
            IChangeStateCallback* m_pChangeStateCallback;
        public:
            ValidateApiTokenState(std::string stateName,
                                  const std::string& apiToken,
                                  Web::ApiTokenValidator& apiTokenValidator);
            
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