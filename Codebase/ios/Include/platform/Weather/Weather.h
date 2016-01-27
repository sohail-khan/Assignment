// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Weather
    {
        enum WeatherType
        {
            Default,
            Sunny,
            Foggy,
            Overcast,
            Snowy,
            Rainy,
            MAX_VALUE
        };
        
        enum TimeOfDay
        {
            Day,
            Night
        };
        
        struct WeatherEffectLayer2;
        class WeatherOverlayController;
        class WeatherOverlayRenderer;
    }
}