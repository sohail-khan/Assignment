// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            template <class TProperty>
            class ISceneModelNodeAnimatedProperty
            {
            public:
                
                virtual ~ISceneModelNodeAnimatedProperty() {}
                
                virtual void GetPropertyForFrame(u32 frame, TProperty& out_property) const = 0;
                
                virtual ISceneModelNodeAnimatedProperty<TProperty>* Clone() = 0;
            };
        }
    }
}