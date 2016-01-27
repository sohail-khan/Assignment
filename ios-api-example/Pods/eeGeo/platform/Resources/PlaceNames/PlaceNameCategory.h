// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            // Only used by V1 Placename data. Converted on parsing to V2 format.
            enum PlaceNameCategory
            {
                PlaceNameCategoryUnknown = 0,
                PlaceNameCategoryCountry = 1,
                PlaceNameCategoryState = 2,
                PlaceNameCategoryCounty = 3,
                PlaceNameCategoryCityCapital = 4,
                PlaceNameCategoryCity = 5,
                PlaceNameCategoryPark = 6,
                PlaceNameCategoryAirport = 7,
                PlaceNameCategoryDistrict = 8,
                PlaceNameCategoryGolfCourse = 9,
                PlaceNameCategoryPlaceOfInterest = 10,
                PlaceNameCategorySmallDistrict = 11,
                PlaceNameCategoryStation = 12,
                PlaceNameCategoryRouteName = 13,
                PlaceNameCategoryFacility = 14,
                PlaceNameCategoryCrossing = 15
            };
        }
    }
}
