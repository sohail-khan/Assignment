// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            class ITerrainHeightLookup
            {
            public:
                virtual ~ITerrainHeightLookup() {}
                virtual bool TryGetHeight(Eegeo::dv3 ecefPoint, float& height) const=0;
                
                // Suspect this in nonsense.  All ITerrainHeightLookup implementations know what key they belong to and are retrieved from repositories
                // via their key. Bit of confusion of who should have knowledge of the MortonKey...
                virtual bool TryGetHeight(Eegeo::dv3 ecefPoint, Streaming::MortonKey key, float& height) const=0;
                
                virtual float GetMaxHeight() const = 0;
                virtual float GetMinHeight() const = 0;
                
                virtual const Eegeo::Streaming::MortonKey& GetMortonKey() const = 0 ;
            };
        }
	}
}