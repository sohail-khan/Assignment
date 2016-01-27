// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMaterial.h"
#include "IdTypes.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class IDiffuseMaterial : public IMaterial
            {
            public:
                virtual void SetDiffuseTexture(TTextureId textureId) = 0;
                virtual TTextureId GetTextureId() const = 0;
                
                virtual ~IDiffuseMaterial() { };
            };
        }
    }
}
