// Copyright eeGeo Ltd (2012-2016), All Rights Reserved
#pragma once

#include "BaseState.h"
#include "AlertBox.h"
#include "Web.h"
#include "ISingleOptionAlertBoxDismissedHandler.h"

namespace Eegeo
{
    namespace WorldStates
    {
        class ConnectivityHealthCheckState : public BaseState
        {
        public:
            ConnectivityHealthCheckState(const std::string& stateName,
                                         Web::WebConnectivityValidator& connectivityValidator,
                                         const Web::WebConnectivityErrorHandler& connectivityErrorHandler);
            
            virtual void Enter();
            
            virtual void Update(float dt,
                                const Camera::RenderCamera& renderCamera,
                                const dv3& ecefInterestPoint,
                                Streaming::IStreamingVolume& streamingVolume);
            
            virtual void Exit();
            
            void SetChangeStateCallback(IChangeStateCallback* changeStateCallback);
            
        private:
            
            void OnDismiss();
            
            Web::WebConnectivityValidator& m_connectivityValidator;
            const Web::WebConnectivityErrorHandler& m_connectivityErrorHandler;
            IChangeStateCallback* m_pChangeStateCallback;
        };
    }
}
