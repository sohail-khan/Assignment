// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Pins.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Interface to a factory for creating PinView objects.
         *
         *  This class allows controller objects to delegate the creation of PinView objects to a seperate factory class.
         *
         */
        class IPinViewFactory
        {
        public:
            /*! Create a new PinView to represent a given Pin object.
             * \param pinModel The Pin model object to create a view for.
             * \return A pointer to the newly created PinView to represent the given model.
             */
            virtual PinView* CreateViewForPin(Pin& pinModel) = 0;
            
            virtual ~IPinViewFactory() {};
        };
    }
}
