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
             * \brief Interface to an observable collection of SceneElement<T> objects.
             *
             *  This interface allows the registration of observer objects to receive notifications when the
             *  contents of the collection are changed. This interface is a companion to ISceneElementObserver.
             *
             */
            template<typename T>
            class ISceneElementObservable
            {
            public:
                /*! Register an observer to receive notifications when the collection's contents are modified.
                 * \param observerToAdd The observer to register.
                 */
                virtual void AddObserver(ISceneElementObserver<T>& observerToAdd) = 0;
                
                /*! De-register an observer from receiving notifications when the collection's contents are modified.
                 * \param observerToRemove The observer to de-register.
                 */
                virtual void RemoveObserver(ISceneElementObserver<T>& observerToRemove) = 0;
                virtual ~ISceneElementObservable() {};
            };
        }
    }
}
