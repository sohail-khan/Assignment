#pragma once

#include "IFileIO.h"
#include "Types.h"
#include <iostream>
#include <vector>
#include <string>
#include "ChunkedFileFormat.h"
#include "CoverageTrees.h"


namespace Eegeo
{
    namespace Streaming
    {
        namespace BlockCoverageTrees
        {
            class CoverageTreeManifestChunkParser: protected Eegeo::NonCopyable
            {
            public:
                
                bool ParseCoverageTreeManifest(const std::vector<Byte>& resourceData,
                                               CoverageTrees::CoverageTreeManifest& manifest);
                
            private:
                
                void ParseCoverageTrees(IO::ChunkedFileFormat::ChunkStream& chunkStream, CoverageTrees::CoverageTreeManifest& manifest) const;
                
                void ParseBuildingFootprints(IO::ChunkedFileFormat::ChunkStream& chunkStream, CoverageTrees::CoverageTreeManifest& manifest) const;
                
                std::string ParseText(IO::ChunkedFileFormat::ChunkStream& chunkStream) const;
                
                std::string ParseString(std::istream& stream) const;
                
            };
        }
    }
}