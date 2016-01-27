// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once



#include "Interiors.h"
#include "IInteriorsMaterialFactory.h"
#include "Types.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsDefaultMaterialFactory : public Eegeo::Resources::Interiors::IInteriorsMaterialFactory, private Eegeo::NonCopyable
            {
            public:
                InteriorsDefaultMaterialFactory(Eegeo::Resources::Interiors::IInteriorsMaterialFactory& untexturedMaterialFactory,
                                               Eegeo::Resources::Interiors::IInteriorsMaterialFactory& stencilMirrorMaskMaterialFactory,
                                               Eegeo::Resources::Interiors::IInteriorsMaterialFactory& diffuseTranslucentMaterialFactory);

                Eegeo::Rendering::Materials::IMaterial* TryCreate(const Eegeo::Resources::Interiors::InteriorMaterialData& interiorMaterialData);
            private:
                Eegeo::Resources::Interiors::IInteriorsMaterialFactory& m_untexturedMaterialFactory;
                Eegeo::Resources::Interiors::IInteriorsMaterialFactory& m_stencilMirrorMaskMaterialFactory;
                Eegeo::Resources::Interiors::IInteriorsMaterialFactory& m_diffuseTranslucentMaterialFactory;
            };
        }
    }
}