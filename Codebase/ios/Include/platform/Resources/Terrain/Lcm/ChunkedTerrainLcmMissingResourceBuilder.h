// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Space.h"
#include "Terrain.h"
#include "Rendering.h"
#include "Streaming.h"
#include "ChunkedFileFormat.h"
#include "GenericMeshData.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace lcm
            {
                const u8 WATER_AREA_CODE = 254;
                const u8 SHALLOW_WATER_AREA_CODE = 253;
                const u8 DEEP_WATER_AREA_CODE = 255;
                
                const int MAX_QUADTREE_DEPTH_FOR_TERRAIN = 14;
                
                typedef IO::ChunkedFileFormat::GenericMeshData<Rendering::VertexTypes::PackedTwoTextureVertex> LcmTerrainMeshData;
                
                void BuildMissingLcmResource(
                                             const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                             ChunkedLcmTerrainBuilderOutput* output,
                                             Rendering::MeshFactories::PackedTwoTextureDiffuseMeshFactory& packedTwoTextureDiffuseMeshFactory,
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                             Rendering::IMaterialProvider& materialProvider
                                             );
                void BuildMissingLcmMeshData(Eegeo::Streaming::MortonKey key, LcmTerrainMeshData &meshData);
            }
        }
    }
}