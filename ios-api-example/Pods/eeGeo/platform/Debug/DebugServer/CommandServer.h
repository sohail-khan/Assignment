// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Networking.h"
#include "Commands.h"
#include "CommandTerminal.h"
#include "CommandProcessor.h"
#include "ITcpListener.h"
#include "ITcpClient.h"
#include "CommandCallback.h"
#include "TcpClientCallback.h"

#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace DebugServer
        {
            class CommandServer : public Commands::ICommandTerminalOutput,
                                  protected Eegeo::NonCopyable
            {
            public:
                CommandServer(Networking::ITcpListener& listener,
                              Commands::CommandBuffer& commandBuffer,
                              Commands::CommandProcessor& commandProcessor,
                              Commands::CommandTerminal& commandTerminal);
                ~CommandServer();
                
                void Write(const std::string& str) const;
                
            private:
                void OnData(Networking::ITcpClient& client, char*& data, int& length);
                void OnClientConnected(Networking::ITcpClient& client);
                void OnClientDisconnected(Networking::ITcpClient& client);
                void OnCommandCompleted();

                Networking::ITcpListener& m_listener;
                Commands::CommandBuffer& m_commandBuffer;
                Commands::CommandProcessor& m_commandProcessor;
                Commands::CommandTerminal& m_commandTerminal;
                
                std::vector<Networking::ITcpClient*> m_clients;
                
                typedef Helpers::TCallback3<CommandServer, Networking::ITcpClient, char*, int> TTcpClientDataCallback;
                typedef Helpers::TCallback1<CommandServer, Networking::ITcpClient> TTcpClientCallback;
                
                TTcpClientDataCallback m_clientReadCallback;
                TTcpClientCallback m_clientConnectionCallback;
                TTcpClientCallback m_clientDisconnectionCallback;
                Commands::TCommandCallback<CommandServer> m_commandCompletedCallback;
            };
        }
    }
}