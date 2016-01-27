// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IJpegLoader.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Raster
            {
                struct TerrainData
                {
                    std::vector<float> heights;
                    u32 blueMarbleWaterTextureId;
                    bool pvr;
                };
                
                bool ParseTerrain(const Byte* data, size_t length, TerrainData& result, const bool manuallyGenerateMipmaps, Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader);
            }
        }
    }
}
