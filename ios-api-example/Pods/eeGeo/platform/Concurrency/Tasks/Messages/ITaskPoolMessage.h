// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMessage.h"
#include "ITaskPoolMessageDispatcher.h"

namespace Eegeo
{
    namespace Concurrency
    {
    	namespace Tasks
    	{
    		namespace Messages
    		{
				class ITaskPoolMessage : public Eegeo::Messaging::IMessage<ITaskPoolMessageDispatcher>
				{
				};
    		}
    	}
    }
}


