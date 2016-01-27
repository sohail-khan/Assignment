// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Scene
        {
            /*!
             * \brief Interface to a filter of SceneElement<T> objects.
             *
             * Implementers of this interface determine whether a single SceneElement<T> should be filtered out, or not.
             */
            template<typename T>
            class ISceneElementFilterCriteria
            {
            protected:
                virtual ~ISceneElementFilterCriteria(){}
                
            public:
                virtual bool FiltersOut(const SceneElement<T>& item) const = 0;
            };
        }
    }
}
