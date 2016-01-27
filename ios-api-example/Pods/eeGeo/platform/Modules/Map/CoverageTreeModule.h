// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

#include "Types.h"
#include "CoverageTrees.h"
#include "BlockCoverageTrees.h"
#include "Web.h"
#include "Buildings.h"
#include "Terrain.h"
#include "Roads.h"
#include "PlaceNames.h"
#include "Interiors.h"
#include "Streaming.h"
#include "NativeUIFactories.h"
#include "IEegeoErrorHandler.h"
#include "Modules.h"
#include "ICallback.h"
#include "IFileIO.h"
#include "CoverageTreeManifest.h"
#include <vector>

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class CoverageTreeModule : protected Eegeo::NonCopyable
            {
            public:
                CoverageTreeModule
                (
                 Streaming::CoverageTrees::ICoverageTreeManifestLoader& manifestLoader,
                 Resources::Buildings::BuildingStreaming& buildingStreaming,
                 Resources::Terrain::TerrainStreaming& terrainStreaming,
                 Resources::Roads::RoadStreaming& transportStreaming,
                 Resources::PlaceNames::PlaceNamesStreaming& placeNameStreaming,
                 Resources::Interiors::InteriorsStreaming& interiorsStreaming,
                 UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                 Web::IConnectivityService& connectivityService,
                 IEegeoErrorHandler* pErrorHandler
                );
                ~CoverageTreeModule();
                
                static CoverageTreeModule* Create(Layers::BuildingStreamingModule& buildingStreamingModule,
                                                  Layers::TerrainStreamingModule& terrainStreamingModule,
                                                  Layers::TransportStreamingModule& transportStreamingModule,
                                                  Layers::PlaceNamesStreamingModule& placeNamesStreamingModule,
                                                  Layers::InteriorsStreamingModule& interiorsStreamingModule,
                                                  Streaming::CoverageTrees::ICoverageTreeManifestLoader& manifestLoader,
                                                  UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                                                  Web::IConnectivityService& connectivityService,
                                                  IEegeoErrorHandler* pErrorHandler);
                
                void LoadCoverageTreeManifest();
                bool LoadingComplete() const;
                float GetProgress() const;

                Streaming::CoverageTrees::CoverageTreeManifestNotifier& CoverageTreeManifestNotifier() const { return *m_pCoverageTreeManifestNotifier; }
                
                void CoverageTreeManifestLoadedHandler(const Streaming::CoverageTrees::CoverageTreeManifestLoaderResult& result);
                
            private:
                
                void LoadCoverageTreesFromManifest(const Streaming::CoverageTrees::CoverageTreeManifest& manifest);
                
                void LoadCoverageTreesForResourceType(const std::vector<Streaming::CoverageTrees::CoverageTreeManifestItem>& items, Streaming::ResourceStreamBase& streaming, const std::string& baseUrl);
                
                Streaming::CoverageTrees::CoverageTreeDownloadFailedHandler* m_pCoverageTreeDownloadFailedHandler;
                Streaming::CoverageTrees::ICoverageTreeManifestLoader& m_manifestLoader;

                Streaming::CoverageTrees::CoverageTreeManifestNotifier* m_pCoverageTreeManifestNotifier;
                
                Resources::Buildings::BuildingStreaming& m_buildingStreaming;
                Resources::Terrain::TerrainStreaming& m_terrainStreaming;
                Resources::Roads::RoadStreaming& m_transportStreaming;
                Resources::PlaceNames::PlaceNamesStreaming& m_placeNameStreaming;
                Resources::Interiors::InteriorsStreaming& m_interiorsStreaming;
                
                bool m_loadingComplete;
                
                typedef  Helpers::TCallback1<CoverageTreeModule, const Streaming::CoverageTrees::CoverageTreeManifestLoaderResult> CoverageTreeManifestLoadedCallback;
                
                CoverageTreeManifestLoadedCallback m_coverageTreeManifestLoadedCallback;
            };
        }
    }
}
    
