// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include <string>
#include "InteriorsLabelParser.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                class IInteriorsLabelController
                {
                public:
                    virtual ~IInteriorsLabelController() {};
                    virtual const TFloorToModelMap& GetFloorsToModels() const = 0;
                    virtual void AddLabelToOmit(const std::string& labelName) = 0;
                    virtual void RemoveLabelToOmit(const std::string& labelName) = 0;
                };
            }
        }
    }
}