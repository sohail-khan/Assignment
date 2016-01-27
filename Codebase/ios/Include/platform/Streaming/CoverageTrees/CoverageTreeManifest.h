// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include <vector>
#include "BlockCoverageTrees.h"

namespace Eegeo
{
    namespace Streaming
    {
        namespace CoverageTrees
        {
            struct InlineKeySet
            {
                std::vector<std::string> Keys;
                int MinLevel;
                int MaxLevel;
                
                InlineKeySet()
                : MinLevel(0)
                , MaxLevel(0)
                {}
            };
            
            struct CoverageTreeManifestItem
            {
                std::string Name;
                std::string StoreRelativePath;
                std::string FeatureRelativePath;
                std::string ResourceName;
                std::string Extension;
                int StreamPriority;
                bool IsCritical;
                
                bool HasBaseOverrideUrl;
                std::string BaseOverrideUrl;
                
                bool HasCoverageTreeOverrideUrl;
                std::string CoverageTreeOverrideUrl;
                
                bool HasSpecialisedBuilder;
                std::string SpecialisedBuilderKey;
                
                bool HasInlineKeySet;
                InlineKeySet KeySet;
                
                bool HasCoverageTree;
                BlockCoverageTrees::BlockCoverageTree* CoverageTree;
                
                CoverageTreeManifestItem()
                : StreamPriority(0)
                , IsCritical(false)
                , HasCoverageTreeOverrideUrl(false)
                , HasSpecialisedBuilder(false)
                , HasInlineKeySet(false)
                , HasBaseOverrideUrl(false)
                , HasCoverageTree(false)
                , CoverageTree(NULL)
                {}
            };
            
            struct StreamComponentToStorePairDto
            {
                std::string ResourceStreamComponentName;
                std::string StoreRelativePath;
            };
            
            
            struct CoverageTreeManifest
            {
                std::string BaseUrl;
                
                std::vector<CoverageTreeManifestItem> BuildingItems;
                std::vector<CoverageTreeManifestItem> GroundItems;
                std::vector<CoverageTreeManifestItem> TransportItems;
                std::vector<CoverageTreeManifestItem> PlaceNameItems;
                std::vector<CoverageTreeManifestItem> InteriorsItems;
                std::vector<StreamComponentToStorePairDto> BuildingFootprintItems;
            };
        }
    }
}
