// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include "Networking.h"
#include "Commands.h"
#include "ITcpListener.h"
#include "CommandBuffer.h"
#include "CommandRegistry.h"
#include "CommandProcessor.h"
#include "CommandParser.h"
#include "TcpListener.h"
#include "CommandServer.h"
#include "TcpClientFactory.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace DebugServer
        {
            class CommandServerModule : protected Eegeo::NonCopyable
            {
            public:
                static const int DefaultPort = 12345;

                CommandServerModule(Commands::CommandBuffer* pBuffer,
                                    Commands::CommandRegistry* pRegistry,
                                    Commands::CommandProcessor* pProcessor,
                                    Commands::CommandParser* pParser,
                                    Commands::CommandTerminal* pTerminal,
                                    DebugServer::CommandServer* pCommandServer,
                                    Networking::ITcpClientFactory* pClientFactory,
                                    Networking::ITcpListener* pTcpListener,
                                    int port=DefaultPort
                                    )
                : m_pBuffer(pBuffer)
                , m_pRegistry(pRegistry)
                , m_pParser(pParser)
                , m_pTerminal(pTerminal)
                , m_pProcessor(pProcessor)
                , m_pClientFactory(pClientFactory)
                , m_pTcpListener(pTcpListener)
                , m_pCommandServer(pCommandServer)
                {
                    Eegeo_ASSERT(pBuffer != NULL);
                    Eegeo_ASSERT(pRegistry != NULL);
                    Eegeo_ASSERT(pParser != NULL);
                    Eegeo_ASSERT(pTerminal != NULL);
                    Eegeo_ASSERT(pProcessor != NULL);
                    Eegeo_ASSERT(pClientFactory != NULL);
                    Eegeo_ASSERT(pTcpListener != NULL);
                    Eegeo_ASSERT(pCommandServer != NULL);

                    m_pTcpListener->StartListening(port);
                }
                
                ~CommandServerModule()
                {
                    Eegeo_DELETE m_pCommandServer;
                    Eegeo_DELETE m_pTcpListener;
                    Eegeo_DELETE m_pClientFactory;
                    Eegeo_DELETE m_pProcessor;
                    Eegeo_DELETE m_pTerminal;
                    Eegeo_DELETE m_pParser;
                    Eegeo_DELETE m_pRegistry;
                    Eegeo_DELETE m_pBuffer;
                }
                
                void Update()
                {
                    m_pTcpListener->Update();
                    while (!m_pBuffer->IsEmpty())
                    {
                        m_pProcessor->Update();
                    }
                }
                
                Commands::CommandRegistry& GetCommandRegistry() const { return *m_pRegistry; }
                Commands::CommandTerminal& GetCommandTerminal() const { return *m_pTerminal; }
                Commands::CommandProcessor& GetCommandProcessor() const { return *m_pProcessor; }
                DebugServer::CommandServer& GetCommandServer() const { return *m_pCommandServer; }
                Networking::ITcpListener& GetTcpListener() const { return *m_pTcpListener; }
                
                static CommandServerModule* BuildDefault()
                {
                    Commands::CommandBuffer* pBuffer = Eegeo_NEW(Commands::CommandBuffer)();
                    Commands::CommandRegistry* pRegistry = Eegeo_NEW(Commands::CommandRegistry)();
                    Commands::CommandParser* pParser = Eegeo_NEW(Commands::CommandParser)();
                    Commands::CommandTerminal* pTerminal = Eegeo_NEW(Commands::CommandTerminal)();
                    Commands::CommandProcessor* pProcessor = Eegeo_NEW(Commands::CommandProcessor)(*pBuffer,
                                                                                                   *pParser,
                                                                                                   *pRegistry,
                                                                                                   *pTerminal);
                    Networking::ITcpClientFactory* pClientFactory = Eegeo_NEW(Networking::TcpClientFactory)();
                    Networking::ITcpListener* pTcpListener = Eegeo_NEW(Networking::TcpListener)(*pClientFactory);
                    
                    CommandServer* pCommandServer = Eegeo_NEW(CommandServer)(*pTcpListener,
                                                                             *pBuffer,
                                                                             *pProcessor,
                                                                             *pTerminal);
                    
                    return Eegeo_NEW(CommandServerModule)(pBuffer,
                                                          pRegistry,
                                                          pProcessor,
                                                          pParser,
                                                          pTerminal,
                                                          pCommandServer,
                                                          pClientFactory,
                                                          pTcpListener);
                }

            private:
                Commands::CommandBuffer* m_pBuffer;
                Commands::CommandRegistry* m_pRegistry;
                Commands::CommandParser* m_pParser;
                Commands::CommandTerminal* m_pTerminal;
                Commands::CommandProcessor* m_pProcessor;
                Networking::ITcpClientFactory* m_pClientFactory;
                Networking::ITcpListener* m_pTcpListener;
                DebugServer::CommandServer* m_pCommandServer;
            };
        }
    }
}
