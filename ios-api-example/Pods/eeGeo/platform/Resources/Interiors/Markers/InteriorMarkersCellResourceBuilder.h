// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "Streaming.h"
#include "ChunkedFileFormat.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Markers
            {
                class InteriorMarkersCellResourceBuilder : private Eegeo::NonCopyable
                {
                public:
                    InteriorMarkersCellResourceBuilder(InteriorMarkerModelRepository& interiorMarkerModelRespository);
                    
                    virtual ~InteriorMarkersCellResourceBuilder();
                    
                    virtual InteriorMarkersCellResource* CreateFromChunkStream(const Streaming::MortonKey& key,
                                                                               Eegeo::IO::ChunkedFileFormat::ChunkStream& chunkStream);
                private:
                    InteriorMarkerModelRepository& m_interiorMarkerModelRespository;
                };
            }
        }
    }
}