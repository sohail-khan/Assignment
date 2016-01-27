// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IInteriorsTextureResourceService.h"
#include "Types.h"

#include "Rendering.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsTextureResourceService : public IInteriorsTextureResourceService, private Eegeo::NonCopyable
            {
            public:
                InteriorsTextureResourceService(IInteriorsTextureResourceBuilder& interiorsTextureResourceBuilder,
                                                IInteriorsCubeTextureResourceBuilder& interiorsCubeTextureResourceBuilder,
                                                IInteriorsTextureResourceRepository& interiorsTextureResourceRepository);
                
                virtual ~InteriorsTextureResourceService();
                
                virtual IInteriorsTextureResource* Create(const std::string& textureKey, const std::string& textureFileName);
                virtual IInteriorsTextureResource* CreateFromCubeMapFaces(const std::string& textureKey, const Eegeo::Helpers::CubeFaceFileNames& cubeFaceFileNames);
                virtual void Destroy(const std::string& textureKey);
                virtual bool Contains(const std::string& textureKey) const;
                virtual IInteriorsTextureResource* Get(const std::string& textureKey) const;
                
            private:
                void DestroyAll();
                
                IInteriorsTextureResourceBuilder& m_interiorsTextureResourceBuilder;
                IInteriorsCubeTextureResourceBuilder& m_interiorsCubeTextureResourceBuilder;
                IInteriorsTextureResourceRepository& m_interiorsTextureResourceRepository;
            };
        }
    }
}