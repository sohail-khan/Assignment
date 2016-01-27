// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BuildingFootprints.h"
#include "Web.h"
#include "BuildingFootprintWebLoader.h"
#include "MortonKey.h"
#include "ICallback.h"
#include "BuildingFootprintResourceStore.h"
#include "Streaming.h"
#include "CoverageTrees.h"


#include <string>
#include <vector>
#include <map>


namespace Eegeo
{
    namespace BuildingFootprints
    {
        struct BuildingFootprintWebLoaderRequest;
        

        
        class BuildingFootprintResourceService : public Eegeo::NonCopyable
        {
        public:
            struct LoadForKeyResult
            {
                const bool Succeeded;
                const bool NotFound;
                const Streaming::MortonKey Key;
                
                LoadForKeyResult(bool succeeded, bool notFound, const Streaming::MortonKey& key)
                : Succeeded(succeeded)
                , NotFound(notFound)
                , Key(key)
                {}
            };
            
            typedef Helpers::ICallback1<const LoadForKeyResult> ILoadForKeyCallback;
            
            
            BuildingFootprintResourceService(BuildingFootprintWebLoader& buildingFootprintWebLoader,
                                             BuildingFootprintRepository& buildingFootprintRepository,
                                             const IBuildingFootprintResourceCoverageFactory& buildingFootprintResourceCoverageFactory,
                                             Eegeo::Streaming::CoverageTrees::CoverageTreeManifestNotifier& coverageTreeManifestNotifier);
            
            virtual ~BuildingFootprintResourceService();
            
            
            virtual void LoadForKey(const Eegeo::Streaming::MortonKey& cellKey, ILoadForKeyCallback& callback);
            
            virtual void DestroyForKey(const Eegeo::Streaming::MortonKey& cellKey);
            
            virtual void DestroyAll();
            
            virtual void CoverageTreeManifestLoadedHandler(const Streaming::CoverageTrees::CoverageTreeManifest& coverageTreeManifest);

        private:
            bool TryComposeUrlFor(const Eegeo::Streaming::MortonKey& key, std::string& out_url) const;
            
            BuildingFootprintWebLoader& m_buildingFootprintWebLoader;
            BuildingFootprintRepository& m_buildingFootprintRepository;
            const IBuildingFootprintResourceCoverageFactory& m_buildingFootprintResourceCoverageFactory;
            Streaming::CoverageTrees::CoverageTreeManifestNotifier& m_coverageTreeManifestNotifier;
            IBuildingFootprintResourceCoverage* m_pBuildingFootprintResourceCoverage;
            
            typedef Eegeo::Helpers::TCallback1<BuildingFootprintResourceService, const Streaming::CoverageTrees::CoverageTreeManifest> CoverageTreeManifestLoadedCallback;
            CoverageTreeManifestLoadedCallback m_coverageTreeManifestLoadedCallback;
        };
    }
}