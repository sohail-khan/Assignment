// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CoverageTreeManifest.h"


namespace Eegeo
{
    namespace Streaming
    {
        namespace CoverageTrees
        {
            struct CoverageTreeManifestLoaderResult
            {
                bool DownloadSucceeded;
                bool ParseSucceeded;
                CoverageTreeManifest Manifest;
                
                CoverageTreeManifestLoaderResult()
                : DownloadSucceeded(false)
                , ParseSucceeded(false)
                {}
            };
        }
    }
}
