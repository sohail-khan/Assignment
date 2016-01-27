// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "LatLongAltitude.h"
#include "InteriorId.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Markers
            {
                class InteriorMarkerModel
                {
                public:
                    InteriorMarkerModel(InteriorId interiorId,
                                        Space::LatLongAltitude markerLatLongAltitude,
                                        const std::string& interiorName,
                                        const std::string& interiorOwner);
                    
                    const InteriorId& GetInteriorId() const { return m_interiorId; }
                    
                    const Space::LatLongAltitude& GetMarkerLatLongAltitude() const { return m_markerLatLongAltitude; }
                    
                    const std::string& GetInteriorName() const { return m_interiorName; }
                    const std::string& GetInteriorOwner() const { return m_interiorOwner; }
                    
                private:
                    InteriorId m_interiorId;
                    const std::string m_interiorName;
                    const std::string m_interiorOwner;
                    
                    Space::LatLongAltitude m_markerLatLongAltitude;
                };
            }
        }
    }
}