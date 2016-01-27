// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ITcpClientFactory.h"
#include "Types.h"
#include <netinet/in.h>

namespace Eegeo
{
    namespace Networking
    {
        class TcpClientFactory : public ITcpClientFactory, protected Eegeo::NonCopyable
        {
        public:
            ITcpClient* Build(int clientSocketFileDescriptor,
                                sockaddr_in clientSocket);
        };
    }
}