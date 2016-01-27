// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"
#include "Types.h"
#include "CollisionMaterialIndexLookupPair.h"

#include <vector>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
           
                struct QCMSReaderContext
                {
                    const std::vector<u16>& vertexBuffer() const { return m_vertexBuffer; };
                    std::vector<u16>& vertexBuffer() { return m_vertexBuffer; };
                    
                    const std::vector<u16>& indexBuffer() const { return m_indexBuffer; }
                    std::vector<u16>& indexBuffer() { return m_indexBuffer; }
                    
                    const std::vector<u16>& vertexPositionIndices() const { return m_vertexPositionIndices; }
                    std::vector<u16>& vertexPositionIndices() { return m_vertexPositionIndices; }
                    
                    const std::vector<u16>& positionTriListIndices() const { return m_positionTriListIndices; }
                    std::vector<u16>& positionTriListIndices() { return m_positionTriListIndices; }
                    
                    Eegeo::Collision::ContiguousRangeBuilder& collisionRangeBuilder() { return m_collisionRangeBuilder; }
                    
                    QCMSReaderContext();
                    
                    void ResizeForMeshInfo(const QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo, size_t destVertexSizeBytes);
                    
                private:
                    std::vector<u16> m_vertexBuffer;
                    std::vector<u16> m_indexBuffer;
                    
                    // these both index into pPositionLUT
                    std::vector<u16> m_vertexPositionIndices;
                    std::vector<u16> m_positionTriListIndices;
                    
                    Eegeo::Collision::ContiguousRangeBuilder m_collisionRangeBuilder;
                };
            }
        }
    }
}
