// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "IBuildingFootprintResourceCoverage.h"
#include "Types.h"
#include "CoverageTreeManifest.h"
#include "Streaming.h"

#include <map>
#include <string>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintResourceCoverage : public IBuildingFootprintResourceCoverage, private Eegeo::NonCopyable
        {
        public:
            typedef std::map<const Eegeo::Streaming::ResourceStreamComponent*, const std::string> StreamComponentToStorePrefix;
            
            BuildingFootprintResourceCoverage(const Streaming::IResourceStream& buildingResourceStream,
                                              const BuildingFootprintResourceStore& resourceStore,
                                              const StreamComponentToStorePrefix& streamComponentToStorePrefix)
            : m_buildingResourceStream(buildingResourceStream)
            , m_buildingFootprintResourceStore(resourceStore)
            , m_streamComponentToStorePrefix(streamComponentToStorePrefix)
            {}
            
            bool TryComposeUrlFor(const Eegeo::Streaming::MortonKey& key, std::string& out_url) const;
            
        private:
            const Streaming::IResourceStream& m_buildingResourceStream;
            const BuildingFootprintResourceStore& m_buildingFootprintResourceStore;
            
            const StreamComponentToStorePrefix m_streamComponentToStorePrefix;
            
        };
    }
}