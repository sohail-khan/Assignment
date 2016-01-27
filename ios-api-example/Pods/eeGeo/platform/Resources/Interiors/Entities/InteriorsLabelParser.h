// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Tasks.h"
#include "Interiors.h"
#include "PlaceNames.h"
#include "VectorMath.h"

#include <vector>
#include <map>
#include <set>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                typedef std::vector<std::pair<InteriorsEntityModel*, PlaceNames::PlaceNameModel*> > TModelVector;
                typedef std::map<int, TModelVector> TFloorToModelMap;
                
                class InteriorsLabelParser
                {
                public:                    
                    static void BuildLabels(const InteriorsModel& interiorsModel,
                                     Resources::PlaceNames::PlaceNameViewBuilder& labelViewBuilder,
                                     const std::vector<InteriorsEntityModel*>& streamedEntities,
                                     const std::set<std::string>& labelsToOmit,
                                     const bool interiorsAffectedByFlattening,
                                     const v3& glyphColor,
                                     const v3& outlineColor,
                                     TFloorToModelMap& out_floorsToModels);
                };
            }
        }
    }
}
