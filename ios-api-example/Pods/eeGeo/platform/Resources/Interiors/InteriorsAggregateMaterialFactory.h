// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IInteriorsMaterialFactory.h"
#include "Types.h"

#include "Rendering.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsAggregateMaterialFactory : public IInteriorsMaterialFactory, private Eegeo::NonCopyable
            {
            public:
                InteriorsAggregateMaterialFactory(std::vector<IInteriorsMaterialFactory*> interiorsMaterialFactories);
                
                virtual Eegeo::Rendering::Materials::IMaterial* TryCreate(const InteriorMaterialData& interiorMaterialData);
                
                virtual void AddHigherPriorityFactory(IInteriorsMaterialFactory* pFactory);
                
            private:
                std::vector<IInteriorsMaterialFactory*> m_interiorsMaterialFactories;
            };
        }
    }
}