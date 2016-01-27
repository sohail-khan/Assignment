// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <netinet/in.h>
#include "ITcpClient.h"

namespace Eegeo
{
    namespace Networking
    {
        class ITcpClientFactory
        {
        public:
            virtual ~ITcpClientFactory() { }
            virtual ITcpClient* Build(int clientSocketFileDescriptor,
                                        sockaddr_in clientSocket) = 0;
        };
    }
}