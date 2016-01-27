// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMaterialProvider.h"

namespace Eegeo
{
    namespace Rendering
    {
        class IMaterialRepository : public IMaterialProvider
        {
        public:
            virtual ~IMaterialRepository() {}
            virtual void AddMaterial(Rendering::Materials::IMaterial* material) = 0;
            virtual void RemoveMaterial(Rendering::Materials::IMaterial* material) = 0;
        };
    }
}