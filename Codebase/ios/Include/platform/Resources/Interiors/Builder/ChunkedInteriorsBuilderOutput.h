// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct ChunkedInteriorsBuilderOutput
                {
                    ChunkedInteriorsBuilderOutput(bool success, const std::vector<InteriorData*>& interiorData);
                    ~ChunkedInteriorsBuilderOutput();
                    
                    bool IsSuccess() const { return m_success; }
                    const std::vector<InteriorData*>& GetInteriorData() const { return m_interiorData; }
                private:
                    bool m_success;
                    const std::vector<InteriorData*> m_interiorData;
                };
            }
        }
    }
}