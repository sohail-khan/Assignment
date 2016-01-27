// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TcpListenerState.h"
#include "TcpClientCallback.h"

namespace Eegeo
{
    namespace Networking
    {
        class ITcpListener
        {
        public:
            virtual ~ITcpListener() { };
            
            virtual void StartListening(int port) = 0;
            virtual void Update() = 0;
            virtual void StopListening() = 0;
            
            virtual const TcpListenerState::Values GetState() const = 0;
            virtual int GetPort() const = 0;
            
            virtual void AddClientConnectedCallback(ITcpClientCallback& callback) = 0;
            virtual void RemoveClientConnectedCallback(ITcpClientCallback& callback) = 0;
            virtual void AddClientDisconnectedCallback(ITcpClientCallback& callback) = 0;
            virtual void RemoveClientDisconnectedCallback(ITcpClientCallback& callback) = 0;
        };
    }
}