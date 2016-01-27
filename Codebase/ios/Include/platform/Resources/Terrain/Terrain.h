// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            class TerrainStreaming;
            class ITerrainHeightLookup;
            
            namespace Collision
            {
                class TerrainRayPicker;
            }
            
            namespace Heights
            {
                class ITerrainHeightsCallback;
                class TerrainHeightProvider;
                class TerrainHeightRepository;
                class CullingVolumeTreeHeightQuery;
            }
            
            namespace lcm
            {
                class ChunkedLcmTerrainBuilder;
                class ChunkedLcmTerrainHeightLookup;
                class CulledHeightMesh;
                struct ChunkedLcmTerrainBuilderOutput;

            }
            
            namespace Placeholder
            {
                class TerrainPlaceholderBuilder;
            }
            
            namespace Raster
            {
                class RasterTerrainBuilder;
                class RasterTerrainHeightLookup;
            }
        }
    }
}