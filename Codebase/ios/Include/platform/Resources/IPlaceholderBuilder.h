// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "Resources.h"

namespace Eegeo
{
    namespace Resources
    {        
        class IPlaceholderBuilder
        {
            public:
        		virtual ~IPlaceholderBuilder(){};
                virtual IBuiltResource* Build(Eegeo::Streaming::MortonKey key) = 0;
        };
    }
    
}