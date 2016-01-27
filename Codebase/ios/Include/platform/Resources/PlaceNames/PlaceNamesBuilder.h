// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PlaceNames.h"
#include "IResourceBuilder.h"
#include "Types.h"
#include "Streaming.h"
#include "Space.h"
#include "ChunkedFileFormat.h"
#include "Interiors.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesBuilder : public IResourceBuilder, protected Eegeo::NonCopyable
            {
            public:
                PlaceNamesBuilder(
                                  PlaceNamesController& placeNamesController,
                                  PlaceNameViewBuilder& placeNameViewBuilder,
                                  Eegeo::Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder& interiorMarkersCellResourceBuilder,
                                  const bool enableInteriorMarkers
                                  );

                virtual ~PlaceNamesBuilder();
                virtual bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result);
                virtual void DestroyBuiltResource(const Streaming::MortonKey& key, void* input);
                virtual void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length);

                virtual bool AcceptsErroredRequests()
                {
                    return false;
                }
                
            private:
            
                PlaceNamesCell* CreatePlaceNamesCellFromChunkStream(const Streaming::MortonKey& key, Eegeo::IO::ChunkedFileFormat::ChunkStream& chunkStream);
                
                Eegeo::Resources::Interiors::Markers::InteriorMarkersCellResource* CreateInteriorMarkersCellFromChunkStream(const Streaming::MortonKey& key, Eegeo::IO::ChunkedFileFormat::ChunkStream& chunkStream);
            
                PlaceNamesController& m_placeNamesController;
                PlaceNameViewBuilder& m_placeNameViewBuilder;
                std::vector<u32> m_utf32Scratch;
                const bool m_enableInteriorMarkers;
                
                Eegeo::Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder& m_interiorMarkersCellResourceBuilder;
                
                PlaceNameModel*  BuildPlaceNameModel(const Eegeo::Space::CubeMap::CubeMapCellInfo& cellInfo, const PlaceNameData& placeNameData);
            };
        }
    }
}