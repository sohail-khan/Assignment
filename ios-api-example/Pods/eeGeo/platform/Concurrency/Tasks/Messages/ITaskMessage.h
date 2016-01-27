// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMessage.h"
#include "ITaskMessageDispatcher.h"

namespace Eegeo
{
    namespace Concurrency
    {
    	namespace Tasks
    	{
    		namespace Messages
    		{
				class ITaskMessage : public Eegeo::Messaging::IMessage<ITaskMessageDispatcher>
				{
				};
    		}
    	}
    }
}

