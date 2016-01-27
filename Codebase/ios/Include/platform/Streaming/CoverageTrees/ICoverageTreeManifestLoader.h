#pragma once

#include "Types.h"
#include "CoverageTrees.h"
#include "ICallback.h"
#include "CoverageTreeManifestLoaderResult.h"

namespace Eegeo
{
    namespace Streaming
    {
        namespace CoverageTrees
        {
            class ICoverageTreeManifestLoader
            {
            public:
                typedef Helpers::ICallback1<const CoverageTreeManifestLoaderResult> IManifestLoadedCallback;
                
                virtual ~ICoverageTreeManifestLoader() {}
                
                virtual void LoadCoverageTreeManifest(IManifestLoadedCallback& manifestLoadedCallback) = 0;
                
                virtual bool IsStreaming() const = 0;
            };
        }
    }
}
