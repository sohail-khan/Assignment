// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class PlaceNamesModelModule : protected Eegeo::NonCopyable
                {
                public:
                    PlaceNamesModelModule();
                    ~PlaceNamesModelModule();
                    static PlaceNamesModelModule* Create();
                    
                    Resources::PlaceNames::PlaceNamesRepository& GetPlaceNamesRepository() const;
                private:
                   Resources::PlaceNames::PlaceNamesRepository* m_pPlaceNamesRepository;
                };
            }
        }
    }
}