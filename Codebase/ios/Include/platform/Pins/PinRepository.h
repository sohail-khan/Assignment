// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IPinObservable.h"
#include "Pins.h"
#include <vector>

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief A repository for a set of Pin model objects.
         *
         *  PinRepository contains an observable set of Pin model objects. It is observable in the sense that external objects
         *  can be registered to receive notifications when Pins are added or removed from the repository.
         *
         */
        class PinRepository : protected Eegeo::NonCopyable, public IPinObservable
        {
        public:
            /*! Create an empty PinRepository
             * \return An empty PinRepository object
             */            
            PinRepository();
            
            /*! Destroy a PinRepository and all of the Pin objects it contains.
             */
            ~PinRepository();
            
            /*! Add a Pin to the respository, notifying any observers as appropriate. 
             *  Asserts if the Pin is already in the repository.
             *  Asserts if the another Pin in the repository has the same ID as the one being added.
             * \param pPinToAdd A pointer to the Pin object to add to the repository.
             */
            void AddPin(Pin& pPinToAdd);

            /*! Remove a Pin from the repository, notifying any observers as appropriate.
             *  Asserts if the Pin couldn't be found in the repository.
             * \param pPinToRemove A pointer to the Pin object to remove to the repository.
             */            
            void RemovePin(Pin& pPinToRemove);
            
            /*! Get the number of Pin objects currently in the repository.
             * \return The number of Pin objects in the repository.
             */            
            int GetNumOfPins() const;
            
            /*! Get the Pin at particular index within the repository.
             * \param pinIndex A zero based index of the Pin to retrieve from the repository.
             * \return A pointer to the Pin at the given index, NULL if the index is out of range.
             */
            Pin* GetPinAtIndex(int pinIndex) const;
            
            /*! Find a Pin in repository with a given Id.
             * \param id The id of the Pin to find in the repository.
             * \return A pointer to the Pin with the given ID or NULL if no Pin could be found with that ID.
             */
            Pin* GetPinById(TPinId id) const;
            
            /*! Register an observer to recieve notifications when the repository contents are modified. 
             *  Registered observers are notified whenever a Pin is added or removed from the repository.
             * \param observerToAdd The observer to register for notifications.
            */
            virtual void AddPinObserver(IPinObserver& observerToAdd);

            /*! De-register an observer from the repository.
             *  Once an observer is de-registered it will no longer receive notifications when the repository contents are
             *  changed.
             * \param observerToRemove The observer to de-register from receiving notifications.
             */
            virtual void RemovePinObserver(IPinObserver& observerToRemove);
            
        private:
            typedef std::vector<Pin*> TPins;
            TPins m_pins;
            
            typedef std::vector<IPinObserver*> TPinObservers;
            TPinObservers m_observers;
            
            bool ContainsPin(const Pin* pPinToCheck) const;
            bool ContainsPinId(TPinId pinId) const;
            Pin* FindPinById(TPinId pinId) const;
        };
    }
}
