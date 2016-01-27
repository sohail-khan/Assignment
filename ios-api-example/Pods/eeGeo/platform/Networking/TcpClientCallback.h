// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Networking.h"
#include "ICallback.h"

namespace Eegeo
{
    namespace Networking
    {
        typedef Helpers::ICallback3<ITcpClient, char*, int> ITcpClientDataCallback;
        typedef Helpers::ICallback1<ITcpClient> ITcpClientCallback;
    }
}