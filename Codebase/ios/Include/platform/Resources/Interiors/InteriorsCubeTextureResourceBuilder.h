// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Interiors.h"
#include "IInteriorsCubeTextureResourceBuilder.h"
#include "Types.h"

#include "Rendering.h"
#include "Helpers.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsCubeTextureResourceBuilder : public IInteriorsCubeTextureResourceBuilder, private Eegeo::NonCopyable
            {
            public:
                InteriorsCubeTextureResourceBuilder(Eegeo::Helpers::ITextureFileLoader& textureFileLoader);
                
                virtual IInteriorsTextureResource* Create(const std::string& textureResourceKey, const Helpers::CubeFaceFileNames& cubeFaceFilenames);
                
                
            private:
                Eegeo::Helpers::ITextureFileLoader& m_textureFileLoader;
            };
        }
    }
}