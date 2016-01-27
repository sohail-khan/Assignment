// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ParsedNavGraph.h"
#include "TrainVehicle.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Traffic
    {
        namespace Config
        {
            namespace FunctionalRoadClassFilterType
            {
                enum Values
                {
                    None = 0,
                    Exclusive,      // Vehicle cannot travel on the road classes in the filter list
                    Inclusive,      // Vehicle can only travel on the road clases in the filter list
                    Count           // Invalid value, just used to tell the number of different enum values
                };
            }
            
            struct TrafficSimulationRoadClassFilter
            {
                TrafficSimulationRoadClassFilter() : FilterType(FunctionalRoadClassFilterType::None) {}
                
                std::vector<Resources::Roads::FunctionalRoadClass> FilterList;
                FunctionalRoadClassFilterType::Values FilterType;

                //Needed to deserialize from the manifest
                static const char* FunctionalRoadClassFilterTypeStrings[];
                
                bool CanUseFunctionalRoadClass(Resources::Roads::FunctionalRoadClass roadClass) const
                {
                    if(FilterType == FunctionalRoadClassFilterType::None)
                    {
                        return true;
                    }
                    
                    std::vector<Resources::Roads::FunctionalRoadClass>::const_iterator iterator = std::find(FilterList.begin(), FilterList.end(), roadClass);
                    if( (FilterType == FunctionalRoadClassFilterType::Exclusive && iterator == FilterList.end()) ||
                       (FilterType == FunctionalRoadClassFilterType::Inclusive && iterator != FilterList.end()) )
                    {
                        return true;
                    }
                    
                    return false;
                }

            };
            
            struct TrafficSimulationVehicleConfiguration
            {                
                TrafficSimulationVehicleConfiguration(std::string name, std::string modelNode, float speed)
                : Name(name)
                , ModelNode(modelNode)
                , Speed(speed)
                , CarriageNode("")
                , TailNode("")
                , MinCarriageCount(0)
                , MaxCarriageCount(0)
                , EngineNodeLength(Eegeo::Traffic::TRAIN_CARRIAGE_SEPARATION)
                , CarriageNodeLength(Eegeo::Traffic::TRAIN_CARRIAGE_SEPARATION)
                , TailNodeLength(Eegeo::Traffic::TRAIN_CARRIAGE_SEPARATION)
                , Scale(1.0f)
                , SpawnWeighting(1.0f)
                {
                }
                
                std::string Name;
                std::string ModelNode;
                float EngineNodeLength;
                std::string CarriageNode;
                float CarriageNodeLength;
                std::string TailNode;
                float TailNodeLength;

                int MinCarriageCount;
                int MaxCarriageCount;
                
                float Speed;
                float Scale;

                float SpawnWeighting;

                TrafficSimulationRoadClassFilter FunctionalRoadClassFilter;

            };

            class TrafficSimulationConfiguration
            {
            public:

                TrafficSimulationConfiguration()
                : DrivesOnRight(true)
                , MinimumDistanceBetweenSpawns(0)
                , SpawnChancePerCell(1)
                {
                }

                std::string Name;
                bool DrivesOnRight;
                std::string VehiclesBasePodFile;
                std::vector<TrafficSimulationVehicleConfiguration> Vehicles;

                float MinimumDistanceBetweenSpawns;
                float SpawnChancePerCell;

                // Define state textures?
            };
        }
    }
}
