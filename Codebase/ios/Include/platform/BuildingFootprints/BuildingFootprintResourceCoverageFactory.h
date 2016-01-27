// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "IBuildingFootprintResourceCoverageFactory.h"
#include "Types.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintResourceCoverageFactory : public IBuildingFootprintResourceCoverageFactory, private Eegeo::NonCopyable
        {
        public:
            BuildingFootprintResourceCoverageFactory(const Streaming::IResourceStream& resourceStream,
                                                     const BuildingFootprintResourceStore& resourceStore)
            : m_resourceStream(resourceStream)
            , m_resourceStore(resourceStore)
            {}
            
            IBuildingFootprintResourceCoverage* Create(const Streaming::CoverageTrees::CoverageTreeManifest& coverageTreeManifest) const;
        private:
            const Streaming::IResourceStream& m_resourceStream;
            const BuildingFootprintResourceStore& m_resourceStore;
        };
    }
}