// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                class InteriorsEntityModel
                {
                public:
                    InteriorsEntityModel(const std::string& identifier);
                    
                    const std::string& GetIdentifier() const;
                    
                private:
                    std::string m_id;
                };
            }
        }
    }
}