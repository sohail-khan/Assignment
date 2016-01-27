// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Io
    {
        namespace AsyncModels
        {
            class IAsyncModel
            {
            public:
            	virtual ~IAsyncModel() {};
                virtual const std::string GetUrl() const = 0;
                virtual bool TryGetModel(Rendering::SceneModels::SceneModel*& out_pModel) const = 0;
                virtual bool IsLoaded() const = 0;
            };
        }
    }
}