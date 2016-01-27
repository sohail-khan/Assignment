// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "ProfileRecord.h"
#include "PoolItemFactory.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            class ProfileRecordFactory : public Eegeo::DataStructures::PoolItemFactory<Eegeo::Debug::Profile::ProfileRecord*>
            {
            public:
                virtual Eegeo::Debug::Profile::ProfileRecord* CreateItem();
            };

        }
    }
}