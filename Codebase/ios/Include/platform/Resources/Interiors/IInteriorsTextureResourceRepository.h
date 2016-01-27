// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Interiors.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsTextureResourceRepository
            {
            public:
                virtual ~IInteriorsTextureResourceRepository() {;}
                virtual bool Contains(const std::string& name) const = 0;
                virtual IInteriorsTextureResource* Get(const std::string& name) const = 0;
                virtual std::vector<IInteriorsTextureResource*> GetAll() const = 0;
                virtual void Add(IInteriorsTextureResource* pInteriorsTextureResource) = 0;
                virtual void Remove(IInteriorsTextureResource* pInteriorsTextureResource) = 0;
            };
        }
    }
}