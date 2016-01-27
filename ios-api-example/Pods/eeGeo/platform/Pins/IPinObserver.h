// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Pins.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Interface to an observer of a collection Pin objects.
         *
         *  This interface specifies how an object can recieve notifications when the contents of a Pin collection
         *  is modified. This interface is a companion to IPinObservable.
         *
         */
        class IPinObserver
        {
        public:
            /*! Notification that a Pin has been added to a collection.
             * \param pin The pin that has been added to the collection.
             */
            virtual void OnPinAdded(Pin& pin) = 0;

            /*! Notification that a Pin has been removed from a collection.
             * \param pin The pin that has been removed from the collection.
             */
            virtual void OnPinRemoved(Pin& pin) = 0;
            
            virtual ~IPinObserver() {};
        };
    }
}
