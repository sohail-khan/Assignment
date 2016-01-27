// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AsyncModels.h"

namespace Eegeo
{
    namespace Io
    {
        namespace AsyncModels
        {
            class IAsyncModelObserver
            {
            public:
            	virtual ~IAsyncModelObserver() {};
                virtual void OnModelLoadSuccess(const IAsyncModel& loadedModel) = 0;
                virtual void OnModelLoadFail(const IAsyncModel& loadedModel) = 0;
            };
        }
    }
}
