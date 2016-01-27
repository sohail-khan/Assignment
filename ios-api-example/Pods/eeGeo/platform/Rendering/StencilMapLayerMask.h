// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Rendering
    {
        namespace StencilMapLayerMask
        {
            enum Type
            {
                None = 0,
                UserArea = 0x1f,
                Buildings = 0x20,
                Transport = 0x40,
                Terrain = 0x80,
                BuildingsAndTransport = Buildings | Transport,
                BuildingsAndTerrain = Buildings | Terrain,
                TransportAndTerrain = Transport | Terrain,
                AllMapLayers = Buildings | Transport | Terrain
            };
        };
    }
}