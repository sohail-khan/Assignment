// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Scene
        {
            template<typename T>
            class ISceneElementRemover
            {
            public:
                virtual void Remove(SceneElement<T>* resource) = 0;
                virtual ~ISceneElementRemover() { };
            };
        }
    }
}