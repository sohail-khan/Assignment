// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include <string>
#include <vector>
#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                struct InteriorsEntityMetadata
                {
                    std::string identifier;
                    std::string name;
                    float priority;
                    double latitudeDegrees;
                    double longitudeDegrees;
                    double altitude;
                    double rotationDegreesOverY;
                    double scale;
                    int floorNumber;
                    std::string entityType;
                    
                    std::string extendedInfo; // Serialized JSON
                };
                
                typedef std::map<std::string,std::vector<InteriorsEntityMetadata> > TCategoryToEntitiesMetadata;
            }
        }
    }
}