// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesRepository : protected Eegeo::NonCopyable
            {
            public:
                void AddPlaceNameModel(PlaceNameModel* pPlaceNameModel);
                PlaceNameModel* FindPlaceNameWithSameName(const PlaceNameModel* pPlaceNameToFind) const;
                PlaceNameModel* FindPlaceNameWithSameNameAndCategory(const PlaceNameModel* pPlaceNameToFind) const;
                void RemovePlaceNameModel(const PlaceNameModel* pPlaceNameModel);
                void RemoveIf(bool (*predicate)(const PlaceNameModel*));
                
                typedef std::vector<PlaceNameModel*> TPlaceNameModels;
                
                const TPlaceNameModels& GetPlaceNameModels() const { return m_placeNameModels; }

            private:
                TPlaceNameModels m_placeNameModels;
            };
        }
    }
}
