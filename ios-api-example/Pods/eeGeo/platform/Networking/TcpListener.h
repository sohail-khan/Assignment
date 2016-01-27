// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <vector>

#include "TcpListenerState.h"
#include "ITcpClient.h"
#include "ITcpListener.h"
#include "TcpClientCallback.h"
#include "Networking.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Networking
    {
        class TcpListener : public ITcpListener, protected Eegeo::NonCopyable
        {
        public:
            TcpListener(ITcpClientFactory& clientFactory);
            ~TcpListener();
            
            void StartListening(int port);
            void Update();
            void StopListening();
            
            void AddClientConnectedCallback(ITcpClientCallback& callback);
            void RemoveClientConnectedCallback(ITcpClientCallback& callback);
            void AddClientDisconnectedCallback(ITcpClientCallback& callback);
            void RemoveClientDisconnectedCallback(ITcpClientCallback& callback);

            const TcpListenerState::Values GetState() const { return m_state; }
            int GetPort() const { return m_port; }
        private:
            void AcceptNewClient();
            
            int m_listenSocketDescriptor;
            int m_port;
            sockaddr_in m_listenSocket;
            std::vector<ITcpClient*> m_clients;
            TcpListenerState::Values m_state;
            ITcpClientFactory& m_clientFactory;
            
            Helpers::CallbackCollection1<ITcpClient> m_connectedCallbacks;
            Helpers::CallbackCollection1<ITcpClient> m_disconnectedCallbacks;
        };
    }
}