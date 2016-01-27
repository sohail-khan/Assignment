// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Concurrency
    {
        class IRunnable
        {
        public:
            virtual ~IRunnable() { };
            virtual bool operator()() = 0;
            virtual void OnStarted() = 0;
            virtual void OnStopped() = 0;
        };
    }
}
