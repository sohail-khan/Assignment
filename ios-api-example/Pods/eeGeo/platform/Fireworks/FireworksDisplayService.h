// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "Fireworks.h"
#include "Camera.h"
#include "SceneGraphCellCallback.h"
#include "Random.h"
#include "Types.h"
#include "ICallback.h"
#include "MortonKey.h"
#include "Terrain.h"
#include <map>
#include <vector>

namespace Eegeo
{
    namespace Fireworks
    {
        class FireworksDisplayService
        {
        public:
            
            FireworksDisplayService(FireworksLocationRepository& fireworksLocationRepository,
                                    FireworksSequenceFactory& sequenceFactory,
                                    Streaming::StreamingController& streamingController,
                                    Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                    Random& random);
            ~FireworksDisplayService();
            
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            
        private:
        
            void HandleCellsMadeVisible(const std::vector<Streaming::MortonKey>& mortonKeys);
            void HandleCellsMadeInvisible(const std::vector<Streaming::MortonKey>& mortonKeys);
            
            void HandleLocationAdded(const IFireworksLocation& fireworksLocation);
            void HandleLocationRemoved(const IFireworksLocation& fireworksLocation);
            
            bool TryAddDisplay(const IFireworksLocation& location);
            void RemoveDisplay(const IFireworksLocation& location);
            
            Random& m_random;
            
            FireworksLocationRepository& m_fireworksLocationRepository;
            FireworksSequenceFactory& m_fireworksSequenceFactory;
            Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            Streaming::StreamingController& m_streamingController;
            
            Helpers::TCallback1<FireworksDisplayService, const std::vector<Streaming::MortonKey>&> m_cellsVisibleCallback;
            Helpers::TCallback1<FireworksDisplayService, const std::vector<Streaming::MortonKey>&> m_cellsInvisibleCallback;
            
            Helpers::TCallback1<FireworksDisplayService, const IFireworksLocation&> m_fireworksAddedCallback;
            Helpers::TCallback1<FireworksDisplayService, const IFireworksLocation&> m_fireworksRemovedCallback;
            
            typedef std::map<u32, FireworksDisplay*> TUidToFireworksDisplayMap;
            TUidToFireworksDisplayMap m_uniqueIdToFireworksDisplayMap;
        };
    }
}