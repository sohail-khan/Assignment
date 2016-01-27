// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CoverageTrees.h"
#include "Streaming.h"
#include "ICallback.h"
#include "CallbackCollection.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Streaming
    {
        namespace CoverageTrees
        {
            class CoverageTreeManifestNotifier : private Eegeo::NonCopyable
            {
            public:
                typedef Eegeo::Helpers::ICallback1<const CoverageTreeManifest> INotifyManifestLoadedCallback;
                
                void AddManifestLoadedObserver(INotifyManifestLoadedCallback& callback);
                void RemoveManifestLoadedObserver(INotifyManifestLoadedCallback& callback);
                
                void NotifyManifestLoaded(const CoverageTreeManifest& coverageTreeManifest);
            private:
            
                Eegeo::Helpers::CallbackCollection1<const CoverageTreeManifest> m_manifestLoadedObservers;
            };
        
        }
    }
}