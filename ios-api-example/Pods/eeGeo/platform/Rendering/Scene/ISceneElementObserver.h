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
             * \brief Interface to an observer of a collection of SceneElement<T> objects.
             *
             *  This interface specifies how an object can recieve notifications when the contents of a SceneElement collection
             *  is modified. This interface is a companion to ISceneElementObservable.
             *
             */
            template<typename T>
            class ISceneElementObserver
            {
            public:
                /*! Notification that a SceneElement has been added to a collection.
                 * \param sceneElement The SceneElement that has been added to the collection.
                 */
                virtual void OnSceneElementAdded(SceneElement<T>& sceneElement) = 0;
                
                /*! Notification that a SceneElement has been removed from a collection.
                 * \param sceneElement The SceneElement that has been removed from the collection.
                 */
                virtual void OnSceneElementRemoved(SceneElement<T>& sceneElement) = 0;
                
                virtual ~ISceneElementObserver() {};
            };
        }
    }
}
