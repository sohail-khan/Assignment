// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "CoverageTrees.h"
#include "Web.h"
#include "WebLoadRequestCompletionCallback.h"
#include "ICallback.h"
#include <string>
#include <vector>
#include "PendingWebRequestsContainer.h"
#include "ICoverageTreeManifestLoader.h"
#include "ConfigSections.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Buildings { class BuildingStreaming; }
        namespace Terrain { class TerrainStreaming; }
        namespace Roads { class RoadStreaming; }
        namespace PlaceNames { class PlaceNamesStreaming; }
        namespace Interiors { class InteriorsStreaming; }
    }
    
    namespace Streaming
    {
        namespace BlockCoverageTrees
        {
            class CoverageTreeManifestBinaryLoader: public CoverageTrees::ICoverageTreeManifestLoader, protected Eegeo::NonCopyable
            {
            public:
            
                CoverageTreeManifestBinaryLoader(Web::IWebLoadRequestFactory& webRequestFactory,
                                                 const Config::CoverageTreeConfigSection& coverageTreeConfig);
                
                void LoadCoverageTreeManifest(IManifestLoadedCallback& manifestLoadedCallback);
                
                bool IsStreaming() const { return m_pendingCount > 0; }
                
            private:
                void WebLoadCompletedHandler(Eegeo::Web::IWebResponse& webResponse);
                
                Web::IWebLoadRequestFactory& m_webRequestFactory;
                Config::CoverageTreeConfigSection m_coverageTreeConfig;
                Web::TWebLoadRequestCompletionCallback<CoverageTreeManifestBinaryLoader> m_webLoadFinishedHandler;
                
                int m_pendingCount;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
            };
        }
    }
}
