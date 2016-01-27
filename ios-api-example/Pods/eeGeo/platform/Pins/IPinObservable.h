// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Pins.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Interface to an observable collection of Pin objects.
         *
         *  This interface allows the registration of observer objects to receive notifications when the
         *  contents of the collection are changed. This interface is a companion to IPinObserver.
         *
         */
        class IPinObservable
        {
        public:
            /*! Register an observer to receive notifications when the collection's contents are modified.
             * \param observerToAdd The observer to register.
             */
            virtual void AddPinObserver(IPinObserver& observerToAdd) = 0;
            
            /*! De-register an observer from receiving notifications when the collection's contents are modified.
             * \param observerToRemove The observer to de-register.
             */
            virtual void RemovePinObserver(IPinObserver& observerToRemove) = 0;            
            virtual ~IPinObservable() {};
        };
    }
}
