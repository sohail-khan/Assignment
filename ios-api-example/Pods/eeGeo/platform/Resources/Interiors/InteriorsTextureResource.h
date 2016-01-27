// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IInteriorsTextureResource.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            
            class InteriorsTextureResource : public IInteriorsTextureResource, private Eegeo::NonCopyable
            {
            public:
                InteriorsTextureResource(const std::string& name, Rendering::TTextureId textureId);
                
                ~InteriorsTextureResource();
                
                std::string GetName() const;
                Rendering::TTextureId GetTextureId() const;
            private:
                const std::string m_name;
                const Rendering::TTextureId m_textureId;
            };
        }
    }
}