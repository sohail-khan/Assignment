// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "CoverageTreeManifest.h"
#include "Streaming.h"


namespace Eegeo
{
    namespace BuildingFootprints
    {
        class IBuildingFootprintResourceCoverageFactory
        {
        public:
            virtual ~IBuildingFootprintResourceCoverageFactory() {}
            virtual IBuildingFootprintResourceCoverage* Create(const Streaming::CoverageTrees::CoverageTreeManifest& coverageTreeManifest) const = 0;
        };
    }
}