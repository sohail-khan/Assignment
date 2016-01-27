// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fireworks.h"
#include "VectorMath.h"
#include "Camera.h"
#include "LatLongAltitude.h"
#include "Types.h"

namespace Eegeo
{
    namespace Fireworks
    {
        /*!
         * \brief Data object storing the configuration for an individual fireworks display.
         *
         *  This type configures a potential fireworks displays settings, from where it's located to when it should play
         *  These should be added to a IFireworksLocationRepository or a FireworksModule in order to see the display in the world.
         */
        struct FireworksLocationConfiguration
        {
            FireworksLocationConfiguration()
            : location(0, 0)
            , chanceOfAppearing(0.0f)
            , startTimeHour(0)
            , endTimeHour(0)
            , loopDisplay(true)
            {}
            
            //! Create a FireworksLocationConfiguration with specified values
            /* \param location A LatLong object specifying the latitude and longitude of the fireworks display.
             * \param chance A float defining the chance of a fireworks display appearing when you visit said location. Valid range is 0 < X <= 1.0
             * \param startTimeHour Specifies the start time in terms of hours on a 24-hour clock the fireworks will play. Valid range is 0 <= X <= 23
             * \param endTimeHour Specifies the end time in terms of hours on a 24-hour clock the fireworks will end. Valid range is 0 <= X <= 23. If it matches startTimeHour, will play indefinitely.
             */
            FireworksLocationConfiguration(Space::LatLong location, float chance, u32 startTimeHour, u32 endTimeHour)
            : location(location)
            , chanceOfAppearing(chance)
            , startTimeHour(startTimeHour)
            , endTimeHour(endTimeHour)
            , loopDisplay(true)
            {}
            
            //! Is this fireworks display configuration configured to run all day? This is true if startTimeHour is equal to endTimeHour.
            bool IsAllDayFireworks() const { return startTimeHour == endTimeHour; }
            
            //! Latitude and Longitude of the position of the fireworks display in the world
            Space::LatLong location;
            
            //! Chance of the fireworks display appearing each time you visit the location. Valid range is 0 < X <= 1.0
            float chanceOfAppearing;
            
            //! The start time in terms of hours on a 24-hour clock the fireworks will play. Valid range is 0 <= X <= 23
            u32 startTimeHour;
            
            //! The end time in terms of hours on a 24-hour clock the fireworks will end. Valid range is 0 <= X <= 23. If it matches startTimeHour, will play indefinitely.
            u32 endTimeHour;
            
            //! The fireworks display will loop the firework sequences when running if true.  If false, it will display each sequence once then stop.
            bool loopDisplay;
        };
    }
}
