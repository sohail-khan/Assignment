// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"
#include "VectorMath.h"
#include "GenericMeshData.h"
#include <vector>
#include <limits>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace MeshDataExtensions
            {

                template <typename TVertex>
                void UnpackVertices(const Eegeo::IO::ChunkedFileFormat::GenericMeshData<TVertex> &meshData,
                                           std::vector<Eegeo::v3> &vertices)
                {
                    float xRange =meshData.maxVertexRange.GetX() -  meshData.minVertexRange.GetX();
                    float yRange =meshData.maxVertexRange.GetY() -  meshData.minVertexRange.GetY();
                    float zRange =meshData.maxVertexRange.GetZ() -  meshData.minVertexRange.GetZ();
                    
                    float uShortMax = std::numeric_limits<u16>::max();
                    
                    float xFactor = xRange/uShortMax;
                    float yFactor = yRange/uShortMax;
                    float zFactor = zRange/uShortMax;
                    
                    for(int i = 0;i < meshData.numVerts; i++)
                    {
                        float x = meshData.pVertexBuffer[i].x*xFactor + meshData.minVertexRange.GetX();
                        float y = meshData.pVertexBuffer[i].y*yFactor + meshData.minVertexRange.GetY();
                        float z = meshData.pVertexBuffer[i].z*zFactor + meshData.minVertexRange.GetZ();
                        
                        vertices.push_back(Eegeo::v3(x,y,z));
                    }
                }
                
                template <typename TVertex>
                v3 UnpackVertex(const Eegeo::IO::ChunkedFileFormat::GenericMeshData<TVertex> &meshData, int vertexIndex)
                {
                    const TVertex& v = meshData.pVertexBuffer[vertexIndex];
                    v3 source(v.x, v.y, v.z);
                    v3 scale(meshData.maxVertexRange - meshData.minVertexRange);
                    scale *= (1.0f / std::numeric_limits<u16>::max());
                    v3 result = meshData.minVertexRange + source*scale;
                    return result;
                }

            };
        }
    }
}
