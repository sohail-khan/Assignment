// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ITaskWorkerRunner.h"

namespace Eegeo
{
    namespace Concurrency
    {
        class ITaskWorkerRunner
        {
        public:
            virtual ~ITaskWorkerRunner() { };
            virtual void RequestStop() = 0;
            virtual void Start() = 0;
            virtual void Stop() = 0;
            virtual bool IsRunning() const = 0;
        };
    }
}

