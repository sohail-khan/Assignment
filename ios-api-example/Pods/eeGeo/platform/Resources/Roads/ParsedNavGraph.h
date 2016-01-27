// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include <vector>
#include <map>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            enum RoadDirection
            {
                BIDIRECTIONAL = 0,
                FT = 1,
                TF = 2,
                CLOSED_IN_BOTH_DIRECTIONS = 3
            };
            
            // If we add a new FunctionalRoadClass we need to add it to the enumMap in the BuildFunctionalRoadClassEnumValuesMap method.
            enum FunctionalRoadClass
            {
                NotApplicable = -1, // (for FeatTyp 4165)
                MotorwayFreewayOrOtherMajorRoad = 0,
                MajorRoadLessImportantThanMotorway = 1,
                OtherMajorRoad = 2,
                SecondaryRoad = 3,
                LocalConnectingRoad = 4,
                LocalRoadOfHighImportance = 5,
                LocalRoad = 6,
                LocalRoadOfMinorImportance = 7,
                OtherRoad = 8,
                Tramline = 98,
                Railway = 99,
                RailHighSpeed1 = 101,
                RailHighSpeed2 = 102,
                RailMainline1 = 103,
                RailMainline2 = 104,
                RailPrivate1 = 105,
                RailPrivate2 = 106,
                RailSubway = 107,
                RailMonorail = 108,
                RailCableCar = 109,
                RailRopeway = 110,
                RailStreetcar = 111
            };
            
            void BuildFunctionalRoadClassEnumValuesMap(std::map<std::string,FunctionalRoadClass> &enumMap);
          
            struct NavGraphRoadData
            {
                float halfWidth;

                u8 averageSpeedInKph;
                u8 roughSpeedLimitInKph;
                u8 numLanes;
                RoadDirection direction;
                FunctionalRoadClass functionalRoadClass;
                
                int vertexOffset;
                int vertexCount;
                int fromConnectionsOffset;
                int fromConnectionsCount;
                int toConnectionsOffset;
                int toConnectionsCount;


                

            };

            struct NavGraphData
            {
                Eegeo::dv3 originECEF;
                std::vector<NavGraphRoadData> roads;
                std::vector<Eegeo::v3> vertices;
                std::vector<u16> fromConnections;
                std::vector<u16> toConnections;
                std::vector<u16> roadIndicesJoiningCell;
                std::vector<u16> roadIndicesLeavingCell;
                
                void Clear()
                {
                    roads.clear();
                    vertices.clear();
                    fromConnections.clear();
                    toConnections.clear();
                    roadIndicesJoiningCell.clear();
                    roadIndicesLeavingCell.clear();
                }
            };
        }
    }
}
