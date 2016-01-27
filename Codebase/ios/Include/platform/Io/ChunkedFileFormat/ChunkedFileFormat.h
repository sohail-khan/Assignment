// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            class ChunkStream;
            
            
            namespace RoadNamesChunkReader
            {
                struct RoadNameInstance;
                struct RoadNames;
            }
            
            namespace QuantizedMeshSetChunkReader
            {
                struct QuantizedMeshInfo;
                struct ReaderMeshResult;
                struct ReaderCollisionResult;
                struct ReaderResult;
                
                struct LookUpTableInfo;
                struct QCMSReaderContext;
                class QCMSMeshReader;
                
                struct ShortVector3;
                struct UShortVector3;
                
                class IQuantizedMeshSetChunkReaderMeshFactory;
            }
        }
    }
}
