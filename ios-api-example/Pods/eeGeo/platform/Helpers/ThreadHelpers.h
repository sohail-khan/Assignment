// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
	namespace Helpers
	{
        namespace ThreadHelpers
		{
            bool IsMainThread();

            void USleep(u32 usec);
        }
    }
}