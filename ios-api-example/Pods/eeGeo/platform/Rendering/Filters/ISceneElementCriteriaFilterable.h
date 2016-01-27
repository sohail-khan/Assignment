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
             * \brief Interface to a set of filterable SceneElement<T> objects.
             *
             * This interface allows a set of criteria to be specified for the filtering of SceneElement<T> objects.
             */
            template<typename T>
            class ISceneElementCriteriaFilterable
            {
            protected:
                virtual ~ISceneElementCriteriaFilterable() {}

            public:
                virtual void SetFilterCriteria(ISceneElementFilterCriteria<T>* pCriteria) = 0;
                virtual void RemoveFilterCriteria() = 0;
            };
        }
    }
}
