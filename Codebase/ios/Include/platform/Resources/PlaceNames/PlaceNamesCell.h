// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BuiltResourceWithKey.h"
#include "PlaceNames.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesCell : public BuiltResourceWithKey, protected Eegeo::NonCopyable
            {
            private:
                static const int MaxNamesPerCell = 25;
                
            public:
                PlaceNamesCell(const Streaming::MortonKey& key, PlaceNamesController& placeNamesController, std::vector<PlaceNameModel*> *pPlaceNameModels);
                ~PlaceNamesCell();

                void Unload();
                void RemovedFromSceneGraph();
                void AddedToSceneGraph();
                        
            private:
                PlaceNamesController& m_placeNamesController;
                std::vector<PlaceNameModel*>* m_pPlaceNameModels;
            };
        }
    }
}