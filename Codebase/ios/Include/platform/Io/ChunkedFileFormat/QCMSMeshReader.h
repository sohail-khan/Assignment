// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"
#include "Resources.h"
#include "Rendering.h"
#include "Types.h"

#include <vector>
#include <iostream>


namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
                class QCMSMeshReader : private Eegeo::NonCopyable
                {
                public:
                    QCMSMeshReader(const int schemaVersion,
                                   const LookUpTableInfo& lookUpTableInfo
                                   );
                    
                    void Read(std::istream& stream,
                              Resources::BinaryParsing::membuf& streamBuf,
                              const QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo,
                              const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                              QCMSReaderContext& readerContext) const;
                    
                    void ReadWithPositionTriListIndices(std::istream& stream,
                                                        Resources::BinaryParsing::membuf& streamBuf,
                                                        const QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo,
                                                        const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                                                        QCMSReaderContext& readerContext) const;
                    
                private:
                    void ReadMesh(
                                  std::istream& stream,
                                  Resources::BinaryParsing::membuf& streamBuf,
                                  const QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo,
                                  const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                                  std::vector<u16>::iterator scratchVertexPositionIndicesStart,
                                  std::vector<u16>::iterator scratchVertexPositionIndicesEnd,
                                  u16* destVertexBufferStart,
                                  const u16* destVertexBufferEnd,
                                  std::vector<u16>::iterator destTriListIndicesStart,
                                  std::vector<u16>::iterator destTriListIndicesEnd,
                                  std::vector<u16>::iterator destPositionTriListIndicesStart,
                                  std::vector<u16>::iterator destPositionTriListIndicesEnd) const;
                
                    const int m_schemaVersion;
                    const LookUpTableInfo& m_lookUpTableInfo;
                };
            }
        }
    }
}