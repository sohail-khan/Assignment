// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Scene
        {
            /*!
             * \brief Interface to a source of SceneElement<T> objects.
             */
            template<class T>
            class ISceneElementSource
            {
            public:
                virtual void GetSceneElements(std::vector<SceneElement<T>*>& out_sceneElements) const = 0;
                virtual ~ISceneElementSource() {};
            };
        }
    }
}
