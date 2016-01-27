// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITcpClient.h"
#include "TcpClientCallback.h"
#include "CallbackCollection.h"

#include <vector>
#include <netinet/in.h>

namespace Eegeo
{
    namespace Networking
    {
        class TcpClient : public ITcpClient, protected Eegeo::NonCopyable
        {
        public:
            TcpClient(int clientSocketFileDescriptor,
                      sockaddr_in clientSocket);
            ~TcpClient();
            
            int GetSocketFileDescriptor() const { return m_clientSocketFileDescriptor; }
            const sockaddr_in GetSocket() const { return m_clientSocket; }
            
            bool Read();
            void Write(const char* data, int length) const;
            void Close();

            void AddReadCallback(ITcpClientDataCallback& readCallback);
            void RemoveReadCallback(ITcpClientDataCallback& readCallback);
            void AddCloseCallback(ITcpClientCallback& closeCallback);
            void RemoveCloseCallback(ITcpClientCallback& closeCallback);
        private:
            int m_clientSocketFileDescriptor;
            sockaddr_in m_clientSocket;
            
            Helpers::CallbackCollection3<ITcpClient, char*, int> m_readCallbacks;
            Helpers::CallbackCollection1<ITcpClient> m_closeCallbacks;
            
            const static int MaxBuffer = 1024;
            char m_buffer[MaxBuffer];
        };
    }
}