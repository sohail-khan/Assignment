//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "FrameProfile.h"
#include "PoolItemFactory.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            class FrameProfileFactory : public Eegeo::DataStructures::PoolItemFactory<Eegeo::Debug::Profile::FrameProfile*>
            {
            public:
                virtual Eegeo::Debug::Profile::FrameProfile* CreateItem();
            };
        }
    }
}
