// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include "Interiors.h"
#include "Resources.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesBuilderOutput : private Eegeo::NonCopyable
            {
            public:
                PlaceNamesBuilderOutput(PlaceNamesCell* pPlaceNameCell,
                                        Eegeo::Resources::Interiors::Markers::InteriorMarkersCellResource* pInteriorMarkersCellResource);
                
                virtual ~PlaceNamesBuilderOutput();
                
                virtual void TransferResourceOwnership();
                
                virtual std::vector<IBuiltResource*> GetBuiltResources() const;
            private:
                PlaceNamesCell* m_pPlaceNameCell;
                Eegeo::Resources::Interiors::Markers::InteriorMarkersCellResource* m_pInteriorMarkersCellResource;
                
            };
        }
    }
}