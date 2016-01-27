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
            class ISceneElementInGraphObserver
            {
            public:
                virtual ~ISceneElementInGraphObserver() { };
                virtual void OnAddedToSceneGraph(SceneElement<T>* resource) = 0;
                virtual void OnRemovedFromSceneGraph(SceneElement<T>* resource) = 0;
            };
        }
    }
}