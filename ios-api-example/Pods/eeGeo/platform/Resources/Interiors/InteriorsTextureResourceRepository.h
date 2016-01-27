// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Interiors.h"
#include "IInteriorsTextureResourceRepository.h"

#include "Types.h"

#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            
            class InteriorsTextureResourceRepository : public IInteriorsTextureResourceRepository, private Eegeo::NonCopyable
            {
            public:
                InteriorsTextureResourceRepository();
                ~InteriorsTextureResourceRepository();
                
                bool Contains(const std::string& name) const;
                IInteriorsTextureResource* Get(const std::string& name) const;
                virtual std::vector<IInteriorsTextureResource*> GetAll() const;
                void Add(IInteriorsTextureResource* pInteriorsTextureResource);
                void Remove(IInteriorsTextureResource* pInteriorsTextureResource);
            private:
                typedef std::map<std::string, IInteriorsTextureResource*> TNameToTextureResource;
                
                TNameToTextureResource m_nameToTextureResource;
            };
            
        }
    }
}